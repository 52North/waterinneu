<?php

/**
 * Validate whether an argument is a course.
 */
class views_plugin_argument_validate_course extends views_plugin_argument_validate_node {

  function validate_argument($argument) {
    $node = node_load($argument);
    return parent::validate_argument($argument) && course_node_is_course($node);
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['access_op']['#dependency'] = array('edit-options-validate-options-course-access' => array(TRUE));
  }

}
