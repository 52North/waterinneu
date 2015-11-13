<?php
/**
 * @file
 * permission.edit_own_organisation_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'edit own organisation content',
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
