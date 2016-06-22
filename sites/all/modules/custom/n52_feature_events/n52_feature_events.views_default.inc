<?php
/**
 * @file
 * n52_feature_events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function n52_feature_events_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Filter by';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'A → Z';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Z → A';
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_date_year_month_day) */
  $handler->display->display_options['sorts']['field_date_year_month_day_value']['id'] = 'field_date_year_month_day_value';
  $handler->display->display_options['sorts']['field_date_year_month_day_value']['table'] = 'field_data_field_date_year_month_day';
  $handler->display->display_options['sorts']['field_date_year_month_day_value']['field'] = 'field_date_year_month_day_value';
  $handler->display->display_options['sorts']['field_date_year_month_day_value']['expose']['label'] = 'Date (field_date_year_month_day)';
  /* Sort criterion: Content: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title_field_value']['expose']['label'] = 'Title';
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
  /* Filter criterion: Content: Date -  start date (field_date_year_month_day) */
  $handler->display->display_options['filters']['field_date_year_month_day_value']['id'] = 'field_date_year_month_day_value';
  $handler->display->display_options['filters']['field_date_year_month_day_value']['table'] = 'field_data_field_date_year_month_day';
  $handler->display->display_options['filters']['field_date_year_month_day_value']['field'] = 'field_date_year_month_day_value';
  $handler->display->display_options['filters']['field_date_year_month_day_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_year_month_day_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_year_month_day_value']['expose']['operator_id'] = 'field_date_year_month_day_value_op';
  $handler->display->display_options['filters']['field_date_year_month_day_value']['expose']['label'] = 'Event happens after?';
  $handler->display->display_options['filters']['field_date_year_month_day_value']['expose']['operator'] = 'field_date_year_month_day_value_op';
  $handler->display->display_options['filters']['field_date_year_month_day_value']['expose']['identifier'] = 'field_date_year_month_day_value';
  $handler->display->display_options['filters']['field_date_year_month_day_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_date_year_month_day_value']['default_date'] = 'now -7 day';
  $handler->display->display_options['filters']['field_date_year_month_day_value']['year_range'] = '-0:+5';
  /* Filter criterion: Content: Categorie (field_n52_event_categorie) */
  $handler->display->display_options['filters']['field_n52_event_categorie_tid']['id'] = 'field_n52_event_categorie_tid';
  $handler->display->display_options['filters']['field_n52_event_categorie_tid']['table'] = 'field_data_field_n52_event_categorie';
  $handler->display->display_options['filters']['field_n52_event_categorie_tid']['field'] = 'field_n52_event_categorie_tid';
  $handler->display->display_options['filters']['field_n52_event_categorie_tid']['value'] = array(
    0 => '3549',
  );
  $handler->display->display_options['filters']['field_n52_event_categorie_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_n52_event_categorie_tid']['vocabulary'] = 'n52_event_categories';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'matchmaking/events';
  $export['events'] = $view;

  return $export;
}
