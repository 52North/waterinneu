<?php
/**
 * @file
 * n52_feature_products.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function n52_feature_products_ctools_plugin_api($module = NULL, $api = NULL) {
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
function n52_feature_products_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function n52_feature_products_node_info() {
  $items = array(
    'tool' => array(
      'name' => t('Product'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('The submission of product specification sheets underlies a moderation workflow. Hence, adding new content might cost some time. Get in touch with the administrator for speeding things up using the <a href="/contact">helpdesk form</a>. <br/>
Please consider the following additional instructions to some of the fields below.
<br />
Product deletion is only possible by admins. If you want to have a product deleted, please use the <a href="/contact">contact form</a>.
Get in touch with our <a href="helpdeskt">helpdesk</a> if your content does not fit in this form.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
