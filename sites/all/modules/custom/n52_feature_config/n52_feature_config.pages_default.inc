<?php
/**
 * @file
 * n52_feature_config.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function n52_feature_config_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'n52_wieu_page_products_and_services';
  $page->task = 'page';
  $page->admin_title = 'Products and Services Page';
  $page->admin_description = 'Products and Services landing page';
  $page->path = 'products-and-services';
  $page->access = array();
  $page->menu = array(
    'type' => 'none',
    'title' => 'Products & Services',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_n52_wieu_page_products_and_services__panel';
  $handler->task = 'page';
  $handler->subtask = 'n52_wieu_page_products_and_services';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Default',
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
  $display->title = 'Products & Services';
  $display->uuid = '9214a7f5-35c0-4984-8cda-cb5308c7fd7e';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_n52_wieu_page_products_and_services__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-782859aa-eb8d-4711-a6c7-28c052b625d2';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'tool_of_the_month';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'span',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'product-of-the-month',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '782859aa-eb8d-4711-a6c7-28c052b625d2';
  $display->content['new-782859aa-eb8d-4711-a6c7-28c052b625d2'] = $pane;
  $display->panels['center'][0] = 'new-782859aa-eb8d-4711-a6c7-28c052b625d2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['n52_wieu_page_products_and_services'] = $page;

  return $pages;

}
