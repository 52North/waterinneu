<?php
/**
 * @file
 * field.node.field_approach.project.inc
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
            'field_data_field_approach' => array(
              'value' => 'field_approach_value',
              'format' => 'field_approach_format',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_approach' => array(
              'value' => 'field_approach_value',
              'format' => 'field_approach_format',
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
    'field_name' => 'field_approach',
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
    'label' => 'Approach',
    'widget' => array(
      'weight' => '20',
      'type' => 'text_textarea',
      'module' => 'text',
      'active' => 1,
      'settings' => array(
        'rows' => '2',
      ),
    ),
    'settings' => array(
      'text_processing' => '0',
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'text_default',
        'weight' => '1',
        'settings' => array(),
        'module' => 'text',
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'smart_trim_format',
        'weight' => '1',
        'settings' => array(
          'trim_link' => '0',
          'trim_length' => '200',
          'trim_type' => 'chars',
          'trim_suffix' => '...',
          'more_link' => '0',
          'more_text' => 'Read more',
          'trim_options' => array(
            'text' => 0,
          ),
          'trim_preserve_tags' => '',
          'summary_handler' => 'full',
        ),
        'module' => 'smart_trim',
      ),
    ),
    'required' => 1,
    'description' => 'On sentence describing the approach followed by the research project (i.e., the steps taken by the project in order to reach its goals).',
    'default_value' => NULL,
    'field_name' => 'field_approach',
    'entity_type' => 'node',
    'bundle' => 'project',
    'deleted' => '0',
  ),
);

$dependencies = array(
  'content_type.project' => 'content_type.project',
);

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'text',
);
