<?php
/**
 * @file
 * permission.administer_filters.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer filters',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'filter',
);
