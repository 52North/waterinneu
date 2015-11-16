<?php
/**
 * @file
 * waterinneu_feature_harmony.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function waterinneu_feature_harmony_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_marketplace:marketplace.
  $menu_links['main-menu_marketplace:marketplace'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'marketplace',
    'router_path' => 'marketplace',
    'link_title' => 'Marketplace',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_marketplace:marketplace',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: navigation_recent-posts:tracker.
  $menu_links['navigation_recent-posts:tracker'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'tracker',
    'router_path' => 'tracker',
    'link_title' => 'Recent posts',
    'options' => array(
      'identifier' => 'navigation_recent-posts:tracker',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Marketplace');
  t('Recent posts');

  return $menu_links;
}
