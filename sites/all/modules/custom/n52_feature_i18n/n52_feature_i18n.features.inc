<?php
/**
 * @file
 * n52_feature_i18n.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function n52_feature_i18n_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_tmgmt_translator().
 */
function n52_feature_i18n_default_tmgmt_translator() {
  $items = array();
  $items['file'] = entity_import('tmgmt_translator', '{
    "name" : "file",
    "label" : "File translator (auto created)",
    "description" : "File translator that exports and imports files.",
    "weight" : "0",
    "plugin" : "file",
    "settings" : {
      "export_format" : "xlf",
      "allow_override" : true,
      "scheme" : "public",
      "xliff_processing" : false
    },
    "rdf_mapping" : []
  }');
  $items['local'] = entity_import('tmgmt_translator', '{
    "name" : "local",
    "label" : "Local Translator (auto created)",
    "description" : "Allows local users to process translation jobs.",
    "weight" : "0",
    "plugin" : "local",
    "settings" : { "auto_accept" : 0, "allow_all" : 1 },
    "rdf_mapping" : []
  }');
  return $items;
}
