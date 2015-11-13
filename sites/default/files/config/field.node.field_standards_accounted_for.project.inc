<?php
/**
 * @file
 * field.node.field_standards_accounted_for.project.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'translatable' => '0',
    'entity_types' => array(),
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'standards',
          'parent' => '0',
        ),
      ),
      'options_list_callback' => 'i18n_taxonomy_allowed_values',
    ),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_field_standards_accounted_for' => array(
              'tid' => 'field_standards_accounted_for_tid',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_standards_accounted_for' => array(
              'tid' => 'field_standards_accounted_for_tid',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(
      'tid' => array(
        'table' => 'taxonomy_term_data',
        'columns' => array(
          'tid' => 'tid',
        ),
      ),
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'field_name' => 'field_standards_accounted_for',
    'type' => 'taxonomy_term_reference',
    'module' => 'taxonomy',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '-1',
    'deleted' => '0',
    'columns' => array(
      'tid' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Standards accounted for',
    'widget' => array(
      'weight' => '17',
      'type' => 'options_select',
      'module' => 'options',
      'active' => 0,
      'settings' => array(
        'size' => 60,
        'autocomplete_path' => 'taxonomy/autocomplete',
      ),
    ),
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'type' => 'textformatter_list',
        'weight' => '15',
        'settings' => array(
          'textformatter_type' => 'comma',
          'textformatter_comma_and' => 1,
          'textformatter_comma_full_stop' => 1,
          'textformatter_comma_override' => 0,
          'textformatter_separator_custom' => '',
          'textformatter_separator_custom_tag' => 'span',
          'textformatter_separator_custom_class' => 'textformatter-separator',
          'textformatter_comma_tag' => 'div',
          'textformatter_class' => 'textformatter-list',
          'textformatter_term_plain' => 0,
          'textformatter_contrib' => array(),
        ),
        'module' => 'textformatter',
      ),
      'teaser' => array(
        'label' => 'inline',
        'type' => 'textformatter_list',
        'weight' => '4',
        'settings' => array(
          'textformatter_type' => 'comma',
          'textformatter_comma_and' => 1,
          'textformatter_comma_full_stop' => 1,
          'textformatter_comma_override' => 0,
          'textformatter_separator_custom' => '',
          'textformatter_separator_custom_tag' => 'span',
          'textformatter_separator_custom_class' => 'textformatter-separator',
          'textformatter_comma_tag' => '0',
          'textformatter_class' => 'textformatter-list',
          'textformatter_term_plain' => 0,
          'textformatter_contrib' => array(),
        ),
        'module' => 'textformatter',
      ),
    ),
    'required' => 0,
    'description' => 'List all standards that are relevant for the project, e.g. OGC Standards, W3C specifications, IEEE best practices,...',
    'default_value' => NULL,
    'field_name' => 'field_standards_accounted_for',
    'entity_type' => 'node',
    'bundle' => 'project',
    'deleted' => '0',
  ),
);

$dependencies = array(
  'content_type.project' => 'content_type.project',
  'vocabulary.standards' => 'vocabulary.standards',
);

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'taxonomy',
  2 => 'options',
);
