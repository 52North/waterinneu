<?php
/**
 * @file
 * n52_feature_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function n52_feature_search_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'advanced_search';
  $page->task = 'page';
  $page->admin_title = 'Advanced Search';
  $page->admin_description = 'Advanced Search Placeholder page.';
  $page->path = 'search/advanced';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_advanced_search__panel';
  $handler->task = 'page';
  $handler->subtask = 'advanced_search';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '14df7716-8e09-4a79-9374-5d297b9462d6';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_advanced_search__panel';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['advanced_search'] = $page;

  return $pages;

}
