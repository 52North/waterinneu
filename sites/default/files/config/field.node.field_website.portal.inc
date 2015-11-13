<?php
/**
 * @file
 * field.node.field_website.portal.inc
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
            'field_data_field_website' => array(
              'url' => 'field_website_url',
              'title' => 'field_website_title',
              'attributes' => 'field_website_attributes',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_website' => array(
              'url' => 'field_website_url',
              'title' => 'field_website_title',
              'attributes' => 'field_website_attributes',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'field_name' => 'field_website',
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
    'label' => 'Website',
    'widget' => array(
      'weight' => '2',
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
      'enable_tokens' => 1,
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'link_default',
        'weight' => '1',
        'settings' => array(),
        'module' => 'link',
      ),
      'teaser' => array(
        'label' => 'above',
        'type' => 'link_plain',
        'weight' => '1',
        'settings' => array(),
        'module' => 'link',
      ),
    ),
    'required' => 1,
    'description' => '',
    'default_value' => array(
      0 => array(
        'title' => 'example.com',
        'url' => 'http://www.example.com/',
        'attributes' => array(
          'target' => 0,
        ),
      ),
    ),
    'field_name' => 'field_website',
    'entity_type' => 'node',
    'bundle' => 'portal',
    'deleted' => '0',
  ),
);

$dependencies = array(
  'content_type.portal' => 'content_type.portal',
);

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'link',
);
