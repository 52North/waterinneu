<?php
/**
 * @file
 * field.node.field_report.project.inc
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
            'field_data_field_report' => array(
              'url' => 'field_report_url',
              'title' => 'field_report_title',
              'attributes' => 'field_report_attributes',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_report' => array(
              'url' => 'field_report_url',
              'title' => 'field_report_title',
              'attributes' => 'field_report_attributes',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'field_name' => 'field_report',
    'type' => 'link_field',
    'module' => 'link',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '1',
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
    'label' => 'Report',
    'widget' => array(
      'weight' => '8',
      'type' => 'link_field',
      'module' => 'link',
      'active' => 0,
      'settings' => array(),
    ),
    'settings' => array(
      'absolute_url' => 1,
      'validate_url' => 1,
      'url' => 0,
      'title' => 'required',
      'title_value' => '',
      'title_label_use_field_label' => 0,
      'title_maxlength' => '128',
      'enable_tokens' => 1,
      'display' => array(
        'url_cutoff' => '80',
      ),
      'attributes' => array(
        'target' => 'default',
        'rel' => '',
        'configurable_class' => 0,
        'class' => '',
        'configurable_title' => 0,
        'title' => '',
      ),
      'rel_remove' => 'default',
      'linkit' => array(
        'enable' => 0,
        'profile' => '',
        'button_text' => 'Search',
      ),
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'type' => 'link_default',
        'weight' => '30',
        'settings' => array(),
        'module' => 'link',
      ),
      'teaser' => array(
        'label' => 'above',
        'type' => 'hidden',
        'weight' => '17',
        'settings' => array(),
      ),
    ),
    'required' => 0,
    'description' => 'A concluding report on the project is available. Link it here.',
    'default_value' => NULL,
    'field_name' => 'field_report',
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
  1 => 'link',
);
