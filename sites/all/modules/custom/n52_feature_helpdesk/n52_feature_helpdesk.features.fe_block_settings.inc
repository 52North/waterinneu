<?php
/**
 * @file
 * n52_feature_helpdesk.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function n52_feature_helpdesk_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-menu-footer-right-links'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer-right-links',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu',
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
        'region' => 'footer_fourth',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => -47,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
