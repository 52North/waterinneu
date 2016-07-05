<?php
/**
 * @file
 * n52_feature_success_story.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function n52_feature_success_story_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function n52_feature_success_story_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function n52_feature_success_story_node_info() {
  $items = array(
    'n52_sucess_story' => array(
      'name' => t('Success Stories'),
      'base' => 'node_content',
      'description' => t('A Sucess Studies describes the application of a product of the market place. It should give details on the implementation and a point of contact for further discussions, e.g. in the forum of the marketplace.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
