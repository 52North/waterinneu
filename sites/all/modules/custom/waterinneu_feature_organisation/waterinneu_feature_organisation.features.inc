<?php
/**
 * @file
 * waterinneu_feature_organisation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function waterinneu_feature_organisation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
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
      'help' => t('Get in touch with our helpdesk if your content does not fit in this form. You can find the helpdesk following the support services tab.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
