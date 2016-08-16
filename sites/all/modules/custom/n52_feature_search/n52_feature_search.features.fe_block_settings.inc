<?php
/**
 * @file
 * n52_feature_search.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function n52_feature_search_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-advanced_search_instructions'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'advanced_search_instructions',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'search/advanced',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'n52_wieu_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => 0,
      ),
    ),
    'title' => 'Advanced Search',
    'visibility' => 1,
  );

  $export['current_search-standard'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'standard',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'current_search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'n52_wieu_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'n52_wieu_theme',
        'weight' => -43,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['search-form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'form',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'search',
    'node_types' => array(),
    'pages' => 'search*',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'adminimal',
        'weight' => 2,
      ),
      'n52_wieu_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'n52_wieu_theme',
        'weight' => -26,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
