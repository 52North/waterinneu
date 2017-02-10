<?php

$view = new view();
$view->name = 'course_object_report';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'course_outline_fulfillment';
$view->human_name = 'course object report';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Object report';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
/* Footer: Global: Result summary */
$handler->display->display_options['footer']['result']['id'] = 'result';
$handler->display->display_options['footer']['result']['table'] = 'views';
$handler->display->display_options['footer']['result']['field'] = 'result';
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'There are no attempts on this object.';
$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
/* Relationship: Course object fulfillment: Uid */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'course_outline_fulfillment';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'Username';
/* Field: Course object fulfillment: Date_started */
$handler->display->display_options['fields']['date_started']['id'] = 'date_started';
$handler->display->display_options['fields']['date_started']['table'] = 'course_outline_fulfillment';
$handler->display->display_options['fields']['date_started']['field'] = 'date_started';
$handler->display->display_options['fields']['date_started']['label'] = 'Started';
$handler->display->display_options['fields']['date_started']['date_format'] = 'short';
$handler->display->display_options['fields']['date_started']['second_date_format'] = 'long';
/* Field: Course object fulfillment: Date_completed */
$handler->display->display_options['fields']['date_completed']['id'] = 'date_completed';
$handler->display->display_options['fields']['date_completed']['table'] = 'course_outline_fulfillment';
$handler->display->display_options['fields']['date_completed']['field'] = 'date_completed';
$handler->display->display_options['fields']['date_completed']['label'] = 'Completed';
$handler->display->display_options['fields']['date_completed']['date_format'] = 'short';
$handler->display->display_options['fields']['date_completed']['second_date_format'] = 'long';
/* Field: Course object fulfillment: Grade_result */
$handler->display->display_options['fields']['grade_result']['id'] = 'grade_result';
$handler->display->display_options['fields']['grade_result']['table'] = 'course_outline_fulfillment';
$handler->display->display_options['fields']['grade_result']['field'] = 'grade_result';
$handler->display->display_options['fields']['grade_result']['label'] = 'Grade';
$handler->display->display_options['fields']['grade_result']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['grade_result']['separator'] = '';
/* Contextual filter: Global: Null */
$handler->display->display_options['arguments']['null']['id'] = 'null';
$handler->display->display_options['arguments']['null']['table'] = 'views';
$handler->display->display_options['arguments']['null']['field'] = 'null';
$handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['null']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['null']['validate']['type'] = 'course';
$handler->display->display_options['arguments']['null']['validate_options']['access'] = TRUE;
$handler->display->display_options['arguments']['null']['validate_options']['access_op'] = 'update';
/* Contextual filter: Course object fulfillment: Coid */
$handler->display->display_options['arguments']['coid']['id'] = 'coid';
$handler->display->display_options['arguments']['coid']['table'] = 'course_outline_fulfillment';
$handler->display->display_options['arguments']['coid']['field'] = 'coid';
$handler->display->display_options['arguments']['coid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['coid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['coid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['coid']['summary_options']['items_per_page'] = '25';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'node/%/course-reports/objects/%/overview';
