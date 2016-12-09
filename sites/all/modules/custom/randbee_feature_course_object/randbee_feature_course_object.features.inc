<?php
/**
 * @file
 * randbee_feature_course_object.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function randbee_feature_course_object_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function randbee_feature_course_object_node_info() {
  $items = array(
    'course_object' => array(
      'name' => t('Course object'),
      'base' => 'node_content',
      'description' => t('Course object.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
