<?php
/**
 * @file
 * n52_feature_helpdesk.features.contact_categories.inc
 */

/**
 * Implements hook_contact_categories_defaults().
 */
function n52_feature_helpdesk_contact_categories_defaults() {
  return array(
    'Commercialising a product' => array(
      'category' => 'Commercialising a product',
      'recipients' => 'waterinneu@creaf.uab.cat',
      'reply' => '',
      'weight' => 4,
      'selected' => 0,
    ),
    'E-learning material' => array(
      'category' => 'E-learning material',
      'recipients' => 'waterinneu@creaf.uab.cat',
      'reply' => '',
      'weight' => 6,
      'selected' => 0,
    ),
    'Event Addition' => array(
      'category' => 'Event Addition',
      'recipients' => 'waterinneu@creaf.uab.cat',
      'reply' => '',
      'weight' => 7,
      'selected' => 0,
    ),
    'Finding a product' => array(
      'category' => 'Finding a product',
      'recipients' => 'waterinneu@creaf.uab.cat',
      'reply' => '',
      'weight' => 2,
      'selected' => 0,
    ),
    'Finding a supplier/consultant' => array(
      'category' => 'Finding a supplier/consultant',
      'recipients' => 'waterinneu@creaf.uab.cat',
      'reply' => '',
      'weight' => 5,
      'selected' => 0,
    ),
    'Implementing a product' => array(
      'category' => 'Implementing a product',
      'recipients' => 'waterinneu@creaf.uab.cat',
      'reply' => '',
      'weight' => 3,
      'selected' => 0,
    ),
    'Other enquiry' => array(
      'category' => 'Other enquiry',
      'recipients' => 'waterinneu@creaf.uab.cat',
      'reply' => '',
      'weight' => 8,
      'selected' => 0,
    ),
    'Uploading a product' => array(
      'category' => 'Uploading a product',
      'recipients' => 'waterinneu@creaf.uab.cat',
      'reply' => '',
      'weight' => 1,
      'selected' => 0,
    ),
  );
}
