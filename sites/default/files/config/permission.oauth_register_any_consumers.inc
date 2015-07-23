<?php
/**
 * @file
 * permission.oauth_register_any_consumers.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'oauth register any consumers',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'oauth_common',
);
