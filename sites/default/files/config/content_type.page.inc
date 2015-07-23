<?php
/**
 * @file
 * content_type.page.inc
 */

$api = '2.0.0';

$data = (object) array(
  'type' => 'page',
  'name' => 'Basic page',
  'description' => 'Use <em>basic pages</em> for your static content, such as an \'About us\' page.',
  'has_title' => '1',
  'title_label' => 'Title',
  'base' => 'node_content',
  'help' => '',
);

$dependencies = array(
  'variable.node_options_page' => 'variable.node_options_page',
  'variable.node_submitted_page' => 'variable.node_submitted_page',
);

$optional = array(
  'field.node.body.page' => 'field.node.body.page',
  'permission.create_page_content' => 'permission.create_page_content',
  'permission.edit_own_page_content' => 'permission.edit_own_page_content',
  'permission.edit_any_page_content' => 'permission.edit_any_page_content',
  'permission.delete_own_page_content' => 'permission.delete_own_page_content',
  'permission.delete_any_page_content' => 'permission.delete_any_page_content',
);

$modules = array(
  0 => 'node',
);
