<?php
/**
 * @file
 * randbee_feature_e_learning_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function randbee_feature_e_learning_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access all course reports'.
  $permissions['access all course reports'] = array(
    'name' => 'access all course reports',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'course',
  );

  // Exported permission: 'access course'.
  $permissions['access course'] = array(
    'name' => 'access course',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'course administrator' => 'course administrator',
      'course participant' => 'course participant',
      'moderator' => 'moderator',
      'translation manager' => 'translation manager',
    ),
    'module' => 'course',
  );

  // Exported permission: 'access course administration area'.
  $permissions['access course administration area'] = array(
    'name' => 'access course administration area',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'course',
  );

  // Exported permission: 'access print'.
  $permissions['access print'] = array(
    'name' => 'access print',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'course administrator' => 'course administrator',
      'course participant' => 'course participant',
      'moderator' => 'moderator',
      'translation manager' => 'translation manager',
    ),
    'module' => 'print',
  );

  // Exported permission: 'access quiz'.
  $permissions['access quiz'] = array(
    'name' => 'access quiz',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'course administrator' => 'course administrator',
      'course participant' => 'course participant',
      'moderator' => 'moderator',
      'translation manager' => 'translation manager',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'add terms in course_type'.
  $permissions['add terms in course_type'] = array(
    'name' => 'add terms in course_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add_terms_course_type'.
  $permissions['add_terms_course_type'] = array(
    'name' => 'add_terms_course_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'administer all signups'.
  $permissions['administer all signups'] = array(
    'name' => 'administer all signups',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'signup',
  );

  // Exported permission: 'administer course'.
  $permissions['administer course'] = array(
    'name' => 'administer course',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'course',
  );

  // Exported permission: 'administer course enrollment types'.
  $permissions['administer course enrollment types'] = array(
    'name' => 'administer course enrollment types',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'course',
  );

  // Exported permission: 'administer fitvids'.
  $permissions['administer fitvids'] = array(
    'name' => 'administer fitvids',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fitvids',
  );

  // Exported permission: 'administer print'.
  $permissions['administer print'] = array(
    'name' => 'administer print',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'print',
  );

  // Exported permission: 'administer quiz configuration'.
  $permissions['administer quiz configuration'] = array(
    'name' => 'administer quiz configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'administer signups for own content'.
  $permissions['administer signups for own content'] = array(
    'name' => 'administer signups for own content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'signup',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'uuid',
  );

  // Exported permission: 'administer video styles'.
  $permissions['administer video styles'] = array(
    'name' => 'administer video styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'video_embed_field',
  );

  // Exported permission: 'assign any action to quiz events'.
  $permissions['assign any action to quiz events'] = array(
    'name' => 'assign any action to quiz events',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'cancel own signups'.
  $permissions['cancel own signups'] = array(
    'name' => 'cancel own signups',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'signup',
  );

  // Exported permission: 'cancel signups'.
  $permissions['cancel signups'] = array(
    'name' => 'cancel signups',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'signup',
  );

  // Exported permission: 'create course content'.
  $permissions['create course content'] = array(
    'name' => 'create course content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create long_answer content'.
  $permissions['create long_answer content'] = array(
    'name' => 'create long_answer content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create matching content'.
  $permissions['create matching content'] = array(
    'name' => 'create matching content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create multichoice content'.
  $permissions['create multichoice content'] = array(
    'name' => 'create multichoice content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create quiz content'.
  $permissions['create quiz content'] = array(
    'name' => 'create quiz content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create quiz_ddlines content'.
  $permissions['create quiz_ddlines content'] = array(
    'name' => 'create quiz_ddlines content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create short_answer content'.
  $permissions['create short_answer content'] = array(
    'name' => 'create short_answer content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create truefalse content'.
  $permissions['create truefalse content'] = array(
    'name' => 'create truefalse content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any course content'.
  $permissions['delete any course content'] = array(
    'name' => 'delete any course content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any long_answer content'.
  $permissions['delete any long_answer content'] = array(
    'name' => 'delete any long_answer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any matching content'.
  $permissions['delete any matching content'] = array(
    'name' => 'delete any matching content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any multichoice content'.
  $permissions['delete any multichoice content'] = array(
    'name' => 'delete any multichoice content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any quiz content'.
  $permissions['delete any quiz content'] = array(
    'name' => 'delete any quiz content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any quiz results'.
  $permissions['delete any quiz results'] = array(
    'name' => 'delete any quiz results',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'delete any quiz_ddlines content'.
  $permissions['delete any quiz_ddlines content'] = array(
    'name' => 'delete any quiz_ddlines content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any short_answer content'.
  $permissions['delete any short_answer content'] = array(
    'name' => 'delete any short_answer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any truefalse content'.
  $permissions['delete any truefalse content'] = array(
    'name' => 'delete any truefalse content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own course content'.
  $permissions['delete own course content'] = array(
    'name' => 'delete own course content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own long_answer content'.
  $permissions['delete own long_answer content'] = array(
    'name' => 'delete own long_answer content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own matching content'.
  $permissions['delete own matching content'] = array(
    'name' => 'delete own matching content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own multichoice content'.
  $permissions['delete own multichoice content'] = array(
    'name' => 'delete own multichoice content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own quiz content'.
  $permissions['delete own quiz content'] = array(
    'name' => 'delete own quiz content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own quiz_ddlines content'.
  $permissions['delete own quiz_ddlines content'] = array(
    'name' => 'delete own quiz_ddlines content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own short_answer content'.
  $permissions['delete own short_answer content'] = array(
    'name' => 'delete own short_answer content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own truefalse content'.
  $permissions['delete own truefalse content'] = array(
    'name' => 'delete own truefalse content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete results for own quiz'.
  $permissions['delete results for own quiz'] = array(
    'name' => 'delete results for own quiz',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'delete terms in course_type'.
  $permissions['delete terms in course_type'] = array(
    'name' => 'delete terms in course_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any course content'.
  $permissions['edit any course content'] = array(
    'name' => 'edit any course content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any long_answer content'.
  $permissions['edit any long_answer content'] = array(
    'name' => 'edit any long_answer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any matching content'.
  $permissions['edit any matching content'] = array(
    'name' => 'edit any matching content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any multichoice content'.
  $permissions['edit any multichoice content'] = array(
    'name' => 'edit any multichoice content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any quiz content'.
  $permissions['edit any quiz content'] = array(
    'name' => 'edit any quiz content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any quiz_ddlines content'.
  $permissions['edit any quiz_ddlines content'] = array(
    'name' => 'edit any quiz_ddlines content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any short_answer content'.
  $permissions['edit any short_answer content'] = array(
    'name' => 'edit any short_answer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any truefalse content'.
  $permissions['edit any truefalse content'] = array(
    'name' => 'edit any truefalse content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own course content'.
  $permissions['edit own course content'] = array(
    'name' => 'edit own course content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own long_answer content'.
  $permissions['edit own long_answer content'] = array(
    'name' => 'edit own long_answer content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own matching content'.
  $permissions['edit own matching content'] = array(
    'name' => 'edit own matching content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own multichoice content'.
  $permissions['edit own multichoice content'] = array(
    'name' => 'edit own multichoice content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own quiz content'.
  $permissions['edit own quiz content'] = array(
    'name' => 'edit own quiz content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own quiz_ddlines content'.
  $permissions['edit own quiz_ddlines content'] = array(
    'name' => 'edit own quiz_ddlines content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own short_answer content'.
  $permissions['edit own short_answer content'] = array(
    'name' => 'edit own short_answer content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own signups'.
  $permissions['edit own signups'] = array(
    'name' => 'edit own signups',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'signup',
  );

  // Exported permission: 'edit own truefalse content'.
  $permissions['edit own truefalse content'] = array(
    'name' => 'edit own truefalse content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit question titles'.
  $permissions['edit question titles'] = array(
    'name' => 'edit question titles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'edit terms in course_type'.
  $permissions['edit terms in course_type'] = array(
    'name' => 'edit terms in course_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'email all signed up users'.
  $permissions['email all signed up users'] = array(
    'name' => 'email all signed up users',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'signup',
  );

  // Exported permission: 'email users signed up for own content'.
  $permissions['email users signed up for own content'] = array(
    'name' => 'email users signed up for own content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'course participant' => 'course participant',
    ),
    'module' => 'signup',
  );

  // Exported permission: 'manual quiz revisioning'.
  $permissions['manual quiz revisioning'] = array(
    'name' => 'manual quiz revisioning',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'merge course_type terms'.
  $permissions['merge course_type terms'] = array(
    'name' => 'merge course_type terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'score any quiz'.
  $permissions['score any quiz'] = array(
    'name' => 'score any quiz',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'score own quiz'.
  $permissions['score own quiz'] = array(
    'name' => 'score own quiz',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'course administrator' => 'course administrator',
      'course participant' => 'course participant',
      'moderator' => 'moderator',
      'translation manager' => 'translation manager',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'score taken quiz answer'.
  $permissions['score taken quiz answer'] = array(
    'name' => 'score taken quiz answer',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'show format selection for course_enrollment'.
  $permissions['show format selection for course_enrollment'] = array(
    'name' => 'show format selection for course_enrollment',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for course_object'.
  $permissions['show format selection for course_object'] = array(
    'name' => 'show format selection for course_object',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for course_report'.
  $permissions['show format selection for course_report'] = array(
    'name' => 'show format selection for course_report',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'sign up for content'.
  $permissions['sign up for content'] = array(
    'name' => 'sign up for content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'course administrator' => 'course administrator',
      'course participant' => 'course participant',
      'moderator' => 'moderator',
      'translation manager' => 'translation manager',
    ),
    'module' => 'signup',
  );

  // Exported permission: 'use regex for short answer'.
  $permissions['use regex for short answer'] = array(
    'name' => 'use regex for short answer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'short_answer',
  );

  // Exported permission: 'view all signups'.
  $permissions['view all signups'] = array(
    'name' => 'view all signups',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'course administrator' => 'course administrator',
      'course participant' => 'course participant',
      'moderator' => 'moderator',
      'translation manager' => 'translation manager',
    ),
    'module' => 'signup',
  );

  // Exported permission: 'view any quiz question correct response'.
  $permissions['view any quiz question correct response'] = array(
    'name' => 'view any quiz question correct response',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'view any quiz results'.
  $permissions['view any quiz results'] = array(
    'name' => 'view any quiz results',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'view own quiz results'.
  $permissions['view own quiz results'] = array(
    'name' => 'view own quiz results',
    'roles' => array(
      'administrator' => 'administrator',
      'course participant' => 'course participant',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'view quiz question outside of a quiz'.
  $permissions['view quiz question outside of a quiz'] = array(
    'name' => 'view quiz question outside of a quiz',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'view results for own quiz'.
  $permissions['view results for own quiz'] = array(
    'name' => 'view results for own quiz',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
    ),
    'module' => 'quiz',
  );

  return $permissions;
}
