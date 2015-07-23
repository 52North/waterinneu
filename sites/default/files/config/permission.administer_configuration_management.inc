<?php
/**
 * @file
 * permission.administer_configuration_management.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer configuration management',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'configuration_ui',
);
