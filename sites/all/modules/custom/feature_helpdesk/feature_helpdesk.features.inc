<?php
/**
 * @file
 * feature_helpdesk.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_helpdesk_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "captcha" && $api == "captcha") {
    return array("version" => "1");
  }
}
