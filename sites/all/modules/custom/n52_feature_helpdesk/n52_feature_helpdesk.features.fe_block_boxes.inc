<?php
/**
 * @file
 * n52_feature_helpdesk.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function n52_feature_helpdesk_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Additional information for contact form';
  $fe_block_boxes->format = 'full_html_plain_no_filter_';
  $fe_block_boxes->machine_name = 'contact_additional_information';
  $fe_block_boxes->body = '<style type="text/css">
.page-title {
    display: none;
}
</style>
<h1>What would you like help with?</h1>';

  $export['contact_additional_information'] = $fe_block_boxes;

  return $export;
}
