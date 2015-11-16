<?php
/**
 * @file
 * waterinneu_feature_roles_and_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function waterinneu_feature_roles_and_permissions_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 6,
  );

  // Exported role: author.
  $roles['author'] = array(
    'name' => 'author',
    'weight' => 2,
  );

  // Exported role: marketplace_author.
  $roles['marketplace_author'] = array(
    'name' => 'marketplace_author',
    'weight' => 3,
  );

  // Exported role: marketplace_moderator.
  $roles['marketplace_moderator'] = array(
    'name' => 'marketplace_moderator',
    'weight' => 5,
  );

  // Exported role: moderator.
  $roles['moderator'] = array(
    'name' => 'moderator',
    'weight' => 4,
  );

  return $roles;
}
