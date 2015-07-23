<?php
/**
 * @file
 * permission.administer_taxonomy.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer taxonomy',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'taxonomy',
);
