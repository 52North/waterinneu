<?php
/**
 * @file
 * field.node.field_climate_change_revelance.tool.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'translatable' => '0',
    'entity_types' => array(),
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'tags',
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
            'field_data_field_climate_change_revelance' => array(
              'tid' => 'field_climate_change_revelance_tid',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_climate_change_revelance' => array(
              'tid' => 'field_climate_change_revelance_tid',
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
    'field_name' => 'field_climate_change_revelance',
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
    'label' => 'Climate Change Relevance',
    'widget' => array(
      'weight' => '10',
      'type' => 'taxonomy_autocomplete',
      'module' => 'taxonomy',
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
        'type' => 'taxonomy_term_reference_link',
        'weight' => '6',
        'settings' => array(),
        'module' => 'taxonomy',
      ),
      'teaser' => array(
        'label' => 'above',
        'type' => 'hidden',
        'weight' => '9',
        'settings' => array(),
      ),
      'tool_of_the_month' => array(
        'label' => 'inline',
        'type' => 'hidden',
        'weight' => '8',
        'settings' => array(),
      ),
    ),
    'required' => 0,
    'description' => 'Indicate the climate change relevance by category.',
    'default_value' => NULL,
    'field_name' => 'field_climate_change_revelance',
    'entity_type' => 'node',
    'bundle' => 'tool',
    'deleted' => '0',
  ),
);

$dependencies = array(
  'content_type.tool' => 'content_type.tool',
  'vocabulary.tags' => 'vocabulary.tags',
);

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'taxonomy',
);
