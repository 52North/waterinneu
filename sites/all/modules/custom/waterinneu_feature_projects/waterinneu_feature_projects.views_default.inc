<?php
/**
 * @file
 * waterinneu_feature_projects.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function waterinneu_feature_projects_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'projects';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = 'Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Projects';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No matches found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Title Sort */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['ui_name'] = 'Title Sort';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Sort criterion: Content: Partners&#039; Countries of Origin  (field_partners_countries_of_orig) */
  $handler->display->display_options['sorts']['field_partners_countries_of_orig_tid']['id'] = 'field_partners_countries_of_orig_tid';
  $handler->display->display_options['sorts']['field_partners_countries_of_orig_tid']['table'] = 'field_data_field_partners_countries_of_orig';
  $handler->display->display_options['sorts']['field_partners_countries_of_orig_tid']['field'] = 'field_partners_countries_of_orig_tid';
  $handler->display->display_options['sorts']['field_partners_countries_of_orig_tid']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_partners_countries_of_orig_tid']['expose']['label'] = 'Partners\' Countries of Origin';
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
  /* Filter criterion: Standards Filter */
  $handler->display->display_options['filters']['field_standards_accounted_for_tid']['id'] = 'field_standards_accounted_for_tid';
  $handler->display->display_options['filters']['field_standards_accounted_for_tid']['table'] = 'field_data_field_standards_accounted_for';
  $handler->display->display_options['filters']['field_standards_accounted_for_tid']['field'] = 'field_standards_accounted_for_tid';
  $handler->display->display_options['filters']['field_standards_accounted_for_tid']['ui_name'] = 'Standards Filter';
  $handler->display->display_options['filters']['field_standards_accounted_for_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_standards_accounted_for_tid']['expose']['operator_id'] = 'field_standards_accounted_for_tid_op';
  $handler->display->display_options['filters']['field_standards_accounted_for_tid']['expose']['label'] = 'Filter by Standards';
  $handler->display->display_options['filters']['field_standards_accounted_for_tid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_standards_accounted_for_tid']['expose']['operator'] = 'field_standards_accounted_for_tid_op';
  $handler->display->display_options['filters']['field_standards_accounted_for_tid']['expose']['identifier'] = 'standards';
  $handler->display->display_options['filters']['field_standards_accounted_for_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_standards_accounted_for_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_standards_accounted_for_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_standards_accounted_for_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_standards_accounted_for_tid']['vocabulary'] = 'standards';
  $handler->display->display_options['filters']['field_standards_accounted_for_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Partners&#039; Countries of Origin  (field_partners_countries_of_orig) */
  $handler->display->display_options['filters']['field_partners_countries_of_orig_tid']['id'] = 'field_partners_countries_of_orig_tid';
  $handler->display->display_options['filters']['field_partners_countries_of_orig_tid']['table'] = 'field_data_field_partners_countries_of_orig';
  $handler->display->display_options['filters']['field_partners_countries_of_orig_tid']['field'] = 'field_partners_countries_of_orig_tid';
  $handler->display->display_options['filters']['field_partners_countries_of_orig_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_partners_countries_of_orig_tid']['expose']['operator_id'] = 'field_partners_countries_of_orig_tid_op';
  $handler->display->display_options['filters']['field_partners_countries_of_orig_tid']['expose']['label'] = 'Filter Partners\' Countries of Origin';
  $handler->display->display_options['filters']['field_partners_countries_of_orig_tid']['expose']['operator'] = 'field_partners_countries_of_orig_tid_op';
  $handler->display->display_options['filters']['field_partners_countries_of_orig_tid']['expose']['identifier'] = 'field_partners_countries_of_orig_tid';
  $handler->display->display_options['filters']['field_partners_countries_of_orig_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_partners_countries_of_orig_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_partners_countries_of_orig_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_partners_countries_of_orig_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_partners_countries_of_orig_tid']['vocabulary'] = 'countries';
  $handler->display->display_options['filters']['field_partners_countries_of_orig_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
    'de' => 'de',
  );
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Filter by Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'projects';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Projects';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $translatables['projects'] = array(
    t('Master'),
    t('Projects'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('No matches found.'),
    t('Title'),
    t('Partners\' Countries of Origin'),
    t('Filter by Standards'),
    t('Filter Partners\' Countries of Origin'),
    t('Filter by Language'),
    t('Page'),
  );
  $export['projects'] = $view;

  return $export;
}