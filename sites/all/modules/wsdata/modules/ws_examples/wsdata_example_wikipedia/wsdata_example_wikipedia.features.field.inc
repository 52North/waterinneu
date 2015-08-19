<?php
/**
 * @file
 * wsdata_example_wikipedia.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function wsdata_example_wikipedia_field_default_fields() {
  $fields = array();

  // Exported field: 'node-linked_data-field_remote_text'.
  $fields['node-linked_data-field_remote_text'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_remote_text',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'storage' => array(
        'active' => '1',
        'module' => 'wsfields_storage',
        'settings' => array(
          'processor' => 'wsdata_simple_xml_processor',
          'propertymap' => array(
            'read' => array(
              '%title' => 'title',
            ),
          ),
          'remotekey' => 'parse:text',
          'translation' => FALSE,
          'wsconfig_name' => 'wikipedia_read',
        ),
        'type' => 'wsfields_storage',
      ),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'linked_data',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 1,
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'trim_length' => 600,
          ),
          'type' => 'text_trimmed',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_remote_text',
      'label' => 'Remote text',
      'required' => 0,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '-3',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Remote text');

  return $fields;
}
