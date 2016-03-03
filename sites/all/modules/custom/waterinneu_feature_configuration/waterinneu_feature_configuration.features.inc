<?php
/**
 * @file
 * waterinneu_feature_configuration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function waterinneu_feature_configuration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "backup_migrate" && $api == "backup_migrate_exportables") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function waterinneu_feature_configuration_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
