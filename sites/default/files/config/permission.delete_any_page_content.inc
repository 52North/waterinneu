<?php
/**
 * @file
 * permission.delete_any_page_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'delete any page content',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array(
  'content_type.page' => 'content_type.page',
);

$optional = array();

$modules = array(
  0 => 'node',
);
