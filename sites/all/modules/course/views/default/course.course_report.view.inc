<?php

$view = new view();
$view->name = 'course_report';
$view->description = '';
$view->tag = '';
$view->base_table = 'course_report';
$view->human_name = '';
$view->core = 0;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Defaults */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->display->display_options['title'] = 'Course Report';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access all course reports';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = 50;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'realname' => 'realname',
  'timestamp' => 'timestamp',
  'date_completed' => 'date_completed',
  'section_name' => 'section_name',
);
$handler->display->display_options['style_options']['default'] = 'date_completed';
$handler->display->display_options['style_options']['info'] = array(
  'realname' => array(
    'sortable' => 1,
    'separator' => '',
  ),
  'timestamp' => array(
    'sortable' => 1,
    'separator' => '',
  ),
  'date_completed' => array(
    'sortable' => 1,
    'separator' => '',
  ),
  'section_name' => array(
    'sortable' => 1,
    'separator' => '',
  ),
);
$handler->display->display_options['style_options']['order'] = 'desc';
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'Sorry, there is no course data to report on.';
$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
/* Relationship: Course report: Course node */
$handler->display->display_options['relationships']['nid']['id'] = 'nid';
$handler->display->display_options['relationships']['nid']['table'] = 'course_report';
$handler->display->display_options['relationships']['nid']['field'] = 'nid';
$handler->display->display_options['relationships']['nid']['required'] = TRUE;
/* Relationship: Course report: Course user */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'course_report';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
$handler->display->display_options['relationships']['uid']['label'] = 'Course User';
$handler->display->display_options['relationships']['uid']['required'] = TRUE;
/* Relationship: Course report: Course enrollment */
$handler->display->display_options['relationships']['course_enrollment']['id'] = 'course_enrollment';
$handler->display->display_options['relationships']['course_enrollment']['table'] = 'course_report';
$handler->display->display_options['relationships']['course_enrollment']['field'] = 'course_enrollment';
/* Field: Course: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'course_node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['relationship'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = 'Node ID';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'nid';
$handler->display->display_options['fields']['title']['label'] = 'Course';
/* Field: User: Uid */
$handler->display->display_options['fields']['uid']['id'] = 'uid';
$handler->display->display_options['fields']['uid']['table'] = 'users';
$handler->display->display_options['fields']['uid']['field'] = 'uid';
$handler->display->display_options['fields']['uid']['relationship'] = 'uid';
$handler->display->display_options['fields']['uid']['label'] = 'User ID';
$handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
/* Field: Course enrollments: Start of enrollment */
$handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['table'] = 'course_enrollment';
$handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['relationship'] = 'course_enrollment';
$handler->display->display_options['fields']['timestamp']['label'] = 'Date Started';
/* Field: Course report: Course date completed */
$handler->display->display_options['fields']['date_completed']['id'] = 'date_completed';
$handler->display->display_options['fields']['date_completed']['table'] = 'course_report';
$handler->display->display_options['fields']['date_completed']['field'] = 'date_completed';
$handler->display->display_options['fields']['date_completed']['label'] = 'Date Completed';
/* Field: Course report: Course status */
$handler->display->display_options['fields']['section_name']['id'] = 'section_name';
$handler->display->display_options['fields']['section_name']['table'] = 'course_report';
$handler->display->display_options['fields']['section_name']['field'] = 'section_name';
$handler->display->display_options['fields']['section_name']['label'] = 'Status';
/* Contextual filter: Content: Nid */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'node';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['relationship'] = 'nid';
$handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
$handler->display->display_options['arguments']['nid']['title'] = '%1';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['nid']['validate']['type'] = 'course';
$handler->display->display_options['arguments']['nid']['validate_options']['access'] = TRUE;
$handler->display->display_options['arguments']['nid']['validate_options']['access_op'] = 'update';
$handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
/* Filter criterion: Course report: Course date completed */
$handler->display->display_options['filters']['date_completed']['id'] = 'date_completed';
$handler->display->display_options['filters']['date_completed']['table'] = 'course_report';
$handler->display->display_options['filters']['date_completed']['field'] = 'date_completed';
$handler->display->display_options['filters']['date_completed']['operator'] = 'between';
$handler->display->display_options['filters']['date_completed']['exposed'] = TRUE;
$handler->display->display_options['filters']['date_completed']['expose']['operator_id'] = 'date_completed_op';
$handler->display->display_options['filters']['date_completed']['expose']['label'] = 'Completed between';
$handler->display->display_options['filters']['date_completed']['expose']['operator'] = 'date_completed_op';
$handler->display->display_options['filters']['date_completed']['expose']['identifier'] = 'date_completed';
/* Filter criterion: Content: Is a course */
$handler->display->display_options['filters']['course']['id'] = 'course';
$handler->display->display_options['filters']['course']['table'] = 'node';
$handler->display->display_options['filters']['course']['field'] = 'course';
$handler->display->display_options['filters']['course']['relationship'] = 'nid';
$handler->display->display_options['filters']['course']['value'] = '1';

/* Display: Course report */
$handler = $view->new_display('page', 'Course report', 'page_1');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Content: Nid */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'node';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['relationship'] = 'nid';
$handler->display->display_options['arguments']['nid']['default_action'] = 'default';
$handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
$handler->display->display_options['arguments']['nid']['title'] = '%1';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['nid']['validate']['type'] = 'course';
$handler->display->display_options['arguments']['nid']['validate_options']['access'] = TRUE;
$handler->display->display_options['arguments']['nid']['validate_options']['access_op'] = 'update';
$handler->display->display_options['path'] = 'node/%/course-reports/overview';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'Overview';
$handler->display->display_options['menu']['weight'] = '-1';
$handler->display->display_options['tab_options']['type'] = 'tab';
$handler->display->display_options['tab_options']['title'] = 'Course reports';
$handler->display->display_options['tab_options']['weight'] = '1';

/* Display: Global course report */
$handler = $view->new_display('page', 'Global course report', 'page_2');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'All courses';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['path'] = 'admin/reports/course/overview/list';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'All courses';
$handler->display->display_options['menu']['description'] = 'View or download a report of all courses.';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'All courses';
$handler->display->display_options['tab_options']['description'] = 'View and download course information.';
$handler->display->display_options['tab_options']['weight'] = '0';
$handler->display->display_options['tab_options']['name'] = 'management';

/* Display: Global export */
$handler = $view->new_display('views_data_export', 'Global export', 'views_data_export_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Global feed';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'views_data_export_csv';
$handler->display->display_options['style_options']['provide_file'] = 1;
$handler->display->display_options['style_options']['parent_sort'] = 0;
$handler->display->display_options['style_options']['quote'] = 1;
$handler->display->display_options['style_options']['header'] = 1;
$handler->display->display_options['path'] = 'admin/reports/course/overview/csv';
$handler->display->display_options['displays'] = array(
  'page_2' => 'page_2',
  'default' => 0,
  'page_1' => 0,
);
$handler->display->display_options['sitename_title'] = 0;

/* Display: Export */
$handler = $view->new_display('views_data_export', 'Export', 'views_data_export_2');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'views_data_export_csv';
$handler->display->display_options['style_options']['provide_file'] = 1;
$handler->display->display_options['style_options']['filename'] = 'course-report-%1-title.csv';
$handler->display->display_options['style_options']['parent_sort'] = 0;
$handler->display->display_options['style_options']['quote'] = 1;
$handler->display->display_options['style_options']['trim'] = 0;
$handler->display->display_options['style_options']['replace_newlines'] = 0;
$handler->display->display_options['style_options']['header'] = 1;
$handler->display->display_options['path'] = 'node/%/report/csv';
$handler->display->display_options['displays'] = array(
  'page_1' => 'page_1',
  'default' => 0,
  'page_2' => 0,
);
