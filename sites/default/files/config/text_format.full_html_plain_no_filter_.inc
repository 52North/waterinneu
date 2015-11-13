<?php
/**
 * @file
 * text_format.full_html_plain_no_filter_.inc
 */

$api = '2.0.0';

$data = (object) array(
  'format' => 'full_html_plain_no_filter_',
  'name' => 'Full HTML - plain (no filter)',
  'cache' => '1',
  'status' => '1',
  'weight' => '0',
  'filters' => array(
    'atjs' => array(
      'weight' => '0',
      'status' => '1',
      'settings' => array(
        'atjs_listeners' => array(
          'harmony_users' => 'harmony_users',
        ),
      ),
    ),
  ),
);

$dependencies = array();

$optional = array(
  'permission.use_text_format_full_html_plain_no_filter_' => 'permission.use_text_format_full_html_plain_no_filter_',
);

$modules = array(
  0 => 'atjs',
);
