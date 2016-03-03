<?php
/**
 * @file
 * waterinneu_feature_organisation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function waterinneu_feature_organisation_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create organisation content'.
  $permissions['create organisation content'] = array(
    'name' => 'create organisation content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any organisation content'.
  $permissions['delete any organisation content'] = array(
    'name' => 'delete any organisation content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own organisation content'.
  $permissions['delete own organisation content'] = array(
    'name' => 'delete own organisation content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in organisation_classification'.
  $permissions['delete terms in organisation_classification'] = array(
    'name' => 'delete terms in organisation_classification',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any organisation content'.
  $permissions['edit any organisation content'] = array(
    'name' => 'edit any organisation content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own organisation content'.
  $permissions['edit own organisation content'] = array(
    'name' => 'edit own organisation content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in organisation_classification'.
  $permissions['edit terms in organisation_classification'] = array(
    'name' => 'edit terms in organisation_classification',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'merge organisation_classification terms'.
  $permissions['merge organisation_classification terms'] = array(
    'name' => 'merge organisation_classification terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'publish revisions of any organisation content'.
  $permissions['publish revisions of any organisation content'] = array(
    'name' => 'publish revisions of any organisation content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of own organisation content'.
  $permissions['publish revisions of own organisation content'] = array(
    'name' => 'publish revisions of own organisation content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of any organisation content'.
  $permissions['view revisions of any organisation content'] = array(
    'name' => 'view revisions of any organisation content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of own organisation content'.
  $permissions['view revisions of own organisation content'] = array(
    'name' => 'view revisions of own organisation content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'revisioning',
  );

  return $permissions;
}
