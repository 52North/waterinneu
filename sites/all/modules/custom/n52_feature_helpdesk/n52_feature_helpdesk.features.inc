<?php
/**
 * @file
 * n52_feature_helpdesk.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function n52_feature_helpdesk_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "captcha" && $api == "captcha") {
    return array("version" => "1");
  }
}
