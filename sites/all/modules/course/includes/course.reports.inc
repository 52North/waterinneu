<?php

/**
 * @file course.reports.inc
 * Reporting framework for course objects.
 */

/**
 * Page handler for course object reports.
 */
function course_object_reports_page($node) {
  $coid = arg(4);
  $report_key = arg(5);
  $report_subkey = arg(6);
  // Report navigation.
  $nav = '';
  // Report header.
  $header = '';
  // Report content.
  $content = '';
  // Render Array
  $render = array();

  $course = course_get_course($node);
  foreach ($course->getObjects() as $courseObject) {
    $items = array();
    if (method_exists($courseObject, 'getReports')) {
      foreach ($courseObject->getReports() as $key => $report) {
        $items[$key] = course_object_single_report_link($courseObject, $key, $report);
      };
      $nav[$courseObject->getId()] = array(
        '#theme' => 'item_list',
        '#title' => $courseObject->getTitle(),
        '#items' => $items,
      );
    }
  }

  if ($coid) {
    $courseObject = course_get_course_object_by_id($coid);
    $report = $courseObject->getReport($report_key, $report_subkey);
    if ($report) {
      if (isset($report['url'])) {
        $content = course_iframe($report['url']);
      }
      if (isset($report['content'])) {
        $content = $report['content'];
      }
      $header = '<h3>' . $courseObject->getTitle() . ': ' . $report['title'] . '</h3>';
    }
    else {
      $content = t('Sorry, no report is available for this type.');
    }
  }

  if (is_array($content)) {
    $content = drupal_render($content);
  }
  $rows['nav'] = array(
    'data' => $nav,
    'width' => 200,
    'id' => 'course-object-reports-nav',
    'valign' => 'top',
  );
  $rows['report'] = array(
    'data' => $header . $content,
    'id' => 'course-object-reports-content',
    'valign' => 'top',
  );

  $render['#rows'] = array('data' => $rows);
  $render['#theme'] = 'table';
  $render['#attributes'] = array('id' => 'course-object-reports');

  return $render;
}

/**
 * Return a link to a report as HTML.
 */
function course_object_single_report_link($courseObject, $key, $report) {
  return l($report['title'], "node/{$courseObject->getCourseNid()}/course-reports/objects/{$courseObject->getId()}/$key");
}
