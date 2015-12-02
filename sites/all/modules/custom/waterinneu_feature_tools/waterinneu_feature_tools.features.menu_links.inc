<?php
/**
 * @file
 * waterinneu_feature_tools.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function waterinneu_feature_tools_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_tools:tools.
  $menu_links['main-menu_tools:tools'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'tools',
    'router_path' => 'tools',
    'link_title' => 'Tools',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_tools:tools',
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
  // Exported menu link: navigation_tool:node/add/tool.
  $menu_links['navigation_tool:node/add/tool'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/tool',
    'router_path' => 'node/add/tool',
    'link_title' => 'Tool',
    'options' => array(
      'attributes' => array(
        'title' => 'Product specification sheet for project results of type tool, e.g. software.',
      ),
      'identifier' => 'navigation_tool:node/add/tool',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'navigation_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Tool');
  t('Tools');

  return $menu_links;
}
