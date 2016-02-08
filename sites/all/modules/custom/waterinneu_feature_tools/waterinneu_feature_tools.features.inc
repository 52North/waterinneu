<?php
/**
 * @file
 * waterinneu_feature_tools.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function waterinneu_feature_tools_ctools_plugin_api($module = NULL, $api = NULL) {
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
function waterinneu_feature_tools_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function waterinneu_feature_tools_node_info() {
  $items = array(
    'tool' => array(
      'name' => t('Product'),
      'base' => 'node_content',
      'description' => t('Product specification sheet for project results of type tool, e.g. software.

'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Get in touch with our helpdesk if your tool does not fit in this form. You can find the helpdesk following the support services tab.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
