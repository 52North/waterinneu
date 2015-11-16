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

  // Exported menu link: management_harmony:admin/harmony.
  $menu_links['management_harmony:admin/harmony'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/harmony',
    'router_path' => 'admin/harmony',
    'link_title' => 'Harmony',
    'options' => array(
      'attributes' => array(
        'title' => 'Harmony dashboard.',
      ),
      'identifier' => 'management_harmony:admin/harmony',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_rebuild-supporting-harmony-entity-data:admin/harmony/config/general/rebuild.
  $menu_links['management_rebuild-supporting-harmony-entity-data:admin/harmony/config/general/rebuild'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/harmony/config/general/rebuild',
    'router_path' => 'admin/harmony/config/general/rebuild',
    'link_title' => 'Rebuild supporting Harmony entity data',
    'options' => array(
      'attributes' => array(
        'title' => 'Rebuild the supporting data used by Harmony entities.',
      ),
      'identifier' => 'management_rebuild-supporting-harmony-entity-data:admin/harmony/config/general/rebuild',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
    'parent_identifier' => 'management_general-settings:admin/harmony/config/general',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Harmony');
  t('Rebuild supporting Harmony entity data');

  return $menu_links;
}
