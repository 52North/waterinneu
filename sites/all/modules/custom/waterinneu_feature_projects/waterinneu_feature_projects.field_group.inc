<?php
/**
 * @file
 * waterinneu_feature_projects.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function waterinneu_feature_projects_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_aggregation_level|node|project|default';
  $field_group->group_name = 'group_aggregation_level';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_geo';
  $field_group->data = array(
    'label' => 'Aggregation Level',
    'weight' => '26',
    'children' => array(
      0 => 'field_hydrolocagical_aggregation',
      1 => 'field_administrative_aggregation',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-aggregation-level field-group-fieldset',
      ),
    ),
  );
  $export['group_aggregation_level|node|project|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_aggretation_level|node|project|form';
  $field_group->group_name = 'group_aggretation_level';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_geo';
  $field_group->data = array(
    'label' => 'Aggregation Level',
    'weight' => '25',
    'children' => array(
      0 => 'field_hydrolocagical_aggregation',
      1 => 'field_administrative_aggregation',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-aggretation-level field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_aggretation_level|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|node|project|default';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background Information',
    'weight' => '6',
    'children' => array(
      0 => 'field_raw_data',
      1 => 'field_metadata_level',
      2 => 'field_report',
      3 => 'field_report_available_',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background field-group-fieldset',
      ),
    ),
  );
  $export['group_background|node|project|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|node|project|form';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background Information',
    'weight' => '6',
    'children' => array(
      0 => 'field_raw_data',
      1 => 'field_metadata_level',
      2 => 'field_report',
      3 => 'field_report_available_',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Background Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-background field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_background|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data_collection|node|project|default';
  $field_group->group_name = 'group_data_collection';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_geo';
  $field_group->data = array(
    'label' => 'Data Collection',
    'weight' => '27',
    'children' => array(
      0 => 'field_hydrological_data_collecti',
      1 => 'field_administrative_data_collec',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-data-collection field-group-fieldset',
      ),
    ),
  );
  $export['group_data_collection|node|project|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data_collection|node|project|form';
  $field_group->group_name = 'group_data_collection';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_geo';
  $field_group->data = array(
    'label' => 'Data Collection',
    'weight' => '26',
    'children' => array(
      0 => 'field_hydrological_data_collecti',
      1 => 'field_administrative_data_collec',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-data-collection field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_data_collection|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_geo|node|project|default';
  $field_group->group_name = 'group_geo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Geographical Description',
    'weight' => '5',
    'children' => array(
      0 => 'field_location',
      1 => 'field_partners_from',
      2 => 'field_partners_countries_of_orig',
      3 => 'field_bounding_box',
      4 => 'group_aggregation_level',
      5 => 'group_data_collection',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-geo field-group-fieldset',
      ),
    ),
  );
  $export['group_geo|node|project|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_geo|node|project|form';
  $field_group->group_name = 'group_geo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Geographical Description',
    'weight' => '3',
    'children' => array(
      0 => 'field_location',
      1 => 'field_partners_from',
      2 => 'field_partners_countries_of_orig',
      3 => 'field_bounding_box',
      4 => 'group_aggretation_level',
      5 => 'group_data_collection',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Geographical Description',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-geo field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_geo|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|project|default';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '8',
    'children' => array(
      0 => 'field_tags',
      1 => 'field_organisations',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-metadata field-group-fieldset',
      ),
    ),
  );
  $export['group_metadata|node|project|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|project|form';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '8',
    'children' => array(
      0 => 'field_approach',
      1 => 'field_comments',
      2 => 'field_tags',
      3 => 'field_organisations',
      4 => 'field_logo',
      5 => 'path',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Metadata',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-metadata field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_metadata|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_results|node|project|default';
  $field_group->group_name = 'group_results';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Results',
    'weight' => '7',
    'children' => array(
      0 => 'field_policy_brief',
      1 => 'field_guideline',
      2 => 'field_administrative_data',
      3 => 'field_model_data',
      4 => 'field_model',
      5 => 'field_observation_data',
      6 => 'field_software',
      7 => 'field_hardware',
      8 => 'field_standards_accounted_for',
      9 => 'field_published_tools',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-results field-group-fieldset',
      ),
    ),
  );
  $export['group_results|node|project|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_results|node|project|form';
  $field_group->group_name = 'group_results';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Results',
    'weight' => '7',
    'children' => array(
      0 => 'field_policy_brief',
      1 => 'field_guideline',
      2 => 'field_administrative_data',
      3 => 'field_model_data',
      4 => 'field_model',
      5 => 'field_observation_data',
      6 => 'field_software',
      7 => 'field_hardware',
      8 => 'field_standards_accounted_for',
      9 => 'field_published_tools',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Results',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-results field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_results|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_temporal|node|project|default';
  $field_group->group_name = 'group_temporal';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Temporal Description',
    'weight' => '4',
    'children' => array(
      0 => 'field_end_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-temporal field-group-fieldset',
      ),
    ),
  );
  $export['group_temporal|node|project|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_temporal|node|project|form';
  $field_group->group_name = 'group_temporal';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Temporal Description',
    'weight' => '5',
    'children' => array(
      0 => 'field_end_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Temporal Description',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-temporal field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_temporal|node|project|form'] = $field_group;

  return $export;
}
