<?php
/**
 * @file
 * text_format.plain_text.inc
 */

$api = '2.0.0';

$data = (object) array(
  'format' => 'plain_text',
  'name' => 'Plain text',
  'cache' => '0',
  'status' => '1',
  'weight' => '-10',
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
    'filter_html_escape' => array(
      'weight' => '0',
      'status' => '1',
      'settings' => array(),
    ),
    'freelinking' => array(
      'weight' => '0',
      'status' => '1',
      'settings' => array(),
    ),
    'filter_url' => array(
      'weight' => '1',
      'status' => '1',
      'settings' => array(
        'filter_url_length' => '72',
      ),
    ),
    'filter_autop' => array(
      'weight' => '2',
      'status' => '1',
      'settings' => array(),
    ),
  ),
);

$dependencies = array();

$optional = array(
  'wysiwyg.plain_text' => 'wysiwyg.plain_text',
);

$modules = array(
  0 => 'atjs',
  1 => 'filter',
  2 => 'freelinking',
);
