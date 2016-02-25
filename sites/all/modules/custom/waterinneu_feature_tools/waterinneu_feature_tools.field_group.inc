<?php
/**
 * @file
 * waterinneu_feature_tools.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function waterinneu_feature_tools_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_how|node|tool|default';
  $field_group->group_name = 'group_how';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'How',
    'weight' => '2',
    'children' => array(
      0 => 'field_case_studies',
      1 => 'field_manuals_training',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-how field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_how|node|tool|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_how|node|tool|form';
  $field_group->group_name = 'group_how';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'How',
    'weight' => '9',
    'children' => array(
      0 => 'field_case_studies',
      1 => 'field_manuals_training',
      2 => 'field_product_projects',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-how field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_how|node|tool|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_interop|node|tool|default';
  $field_group->group_name = 'group_interop';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Interoperability',
    'weight' => '3',
    'children' => array(
      0 => 'field_type_of_input_data',
      1 => 'field_supported_legacy_systems',
      2 => 'field_standards_accounted_for',
      3 => 'field_combinability',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-interop field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_interop|node|tool|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_interop|node|tool|form';
  $field_group->group_name = 'group_interop';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Interoperability',
    'weight' => '10',
    'children' => array(
      0 => 'field_type_of_input_data',
      1 => 'field_supported_legacy_systems',
      2 => 'field_standards_accounted_for',
      3 => 'field_combinability',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-interop field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_interop|node|tool|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|tool|default';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '0',
    'children' => array(
      0 => 'field_description',
      1 => 'field_logo',
      2 => 'field_website',
      3 => 'field_license',
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
  $field_groups['group_metadata|node|tool|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|tool|form';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '7',
    'children' => array(
      0 => 'field_license',
      1 => 'field_tool_of_the_month',
      2 => 'field_costs',
      3 => 'language',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-metadata field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_metadata|node|tool|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_what|node|tool|default';
  $field_group->group_name = 'group_what';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'What',
    'weight' => '1',
    'children' => array(
      0 => 'field_purpose',
      1 => 'field_climate_change_revelance',
      2 => 'field_application_scale',
      3 => 'field_category',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-what field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_what|node|tool|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_what|node|tool|form';
  $field_group->group_name = 'group_what';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'What',
    'weight' => '8',
    'children' => array(
      0 => 'field_purpose',
      1 => 'field_application_scale',
      2 => 'field_user_profile',
      3 => 'field_wrd_relevance',
      4 => 'field_innovative_pro',
      5 => 'field_innovative_contra',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-what field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_what|node|tool|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('How');
  t('Interoperability');
  t('Metadata');
  t('What');

  return $field_groups;
}
