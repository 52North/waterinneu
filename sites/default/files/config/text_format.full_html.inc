<?php
/**
 * @file
 * text_format.full_html.inc
 */

$api = '2.0.0';

$data = (object) array(
  'format' => 'full_html',
  'name' => 'Full HTML',
  'cache' => '1',
  'status' => '1',
  'weight' => '1',
  'filters' => array(
    'filter_url' => array(
      'weight' => '0',
      'status' => '1',
      'settings' => array(
        'filter_url_length' => 72,
      ),
    ),
    'filter_autop' => array(
      'weight' => '1',
      'status' => '1',
      'settings' => array(),
    ),
    'filter_htmlcorrector' => array(
      'weight' => '10',
      'status' => '1',
      'settings' => array(),
    ),
  ),
);

$dependencies = array();

$optional = array(
  'permission.use_text_format_full_html' => 'permission.use_text_format_full_html',
);

$modules = array(
  0 => 'filter',
);
