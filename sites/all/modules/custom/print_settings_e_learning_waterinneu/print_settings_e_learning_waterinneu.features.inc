<?php
/**
 * @file
 * print_settings_e_learning_waterinneu.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function print_settings_e_learning_waterinneu_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
