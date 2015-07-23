<?php
/**
 * @file
 * permission.administer_comments.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer comments',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'comment',
);
