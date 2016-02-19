<?php
/**
 * @file
 * waterinneu_feature_organisation.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function waterinneu_feature_organisation_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views--exp-organisations-page'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '-exp-organisations-page',
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
        'region' => 'help',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => -33,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
