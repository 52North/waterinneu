<?php
// $Id$

/**
 * @file
 * API documentation for users_export module.
 *
 * @addtogroup hooks
 * @{
 */

/**
 * Implements hook_users_export_row_alter().
 *
 * Modify the contents of an exported row
 *
 * @param array &$row
 * @param int $uid
 *
 * @return NULL
 */
function hook_core_users_export_row_alter(&$row, $uid) {
  $names = &drupal_static(__FUNCTION__, array());
  if (empty($names)) {

    // Add in the first and last name of the user
    $query = db_select('field_data_field_first_name', 'f');
    $names['first'] = $query
      ->fields('f', array('entity_id', 'field_first_name_value'))
      ->execute()->fetchAllAssoc('entity_id');

    $query = db_select('field_data_field_last_name', 'l');
    $names['last'] = $query
      ->fields('l', array('entity_id', 'field_last_name_value'))
      ->execute()->fetchAllAssoc('entity_id');
  }
  $row['first_name']  = empty($names['first'][$uid]->field_first_name_value) ? '' : $names['first'][$uid]->field_first_name_value;
  $row['last_name']   = empty($names['last'][$uid]->field_last_name_value) ? '' : $names['last'][$uid]->field_last_name_value;
}

/**
 * Implements hook_users_export_data().
 *
 * Modify the export data before it is saved to file
 *
 * @param array &$data
 * - header: An array of the header values if the header is to be printed
 * - rows: An array of the data rows;
 * - type: The type of file to be written
 *
 * @return NULL
 */
function hook_users_export_data_alter(&$data) {
  foreach (array_keys($data['header']) as $key) {
    $data['header'][$key] = ucwords(str_replace('_', ' ', $data['header'][$key]));
  }
}

/** @} */ //end of group hooks
