<?php
/**
 * @file
 * permission.edit_own_comments.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'edit own comments',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'comment',
);
