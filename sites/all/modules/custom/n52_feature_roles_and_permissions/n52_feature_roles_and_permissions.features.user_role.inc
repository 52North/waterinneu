<?php
/**
 * @file
 * n52_feature_roles_and_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function n52_feature_roles_and_permissions_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 6,
  );

  // Exported role: moderator.
  $roles['moderator'] = array(
    'name' => 'moderator',
    'weight' => 4,
  );

  return $roles;
}
