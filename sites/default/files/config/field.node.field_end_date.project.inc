<?php
/**
 * @file
 * field.node.field_end_date.project.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'translatable' => '0',
    'entity_types' => array(),
    'settings' => array(
      'granularity' => array(
        'month' => 'month',
        'year' => 'year',
        'day' => 0,
        'hour' => 0,
        'minute' => 0,
        'second' => 0,
      ),
      'tz_handling' => 'none',
      'timezone_db' => '',
      'cache_enabled' => 0,
      'cache_count' => '4',
      'repeat' => '0',
      'todate' => '',
    ),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_field_end_date' => array(
              'value' => 'field_end_date_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_end_date' => array(
              'value' => 'field_end_date_value',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'field_name' => 'field_end_date',
    'type' => 'date',
    'module' => 'date',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'value' => array(
        'type' => 'varchar',
        'length' => 20,
        'not null' => FALSE,
        'sortable' => TRUE,
        'views' => TRUE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'End Date',
    'widget' => array(
      'weight' => '4',
      'type' => 'date_popup',
      'module' => 'date',
      'active' => 1,
      'settings' => array(
        'input_format' => 'd.m.Y - H:i:s',
        'input_format_custom' => '',
        'year_range' => '-10:+10',
        'increment' => '15',
        'label_position' => 'above',
        'text_parts' => array(),
        'display_all_day' => 0,
        'no_fieldset' => 0,
        'repeat_collapsed' => 0,
      ),
    ),
    'settings' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'type' => 'date_default',
        'weight' => '2',
        'settings' => array(
          'format_type' => 'long',
          'multiple_number' => '',
          'multiple_from' => '',
          'multiple_to' => '',
          'fromto' => 'both',
          'show_remaining_days' => FALSE,
          'show_repeat_rule' => 'show',
        ),
        'module' => 'date',
      ),
      'teaser' => array(
        'label' => 'above',
        'type' => 'hidden',
        'weight' => '20',
        'settings' => array(),
      ),
    ),
    'required' => 0,
    'description' => 'The date when the project finished.',
    'field_name' => 'field_end_date',
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
  1 => 'date',
);
