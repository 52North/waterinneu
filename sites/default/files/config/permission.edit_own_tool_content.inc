<?php
/**
 * @file
 * permission.edit_own_tool_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'edit own tool content',
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
