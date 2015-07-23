<?php
/**
 * @file
 * permission.access_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'access content',
  'roles' => array(
    0 => 'anonymous user',
    1 => 'authenticated user',
    2 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'node',
);
