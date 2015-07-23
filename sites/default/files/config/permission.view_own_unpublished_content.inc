<?php
/**
 * @file
 * permission.view_own_unpublished_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'view own unpublished content',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'node',
);
