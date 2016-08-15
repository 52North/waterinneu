<?php
/**
 * @file
 * n52_feature_products.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function n52_feature_products_field_group_info() {
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
  $field_group->identifier = 'group_n52_product_details_g1|node|tool|default';
  $field_group->group_name = 'group_n52_product_details_g1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_n52_product_details';
  $field_group->data = array(
    'label' => 'Details Group #1',
    'weight' => '40',
    'children' => array(
      0 => 'field_license',
      1 => 'field_type_of_software',
      2 => 'field_type_of_hardware',
      3 => 'field_licenseinfo',
      4 => 'field_costs',
      5 => 'field_costinfo',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details Group #1',
      'instance_settings' => array(
        'id' => 'group-n52-product-details-g1',
        'classes' => 'group-n52-product-details-g1 field-group-div container-fluid',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_n52_product_details_g1|node|tool|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_n52_product_details_g1|node|tool|print';
  $field_group->group_name = 'group_n52_product_details_g1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'print';
  $field_group->parent_name = 'group_n52_product_details';
  $field_group->data = array(
    'label' => 'Details Group #1',
    'weight' => '40',
    'children' => array(
      0 => 'field_license',
      1 => 'field_type_of_software',
      2 => 'field_type_of_hardware',
      3 => 'field_licenseinfo',
      4 => 'field_costs',
      5 => 'field_costinfo',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details Group #1',
      'instance_settings' => array(
        'id' => 'group-n52-product-details-g1',
        'classes' => 'group-n52-product-details-g1 field-group-div container-fluid',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_n52_product_details_g1|node|tool|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_n52_product_details_g2|node|tool|default';
  $field_group->group_name = 'group_n52_product_details_g2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_n52_product_details';
  $field_group->data = array(
    'label' => 'Details Group #2',
    'weight' => '41',
    'children' => array(
      0 => 'field_n52_e_learn_and_support',
      1 => 'field_n52_case_studies',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details Group #2',
      'instance_settings' => array(
        'id' => 'group-n52-product-details-g2',
        'classes' => 'group-n52-product-details-g2 field-group-div container-fluid',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_n52_product_details_g2|node|tool|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_n52_product_details_g2|node|tool|print';
  $field_group->group_name = 'group_n52_product_details_g2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'print';
  $field_group->parent_name = 'group_n52_product_details';
  $field_group->data = array(
    'label' => 'Details Group #2',
    'weight' => '41',
    'children' => array(
      0 => 'field_n52_e_learn_and_support',
      1 => 'field_n52_case_studies',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details Group #2',
      'instance_settings' => array(
        'id' => 'group-n52-product-details-g2',
        'classes' => 'group-n52-product-details-g2 field-group-div container-fluid',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_n52_product_details_g2|node|tool|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_n52_product_details_g3|node|tool|default';
  $field_group->group_name = 'group_n52_product_details_g3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_n52_product_details';
  $field_group->data = array(
    'label' => 'Details Group #3',
    'weight' => '42',
    'children' => array(
      0 => 'field_supported_legacy_systems',
      1 => 'field_combinability',
      2 => 'field_purpose',
      3 => 'field_issue',
      4 => 'field_relevant_water_bodies',
      5 => 'field_target_user_group',
      6 => 'field_type_of_input_requirements',
      7 => 'field_type_of_output',
      8 => 'field_purpose_info',
      9 => 'field_issue_info',
      10 => 'field_relevant_water_bodies_info',
      11 => 'field_target_user_group_info',
      12 => 'group_supported_standards',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details Group #3',
      'instance_settings' => array(
        'id' => 'group-n52-product-details-g3',
        'classes' => 'group-n52-product-details-g3 field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_n52_product_details_g3|node|tool|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_n52_product_details_g3|node|tool|print';
  $field_group->group_name = 'group_n52_product_details_g3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'print';
  $field_group->parent_name = 'group_n52_product_details';
  $field_group->data = array(
    'label' => 'Details Group #3',
    'weight' => '42',
    'children' => array(
      0 => 'field_supported_legacy_systems',
      1 => 'field_combinability',
      2 => 'field_purpose',
      3 => 'field_issue',
      4 => 'field_relevant_water_bodies',
      5 => 'field_target_user_group',
      6 => 'field_type_of_input_requirements',
      7 => 'field_type_of_output',
      8 => 'field_purpose_info',
      9 => 'field_issue_info',
      10 => 'field_relevant_water_bodies_info',
      11 => 'field_target_user_group_info',
      12 => 'group_supported_standards',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details Group #3',
      'instance_settings' => array(
        'id' => 'group-n52-product-details-g3',
        'classes' => 'group-n52-product-details-g3 field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_n52_product_details_g3|node|tool|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_n52_product_details_g4|node|tool|default';
  $field_group->group_name = 'group_n52_product_details_g4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_n52_product_details';
  $field_group->data = array(
    'label' => 'Details Group #4',
    'weight' => '44',
    'children' => array(
      0 => 'field_version',
      1 => 'field_links',
      2 => 'field_project',
      3 => 'field_organisation',
      4 => 'field_contact_details',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details Group #4',
      'instance_settings' => array(
        'id' => 'group-n52-product-details-g4',
        'classes' => 'group-n52-product-details-g4 field-group-div container-fluid',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_n52_product_details_g4|node|tool|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_n52_product_details_g4|node|tool|print';
  $field_group->group_name = 'group_n52_product_details_g4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'print';
  $field_group->parent_name = 'group_n52_product_details';
  $field_group->data = array(
    'label' => 'Details Group #4',
    'weight' => '43',
    'children' => array(
      0 => 'field_version',
      1 => 'field_links',
      2 => 'field_project',
      3 => 'field_organisation',
      4 => 'field_contact_details',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details Group #4',
      'instance_settings' => array(
        'id' => 'group-n52-product-details-g4',
        'classes' => 'group-n52-product-details-g4 field-group-div container-fluid',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_n52_product_details_g4|node|tool|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_n52_product_details|node|tool|default';
  $field_group->group_name = 'group_n52_product_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '9',
    'children' => array(
      0 => 'group_n52_product_details_g1',
      1 => 'group_n52_product_details_g2',
      2 => 'group_n52_product_details_g3',
      3 => 'group_n52_product_details_g4',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'id' => 'group-n52-product-details',
        'classes' => 'group-n52-product-details field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_n52_product_details|node|tool|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_n52_product_details|node|tool|print';
  $field_group->group_name = 'group_n52_product_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '9',
    'children' => array(
      0 => 'group_n52_product_details_g1',
      1 => 'group_n52_product_details_g2',
      2 => 'group_n52_product_details_g3',
      3 => 'group_n52_product_details_g4',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'id' => 'group-n52-product-details',
        'classes' => 'group-n52-product-details field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_n52_product_details|node|tool|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_supported_standards|node|tool|default';
  $field_group->group_name = 'group_supported_standards';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_n52_product_details_g3';
  $field_group->data = array(
    'label' => 'Supported Standards',
    'weight' => '55',
    'children' => array(
      0 => 'field_standard_category',
      1 => 'field_supported_data_discovery_s',
      2 => 'field_supported_data_downloading',
      3 => 'field_supported_data_encoding_st',
      4 => 'field_supported_data_visualizati',
      5 => 'field_supported_processes_and_mo',
      6 => 'field_supported_sensor_data_stan',
      7 => 'field_supported_other_standards',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Supported Standards',
      'instance_settings' => array(
        'id' => 'supported-standards-group',
        'classes' => ' field-group-div supported-standards-group',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_supported_standards|node|tool|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_supported_standards|node|tool|print';
  $field_group->group_name = 'group_supported_standards';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'print';
  $field_group->parent_name = 'group_n52_product_details_g3';
  $field_group->data = array(
    'label' => 'Supported Standards',
    'weight' => '34',
    'children' => array(
      0 => 'field_standard_category',
      1 => 'field_supported_data_discovery_s',
      2 => 'field_supported_data_downloading',
      3 => 'field_supported_data_encoding_st',
      4 => 'field_supported_data_visualizati',
      5 => 'field_supported_processes_and_mo',
      6 => 'field_supported_sensor_data_stan',
      7 => 'field_supported_other_standards',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Supported Standards',
      'instance_settings' => array(
        'id' => 'supported-standards-group',
        'classes' => ' field-group-div supported-standards-group',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_supported_standards|node|tool|print'] = $field_group;

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
  t('Details');
  t('Details Group #1');
  t('Details Group #2');
  t('Details Group #3');
  t('Details Group #4');
  t('How');
  t('Interoperability');
  t('Metadata');
  t('Supported Standards');
  t('What');

  return $field_groups;
}
