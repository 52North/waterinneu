<?php
/**
 * @file
 * permission.change_own_username.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'change own username',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'user',
);
