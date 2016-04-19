<?php
/**
 * @file
 * n52_feature_organisations.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function n52_feature_organisations_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_organisation:node/add/organisation.
  $menu_links['navigation_organisation:node/add/organisation'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/organisation',
    'router_path' => 'node/add/organisation',
    'link_title' => 'Organisation',
    'options' => array(
      'attributes' => array(
        'title' => 'Organisation Description',
      ),
      'identifier' => 'navigation_organisation:node/add/organisation',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'navigation_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Organisation');

  return $menu_links;
}
