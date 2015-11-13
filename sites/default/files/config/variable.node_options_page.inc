<?php
/**
 * @file
 * variable.node_options_page.inc
 */

$api = '2.0.0';

$data = $strongarm = new stdClass();
$strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
$strongarm->api_version = 1;
$strongarm->name = 'node_options_page';
$strongarm->value = array(
  0 => 'revision',
  1 => 'revision_moderation',
);


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'strongarm',
  1 => 'ctools',
  2 => 'system',
);
