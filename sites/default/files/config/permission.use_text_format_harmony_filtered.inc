<?php
/**
 * @file
 * permission.use_text_format_harmony_filtered.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'use text format harmony_filtered',
  'roles' => array(
    0 => 'author',
    1 => 'marketplace_author',
    2 => 'moderator',
    3 => 'marketplace_moderator',
    4 => 'administrator',
  ),
);

$dependencies = array(
  'text_format.harmony_filtered' => 'text_format.harmony_filtered',
);

$optional = array();

$modules = array(
  0 => 'filter',
);
