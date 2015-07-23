<?php
/**
 * @file
 * permission.administer_search.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer search',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'search',
);
