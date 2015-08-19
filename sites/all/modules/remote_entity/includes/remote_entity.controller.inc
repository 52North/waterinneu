<?php

/**
 * Entity controller implementing EntityAPIControllerInterface.
 *
 * Inspired in part by http://wunderkraut.com/blog/remote-entities-in-drupal-7/2012-10-25.
 *
 * This allows loading and saving from the remote source in addition to using
 * the local cached copy.
 *
 * The standard methods try to do the sane thing you'd want to happen in usual
 * circumstances; for other cases, other methods exist.
 *  - load() tries to work locally, and will resort to a remote retrieval if
 *    the entity is expired.
 *  - save() works only locally. This is so that entity forms can work as
 *    normal, and strictly local operations such as saving FieldAPI fields
 *    don't incur a costly remote operation.
 *  - remote_save() saves the entity remotely.
 */
class RemoteEntityAPIDefaultController extends EntityAPIController implements EntityAPIControllerInterface {

  /**
   * Determines whether to bypass remote retrieval of entities.
   *
   * This is needed because several pathways that aren't load() nonetheless
   * result in a load, including saving and deleting. Since we also want to save
   * locally when we retrieve remotely, and we want to purge entities locally
   * without incurring a retrieval, we need this to bypass loading during
   * those operations (the former is circular, the second just slow). Because
   * the results of entity_get_controller() are statically cached, this can be
   * set before saving and deleting and then restored afterwards.
   */
  public $bypass_remote_retrieve = FALSE;

  /**
   * Overridden to retrieve entities from remote source if expired.
   *
   * Retrieving remote entities can be bypassed by setting the value of the
   * property $bypass_remote_retrieve on the controller object to TRUE.
   *
   * @see DrupalDefaultEntityController#load($ids, $conditions)
   */
  public function load($ids = array(), $conditions = array()) {
    $entities = parent::load($ids, $conditions);
    //dsm($entities, 'CONTROLLER load');

    // Check each entity for expiry, if the entity type supports it. We also
    // allow the controller setting to bypass this.
    if (!empty($this->entityInfo['expiry']) && !$this->bypass_remote_retrieve) {
      // Assemble a list of expired entities, to remote load them in bulk.
      $expired_entity_remote_ids = array();
      foreach ($entities as $id => $entity) {
        // A value of 0 for the expiry means it doesn't expire.
        if (!empty($entity->expires) && $entity->expires < REQUEST_TIME) {
          // Entity has expired.
          // If the entity is marked for remote save, skip this step.
          if (!empty($entity->needs_remote_save)) {
            continue;
          }

          $expired_entity_remote_ids[$id] = $entity->remote_id;
        }
      }

      // If any entities require a refresh from remote, remote load them.
      if ($expired_entity_remote_ids) {
        $resource = clients_resource_get_for_component('remote_entity', $this->entityType);
        // Load the remote entities. This in turn:
        // - calls the connection to build a RemoteEntityQuery
        // - calls us to take care of doing the packing and the saving.
        $refreshed_entities = $resource->remote_entity_load_multiple($expired_entity_remote_ids);

        // Replace the entities in the array, they are now stale.
        // Only return something if the entity exists: if nothing has come
        // back then the remote entity has vanished on the remote site.
        foreach ($refreshed_entities as $id => $refreshed_entity) {
          if (!empty($refreshed_entity)) {
            $entities[$id] = $refreshed_entity;
          }
          // TODO: if the remote entity is gone, should we delete locally, or
          // is that overstepping our bounds and something to be figured out
          // on a case by case basis?
        }
      }
    }

    return $entities;
  }

  /**
   * Load a local copy of an entity by remote id.
   *
   * This should be used to get a local copy when comparing it or associating it
   * to a retrieved remote.
   *
   * @param $remote_id
   *  The remote ID of the entity. This is saved in the 'remote_id' column in
   *  the table, and in the remote entity data is in the key given by the
   *  entity info.
   *
   * @return
   *  Either an entity or NULL if none found.
   */
  public function local_load_by_remote_id($remote_id) {
    $entities = $this->load(FALSE, array('remote_id' => $remote_id));
    return reset($entities);
  }

  /**
   * Sets the expiry time on the entity object.
   *
   * Note this does not save: call save() afterwards.
   *
   * This is safe to call even if the entity info doesn't use expiry, in which
   * case, calling this will do nothing.
   *
   * @param $entity
   *  The entity to set expiry time on.
   * @param $expiry_time
   *  (optional) The expiry time to set. If not given, this is calculated based
   *  on the request time and the entity info properties.
   *  @see remote_entity_hook_entity_info()
   */
  public function set_expiry($entity, $expiry_time = NULL) {
    // Only set this if the entity info requests it.
    if (isset($this->entityInfo['expiry'])) {
      if (!isset($expiry_time)) {
        // Set the expiry timestamp.
        $expiry_time = REQUEST_TIME + $this->entityInfo['expiry']['expiry time'];
      }
      $entity->expires = $expiry_time;

      // Clear the deleted flag, in case our local copy was sitting waiting to
      // be deleted. The change to the expiry time deals with the queue having
      // a deletion worker for this entity.
      $entity->deleted = 0;
    }
  }

  /**
   * Save the entity locally.
   *
   * The parent method works fine here. For now!
   */
  //public function save($entity, DatabaseTransaction $transaction = NULL) {}

  /**
   * Save the entity remotely.
   *
   * This may optionally save the entity locally if anything has changed about
   * it. For example, when performing a remote insert, the new remote ID is
   * saved.
   *
   * @param $entity
   *  The entity to save.
   * @param $remote_properties
   *  (Optional) An array of properties to save. Values should be names of
   *  properties which are keys in the entity info 'property map' array. Only
   *  applies when updating rather than inserting. Client connection types may
   *  ignore this.
   *
   * @throws Exception
   *  Re-throws exceptions from the client connection, after setting the failed
   *  entity's 'needs_remote_save' property to REMOTE_ENTITY_REMOTE_SAVE_FAILED.
   *  This ensures the problem entity will not attempt to save again, but is
   *  flagged for inspection. Note that the change in the property entails a
   *  local save, which in turn will update the 'changed' property.
   *
   * @see clients_resource_remote_entity::remote_entity_save()
   * @see callback_remote_entity_unpack()
   */
  public function remote_save($entity, $remote_properties = array()) {
    // Set ourselves to bypass remote retrievals, as we don't want any
    // save operation (which calls load()!) to result in a remote load.
    $this->bypass_remote_retrieve = TRUE;

    // Unpack the remote data from the local entity.
    // By default this does nothing, but subclasses may wish to override this.
    $this->unpack($entity, $remote_properties);

    $resource = clients_resource_get_for_component('remote_entity', $this->entityType);

    // The connection may throw an exception is there is a problem with the
    // remote server.
    try {
      $remote_id = $resource->remote_entity_save($entity, $remote_properties);
    }
    catch (Exception $e) {
      // Save the entity locally, marking it as having failed remote save.
      $entity->needs_remote_save = REMOTE_ENTITY_REMOTE_SAVE_FAILED;

      // We flag this as a remote save (even if just a failed attempt), in case
      // the entity's normal save workflow needs to be aware of this.
      $entity->is_remote_save = TRUE;
      $this->save($entity);

      // Clear the flag.
      $entity->is_remote_save = TRUE;

      // Re-throw the exception.
      throw $e;
    }

    // If creating a new entity remotely, we receive its new ID.
    if (isset($remote_id)) {
      // Set this into the remote ID property.
      $entity->remote_id = $remote_id;

      // Set the remote ID into the remote data.
      $remote_id_key = $this->entityInfo['remote entity keys']['remote id'];
      $entity->entity_data->{$remote_id_key} = $remote_id;
    }

    // Set the time at which this was last saved remotely.
    $entity->remote_saved = REQUEST_TIME;

    // Clear the flag now we've saved it.
    $entity->needs_remote_save = FALSE;

    // Save the entity locally, so the remote ID and timestamp are saved.
    // We flag this as a remote save, in case the entity's normal save workflow
    // needs to be aware of this.
    $entity->is_remote_save = TRUE;
    $this->save($entity);

    // Clear the flag.
    $entity->is_remote_save = TRUE;
  }

  /**
   * Save multiple entities remotely.
   *
   * @param $entities
   *   An array of entities to save remotely, keyed by entity id. They should
   *   already have been saved locally, though there can be a mix of remote
   *   inserts and updates.
   * @param $remote_properties
   *   (Optional) An array of properties to save. Values should be names of
   *   properties which are keys in the entity info 'property map' array. Only
   *   applies for entities which are about to be updated rather than inserted.
   *   Client connection types may ignore this.
   */
  public function remote_save_multiple($entities, $remote_properties) {
    // First check whether our connection supports this.
    $resource = clients_resource_get_for_component('remote_entity', $this->entityType);

    // Set ourselves to bypass remote retrievals, as we don't want any
    // save operation (which calls load()!) to result in a remote load.
    $this->bypass_remote_retrieve = TRUE;

    // Unpack the remote data from each entity.
    // By default this does nothing, but entity types may override this or
    // define callbacks.
    foreach ($entities as $entity) {
      $this->unpack($entity, $remote_properties);
    }

    // Save the entities using the resource.
    try {
      $remote_ids = $resource->remote_entity_save_multiple($entities, $remote_properties);
    }
    catch (Exception $e) {
      // We assume that the connection can't tell us which of the entities
      // had the problem. So we can only mark all of them as being a problem.
      foreach ($entities as $eid => $entity) {
        // Mark the entity as having failed remote save.
        $entity->needs_remote_save = REMOTE_ENTITY_REMOTE_SAVE_FAILED;

        // We flag this as a remote save (even if just a failed attempt), in case
        // the entity's normal save workflow needs to be aware of this.
        $entity->is_remote_save = TRUE;
        $this->save($entity);

        // Clear the flag.
        $entity->is_remote_save = TRUE;
      }

      // Re-throw the exception.
      throw $e;
    }

    // Update our local copy of each entity.
    $remote_id_key = $this->entityInfo['remote entity keys']['remote id'];
    foreach ($entities as $eid => $entity) {
      // The $remote_ids array will contain remote IDs for any entities which
      // were created remotely. If there's a remote ID, need to set it on the
      // local copy.
      if (isset($remote_ids[$eid])) {
        // Set this into the remote ID property.
        $entity->remote_id = $remote_ids[$eid];

        // Set the remote ID into the remote data.
        $entity->entity_data->{$remote_id_key} = $remote_ids[$eid];
      }

      // Set the time at which this was last saved remotely.
      $entity->remote_saved = REQUEST_TIME;

      // Clear the flag now we've saved it.
      $entity->needs_remote_save = FALSE;

      // Save the entity locally, so the remote ID and timestamp are saved.
      // We flag this as a remote save, in case the entity's normal save workflow
      // needs to be aware of this.
      $entity->is_remote_save = TRUE;
      $this->save($entity);

      // Clear the flag.
      $entity->is_remote_save = TRUE;
    }

    // Remove the bypass to restore normal operation.
    $this->bypass_remote_retrieve = FALSE;
  }

  /**
   * Get a new RemoteEntityQuery object appropriate for this entity type.
   *
   * @param $bundle_name
   *  (optional) The name of a bundle of this entity to query for. This requires
   *  the 'remote entity conditions' property to be set in the entity info for
   *  the requested bundle.
   *
   * @return
   *  A RemoteEntityQuery object with the base already set for our entity type.
   *  This should be executed by passing it to executeRemoteEntityQuery().
   *
   * @see clients_resource_remote_entity::getRemoteEntityQuery()
   */
  function getRemoteEntityQuery($bundle_name = NULL) {
    $resource = clients_resource_get_for_component('remote_entity', $this->entityType);
    $connection = $resource->getConnection();
    $query = $connection->getRemoteEntityQuery();
    // Set the base of the query.
    $query->base($this->entityType);

    if (isset($bundle_name)) {
      $bundle_info = $this->entityInfo['bundles'][$bundle_name];
      if (!isset($bundle_info['remote entity conditions'])) {
        throw new Exception(t("Requested bundle @bundle does not have its remote entity conditions set in the entity info.", array(
          '@bundle' => $bundle_name,
        )));
      }

      foreach ($bundle_info['remote entity conditions'] as $condition_property => $condition_value) {
        $query->fieldRemoteCondition($condition_property, $condition_value);
      }
    }

    // Invoke callback_remote_entity_query_defaults() with the query.
    // This can be used to set conditions or relationships that should be on
    // all queries for this entity type.
    if (isset($this->entityInfo['remote query defaults callback'])) {
      $function = $this->entityInfo['remote query defaults callback'];
      $function($query);
    }

    return $query;
  }

  /**
   * Execute a RemoteEntityQuery, and process and save the result.
   *
   * @param RemoteEntityQuery $query
   *  A RemoteEntityQuery object which is ready to be executed.
   *
   * @return
   *  An array of local entities, which have been saved.
   *
   * @see RemoteEntityAPIDefaultController::getRemoteEntityQuery()
   */
  function executeRemoteEntityQuery($query) {
    $remote_entities = $query->execute();

    // Get the controller to process them to local entities and save them.
    $entities = $this->process_remote_entities($remote_entities);

    return $entities;
  }

  /**
   * Process a remote entity that has been retrieved by a RemoteEntityQuery.
   *
   * @param $remote_entities
   *  An array of raw remote entities, as retrieved from the remote connection
   *  with a RemoteEntityQuery.
   *
   * @return
   *  An array of fully loaded local entities, keyed by entity id.
   *
   * @see clients_resource_remote_entity::executeRemoteEntityQuery()
   */
  public function process_remote_entities($remote_entities) {
    // Set ourselves to bypass remote retrievals, as we don't want either the
    // load in pack() or the save operation (which calls load()!) to result in
    // circularity.
    $this->bypass_remote_retrieve = TRUE;

    $entities = array();
    foreach ($remote_entities as $remote_entity) {
      // Pack the remote entity into a local entity.
      $entity = $this->pack($remote_entity);

      // Set the expiry time before we save it.
      $this->set_expiry($entity);
      $this->save($entity);

      $entities[$entity->eid] = $entity;
    }

    // Invoke hook_remote_entity_process() on the entities.
    module_invoke_all('remote_entity_process', $entities, $this->entityType);

    // Remove the bypass.
    $this->bypass_remote_retrieve = FALSE;

    return $entities;
  }

  /**
   * Packs remote entity data into a local entity for local consumption.
   *
   * (Are you local? ;)
   *
   * This ensures we don't get any clashes between remote and local keys, and
   * also means the entity object we work with locally looks the same as what
   * we stored in the database here.
   *
   * If the entity is already saved locally, it gets associated with the local
   * copy, thus preserving IDs.
   *
   * @param $remote_entity
   *  A remote entity object.
   *
   * @return
   *  A local entity, which has not yet been saved.
   */
  public function pack($remote_entity) {
    $remote_id_key = $this->entityInfo['remote entity keys']['remote id'];
    $remote_id = $remote_entity->{$remote_id_key};

    // Is this entity already stored locally?
    $local_entity = $this->local_load_by_remote_id($remote_id);
    if ($local_entity) {
      // If stored locally, check whether our local copy is marked as
      // needing a remote save. If that's the case, we merely return the local
      // copy, as we don't want the remote data to clobber what needs to be
      // saved.
      if (!empty($local_entity->needs_remote_save)) {
        $entity = $local_entity;
      }
      else {
        // If the local copy doesn't need a remote save, associate the incoming
        // entity with the existing cached copy.
        $local_entity->entity_data = $remote_entity;
        // Set the updated time.
        // TODO: does save() do this anyway???
        $local_entity->updated = REQUEST_TIME;

        $entity = $local_entity;
      }
    }
    else {
      // Create a new stub entity to hold the remote entity.
      $values = array(
        'created' => REQUEST_TIME,
        'updated' => REQUEST_TIME,
      );

      // If our entity type needs a bundle key setting, we have to figure out
      // the bundle to set based on the incoming data.
      if (!empty($this->entityInfo['entity keys']['bundle'])) {
        $bundle_name = $this->getNewEntityBundle($remote_entity);

        $values[$this->entityInfo['entity keys']['bundle']] = $bundle_name;
      }

      $entity = $this->create($values);

      // Set the remote data.
      $entity->entity_data = $remote_entity;

      // Set the remote ID.
      $entity->remote_id = $remote_entity->{$remote_id_key};
    }

    // Shadow data from remote properties to local ones.
    // Get our properties. We get them from the wrapper rather than use
    // entity_get_property_info() so that EntityDrupalWrapper::spotBundleInfo()
    // can add/override properties from bundles. This allows bundle-specific
    // property shadowing.
    // TODO: consider moving this functionality out to a helper method.
    $wrapper = entity_metadata_wrapper($this->entityType, $entity);
    $properties = $wrapper->getPropertyInfo();

    // Intersect with all the remote properties.
    $properties = array_intersect_key($properties, $this->entityInfo['property map']);

    foreach ($properties as $property_name => $property_info) {
      // Invoke callback_remote_entity_property_info_shadow_property().
      if (isset($property_info['remote property shadowing']['remote to local callback'])) {
        $callback = $property_info['remote property shadowing']['remote to local callback'];
        $callback($entity, $property_name, $this->entityType, $property_info, 'remote to local');
      }
    }

    return $entity;
  }

  /**
   * Helper for pack() to get the bundle of a new entity based on remote data.
   *
   * This considers an array of conditions in the info for each bundle. If all
   * the conditions pass, then the bundle is the desired one. It is up to
   * implementors to ensure that their bundle conditions will always match the
   * remote entities they query for.
   *
   * @param $remote_entity
   *  A remote entity object, as received by pack().
   *
   * @return
   *  The bundle name for the new entity.
   *
   * @throws
   *  Exception if no bundle name found.
   */
  protected function getNewEntityBundle($remote_entity) {
    foreach ($this->entityInfo['bundles'] as $bundle_name => $bundle_info) {
      if (isset($bundle_info['remote entity conditions'])) {
        $bundle_conditions_apply = FALSE;
        foreach ($bundle_info['remote entity conditions'] as $condition_property => $condition_value) {
          // All conditions defined in the bundle info must pass.
          if ($remote_entity->$condition_property == $condition_value) {
            $bundle_conditions_apply = TRUE;
          }
          else {
            // One failed: this bundle is no good. Give up on it.
            $bundle_conditions_apply = FALSE;
            break;
          }
        }

        // If the bundle passed, it's the right one.
        // (It's up to implementors to ensure their conditions are mutually
        // exclusive!)
        if ($bundle_conditions_apply) {
          return $bundle_name;
        }
      }
    }

    // If we get here then no bundle name matched.
    $remote_id_key = $this->entityInfo['remote entity keys']['remote id'];
    throw new Exception(t("No bundle name found for remote entity id '@id'.", array(
      '@id' => $remote_entity->{$remote_id_key},
    )));
  }

  /**
   * Unpacks remote entity data from the local entity for remote saving.
   *
   * Properties on the remote entity may be set on it prior to saving. This is
   * referred to as 'shadowing', as the main use case is mapping data from
   * schema properties or Field API fields into remote entity properties. This
   * is determined by the 'remote property shadowing' section of the metadata
   * property info defined in hook_entity_property_info().
   *
   * If a shadowing callback returns NULL, it is skipped.
   *
   * @param $entity
   *  An entity which is to be saved remotely.
   * @param $remote_properties
   *  (Optional) An array of properties which the remote save operation will
   *  update, provided the Client connection supports this. Values are names of
   *  properties which are keys in the entity info 'property map' array. Only
   *  applies when updating rather than inserting. If empty, all properties will
   *  be updated.
   *
   * @see remote_entity_hook_entity_property_info()
   */
  public function unpack($entity, $remote_properties = array()) {
    // Shadow data from local properties to remote ones.
    // Get our properties. We get them from the wrapper rather than use
    // entity_get_property_info() so that EntityDrupalWrapper::spotBundleInfo()
    // can add/override properties from bundles. This allows bundle-specific
    // property shadowing.
    $wrapper = entity_metadata_wrapper($this->entityType, $entity);

    // TODO: consider moving this functionality out to a helper method.
    $properties = $wrapper->getPropertyInfo();

    // Intersect to reduce this to remote properties.
    if (empty($remote_properties)) {
      // Intersect with all the remote properties.
      $properties = array_intersect_key($properties, $this->entityInfo['property map']);
    }
    else {
      // Intersect with the properties we've been requested to save.
      $properties = array_intersect_key($properties, array_fill_keys($remote_properties, TRUE));
    }

    // Only act if there are properties, so we only load the wrapper if needed.
    if (!empty($properties)) {
      $wrapper = entity_metadata_wrapper($this->entityType, $entity);

      foreach ($properties as $property_name => $property_info) {
        // Invoke callback_remote_entity_property_info_shadow_property().
        if (isset($property_info['remote property shadowing']['local to remote callback'])) {
          $callback = $property_info['remote property shadowing']['local to remote callback'];
          $value = $callback($entity, $property_name, $this->entityType, $property_info, 'local to remote');

          // Don't set a value if it's NULL.
          if (is_null($value)) {
            continue;
          }

          $wrapper->{$property_name}->set($value);
        }
      }
    }

    // Invoke callback_remote_entity_unpack() to allow the entity's module to
    // set properties on the remote data before we save it.
    if (isset($this->entityInfo['remote entity unpack callback'])) {
      $callback = $this->entityInfo['remote entity unpack callback'];
      $callback($this->entityType, $entity);
    }
  }

}
