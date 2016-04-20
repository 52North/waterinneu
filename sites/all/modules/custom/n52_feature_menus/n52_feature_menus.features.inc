<?php
/**
 * @file
 * n52_feature_menus.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function n52_feature_menus_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
