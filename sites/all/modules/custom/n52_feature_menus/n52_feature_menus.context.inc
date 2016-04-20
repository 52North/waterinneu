<?php
/**
 * @file
 * n52_feature_menus.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function n52_feature_menus_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'about';
  $context->description = '';
  $context->tag = 'main_menu';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'about' => 'about',
        'about/*' => 'about/*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:node/8772',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('main_menu');
  $export['about'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'author';
  $context->description = 'Everything that is relevant for authors';
  $context->tag = 'menu';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'author' => 'author',
        'marketplace_author' => 'marketplace_author',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-author' => array(
          'module' => 'menu',
          'delta' => 'menu-author',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Everything that is relevant for authors');
  t('menu');
  $export['author'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home';
  $context->description = '';
  $context->tag = 'main_menu';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:<front>',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('main_menu');
  $export['home'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'moderator';
  $context->description = 'Everything that is relevant for moderators';
  $context->tag = 'menu';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'marketplace_moderator' => 'marketplace_moderator',
        'moderator' => 'moderator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-moderator' => array(
          'module' => 'menu',
          'delta' => 'menu-moderator',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Everything that is relevant for moderators');
  t('menu');
  $export['moderator'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'other';
  $context->description = '';
  $context->tag = 'main_menu';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'organisation/*' => 'organisation/*',
        'organisations' => 'organisations',
        'portal*' => 'portal*',
        'n52*' => 'n52*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:node/42',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('main_menu');
  $export['other'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'products';
  $context->description = '';
  $context->tag = 'main_menu';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'product*' => 'product*',
        'product/*' => 'product/*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:product',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('main_menu');
  $export['products'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_guide';
  $context->description = '';
  $context->tag = 'main_menu';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user-guide' => 'user-guide',
        'user-guide/*' => 'user-guide/*',
        'filter/tips' => 'filter/tips',
        'glossary' => 'glossary',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:node/33',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('main_menu');
  $export['user_guide'] = $context;

  return $export;
}
