<?php
/**
 * @file
 * waterinneu_feature_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function waterinneu_feature_menus_menu_default_menu_custom() {
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
  // Exported menu: menu-moderator.
  $menus['menu-moderator'] = array(
    'menu_name' => 'menu-moderator',
    'title' => 'Moderator',
    'description' => 'Everything regarding moderation tasks',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-top-level-links-registered-.
  $menus['menu-top-level-links-registered-'] = array(
    'menu_name' => 'menu-top-level-links-registered-',
    'title' => 'Top-Level-Links (registered)',
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
    'description' => 'The <em>Navigation</em> menu contains links intended for site visitors. Links are added to the <em>Navigation</em> menu automatically by some modules.',
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
  t('Everything regarding moderation tasks');
  t('Footer 3rd Links');
  t('Holds all links that are in the top div.');
  t('Moderator');
  t('Navigation');
  t('The <em>Navigation</em> menu contains links intended for site visitors. Links are added to the <em>Navigation</em> menu automatically by some modules.');
  t('The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.');
  t('Top-Level-Links (anon)');
  t('Top-Level-Links (registered)');
  t('User menu');

  return $menus;
}
