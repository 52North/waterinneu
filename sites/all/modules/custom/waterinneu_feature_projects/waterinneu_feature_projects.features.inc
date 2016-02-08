<?php
/**
 * @file
 * waterinneu_feature_projects.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function waterinneu_feature_projects_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function waterinneu_feature_projects_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function waterinneu_feature_projects_node_info() {
  $items = array(
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('A project dealing with hydrological topics.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => t('Get in touch with our helpdesk if your content does not fit in this form. You can find the helpdesk following the support services tab.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
