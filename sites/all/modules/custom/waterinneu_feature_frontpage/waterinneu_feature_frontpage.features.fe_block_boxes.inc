<?php
/**
 * @file
 * waterinneu_feature_frontpage.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function waterinneu_feature_frontpage_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'landingpage_updates';
  $fe_block_boxes->format = 'full_html_plain_no_filter_';
  $fe_block_boxes->machine_name = 'landingpage_updates';
  $fe_block_boxes->body = '&nbsp;';

  $export['landingpage_updates'] = $fe_block_boxes;

  return $export;
}
