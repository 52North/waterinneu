<?php
/**
 * @file
 * n52_feature_events.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function n52_feature_events_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views--exp-events-page'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '-exp-events-page',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'matchmaking/events',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'n52_wieu_theme' => array(
        'region' => 'help',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  return $export;
}
