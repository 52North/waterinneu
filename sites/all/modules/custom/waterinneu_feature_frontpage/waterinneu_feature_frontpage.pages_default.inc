<?php
/**
 * @file
 * waterinneu_feature_frontpage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function waterinneu_feature_frontpage_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'landing_page_panel';
  $page->task = 'page';
  $page->admin_title = 'Landing Page Panel';
  $page->admin_description = 'This panel is used for the landing page.';
  $page->path = 'welcome';
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
  $handler->name = 'page_landing_page_panel__panel';
  $handler->task = 'page';
  $handler->subtask = 'landing_page_panel';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
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
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_column',
          1 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
        'hide_empty' => 1,
      ),
      'left_column' => array(
        'type' => 'region',
        'title' => 'Left Column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left_column' => NULL,
    ),
    'left_column' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '531e6397-ccd9-43f4-b2c2-2ec8e4537502';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1b8cd7e8-163d-446d-8552-2582e5442646';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'views-tool_of_the_month-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'span',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'default',
    );
    $pane->css = array(
      'css_id' => 'product-of-the-month',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1b8cd7e8-163d-446d-8552-2582e5442646';
    $display->content['new-1b8cd7e8-163d-446d-8552-2582e5442646'] = $pane;
    $display->panels['center'][0] = 'new-1b8cd7e8-163d-446d-8552-2582e5442646';
    $pane = new stdClass();
    $pane->pid = 'new-c53a5de9-7e65-4b96-a2ad-6a92d18e1fb7';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'node-recent';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c53a5de9-7e65-4b96-a2ad-6a92d18e1fb7';
    $display->content['new-c53a5de9-7e65-4b96-a2ad-6a92d18e1fb7'] = $pane;
    $display->panels['center'][1] = 'new-c53a5de9-7e65-4b96-a2ad-6a92d18e1fb7';
    $pane = new stdClass();
    $pane->pid = 'new-df9b4537-fc61-4446-9537-d58db53c18c7';
    $pane->panel = 'left_column';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '8781',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'div',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'landingpage-features-accordion',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'df9b4537-fc61-4446-9537-d58db53c18c7';
    $display->content['new-df9b4537-fc61-4446-9537-d58db53c18c7'] = $pane;
    $display->panels['left_column'][0] = 'new-df9b4537-fc61-4446-9537-d58db53c18c7';
    $pane = new stdClass();
    $pane->pid = 'new-89235da5-fb9c-4025-9393-1d2b0c3208ad';
    $pane->panel = 'left_column';
    $pane->type = 'block';
    $pane->subtype = 'twitter_block-1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '89235da5-fb9c-4025-9393-1d2b0c3208ad';
    $display->content['new-89235da5-fb9c-4025-9393-1d2b0c3208ad'] = $pane;
    $display->panels['left_column'][1] = 'new-89235da5-fb9c-4025-9393-1d2b0c3208ad';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-1b8cd7e8-163d-446d-8552-2582e5442646';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['landing_page_panel'] = $page;

  return $pages;

}
