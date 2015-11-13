<?php
/**
 * @file
 * permission.use_text_format_full_html_tinymce.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'use text format full_html_tinymce',
  'roles' => array(
    0 => 'authenticated user',
    1 => 'author',
    2 => 'marketplace_author',
    3 => 'moderator',
    4 => 'marketplace_moderator',
    5 => 'administrator',
  ),
);

$dependencies = array(
  'text_format.full_html_tinymce' => 'text_format.full_html_tinymce',
);

$optional = array();

$modules = array(
  0 => 'filter',
);
