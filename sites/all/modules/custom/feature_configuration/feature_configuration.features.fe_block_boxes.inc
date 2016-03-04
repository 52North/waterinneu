<?php
/**
 * @file
 * feature_configuration.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function feature_configuration_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Content of the right column of the footer';
  $fe_block_boxes->format = 'full_html_tinymce';
  $fe_block_boxes->machine_name = 'footer_right_content';
  $fe_block_boxes->body = '<p><a href="/contact">Contact/Helpdesk</a></p>';

  $export['footer_right_content'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Content of the third column of the footer';
  $fe_block_boxes->format = 'full_html_tinymce';
  $fe_block_boxes->machine_name = 'footer_third_column';
  $fe_block_boxes->body = '<p><a href="imprint">Imprint</a></p>';

  $export['footer_third_column'] = $fe_block_boxes;

  return $export;
}
