<?php
/**
 * @file
 * n52_feature_frontpage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function n52_feature_frontpage_default_page_manager_pages() {
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
        'contains' => 'column',
        'children' => array(
          0 => 2,
          1 => 1,
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      1 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'children' => array(
          0 => 4,
          1 => 5,
        ),
        'class' => '',
        'hide_empty' => 1,
      ),
      2 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'children' => array(
          0 => 3,
        ),
        'class' => '',
        'hide_empty' => 1,
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_column',
        ),
        'parent' => '2',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left_column' => array(
        'type' => 'region',
        'title' => 'Left Column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
        'hide_empty' => 1,
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'right_column',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      5 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 6,
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      'right_column' => array(
        'type' => 'region',
        'title' => 'Right Column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => '',
        'hide_empty' => 1,
      ),
      6 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '5',
        'children' => array(
          0 => 7,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      7 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(),
        'parent' => '6',
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
      'right_column' => NULL,
    ),
    'left_column' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '531e6397-ccd9-43f4-b2c2-2ec8e4537502';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_landing_page_panel__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a357e199-1345-4ad2-a819-2edd2e600b85';
  $pane->panel = 'left_column';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '8823',
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
  $pane->uuid = 'a357e199-1345-4ad2-a819-2edd2e600b85';
  $display->content['new-a357e199-1345-4ad2-a819-2edd2e600b85'] = $pane;
  $display->panels['left_column'][0] = 'new-a357e199-1345-4ad2-a819-2edd2e600b85';
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
  $pane = new stdClass();
  $pane->pid = 'new-a69c8ba6-ff2a-46c2-87d7-ffd3a204a53f';
  $pane->panel = 'right_column';
  $pane->type = 'block';
  $pane->subtype = 'block-7';
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
  $pane->css = array(
    'css_id' => 'landingpage-introduction',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a69c8ba6-ff2a-46c2-87d7-ffd3a204a53f';
  $display->content['new-a69c8ba6-ff2a-46c2-87d7-ffd3a204a53f'] = $pane;
  $display->panels['right_column'][0] = 'new-a69c8ba6-ff2a-46c2-87d7-ffd3a204a53f';
  $pane = new stdClass();
  $pane->pid = 'new-6875f6bd-9134-4a9c-8d25-883215b72abd';
  $pane->panel = 'right_column';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6875f6bd-9134-4a9c-8d25-883215b72abd';
  $display->content['new-6875f6bd-9134-4a9c-8d25-883215b72abd'] = $pane;
  $display->panels['right_column'][1] = 'new-6875f6bd-9134-4a9c-8d25-883215b72abd';
  $pane = new stdClass();
  $pane->pid = 'new-7dc1d897-f09d-406a-b86a-c7cbc82799ab';
  $pane->panel = 'right_column';
  $pane->type = 'block';
  $pane->subtype = 'block-2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Updates',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '7dc1d897-f09d-406a-b86a-c7cbc82799ab';
  $display->content['new-7dc1d897-f09d-406a-b86a-c7cbc82799ab'] = $pane;
  $display->panels['right_column'][2] = 'new-7dc1d897-f09d-406a-b86a-c7cbc82799ab';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_landing_page_panel__panel_context_e2e66931-e6be-4c91-aa9b-d51bc2527833';
  $handler->task = 'page';
  $handler->subtask = 'landing_page_panel';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'One Column',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'landingpage-one-column',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
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
          0 => 4,
          1 => 'main-row',
          2 => 1,
          3 => 2,
          4 => 3,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
        'class' => 'landing-page-action-buttons row',
        'hide_empty' => 0,
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Button Bar',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'landing-page-button-bar',
        'hide_empty' => 0,
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'tweets',
          1 => 'tweets_and_events',
        ),
        'parent' => 'main',
        'class' => 'landing-page-tweets-and-events row',
        'hide_empty' => 0,
      ),
      'tweets_and_events' => array(
        'type' => 'region',
        'title' => 'Events',
        'width' => '50',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'landing-page-events',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'updates',
        ),
        'parent' => 'main',
        'class' => 'landing-page-updates row',
        'hide_empty' => 0,
      ),
      'updates' => array(
        'type' => 'region',
        'title' => 'Updates',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'landing-page-updates',
        'hide_empty' => 0,
      ),
      'tweets' => array(
        'type' => 'region',
        'title' => 'Tweets',
        'width' => '50',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'landing-page-tweets',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'about',
        ),
        'parent' => 'main',
        'class' => 'landing-page-about row',
        'hide_empty' => 0,
      ),
      'about' => array(
        'type' => 'region',
        'title' => 'About',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => 'landing-page-about',
        'hide_empty' => 0,
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'introduction_text',
        ),
        'parent' => 'main',
        'class' => 'landing-page-introduction-text',
        'hide_empty' => 0,
      ),
      'introduction_text' => array(
        'type' => 'region',
        'title' => 'Introduction Text',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => 'landing-page-introduction-text-region',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'tweets_and_events' => NULL,
      'updates' => NULL,
      'tweets' => NULL,
      'about' => NULL,
      'introduction_text' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fb6d5e54-f87d-4349-9057-e5c79b806b76';
  $display->storage_type = 'page_manager';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4645b426-6e36-40c8-ab76-1af2af0830aa';
  $pane->panel = 'about';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '8884',
    'links' => 0,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'full',
    'link_node_title' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'span',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4645b426-6e36-40c8-ab76-1af2af0830aa';
  $display->content['new-4645b426-6e36-40c8-ab76-1af2af0830aa'] = $pane;
  $display->panels['about'][0] = 'new-4645b426-6e36-40c8-ab76-1af2af0830aa';
  $pane = new stdClass();
  $pane->pid = 'new-feee463e-4160-4f3d-a21b-2f74faa13470';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '8886',
    'links' => 0,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'full',
    'link_node_title' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'span',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'feee463e-4160-4f3d-a21b-2f74faa13470';
  $display->content['new-feee463e-4160-4f3d-a21b-2f74faa13470'] = $pane;
  $display->panels['center'][0] = 'new-feee463e-4160-4f3d-a21b-2f74faa13470';
  $pane = new stdClass();
  $pane->pid = 'new-8ead351e-9236-417b-83b7-7ee5824030d7';
  $pane->panel = 'introduction_text';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '8887',
    'links' => 0,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'full',
    'link_node_title' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'span',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8ead351e-9236-417b-83b7-7ee5824030d7';
  $display->content['new-8ead351e-9236-417b-83b7-7ee5824030d7'] = $pane;
  $display->panels['introduction_text'][0] = 'new-8ead351e-9236-417b-83b7-7ee5824030d7';
  $pane = new stdClass();
  $pane->pid = 'new-84bd7d66-7802-401e-acfa-81fc7fcf1670';
  $pane->panel = 'tweets';
  $pane->type = 'block';
  $pane->subtype = 'twitter_block-1';
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
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '84bd7d66-7802-401e-acfa-81fc7fcf1670';
  $display->content['new-84bd7d66-7802-401e-acfa-81fc7fcf1670'] = $pane;
  $display->panels['tweets'][0] = 'new-84bd7d66-7802-401e-acfa-81fc7fcf1670';
  $pane = new stdClass();
  $pane->pid = 'new-1a786626-82ad-4956-bdaa-b56476ba6e7e';
  $pane->panel = 'tweets_and_events';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '8885',
    'links' => 0,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'full',
    'link_node_title' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'span',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1a786626-82ad-4956-bdaa-b56476ba6e7e';
  $display->content['new-1a786626-82ad-4956-bdaa-b56476ba6e7e'] = $pane;
  $display->panels['tweets_and_events'][0] = 'new-1a786626-82ad-4956-bdaa-b56476ba6e7e';
  $pane = new stdClass();
  $pane->pid = 'new-60a4270b-18c9-454a-bee8-1fb2cb24501e';
  $pane->panel = 'updates';
  $pane->type = 'block';
  $pane->subtype = 'block-2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Updates',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '60a4270b-18c9-454a-bee8-1fb2cb24501e';
  $display->content['new-60a4270b-18c9-454a-bee8-1fb2cb24501e'] = $pane;
  $display->panels['updates'][0] = 'new-60a4270b-18c9-454a-bee8-1fb2cb24501e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['landing_page_panel'] = $page;

  return $pages;

}
