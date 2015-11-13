<?php
/**
 * @file
 * field.node.field_hardware.project.inc
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
            'field_data_field_hardware' => array(
              'value' => 'field_hardware_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_hardware' => array(
              'value' => 'field_hardware_value',
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
    'field_name' => 'field_hardware',
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
    'label' => 'Hardware available?',
    'widget' => array(
      'weight' => '16',
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
        'weight' => '14',
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
        'weight' => '15',
        'settings' => array(),
      ),
    ),
    'required' => 0,
    'description' => 'Any physical component or instructions on how to build a piece of hardware.',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'field_name' => 'field_hardware',
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
