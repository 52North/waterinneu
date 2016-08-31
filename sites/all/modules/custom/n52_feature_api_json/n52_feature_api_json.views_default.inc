<?php
/**
 * @file
 * n52_feature_api_json.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function n52_feature_api_json_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'n52_views_api_events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'API: Events Resource';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'events';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 1;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 1;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path']['hide_empty'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'api/events';
  $export['n52_views_api_events'] = $view;

  $view = new view();
  $view->name = 'n52_views_api_organisations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Organisations Ressource';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'organisations';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 1;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 1;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path']['hide_empty'] = TRUE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Class */
  $handler->display->display_options['fields']['field_class']['id'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['table'] = 'field_data_field_class';
  $handler->display->display_options['fields']['field_class']['field'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_class']['delta_offset'] = '0';
  /* Field: Content: Product */
  $handler->display->display_options['fields']['field_product']['id'] = 'field_product';
  $handler->display->display_options['fields']['field_product']['table'] = 'field_data_field_product';
  $handler->display->display_options['fields']['field_product']['field'] = 'field_product';
  $handler->display->display_options['fields']['field_product']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_product']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_product']['delta_offset'] = '0';
  /* Field: Content: Projects */
  $handler->display->display_options['fields']['field_projects']['id'] = 'field_projects';
  $handler->display->display_options['fields']['field_projects']['table'] = 'field_data_field_projects';
  $handler->display->display_options['fields']['field_projects']['field'] = 'field_projects';
  $handler->display->display_options['fields']['field_projects']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_projects']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_projects']['delta_offset'] = '0';
  /* Field: Content: Service Offerings */
  $handler->display->display_options['fields']['field_service_offerings']['id'] = 'field_service_offerings';
  $handler->display->display_options['fields']['field_service_offerings']['table'] = 'field_data_field_service_offerings';
  $handler->display->display_options['fields']['field_service_offerings']['field'] = 'field_service_offerings';
  $handler->display->display_options['fields']['field_service_offerings']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_service_offerings']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_service_offerings']['delta_offset'] = '0';
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_absolute';
  $handler->display->display_options['fields']['field_website']['delta_offset'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organisation' => 'organisation',
  );
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title (title_field)';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Class (field_class) */
  $handler->display->display_options['filters']['field_class_tid']['id'] = 'field_class_tid';
  $handler->display->display_options['filters']['field_class_tid']['table'] = 'field_data_field_class';
  $handler->display->display_options['filters']['field_class_tid']['field'] = 'field_class_tid';
  $handler->display->display_options['filters']['field_class_tid']['value'] = '';
  $handler->display->display_options['filters']['field_class_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_class_tid']['expose']['operator_id'] = 'field_class_tid_op';
  $handler->display->display_options['filters']['field_class_tid']['expose']['label'] = 'Class (field_class)';
  $handler->display->display_options['filters']['field_class_tid']['expose']['operator'] = 'field_class_tid_op';
  $handler->display->display_options['filters']['field_class_tid']['expose']['identifier'] = 'class';
  $handler->display->display_options['filters']['field_class_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_class_tid']['vocabulary'] = 'organisation_classification';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'api/organisations';
  $export['n52_views_api_organisations'] = $view;

  $view = new view();
  $view->name = 'n52_views_api_products';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Products Resource';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'products';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 1;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 1;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'title';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['alter']['text'] = 'http://localhost[path]';
  $handler->display->display_options['fields']['path']['hide_empty'] = TRUE;
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_category']['id'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['table'] = 'field_data_field_category';
  $handler->display->display_options['fields']['field_category']['field'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['hide_empty'] = TRUE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  /* Field: Content: Contact Details */
  $handler->display->display_options['fields']['field_contact_details']['id'] = 'field_contact_details';
  $handler->display->display_options['fields']['field_contact_details']['table'] = 'field_data_field_contact_details';
  $handler->display->display_options['fields']['field_contact_details']['field'] = 'field_contact_details';
  $handler->display->display_options['fields']['field_contact_details']['hide_empty'] = TRUE;
  /* Field: Content: Costinfo */
  $handler->display->display_options['fields']['field_costinfo']['id'] = 'field_costinfo';
  $handler->display->display_options['fields']['field_costinfo']['table'] = 'field_data_field_costinfo';
  $handler->display->display_options['fields']['field_costinfo']['field'] = 'field_costinfo';
  $handler->display->display_options['fields']['field_costinfo']['hide_empty'] = TRUE;
  /* Field: Content: Costs */
  $handler->display->display_options['fields']['field_costs']['id'] = 'field_costs';
  $handler->display->display_options['fields']['field_costs']['table'] = 'field_data_field_costs';
  $handler->display->display_options['fields']['field_costs']['field'] = 'field_costs';
  $handler->display->display_options['fields']['field_costs']['hide_empty'] = TRUE;
  /* Field: Content: Issue */
  $handler->display->display_options['fields']['field_issue']['id'] = 'field_issue';
  $handler->display->display_options['fields']['field_issue']['table'] = 'field_data_field_issue';
  $handler->display->display_options['fields']['field_issue']['field'] = 'field_issue';
  $handler->display->display_options['fields']['field_issue']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_issue']['delta_offset'] = '0';
  /* Field: Content: Issue info */
  $handler->display->display_options['fields']['field_issue_info']['id'] = 'field_issue_info';
  $handler->display->display_options['fields']['field_issue_info']['table'] = 'field_data_field_issue_info';
  $handler->display->display_options['fields']['field_issue_info']['field'] = 'field_issue_info';
  $handler->display->display_options['fields']['field_issue_info']['hide_empty'] = TRUE;
  /* Field: Content: License / Copyright */
  $handler->display->display_options['fields']['field_license']['id'] = 'field_license';
  $handler->display->display_options['fields']['field_license']['table'] = 'field_data_field_license';
  $handler->display->display_options['fields']['field_license']['field'] = 'field_license';
  $handler->display->display_options['fields']['field_license']['hide_empty'] = TRUE;
  /* Field: Content: Licenseinfo */
  $handler->display->display_options['fields']['field_licenseinfo']['id'] = 'field_licenseinfo';
  $handler->display->display_options['fields']['field_licenseinfo']['table'] = 'field_data_field_licenseinfo';
  $handler->display->display_options['fields']['field_licenseinfo']['field'] = 'field_licenseinfo';
  $handler->display->display_options['fields']['field_licenseinfo']['hide_empty'] = TRUE;
  /* Field: Content: Organisation */
  $handler->display->display_options['fields']['field_organisation']['id'] = 'field_organisation';
  $handler->display->display_options['fields']['field_organisation']['table'] = 'field_data_field_organisation';
  $handler->display->display_options['fields']['field_organisation']['field'] = 'field_organisation';
  $handler->display->display_options['fields']['field_organisation']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_organisation']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Potential to combine this product with other products */
  $handler->display->display_options['fields']['field_combinability']['id'] = 'field_combinability';
  $handler->display->display_options['fields']['field_combinability']['table'] = 'field_data_field_combinability';
  $handler->display->display_options['fields']['field_combinability']['field'] = 'field_combinability';
  $handler->display->display_options['fields']['field_combinability']['hide_empty'] = TRUE;
  /* Field: Content: Project */
  $handler->display->display_options['fields']['field_project']['id'] = 'field_project';
  $handler->display->display_options['fields']['field_project']['table'] = 'field_data_field_project';
  $handler->display->display_options['fields']['field_project']['field'] = 'field_project';
  $handler->display->display_options['fields']['field_project']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_project']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: WFD objectives */
  $handler->display->display_options['fields']['field_purpose']['id'] = 'field_purpose';
  $handler->display->display_options['fields']['field_purpose']['table'] = 'field_data_field_purpose';
  $handler->display->display_options['fields']['field_purpose']['field'] = 'field_purpose';
  $handler->display->display_options['fields']['field_purpose']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_purpose']['delta_offset'] = '0';
  /* Field: Content: WFD objectives Info */
  $handler->display->display_options['fields']['field_purpose_info']['id'] = 'field_purpose_info';
  $handler->display->display_options['fields']['field_purpose_info']['table'] = 'field_data_field_purpose_info';
  $handler->display->display_options['fields']['field_purpose_info']['field'] = 'field_purpose_info';
  $handler->display->display_options['fields']['field_purpose_info']['hide_empty'] = TRUE;
  /* Field: Content: Project & promotional material about the product */
  $handler->display->display_options['fields']['field_links']['id'] = 'field_links';
  $handler->display->display_options['fields']['field_links']['table'] = 'field_data_field_links';
  $handler->display->display_options['fields']['field_links']['field'] = 'field_links';
  $handler->display->display_options['fields']['field_links']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_links']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_links']['delta_offset'] = '0';
  /* Field: Content: Relevant Water Bodies */
  $handler->display->display_options['fields']['field_relevant_water_bodies']['id'] = 'field_relevant_water_bodies';
  $handler->display->display_options['fields']['field_relevant_water_bodies']['table'] = 'field_data_field_relevant_water_bodies';
  $handler->display->display_options['fields']['field_relevant_water_bodies']['field'] = 'field_relevant_water_bodies';
  $handler->display->display_options['fields']['field_relevant_water_bodies']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_relevant_water_bodies']['delta_offset'] = '0';
  /* Field: Content: Relevant Water Bodies Info */
  $handler->display->display_options['fields']['field_relevant_water_bodies_info']['id'] = 'field_relevant_water_bodies_info';
  $handler->display->display_options['fields']['field_relevant_water_bodies_info']['table'] = 'field_data_field_relevant_water_bodies_info';
  $handler->display->display_options['fields']['field_relevant_water_bodies_info']['field'] = 'field_relevant_water_bodies_info';
  $handler->display->display_options['fields']['field_relevant_water_bodies_info']['hide_empty'] = TRUE;
  /* Field: Content: Standard Category */
  $handler->display->display_options['fields']['field_standard_category']['id'] = 'field_standard_category';
  $handler->display->display_options['fields']['field_standard_category']['table'] = 'field_data_field_standard_category';
  $handler->display->display_options['fields']['field_standard_category']['field'] = 'field_standard_category';
  $handler->display->display_options['fields']['field_standard_category']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_standard_category']['delta_offset'] = '0';
  /* Field: Content: Supported Data Discovery Standards */
  $handler->display->display_options['fields']['field_supported_data_discovery_s']['id'] = 'field_supported_data_discovery_s';
  $handler->display->display_options['fields']['field_supported_data_discovery_s']['table'] = 'field_data_field_supported_data_discovery_s';
  $handler->display->display_options['fields']['field_supported_data_discovery_s']['field'] = 'field_supported_data_discovery_s';
  $handler->display->display_options['fields']['field_supported_data_discovery_s']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_supported_data_discovery_s']['delta_offset'] = '0';
  /* Field: Content: Supported Data Downloading Standards */
  $handler->display->display_options['fields']['field_supported_data_downloading']['id'] = 'field_supported_data_downloading';
  $handler->display->display_options['fields']['field_supported_data_downloading']['table'] = 'field_data_field_supported_data_downloading';
  $handler->display->display_options['fields']['field_supported_data_downloading']['field'] = 'field_supported_data_downloading';
  $handler->display->display_options['fields']['field_supported_data_downloading']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_supported_data_downloading']['delta_offset'] = '0';
  /* Field: Content: Supported Data Encoding Standards */
  $handler->display->display_options['fields']['field_supported_data_encoding_st']['id'] = 'field_supported_data_encoding_st';
  $handler->display->display_options['fields']['field_supported_data_encoding_st']['table'] = 'field_data_field_supported_data_encoding_st';
  $handler->display->display_options['fields']['field_supported_data_encoding_st']['field'] = 'field_supported_data_encoding_st';
  $handler->display->display_options['fields']['field_supported_data_encoding_st']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_supported_data_encoding_st']['delta_offset'] = '0';
  /* Field: Content: Supported Data Visualization Standards */
  $handler->display->display_options['fields']['field_supported_data_visualizati']['id'] = 'field_supported_data_visualizati';
  $handler->display->display_options['fields']['field_supported_data_visualizati']['table'] = 'field_data_field_supported_data_visualizati';
  $handler->display->display_options['fields']['field_supported_data_visualizati']['field'] = 'field_supported_data_visualizati';
  $handler->display->display_options['fields']['field_supported_data_visualizati']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_supported_data_visualizati']['delta_offset'] = '0';
  /* Field: Content: Supported Legacy Systems */
  $handler->display->display_options['fields']['field_supported_legacy_systems']['id'] = 'field_supported_legacy_systems';
  $handler->display->display_options['fields']['field_supported_legacy_systems']['table'] = 'field_data_field_supported_legacy_systems';
  $handler->display->display_options['fields']['field_supported_legacy_systems']['field'] = 'field_supported_legacy_systems';
  $handler->display->display_options['fields']['field_supported_legacy_systems']['hide_empty'] = TRUE;
  /* Field: Content: Supported Other Standards */
  $handler->display->display_options['fields']['field_supported_other_standards']['id'] = 'field_supported_other_standards';
  $handler->display->display_options['fields']['field_supported_other_standards']['table'] = 'field_data_field_supported_other_standards';
  $handler->display->display_options['fields']['field_supported_other_standards']['field'] = 'field_supported_other_standards';
  $handler->display->display_options['fields']['field_supported_other_standards']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_supported_other_standards']['delta_offset'] = '0';
  /* Field: Content: Supported Processes and Modells Standards */
  $handler->display->display_options['fields']['field_supported_processes_and_mo']['id'] = 'field_supported_processes_and_mo';
  $handler->display->display_options['fields']['field_supported_processes_and_mo']['table'] = 'field_data_field_supported_processes_and_mo';
  $handler->display->display_options['fields']['field_supported_processes_and_mo']['field'] = 'field_supported_processes_and_mo';
  $handler->display->display_options['fields']['field_supported_processes_and_mo']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_supported_processes_and_mo']['delta_offset'] = '0';
  /* Field: Content: Supported Sensor Data Standards */
  $handler->display->display_options['fields']['field_supported_sensor_data_stan']['id'] = 'field_supported_sensor_data_stan';
  $handler->display->display_options['fields']['field_supported_sensor_data_stan']['table'] = 'field_data_field_supported_sensor_data_stan';
  $handler->display->display_options['fields']['field_supported_sensor_data_stan']['field'] = 'field_supported_sensor_data_stan';
  $handler->display->display_options['fields']['field_supported_sensor_data_stan']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_supported_sensor_data_stan']['delta_offset'] = '0';
  /* Field: Content: Target User Group */
  $handler->display->display_options['fields']['field_target_user_group']['id'] = 'field_target_user_group';
  $handler->display->display_options['fields']['field_target_user_group']['table'] = 'field_data_field_target_user_group';
  $handler->display->display_options['fields']['field_target_user_group']['field'] = 'field_target_user_group';
  $handler->display->display_options['fields']['field_target_user_group']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_target_user_group']['delta_offset'] = '0';
  /* Field: Content: Target User Group Info */
  $handler->display->display_options['fields']['field_target_user_group_info']['id'] = 'field_target_user_group_info';
  $handler->display->display_options['fields']['field_target_user_group_info']['table'] = 'field_data_field_target_user_group_info';
  $handler->display->display_options['fields']['field_target_user_group_info']['field'] = 'field_target_user_group_info';
  $handler->display->display_options['fields']['field_target_user_group_info']['hide_empty'] = TRUE;
  /* Field: Content: Type of Hardware */
  $handler->display->display_options['fields']['field_type_of_hardware']['id'] = 'field_type_of_hardware';
  $handler->display->display_options['fields']['field_type_of_hardware']['table'] = 'field_data_field_type_of_hardware';
  $handler->display->display_options['fields']['field_type_of_hardware']['field'] = 'field_type_of_hardware';
  $handler->display->display_options['fields']['field_type_of_hardware']['hide_empty'] = TRUE;
  /* Field: Content: Type of Input requirements */
  $handler->display->display_options['fields']['field_type_of_input_requirements']['id'] = 'field_type_of_input_requirements';
  $handler->display->display_options['fields']['field_type_of_input_requirements']['table'] = 'field_data_field_type_of_input_requirements';
  $handler->display->display_options['fields']['field_type_of_input_requirements']['field'] = 'field_type_of_input_requirements';
  $handler->display->display_options['fields']['field_type_of_input_requirements']['hide_empty'] = TRUE;
  /* Field: Content: Type of Output */
  $handler->display->display_options['fields']['field_type_of_output']['id'] = 'field_type_of_output';
  $handler->display->display_options['fields']['field_type_of_output']['table'] = 'field_data_field_type_of_output';
  $handler->display->display_options['fields']['field_type_of_output']['field'] = 'field_type_of_output';
  $handler->display->display_options['fields']['field_type_of_output']['hide_empty'] = TRUE;
  /* Field: Content: Type of Software */
  $handler->display->display_options['fields']['field_type_of_software']['id'] = 'field_type_of_software';
  $handler->display->display_options['fields']['field_type_of_software']['table'] = 'field_data_field_type_of_software';
  $handler->display->display_options['fields']['field_type_of_software']['field'] = 'field_type_of_software';
  $handler->display->display_options['fields']['field_type_of_software']['hide_empty'] = TRUE;
  /* Field: Content: Version */
  $handler->display->display_options['fields']['field_version']['id'] = 'field_version';
  $handler->display->display_options['fields']['field_version']['table'] = 'field_data_field_version';
  $handler->display->display_options['fields']['field_version']['field'] = 'field_version';
  $handler->display->display_options['fields']['field_version']['hide_empty'] = TRUE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'tool' => 'tool',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'api/products';
  $export['n52_views_api_products'] = $view;

  $view = new view();
  $view->name = 'n52_views_api_projects';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Projects Ressource';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'projects';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 1;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 1;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path']['hide_empty'] = TRUE;
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_absolute';
  $handler->display->display_options['fields']['field_website']['delta_offset'] = '0';
  /* Field: Content: End Date */
  $handler->display->display_options['fields']['field_end_date']['id'] = 'field_end_date';
  $handler->display->display_options['fields']['field_end_date']['table'] = 'field_data_field_end_date';
  $handler->display->display_options['fields']['field_end_date']['field'] = 'field_end_date';
  $handler->display->display_options['fields']['field_end_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_end_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Sort criterion: Content: End Date (field_end_date) */
  $handler->display->display_options['sorts']['field_end_date_value']['id'] = 'field_end_date_value';
  $handler->display->display_options['sorts']['field_end_date_value']['table'] = 'field_data_field_end_date';
  $handler->display->display_options['sorts']['field_end_date_value']['field'] = 'field_end_date_value';
  $handler->display->display_options['sorts']['field_end_date_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_end_date_value']['expose']['label'] = 'End Date (field_end_date)';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title (title_field)';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'api/projects';
  $export['n52_views_api_projects'] = $view;

  $view = new view();
  $view->name = 'n52_views_api_service_offerings';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Service Offerings Ressource';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'sercvice-offerings';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 1;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 1;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path']['hide_empty'] = TRUE;
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_service_category']['id'] = 'field_service_category';
  $handler->display->display_options['fields']['field_service_category']['table'] = 'field_data_field_service_category';
  $handler->display->display_options['fields']['field_service_category']['field'] = 'field_service_category';
  $handler->display->display_options['fields']['field_service_category']['hide_empty'] = TRUE;
  /* Field: Content: Product */
  $handler->display->display_options['fields']['field_product']['id'] = 'field_product';
  $handler->display->display_options['fields']['field_product']['table'] = 'field_data_field_product';
  $handler->display->display_options['fields']['field_product']['field'] = 'field_product';
  $handler->display->display_options['fields']['field_product']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_product']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_product']['delta_offset'] = '0';
  /* Field: Content: Organisation */
  $handler->display->display_options['fields']['field_organisation']['id'] = 'field_organisation';
  $handler->display->display_options['fields']['field_organisation']['table'] = 'field_data_field_organisation';
  $handler->display->display_options['fields']['field_organisation']['field'] = 'field_organisation';
  $handler->display->display_options['fields']['field_organisation']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_organisation']['settings'] = array(
    'link' => 0,
  );
  /* Sort criterion: Content: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title_field_value']['expose']['label'] = 'Title (title_field)';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'service_offering' => 'service_offering',
  );
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title (title_field)';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'api/service-offerings';
  $export['n52_views_api_service_offerings'] = $view;

  $view = new view();
  $view->name = 'n52_views_api_service_requests';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Service Requests Ressource';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'sercvice-requests';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 1;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 1;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path']['hide_empty'] = TRUE;
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_service_category']['id'] = 'field_service_category';
  $handler->display->display_options['fields']['field_service_category']['table'] = 'field_data_field_service_category';
  $handler->display->display_options['fields']['field_service_category']['field'] = 'field_service_category';
  $handler->display->display_options['fields']['field_service_category']['hide_empty'] = TRUE;
  /* Field: Content: Product */
  $handler->display->display_options['fields']['field_product']['id'] = 'field_product';
  $handler->display->display_options['fields']['field_product']['table'] = 'field_data_field_product';
  $handler->display->display_options['fields']['field_product']['field'] = 'field_product';
  $handler->display->display_options['fields']['field_product']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_product']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_product']['delta_offset'] = '0';
  /* Sort criterion: Content: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title_field_value']['expose']['label'] = 'Title (title_field)';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'service_request' => 'service_request',
  );
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title (title_field)';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'api/service-requests';
  $export['n52_views_api_service_requests'] = $view;

  return $export;
}
