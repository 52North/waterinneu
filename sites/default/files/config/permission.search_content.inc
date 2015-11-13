<?php
/**
 * @file
 * permission.search_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'search content',
  'roles' => array(
    0 => 'anonymous user',
    1 => 'authenticated user',
    2 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'search',
);
