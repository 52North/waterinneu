<?php
/**
 * @file
 * permission.edit_own_project_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'edit own project content',
  'roles' => array(
    0 => 'author',
    1 => 'administrator',
  ),
);

$dependencies = array(
  'content_type.project' => 'content_type.project',
);

$optional = array();

$modules = array(
  0 => 'node',
);
