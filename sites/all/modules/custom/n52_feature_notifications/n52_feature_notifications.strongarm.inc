<?php
/**
 * @file
 * n52_feature_notifications.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function n52_feature_notifications_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'rules_debug';
  $strongarm->value = '2';
  $export['rules_debug'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'rules_debug_log';
  $strongarm->value = 1;
  $export['rules_debug_log'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'rules_debug_region_adminimal';
  $strongarm->value = 'help';
  $export['rules_debug_region_adminimal'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'rules_log_errors';
  $strongarm->value = '2';
  $export['rules_log_errors'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'rules_path_cleaning_callback';
  $strongarm->value = 'rules_path_default_cleaning_method';
  $export['rules_path_cleaning_callback'] = $strongarm;

  return $export;
}
