<?php
/**
 * @file
 * feature_default_nodes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_default_nodes_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
