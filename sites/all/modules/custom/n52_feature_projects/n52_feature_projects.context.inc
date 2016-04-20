<?php
/**
 * @file
 * n52_feature_projects.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function n52_feature_projects_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE;
  $context->api_version = 3;
  $context->name = 'projects';
  $context->description = '';
  $context->tag = 'main_menu';
  $context->conditions = array();
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('main_menu');
  $export['projects'] = $context;

  return $export;
}
