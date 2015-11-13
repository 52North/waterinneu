<?php
/**
 * @file
 * field.node.field_country_term.organisation.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'translatable' => '0',
    'entity_types' => array(),
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'countries',
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
            'field_data_field_country_term' => array(
              'tid' => 'field_country_term_tid',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_country_term' => array(
              'tid' => 'field_country_term_tid',
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
    'field_name' => 'field_country_term',
    'type' => 'taxonomy_term_reference',
    'module' => 'taxonomy',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '1',
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
    'label' => 'Country',
    'widget' => array(
      'weight' => '3',
      'type' => 'options_select',
      'module' => 'options',
      'active' => 1,
      'settings' => array(),
    ),
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'type' => 'textformatter_list',
        'weight' => '0',
        'settings' => array(
          'textformatter_type' => 'comma',
          'textformatter_comma_and' => 1,
          'textformatter_comma_full_stop' => 1,
          'textformatter_comma_override' => 0,
          'textformatter_separator_custom' => '',
          'textformatter_separator_custom_tag' => 'span',
          'textformatter_separator_custom_class' => 'textformatter-separator',
          'textformatter_comma_tag' => 'span',
          'textformatter_class' => 'textformatter-list',
          'textformatter_term_plain' => 0,
          'textformatter_contrib' => array(),
        ),
        'module' => 'textformatter',
      ),
      'teaser' => array(
        'label' => 'inline',
        'type' => 'textformatter_list',
        'weight' => '0',
        'settings' => array(
          'textformatter_type' => 'comma',
          'textformatter_comma_and' => 0,
          'textformatter_comma_full_stop' => 0,
          'textformatter_comma_override' => 0,
          'textformatter_separator_custom' => '',
          'textformatter_separator_custom_tag' => 'span',
          'textformatter_separator_custom_class' => 'textformatter-separator',
          'textformatter_comma_tag' => 'span',
          'textformatter_class' => 'textformatter-list',
          'textformatter_term_plain' => 0,
          'textformatter_contrib' => array(),
        ),
        'module' => 'textformatter',
      ),
    ),
    'required' => 0,
    'description' => '',
    'default_value' => array(
      0 => array(
        'tid' => '92',
      ),
    ),
    'field_name' => 'field_country_term',
    'entity_type' => 'node',
    'bundle' => 'organisation',
    'deleted' => '0',
  ),
);

$dependencies = array(
  'content_type.organisation' => 'content_type.organisation',
  'vocabulary.countries' => 'vocabulary.countries',
);

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'taxonomy',
  2 => 'options',
);
