<?php
/**
 * @file
 * permission.administer_nodes.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer nodes',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'node',
);
