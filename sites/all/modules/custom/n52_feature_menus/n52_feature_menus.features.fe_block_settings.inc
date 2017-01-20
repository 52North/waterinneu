<?php
/**
 * @file
 * n52_feature_menus.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function n52_feature_menus_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  return $export;
}
