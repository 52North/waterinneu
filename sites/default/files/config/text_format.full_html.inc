<?php
/**
 * @file
 * text_format.full_html.inc
 */

$api = '2.0.0';

$data = (object) array(
  'format' => 'full_html',
  'name' => 'Full HTML - CKEditor',
  'cache' => '0',
  'status' => '1',
  'weight' => '-8',
  'filters' => array(
    'freelinking' => array(
      'weight' => '-48',
      'status' => '1',
      'settings' => array(),
    ),
    'filter_url' => array(
      'weight' => '-47',
      'status' => '1',
      'settings' => array(
        'filter_url_length' => '72',
      ),
    ),
    'filter_autop' => array(
      'weight' => '-46',
      'status' => '1',
      'settings' => array(),
    ),
    'filter_htmlcorrector' => array(
      'weight' => '-45',
      'status' => '1',
      'settings' => array(),
    ),
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
  'permission.use_text_format_full_html' => 'permission.use_text_format_full_html',
  'wysiwyg.full_html' => 'wysiwyg.full_html',
);

$modules = array(
  0 => 'freelinking',
  1 => 'filter',
  2 => 'atjs',
);
