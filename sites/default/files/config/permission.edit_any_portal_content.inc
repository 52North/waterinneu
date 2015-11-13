<?php
/**
 * @file
 * permission.edit_any_portal_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'edit any portal content',
  'roles' => array(
    0 => 'moderator',
    1 => 'administrator',
  ),
);

$dependencies = array(
  'content_type.portal' => 'content_type.portal',
);

$optional = array();

$modules = array(
  0 => 'node',
);
