<?php
/**
 * @file
 * variable.variable_module_list.inc
 */

$api = '2.0.0';

$data = $strongarm = new stdClass();
$strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
$strongarm->api_version = 1;
$strongarm->name = 'variable_module_list';
$strongarm->value = array(
  'locale' => array(
    0 => 'language_content_type_article',
    1 => 'language_content_type_page',
    2 => 'language_default',
  ),
  'i18n' => array(
    0 => 'i18n_language_list',
  ),
  'i18n_string' => array(
    0 => 'i18n_string_translate_langcode_en',
    1 => 'i18n_string_allowed_formats',
    2 => 'i18n_string_source_language',
    3 => 'i18n_string_debug',
  ),
  'variable_realm' => array(
    0 => 'variable_realm_list_global',
    1 => 'variable_realm_weight_global',
  ),
  'i18n_sync' => array(
    0 => 'i18n_sync_node_type_article',
    1 => 'i18n_sync_node_type_page',
    2 => 'i18n_sync_node_type_organisation',
    3 => 'i18n_sync_node_type_portal',
    4 => 'i18n_sync_node_type_forum',
    5 => 'i18n_sync_node_type_project',
    6 => 'i18n_sync_node_type_tool',
  ),
  'r4032login' => array(
    0 => 'r4032login_display_denied_message',
    1 => 'r4032login_access_denied_message',
    2 => 'r4032login_redirect_authenticated_users_to',
    3 => 'r4032login_user_login_path',
    4 => 'r4032login_default_redirect_code',
    5 => 'r4032login_match_redirect_code',
    6 => 'r4032login_match_redirect_pages',
  ),
);


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'strongarm',
  1 => 'ctools',
  2 => 'system',
);
