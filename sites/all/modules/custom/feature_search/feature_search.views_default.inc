<?php
/**
 * @file
 * feature_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'advanced_event_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_event_index';
  $view->human_name = 'Advanced Event Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Advanced Event Search';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'entity';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_event_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Filter criterion: Indexed Node: Venue */
  $handler->display->display_options['filters']['field_venue']['id'] = 'field_venue';
  $handler->display->display_options['filters']['field_venue']['table'] = 'search_api_index_event_index';
  $handler->display->display_options['filters']['field_venue']['field'] = 'field_venue';
  $handler->display->display_options['filters']['field_venue']['value'] = array();
  $handler->display->display_options['filters']['field_venue']['group'] = 1;
  $handler->display->display_options['filters']['field_venue']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_venue']['expose']['operator_id'] = 'field_venue_op';
  $handler->display->display_options['filters']['field_venue']['expose']['label'] = 'Venue';
  $handler->display->display_options['filters']['field_venue']['expose']['operator'] = 'field_venue_op';
  $handler->display->display_options['filters']['field_venue']['expose']['identifier'] = 'field_venue';
  $handler->display->display_options['filters']['field_venue']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_venue']['expose']['reduce'] = 0;
  /* Filter criterion: Date: Start date (indexed) */
  $handler->display->display_options['filters']['field_date_year_month_day_value']['id'] = 'field_date_year_month_day_value';
  $handler->display->display_options['filters']['field_date_year_month_day_value']['table'] = 'search_api_index_event_index';
  $handler->display->display_options['filters']['field_date_year_month_day_value']['field'] = 'field_date_year_month_day_value';
  $handler->display->display_options['filters']['field_date_year_month_day_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_year_month_day_value']['group'] = 1;
  $handler->display->display_options['filters']['field_date_year_month_day_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_year_month_day_value']['expose']['operator_id'] = 'field_date_year_month_day_value_op';
  $handler->display->display_options['filters']['field_date_year_month_day_value']['expose']['label'] = 'Start Date';
  $handler->display->display_options['filters']['field_date_year_month_day_value']['expose']['operator'] = 'field_date_year_month_day_value_op';
  $handler->display->display_options['filters']['field_date_year_month_day_value']['expose']['identifier'] = 'field_date_year_month_day_value';
  $handler->display->display_options['filters']['field_date_year_month_day_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_date_year_month_day_value']['widget_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_date_year_month_day_value']['date_popup_format'] = 'd.m.Y';
  $handler->display->display_options['filters']['field_date_year_month_day_value']['year_range'] = '-5:+5';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_event_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['advanced_event_search'] = $view;

  $view = new view();
  $view->name = 'advanced_search_products';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_product_index';
  $view->human_name = 'Advanced Product Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Advanced Product Search';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'entity';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Filter criterion: Indexed Node: Application Scale */
  $handler->display->display_options['filters']['field_application_scale']['id'] = 'field_application_scale';
  $handler->display->display_options['filters']['field_application_scale']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['field_application_scale']['field'] = 'field_application_scale';
  $handler->display->display_options['filters']['field_application_scale']['value'] = array();
  $handler->display->display_options['filters']['field_application_scale']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_application_scale']['expose']['operator_id'] = 'field_application_scale_op';
  $handler->display->display_options['filters']['field_application_scale']['expose']['label'] = 'Application Scale';
  $handler->display->display_options['filters']['field_application_scale']['expose']['operator'] = 'field_application_scale_op';
  $handler->display->display_options['filters']['field_application_scale']['expose']['identifier'] = 'field_application_scale';
  $handler->display->display_options['filters']['field_application_scale']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_application_scale']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Category */
  $handler->display->display_options['filters']['field_category']['id'] = 'field_category';
  $handler->display->display_options['filters']['field_category']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['field_category']['field'] = 'field_category';
  $handler->display->display_options['filters']['field_category']['value'] = array();
  $handler->display->display_options['filters']['field_category']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_category']['expose']['operator_id'] = 'field_category_op';
  $handler->display->display_options['filters']['field_category']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['field_category']['expose']['operator'] = 'field_category_op';
  $handler->display->display_options['filters']['field_category']['expose']['identifier'] = 'field_category';
  $handler->display->display_options['filters']['field_category']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_category']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Costs */
  $handler->display->display_options['filters']['field_costs']['id'] = 'field_costs';
  $handler->display->display_options['filters']['field_costs']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['field_costs']['field'] = 'field_costs';
  $handler->display->display_options['filters']['field_costs']['value'] = array();
  $handler->display->display_options['filters']['field_costs']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_costs']['expose']['operator_id'] = 'field_costs_op';
  $handler->display->display_options['filters']['field_costs']['expose']['label'] = 'Costs';
  $handler->display->display_options['filters']['field_costs']['expose']['operator'] = 'field_costs_op';
  $handler->display->display_options['filters']['field_costs']['expose']['identifier'] = 'field_costs';
  $handler->display->display_options['filters']['field_costs']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_costs']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Issue */
  $handler->display->display_options['filters']['field_issue']['id'] = 'field_issue';
  $handler->display->display_options['filters']['field_issue']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['field_issue']['field'] = 'field_issue';
  $handler->display->display_options['filters']['field_issue']['value'] = array();
  $handler->display->display_options['filters']['field_issue']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_issue']['expose']['operator_id'] = 'field_issue_op';
  $handler->display->display_options['filters']['field_issue']['expose']['label'] = 'Issue';
  $handler->display->display_options['filters']['field_issue']['expose']['operator'] = 'field_issue_op';
  $handler->display->display_options['filters']['field_issue']['expose']['identifier'] = 'field_issue';
  $handler->display->display_options['filters']['field_issue']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_issue']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: License / Copyright */
  $handler->display->display_options['filters']['field_license']['id'] = 'field_license';
  $handler->display->display_options['filters']['field_license']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['field_license']['field'] = 'field_license';
  $handler->display->display_options['filters']['field_license']['value'] = array();
  $handler->display->display_options['filters']['field_license']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_license']['expose']['operator_id'] = 'field_license_op';
  $handler->display->display_options['filters']['field_license']['expose']['label'] = 'License / Copyright';
  $handler->display->display_options['filters']['field_license']['expose']['operator'] = 'field_license_op';
  $handler->display->display_options['filters']['field_license']['expose']['identifier'] = 'field_license';
  $handler->display->display_options['filters']['field_license']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_license']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Purpose */
  $handler->display->display_options['filters']['field_purpose']['id'] = 'field_purpose';
  $handler->display->display_options['filters']['field_purpose']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['field_purpose']['field'] = 'field_purpose';
  $handler->display->display_options['filters']['field_purpose']['value'] = array();
  $handler->display->display_options['filters']['field_purpose']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_purpose']['expose']['operator_id'] = 'field_purpose_op';
  $handler->display->display_options['filters']['field_purpose']['expose']['label'] = 'Purpose';
  $handler->display->display_options['filters']['field_purpose']['expose']['operator'] = 'field_purpose_op';
  $handler->display->display_options['filters']['field_purpose']['expose']['identifier'] = 'field_purpose';
  $handler->display->display_options['filters']['field_purpose']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_purpose']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Relevant Water Bodies */
  $handler->display->display_options['filters']['field_relevant_water_bodies']['id'] = 'field_relevant_water_bodies';
  $handler->display->display_options['filters']['field_relevant_water_bodies']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['field_relevant_water_bodies']['field'] = 'field_relevant_water_bodies';
  $handler->display->display_options['filters']['field_relevant_water_bodies']['value'] = array();
  $handler->display->display_options['filters']['field_relevant_water_bodies']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_relevant_water_bodies']['expose']['operator_id'] = 'field_relevant_water_bodies_op';
  $handler->display->display_options['filters']['field_relevant_water_bodies']['expose']['label'] = 'Relevant Water Bodies';
  $handler->display->display_options['filters']['field_relevant_water_bodies']['expose']['operator'] = 'field_relevant_water_bodies_op';
  $handler->display->display_options['filters']['field_relevant_water_bodies']['expose']['identifier'] = 'field_relevant_water_bodies';
  $handler->display->display_options['filters']['field_relevant_water_bodies']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_relevant_water_bodies']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Standard Category */
  $handler->display->display_options['filters']['field_standard_category']['id'] = 'field_standard_category';
  $handler->display->display_options['filters']['field_standard_category']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['field_standard_category']['field'] = 'field_standard_category';
  $handler->display->display_options['filters']['field_standard_category']['value'] = array();
  $handler->display->display_options['filters']['field_standard_category']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_standard_category']['expose']['operator_id'] = 'field_standard_category_op';
  $handler->display->display_options['filters']['field_standard_category']['expose']['label'] = 'Standard Category';
  $handler->display->display_options['filters']['field_standard_category']['expose']['operator'] = 'field_standard_category_op';
  $handler->display->display_options['filters']['field_standard_category']['expose']['identifier'] = 'field_standard_category';
  $handler->display->display_options['filters']['field_standard_category']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_standard_category']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Target User Group */
  $handler->display->display_options['filters']['field_target_user_group']['id'] = 'field_target_user_group';
  $handler->display->display_options['filters']['field_target_user_group']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['field_target_user_group']['field'] = 'field_target_user_group';
  $handler->display->display_options['filters']['field_target_user_group']['value'] = array();
  $handler->display->display_options['filters']['field_target_user_group']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_target_user_group']['expose']['operator_id'] = 'field_target_user_group_op';
  $handler->display->display_options['filters']['field_target_user_group']['expose']['label'] = 'Target User Group';
  $handler->display->display_options['filters']['field_target_user_group']['expose']['operator'] = 'field_target_user_group_op';
  $handler->display->display_options['filters']['field_target_user_group']['expose']['identifier'] = 'field_target_user_group';
  $handler->display->display_options['filters']['field_target_user_group']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_target_user_group']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Technology Readiness Level */
  $handler->display->display_options['filters']['field_technology_readiness_level']['id'] = 'field_technology_readiness_level';
  $handler->display->display_options['filters']['field_technology_readiness_level']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['field_technology_readiness_level']['field'] = 'field_technology_readiness_level';
  $handler->display->display_options['filters']['field_technology_readiness_level']['value'] = array();
  $handler->display->display_options['filters']['field_technology_readiness_level']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_technology_readiness_level']['expose']['operator_id'] = 'field_technology_readiness_level_op';
  $handler->display->display_options['filters']['field_technology_readiness_level']['expose']['label'] = 'Technology Readiness Level';
  $handler->display->display_options['filters']['field_technology_readiness_level']['expose']['operator'] = 'field_technology_readiness_level_op';
  $handler->display->display_options['filters']['field_technology_readiness_level']['expose']['identifier'] = 'field_technology_readiness_level';
  $handler->display->display_options['filters']['field_technology_readiness_level']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_technology_readiness_level']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Type of Hardware */
  $handler->display->display_options['filters']['field_type_of_hardware']['id'] = 'field_type_of_hardware';
  $handler->display->display_options['filters']['field_type_of_hardware']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['field_type_of_hardware']['field'] = 'field_type_of_hardware';
  $handler->display->display_options['filters']['field_type_of_hardware']['value'] = array();
  $handler->display->display_options['filters']['field_type_of_hardware']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_type_of_hardware']['expose']['operator_id'] = 'field_type_of_hardware_op';
  $handler->display->display_options['filters']['field_type_of_hardware']['expose']['label'] = 'Type of Hardware';
  $handler->display->display_options['filters']['field_type_of_hardware']['expose']['operator'] = 'field_type_of_hardware_op';
  $handler->display->display_options['filters']['field_type_of_hardware']['expose']['identifier'] = 'field_type_of_hardware';
  $handler->display->display_options['filters']['field_type_of_hardware']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_type_of_hardware']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Type of Software */
  $handler->display->display_options['filters']['field_type_of_software']['id'] = 'field_type_of_software';
  $handler->display->display_options['filters']['field_type_of_software']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['field_type_of_software']['field'] = 'field_type_of_software';
  $handler->display->display_options['filters']['field_type_of_software']['value'] = array();
  $handler->display->display_options['filters']['field_type_of_software']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_type_of_software']['expose']['operator_id'] = 'field_type_of_software_op';
  $handler->display->display_options['filters']['field_type_of_software']['expose']['label'] = 'Type of Software';
  $handler->display->display_options['filters']['field_type_of_software']['expose']['operator'] = 'field_type_of_software_op';
  $handler->display->display_options['filters']['field_type_of_software']['expose']['identifier'] = 'field_type_of_software';
  $handler->display->display_options['filters']['field_type_of_software']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_type_of_software']['expose']['reduce'] = 0;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['advanced_search_products'] = $view;

  $view = new view();
  $view->name = 'advanced_search_service_offerings';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_service_offering_index';
  $view->human_name = 'Advanced Service Offering Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Advanced Service Offering Search';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_service_offering_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Filter criterion: Indexed Node: Category */
  $handler->display->display_options['filters']['field_service_category']['id'] = 'field_service_category';
  $handler->display->display_options['filters']['field_service_category']['table'] = 'search_api_index_service_offering_index';
  $handler->display->display_options['filters']['field_service_category']['field'] = 'field_service_category';
  $handler->display->display_options['filters']['field_service_category']['value'] = array();
  $handler->display->display_options['filters']['field_service_category']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_service_category']['expose']['operator_id'] = 'field_service_category_op';
  $handler->display->display_options['filters']['field_service_category']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['field_service_category']['expose']['operator'] = 'field_service_category_op';
  $handler->display->display_options['filters']['field_service_category']['expose']['identifier'] = 'field_service_category';
  $handler->display->display_options['filters']['field_service_category']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_service_category']['expose']['reduce'] = 0;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_service_offering_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['advanced_search_service_offerings'] = $view;

  $view = new view();
  $view->name = 'advanced_search_service_requests';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_service_requests_index';
  $view->human_name = 'Advanced Service Request Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Advanced Service Request Search';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_service_requests_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Filter criterion: Indexed Node: Category */
  $handler->display->display_options['filters']['field_service_category']['id'] = 'field_service_category';
  $handler->display->display_options['filters']['field_service_category']['table'] = 'search_api_index_service_requests_index';
  $handler->display->display_options['filters']['field_service_category']['field'] = 'field_service_category';
  $handler->display->display_options['filters']['field_service_category']['value'] = array();
  $handler->display->display_options['filters']['field_service_category']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_service_category']['expose']['operator_id'] = 'field_service_category_op';
  $handler->display->display_options['filters']['field_service_category']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['field_service_category']['expose']['operator'] = 'field_service_category_op';
  $handler->display->display_options['filters']['field_service_category']['expose']['identifier'] = 'field_service_category';
  $handler->display->display_options['filters']['field_service_category']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_service_category']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Products */
  $handler->display->display_options['filters']['field_product']['id'] = 'field_product';
  $handler->display->display_options['filters']['field_product']['table'] = 'search_api_index_service_requests_index';
  $handler->display->display_options['filters']['field_product']['field'] = 'field_product';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_service_requests_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['advanced_search_service_requests'] = $view;

  $view = new view();
  $view->name = 'view_advanced_search_organsations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_organisation_index';
  $view->human_name = 'Advanced Organisation Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Advanced Organisation Search';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_organisation_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Filter criterion: Indexed Node: Class */
  $handler->display->display_options['filters']['field_class']['id'] = 'field_class';
  $handler->display->display_options['filters']['field_class']['table'] = 'search_api_index_organisation_index';
  $handler->display->display_options['filters']['field_class']['field'] = 'field_class';
  $handler->display->display_options['filters']['field_class']['value'] = array();
  $handler->display->display_options['filters']['field_class']['group'] = 1;
  $handler->display->display_options['filters']['field_class']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_class']['expose']['operator_id'] = 'field_class_op';
  $handler->display->display_options['filters']['field_class']['expose']['label'] = 'Class';
  $handler->display->display_options['filters']['field_class']['expose']['operator'] = 'field_class_op';
  $handler->display->display_options['filters']['field_class']['expose']['identifier'] = 'field_class';
  $handler->display->display_options['filters']['field_class']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_class']['type'] = 'select';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_organisation_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['view_advanced_search_organsations'] = $view;

  return $export;
}
