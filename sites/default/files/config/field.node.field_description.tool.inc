<?php
/**
 * @file
 * field.node.field_description.tool.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'translatable' => '0',
    'entity_types' => array(),
    'settings' => array(),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_field_description' => array(
              'value' => 'field_description_value',
              'format' => 'field_description_format',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_description' => array(
              'value' => 'field_description_value',
              'format' => 'field_description_format',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(
      'format' => array(
        'table' => 'filter_format',
        'columns' => array(
          'format' => 'format',
        ),
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'field_name' => 'field_description',
    'type' => 'text_long',
    'module' => 'text',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'value' => array(
        'type' => 'text',
        'size' => 'big',
        'not null' => FALSE,
      ),
      'format' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Description',
    'widget' => array(
      'weight' => '5',
      'type' => 'text_textarea',
      'module' => 'text',
      'active' => 1,
      'settings' => array(
        'rows' => '3',
      ),
    ),
    'settings' => array(
      'text_processing' => '1',
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'text_default',
        'weight' => '4',
        'settings' => array(),
        'module' => 'text',
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'smart_trim_format',
        'weight' => '1',
        'settings' => array(
          'trim_length' => 300,
          'trim_type' => 'chars',
          'trim_suffix' => '...',
          'trim_link' => FALSE,
          'more_link' => FALSE,
          'more_text' => 'Read more',
          'summary_handler' => 'full',
          'trim_options' => array(),
          'trim_preserve_tags' => '',
        ),
        'module' => 'smart_trim',
      ),
      'tool_of_the_month' => array(
        'label' => 'hidden',
        'type' => 'smart_trim_format',
        'weight' => '1',
        'settings' => array(
          'trim_link' => '0',
          'trim_length' => '300',
          'trim_type' => 'words',
          'trim_suffix' => '...',
          'more_link' => '1',
          'more_text' => '  Read more',
          'trim_options' => array(
            'text' => 0,
          ),
          'trim_preserve_tags' => '',
          'summary_handler' => 'full',
        ),
        'module' => 'smart_trim',
      ),
    ),
    'required' => 0,
    'description' => 'Textual description of the tool.',
    'default_value' => NULL,
    'field_name' => 'field_description',
    'entity_type' => 'node',
    'bundle' => 'tool',
    'deleted' => '0',
  ),
);

$dependencies = array(
  'content_type.tool' => 'content_type.tool',
);

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'text',
);
