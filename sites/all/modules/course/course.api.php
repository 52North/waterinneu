<?php

/**
 * @file
 * Hooks provided by Course module.
 *
 * These entity types provided by Course also have entity API hooks.
 *
 * course_report
 * course_object
 * course_object_fulfillment
 * course_enrollment
 *
 * So for example
 *
 * hook_course_report_presave(&$course_report)
 * hook_course_object_fulfillment_insert($course_object_fulfillment)
 *
 * Enjoy :)
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Allow modules to define handlers that extend Course functionality.
 *
 * @return array
 *   A associative array of handler declarations, keyed by type:
 *   - object: An associative array of course object types, keyed by type:
 *     - name: A string to reference this type on administrative forms.
 *     - description: A string to display more information to administrators.
 *     - class: (optional) A class name which will override the default
 *       CourseObject class.
 *   - outline: An asociative array of outline handlers, keyed by type:
 *     - name: A string to reference this type on administrative forms.
 *     - description: A string to display more information to administrators.
 *     - callback: A function name that will return themed course outline HTML.
 *     - file: (optional) A string to locate the callback file. This should be
 *       specified if not located in the implementing module's .module file.
 *     - file path: (optional) The path to the directory containing the file
 *       specified in 'file'. Defaults to the implementing module path.
 *   - settings: An associative array of configurations, which will be available
 *     as secondary tabs from the Course sitewide settings form:
 *     - name: A string to reference this type on administrative forms.
 *     - description: A string to display more information to administrators.
 *     - callback: A function name that will return a Drupal form API array.
 *     - file: (optional) A string to locate the callback file. This should be
 *       specified if not located in the implementing module's .module file.
 *     - file path: (optional) The path to the directory containing the file
 *       specified in 'file'. Defaults to the implementing module path.
 *     - package: (optional) The key of the settings package this form should be
 *       grouped with.
 */
function hook_course_handlers() {
  // Example: a custom module definition.
  return array(
    'object' => array(
      'custom' => array(
        'name' => t('Custom'),
        'class' => 'CustomCourseObject',
        'description' => t('A custom course object.'),
      ),
    ),
    'outline' => array(
      'custom' => array(
        'name' => t('Custom'),
        'description' => t('Custom outline display.'),
        'callback' => 'custom_outline',
      ),
    ),
    'settings' => array(
      'custom' => array(
        'name' => t('Custom'),
        'description' => t('Course custom configurations.'),
        'callback' => 'custom_course_settings',
      ),
      'followup' => array(
        'name' => t('Follow up'),
        'description' => t('Course custom followup configurations.'),
        'callback' => 'custom_course_followup_settings',
        'file' => 'includes/another_module.followup.inc',
        'file path' => drupal_get_path('module', 'another_module'),
        'package' => 'custom',
      ),
    ),
  );
}

/**
 * Allow modules to alter each other's list of handlers.
 *
 * @param array $handlers
 *   By reference. The return value from each module that implements
 *   hook_course_handlers().
 * @param type $module
 *
 * @see course_get_handlers()
 */
function hook_course_handlers_alter(&$handlers, $module) {
  // Example: alter the class of a course object handler.
  $is_quiz_type = isset($handlers['object']) && isset($handlers['object']['quiz']);
  if ($module == 'course_quiz' && $is_quiz_type) {
    // Change which class should be used.
    $handlers['object']['quiz']['class'] = 'CustomQuizCourseObject';
  }
}

/**
 * Allow modules to add links to the course completion landing page, such as
 * post-course actions.
 *
 * @param array $links
 *   By reference. Currently an array of three elements:
 *   - 0: $path param for l().
 *   - 1: $text param for l().
 *   - 2: A description, suitable for theme_form_element().
 * @param object $course_node
 *   The course node object.
 * @param object $account
 *   The user who just took the course.
 *
 * @see course_completion_page()
 */
function hook_course_outline_completion_links_alter(&$links, $course_node, $account) {
  // Example: add a link.
  $links['gohome'] = array(t('Go home!'), '<front>', t('If you got this far, you
    deserve a link back home'));
}

/**
 * Allow modules to alter remaining incomplete links on the course completion
 * landing page.
 *
 * @param array $links
 *   Same as $links param for hook_course_outline_completion_links().
 * @param object $course_node
 *   The course node object.
 * @param object $account
 *   The user who just took the course.
 *
 * @see course_completion_page()
 */
function hook_course_outline_incomplete_links_alter(&$links, $course_node, $account) {
  // Example: change the default link.
  $links['course'] = array(t("Let's try that again"), "node/$course_node->nid/takecourse", t('Looks like you missed something.'));
}

/**
 * Allow modules to restrict menu access to the take course tab.
 *
 * @param object $node
 *   The course node.
 * @param object $user
 *   The user to check access.
 *
 * @return boolean
 *   Any hook returning FALSE will restrict access to the take course tab.
 */
function hook_course_has_takecourse($node, $user) {
  if ($node->type == 'imported_course') {
    // Users cannot take imported courses.
    return FALSE;
  }
}

/**
 * Allow modules to determine if this course should be restricted.
 *
 * If any module implementing this hook returns FALSE or an array containing
 * 'success' => FALSE, the course will be restricted.
 *
 * @param string $op
 *   Either 'enroll' or 'take'.
 * @param object $node
 *   The course node.
 * @param object $user
 *   The user who may or may not enroll/take the course.
 *
 * @return boolean|array
 *   Either FALSE, or an array containing:
 *   - success: Boolean. Indicates whether or not the user has permission to
 *     enroll or take this course.
 *   - message: String. If success is FALSE, a message to display to the user.
 *
 * @see course_take_course_access()
 * @see course_enroll_access()
 */
function hook_course_access($op, $node, $user) {
  if ($op == 'take') {
    // Example: do not allow users to take courses on Wednesdays.
    if (date('L') == 'wednesday') {
      $hooks[] = array(
        'success' => FALSE,
        'message' => t('Courses are closed on Wednesdays.'),
      );
    }
    // Example: however allow users to bypass enrollment restriction on Christmas.
    elseif ((date('m') == 12) && (date('d') == 25)) {
      $hooks[] = array('success' => TRUE);
    }

    return $hooks;
  }

  if ($op == 'enroll') {
    // Same usage as $op == 'take'.
  }
}

/**
 * Allow modules to be notified about a new course enrollment.
 *
 * @deprecated - use hook_course_enrollment_[insert|update]($enrollment)
 */
function hook_course_enroll($node, $user) {
  drupal_set_message("User enrolled into course.");
}

/**
 * Allow modules to be notified about an unenrollment.
 *
 * @deprecated - use hook_course_enrollment_delete($enrollment)
 */
function hook_course_unenroll($node, $user) {
  drupal_set_message("User unenrolled from course.");
}

/**
 * Implements hook_course_access_alter().
 */
function hook_course_access_alter(&$hooks, $op, $node, $account) {
  if ($op == 'enroll') {
    $hooks['wait_a_minute'] = array(
      'message' => t('You cannot take this course.'),
      'weight' => 5,
      'success' => FALSE,
    );
  }
}
