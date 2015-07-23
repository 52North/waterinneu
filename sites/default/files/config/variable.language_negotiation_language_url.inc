<?php
/**
 * @file
 * variable.language_negotiation_language_url.inc
 */

$api = '2.0.0';

$data = array(
  'name' => 'language_negotiation_language_url',
  'content' => array(
    'locale-url' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_url',
        'switcher' => 'locale_language_switcher_url',
        'url_rewrite' => 'locale_language_url_rewrite_url',
      ),
      'file' => 'includes/locale.inc',
    ),
    'locale-url-fallback' => array(
      'callbacks' => array(
        'language' => 'locale_language_url_fallback',
      ),
      'file' => 'includes/locale.inc',
    ),
  ),
);

$dependencies = array();

$optional = array();

$modules = array();
