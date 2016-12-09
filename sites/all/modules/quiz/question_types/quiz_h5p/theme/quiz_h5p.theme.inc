<?php

/**
 * Theme function for user response report
 *
 * @param array $variables User response data
 *
 * @return bool|string User response report
 */
function theme_quiz_h5p_response($variables) {
  $H5PReport = H5PReport::getInstance();
  $reportHtml = $H5PReport->generateReport($variables['question']);

  // Add styles used during processing
  $module_path = drupal_get_path('module', 'quiz_h5p');
  foreach ($H5PReport->getStylesUsed() as $style) {
    drupal_add_css("{$module_path}/report/{$style}");
  }

  return $reportHtml;
}
