<?php
/**
 * @file
 * permission.delete_any_tool_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'delete any tool content',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array(
  'content_type.tool' => 'content_type.tool',
);

$optional = array();

$modules = array(
  0 => 'node',
);
