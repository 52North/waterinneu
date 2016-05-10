<?php
/**
 * @file
 * n52_feature_service_requests_and_offerings.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function n52_feature_service_requests_and_offerings_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views--exp-service_offerings-page'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '-exp-service_offerings-page',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'matchmaking/service-offerings',
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
        'weight' => -43,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views--exp-service_requests-page'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '-exp-service_requests-page',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'matchmaking/service-requests',
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
    'title' => '',
    'visibility' => 1,
  );

  $export['views-5533515c7cf03440898f8e331eb70e6d'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '5533515c7cf03440898f8e331eb70e6d',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
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
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-8cb0ff3fc943e490cd77766adfc2089e'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '8cb0ff3fc943e490cd77766adfc2089e',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
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
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
