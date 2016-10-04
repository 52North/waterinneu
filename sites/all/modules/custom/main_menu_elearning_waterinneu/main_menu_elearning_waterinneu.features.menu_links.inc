<?php
/**
 * @file
 * main_menu_elearning_waterinneu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function main_menu_elearning_waterinneu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_e-learning:e-learning.
  $menu_links['main-menu_e-learning:e-learning'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'e-learning',
    'router_path' => 'e-learning',
    'link_title' => 'E-learning',
    'options' => array(
      'identifier' => 'main-menu_e-learning:e-learning',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('E-learning');

  return $menu_links;
}
