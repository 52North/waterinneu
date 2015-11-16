<?php
/**
 * @file
 * waterinneu_feature_organisation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function waterinneu_feature_organisation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function waterinneu_feature_organisation_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function waterinneu_feature_organisation_node_info() {
  $items = array(
    'organisation' => array(
      'name' => t('Organisation'),
      'base' => 'node_content',
      'description' => t('Organisation Description'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => t('Explanation or submission guidelines for organisation entities'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
