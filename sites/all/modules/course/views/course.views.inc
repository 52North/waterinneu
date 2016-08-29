<?php

module_load_include('inc', 'course', 'views/handlers/views_join_course');

/**
 * Implements hook_views_data_alter().
 */
function course_views_data_alter(&$data) {
  // We still need some views relationships because of how the data is joined
  // (on two fields). Get the user's enrollment from a course report record.
    $data['course_enrollment']['course_report'] = array(
    'title' => 'Course report',
    'relationship' => array(
      'base' => 'course_report',
      'handler' => 'course_views_handler_relationship_ce_cr',
      'label' => t('Course report'),
      'help' => t('Create a relationship from the course enrollment to the course report.'),
    ),
  );

  $data['course_report']['course_enrollment'] = array(
    'title' => 'Course enrollment',
    'relationship' => array(
      'base' => 'course_enrollment',
      'handler' => 'course_views_handler_relationship_cr_ce',
      'label' => t('Enrollment'),
      'help' => t('Create a relationship from the course report to the course enrollment.'),
    ),
  );

  // Filter for the node being a course.
  $data['node']['course'] = array(
    'title' => t('Is a course'),
    'help' => t('Whether or not the content type is marked as a course.'),
    'real field' => 'type',
    'filter' => array(
      'label' => 'Course',
      'handler' => 'views_handler_filter_course',
    ),
  );

  // Filter for the type of course object.
  $data['course_outline']['object_type']['filter'] = array(
    'handler' => 'views_handler_filter_course_object_type',
  );
}

/**
 * Implements hook_views_handlers().
 */
function course_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'course') . '/views/handlers',
    ),
    'handlers' => array(
      'views_handler_filter_course_type' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'views_handler_filter_course' => array(
        'parent' => 'views_handler_filter_boolean_operator',
      ),
      'course_views_handler_relationship_ce_cr' => array(
        'parent' => 'views_handler_relationship',
      ),
      'course_views_handler_relationship_cr_ce' => array(
        'parent' => 'views_handler_relationship',
      ),
    ),
  );
}
