<?php
/**
 * @file
 * n52_feature_frontpage.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function n52_feature_frontpage_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  return $export;
}
