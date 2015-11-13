<?php
/**
 * @file
 * permission.use_advanced_search.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'use advanced search',
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
