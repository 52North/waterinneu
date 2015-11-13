<?php
/**
 * @file
 * permission.edit_any_tool_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'edit any tool content',
  'roles' => array(
    0 => 'moderator',
    1 => 'administrator',
  ),
);

$dependencies = array(
  'content_type.tool' => 'content_type.tool',
);

$optional = array();

$modules = array(
  0 => 'node',
);
