<?php
/**
 * @file
 * field.node.field_observation_data.project.inc
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
            'field_data_field_observation_data' => array(
              'value' => 'field_observation_data_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_observation_data' => array(
              'value' => 'field_observation_data_value',
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
    'field_name' => 'field_observation_data',
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
    'label' => 'Observation Data available?',
    'widget' => array(
      'weight' => '14',
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
        'weight' => '12',
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
        'weight' => '12',
        'settings' => array(),
      ),
    ),
    'required' => 0,
    'description' => 'Numerical data originating directly from measurements or indirectly using a simple procedure (e.g., discharge data resulting from a stage-discharge curve).',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'field_name' => 'field_observation_data',
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
