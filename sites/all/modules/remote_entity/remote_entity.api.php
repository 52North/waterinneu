<?php

/**
 * @file
 * Hooks provided by the Remote Entity API.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Provide an entity type via the remote entity API.
 *
 * This is a placeholder for describing further keys for hook_entity_info(),
 * which are introduced by the remote entity API for providing a new entity type
 * in sync with a remote entity.
 *
 * The following core or Entity API keys are used by the remote entity API:
 *
 * - 'controller class': This should be 'RemoteEntityAPIDefaultController' or
 *    a subclass.
 * - 'metadata controller class': This should be
 *   'RemoteEntityAPIDefaultMetadataController' or a subclass.
 *
 * The following core or Entity API keys are extended by the remote entity API:
 *
 * - 'admin ui': If the entity uses RemoteEntityEntityUIController as its
 *   controller, then this may have the following additional keys:
 *    - 'form buttons': An array specifying which buttons should be shown on the
 *      form, in the format 'button_name' => TRUE. Possible button names are:
 *      - 'fetch': Show a button to fetch all remote entities. (Only use this
 *        when you know the number of remote entities is relatively small!)
 * - 'entity keys': The following additional keys are used by the Remote Entity
 *   API:
 *    - 'needs remote save': (optional) The key of the entity property holding
 *      the boolean flag that marks the entity as needing to be saved remotely.
 *
 * The remote entity API supports the following keys:
 *
 * - 'remote base table': The remote base table or entity type. This is used
 *   in remote queries.
 * - 'remote query defaults callback': (Optional) A function with signature
 *   callback_remote_entity_query_defaults(), which is called on all new
 *   RemoteEntityQuery objects. This may be used to set default conditions or
 *   relationships on queries.
 * - 'remote entity keys': An array of properties on the Drupal entity that map
 *   to properties on the remote data.
 *    - 'remote id': The remote entity property which gives its remote ID.
 *    - 'label': The remote entity property which gives its label, if
 *      remote_entity_entity_label() is being used as the label callback.
 * - 'property map': An array of mappings from local property names to remote
 *   entity properties. Local names will be made available via the Entity
 *   metadata API. For instance, the key-value pair 'foo' => 'bar' will mean
 *   that $wrapper->foo->value() will return the value of $remote_entity->bar.
 * - 'expiry': (optional) Allows local copies of entities to expire, after
 *   which time they are refreshed. If this is not set, local entities never
 *   expire. This should be an array with the following properties:
 *    - 'expiry time': A value in seconds that determines how long a local copy
 *      of a remote entity is considered fresh. After this time, loading the
 *      local copy will result in a remote retrieval of the entity.
 *    - 'purge': A boolean indicating whether or not to delete expired local
 *      entities on cron. Warning: purging local entities will mean that when
 *      they are next retrieved, their local entity ID will change, thus
 *      breaking any entityreference field values and fields on the entities
 *      themselves.
 * - 'remote entity unpack callback': The name of an implementation of
 *    callback_remote_entity_unpack(). This allows the entity's module to set
 *    remote properties on the entity to be set prior to saving.
 * - (TODO) 'remote entity pack callback': The name of an implementation of
 *    callback_remote_entity_pack(). This allows the entity's module to extract
 *    remote properties from the remote entity data when it is loaded from
 *    the remote source. For example, the controller by default extracts the
 *    remote ID and places it in the entity's 'remote_id' property.
 *  - 'bundles': Within a bundle info array, the following extra properties are
 *    supported:
 *    - 'remote entity conditions': (optional) An array of conditions to apply
 *      when a remote entity is being packed on initial retrieval, to determine
 *      which bundle to use for the local entity. This is only required if the
 *      entity type has bundles, and will be queried for remotely. Furthermore,
 *      only bundles that will be queried for need this. Each condition in the
 *      array has as its key the name of a remote property (i.e. a property on
 *      the remote data as retrieved) and its value a value to match for that
 *      property. Entity types needing more complicated logic should override
 *      the getNewEntityBundle() method.
 *
 * @see hook_entity_info()
 * @see entity_crud_hook_entity_info()
 */
function remote_entity_hook_entity_info() {

}

/**
 * Provide a entity metadata for the remote entity API.
 *
 * This is a placeholder for describing further keys for
 * hook_entity_property_info(), which are introduced by the Remote Entity API
 * for providing a new entity type in sync with a remote entity.
 *
 * @return
 *   - properties: Within a properties array, the following keys are used by
 *    Remote Entity API:
 *     - 'remote property shadowing': Applies only to a mapped remote property;
 *        that is, one that is defined in the entity info 'property map'. This
 *        should be an array detailing how a remote property is shadowed into
 *        native Drupal storage, such as a FieldAPI field or an entity database
 *        table field. Keys are:
 *        - 'local to remote callback': The name of an implementation of
 *          callback_remote_entity_property_info_shadow_property(), which is
 *          responsible for copying data from Drupal local properties to the
 *          mapped remote property.
 *        - 'remote to local callback': The name of an implementation of
 *          callback_remote_entity_property_info_shadow_property(), which is
 *          responsible for copying data from the remote mapped property to
 *          Drupal local properties.
 *        - 'local property': If the callback specified for either direction is
 *          remote_entity_shadowing_schema_property_verbatim_named(), this must
 *          specify the name of a local property on the entity, whose value is
 *          copied to and from the remote property.
 *        Since the same callback signature is used for both callbacks, it is
 *        possible to use the same function, but this is not necessary. If this
 *        is set on a bundle-level property, then it overrides the same item on
 *        the entity-level property. For example:
 *        @code
 *        $info['entitytype']['bundles']['bundle']['properties']['foo']['remote property shadowing]...
 *        $info['entitytype']['properties']['foo']['remote property shadowing]...
 *        @endcode
 *
 * @see remote_entity_shadowing_schema_property_verbatim()
 * @see remote_entity_shadowing_schema_property_verbatim_named()
 */
function remote_entity_hook_entity_property_info() {

}


/**
 * Act when remote entities are processed to local copies.
 *
 * This is invoked after remote entities have been packed into local copies
 * and saved.
 *
 * @param $entities
 *  An array of entities, keyed by entity ID.
 * @param $entity_type
 *  The type of the entities.
 *
 * @see RemoteEntityAPIDefaultController::process_remote_entities()
 */
function hook_remote_entity_process($entities, $entity_type) {

}

/**
 * Declare information about remote tables for RemoteEntityQuery.
 *
 * Loosely inspired by hook_views_data().
 *
 * WARNING: This system is currently under active development, and may be
 * further changed in the future.
 *
 * @return
 *  An array of data about remote tables, used for building remote queries.
 *  This should be keyed by connection name, where each value is then an array
 *  keyed by remote table name. Each table value is an array of data for that
 *  table containing:
 *  - 'fields': An array whose keys are remote field names. Each value is an
 *    array which itself contains data about the field. The contents of this
 *    will depend on the connection type.
 *  - 'relationships': The contents of this depend on the connection type.
 *
 * @see remote_entity_get_query_table_info()
 * @see hook_remote_entity_query_table_info_alter()
 */
function hook_remote_entity_query_table_info() {
  $data = array(
    // The connection name.
    'my_connection' => array(
      // The remote table name.
      'mytable' => array(
        // Data about fields. Not all RemoteEntityQuery implementations will
        // necessarily need this, or need this for all contexts. Eg, these may
        // only be needed when used in conditions.
        'fields' => array(
          // The default type is 'string'; only define ones that differ.
          'typecode' => array(
            'type' => 'int',
          ),
          'statecode' => array(
            'type' => 'int',
          ),
        ),
        // Joins from this table to others.
        'relationships' => array(
          // Relationship name. Arbitrary, used in adding to the query.
          'myrelationship' => array(
            // The LHS of the join, starting from this table.
            'base' => array(
              // The field on this table.
              'field' => 'address1_addressid',
            ),
            // The RHS of the join.
            'join' => array(
              'table' => 'customeraddress',
              'field' => 'customeraddressid',
            ),
          ),
        ),
      ),
    ),
  );

  return $data;
}

/**
 * Alter information about remote tables for RemoteEntityQuery.
 *
 * @param $table_data
 *  The table data from other modules.
 *
 * @see remote_entity_get_query_table_info()
 * @see hook_remote_entity_query_table_info()
 */
function hook_remote_entity_query_table_info_alter(&$table_data) {
}

/**
 * @addtogroup callbacks
 * @{
 */

/**
 * Retrieve or place a remote property value from Drupal-native storage.
 *
 * Callback for entity_property_info().
 *
 * This allows remote entity properties to be automatically extracted from the
 * remote data and stored in Drupal-native storage. For example, extracting data
 * to a FieldAPI field allows Drupal field widgets to be used to editing data;
 * extracting data to an entity database table property allows easy querying for
 * single-valued data.
 *
 * This callback should either set properties on the entity based on the remote
 * data, or return a value for the remote data based on the entity, depending on
 * the value of $direction.
 *
 * @param $entity
 *  The entity to act on.
 * @param $property_name
 *  The property name to shadow. This will be one of the keys of the array in
 *  the entity info's 'property map' array.
 * @param $entity_type
 *  The type of the entity.
 * @param $property_info
 *  The property info array for the property to shadow, as returned by
 *  entity_get_property_info(). This contains the 'remote_property' key, which
 *  gives the name of the remote property.
 * @param $direction
 *  The direction of shadowing, one of:
 *  - 'local to remote': The local shadowed entity data is being returned to the
 *    remote entity data.
 *  - 'remote to local': The remote entity data is being shadowed to the
 *    local entity data.
 *    This is a convenience to allow a callback to function in both directions;
 *    it may prove more convenient to implement two separate callbacks.
 *
 * @return
 *  Depending on the value of $direction:
 *  - 'local to remote callback': The value to set on the remote property. If
 *    this is NULL then nothing is set.
 *  - 'remote to local callback': Nothing. The local value should be set on the
 *    entity directly.
 *
 * @see remote_entity_hook_entity_property_info()
 * @see RemoteEntityAPIDefaultController::unpack()
 */
function callback_remote_entity_property_info_shadow_property($entity, $property_name, $entity_type, $property_info, $direction) {
  $wrapper = entity_metadata_wrapper($entity_type, $entity);

  if ($direction == 'local to remote') {
    // Get a value from a FieldAPI field.
    $value = $wrapper->field_my_shadow_field->raw();

    // Return the value for the API to set it.
    return $value;
  }

  if ($direction == 'remote to local') {
    // Get a value from the remote property.
    $value = $wrapper->{$property_name}->raw();

    // Set it on a FieldAPI field.
    $wrapper->field_my_shadow_field->set($value);
  }
}

/**
 * Allows defaults to be set on all RemoteEntityQueries for an entity type.
 *
 * @param RemoteEntityQuery $query
 *  A RemoteEntityQuery, with the base already set by the entity controller.
 *  This is passed by reference and should be altered directly.
 *  The entity info for the base entity can be found in $query->entity_info.
 *
 * @see remote_entity_hook_entity_info()
 * @see RemoteEntityAPIDefaultController::getRemoteEntityQuery()
 */
function callback_remote_entity_query_defaults($query) {
  // We only work with remote entities of property foo equal to bar.
  $query->fieldRemoteCondition('foo', 'bar');
}

/**
 * Allows setting of remote properties on the entity prior to remote saving.
 *
 * For example, the entity may use FieldAPI to collect data from users, which
 * should then be set into the remote entity data and saved remotely.
 *
 * @param $entity_type
 *  The entity type.
 * @param $entity
 *  The entity that is about to be saved remotely.
 */
function callback_remote_entity_unpack($entity_type, $entity) {

}
