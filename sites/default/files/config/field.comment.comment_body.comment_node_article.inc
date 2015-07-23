<?php
/**
 * @file
 * field.comment.comment_body.comment_node_article.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'entity_types' => array(
      0 => 'comment',
    ),
    'translatable' => '0',
    'settings' => array(),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_comment_body' => array(
              'value' => 'comment_body_value',
              'format' => 'comment_body_format',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_comment_body' => array(
              'value' => 'comment_body_value',
              'format' => 'comment_body_format',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(
      'format' => array(
        'table' => 'filter_format',
        'columns' => array(
          'format' => 'format',
        ),
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'field_name' => 'comment_body',
    'type' => 'text_long',
    'module' => 'text',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'value' => array(
        'type' => 'text',
        'size' => 'big',
        'not null' => FALSE,
      ),
      'format' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Comment',
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'required' => TRUE,
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'text_default',
        'weight' => 0,
        'settings' => array(),
        'module' => 'text',
      ),
    ),
    'widget' => array(
      'type' => 'text_textarea',
      'settings' => array(
        'rows' => 5,
      ),
      'weight' => 0,
      'module' => 'text',
    ),
    'description' => '',
    'field_name' => 'comment_body',
    'entity_type' => 'comment',
    'bundle' => 'comment_node_article',
    'deleted' => '0',
    'default_value' => NULL,
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'text',
);
