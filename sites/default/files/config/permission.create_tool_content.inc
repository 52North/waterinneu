<?php
/**
 * @file
 * permission.create_tool_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'create tool content',
  'roles' => array(
    0 => 'author',
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
