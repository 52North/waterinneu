<?php

/**
 * Implements hook_views_handlers().
 */
function course_signup_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'course') . '/views/handlers',
    ),
    'handlers' => array(
      'course_views_handler_relationship_ce_sl' => array(
        'parent' => 'views_handler_relationship',
      ),
      'course_views_handler_relationship_sl_ce' => array(
        'parent' => 'views_handler_relationship',
      ),
    ),
  );
}

function course_signup_views_data() {
  $data = array();

  $data['signup_log']['course_enrollment'] = array(
    'title' => 'Course enrollment',
    'relationship' => array(
      'base' => 'course_enrollment',
      'handler' => 'course_views_handler_relationship_sl_ce',
      'label' => t('Enrollment'),
      'help' => 'Create a relationship from the signup log to the course enrollment data.',
    ),
  );

  $data['course_enrollment']['signup_log'] = array(
    'title' => 'Signup',
    'relationship' => array(
      'base' => 'signup_log',
      'handler' => 'course_views_handler_relationship_ce_sl',
      'label' => t('Signup'),
      'help' => 'Create a relationship from the course enrollment to the signup.',
    ),
  );

  return $data;
}
