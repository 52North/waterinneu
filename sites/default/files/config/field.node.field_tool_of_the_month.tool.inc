<?php
/**
 * @file
 * field.node.field_tool_of_the_month.tool.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'translatable' => '0',
    'entity_types' => array(),
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
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
            'field_data_field_tool_of_the_month' => array(
              'value' => 'field_tool_of_the_month_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_tool_of_the_month' => array(
              'value' => 'field_tool_of_the_month_value',
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
    'field_name' => 'field_tool_of_the_month',
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
    'label' => 'Tool of the Month',
    'widget' => array(
      'weight' => '7',
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
        'label' => 'above',
        'type' => 'hidden',
        'weight' => '5',
        'settings' => array(),
      ),
      'tool_of_the_month' => array(
        'label' => 'above',
        'type' => 'hidden',
        'weight' => '14',
        'settings' => array(),
      ),
      'teaser' => array(
        'type' => 'hidden',
        'label' => 'above',
        'settings' => array(),
        'weight' => 0,
      ),
    ),
    'required' => 0,
    'description' => 'The setting controls the content of the tool of the month box on the front page, hence, only one tools should have set this to true.',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'field_name' => 'field_tool_of_the_month',
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
  1 => 'list',
  2 => 'options',
);
