<?php
/**
 * @file
 * field.node.field_bounding_box.project.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'translatable' => '0',
    'entity_types' => array(),
    'settings' => array(
      'backend' => 'default',
      'srid' => '4326',
    ),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_field_bounding_box' => array(
              'geom' => 'field_bounding_box_geom',
              'geo_type' => 'field_bounding_box_geo_type',
              'lat' => 'field_bounding_box_lat',
              'lon' => 'field_bounding_box_lon',
              'left' => 'field_bounding_box_left',
              'top' => 'field_bounding_box_top',
              'right' => 'field_bounding_box_right',
              'bottom' => 'field_bounding_box_bottom',
              'geohash' => 'field_bounding_box_geohash',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_bounding_box' => array(
              'geom' => 'field_bounding_box_geom',
              'geo_type' => 'field_bounding_box_geo_type',
              'lat' => 'field_bounding_box_lat',
              'lon' => 'field_bounding_box_lon',
              'left' => 'field_bounding_box_left',
              'top' => 'field_bounding_box_top',
              'right' => 'field_bounding_box_right',
              'bottom' => 'field_bounding_box_bottom',
              'geohash' => 'field_bounding_box_geohash',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'lat' => array(
        0 => 'lat',
      ),
      'lon' => array(
        0 => 'lon',
      ),
      'top' => array(
        0 => 'top',
      ),
      'bottom' => array(
        0 => 'bottom',
      ),
      'left' => array(
        0 => 'left',
      ),
      'right' => array(
        0 => 'right',
      ),
      'geohash' => array(
        0 => 'geohash',
      ),
      'centroid' => array(
        0 => 'lat',
        1 => 'lon',
      ),
      'bbox' => array(
        0 => 'top',
        1 => 'bottom',
        2 => 'left',
        3 => 'right',
      ),
    ),
    'field_name' => 'field_bounding_box',
    'type' => 'geofield',
    'module' => 'geofield',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'geom' => array(
        'type' => 'blob',
        'size' => 'big',
        'not null' => FALSE,
      ),
      'geo_type' => array(
        'type' => 'varchar',
        'default' => '',
        'length' => 64,
      ),
      'lat' => array(
        'type' => 'numeric',
        'precision' => 18,
        'scale' => 12,
        'not null' => FALSE,
      ),
      'lon' => array(
        'type' => 'numeric',
        'precision' => 18,
        'scale' => 12,
        'not null' => FALSE,
      ),
      'left' => array(
        'type' => 'numeric',
        'precision' => 18,
        'scale' => 12,
        'not null' => FALSE,
      ),
      'top' => array(
        'type' => 'numeric',
        'precision' => 18,
        'scale' => 12,
        'not null' => FALSE,
      ),
      'right' => array(
        'type' => 'numeric',
        'precision' => 18,
        'scale' => 12,
        'not null' => FALSE,
      ),
      'bottom' => array(
        'type' => 'numeric',
        'precision' => 18,
        'scale' => 12,
        'not null' => FALSE,
      ),
      'geohash' => array(
        'type' => 'varchar',
        'length' => 16,
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Study Area',
    'widget' => array(
      'weight' => '24',
      'type' => 'geofield_geojson',
      'module' => 'geofield',
      'active' => 1,
      'settings' => array(),
    ),
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'geofield_map_map',
        'weight' => '22',
        'settings' => array(
          'geofield_map_width' => '100%',
          'geofield_map_height' => '300px',
          'geofield_map_center' => array(
            'lat' => '51.935445099999995',
            'lon' => '7.6521963',
            'geocode' => 'Find my location',
          ),
          'geofield_map_zoom' => '8',
          'geofield_map_min_zoom' => '0',
          'geofield_map_max_zoom' => '0',
          'geofield_map_controltype' => 'default',
          'geofield_map_mtc' => 'standard',
          'geofield_map_pancontrol' => 1,
          'geofield_map_maptype' => 'map',
          'geofield_map_baselayers_map' => 1,
          'geofield_map_baselayers_satellite' => 1,
          'geofield_map_baselayers_hybrid' => 1,
          'geofield_map_baselayers_physical' => 0,
          'geofield_map_scale' => 0,
          'geofield_map_overview' => 0,
          'geofield_map_overview_opened' => 0,
          'geofield_map_scrollwheel' => 0,
          'geofield_map_draggable' => 0,
          'geofield_map_streetview_show' => 0,
        ),
        'module' => 'geofield_map',
      ),
      'teaser' => array(
        'label' => 'above',
        'type' => 'hidden',
        'weight' => '8',
        'settings' => array(),
      ),
    ),
    'required' => 0,
    'description' => 'Please specify the spatial extend of this project. (Refine this text)',
    'default_value' => NULL,
    'field_name' => 'field_bounding_box',
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
  1 => 'geofield',
);
