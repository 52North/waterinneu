<?php
/**
 * @file
 * randbee_feature_e_learning_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function randbee_feature_e_learning_roles_user_default_roles() {
  $roles = array();

  $roles['course participant'] = array(
    'name' => 'course participant',
    'weight' => 7,
  );

  $roles['course administrator'] = array(
    'name' => 'course administrator',
    'weight' => 8,
  );

  return $roles;
}
