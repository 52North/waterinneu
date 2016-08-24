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
    'weight' => 4,
  );

  // Exported role: moderator.
  $roles['moderator'] = array(
    'name' => 'moderator',
    'weight' => 2,
  );

  // Exported role: translation manager.
  $roles['translation manager'] = array(
    'name' => 'translation manager',
    'weight' => 3,
  );

  return $roles;
}
