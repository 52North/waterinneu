<?php
/**
 * @file
 * feature_search.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function feature_search_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Advanced Search Instructions Block';
  $fe_block_boxes->format = 'full_html_plain_no_filter_';
  $fe_block_boxes->machine_name = 'advanced_search_instructions';
  $fe_block_boxes->body = 'Please select the type of content by clicking on the corresponding tab and use the rendered search form than.';

  $export['advanced_search_instructions'] = $fe_block_boxes;

  return $export;
}
