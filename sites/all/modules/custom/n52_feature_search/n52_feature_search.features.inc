<?php
/**
 * @file
 * n52_feature_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function n52_feature_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function n52_feature_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_search_autocomplete_config_features_default_settings().
 */
function n52_feature_search_search_autocomplete_config_features_default_settings() {
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
    1 => array(
      'fid' => 2,
      'title' => 'Search page - User Tab  (search/user/%)',
      'selector' => '#search-form[action="/search/user"] #edit-keys',
      'weight' => -1,
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
      'data_callback' => 'search_autocomplete/autocomplete/2/',
      'data_static' => '',
      'data_view' => 'users_autocomplete',
      'theme' => 'user-blue.css',
    ),
    2 => array(
      'fid' => 3,
      'title' => 'Search Block',
      'selector' => '#edit-search-block-form--2',
      'weight' => -3,
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
      'data_callback' => 'search_autocomplete/autocomplete/3/',
      'data_static' => '',
      'data_view' => 'words_autocomplete',
      'theme' => 'basic-green.css',
    ),
    3 => array(
      'fid' => 4,
      'title' => 'Harmony Post',
      'selector' => 'textarea',
      'weight' => -4,
      'enabled' => 0,
      'parent_fid' => 0,
      'min_char' => 3,
      'max_sug' => 10,
      'no_results' => '{"label":"","value":"","link":"","group":{"group_id":"no_results"}}',
      'all_results' => '{"label":"","value":"","link":"","group":{"group_id":"all_results"}}',
      'auto_submit' => 0,
      'auto_redirect' => 0,
      'translite' => 1,
      'data_source' => 'view',
      'data_callback' => 'search_autocomplete/autocomplete/4/',
      'data_static' => '',
      'data_view' => 'all_autocomplete',
      'theme' => 'basic-green.css',
    ),
    4 => array(
      'fid' => 5,
      'title' => 'Global Search',
      'selector' => '#edit-custom-search-blocks-form-1--2',
      'weight' => 0,
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
      'data_callback' => 'search_autocomplete/autocomplete/5/',
      'data_static' => '',
      'data_view' => 'nodes_autocomplete',
      'theme' => 'basic-blue.css',
    ),
  );
}
