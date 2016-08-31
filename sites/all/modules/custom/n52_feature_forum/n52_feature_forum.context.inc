<?php
/**
 * @file
 * n52_feature_forum.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function n52_feature_forum_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'forum';
  $context->description = '';
  $context->tag = 'main_menu';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'forum*' => 'forum*',
        'thread*' => 'thread*',
        'post*' => 'post*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:forum',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('main_menu');
  $export['forum'] = $context;

  return $export;
}
