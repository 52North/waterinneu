<?php
/**
 * @file
 * permission.administer_menu.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer menu',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'menu',
);
