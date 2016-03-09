<?php
/**
 * @file
 * waterinneu_feature_frontpage.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function waterinneu_feature_frontpage_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'frontpage_latest_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Frontpage Latest Content';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'views-row';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'changed' => 'changed',
    'type' => 'type',
    'last_editor' => 'last_editor',
  );
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'short';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'a new ';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['text'] = '<i>[type]</i>';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Last edited by */
  $handler->display->display_options['fields']['last_editor']['id'] = 'last_editor';
  $handler->display->display_options['fields']['last_editor']['table'] = 'node';
  $handler->display->display_options['fields']['last_editor']['field'] = 'last_editor';
  $handler->display->display_options['fields']['last_editor']['label'] = 'by';
  $handler->display->display_options['fields']['last_editor']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['last_editor']['alter']['text'] = '[last_editor]: ';
  $handler->display->display_options['fields']['last_editor']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'frontpage-latest-content';
  $export['frontpage_latest_content'] = $view;

  $view = new view();
  $view->name = 'frontpage_latest_posts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'harmony_post_revision';
  $view->human_name = 'latest-posts';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Post (historical data): Created date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'harmony_post_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'long';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Field: Post (historical data): Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'harmony_post_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Post (historical data): Thread */
  $handler->display->display_options['fields']['field_harmony_thread-revision_id']['id'] = 'field_harmony_thread-revision_id';
  $handler->display->display_options['fields']['field_harmony_thread-revision_id']['table'] = 'field_revision_field_harmony_thread';
  $handler->display->display_options['fields']['field_harmony_thread-revision_id']['field'] = 'field_harmony_thread-revision_id';
  $handler->display->display_options['fields']['field_harmony_thread-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_harmony_thread-revision_id']['settings'] = array(
    'link' => 1,
  );
  /* Field: Post (historical data): Post is reply to */
  $handler->display->display_options['fields']['field_harmony_post_is_reply_to-revision_id']['id'] = 'field_harmony_post_is_reply_to-revision_id';
  $handler->display->display_options['fields']['field_harmony_post_is_reply_to-revision_id']['table'] = 'field_revision_field_harmony_post_is_reply_to';
  $handler->display->display_options['fields']['field_harmony_post_is_reply_to-revision_id']['field'] = 'field_harmony_post_is_reply_to-revision_id';
  $handler->display->display_options['fields']['field_harmony_post_is_reply_to-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_harmony_post_is_reply_to-revision_id']['settings'] = array(
    'link' => 1,
  );
  /* Sort criterion: Post (historical data): Created date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'harmony_post_revision';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';

  /* Display: Latest Posts */
  $handler = $view->new_display('block', 'Latest Posts', 'block');
  $export['frontpage_latest_posts'] = $view;

  $view = new view();
  $view->name = 'frontpage_latest_questions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'harmony_thread';
  $view->human_name = 'Frontpage Latest Questions';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'updated' => 'updated',
    'field_harmony_category' => 'field_harmony_category',
    'uid' => 'uid',
    'harmony_thread_replies' => 'harmony_thread_replies',
  );
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Thread: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'harmony_thread';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_thread'] = TRUE;
  /* Field: Thread: Date updated */
  $handler->display->display_options['fields']['updated']['id'] = 'updated';
  $handler->display->display_options['fields']['updated']['table'] = 'harmony_thread';
  $handler->display->display_options['fields']['updated']['field'] = 'updated';
  $handler->display->display_options['fields']['updated']['label'] = '';
  $handler->display->display_options['fields']['updated']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['updated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['updated']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['updated']['date_format'] = 'short';
  $handler->display->display_options['fields']['updated']['second_date_format'] = 'long';
  /* Field: Thread: Category */
  $handler->display->display_options['fields']['field_harmony_category']['id'] = 'field_harmony_category';
  $handler->display->display_options['fields']['field_harmony_category']['table'] = 'field_data_field_harmony_category';
  $handler->display->display_options['fields']['field_harmony_category']['field'] = 'field_harmony_category';
  $handler->display->display_options['fields']['field_harmony_category']['label'] = '';
  $handler->display->display_options['fields']['field_harmony_category']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_harmony_category']['element_label_colon'] = FALSE;
  /* Field: Thread: Author */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'harmony_thread';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  /* Field: Thread: Number of replies to Thread */
  $handler->display->display_options['fields']['harmony_thread_replies']['id'] = 'harmony_thread_replies';
  $handler->display->display_options['fields']['harmony_thread_replies']['table'] = 'field_data_field_harmony_post_count';
  $handler->display->display_options['fields']['harmony_thread_replies']['field'] = 'harmony_thread_replies';
  $handler->display->display_options['fields']['harmony_thread_replies']['label'] = '';
  $handler->display->display_options['fields']['harmony_thread_replies']['element_label_colon'] = FALSE;
  /* Sort criterion: Thread: Date updated */
  $handler->display->display_options['sorts']['updated']['id'] = 'updated';
  $handler->display->display_options['sorts']['updated']['table'] = 'harmony_thread';
  $handler->display->display_options['sorts']['updated']['field'] = 'updated';
  $handler->display->display_options['sorts']['updated']['order'] = 'DESC';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'frontpage_latest_questions';
  $export['frontpage_latest_questions'] = $view;

  $view = new view();
  $view->name = 'latest_news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'aggregator_item';
  $view->human_name = 'Frontpage Latest News';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest News';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'timestamp' => 'timestamp',
    'author' => 'author',
    'title_1' => 'title_1',
  );
  $handler->display->display_options['row_options']['separator'] = '-';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'title';
  $handler->display->display_options['header']['area']['content'] = '<h2>Latest News</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Aggregator: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'aggregator_item';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Aggregator: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'aggregator_item';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Field: Aggregator: Author */
  $handler->display->display_options['fields']['author']['id'] = 'author';
  $handler->display->display_options['fields']['author']['table'] = 'aggregator_item';
  $handler->display->display_options['fields']['author']['field'] = 'author';
  $handler->display->display_options['fields']['author']['label'] = '';
  $handler->display->display_options['fields']['author']['element_label_colon'] = FALSE;
  /* Field: Aggregator feed: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'aggregator_feed';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['display_as_link'] = FALSE;
  /* Field: Aggregator: Item ID */
  $handler->display->display_options['fields']['iid']['id'] = 'iid';
  $handler->display->display_options['fields']['iid']['table'] = 'aggregator_item';
  $handler->display->display_options['fields']['iid']['field'] = 'iid';
  $handler->display->display_options['fields']['iid']['exclude'] = TRUE;
  /* Sort criterion: Aggregator: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'aggregator_item';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';

  /* Display: Frontpage Latest News */
  $handler = $view->new_display('block', 'Frontpage Latest News', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['block_description'] = 'frontpage_latest_news';
  $export['latest_news'] = $view;

  return $export;
}
