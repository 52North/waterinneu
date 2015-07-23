<?php
/**
 * @file
 * permission.administer_users.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer users',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'user',
);
