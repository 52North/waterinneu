<?php
/**
 * @file
 * waterinneu_feature_projects.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function waterinneu_feature_projects_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create project content'.
  $permissions['create project content'] = array(
    'name' => 'create project content',
    'roles' => array(
      'administrator' => 'administrator',
      'author' => 'author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any project content'.
  $permissions['delete any project content'] = array(
    'name' => 'delete any project content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own project content'.
  $permissions['delete own project content'] = array(
    'name' => 'delete own project content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any project content'.
  $permissions['edit any project content'] = array(
    'name' => 'edit any project content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own project content'.
  $permissions['edit own project content'] = array(
    'name' => 'edit own project content',
    'roles' => array(
      'administrator' => 'administrator',
      'author' => 'author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'publish revisions of any project content'.
  $permissions['publish revisions of any project content'] = array(
    'name' => 'publish revisions of any project content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of own project content'.
  $permissions['publish revisions of own project content'] = array(
    'name' => 'publish revisions of own project content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of any project content'.
  $permissions['view revisions of any project content'] = array(
    'name' => 'view revisions of any project content',
    'roles' => array(
      'author' => 'author',
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of own project content'.
  $permissions['view revisions of own project content'] = array(
    'name' => 'view revisions of own project content',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'revisioning',
  );

  return $permissions;
}
