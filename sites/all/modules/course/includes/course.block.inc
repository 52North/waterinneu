<?php

/**
 * @file course blocks
 */

/**
 * Course block callback: define outline view block.
 */
function _course_block_outline_view() {
  if ($node = course_get_context()) {
    if ($output = course_outline_list($node)) {
      return array('subject' => t('Course outline'), 'content' => $output);
    }
  }
}

/**
 * Course block callback: navigation view.
 */
function _course_block_navigation_view() {
  global $user;
  $node = course_get_context();
  if ($node) {
    $course = course_get_course($node, $user, TRUE);
    $links = $course->getNavigation();

    $items = array();
    foreach($links as $key => $value) {
      $items[] = array(
        'class' => array('course-nav-' . $key),
        'data' => $value,
      );
    }

    // Add javascript poller to update the next step button.
    drupal_add_js(drupal_get_path('module', 'course') . '/js/nav.js', array('cache' => FALSE, 'preprocess' => FALSE));

    return array(
      'subject' => '',
      'content' => theme('item_list', array('items' => $items, 'title' => '', 'type' => 'ul', 'attributes' => array('id' => 'course-nav'))),
    );
  }
}
