<?php
/**
 * @file
 * permission.administer_oauth.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer oauth',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'oauth_common',
);
