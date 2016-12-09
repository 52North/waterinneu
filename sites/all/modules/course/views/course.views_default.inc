<?php

/**
 * Implements hook_views_default_views().
 */
function course_views_default_views() {
  $views = array();

  $path = drupal_get_path('module', 'course') . '/views/default';
  $view_files = file_scan_directory($path, '/.*\.view\.inc/');
  foreach ($view_files as $file) {
    include DRUPAL_ROOT . '/' . $path . '/' . $file->filename;
    $views[$view->name] = $view;
  }

  return $views;
}
