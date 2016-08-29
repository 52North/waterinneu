<?php
/**
 * @file
 * roles_e_learning_waterinneu.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function roles_e_learning_waterinneu_user_default_roles() {
  $roles = array();

  // Exported role: Student.
  $roles['Student'] = array(
    'name' => 'Student',
    'weight' => 7,
  );

  // Exported role: Teacher.
  $roles['Teacher'] = array(
    'name' => 'Teacher',
    'weight' => 8,
  );

  return $roles;
}
