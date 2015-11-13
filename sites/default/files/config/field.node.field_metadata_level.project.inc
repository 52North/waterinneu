<?php
/**
 * @file
 * field.node.field_metadata_level.project.inc
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
            'field_data_field_metadata_level' => array(
              'value' => 'field_metadata_level_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_metadata_level' => array(
              'value' => 'field_metadata_level_value',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'field_name' => 'field_metadata_level',
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
    'label' => 'Metadata Level',
    'widget' => array(
      'weight' => '10',
      'type' => 'number',
      'module' => 'number',
      'active' => 0,
      'settings' => array(),
    ),
    'settings' => array(
      'min' => '1',
      'max' => '5',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'type' => 'number_integer',
        'weight' => '32',
        'settings' => array(
          'thousand_separator' => ' ',
          'decimal_separator' => '.',
          'scale' => 0,
          'prefix_suffix' => TRUE,
        ),
        'module' => 'number',
      ),
      'teaser' => array(
        'label' => 'above',
        'type' => 'hidden',
        'weight' => '26',
        'settings' => array(),
      ),
    ),
    'required' => 0,
    'description' => 'Commenting data on the origin, quality, and handling of the data. The quality is assessed on a scale from 1 (very poor) to 5 (very good).',
    'default_value' => NULL,
    'field_name' => 'field_metadata_level',
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
  1 => 'number',
);
