<?php
/**
 * @file
 * field.node.field_logo.portal.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'translatable' => '0',
    'entity_types' => array(),
    'settings' => array(
      'uri_scheme' => 'public',
      'default_image' => 0,
    ),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_field_logo' => array(
              'fid' => 'field_logo_fid',
              'alt' => 'field_logo_alt',
              'title' => 'field_logo_title',
              'width' => 'field_logo_width',
              'height' => 'field_logo_height',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_logo' => array(
              'fid' => 'field_logo_fid',
              'alt' => 'field_logo_alt',
              'title' => 'field_logo_title',
              'width' => 'field_logo_width',
              'height' => 'field_logo_height',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(
      'fid' => array(
        'table' => 'file_managed',
        'columns' => array(
          'fid' => 'fid',
        ),
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'field_name' => 'field_logo',
    'type' => 'image',
    'module' => 'image',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'fid' => array(
        'description' => 'The {file_managed}.fid being referenced in this field.',
        'type' => 'int',
        'not null' => FALSE,
        'unsigned' => TRUE,
      ),
      'alt' => array(
        'description' => 'Alternative image text, for the image\'s \'alt\' attribute.',
        'type' => 'varchar',
        'length' => 512,
        'not null' => FALSE,
      ),
      'title' => array(
        'description' => 'Image title text, for the image\'s \'title\' attribute.',
        'type' => 'varchar',
        'length' => 1024,
        'not null' => FALSE,
      ),
      'width' => array(
        'description' => 'The width of the image in pixels.',
        'type' => 'int',
        'unsigned' => TRUE,
      ),
      'height' => array(
        'description' => 'The height of the image in pixels.',
        'type' => 'int',
        'unsigned' => TRUE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Logo',
    'widget' => array(
      'weight' => '1',
      'type' => 'image_image',
      'module' => 'image',
      'active' => 1,
      'settings' => array(
        'progress_indicator' => 'bar',
        'preview_image_style' => 'thumbnail',
      ),
    ),
    'settings' => array(
      'file_directory' => 'logos',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '125x125',
      'min_resolution' => '',
      'alt_field' => 1,
      'title_field' => 1,
      'default_image' => 0,
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'image',
        'weight' => '0',
        'settings' => array(
          'image_style' => 'thumbnail',
          'image_link' => '',
        ),
        'module' => 'image',
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'image',
        'weight' => '0',
        'settings' => array(
          'image_style' => '',
          'image_link' => '',
        ),
        'module' => 'image',
      ),
    ),
    'required' => 0,
    'description' => '',
    'field_name' => 'field_logo',
    'entity_type' => 'node',
    'bundle' => 'portal',
    'deleted' => '0',
  ),
);

$dependencies = array(
  'content_type.portal' => 'content_type.portal',
  'image_style.thumbnail' => 'image_style.thumbnail',
);

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'image',
);
