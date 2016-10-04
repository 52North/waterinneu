<?php
/**
 * @file
 * n52_feature_config.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function n52_feature_config_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'product_and_services';
  $context->description = 'set breadcrumbs for product and services';
  $context->tag = 'theme';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'products-and-services' => 'products-and-services',
      ),
    ),
  );
  $context->reactions = array(
    'breadcrumb' => array(
      0 => 'main-menu:product',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('set breadcrumbs for product and services');
  t('theme');
  $export['product_and_services'] = $context;

  return $export;
}
