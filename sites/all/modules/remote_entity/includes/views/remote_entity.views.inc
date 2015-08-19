<?php

/**
 * @file remote_entity.views.inc
 * Contains Views hooks.
 */


/**
 * Implements hook_views_data_alter().
 */
function remote_entity_views_data_alter(&$data) {
  // Add a field for each remote property on entities.
  foreach (entity_get_info() as $entity_type => $entity_info) {
    // Only add remote property fields to entities if they have them.
    if (!isset($entity_info['property map'])) {
      continue;
    }

    // Only add remote property fields to entities if their base table has
    // Views data.
    if (isset($entity_info['base table']) && !isset($data[$entity_info['base table']])) {
      continue;
    }

    $base_table = $entity_info['base table'];

    $property_info = entity_get_property_info($entity_type);

    // During install (and in particular when setting up test cases), we get
    // here before new entity types have their property info, so skip if that's
    // the case.
    if (empty($property_info)) {
      continue;
    }

    foreach ($entity_info['property map'] as $property => $remote_property) {
      // We can *still* get here and not have the properties that are derived
      // from the remote property map.
      if (!isset($property_info['properties'][$property])) {
        continue;
      }

      $data[$base_table]['remote_property_' . $property] = array(
        'title' => t('Remote property: !property', array(
          // Use the label from entity property info, in case entity type
          // modules have replaced it with something nicer than the machine
          // name we set in RemoteEntityAPIDefaultMetadataController.
          '!property' => $property_info['properties'][$property]['label'],
        )),
        'help' => t("Displays the entity's '!property' remote property.", array(
          '!property' => $property_info['properties'][$property]['label'],
        )),
        'field' => array(
          'real field' => $entity_info['entity keys']['id'],
          'handler' => 'remote_entity_handler_field_remote_property',
          // Data for our handler to find.
          'property name' => $property,
        ),
      );
    }
  }

  // Add our field handler for bypassing remote retrieval.
  $data['views']['remote_entity_bypass_retrieval'] = array(
    'title' => t('Bypass remote entity retrieval'),
    'help' => t("Prevents remote entity types from refreshing expired entities when the view's result is shown, to improve performance of the view. This handler should be first in the list of fields. It will not produce any output."),
    'field' => array(
      'handler' => 'remote_entity_handler_field_bypass_remote_retrieve',
    ),
  );
}
