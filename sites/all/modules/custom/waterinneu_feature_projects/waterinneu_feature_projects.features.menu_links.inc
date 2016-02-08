<?php
/**
 * @file
 * waterinneu_feature_projects.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function waterinneu_feature_projects_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_project:node/add/project.
  $menu_links['navigation_project:node/add/project'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/project',
    'router_path' => 'node/add/project',
    'link_title' => 'Project',
    'options' => array(
      'attributes' => array(
        'title' => 'A project dealing with hydrological topics.',
      ),
      'identifier' => 'navigation_project:node/add/project',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'navigation_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Project');

  return $menu_links;
}
