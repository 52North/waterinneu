<?php
/**
 * @file
 * variable.user_picture_file_size.inc
 */

$api = '2.0.0';

$data = $strongarm = new stdClass();
$strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
$strongarm->api_version = 1;
$strongarm->name = 'user_picture_file_size';
$strongarm->value = '800';


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'strongarm',
  1 => 'ctools',
  2 => 'system',
);
