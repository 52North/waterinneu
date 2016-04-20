<?php
/**
 * @file
 * n52_feature_products.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function n52_feature_products_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE;
  $context->api_version = 3;
  $context->name = 'tools';
  $context->description = '';
  $context->tag = 'main_menu';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'tool*' => 'tool*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:tools',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('main_menu');
  $export['tools'] = $context;

  return $export;
}
