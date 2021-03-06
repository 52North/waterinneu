<?php
/**
 * @file
 * n52_feature_menus.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function n52_feature_menus_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['custom_search_blocks-1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 1,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'custom_search_blocks',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'n52_wieu_theme' => array(
        'region' => 'header_top_right',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => -54,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['lang_dropdown-language'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'language',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'lang_dropdown',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'n52_wieu_theme' => array(
        'region' => 'header_top_right',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => -55,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-footer-3rd-links'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer-3rd-links',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'n52_wieu_theme' => array(
        'region' => 'footer_third',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-n52-footer-first-links'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-n52-footer-first-links',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'n52_wieu_theme' => array(
        'region' => 'footer_first',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-n52-footer-second-links'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-n52-footer-second-links',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'n52_wieu_theme' => array(
        'region' => 'footer_second',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-top-links'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-top-links',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'n52_wieu_theme' => array(
        'region' => 'header_top_right',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => -56,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main-menu',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'n52_wieu_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'n52_wieu_theme',
        'weight' => -36,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-user-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'user-menu',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'n52_wieu_theme' => array(
        'region' => 'header_top_right',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => -57,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
