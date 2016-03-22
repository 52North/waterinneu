<?php
/**
 * @file
 * feature_i18n.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_i18n_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
