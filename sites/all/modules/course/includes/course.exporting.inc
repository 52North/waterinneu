<?php

/**
 * Implements hook_clone_node_alter().
 *
 * Display warning messages if there are objects which might not properly clone.
 */
function course_clone_node_alter(&$node, $context) {
  if ($context['method'] == 'prepopulate') {
    if ($course = course_get_course($context['original_node'])) {
      course_clone_warning_messages($course);
    }
  }
}

/**
 * Show warning messages for a Course.
 *
 * @param Course $course
 */
function course_clone_warning_messages($course) {
  $messages = array();
  foreach ($course->getObjects() as $courseObject) {
    $warning = $courseObject->getCloneAbility();
    if ($warning === FALSE) {
      $messages[] = t('The course object %object cannot be cloned. A new instance will be created.', array('%object' => $courseObject->getTitle()));
    }
    if (is_string($warning)) {
      $messages[] = $warning;
    }
  }

  $messages[] = t('Cloned course objects that reference an existing course object in this course will need to be updated to reference the newly cloned course object.');

  if ($messages) {
    drupal_set_message(filter_xss_admin(theme('item_list', array('items' => $messages, 'title' => t('Cloning issues')))), 'warning');
  }
}

/**
 * Implements hook_node_export_node_alter().
 *
 * Allow course objects to freeze data into the export.
 */
function course_node_export_node_alter($node, $original_node, $op) {
  if ($op == 'export') {
    if (course_node_is_course($node)) {
      $course = course_get_course($node);
      if (arg(2) == 'node_export') {
        course_clone_warning_messages($course);
        foreach ($course->getObjects() as $object) {
          if ($object->getCloneAbility() !== FALSE) {
            $node->course['objects'][$object->getId()]->freeze = $object->freeze();
          }
        }
      }
    }
  }
}

/**
 * Freeze course objects onto a node if necessary.
 */
function course_handle_clone($node) {
  if (isset($node->clone_from_original_nid) && $original = node_load($node->clone_from_original_nid)) {
    $node->course['objects'] = course_get_course($original)->getObjects();
    switch ($node->course['clone_type']) {
      case 'reference':
        break;
      case 'new':
        foreach ($node->course['objects'] as $object_data) {
          unset($object_data->instance);
        }
        break;
      case 'clone':
      default:
        foreach ($node->course['objects'] as $object_data) {
          $courseObject = course_get_course_object_by_id($object_data->coid);
          if ($courseObject->getCloneAbility() === FALSE) {
            unset($object_data->instance);
          }
          $object_data->freeze = $courseObject->freeze();
        }
        break;
    }
  }
}
