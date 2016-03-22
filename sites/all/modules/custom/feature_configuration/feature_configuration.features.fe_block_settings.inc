<?php
/**
 * @file
 * feature_configuration.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function feature_configuration_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['backup_migrate-quick_backup'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'quick_backup',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'backup_migrate',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => 'dashboard_main',
        'status' => 1,
        'theme' => 'adminimal',
        'weight' => 1,
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

  $export['block-advanced_search_instructions'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
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

  $export['block-contact_additional_information'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'contact_additional_information',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'contact',
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
        'weight' => -42,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['block-footer_third_column'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(
      0 => 'en',
    ),
    'i18n_mode' => 1,
    'machine_name' => 'footer_third_column',
    'module' => 'block',
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
        'region' => 'footer_third',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
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
      'adminimal' => array(
        'region' => 'dashboard_main',
        'status' => 1,
        'theme' => 'adminimal',
        'weight' => 2,
      ),
      'n52_wieu_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'n52_wieu_theme',
        'weight' => -22,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['context_ui-devel'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'devel',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'context_ui',
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
        'weight' => -41,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['context_ui-editor'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'editor',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'context_ui',
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
        'weight' => -42,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['devel-execute_php'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'execute_php',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'devel',
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
        'weight' => -38,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['devel-switch_user'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'switch_user',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'devel',
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
        'weight' => -13,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['devel_node_access-dna_node'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'dna_node',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'devel_node_access',
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
        'region' => 'footer',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => -42,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['devel_node_access-dna_user'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'dna_user',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'devel_node_access',
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
        'region' => 'footer',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => -40,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['diff-inline'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'inline',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'diff',
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
        'weight' => -34,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['faq-faq_categories'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'faq_categories',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'faq',
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
        'weight' => -36,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['harmony_core-reply_form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'reply_form',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'harmony_core',
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
        'weight' => 10,
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
        'weight' => -31,
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
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -5,
      ),
      'n52_wieu_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'n52_wieu_theme',
        'weight' => -32,
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
        'weight' => -33,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['markdown-markdown_help'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'markdown_help',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'markdown',
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
        'weight' => -28,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-devel'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'devel',
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
        'region' => 'footer',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => -43,
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
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'n52_wieu_theme' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => -43,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-moderator'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-moderator',
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
      'moderator' => 9,
    ),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'n52_wieu_theme' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => -42,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['node-syndicate'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'syndicate',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'node',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 1,
      ),
      'n52_wieu_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'n52_wieu_theme',
        'weight' => -12,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['revisioning-pending'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'pending',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'revisioning',
    'node_types' => array(),
    'pages' => '<front>
e-learning*
forum*
thread*',
    'roles' => array(
      'administrator' => 3,
      'moderator' => 9,
    ),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -10,
      ),
      'n52_wieu_theme' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => -41,
      ),
    ),
    'title' => 'Pending Revisions',
    'visibility' => 0,
  );

  $export['shortcut-shortcuts'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'shortcuts',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'shortcut',
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
        'weight' => -18,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['superfish-1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 1,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'superfish',
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
        'weight' => -17,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['superfish-2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 2,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'superfish',
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
        'weight' => -16,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['superfish-3'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 3,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'superfish',
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
        'weight' => -15,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['superfish-4'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 4,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'superfish',
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
        'weight' => -14,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-help'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'help',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => 'help',
        'status' => 1,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'n52_wieu_theme' => array(
        'region' => 'help',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => -38,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'n52_wieu_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'n52_wieu_theme',
        'weight' => -41,
      ),
    ),
    'title' => '',
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
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -4,
      ),
      'n52_wieu_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'n52_wieu_theme',
        'weight' => -30,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-management'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'management',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -3,
      ),
      'n52_wieu_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'n52_wieu_theme',
        'weight' => -29,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-navigation'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'navigation',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -2,
      ),
      'n52_wieu_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'n52_wieu_theme',
        'weight' => -27,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-powered-by'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'powered-by',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -1,
      ),
      'n52_wieu_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'n52_wieu_theme',
        'weight' => -26,
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
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 2,
      ),
      'n52_wieu_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'n52_wieu_theme',
        'weight' => 13,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-12'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 12,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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

  $export['tagclouds-13'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 13,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => 9,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-14'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 14,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => 8,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-15'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 15,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => 1,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-16'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 16,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => -4,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-17'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 17,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => 2,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-18'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 18,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => 6,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-19'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 19,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => -9,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-20'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 20,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => -11,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-21'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 21,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => 5,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-22'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 22,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => 7,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-23'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 23,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => -8,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-24'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 24,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => -7,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-25'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 25,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => -6,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-26'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 26,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => -5,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-27'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 27,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => -1,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-28'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 28,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => 3,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-29'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 29,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => -2,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-3'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 3,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => -3,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-30'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 30,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => 4,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-31'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 31,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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

  $export['tagclouds-7'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 7,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => -10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tagclouds-8'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 8,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tagclouds',
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
        'weight' => -39,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'login',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'adminimal',
        'weight' => 10,
      ),
      'n52_wieu_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'n52_wieu_theme',
        'weight' => 12,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-new'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'new',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'adminimal',
        'weight' => 1,
      ),
      'n52_wieu_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'n52_wieu_theme',
        'weight' => 18,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-online'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'online',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'administrator' => 3,
    ),
    'themes' => array(
      'adminimal' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'n52_wieu_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'n52_wieu_theme',
        'weight' => 19,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-0a085b397a9696f176b4abbe0949c53b'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '0a085b397a9696f176b4abbe0949c53b',
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

  $export['views-490cba9e5998ba07082022e998419960'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '490cba9e5998ba07082022e998419960',
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
        'weight' => 14,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-84884952df7f4e4d5e4af3511b30976f'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '84884952df7f4e4d5e4af3511b30976f',
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

  $export['views-885d349364fe158251c325cddb8257d5'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '885d349364fe158251c325cddb8257d5',
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
        'weight' => 22,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-advanced_event_search-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'advanced_event_search-block',
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

  $export['views-advanced_search_products-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'advanced_search_products-block',
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

  $export['views-c4eb6263e23f52a9df67c68255610393'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'c4eb6263e23f52a9df67c68255610393',
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

  $export['views-faq-faq_random'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'faq-faq_random',
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
        'weight' => -24,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-faq-faq_recent'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'faq-faq_recent',
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
        'weight' => -23,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-my_content-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'my_content-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'users/*
user',
    'roles' => array(
      'administrator' => 3,
      'authenticated user' => 2,
      'moderator' => 9,
    ),
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
        'weight' => 17,
      ),
    ),
    'title' => 'My Content',
    'visibility' => 1,
  );

  return $export;
}
