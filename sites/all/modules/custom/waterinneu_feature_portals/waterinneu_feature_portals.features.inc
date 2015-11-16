<?php
/**
 * @file
 * waterinneu_feature_portals.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function waterinneu_feature_portals_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function waterinneu_feature_portals_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function waterinneu_feature_portals_node_info() {
  $items = array(
    'portal' => array(
      'name' => t('Portal'),
      'base' => 'node_content',
      'description' => t('A website that provides means for finding projects, organisations, or experts dealing with a common topic.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => t('Portal content type submission guildelines.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
