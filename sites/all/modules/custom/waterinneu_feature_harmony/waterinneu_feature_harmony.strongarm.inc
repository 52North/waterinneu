<?php
/**
 * @file
 * waterinneu_feature_harmony.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function waterinneu_feature_harmony_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'features_admin_show_component_harmony_thread_type';
  $strongarm->value = 1;
  $export['features_admin_show_component_harmony_thread_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'features_component_locked_harmony_thread_type';
  $strongarm->value = 0;
  $export['features_component_locked_harmony_thread_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_harmony_core_harmony_thread_pattern';
  $strongarm->value = '';
  $export['pathauto_harmony_core_harmony_thread_pattern'] = $strongarm;

  return $export;
}
