<?php

/**
 * @file
 * Contains the interface and the Clients resource class for remote entities.
 */

/**
 * Interface for client connections providing a remote entity.
 */
interface ClientsRemoteEntityInterface {

  /**
   * Load a remote entity.
   *
   * @param $entity_type
   *  The entity type to load.
   * @param $id
   *  The (remote) ID of the entity.
   *
   * @return
   *  An entity object.
   */
  function remote_entity_load($entity_type, $id);

  /**
   * Save a remote entity.
   *
   * @param $entity_type
   *  The type of the entity.
   * @param $entity
   *  The entity to save.
   * @param $remote_properties
   *  (Optional) An array of properties to save. Values should be names of
   *  properties which are keys in the entity info 'property map' array. Only
   *  applies when updating rather than inserting. Client connection types may
   *  ignore this.
   *
   * @return
   *  If the entity is being created remotely, the new remote ID.
   */
  function remote_entity_save($entity_type, $entity, $remote_properties = array());

  /**
   * Get a new RemoteEntityQuery object appropriate for the connection.
   */
  function getRemoteEntityQuery();

  /**
   * Provide a map of remote property types to Drupal types.
   *
   * Roughly analogous to _entity_metadata_convert_schema_type().
   *
   * @return
   *  An array whose keys are remote property types as used as types for fields
   *  in hook_remote_entity_query_table_info(), and whose values are types
   *  recognized by the Entity Metadata API (as listed in the documentation for
   *  hook_entity_property_info()).
   *  If a remote property type is not listed here, it will be mapped to 'text'
   *  by default.
   */
  function entity_property_type_map();

}

/**
 * Class for Clients remote entity resource.
 *
 * There are two pathways that get a remote entity:
 *  - remote_entity_load() loads a single entity
 *  - getRemoteEntityQuery() starts a remote query. Use
 *    executeRemoteEntityQuery() to complete it.
 */
class clients_resource_remote_entity extends clients_resource_base {

  // The Remote Entity Resource API.

  /**
   * The current remote entity query.
   */
  public $remoteEntityQuery;

  /**
   * Load multiple remote entities.
   *
   * Takes care of calling process_remote_entities() on the controller
   * for the retrieved remote entity. This in turn saves a local copy of the
   * remote entity.
   *
   * If the connection supports remote_entity_load_multiple(), then this uses
   * it; otherwise, it's the same as calling this class's remote_entity_load().
   *
   * Connections implementing remote_entity_load_multiple() should consider
   * practical limitations to the number of entities that can be retrieved in a
   * single request, and in light of this split the operation into several
   * requests.
   *
   * @param $ids
   *  An array of the (remote) entity IDs.
   *
   * @return
   *  An array of local entities, keyed by the local entity IDs.
   */
  function remote_entity_load_multiple($ids) {
    $connection = $this->getConnection();
    $entity_type = $this->component;

    if (method_exists($connection, 'remote_entity_load_multiple')) {
      $remote_entities = $connection->remote_entity_load_multiple($entity_type, $ids);
    }
    else {
      // Fall back to single entity load.
      $remote_entities = array();
      foreach ($ids as $id) {
        $remote_entities[] = $connection->remote_entity_load($entity_type, $id);
      }
    }

    if (!empty($remote_entities)) {
      $controller = entity_get_controller($this->component);
      // The controller's process_remote_entities() doesn't care about the key
      // of the array of remote entities.
      $entities = $controller->process_remote_entities($remote_entities);

      return $entities;
    }
    return array();
  }

  /**
   * Load a remote entity.
   *
   * Takes care of calling process_remote_entities() on the controller
   * for the retrieved remote entity. This in turn saves a local copy of the
   * remote entity.
   *
   * @param $id
   *  The (remote) ID of the entity.
   *
   * @return
   *  An entity object, or FALSE if the entity is not found.
   */
  function remote_entity_load($id) {
    $connection = $this->getConnection();
    $entity_type = $this->component;
    $remote_entity = $connection->remote_entity_load($entity_type, $id);

    if (!empty($remote_entity)) {
      // Get the controller to process the data to a local entity and save it.
      $controller = entity_get_controller($this->component);
      $entities = $controller->process_remote_entities(array($remote_entity));

      return reset($entities);
    }

    return FALSE;
  }

  /**
   * Save a remote entity.
   *
   * Should be called via the controller's equivalent method, which handles
   * setting the returned remote ID.
   *
   * @param $entity
   *  The entity to save.
   * @param $remote_properties
   *  (Optional) An array of properties to save. Values should be names of
   *  properties which are keys in the entity info 'property map' array. Only
   *  applies when updating rather than inserting. Client connection types may
   *  ignore this.
   *
   * @return
   *  If the entity is being created remotely, the new remote ID. If the entity
   *  is updated, NULL.
   */
  function remote_entity_save($entity, $remote_properties = array()) {
    $connection = $this->getConnection();
    $entity_type = $this->component;

    // Handle a read-only connection.
    if (!empty($connection->configuration['read_only'])) {
      // If there is no remote ID yet, simulate an insert.
      if (empty($entity->remote_id)) {
        return $connection->generateDummyRemoteID();
      }
      // Return nothing to simulate a save.
      return;
    }

    // Hand over to the connection to perform specialized tasks.
    $return = $connection->remote_entity_save($entity_type, $entity, $remote_properties);

    return $return;
  }

  /**
   * Save multiple entities remotely, using bulk saving methods on the remote.
   *
   * This falls back to the single remote_entity_save() if the underlying
   * connection does not have a remote_entity_save_multiple() method.
   *
   * @param $entities
   *  An array of entities to save in bulk, keyed by the entity ID.
   * @param $remote_properties
   *  Same as remote_entity_save().
   *
   * @return
   *  An array of remote IDs created by the remote save. The array is keyed by
   *  entity ID. Only entities which were inserted remotely (rather than
   *  updated) are included.
   */
  public function remote_entity_save_multiple($entities, $remote_properties) {
    $connection = $this->getConnection();

    // For a read-only connection, there is no performance improvement to be
    // achieved anyway, so we fall back to the single save method and rely on
    // its handling of the read-only case.
    if (!empty($connection->configuration['read_only'])) {
      $fall_back_to_single = TRUE;
    }

    // Check our connection has the method needed, and fall back to the single
    // method if we don't have it.
    $connection = $this->getConnection();
    if (!method_exists($connection, 'remote_entity_save_multiple')) {
      $fall_back_to_single = TRUE;
    }

    if (!empty($fall_back_to_single)) {
      $return = array();
      foreach ($entities as $eid => $entity) {
        $remote_id = $this->remote_entity_save($entity, $remote_properties);
        // Only populate the return array with actual values; updates don't get
        // us a remote ID.
        if (!empty($remote_id)) {
          $return[$eid] = $remote_id;
        }
      }
      return $return;
    }

    $entity_type = $this->component;
    $return = $connection->remote_entity_save_multiple($entity_type, $entities, $remote_properties);
    return $return;
  }

  /**
   * Get a new RemoteEntityQuery object appropriate for the connection.
   *
   * @return
   *  A RemoteEntityQuery object with the base already set for the current
   *  resource's entity type.
   */
  function getRemoteEntityQuery() {
    $connection = $this->getConnection();
    $query = $connection->getRemoteEntityQuery();

    $query->base($this->component);

    $this->remoteEntityQuery = $query;

    return $query;
  }

  /**
   * Execute the current RemoteEntityQuery, and process and save the result.
   *
   * @return
   *  An array of local entities, which have been saved. These are keyed by
   *  entity ID.
   */
  function executeRemoteEntityQuery() {
    $remote_entities = $this->remoteEntityQuery->execute();

    // Get the controller to process them to local entities and save them.
    $controller = entity_get_controller($this->component);
    $entities = $controller->process_remote_entities($remote_entities);

    return $entities;
  }

  // Clients Resource UI.

  /**
   * Alterations to the resource form.
   */
  function resourceSettingsFormAlter(&$form, &$form_state) {
    // Change the component form element.
    $form['component']['#title'] = t('Entity type');
    $form['component']['#description'] = t('The name of the entity type that this resource provides.');

    $form['component_notice'] = array(
      '#markup' => '<p class="warning">' . t("Notice: This resource type requires hook_entity_info() to be implemented for the entity type.") . '</p>',
    );
  }

}
