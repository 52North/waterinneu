<?php
/**
 * @file
 * n52_feature_helpdesk.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function n52_feature_helpdesk_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer-right-links.
  $menus['menu-footer-right-links'] = array(
    'menu_name' => 'menu-footer-right-links',
    'title' => 'Footer Right Links',
    'description' => 'All links for the fourth or right most footer',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('All links for the fourth or right most footer');
  t('Footer Right Links');

  return $menus;
}
