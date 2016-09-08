<?php
/**
 * @file
 * n52_feature_frontpage.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function n52_feature_frontpage_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'landingpage_updates';
  $fe_block_boxes->format = 'full_html_plain_no_filter_';
  $fe_block_boxes->machine_name = 'landingpage_updates';
  $fe_block_boxes->body = '&nbsp;';

  $export['landingpage_updates'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'An immediate introduction to the user';
  $fe_block_boxes->format = 'plain_text';
  $fe_block_boxes->machine_name = 'n52_landingpage_introduction';
  $fe_block_boxes->body = 'The WaterInnEU Marketplace is a market led innovation platform that screens the most relevant products and services for River Basin Managers and accelerates their uptake through targeted dissemination and support services.';

  $export['n52_landingpage_introduction'] = $fe_block_boxes;

  return $export;
}
