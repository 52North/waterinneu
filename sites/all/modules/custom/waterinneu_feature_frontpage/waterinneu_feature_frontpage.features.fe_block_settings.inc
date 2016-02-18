<?php
/**
 * @file
 * waterinneu_feature_frontpage.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function waterinneu_feature_frontpage_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['twitter_block-1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 1,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'twitter_block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'bootstrap_business' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap_business',
        'weight' => 0,
      ),
      'fusion_marina' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'fusion_marina',
        'weight' => 0,
      ),
      'n52_wieu_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'n52_wieu_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  return $export;
}
