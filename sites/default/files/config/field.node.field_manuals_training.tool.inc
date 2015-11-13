<?php
/**
 * @file
 * field.node.field_manuals_training.tool.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'translatable' => '0',
    'entity_types' => array(),
    'settings' => array(
      'attributes' => array(
        'target' => 'default',
        'class' => '',
        'rel' => '',
      ),
      'url' => 0,
      'title' => 'optional',
      'title_value' => '',
      'title_maxlength' => 128,
      'enable_tokens' => 1,
      'display' => array(
        'url_cutoff' => 80,
      ),
    ),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_field_manuals_training' => array(
              'url' => 'field_manuals_training_url',
              'title' => 'field_manuals_training_title',
              'attributes' => 'field_manuals_training_attributes',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_manuals_training' => array(
              'url' => 'field_manuals_training_url',
              'title' => 'field_manuals_training_title',
              'attributes' => 'field_manuals_training_attributes',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'field_name' => 'field_manuals_training',
    'type' => 'link_field',
    'module' => 'link',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '-1',
    'deleted' => '0',
    'columns' => array(
      'url' => array(
        'type' => 'varchar',
        'length' => 2048,
        'not null' => FALSE,
        'sortable' => TRUE,
      ),
      'title' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
        'sortable' => TRUE,
      ),
      'attributes' => array(
        'type' => 'text',
        'size' => 'medium',
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Manuals/Training',
    'widget' => array(
      'weight' => '7',
      'type' => 'link_field',
      'module' => 'link',
      'active' => 0,
      'settings' => array(),
    ),
    'settings' => array(
      'absolute_url' => 1,
      'validate_url' => 1,
      'url' => 0,
      'title' => 'optional',
      'title_value' => '',
      'title_label_use_field_label' => 0,
      'title_maxlength' => '128',
      'enable_tokens' => 1,
      'display' => array(
        'url_cutoff' => '80',
      ),
      'attributes' => array(
        'target' => '_blank',
        'rel' => '',
        'configurable_class' => 0,
        'class' => '',
        'configurable_title' => 0,
        'title' => '',
      ),
      'rel_remove' => 'default',
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'type' => 'textformatter_list',
        'weight' => '5',
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
          'textformatter_contrib' => array(
            'link_field_display_type' => 'link_default',
          ),
          'textformatter_term_plain' => 0,
        ),
        'module' => 'textformatter',
      ),
      'teaser' => array(
        'label' => 'above',
        'type' => 'hidden',
        'weight' => '13',
        'settings' => array(),
      ),
      'tool_of_the_month' => array(
        'label' => 'inline',
        'type' => 'hidden',
        'weight' => '7',
        'settings' => array(),
      ),
    ),
    'required' => 0,
    'description' => 'Links to existing training materials and manuals.',
    'default_value' => NULL,
    'field_name' => 'field_manuals_training',
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
  1 => 'link',
);
