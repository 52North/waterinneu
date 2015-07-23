<?php
/**
 * @file
 * permission.use_text_format_filtered_html.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'use text format filtered_html',
  'roles' => array(
    0 => 'anonymous user',
    1 => 'authenticated user',
    2 => 'administrator',
  ),
);

$dependencies = array(
  'text_format.filtered_html' => 'text_format.filtered_html',
);

$optional = array();

$modules = array(
  0 => 'filter',
);
