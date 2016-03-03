<?php
/**
 * @file
 * feature_service_requests_and_offerings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_service_requests_and_offerings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_service_requests_and_offerings_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function feature_service_requests_and_offerings_node_info() {
  $items = array(
    'service_offering' => array(
      'name' => t('Service Offering'),
      'base' => 'node_content',
      'description' => t('A service offering documents the proposition for support regarding a certain product by someone.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'service_request' => array(
      'name' => t('Service Request'),
      'base' => 'node_content',
      'description' => t('A service request documents the need for support regarding a certain product by someone.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
