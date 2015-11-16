<?php
/**
 * @file
 * waterinneu_feature_tools.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function waterinneu_feature_tools_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create tool content'.
  $permissions['create tool content'] = array(
    'name' => 'create tool content',
    'roles' => array(
      'administrator' => 'administrator',
      'author' => 'author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any tool content'.
  $permissions['delete any tool content'] = array(
    'name' => 'delete any tool content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own tool content'.
  $permissions['delete own tool content'] = array(
    'name' => 'delete own tool content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any tool content'.
  $permissions['edit any tool content'] = array(
    'name' => 'edit any tool content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own tool content'.
  $permissions['edit own tool content'] = array(
    'name' => 'edit own tool content',
    'roles' => array(
      'administrator' => 'administrator',
      'author' => 'author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'publish revisions of any tool content'.
  $permissions['publish revisions of any tool content'] = array(
    'name' => 'publish revisions of any tool content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of own tool content'.
  $permissions['publish revisions of own tool content'] = array(
    'name' => 'publish revisions of own tool content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of any tool content'.
  $permissions['view revisions of any tool content'] = array(
    'name' => 'view revisions of any tool content',
    'roles' => array(
      'author' => 'author',
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of own tool content'.
  $permissions['view revisions of own tool content'] = array(
    'name' => 'view revisions of own tool content',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'revisioning',
  );

  return $permissions;
}
