<?php
/**
 * @file
 * permission.use_text_format_full_html.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'use text format full_html',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array(
  'text_format.full_html' => 'text_format.full_html',
);

$optional = array();

$modules = array(
  0 => 'filter',
);
