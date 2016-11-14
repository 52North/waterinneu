<?php

/**
 * Implements hook_rules_condition_info().
 */
function course_rules_condition_info() {
  return array(
    'course_enrollment_check' => array(
      'label' => t('User is enrolled'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
        ),
        'user' => array(
          'type' => 'user',
          'label' => t('User'),
        ),
      ),
      'group' => t('Course'),
      'base' => 'course_rules_condition_course_enrollment_check',
    ),
  );
}

/**
 * Rules condition handler to check enrollment.
 */
function course_rules_condition_course_enrollment_check($node, $user) {
  $nid = $node->nid;
  $uid = $user->uid;
  return course_enrollment_check($nid, $uid);
}

/**
 * Implements hook_rules_action_info().
 */
function course_rules_action_info() {
  $defaults = array(
    'parameter' => array(
      'node' => array(
        'type' => 'node',
        'label' => t('Node'),
      ),
      'user' => array(
        'type' => 'user',
        'label' => t('User'),
      ),
    ),
    'group' => t('Course'),
  );

  $actions['course_enroll'] = $defaults + array(
    'label' => t('Enroll a user in a course'),
    'base' => 'course_rules_action_course_enroll',
  );

  $actions['course_unenroll'] = $defaults + array(
    'label' => t('Unenroll a user from a course'),
    'base' => 'course_rules_action_course_unenroll',
  );

  return $actions;
}

/**
 * Rules action handler for enrollment.
 */
function course_rules_action_course_enroll($node, $account) {
  course_enroll($node, $account);
}

/**
 * Rules action handler for unenrollment.
 */
function course_rules_action_course_unenroll($node, $account) {
  course_unenroll($node, $account);
}
