<?php
/**
 * @file
 * permission.administer_languages.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer languages',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'locale',
);
