<?php
/**
 * @file
 * waterinneu_feature_harmony.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function waterinneu_feature_harmony_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'marketplace';
  $context->description = '';
  $context->tag = 'main_menu';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'marketplace*' => 'marketplace*',
        'thread*' => 'thread*',
        'post*' => 'post*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:marketplace',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('main_menu');
  $export['marketplace'] = $context;

  return $export;
}
