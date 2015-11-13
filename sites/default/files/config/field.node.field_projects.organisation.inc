<?php
/**
 * @file
 * field.node.field_projects.organisation.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'translatable' => '0',
    'entity_types' => array(),
    'settings' => array(
      'target_type' => 'node',
      'handler' => 'base',
      'handler_settings' => array(
        'target_bundles' => array(
          'project' => 'project',
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
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
            'field_data_field_projects' => array(
              'target_id' => 'field_projects_target_id',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_projects' => array(
              'target_id' => 'field_projects_target_id',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(
      'node' => array(
        'table' => 'node',
        'columns' => array(
          'target_id' => 'nid',
        ),
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'field_name' => 'field_projects',
    'type' => 'entityreference',
    'module' => 'entityreference',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '-1',
    'deleted' => '0',
    'columns' => array(
      'target_id' => array(
        'description' => 'The id of the target entity.',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Projects',
    'widget' => array(
      'weight' => '9',
      'type' => 'entityreference_autocomplete_tags',
      'module' => 'entityreference',
      'active' => 1,
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'size' => '60',
        'path' => '',
      ),
    ),
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'type' => 'textformatter_list',
        'weight' => '6',
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
          'textformatter_contrib' => array(
            'entityreference_link' => 1,
          ),
          'textformatter_term_plain' => 0,
        ),
        'module' => 'textformatter',
      ),
      'teaser' => array(
        'label' => 'above',
        'type' => 'hidden',
        'weight' => '7',
        'settings' => array(),
      ),
    ),
    'required' => 0,
    'description' => 'The projects the organisation participated in.',
    'default_value' => NULL,
    'field_name' => 'field_projects',
    'entity_type' => 'node',
    'bundle' => 'organisation',
    'deleted' => '0',
  ),
);

$dependencies = array(
  'content_type.organisation' => 'content_type.organisation',
);

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'entityreference',
);
