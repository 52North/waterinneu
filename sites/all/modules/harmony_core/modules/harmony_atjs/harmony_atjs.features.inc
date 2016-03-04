<?php
/**
 * @file
 * harmony_atjs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function harmony_atjs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "atjs" && $api == "default_atjs_listener") {
    return array("version" => "1");
  }
}
