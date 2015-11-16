<?php
/**
 * @file
 * waterinneu_feature_portals.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function waterinneu_feature_portals_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create portal content'.
  $permissions['create portal content'] = array(
    'name' => 'create portal content',
    'roles' => array(
      'administrator' => 'administrator',
      'author' => 'author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any portal content'.
  $permissions['delete any portal content'] = array(
    'name' => 'delete any portal content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own portal content'.
  $permissions['delete own portal content'] = array(
    'name' => 'delete own portal content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any portal content'.
  $permissions['edit any portal content'] = array(
    'name' => 'edit any portal content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own portal content'.
  $permissions['edit own portal content'] = array(
    'name' => 'edit own portal content',
    'roles' => array(
      'administrator' => 'administrator',
      'author' => 'author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'publish revisions of any portal content'.
  $permissions['publish revisions of any portal content'] = array(
    'name' => 'publish revisions of any portal content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of own portal content'.
  $permissions['publish revisions of own portal content'] = array(
    'name' => 'publish revisions of own portal content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of any portal content'.
  $permissions['view revisions of any portal content'] = array(
    'name' => 'view revisions of any portal content',
    'roles' => array(
      'author' => 'author',
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of own portal content'.
  $permissions['view revisions of own portal content'] = array(
    'name' => 'view revisions of own portal content',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'revisioning',
  );

  return $permissions;
}
