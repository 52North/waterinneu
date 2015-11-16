<?php
/**
 * @file
 * waterinneu_feature_frontpage.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function waterinneu_feature_frontpage_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-front-page-buttons_ask-a-question:thread/add.
  $menu_links['menu-front-page-buttons_ask-a-question:thread/add'] = array(
    'menu_name' => 'menu-front-page-buttons',
    'link_path' => 'thread/add',
    'router_path' => 'thread/add',
    'link_title' => 'Ask a question!',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'ignore_access_roles' => array(
        1 => 1,
        2 => 2,
        8 => 8,
        10 => 10,
        9 => 9,
        11 => 11,
        3 => 3,
      ),
      'identifier' => 'menu-front-page-buttons_ask-a-question:thread/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-front-page-buttons_neu-hier:node/33.
  $menu_links['menu-front-page-buttons_neu-hier:node/33'] = array(
    'menu_name' => 'menu-front-page-buttons',
    'link_path' => 'node/33',
    'router_path' => 'node/%',
    'link_title' => 'Neu hier?',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-front-page-buttons_neu-hier:node/33',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'de',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-front-page-buttons_new-here:node/33.
  $menu_links['menu-front-page-buttons_new-here:node/33'] = array(
    'menu_name' => 'menu-front-page-buttons',
    'link_path' => 'node/33',
    'router_path' => 'node/%',
    'link_title' => 'New here?',
    'options' => array(
      'attributes' => array(
        'title' => 'Link to how to use the portal',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-front-page-buttons_new-here:node/33',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-front-page-buttons_stell-eine-frage:thread/add.
  $menu_links['menu-front-page-buttons_stell-eine-frage:thread/add'] = array(
    'menu_name' => 'menu-front-page-buttons',
    'link_path' => 'thread/add',
    'router_path' => 'thread/add',
    'link_title' => 'Stell eine Frage!',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'ignore_access_roles' => array(
        1 => 1,
        2 => 2,
        8 => 8,
        10 => 10,
        9 => 9,
        11 => 11,
        3 => 3,
      ),
      'identifier' => 'menu-front-page-buttons_stell-eine-frage:thread/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'de',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Ask a question!');
  t('Neu hier?');
  t('New here?');
  t('Stell eine Frage!');

  return $menu_links;
}
