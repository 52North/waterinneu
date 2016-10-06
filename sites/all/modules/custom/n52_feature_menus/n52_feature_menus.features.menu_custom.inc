<?php
/**
 * @file
 * n52_feature_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function n52_feature_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-author.
  $menus['menu-author'] = array(
    'menu_name' => 'menu-author',
    'title' => 'Author',
    'description' => 'Contains everything regarding author tasks like adding new content',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-footer-3rd-links.
  $menus['menu-footer-3rd-links'] = array(
    'menu_name' => 'menu-footer-3rd-links',
    'title' => 'Footer 3rd Links',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-footer-right-links.
  $menus['menu-footer-right-links'] = array(
    'menu_name' => 'menu-footer-right-links',
    'title' => 'Footer 4th Links',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-n52-footer-first-links.
  $menus['menu-n52-footer-first-links'] = array(
    'menu_name' => 'menu-n52-footer-first-links',
    'title' => 'Footer 1st Links',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-n52-footer-second-links.
  $menus['menu-n52-footer-second-links'] = array(
    'menu_name' => 'menu-n52-footer-second-links',
    'title' => 'Footer 2nd Links',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-top-links.
  $menus['menu-top-links'] = array(
    'menu_name' => 'menu-top-links',
    'title' => 'Top-Level-Links (anon)',
    'description' => 'Holds all links that are in the top div.',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: navigation.
  $menus['navigation'] = array(
    'menu_name' => 'navigation',
    'title' => 'Navigation',
    'description' => 'THIS MENU IS NOT USED ATM.',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: user-menu.
  $menus['user-menu'] = array(
    'menu_name' => 'user-menu',
    'title' => 'User menu',
    'description' => 'The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Author');
  t('Contains everything regarding author tasks like adding new content');
  t('Footer 1st Links');
  t('Footer 2nd Links');
  t('Footer 3rd Links');
  t('Footer 4th Links');
  t('Holds all links that are in the top div.');
  t('Navigation');
  t('THIS MENU IS NOT USED ATM.');
  t('The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.');
  t('Top-Level-Links (anon)');
  t('User menu');

  return $menus;
}
