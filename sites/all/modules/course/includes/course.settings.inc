<?php

/**
 * @file
 * Administrative settings for Course module.
 */

/**
 * Menu callback: Define the Course settings page.
 */
function course_settings_overview() {
  module_load_include('admin.inc', 'system', 'system');
  return system_admin_menu_block_page();
}

/**
 * Appearance settings form callback.
 */
function course_settings_appearance_form() {
  $form = array();

  $form['course_takecourse_tab_display'] = array(
    '#title' => t('Show a "take course" tab on course nodes'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('course_takecourse_tab_display', 1),
  );

  $form['course_take_course_button_show'] = array(
    '#title' => t('Show "take course" button on'),
    '#type' => 'checkboxes',
    '#options' => array(
      'teaser' => t('Teaser'),
      'full' => t('Full'),
    ),
    '#default_value' => variable_get('course_take_course_button_show', array('full' => 'full')),
    '#description' => t('Check to show a "take course" button on courses.'),
  );

  $form['course_disable_regions'] = array(
    '#title' => t('Disable theme regions when taking a course'),
    '#type' => 'checkboxes',
    '#default_value' => variable_get('course_disable_regions', array()),
    '#options' => system_region_list(variable_get('theme_default', '')),
  );

  return system_settings_form($form);
}

/**
 * Element validator to make sure all entries are in key|val format.
 */
function course_check_keyval($element, &$form_state) {
  $val = trim($element['#value']);
  if ($val) {
    if (substr_count($val, "\n") + 1 != substr_count($val, '|')) {
      form_error($element, t('Please ensure all custom object fields are in the format key|value.'));
    }
  }
}

/**
 * Settings form for course enrollments.
 */
function course_enrollment_settings_form($form) {
  $form['header']['#markup'] = '<p>' . t('Here, you can manage the settings related to course enrollments.') . '</p>';
  $form['header']['#markup'] .= '<p>' . t('Currently, there are not any settings.') . '</p>';
  return $form;
}

/**
 * Settings form for course reporting.
 */
function course_report_settings_form($form) {
  $form['header']['#markup'] = '<p>' . t('Here, you can manage the settings related to course progress and completion.') . '</p>';
  $form['header']['#markup'] .= '<p>' . t('Fields may be added to the course progress tracker entity for future functionality.') . '</p>';
  return $form;
}

/**
 * Settings form for course objects.
 */
function course_object_settings_form($form) {
  $form['header']['#markup'] = '<p>' . t('Here, you can manage the settings related to course objects.') . '</p>';
  $form['header']['#markup'] .= '<p>' . t('Fields added to the course object entity are included on the course object editing form, and may be used in course object theme hooks.') . '</p>';

  $form['course_object_private_roles'] = array(
    '#title' => 'Default roles allowed access',
    '#description' => t('By default, when a private course object is created, all view access is revoked. Set roles here that will have access to view private course objects without having access.'),
    '#type' => 'checkboxes',
    '#default_value' => variable_get('course_object_private_roles', array()),
    '#options' => user_roles(),
  );

  return system_settings_form($form);
}
