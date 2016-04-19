<?php
/**
 * @file
 * n52_feature_organisations.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function n52_feature_organisations_ctools_plugin_api($module = NULL, $api = NULL) {
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
function n52_feature_organisations_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function n52_feature_organisations_node_info() {
  $items = array(
    'organisation' => array(
      'name' => t('Organisation'),
      'base' => 'node_content',
      'description' => t('Organisation Description missing. If you have any, please send a mail to e.h.juerrens@52north.org.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => t('Organisation deletion is only possible by admins. If you want to have an organisation deleted, please use the <a href="/contact">contact form</a>.

Get in touch with our <a href="helpdeskt">helpdesk</a> if your content does not fit in this form.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
