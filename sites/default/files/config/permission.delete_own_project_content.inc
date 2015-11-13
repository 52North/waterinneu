<?php
/**
 * @file
 * permission.delete_own_project_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'delete own project content',
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
