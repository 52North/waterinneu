<?php
/**
 * @file
 * waterinneu_feature_configuration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function waterinneu_feature_configuration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "backup_migrate" && $api == "backup_migrate_exportables") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function waterinneu_feature_configuration_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_search_autocomplete_config_features_default_settings().
 */
function waterinneu_feature_configuration_search_autocomplete_config_features_default_settings() {
  return array(
    0 => array(
      'fid' => 1,
      'title' => 'Search page - Node Tab  (search/node/%)',
      'selector' => '#search-form[action="/search/node"] #edit-keys',
      'weight' => -2,
      'enabled' => 1,
      'parent_fid' => 0,
      'min_char' => 3,
      'max_sug' => 10,
      'no_results' => '{"label":"No results found for [search-phrase]. Click to perform full search.","value":"[search-phrase]","link":"","group":{"group_id":"no_results"}}',
      'all_results' => '{"label":"View all results for [search-phrase].","value":"[search-phrase]","link":"","group":{"group_id":"all_results"}}',
      'auto_submit' => 1,
      'auto_redirect' => 1,
      'translite' => 1,
      'data_source' => 'view',
      'data_callback' => 'search_autocomplete/autocomplete/1/',
      'data_static' => '',
      'data_view' => 'words_autocomplete',
      'theme' => 'basic-green.css',
    ),
  );
}
