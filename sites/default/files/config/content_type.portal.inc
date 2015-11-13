<?php
/**
 * @file
 * content_type.portal.inc
 */

$api = '2.0.0';

$data = (object) array(
  'type' => 'portal',
  'name' => 'Portal',
  'description' => 'A website that provides means for finding projects, organisations, or experts dealing with a common topic.',
  'has_title' => '1',
  'title_label' => 'Name',
  'base' => 'node_content',
  'help' => 'Portal content type submission guildelines.',
);

$dependencies = array();

$optional = array(
  'field.node.field_website.portal' => 'field.node.field_website.portal',
  'field.node.field_logo.portal' => 'field.node.field_logo.portal',
  'permission.create_portal_content' => 'permission.create_portal_content',
  'permission.edit_own_portal_content' => 'permission.edit_own_portal_content',
  'permission.edit_any_portal_content' => 'permission.edit_any_portal_content',
  'permission.delete_own_portal_content' => 'permission.delete_own_portal_content',
  'permission.delete_any_portal_content' => 'permission.delete_any_portal_content',
);

$modules = array(
  0 => 'node',
);
