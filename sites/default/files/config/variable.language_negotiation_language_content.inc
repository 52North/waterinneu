<?php
/**
 * @file
 * variable.language_negotiation_language_content.inc
 */

$api = '2.0.0';

$data = array(
  'name' => 'language_negotiation_language_content',
  'content' => array(
    'locale-interface' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_interface',
      ),
      'file' => 'includes/locale.inc',
    ),
  ),
);

$dependencies = array();

$optional = array();

$modules = array();
