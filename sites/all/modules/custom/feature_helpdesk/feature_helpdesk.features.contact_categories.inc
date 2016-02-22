<?php
/**
 * @file
 * feature_helpdesk.features.contact_categories.inc
 */

/**
 * Implements hook_contact_categories_defaults().
 */
function feature_helpdesk_contact_categories_defaults() {
  return array(
    'Typo' => array(
      'category' => 'Typo',
      'recipients' => 'typo-team@exampl.com',
      'reply' => '',
      'weight' => 0,
      'selected' => 0,
    ),
    'Website feedback' => array(
      'category' => 'Website feedback',
      'recipients' => 'e.h.juerrens@52north.org',
      'reply' => '',
      'weight' => 0,
      'selected' => 0,
    ),
  );
}
