<?php
/**
 * @file
 * feature_configuration.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function feature_configuration_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'matchmaking';
  $context->description = '';
  $context->tag = 'main_menu';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'matchmaking*' => 'matchmaking*',
        'matchmaking/*' => 'matchmaking/*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:node/8784',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('main_menu');
  $export['matchmaking'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'my_content';
  $context->description = 'Show my content view block only on own profile page';
  $context->tag = 'views';
  $context->conditions = array(
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'current',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-my_content-block' => array(
          'module' => 'views',
          'delta' => 'my_content-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Show my content view block only on own profile page');
  t('views');
  $export['my_content'] = $context;

  return $export;
}
