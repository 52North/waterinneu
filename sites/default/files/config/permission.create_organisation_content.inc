<?php
/**
 * @file
 * permission.create_organisation_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'create organisation content',
  'roles' => array(
    0 => 'author',
    1 => 'administrator',
  ),
);

$dependencies = array(
  'content_type.organisation' => 'content_type.organisation',
);

$optional = array();

$modules = array(
  0 => 'node',
);
