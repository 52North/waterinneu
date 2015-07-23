<?php
/**
 * @file
 * permission.administer_rules.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer rules',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'rules',
);
