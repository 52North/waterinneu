<?php
/**
 * @file
 * variable.drupal_private_key.inc
 */

$api = '2.0.0';

$data = $strongarm = new stdClass();
$strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
$strongarm->api_version = 1;
$strongarm->name = 'drupal_private_key';
$strongarm->value = 'U81YHp13FQOWQsEO3gLyM0lCp-CMufygF-ttOBOf-0k';


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'strongarm',
  1 => 'ctools',
  2 => 'system',
);
