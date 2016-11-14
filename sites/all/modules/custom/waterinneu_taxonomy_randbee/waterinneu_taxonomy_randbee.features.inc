<?php
/**
 * @file
 * waterinneu_taxonomy_randbee.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function waterinneu_taxonomy_randbee_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
