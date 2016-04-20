<?php
/**
 * @file
 * n52_feature_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function n52_feature_events_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function n52_feature_events_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function n52_feature_events_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Event Description is missing. Please provide one and send to e.h.juerrens@52north.org.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Event deletion is only possible by admins. If you want to have an event deleted, please use the <a href="/contact">contact form</a>.

Get in touch with our <a href="helpdeskt">helpdesk</a> if your content does not fit in this form.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
