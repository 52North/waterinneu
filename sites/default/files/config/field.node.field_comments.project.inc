<?php
/**
 * @file
 * field.node.field_comments.project.inc
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
            'field_data_field_comments' => array(
              'value' => 'field_comments_value',
              'format' => 'field_comments_format',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_comments' => array(
              'value' => 'field_comments_value',
              'format' => 'field_comments_format',
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
    'field_name' => 'field_comments',
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
    'label' => 'Comments',
    'widget' => array(
      'weight' => '21',
      'type' => 'text_textarea',
      'module' => 'text',
      'active' => 1,
      'settings' => array(
        'rows' => '5',
      ),
    ),
    'settings' => array(
      'text_processing' => '0',
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'type' => 'text_default',
        'weight' => '2',
        'settings' => array(),
        'module' => 'text',
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'smart_trim_format',
        'weight' => '2',
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
    'description' => 'Description of the project.',
    'default_value' => NULL,
    'field_name' => 'field_comments',
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
