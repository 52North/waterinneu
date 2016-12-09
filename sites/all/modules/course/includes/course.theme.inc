<?php

/**
 * Theme the course outline.
 */
function theme_course_outline($variables) {
  $output = '';
  $output .= '<div class="course-outline">';
  $output .= '<span class="trigger"></span>';
  $output .= '<h4 class="course-title">' . filter_xss($variables['node']->title) . '</h4>';
  $output .= theme('item_list', array('title' => '', 'items' => $variables['items']));
  $output .= '</div>';
  return $output;
}

/**
 * Generate a button for taking the course.
 */
function theme_course_take_course_button($variables) {
  $node = $variables['node'];
  $link = '<div class="course-take-course-link-wrapper">' . l(t('Take course'), "node/{$node->nid}/takecourse", array('attributes' => array('class' => array('course-take-course-link')))) . '</div>';
  return $link;
}
