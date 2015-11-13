<?php
/**
 * @file
 * field.node.field_software.project.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'translatable' => '0',
    'entity_types' => array(),
    'settings' => array(
      'allowed_values' => array(
        0 => 'not_available',
        1 => 'available',
      ),
      'allowed_values_function' => '',
    ),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_field_software' => array(
              'value' => 'field_software_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_software' => array(
              'value' => 'field_software_value',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'field_name' => 'field_software',
    'type' => 'list_boolean',
    'module' => 'list',
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
    'label' => 'Software available?',
    'widget' => array(
      'weight' => '15',
      'type' => 'options_onoff',
      'module' => 'options',
      'active' => 1,
      'settings' => array(
        'display_label' => 1,
      ),
    ),
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'type' => 'boolean_yes_no',
        'weight' => '13',
        'settings' => array(
          'format' => 'unicode-yes-no',
          'custom_on' => '',
          'custom_off' => '',
          'reverse' => 0,
        ),
        'module' => 'boolean_formatter',
      ),
      'teaser' => array(
        'label' => 'above',
        'type' => 'hidden',
        'weight' => '11',
        'settings' => array(),
      ),
    ),
    'required' => 0,
    'description' => 'Any digital tool, such as computer modeling software, GIS software, digital application for agent-based or participatory modeling, etc.',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'field_name' => 'field_software',
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
  1 => 'list',
  2 => 'options',
);
