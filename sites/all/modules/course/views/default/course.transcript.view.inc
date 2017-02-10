<?php

$view = new view();
$view->name = 'transcript';
$view->description = '';
$view->tag = '';
$view->base_table = 'course_report';
$view->human_name = '';
$view->core = 0;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Defaults */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->display->display_options['title'] = 'Completed Activities';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'title' => 'title',
  'timestamp' => 'timestamp',
  'date_completed' => 'date_completed',
  'section_name' => 'section_name',
);
$handler->display->display_options['style_options']['default'] = 'date_completed';
$handler->display->display_options['style_options']['info'] = array(
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'timestamp' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'date_completed' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
  ),
  'section_name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
);
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['text']['id'] = 'area';
$handler->display->display_options['empty']['text']['table'] = 'views';
$handler->display->display_options['empty']['text']['field'] = 'area';
$handler->display->display_options['empty']['text']['content'] = 'You don\'t have any completed activities.';
$handler->display->display_options['empty']['text']['format'] = '2';
/* Relationship: Course report: Nid */
$handler->display->display_options['relationships']['nid']['id'] = 'nid';
$handler->display->display_options['relationships']['nid']['table'] = 'course_report';
$handler->display->display_options['relationships']['nid']['field'] = 'nid';
$handler->display->display_options['relationships']['nid']['required'] = TRUE;
/* Relationship: Course report: Uid */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'course_report';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Relationship: Course report: Course enrollment */
$handler->display->display_options['relationships']['course_enrollment']['id'] = 'course_enrollment';
$handler->display->display_options['relationships']['course_enrollment']['table'] = 'course_report';
$handler->display->display_options['relationships']['course_enrollment']['field'] = 'course_enrollment';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'nid';
/* Field: Course enrollment: Timestamp */
$handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['table'] = 'course_enrollment';
$handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['relationship'] = 'course_enrollment';
$handler->display->display_options['fields']['timestamp']['label'] = 'Date enrolled';
$handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
$handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'm/d/Y';
/* Field: Course report: Section_name */
$handler->display->display_options['fields']['section_name']['id'] = 'section_name';
$handler->display->display_options['fields']['section_name']['table'] = 'course_report';
$handler->display->display_options['fields']['section_name']['field'] = 'section_name';
$handler->display->display_options['fields']['section_name']['label'] = 'Status';
/* Field: Course report: Date_completed */
$handler->display->display_options['fields']['date_completed']['id'] = 'date_completed';
$handler->display->display_options['fields']['date_completed']['table'] = 'course_report';
$handler->display->display_options['fields']['date_completed']['field'] = 'date_completed';
$handler->display->display_options['fields']['date_completed']['label'] = 'Date completed';
$handler->display->display_options['fields']['date_completed']['date_format'] = 'short';
$handler->display->display_options['fields']['date_completed']['custom_date_format'] = 'm/d/Y';
/* Contextual filter: User: Uid */
$handler->display->display_options['arguments']['uid']['id'] = 'uid';
$handler->display->display_options['arguments']['uid']['table'] = 'users';
$handler->display->display_options['arguments']['uid']['field'] = 'uid';
$handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
$handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
$handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
/* Filter criterion: Course report: Complete */
$handler->display->display_options['filters']['complete']['id'] = 'complete';
$handler->display->display_options['filters']['complete']['table'] = 'course_report';
$handler->display->display_options['filters']['complete']['field'] = 'complete';
$handler->display->display_options['filters']['complete']['value']['min'] = '1';
$handler->display->display_options['filters']['complete']['value']['max'] = '1';
$handler->display->display_options['filters']['complete']['value']['value'] = '1';
$handler->display->display_options['filters']['complete']['expose']['operator'] = FALSE;

/* Display: Pending */
$handler = $view->new_display('page', 'Pending', 'pending');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Courses in progress';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['text']['id'] = 'text';
$handler->display->display_options['empty']['text']['table'] = 'views';
$handler->display->display_options['empty']['text']['field'] = 'area';
$handler->display->display_options['empty']['text']['empty'] = TRUE;
$handler->display->display_options['empty']['text']['content'] = 'You don\'t have any courses in progress.';
$handler->display->display_options['empty']['text']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'nid';
/* Field: Course enrollment: Timestamp */
$handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['table'] = 'course_enrollment';
$handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['relationship'] = 'course_enrollment';
$handler->display->display_options['fields']['timestamp']['label'] = 'Date enrolled';
$handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
$handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'd/m/Y';
/* Field: Course report: Section_name */
$handler->display->display_options['fields']['section_name']['id'] = 'section_name';
$handler->display->display_options['fields']['section_name']['table'] = 'course_report';
$handler->display->display_options['fields']['section_name']['field'] = 'section_name';
$handler->display->display_options['fields']['section_name']['label'] = 'Status';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Course report: Complete */
$handler->display->display_options['filters']['complete']['id'] = 'complete';
$handler->display->display_options['filters']['complete']['table'] = 'course_report';
$handler->display->display_options['filters']['complete']['field'] = 'complete';
$handler->display->display_options['path'] = 'user/%/courses/pending';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'In progress';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Completed */
$handler = $view->new_display('page', 'Completed', 'completed');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Completed courses';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['text']['id'] = 'text';
$handler->display->display_options['empty']['text']['table'] = 'views';
$handler->display->display_options['empty']['text']['field'] = 'area';
$handler->display->display_options['empty']['text']['empty'] = TRUE;
$handler->display->display_options['empty']['text']['content'] = 'You don\'t have any completed courses.';
$handler->display->display_options['empty']['text']['format'] = 'filtered_html';
$handler->display->display_options['path'] = 'user/%/courses/completed';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'Completed';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$handler->display->display_options['tab_options']['type'] = 'tab';
$handler->display->display_options['tab_options']['title'] = 'Courses';
$handler->display->display_options['tab_options']['weight'] = '0';
$handler->display->display_options['tab_options']['name'] = 'main-menu';
