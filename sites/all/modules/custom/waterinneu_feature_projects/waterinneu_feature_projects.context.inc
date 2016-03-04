<?php
/**
 * @file
 * waterinneu_feature_projects.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function waterinneu_feature_projects_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
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
