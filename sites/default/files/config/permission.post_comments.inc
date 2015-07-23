<?php
/**
 * @file
 * permission.post_comments.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'post comments',
  'roles' => array(
    0 => 'authenticated user',
    1 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'comment',
);
