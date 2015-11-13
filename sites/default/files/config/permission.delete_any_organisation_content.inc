<?php
/**
 * @file
 * permission.delete_any_organisation_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'delete any organisation content',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array(
  'content_type.organisation' => 'content_type.organisation',
);

$optional = array();

$modules = array(
  0 => 'node',
);
