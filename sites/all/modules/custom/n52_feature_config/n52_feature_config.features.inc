<?php
/**
 * @file
 * n52_feature_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function n52_feature_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "backup_migrate" && $api == "backup_migrate_exportables") {
    return array("version" => "1");
  }
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
function n52_feature_config_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function n52_feature_config_image_default_styles() {
  $styles = array();

  // Exported image style: n52_image_style_product_of_the_month.
  $styles['n52_image_style_product_of_the_month'] = array(
    'label' => '52N - Product of the Month',
    'effects' => array(
      3 => array(
        'name' => 'iek_image_resize',
        'data' => array(
          'width' => 475,
          'height' => 200,
          'blank_margin' => 0,
          'blank_margin_bg_color' => '#FFFFFF',
          'position' => 'middle_center',
          'x' => 0,
          'y' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: n52_image_style_teaser_photo.
  $styles['n52_image_style_teaser_photo'] = array(
    'label' => '52N - Teaser Photo',
    'effects' => array(),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function n52_feature_config_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Get in touch with our helpdesk if your content does not fit in this form. You can find the helpdesk following the support services tab.'),
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Get in touch with our helpdesk if your content does not fit in this form. You can find the helpdesk following the support services tab.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
