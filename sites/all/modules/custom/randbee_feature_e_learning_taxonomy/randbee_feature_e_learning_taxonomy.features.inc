<?php
/**
 * @file
 * randbee_feature_e_learning_taxonomy.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function randbee_feature_e_learning_taxonomy_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
