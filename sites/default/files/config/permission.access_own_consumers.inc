<?php
/**
 * @file
 * permission.access_own_consumers.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'access own consumers',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'oauth_common',
);
