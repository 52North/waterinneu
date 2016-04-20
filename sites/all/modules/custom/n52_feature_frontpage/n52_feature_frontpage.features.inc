<?php
/**
 * @file
 * n52_feature_frontpage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function n52_feature_frontpage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function n52_feature_frontpage_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
