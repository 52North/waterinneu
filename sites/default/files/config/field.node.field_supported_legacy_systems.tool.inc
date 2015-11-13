<?php
/**
 * @file
 * field.node.field_supported_legacy_systems.tool.inc
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
            'field_data_field_supported_legacy_systems' => array(
              'value' => 'field_supported_legacy_systems_value',
              'format' => 'field_supported_legacy_systems_format',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_supported_legacy_systems' => array(
              'value' => 'field_supported_legacy_systems_value',
              'format' => 'field_supported_legacy_systems_format',
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
    'field_name' => 'field_supported_legacy_systems',
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
    'label' => 'Supported Legacy Systems',
    'widget' => array(
      'weight' => '16',
      'type' => 'text_textarea',
      'module' => 'text',
      'active' => 1,
      'settings' => array(
        'rows' => '5',
      ),
    ),
    'settings' => array(
      'text_processing' => '1',
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'type' => 'text_default',
        'weight' => '6',
        'settings' => array(),
        'module' => 'text',
      ),
      'teaser' => array(
        'label' => 'above',
        'type' => 'hidden',
        'weight' => '7',
        'settings' => array(),
      ),
      'tool_of_the_month' => array(
        'label' => 'inline',
        'type' => 'hidden',
        'weight' => '9',
        'settings' => array(),
      ),
    ),
    'required' => 0,
    'description' => 'Document support of legacy systems.',
    'default_value' => NULL,
    'field_name' => 'field_supported_legacy_systems',
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
