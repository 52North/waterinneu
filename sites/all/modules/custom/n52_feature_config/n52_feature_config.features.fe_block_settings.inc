<?php
/**
 * @file
 * n52_feature_config.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function n52_feature_config_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-n52_funding_footer'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'n52_funding_footer',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'n52_wieu_theme' => array(
        'region' => 'header_top_left',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => -57,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['block-n52_wieu_you_can_also_e_learning'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'n52_wieu_you_can_also_e_learning',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'e-learning
e-learning/*
success-story
success-story/*',
    'roles' => array(),
    'themes' => array(
      'n52_wieu_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => -54,
      ),
    ),
    'title' => 'You can also:',
    'visibility' => 1,
  );

  $export['block-n52_wieu_you_can_also_join_us'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'n52_wieu_you_can_also_join_us',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'join-us',
    'roles' => array(),
    'themes' => array(
      'n52_wieu_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => -55,
      ),
    ),
    'title' => 'You can also:',
    'visibility' => 1,
  );

  $export['block-n52_wieu_you_can_also_products'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'n52_wieu_you_can_also_products',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'product
product/*
products-and-services
organisation
organisation/*
matchmaking*',
    'roles' => array(),
    'themes' => array(
      'n52_wieu_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => -56,
      ),
    ),
    'title' => 'You can also:',
    'visibility' => 1,
  );

  $export['comment-recent'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'recent',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'comment',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'n52_wieu_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'n52_wieu_theme',
        'weight' => -28,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['lang_dropdown-language_content'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'language_content',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'lang_dropdown',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'n52_wieu_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'n52_wieu_theme',
        'weight' => -37,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['locale-language'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'language',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'locale',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'n52_wieu_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'n52_wieu_theme',
        'weight' => -38,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['locale-language_content'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'language_content',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'locale',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'n52_wieu_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'n52_wieu_theme',
        'weight' => -39,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-author'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-author',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '<front>
e-learning*
forum*
thread*',
    'roles' => array(
      'administrator' => 3,
      'authenticated user' => 2,
      'moderator' => 9,
    ),
    'themes' => array(
      'n52_wieu_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => -53,
      ),
    ),
    'title' => 'My actions',
    'visibility' => 0,
  );

  return $export;
}
