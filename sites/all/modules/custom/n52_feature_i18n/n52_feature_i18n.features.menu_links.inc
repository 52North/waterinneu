<?php
/**
 * @file
 * n52_feature_i18n.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function n52_feature_i18n_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_frequently-asked-questions:faq-page.
  $menu_links['navigation_frequently-asked-questions:faq-page'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'faq-page',
    'router_path' => 'faq-page',
    'link_title' => 'Frequently Asked Questions',
    'options' => array(
      'identifier' => 'navigation_frequently-asked-questions:faq-page',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: navigation_tags:tagclouds.
  $menu_links['navigation_tags:tagclouds'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'tagclouds',
    'router_path' => 'tagclouds',
    'link_title' => 'Tags',
    'options' => array(
      'identifier' => 'navigation_tags:tagclouds',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: navigation_user-list:profile.
  $menu_links['navigation_user-list:profile'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'profile',
    'router_path' => 'profile',
    'link_title' => 'User list',
    'options' => array(
      'identifier' => 'navigation_user-list:profile',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Frequently Asked Questions');
  t('Tags');
  t('User list');

  return $menu_links;
}
