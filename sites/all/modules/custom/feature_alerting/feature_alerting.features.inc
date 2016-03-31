<?php
/**
 * @file
 * feature_alerting.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_alerting_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
