<?php
/**
 * @file
 * n52_feature_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function n52_feature_search_views_default_views() {
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
  $handler->display->display_options['access']['type'] = 'perm';
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
  $handler->display->display_options['access']['type'] = 'perm';
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
  /* Filter criterion: Indexed Node: Category */
  $handler->display->display_options['filters']['field_category']['id'] = 'field_category';
  $handler->display->display_options['filters']['field_category']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['field_category']['field'] = 'field_category';
  $handler->display->display_options['filters']['field_category']['value'] = array();
  $handler->display->display_options['filters']['field_category']['group'] = 1;
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
  $handler->display->display_options['filters']['field_costs']['group'] = 1;
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
  $handler->display->display_options['filters']['field_issue']['group'] = 1;
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
  $handler->display->display_options['filters']['field_license']['group'] = 1;
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
  /* Filter criterion: Indexed Node: Relevant Water Bodies */
  $handler->display->display_options['filters']['field_relevant_water_bodies']['id'] = 'field_relevant_water_bodies';
  $handler->display->display_options['filters']['field_relevant_water_bodies']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['field_relevant_water_bodies']['field'] = 'field_relevant_water_bodies';
  $handler->display->display_options['filters']['field_relevant_water_bodies']['value'] = array();
  $handler->display->display_options['filters']['field_relevant_water_bodies']['group'] = 1;
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
  /* Filter criterion: Indexed Node: Stage of Commercial Development */
  $handler->display->display_options['filters']['field_n52_comm_dev']['id'] = 'field_n52_comm_dev';
  $handler->display->display_options['filters']['field_n52_comm_dev']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['field_n52_comm_dev']['field'] = 'field_n52_comm_dev';
  $handler->display->display_options['filters']['field_n52_comm_dev']['value'] = array();
  $handler->display->display_options['filters']['field_n52_comm_dev']['group'] = 1;
  $handler->display->display_options['filters']['field_n52_comm_dev']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_n52_comm_dev']['expose']['operator_id'] = 'field_n52_comm_dev_op';
  $handler->display->display_options['filters']['field_n52_comm_dev']['expose']['label'] = 'Stage of Commercial Development';
  $handler->display->display_options['filters']['field_n52_comm_dev']['expose']['operator'] = 'field_n52_comm_dev_op';
  $handler->display->display_options['filters']['field_n52_comm_dev']['expose']['identifier'] = 'field_n52_comm_dev';
  $handler->display->display_options['filters']['field_n52_comm_dev']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    10 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_n52_comm_dev']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Standard Category */
  $handler->display->display_options['filters']['field_standard_category']['id'] = 'field_standard_category';
  $handler->display->display_options['filters']['field_standard_category']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['field_standard_category']['field'] = 'field_standard_category';
  $handler->display->display_options['filters']['field_standard_category']['value'] = array();
  $handler->display->display_options['filters']['field_standard_category']['group'] = 1;
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
  $handler->display->display_options['filters']['field_target_user_group']['group'] = 1;
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
  /* Filter criterion: Indexed Node: Type of Hardware */
  $handler->display->display_options['filters']['field_type_of_hardware']['id'] = 'field_type_of_hardware';
  $handler->display->display_options['filters']['field_type_of_hardware']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['field_type_of_hardware']['field'] = 'field_type_of_hardware';
  $handler->display->display_options['filters']['field_type_of_hardware']['value'] = array();
  $handler->display->display_options['filters']['field_type_of_hardware']['group'] = 1;
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
  $handler->display->display_options['filters']['field_type_of_software']['group'] = 1;
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
  /* Filter criterion: Indexed Node: WFD Objectives */
  $handler->display->display_options['filters']['field_purpose']['id'] = 'field_purpose';
  $handler->display->display_options['filters']['field_purpose']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['field_purpose']['field'] = 'field_purpose';
  $handler->display->display_options['filters']['field_purpose']['value'] = array();
  $handler->display->display_options['filters']['field_purpose']['group'] = 1;
  $handler->display->display_options['filters']['field_purpose']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_purpose']['expose']['operator_id'] = 'field_purpose_op';
  $handler->display->display_options['filters']['field_purpose']['expose']['label'] = 'WFD Objective';
  $handler->display->display_options['filters']['field_purpose']['expose']['operator'] = 'field_purpose_op';
  $handler->display->display_options['filters']['field_purpose']['expose']['identifier'] = 'field_purpose';
  $handler->display->display_options['filters']['field_purpose']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    10 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_purpose']['expose']['reduce'] = 0;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_product_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
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
  $handler->display->display_options['access']['type'] = 'perm';
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
  $handler->display->display_options['access']['type'] = 'perm';
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
  /* Filter criterion: Indexed Node: Product */
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
  $view->name = 'n52_views_advanced_search_forum';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_n52_search_api_index_thread';
  $view->human_name = 'Advanced Forum Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Advanced Forum Search';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'harmony_table';
  $handler->display->display_options['style_options']['columns'] = array(
    'last_post_uri' => 'last_post_uri',
    'posts_title' => 'posts_title',
    'field_harmony_last_user_to_reply' => 'field_harmony_last_user_to_reply',
    'created' => 'created',
    'thread_id' => 'thread_id',
    'field_harmony_post_count' => 'field_harmony_post_count',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'last_post_uri' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'cell_class' => '',
      'meta_field' => 0,
    ),
    'posts_title' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'cell_class' => '',
      'meta_field' => 0,
    ),
    'field_harmony_last_user_to_reply' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'cell_class' => '',
      'meta_field' => 0,
    ),
    'created' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'cell_class' => '',
      'meta_field' => 0,
    ),
    'thread_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'cell_class' => '',
      'meta_field' => 0,
    ),
    'field_harmony_post_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'cell_class' => '',
      'meta_field' => 0,
    ),
    'title' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'cell_class' => '',
      'meta_field' => 0,
    ),
  );
  /* Field: last_post_uri */
  $handler->display->display_options['fields']['last_post_uri']['id'] = 'last_post_uri';
  $handler->display->display_options['fields']['last_post_uri']['table'] = 'search_api_index_n52_search_api_index_thread';
  $handler->display->display_options['fields']['last_post_uri']['field'] = 'last_post_uri';
  $handler->display->display_options['fields']['last_post_uri']['ui_name'] = 'last_post_uri';
  $handler->display->display_options['fields']['last_post_uri']['label'] = '';
  $handler->display->display_options['fields']['last_post_uri']['exclude'] = TRUE;
  $handler->display->display_options['fields']['last_post_uri']['element_label_colon'] = FALSE;
  /* Field: Posts: Title (indexed) */
  $handler->display->display_options['fields']['posts_title']['id'] = 'posts_title';
  $handler->display->display_options['fields']['posts_title']['table'] = 'search_api_index_n52_search_api_index_thread';
  $handler->display->display_options['fields']['posts_title']['field'] = 'posts_title';
  $handler->display->display_options['fields']['posts_title']['label'] = 'Title';
  $handler->display->display_options['fields']['posts_title']['alter']['path'] = '[last_post_uri]';
  $handler->display->display_options['fields']['posts_title']['hide_empty'] = TRUE;
  /* Field: Indexed Thread: Last user to post a reply */
  $handler->display->display_options['fields']['field_harmony_last_user_to_reply']['id'] = 'field_harmony_last_user_to_reply';
  $handler->display->display_options['fields']['field_harmony_last_user_to_reply']['table'] = 'search_api_index_n52_search_api_index_thread';
  $handler->display->display_options['fields']['field_harmony_last_user_to_reply']['field'] = 'field_harmony_last_user_to_reply';
  $handler->display->display_options['fields']['field_harmony_last_user_to_reply']['label'] = 'Author';
  /* Field: Indexed Thread: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_n52_search_api_index_thread';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  /* Field: Indexed Thread: Thread ID */
  $handler->display->display_options['fields']['thread_id']['id'] = 'thread_id';
  $handler->display->display_options['fields']['thread_id']['table'] = 'search_api_index_n52_search_api_index_thread';
  $handler->display->display_options['fields']['thread_id']['field'] = 'thread_id';
  $handler->display->display_options['fields']['thread_id']['exclude'] = TRUE;
  /* Field: Indexed Thread: Post count */
  $handler->display->display_options['fields']['field_harmony_post_count']['id'] = 'field_harmony_post_count';
  $handler->display->display_options['fields']['field_harmony_post_count']['table'] = 'search_api_index_n52_search_api_index_thread';
  $handler->display->display_options['fields']['field_harmony_post_count']['field'] = 'field_harmony_post_count';
  $handler->display->display_options['fields']['field_harmony_post_count']['label'] = 'Replies';
  /* Field: Indexed Thread: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_n52_search_api_index_thread';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'in Thread';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_n52_search_api_index_thread';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
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
  $export['n52_views_advanced_search_forum'] = $view;

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
  $handler->display->display_options['access']['type'] = 'perm';
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
