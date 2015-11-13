<?php
/**
 * @file
 * field.node.field_code.organisation.inc
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
            'field_data_field_code' => array(
              'value' => 'field_code_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_code' => array(
              'value' => 'field_code_value',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'field_name' => 'field_code',
    'type' => 'number_integer',
    'module' => 'number',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'value' => array(
        'type' => 'int',
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'code',
    'widget' => array(
      'weight' => '11',
      'type' => 'number',
      'module' => 'number',
      'active' => 0,
      'settings' => array(),
    ),
    'settings' => array(
      'min' => '1',
      'max' => '99999',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'hidden',
        'weight' => '8',
        'settings' => array(),
      ),
      'teaser' => array(
        'label' => 'above',
        'type' => 'hidden',
        'weight' => '4',
        'settings' => array(),
      ),
    ),
    'required' => 0,
    'description' => 'internal code for referencing',
    'default_value' => NULL,
    'field_name' => 'field_code',
    'entity_type' => 'node',
    'bundle' => 'organisation',
    'deleted' => '0',
  ),
);

$dependencies = array(
  'content_type.organisation' => 'content_type.organisation',
);

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'number',
);
