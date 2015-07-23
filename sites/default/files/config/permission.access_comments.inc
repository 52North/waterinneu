<?php
/**
 * @file
 * permission.access_comments.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'access comments',
  'roles' => array(
    0 => 'anonymous user',
    1 => 'authenticated user',
    2 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'comment',
);
