<?php

/**
 * Entity metadata controller.
 *
 * Registers the properties declared in $entity_info['remote entity keys'] and
 * $entity_info['property map'].
 *
 * See remote_entity_hook_entity_info() for details on using these.
 */
class RemoteEntityAPIDefaultMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    // Let the parent class handle the schema properties.
    $parent_info = parent::entityPropertyInfo();

    // This is so awkward I am surely doing it wrong :/
    $properties = $parent_info[$this->type]['properties'];

    // Add some labels and types for our schema properties, allowing for the
    // fact that entity type modules may have changed the schema to suit their
    // own purposes.
    if (isset($properties['created'])) {
      $properties['created']['type'] = 'date';
      $properties['created']['label'] = t("Created date");
      $properties['created']['description'] = t("The date the entity was created.");
    }
    if (isset($properties['changed'])) {
      $properties['changed']['type'] = 'date';
      $properties['changed']['label'] = t("Changed date");
      $properties['changed']['description'] = t("The date the entity was last changed.");
    }
    if (isset($properties['remote_saved'])) {
      $properties['remote_saved']['type'] = 'date';
      $properties['remote_saved']['label'] = t("Remote save date");
      $properties['remote_saved']['description'] = t("The date the entity was last saved remotely.");
    }
    if (isset($properties['expires'])) {
      $properties['expires']['type'] = 'date';
      $properties['expires']['label'] = t("Expiry date");
      $properties['expires']['description'] = t("The date the local copy of the entity expires.");
    }
    if (isset($properties['needs_remote_save'])) {
      $properties['needs_remote_save']['type'] = 'integer';
      $properties['needs_remote_save']['label'] = t("Needs remote save");
      $properties['needs_remote_save']['description'] = t("Indicates whether the entity needs to be saved remotely.");
      $properties['needs_remote_save']['options list'] = 'remote_entity_entity_needs_remote_save_options_list';
    }
    if (isset($properties['deleted'])) {
      $properties['deleted']['type'] = 'boolean';
      $properties['deleted']['label'] = t("Deleted");
      $properties['deleted']['description'] = t("Boolean indicating that the entity is marked for deletion.");
    }

    // Get the property type map out of the connection for our remote entity
    // type.
    // First get the resource for our entity type, and then the connection.
    $resource = clients_resource_get_for_component('remote_entity', $this->type);
    if (empty($resource)) {
      // It's possible to come here and find no resource for a remote entity
      // type. This happens when _entity_defaults_rebuild() imports resources
      // defined in code, and during its own invocation of entity hooks, other
      // modules make use of the Entity Metadata API.
      // All we can do it bail here, since our resource does not exist.
      // remote_entity_clients_connection_defaults_rebuild() takes care of
      // causing another rebuild of Entity Metadata properties afterwards.
      return $parent_info;
    }

    $connection = $resource->getConnection();
    $property_type_map = $connection->entity_property_type_map();
    if (method_exists($connection, 'entity_property_type_callbacks')) {
      $property_type_callbacks = $connection->entity_property_type_callbacks();
    }

    // Get the remote table info.
    $table_info = remote_entity_get_query_table_info($connection->name, $this->info['remote base table']);

    // Properties from the property map.
    foreach ($this->info['property map'] as $property => $remote_property) {
      // Type defaults to 'text'.
      $type = 'text';
      $remote_type = NULL;
      // Now see if that should actually be something else, by inspecting the
      // remote table info and the remote property type map.
      if (isset($table_info['fields'][$remote_property])) {
        // If the table info defines the field...
        $remote_type = $table_info['fields'][$remote_property]['type'];
        if (isset($property_type_map[$remote_type])) {
          // ...and the property map has the type, take our type from the map.
          $type = $property_type_map[$remote_type];
        }
      }

      $properties[$property] = array(
        'label' => $property,
        'description' => t("A remote property."),
        'type' => $type,
        'getter callback' => 'remote_entity_entity_mapped_property_get',
        'setter callback' => 'remote_entity_entity_mapped_property_set',
        // Custom property to help our getters and setters.
        'remote_property' => $remote_property,
      );

      // If the connection specified particular callbacks for the remote type
      // (and we have a remote type), add them in here.
      if (isset($remote_type) && isset($property_type_callbacks[$remote_type])) {
        $properties[$property] = $property_type_callbacks[$remote_type] + $properties[$property];
      }
    }

    // Remove the setter callback from the property for the remote id: it
    // should not be set locally.
    // Get the remote id property.
    $id_property = $this->info['remote entity keys']['remote id'];
    // Flip the property map so we can find its local name.
    $flipped_property_map = array_flip($this->info['property map']);
    // Get the local property name that maps to the remote id property.
    $local_id_property = $flipped_property_map[$id_property];
    // Unset the callback.
    unset($properties[$local_id_property]['setter callback']);

    $info = array();
    $info[$this->type]['properties'] = $properties;

    return $info;
  }

}
