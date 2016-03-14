<?php
/**
 * @file
 * waterinneu_feature_harmony.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function waterinneu_feature_harmony_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function waterinneu_feature_harmony_field_default_field_instances_alter(&$data) {
  if (isset($data['harmony_post-harmony_post-field_harmony_text'])) {
    $data['harmony_post-harmony_post-field_harmony_text']['settings']['better_formats']['allowed_formats']['full_html_plain_no_filter_'] = 0; /* WAS: '' */
    $data['harmony_post-harmony_post-field_harmony_text']['settings']['better_formats']['allowed_formats']['full_html_tinymce'] = 0; /* WAS: '' */
    $data['harmony_post-harmony_post-field_harmony_text']['settings']['better_formats']['default_order_wrapper']['formats']['full_html_plain_no_filter_'] = array(
      'weight' => 0,
    ); /* WAS: '' */
    $data['harmony_post-harmony_post-field_harmony_text']['settings']['better_formats']['default_order_wrapper']['formats']['full_html_tinymce'] = array(
      'weight' => -7,
    ); /* WAS: '' */
    $data['harmony_post-harmony_post-field_harmony_text']['settings']['linkit'] = array(
      'button_text' => 'Search',
      'enable' => 0,
      'profile' => '',
    ); /* WAS: '' */
    $data['harmony_post-harmony_post-field_harmony_text']['settings']['text_processing'] = 0; /* WAS: 1 */
  }
}

/**
 * Implements hook_default_harmony_thread_type().
 */
function waterinneu_feature_harmony_default_harmony_thread_type() {
  $items = array();
  $items['harmony_thread'] = entity_import('harmony_thread_type', '{ "type" : "harmony_thread", "label" : "Thread", "rdf_mapping" : [] }');
  return $items;
}
