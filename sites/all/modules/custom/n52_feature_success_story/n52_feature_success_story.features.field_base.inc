<?php
/**
 * @file
 * n52_feature_success_story.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function n52_feature_success_story_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_n52_story_attachment'.
  $field_bases['field_n52_story_attachment'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_n52_story_attachment',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'uri_scheme' => 'public',
    ),
    'translatable' => 1,
    'type' => 'file',
  );

  return $field_bases;
}
