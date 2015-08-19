<?php

/**
 * @file wsfields_views.views.inc
 */

/**
 * Implements hook_views_data().
 */
function wsfields_views_views_data() {
  $data = array();
  foreach (field_info_fields() as $field) {
    if ($field['storage']['type'] != 'wsfields_storage') {
      continue;
    }
    $entity_types = array_keys($field['bundles']);

    foreach ($entity_types as $entity_type) {
      $data[$entity_type][$field['field_name']]['field'] = array(
        'title' => $field['field_name'],
        'help' => t('WSFields Remote Field'),
        'handler' => 'wsfields_views_handler_field',
      );
      $data[$entity_type][$field['field_name'] . '_sort']['sort'] = array(
        'title' => $field['field_name'],
        'help' => t('WSFields Remote Field'),
        'handler' => 'wsfields_views_handler_sort',
      );
    }
  }
  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function wsfields_views_views_data_alter(&$data) {
}
