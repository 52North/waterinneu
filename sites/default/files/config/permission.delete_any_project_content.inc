<?php
/**
 * @file
 * permission.delete_any_project_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'delete any project content',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array(
  'content_type.project' => 'content_type.project',
);

$optional = array();

$modules = array(
  0 => 'node',
);
