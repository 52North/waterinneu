<?php
/**
 * @file
 * n52_feature_i18n.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function n52_feature_i18n_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_comment_filter_article';
  $strongarm->value = 0;
  $export['entity_translation_comment_filter_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_comment_filter_faq';
  $strongarm->value = 0;
  $export['entity_translation_comment_filter_faq'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_comment_filter_organisation';
  $strongarm->value = 0;
  $export['entity_translation_comment_filter_organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_comment_filter_page';
  $strongarm->value = 0;
  $export['entity_translation_comment_filter_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_comment_filter_portal';
  $strongarm->value = 0;
  $export['entity_translation_comment_filter_portal'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_comment_filter_project';
  $strongarm->value = 0;
  $export['entity_translation_comment_filter_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_comment_filter_service_offering';
  $strongarm->value = 0;
  $export['entity_translation_comment_filter_service_offering'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_comment_filter_service_request';
  $strongarm->value = 0;
  $export['entity_translation_comment_filter_service_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_comment_filter_tool';
  $strongarm->value = 0;
  $export['entity_translation_comment_filter_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_entity_types';
  $strongarm->value = array(
    'node' => 'node',
    'taxonomy_term' => 'taxonomy_term',
    'comment' => 'comment',
    'user' => 0,
  );
  $export['entity_translation_entity_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_article';
  $strongarm->value = 1;
  $export['entity_translation_hide_translation_links_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_event';
  $strongarm->value = 1;
  $export['entity_translation_hide_translation_links_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_faq';
  $strongarm->value = 0;
  $export['entity_translation_hide_translation_links_faq'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_organisation';
  $strongarm->value = 1;
  $export['entity_translation_hide_translation_links_organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_page';
  $strongarm->value = 1;
  $export['entity_translation_hide_translation_links_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_portal';
  $strongarm->value = 1;
  $export['entity_translation_hide_translation_links_portal'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_project';
  $strongarm->value = 1;
  $export['entity_translation_hide_translation_links_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_service_offering';
  $strongarm->value = 1;
  $export['entity_translation_hide_translation_links_service_offering'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_service_request';
  $strongarm->value = 1;
  $export['entity_translation_hide_translation_links_service_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_tool';
  $strongarm->value = 1;
  $export['entity_translation_hide_translation_links_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_article';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_event';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_faq';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_faq'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_organisation';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_page';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_portal';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_portal'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_project';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_service_offering';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_service_offering'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_service_request';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_service_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_tool';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_revision_enabled';
  $strongarm->value = TRUE;
  $export['entity_translation_revision_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__article';
  $strongarm->value = array(
    'default_language' => 'und',
    'hide_language_selector' => 0,
    'exclude_language_none' => 0,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_node__article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__organisation';
  $strongarm->value = array(
    'default_language' => 'und',
    'hide_language_selector' => 0,
    'exclude_language_none' => 0,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_node__organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__page';
  $strongarm->value = array(
    'default_language' => 'und',
    'hide_language_selector' => 0,
    'exclude_language_none' => 0,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_node__page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__portal';
  $strongarm->value = array(
    'default_language' => 'en',
    'hide_language_selector' => 0,
    'exclude_language_none' => 1,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_node__portal'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__project';
  $strongarm->value = array(
    'default_language' => 'und',
    'hide_language_selector' => 0,
    'exclude_language_none' => 0,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_node__project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__tool';
  $strongarm->value = array(
    'default_language' => 'und',
    'hide_language_selector' => 0,
    'exclude_language_none' => 0,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_node__tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_taxonomy_term__administrative_levels';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 1,
    'exclude_language_none' => 0,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_taxonomy_term__administrative_levels'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_taxonomy_term__countries';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 1,
    'exclude_language_none' => 0,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_taxonomy_term__countries'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_taxonomy_term__harmony_category';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 1,
    'exclude_language_none' => 0,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_taxonomy_term__harmony_category'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_taxonomy_term__hydrological_level';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 1,
    'exclude_language_none' => 0,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_taxonomy_term__hydrological_level'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_taxonomy_term__license';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 1,
    'exclude_language_none' => 0,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_taxonomy_term__license'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_taxonomy_term__location';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 1,
    'exclude_language_none' => 0,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_taxonomy_term__location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_taxonomy_term__organisation_classification';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 1,
    'exclude_language_none' => 0,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_taxonomy_term__organisation_classification'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_taxonomy_term__standards';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 1,
    'exclude_language_none' => 0,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_taxonomy_term__standards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_taxonomy_term__tags';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 1,
    'exclude_language_none' => 0,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_taxonomy_term__tags'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_shared_labels';
  $strongarm->value = 1;
  $export['entity_translation_shared_labels'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_workflow_enabled';
  $strongarm->value = 0;
  $export['entity_translation_workflow_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'features_admin_show_component_language';
  $strongarm->value = 1;
  $export['features_admin_show_component_language'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'features_component_locked_language';
  $strongarm->value = 0;
  $export['features_component_locked_language'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'freelinking_wikipedia_languagecode';
  $strongarm->value = 'en';
  $export['freelinking_wikipedia_languagecode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_article';
  $strongarm->value = 1;
  $export['i18n_node_extended_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_forum';
  $strongarm->value = 1;
  $export['i18n_node_extended_forum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_organisation';
  $strongarm->value = 1;
  $export['i18n_node_extended_organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_page';
  $strongarm->value = 1;
  $export['i18n_node_extended_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_portal';
  $strongarm->value = 1;
  $export['i18n_node_extended_portal'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_project';
  $strongarm->value = 1;
  $export['i18n_node_extended_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_tool';
  $strongarm->value = 1;
  $export['i18n_node_extended_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_article';
  $strongarm->value = array();
  $export['i18n_node_options_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_forum';
  $strongarm->value = array();
  $export['i18n_node_options_forum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_organisation';
  $strongarm->value = array();
  $export['i18n_node_options_organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_page';
  $strongarm->value = array();
  $export['i18n_node_options_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_portal';
  $strongarm->value = array();
  $export['i18n_node_options_portal'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_project';
  $strongarm->value = array();
  $export['i18n_node_options_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_tool';
  $strongarm->value = array();
  $export['i18n_node_options_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_string_allowed_formats';
  $strongarm->value = array(
    'plain_text' => 'plain_text',
    'filtered_html' => 'filtered_html',
    'full_html' => 'full_html',
    'full_html_tinymce' => 'full_html_tinymce',
    'harmony_filtered' => 'harmony_filtered',
    'full_html_plain_no_filter_' => 'full_html_plain_no_filter_',
  );
  $export['i18n_string_allowed_formats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_string_source_language';
  $strongarm->value = 'en';
  $export['i18n_string_source_language'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_sync_node_type_article';
  $strongarm->value = array();
  $export['i18n_sync_node_type_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_sync_node_type_faq';
  $strongarm->value = array();
  $export['i18n_sync_node_type_faq'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_sync_node_type_page';
  $strongarm->value = array();
  $export['i18n_sync_node_type_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_sync_node_type_portal';
  $strongarm->value = array();
  $export['i18n_sync_node_type_portal'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'l10n_update_download_store';
  $strongarm->value = 'sites/all/translations';
  $export['l10n_update_download_store'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'l10n_update_last_check';
  $strongarm->value = 1465916836;
  $export['l10n_update_last_check'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'l10n_update_rebuild_projects';
  $strongarm->value = 1;
  $export['l10n_update_rebuild_projects'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'l10n_update_translation_status';
  $strongarm->value = array(
    'addressfield' => array(
      'de' => (object) array(
        'name' => 'addressfield',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.2',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'addressfield',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1459344192,
        'last_checked' => 1459344197,
        'files' => array(
          'remote' => (object) array(
            'project' => 'addressfield',
            'langcode' => 'de',
            'version' => '7.x-1.2',
            'type' => 'remote',
            'filename' => 'addressfield-7.x-1.2.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/addressfield/addressfield-7.x-1.2.de.po',
            'timestamp' => 1444459653,
          ),
          'local' => (object) array(
            'project' => 'addressfield',
            'langcode' => 'de',
            'version' => '7.x-1.2',
            'type' => 'local',
            'filename' => 'addressfield-7.x-1.2.de.po',
            'uri' => 'translations://addressfield-7.x-1.2.de.po',
            'timestamp' => 1459344192,
            'directory' => 'translations://',
            'last_checked' => 1459344197,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'adminimal_admin_menu' => array(
      'de' => (object) array(
        'name' => 'adminimal_admin_menu',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.6',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'adminimal_admin_menu',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465305325,
        'last_checked' => 1465304984,
        'files' => array(
          'remote' => (object) array(
            'project' => 'adminimal_admin_menu',
            'langcode' => 'de',
            'version' => '7.x-1.6',
            'type' => 'remote',
            'filename' => 'adminimal_admin_menu-7.x-1.6.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/adminimal_admin_menu/adminimal_admin_menu-7.x-1.6.de.po',
            'timestamp' => 1437375116,
          ),
          'local' => (object) array(
            'project' => 'adminimal_admin_menu',
            'langcode' => 'de',
            'version' => '7.x-1.6',
            'type' => 'local',
            'filename' => 'adminimal_admin_menu-7.x-1.6.de.po',
            'uri' => 'translations://adminimal_admin_menu-7.x-1.6.de.po',
            'timestamp' => 1465305325,
            'directory' => 'translations://',
            'last_checked' => 1465304984,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'adminimal_theme' => array(
      'de' => (object) array(
        'name' => 'adminimal_theme',
        'project_type' => 'theme',
        'core' => '7.x',
        'version' => '7.x-1.23',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'adminimal_theme',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465305326,
        'last_checked' => 1465304984,
        'files' => array(
          'remote' => (object) array(
            'project' => 'adminimal_theme',
            'langcode' => 'de',
            'version' => '7.x-1.23',
            'type' => 'remote',
            'filename' => 'adminimal_theme-7.x-1.23.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/adminimal_theme/adminimal_theme-7.x-1.23.de.po',
            'timestamp' => 1445409261,
          ),
          'local' => (object) array(
            'project' => 'adminimal_theme',
            'langcode' => 'de',
            'version' => '7.x-1.23',
            'type' => 'local',
            'filename' => 'adminimal_theme-7.x-1.23.de.po',
            'uri' => 'translations://adminimal_theme-7.x-1.23.de.po',
            'timestamp' => 1465305326,
            'directory' => 'translations://',
            'last_checked' => 1465304984,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'admin_menu' => array(
      'de' => (object) array(
        'name' => 'admin_menu',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-3.0-rc5',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'admin_menu',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465305327,
        'last_checked' => 1465304984,
        'files' => array(
          'remote' => (object) array(
            'project' => 'admin_menu',
            'langcode' => 'de',
            'version' => '7.x-3.0-rc5',
            'type' => 'remote',
            'filename' => 'admin_menu-7.x-3.0-rc5.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/admin_menu/admin_menu-7.x-3.0-rc5.de.po',
            'timestamp' => 1419233581,
          ),
          'local' => (object) array(
            'project' => 'admin_menu',
            'langcode' => 'de',
            'version' => '7.x-3.0-rc5',
            'type' => 'local',
            'filename' => 'admin_menu-7.x-3.0-rc5.de.po',
            'uri' => 'translations://admin_menu-7.x-3.0-rc5.de.po',
            'timestamp' => 1465305327,
            'directory' => 'translations://',
            'last_checked' => 1465304984,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'admin_views' => array(
      'de' => (object) array(
        'name' => 'admin_views',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.5',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'admin_views',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465305328,
        'last_checked' => 1465304984,
        'files' => array(
          'remote' => (object) array(
            'project' => 'admin_views',
            'langcode' => 'de',
            'version' => '7.x-1.5',
            'type' => 'remote',
            'filename' => 'admin_views-7.x-1.5.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/admin_views/admin_views-7.x-1.5.de.po',
            'timestamp' => 1436423783,
          ),
          'local' => (object) array(
            'project' => 'admin_views',
            'langcode' => 'de',
            'version' => '7.x-1.5',
            'type' => 'local',
            'filename' => 'admin_views-7.x-1.5.de.po',
            'uri' => 'translations://admin_views-7.x-1.5.de.po',
            'timestamp' => 1465305328,
            'directory' => 'translations://',
            'last_checked' => 1465304984,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'advanced_help_hint' => array(
      'de' => (object) array(
        'name' => 'advanced_help_hint',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.2',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'advanced_help_hint',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'advanced_help_hint',
            'langcode' => 'de',
            'version' => '7.x-1.2',
            'type' => 'remote',
            'filename' => 'advanced_help_hint-7.x-1.2.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/advanced_help_hint/advanced_help_hint-7.x-1.2.de.po',
          ),
          'local' => (object) array(
            'project' => 'advanced_help_hint',
            'langcode' => 'de',
            'version' => '7.x-1.2',
            'type' => 'local',
            'filename' => 'advanced_help_hint-7.x-1.2.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://advanced_help_hint-7.x-1.2.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'atjs' => array(
      'de' => (object) array(
        'name' => 'atjs',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.x-dev',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'atjs',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'atjs',
            'langcode' => 'de',
            'version' => '7.x-1.x-dev',
            'type' => 'remote',
            'filename' => 'atjs-7.x-1.x-dev.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/atjs/atjs-7.x-1.x-dev.de.po',
          ),
          'local' => (object) array(
            'project' => 'atjs',
            'langcode' => 'de',
            'version' => '7.x-1.x-dev',
            'type' => 'local',
            'filename' => 'atjs-7.x-1.x-dev.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://atjs-7.x-1.x-dev.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'autocomplete_deluxe' => array(
      'de' => (object) array(
        'name' => 'autocomplete_deluxe',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.1',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'autocomplete_deluxe',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'autocomplete_deluxe',
            'langcode' => 'de',
            'version' => '7.x-2.1',
            'type' => 'remote',
            'filename' => 'autocomplete_deluxe-7.x-2.1.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/autocomplete_deluxe/autocomplete_deluxe-7.x-2.1.de.po',
          ),
          'local' => (object) array(
            'project' => 'autocomplete_deluxe',
            'langcode' => 'de',
            'version' => '7.x-2.1',
            'type' => 'local',
            'filename' => 'autocomplete_deluxe-7.x-2.1.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://autocomplete_deluxe-7.x-2.1.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'backup_migrate' => array(
      'de' => (object) array(
        'name' => 'backup_migrate',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-3.1',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'backup_migrate',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465305332,
        'last_checked' => 1465306262,
        'files' => array(
          'remote' => (object) array(
            'project' => 'backup_migrate',
            'langcode' => 'de',
            'version' => '7.x-3.1',
            'type' => 'remote',
            'filename' => 'backup_migrate-7.x-3.1.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/backup_migrate/backup_migrate-7.x-3.1.de.po',
            'timestamp' => 1431509934,
          ),
          'local' => (object) array(
            'project' => 'backup_migrate',
            'langcode' => 'de',
            'version' => '7.x-3.1',
            'type' => 'local',
            'filename' => 'backup_migrate-7.x-3.1.de.po',
            'uri' => 'translations://backup_migrate-7.x-3.1.de.po',
            'timestamp' => 1465305332,
            'directory' => 'translations://',
            'last_checked' => 1465306262,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'better_formats' => array(
      'de' => (object) array(
        'name' => 'better_formats',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.0-beta1',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'better_formats',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465305336,
        'last_checked' => 1465304984,
        'files' => array(
          'remote' => (object) array(
            'project' => 'better_formats',
            'langcode' => 'de',
            'version' => '7.x-1.0-beta1',
            'type' => 'remote',
            'filename' => 'better_formats-7.x-1.0-beta1.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/better_formats/better_formats-7.x-1.0-beta1.de.po',
            'timestamp' => 1438092547,
          ),
          'local' => (object) array(
            'project' => 'better_formats',
            'langcode' => 'de',
            'version' => '7.x-1.0-beta1',
            'type' => 'local',
            'filename' => 'better_formats-7.x-1.0-beta1.de.po',
            'uri' => 'translations://better_formats-7.x-1.0-beta1.de.po',
            'timestamp' => 1465305336,
            'directory' => 'translations://',
            'last_checked' => 1465304984,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'boolean_formatter' => array(
      'de' => (object) array(
        'name' => 'boolean_formatter',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.3',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'boolean_formatter',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465305337,
        'last_checked' => 1465304984,
        'files' => array(
          'remote' => (object) array(
            'project' => 'boolean_formatter',
            'langcode' => 'de',
            'version' => '7.x-1.3',
            'type' => 'remote',
            'filename' => 'boolean_formatter-7.x-1.3.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/boolean_formatter/boolean_formatter-7.x-1.3.de.po',
            'timestamp' => 1390578896,
          ),
          'local' => (object) array(
            'project' => 'boolean_formatter',
            'langcode' => 'de',
            'version' => '7.x-1.3',
            'type' => 'local',
            'filename' => 'boolean_formatter-7.x-1.3.de.po',
            'uri' => 'translations://boolean_formatter-7.x-1.3.de.po',
            'timestamp' => 1465305337,
            'directory' => 'translations://',
            'last_checked' => 1465304984,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'captcha' => array(
      'de' => (object) array(
        'name' => 'captcha',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.3',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'captcha',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1456149120,
        'last_checked' => 1456149119,
        'files' => array(
          'remote' => (object) array(
            'project' => 'captcha',
            'langcode' => 'de',
            'version' => '7.x-1.3',
            'type' => 'remote',
            'filename' => 'captcha-7.x-1.3.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/captcha/captcha-7.x-1.3.de.po',
            'timestamp' => 1429397590,
          ),
          'local' => (object) array(
            'project' => 'captcha',
            'langcode' => 'de',
            'version' => '7.x-1.3',
            'type' => 'local',
            'filename' => 'captcha-7.x-1.3.de.po',
            'uri' => 'translations://captcha-7.x-1.3.de.po',
            'timestamp' => 1456149120,
            'directory' => 'translations://',
            'last_checked' => 1456149119,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'chain_menu_access' => array(
      'de' => (object) array(
        'name' => 'chain_menu_access',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.0',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'chain_menu_access',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465305338,
        'last_checked' => 1465304984,
        'files' => array(
          'remote' => (object) array(
            'project' => 'chain_menu_access',
            'langcode' => 'de',
            'version' => '7.x-2.0',
            'type' => 'remote',
            'filename' => 'chain_menu_access-7.x-2.0.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/chain_menu_access/chain_menu_access-7.x-2.0.de.po',
            'timestamp' => 1346338942,
          ),
          'local' => (object) array(
            'project' => 'chain_menu_access',
            'langcode' => 'de',
            'version' => '7.x-2.0',
            'type' => 'local',
            'filename' => 'chain_menu_access-7.x-2.0.de.po',
            'uri' => 'translations://chain_menu_access-7.x-2.0.de.po',
            'timestamp' => 1465305338,
            'directory' => 'translations://',
            'last_checked' => 1465304984,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'chosen' => array(
      'de' => (object) array(
        'name' => 'chosen',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.0-beta5',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'chosen',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465305339,
        'last_checked' => 1465304984,
        'files' => array(
          'remote' => (object) array(
            'project' => 'chosen',
            'langcode' => 'de',
            'version' => '7.x-2.0-beta5',
            'type' => 'remote',
            'filename' => 'chosen-7.x-2.0-beta5.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/chosen/chosen-7.x-2.0-beta5.de.po',
            'timestamp' => 1459978757,
          ),
          'local' => (object) array(
            'project' => 'chosen',
            'langcode' => 'de',
            'version' => '7.x-2.0-beta5',
            'type' => 'local',
            'filename' => 'chosen-7.x-2.0-beta5.de.po',
            'uri' => 'translations://chosen-7.x-2.0-beta5.de.po',
            'timestamp' => 1465305339,
            'directory' => 'translations://',
            'last_checked' => 1465304984,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'codefilter' => array(
      'de' => (object) array(
        'name' => 'codefilter',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.1',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'codefilter',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465305339,
        'last_checked' => 1465304984,
        'files' => array(
          'remote' => (object) array(
            'project' => 'codefilter',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'remote',
            'filename' => 'codefilter-7.x-1.1.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/codefilter/codefilter-7.x-1.1.de.po',
            'timestamp' => 1399401678,
          ),
          'local' => (object) array(
            'project' => 'codefilter',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'local',
            'filename' => 'codefilter-7.x-1.1.de.po',
            'uri' => 'translations://codefilter-7.x-1.1.de.po',
            'timestamp' => 1465305339,
            'directory' => 'translations://',
            'last_checked' => 1465304984,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'conditional_fields' => array(
      'de' => (object) array(
        'name' => 'conditional_fields',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-3.0-alpha2',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'conditional_fields',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465305340,
        'last_checked' => 1465304984,
        'files' => array(
          'remote' => (object) array(
            'project' => 'conditional_fields',
            'langcode' => 'de',
            'version' => '7.x-3.0-alpha2',
            'type' => 'remote',
            'filename' => 'conditional_fields-7.x-3.0-alpha2.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/conditional_fields/conditional_fields-7.x-3.0-alpha2.de.po',
            'timestamp' => 1443768143,
          ),
          'local' => (object) array(
            'project' => 'conditional_fields',
            'langcode' => 'de',
            'version' => '7.x-3.0-alpha2',
            'type' => 'local',
            'filename' => 'conditional_fields-7.x-3.0-alpha2.de.po',
            'uri' => 'translations://conditional_fields-7.x-3.0-alpha2.de.po',
            'timestamp' => 1465305340,
            'directory' => 'translations://',
            'last_checked' => 1465304984,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'context' => array(
      'de' => (object) array(
        'name' => 'context',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-3.6',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'context',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465305341,
        'last_checked' => 1465304984,
        'files' => array(
          'remote' => (object) array(
            'project' => 'context',
            'langcode' => 'de',
            'version' => '7.x-3.6',
            'type' => 'remote',
            'filename' => 'context-7.x-3.6.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/context/context-7.x-3.6.de.po',
            'timestamp' => 1421666959,
          ),
          'local' => (object) array(
            'project' => 'context',
            'langcode' => 'de',
            'version' => '7.x-3.6',
            'type' => 'local',
            'filename' => 'context-7.x-3.6.de.po',
            'uri' => 'translations://context-7.x-3.6.de.po',
            'timestamp' => 1465305341,
            'directory' => 'translations://',
            'last_checked' => 1465304984,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'ctools' => array(
      'de' => (object) array(
        'name' => 'ctools',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.9',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'ctools',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465305344,
        'last_checked' => 1465304984,
        'files' => array(
          'remote' => (object) array(
            'project' => 'ctools',
            'langcode' => 'de',
            'version' => '7.x-1.9',
            'type' => 'remote',
            'filename' => 'ctools-7.x-1.9.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/ctools/ctools-7.x-1.9.de.po',
            'timestamp' => 1440230016,
          ),
          'local' => (object) array(
            'project' => 'ctools',
            'langcode' => 'de',
            'version' => '7.x-1.9',
            'type' => 'local',
            'filename' => 'ctools-7.x-1.9.de.po',
            'uri' => 'translations://ctools-7.x-1.9.de.po',
            'timestamp' => 1465305344,
            'directory' => 'translations://',
            'last_checked' => 1465304984,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'custom_search' => array(
      'de' => (object) array(
        'name' => 'custom_search',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.18',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'custom_search',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465305345,
        'last_checked' => 1465304984,
        'files' => array(
          'remote' => (object) array(
            'project' => 'custom_search',
            'langcode' => 'de',
            'version' => '7.x-1.18',
            'type' => 'remote',
            'filename' => 'custom_search-7.x-1.18.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/custom_search/custom_search-7.x-1.18.de.po',
            'timestamp' => 1451118102,
          ),
          'local' => (object) array(
            'project' => 'custom_search',
            'langcode' => 'de',
            'version' => '7.x-1.18',
            'type' => 'local',
            'filename' => 'custom_search-7.x-1.18.de.po',
            'uri' => 'translations://custom_search-7.x-1.18.de.po',
            'timestamp' => 1465305345,
            'directory' => 'translations://',
            'last_checked' => 1465304984,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'date' => array(
      'de' => (object) array(
        'name' => 'date',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.9',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'date',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465305346,
        'last_checked' => 1465306329,
        'files' => array(
          'remote' => (object) array(
            'project' => 'date',
            'langcode' => 'de',
            'version' => '7.x-2.9',
            'type' => 'remote',
            'filename' => 'date-7.x-2.9.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/date/date-7.x-2.9.de.po',
            'timestamp' => 1441955014,
          ),
          'local' => (object) array(
            'project' => 'date',
            'langcode' => 'de',
            'version' => '7.x-2.9',
            'type' => 'local',
            'filename' => 'date-7.x-2.9.de.po',
            'uri' => 'translations://date-7.x-2.9.de.po',
            'timestamp' => 1465305346,
            'directory' => 'translations://',
            'last_checked' => 1465306329,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'devel' => array(
      'de' => (object) array(
        'name' => 'devel',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.5',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'devel',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465305351,
        'last_checked' => 1465304984,
        'files' => array(
          'remote' => (object) array(
            'project' => 'devel',
            'langcode' => 'de',
            'version' => '7.x-1.5',
            'type' => 'remote',
            'filename' => 'devel-7.x-1.5.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/devel/devel-7.x-1.5.de.po',
            'timestamp' => 1414248964,
          ),
          'local' => (object) array(
            'project' => 'devel',
            'langcode' => 'de',
            'version' => '7.x-1.5',
            'type' => 'local',
            'filename' => 'devel-7.x-1.5.de.po',
            'uri' => 'translations://devel-7.x-1.5.de.po',
            'timestamp' => 1465305351,
            'directory' => 'translations://',
            'last_checked' => 1465304984,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'diff' => array(
      'de' => (object) array(
        'name' => 'diff',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-3.2',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'diff',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'diff',
            'langcode' => 'de',
            'version' => '7.x-3.2',
            'type' => 'remote',
            'filename' => 'diff-7.x-3.2.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/diff/diff-7.x-3.2.de.po',
          ),
          'local' => (object) array(
            'project' => 'diff',
            'langcode' => 'de',
            'version' => '7.x-3.2',
            'type' => 'local',
            'filename' => 'diff-7.x-3.2.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://diff-7.x-3.2.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'drupal' => array(
      'de' => (object) array(
        'name' => 'drupal',
        'project_type' => 'core',
        'core' => '7.x',
        'version' => '7.41',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'drupal',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'drupal',
            'langcode' => 'de',
            'version' => '7.41',
            'type' => 'remote',
            'filename' => 'drupal-7.41.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/drupal/drupal-7.41.de.po',
          ),
          'local' => (object) array(
            'project' => 'drupal',
            'langcode' => 'de',
            'version' => '7.41',
            'type' => 'local',
            'filename' => 'drupal-7.41.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://drupal-7.41.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'elements' => array(
      'de' => (object) array(
        'name' => 'elements',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.4',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'elements',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306189,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'elements',
            'langcode' => 'de',
            'version' => '7.x-1.4',
            'type' => 'remote',
            'filename' => 'elements-7.x-1.4.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/elements/elements-7.x-1.4.de.po',
            'timestamp' => 1421645158,
          ),
          'local' => (object) array(
            'project' => 'elements',
            'langcode' => 'de',
            'version' => '7.x-1.4',
            'type' => 'local',
            'filename' => 'elements-7.x-1.4.de.po',
            'uri' => 'translations://elements-7.x-1.4.de.po',
            'timestamp' => 1465306189,
            'directory' => 'translations://',
            'last_checked' => 1465306183,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'entity' => array(
      'de' => (object) array(
        'name' => 'entity',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.6',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'entity',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306191,
        'last_checked' => 1465306262,
        'files' => array(
          'remote' => (object) array(
            'project' => 'entity',
            'langcode' => 'de',
            'version' => '7.x-1.6',
            'type' => 'remote',
            'filename' => 'entity-7.x-1.6.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/entity/entity-7.x-1.6.de.po',
            'timestamp' => 1425100449,
          ),
          'local' => (object) array(
            'project' => 'entity',
            'langcode' => 'de',
            'version' => '7.x-1.6',
            'type' => 'local',
            'filename' => 'entity-7.x-1.6.de.po',
            'uri' => 'translations://entity-7.x-1.6.de.po',
            'timestamp' => 1465306191,
            'directory' => 'translations://',
            'last_checked' => 1465306262,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'entityreference' => array(
      'de' => (object) array(
        'name' => 'entityreference',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.1',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'entityreference',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'entityreference',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'remote',
            'filename' => 'entityreference-7.x-1.1.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/entityreference/entityreference-7.x-1.1.de.po',
          ),
          'local' => (object) array(
            'project' => 'entityreference',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'local',
            'filename' => 'entityreference-7.x-1.1.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://entityreference-7.x-1.1.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'entityreference_prepopulate' => array(
      'de' => (object) array(
        'name' => 'entityreference_prepopulate',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.5',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'entityreference_prepopulate',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'entityreference_prepopulate',
            'langcode' => 'de',
            'version' => '7.x-1.5',
            'type' => 'remote',
            'filename' => 'entityreference_prepopulate-7.x-1.5.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/entityreference_prepopulate/entityreference_prepopulate-7.x-1.5.de.po',
          ),
          'local' => (object) array(
            'project' => 'entityreference_prepopulate',
            'langcode' => 'de',
            'version' => '7.x-1.5',
            'type' => 'local',
            'filename' => 'entityreference_prepopulate-7.x-1.5.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://entityreference_prepopulate-7.x-1.5.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'entityreference_view_widget' => array(
      'de' => (object) array(
        'name' => 'entityreference_view_widget',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.0-rc6',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'entityreference_view_widget',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1457006464,
        'last_checked' => 1457006464,
        'files' => array(
          'remote' => (object) array(
            'project' => 'entityreference_view_widget',
            'langcode' => 'de',
            'version' => '7.x-2.0-rc6',
            'type' => 'remote',
            'filename' => 'entityreference_view_widget-7.x-2.0-rc6.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/entityreference_view_widget/entityreference_view_widget-7.x-2.0-rc6.de.po',
            'timestamp' => 1424581817,
          ),
          'local' => (object) array(
            'project' => 'entityreference_view_widget',
            'langcode' => 'de',
            'version' => '7.x-2.0-rc6',
            'type' => 'local',
            'filename' => 'entityreference_view_widget-7.x-2.0-rc6.de.po',
            'uri' => 'translations://entityreference_view_widget-7.x-2.0-rc6.de.po',
            'timestamp' => 1457006464,
            'directory' => 'translations://',
            'last_checked' => 1457006464,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'entity_quote' => array(
      'de' => (object) array(
        'name' => 'entity_quote',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.x-dev',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'entity_quote',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'entity_quote',
            'langcode' => 'de',
            'version' => '7.x-1.x-dev',
            'type' => 'remote',
            'filename' => 'entity_quote-7.x-1.x-dev.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/entity_quote/entity_quote-7.x-1.x-dev.de.po',
          ),
          'local' => (object) array(
            'project' => 'entity_quote',
            'langcode' => 'de',
            'version' => '7.x-1.x-dev',
            'type' => 'local',
            'filename' => 'entity_quote-7.x-1.x-dev.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://entity_quote-7.x-1.x-dev.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'entity_translation' => array(
      'de' => (object) array(
        'name' => 'entity_translation',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.0-beta4',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'entity_translation',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'entity_translation',
            'langcode' => 'de',
            'version' => '7.x-1.0-beta4',
            'type' => 'remote',
            'filename' => 'entity_translation-7.x-1.0-beta4.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/entity_translation/entity_translation-7.x-1.0-beta4.de.po',
          ),
          'local' => (object) array(
            'project' => 'entity_translation',
            'langcode' => 'de',
            'version' => '7.x-1.0-beta4',
            'type' => 'local',
            'filename' => 'entity_translation-7.x-1.0-beta4.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://entity_translation-7.x-1.0-beta4.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'entity_view_mode' => array(
      'de' => (object) array(
        'name' => 'entity_view_mode',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.0-rc1',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'entity_view_mode',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1382199035,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'entity_view_mode',
            'langcode' => 'de',
            'version' => '7.x-1.0-rc1',
            'type' => 'remote',
            'filename' => 'entity_view_mode-7.x-1.0-rc1.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/entity_view_mode/entity_view_mode-7.x-1.0-rc1.de.po',
            'timestamp' => 1382199035,
          ),
          'local' => (object) array(
            'project' => 'entity_view_mode',
            'langcode' => 'de',
            'version' => '7.x-1.0-rc1',
            'type' => 'local',
            'filename' => 'entity_view_mode-7.x-1.0-rc1.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://entity_view_mode-7.x-1.0-rc1.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'eu_cookie_compliance' => array(
      'de' => (object) array(
        'name' => 'eu_cookie_compliance',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.14',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'eu_cookie_compliance',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1448272647,
        'last_checked' => 1448272646,
        'files' => array(
          'remote' => (object) array(
            'project' => 'eu_cookie_compliance',
            'langcode' => 'de',
            'version' => '7.x-1.14',
            'type' => 'remote',
            'filename' => 'eu_cookie_compliance-7.x-1.14.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/eu_cookie_compliance/eu_cookie_compliance-7.x-1.14.de.po',
            'timestamp' => 1400697147,
          ),
          'local' => (object) array(
            'project' => 'eu_cookie_compliance',
            'langcode' => 'de',
            'version' => '7.x-1.14',
            'type' => 'local',
            'filename' => 'eu_cookie_compliance-7.x-1.14.de.po',
            'uri' => 'translations://eu_cookie_compliance-7.x-1.14.de.po',
            'timestamp' => 1448272647,
            'directory' => 'translations://',
            'last_checked' => 1448272646,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'facetapi' => array(
      'de' => (object) array(
        'name' => 'facetapi',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.5',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'facetapi',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1414239367,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'facetapi',
            'langcode' => 'de',
            'version' => '7.x-1.5',
            'type' => 'remote',
            'filename' => 'facetapi-7.x-1.5.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/facetapi/facetapi-7.x-1.5.de.po',
            'timestamp' => 1414239367,
          ),
          'local' => (object) array(
            'project' => 'facetapi',
            'langcode' => 'de',
            'version' => '7.x-1.5',
            'type' => 'local',
            'filename' => 'facetapi-7.x-1.5.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://facetapi-7.x-1.5.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'faq' => array(
      'de' => (object) array(
        'name' => 'faq',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.1',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'faq',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1449238930,
        'last_checked' => 1449238930,
        'files' => array(
          'remote' => (object) array(
            'project' => 'faq',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'remote',
            'filename' => 'faq-7.x-1.1.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/faq/faq-7.x-1.1.de.po',
            'timestamp' => 1441955350,
          ),
          'local' => (object) array(
            'project' => 'faq',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'local',
            'filename' => 'faq-7.x-1.1.de.po',
            'uri' => 'translations://faq-7.x-1.1.de.po',
            'timestamp' => 1449238930,
            'directory' => 'translations://',
            'last_checked' => 1449238930,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'features' => array(
      'de' => (object) array(
        'name' => 'features',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.7',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'features',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'features',
            'langcode' => 'de',
            'version' => '7.x-2.7',
            'type' => 'remote',
            'filename' => 'features-7.x-2.7.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/features/features-7.x-2.7.de.po',
          ),
          'local' => (object) array(
            'project' => 'features',
            'langcode' => 'de',
            'version' => '7.x-2.7',
            'type' => 'local',
            'filename' => 'features-7.x-2.7.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://features-7.x-2.7.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'features_banish' => array(
      'de' => (object) array(
        'name' => 'features_banish',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.0',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'features_banish',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'features_banish',
            'langcode' => 'de',
            'version' => '7.x-1.0',
            'type' => 'remote',
            'filename' => 'features_banish-7.x-1.0.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/features_banish/features_banish-7.x-1.0.de.po',
          ),
          'local' => (object) array(
            'project' => 'features_banish',
            'langcode' => 'de',
            'version' => '7.x-1.0',
            'type' => 'local',
            'filename' => 'features_banish-7.x-1.0.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://features_banish-7.x-1.0.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'features_extra' => array(
      'de' => (object) array(
        'name' => 'features_extra',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.0',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'features_extra',
        'langcode' => 'de',
        'type' => 'local',
        'timestamp' => 1465306196,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'features_extra',
            'langcode' => 'de',
            'version' => '7.x-1.0',
            'type' => 'remote',
            'filename' => 'features_extra-7.x-1.0.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/features_extra/features_extra-7.x-1.0.de.po',
            'timestamp' => 1439448155,
          ),
          'local' => (object) array(
            'project' => 'features_extra',
            'langcode' => 'de',
            'version' => '7.x-1.0',
            'type' => 'local',
            'filename' => 'features_extra-7.x-1.0.de.po',
            'uri' => 'translations://features_extra-7.x-1.0.de.po',
            'timestamp' => 1465306196,
            'directory' => 'translations://',
          ),
        ),
        'language' => 'de',
        'filename' => '',
        'fileurl' => '',
        'uri' => '',
      ),
    ),
    'features_override' => array(
      'de' => (object) array(
        'name' => 'features_override',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.0-rc3',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'features_override',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'features_override',
            'langcode' => 'de',
            'version' => '7.x-2.0-rc3',
            'type' => 'remote',
            'filename' => 'features_override-7.x-2.0-rc3.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/features_override/features_override-7.x-2.0-rc3.de.po',
          ),
          'local' => (object) array(
            'project' => 'features_override',
            'langcode' => 'de',
            'version' => '7.x-2.0-rc3',
            'type' => 'local',
            'filename' => 'features_override-7.x-2.0-rc3.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://features_override-7.x-2.0-rc3.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'field_group' => array(
      'de' => (object) array(
        'name' => 'field_group',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.4',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'field_group',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1401953050,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'field_group',
            'langcode' => 'de',
            'version' => '7.x-1.4',
            'type' => 'remote',
            'filename' => 'field_group-7.x-1.4.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/field_group/field_group-7.x-1.4.de.po',
            'timestamp' => 1401953050,
          ),
          'local' => (object) array(
            'project' => 'field_group',
            'langcode' => 'de',
            'version' => '7.x-1.4',
            'type' => 'local',
            'filename' => 'field_group-7.x-1.4.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://field_group-7.x-1.4.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'flag' => array(
      'de' => (object) array(
        'name' => 'flag',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-3.7',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'flag',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'flag',
            'langcode' => 'de',
            'version' => '7.x-3.7',
            'type' => 'remote',
            'filename' => 'flag-7.x-3.7.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/flag/flag-7.x-3.7.de.po',
          ),
          'local' => (object) array(
            'project' => 'flag',
            'langcode' => 'de',
            'version' => '7.x-3.7',
            'type' => 'local',
            'filename' => 'flag-7.x-3.7.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://flag-7.x-3.7.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'fpa' => array(
      'de' => (object) array(
        'name' => 'fpa',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.6',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'fpa',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1408792364,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'fpa',
            'langcode' => 'de',
            'version' => '7.x-2.6',
            'type' => 'remote',
            'filename' => 'fpa-7.x-2.6.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/fpa/fpa-7.x-2.6.de.po',
            'timestamp' => 1408792364,
          ),
          'local' => (object) array(
            'project' => 'fpa',
            'langcode' => 'de',
            'version' => '7.x-2.6',
            'type' => 'local',
            'filename' => 'fpa-7.x-2.6.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://fpa-7.x-2.6.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'freelinking' => array(
      'de' => (object) array(
        'name' => 'freelinking',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-3.8',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'freelinking',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'freelinking',
            'langcode' => 'de',
            'version' => '7.x-3.8',
            'type' => 'remote',
            'filename' => 'freelinking-7.x-3.8.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/freelinking/freelinking-7.x-3.8.de.po',
          ),
          'local' => (object) array(
            'project' => 'freelinking',
            'langcode' => 'de',
            'version' => '7.x-3.8',
            'type' => 'local',
            'filename' => 'freelinking-7.x-3.8.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://freelinking-7.x-3.8.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'geofield' => array(
      'de' => (object) array(
        'name' => 'geofield',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.3',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'geofield',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1446244251,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'geofield',
            'langcode' => 'de',
            'version' => '7.x-2.3',
            'type' => 'remote',
            'filename' => 'geofield-7.x-2.3.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/geofield/geofield-7.x-2.3.de.po',
            'timestamp' => 1446244251,
          ),
          'local' => (object) array(
            'project' => 'geofield',
            'langcode' => 'de',
            'version' => '7.x-2.3',
            'type' => 'local',
            'filename' => 'geofield-7.x-2.3.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://geofield-7.x-2.3.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'geophp' => array(
      'de' => (object) array(
        'name' => 'geophp',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.7',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'geophp',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'geophp',
            'langcode' => 'de',
            'version' => '7.x-1.7',
            'type' => 'remote',
            'filename' => 'geophp-7.x-1.7.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/geophp/geophp-7.x-1.7.de.po',
          ),
          'local' => (object) array(
            'project' => 'geophp',
            'langcode' => 'de',
            'version' => '7.x-1.7',
            'type' => 'local',
            'filename' => 'geophp-7.x-1.7.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://geophp-7.x-1.7.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'globalredirect' => array(
      'de' => (object) array(
        'name' => 'globalredirect',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.5',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'globalredirect',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1339749142,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'globalredirect',
            'langcode' => 'de',
            'version' => '7.x-1.5',
            'type' => 'remote',
            'filename' => 'globalredirect-7.x-1.5.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/globalredirect/globalredirect-7.x-1.5.de.po',
            'timestamp' => 1339749142,
          ),
          'local' => (object) array(
            'project' => 'globalredirect',
            'langcode' => 'de',
            'version' => '7.x-1.5',
            'type' => 'local',
            'filename' => 'globalredirect-7.x-1.5.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://globalredirect-7.x-1.5.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'harmony_access' => array(
      'de' => (object) array(
        'name' => 'harmony_access',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.0-alpha1',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'harmony_access',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'harmony_access',
            'langcode' => 'de',
            'version' => '7.x-1.0-alpha1',
            'type' => 'remote',
            'filename' => 'harmony_access-7.x-1.0-alpha1.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/harmony_access/harmony_access-7.x-1.0-alpha1.de.po',
          ),
          'local' => (object) array(
            'project' => 'harmony_access',
            'langcode' => 'de',
            'version' => '7.x-1.0-alpha1',
            'type' => 'local',
            'filename' => 'harmony_access-7.x-1.0-alpha1.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://harmony_access-7.x-1.0-alpha1.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'harmony_core' => array(
      'de' => (object) array(
        'name' => 'harmony_core',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.0-alpha7',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'harmony_core',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1455638043,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'harmony_core',
            'langcode' => 'de',
            'version' => '7.x-1.0-alpha7',
            'type' => 'remote',
            'filename' => 'harmony_core-7.x-1.0-alpha7.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/harmony_core/harmony_core-7.x-1.0-alpha7.de.po',
            'timestamp' => 1455638043,
          ),
          'local' => (object) array(
            'project' => 'harmony_core',
            'langcode' => 'de',
            'version' => '7.x-1.0-alpha7',
            'type' => 'local',
            'filename' => 'harmony_core-7.x-1.0-alpha7.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://harmony_core-7.x-1.0-alpha7.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'harmony_search' => array(
      'de' => (object) array(
        'name' => 'harmony_search',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.x-dev',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'harmony_search',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'harmony_search',
            'langcode' => 'de',
            'version' => '7.x-1.x-dev',
            'type' => 'remote',
            'filename' => 'harmony_search-7.x-1.x-dev.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/harmony_search/harmony_search-7.x-1.x-dev.de.po',
          ),
          'local' => (object) array(
            'project' => 'harmony_search',
            'langcode' => 'de',
            'version' => '7.x-1.x-dev',
            'type' => 'local',
            'filename' => 'harmony_search-7.x-1.x-dev.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://harmony_search-7.x-1.x-dev.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'http_client' => array(
      'de' => (object) array(
        'name' => 'http_client',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.4',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'http_client',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'http_client',
            'langcode' => 'de',
            'version' => '7.x-2.4',
            'type' => 'remote',
            'filename' => 'http_client-7.x-2.4.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/http_client/http_client-7.x-2.4.de.po',
          ),
          'local' => (object) array(
            'project' => 'http_client',
            'langcode' => 'de',
            'version' => '7.x-2.4',
            'type' => 'local',
            'filename' => 'http_client-7.x-2.4.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://http_client-7.x-2.4.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'i18n' => array(
      'de' => (object) array(
        'name' => 'i18n',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.13',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'i18n',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'i18n',
            'langcode' => 'de',
            'version' => '7.x-1.13',
            'type' => 'remote',
            'filename' => 'i18n-7.x-1.13.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/i18n/i18n-7.x-1.13.de.po',
          ),
          'local' => (object) array(
            'project' => 'i18n',
            'langcode' => 'de',
            'version' => '7.x-1.13',
            'type' => 'local',
            'filename' => 'i18n-7.x-1.13.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://i18n-7.x-1.13.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'i18nviews' => array(
      'de' => (object) array(
        'name' => 'i18nviews',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-3.x-dev',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'i18nviews',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'i18nviews',
            'langcode' => 'de',
            'version' => '7.x-3.x-dev',
            'type' => 'remote',
            'filename' => 'i18nviews-7.x-3.x-dev.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/i18nviews/i18nviews-7.x-3.x-dev.de.po',
          ),
          'local' => (object) array(
            'project' => 'i18nviews',
            'langcode' => 'de',
            'version' => '7.x-3.x-dev',
            'type' => 'local',
            'filename' => 'i18nviews-7.x-3.x-dev.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://i18nviews-7.x-3.x-dev.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'imce' => array(
      'de' => (object) array(
        'name' => 'imce',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.9',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'imce',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1400316146,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'imce',
            'langcode' => 'de',
            'version' => '7.x-1.9',
            'type' => 'remote',
            'filename' => 'imce-7.x-1.9.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/imce/imce-7.x-1.9.de.po',
            'timestamp' => 1400316146,
          ),
          'local' => (object) array(
            'project' => 'imce',
            'langcode' => 'de',
            'version' => '7.x-1.9',
            'type' => 'local',
            'filename' => 'imce-7.x-1.9.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://imce-7.x-1.9.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'imce_wysiwyg' => array(
      'de' => (object) array(
        'name' => 'imce_wysiwyg',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.0',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'imce_wysiwyg',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'imce_wysiwyg',
            'langcode' => 'de',
            'version' => '7.x-1.0',
            'type' => 'remote',
            'filename' => 'imce_wysiwyg-7.x-1.0.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/imce_wysiwyg/imce_wysiwyg-7.x-1.0.de.po',
          ),
          'local' => (object) array(
            'project' => 'imce_wysiwyg',
            'langcode' => 'de',
            'version' => '7.x-1.0',
            'type' => 'local',
            'filename' => 'imce_wysiwyg-7.x-1.0.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://imce_wysiwyg-7.x-1.0.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'inline_entity_form' => array(
      'de' => (object) array(
        'name' => 'inline_entity_form',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.6',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'inline_entity_form',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1434566086,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'inline_entity_form',
            'langcode' => 'de',
            'version' => '7.x-1.6',
            'type' => 'remote',
            'filename' => 'inline_entity_form-7.x-1.6.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/inline_entity_form/inline_entity_form-7.x-1.6.de.po',
            'timestamp' => 1434566086,
          ),
          'local' => (object) array(
            'project' => 'inline_entity_form',
            'langcode' => 'de',
            'version' => '7.x-1.6',
            'type' => 'local',
            'filename' => 'inline_entity_form-7.x-1.6.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://inline_entity_form-7.x-1.6.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'jquery_update' => array(
      'de' => (object) array(
        'name' => 'jquery_update',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-3.0-alpha3',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'jquery_update',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'jquery_update',
            'langcode' => 'de',
            'version' => '7.x-3.0-alpha3',
            'type' => 'remote',
            'filename' => 'jquery_update-7.x-3.0-alpha3.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/jquery_update/jquery_update-7.x-3.0-alpha3.de.po',
          ),
          'local' => (object) array(
            'project' => 'jquery_update',
            'langcode' => 'de',
            'version' => '7.x-3.0-alpha3',
            'type' => 'local',
            'filename' => 'jquery_update-7.x-3.0-alpha3.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://jquery_update-7.x-3.0-alpha3.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'l10n_client' => array(
      'de' => (object) array(
        'name' => 'l10n_client',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.3',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'l10n_client',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'l10n_client',
            'langcode' => 'de',
            'version' => '7.x-1.3',
            'type' => 'remote',
            'filename' => 'l10n_client-7.x-1.3.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/l10n_client/l10n_client-7.x-1.3.de.po',
          ),
          'local' => (object) array(
            'project' => 'l10n_client',
            'langcode' => 'de',
            'version' => '7.x-1.3',
            'type' => 'local',
            'filename' => 'l10n_client-7.x-1.3.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://l10n_client-7.x-1.3.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'l10n_update' => array(
      'de' => (object) array(
        'name' => 'l10n_update',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.0',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'l10n_update',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1440959946,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'l10n_update',
            'langcode' => 'de',
            'version' => '7.x-2.0',
            'type' => 'remote',
            'filename' => 'l10n_update-7.x-2.0.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/l10n_update/l10n_update-7.x-2.0.de.po',
            'timestamp' => 1440959946,
          ),
          'local' => (object) array(
            'project' => 'l10n_update',
            'langcode' => 'de',
            'version' => '7.x-2.0',
            'type' => 'local',
            'filename' => 'l10n_update-7.x-2.0.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://l10n_update-7.x-2.0.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'languageicons' => array(
      'de' => (object) array(
        'name' => 'languageicons',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.1',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'languageicons',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1399919590,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'languageicons',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'remote',
            'filename' => 'languageicons-7.x-1.1.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/languageicons/languageicons-7.x-1.1.de.po',
            'timestamp' => 1399919590,
          ),
          'local' => (object) array(
            'project' => 'languageicons',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'local',
            'filename' => 'languageicons-7.x-1.1.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://languageicons-7.x-1.1.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'lang_dropdown' => array(
      'de' => (object) array(
        'name' => 'lang_dropdown',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.5',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'lang_dropdown',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'lang_dropdown',
            'langcode' => 'de',
            'version' => '7.x-2.5',
            'type' => 'remote',
            'filename' => 'lang_dropdown-7.x-2.5.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/lang_dropdown/lang_dropdown-7.x-2.5.de.po',
          ),
          'local' => (object) array(
            'project' => 'lang_dropdown',
            'langcode' => 'de',
            'version' => '7.x-2.5',
            'type' => 'local',
            'filename' => 'lang_dropdown-7.x-2.5.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://lang_dropdown-7.x-2.5.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'leaflet_widget' => array(
      'de' => (object) array(
        'name' => 'leaflet_widget',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.0-beta1',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'leaflet_widget',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1407333977,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'leaflet_widget',
            'langcode' => 'de',
            'version' => '7.x-2.0-beta1',
            'type' => 'remote',
            'filename' => 'leaflet_widget-7.x-2.0-beta1.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/leaflet_widget/leaflet_widget-7.x-2.0-beta1.de.po',
            'timestamp' => 1407333977,
          ),
          'local' => (object) array(
            'project' => 'leaflet_widget',
            'langcode' => 'de',
            'version' => '7.x-2.0-beta1',
            'type' => 'local',
            'filename' => 'leaflet_widget-7.x-2.0-beta1.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://leaflet_widget-7.x-2.0-beta1.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'legal' => array(
      'de' => (object) array(
        'name' => 'legal',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.5',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'legal',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1456735309,
        'last_checked' => 1456735309,
        'files' => array(
          'remote' => (object) array(
            'project' => 'legal',
            'langcode' => 'de',
            'version' => '7.x-1.5',
            'type' => 'remote',
            'filename' => 'legal-7.x-1.5.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/legal/legal-7.x-1.5.de.po',
            'timestamp' => 1392487848,
          ),
          'local' => (object) array(
            'project' => 'legal',
            'langcode' => 'de',
            'version' => '7.x-1.5',
            'type' => 'local',
            'filename' => 'legal-7.x-1.5.de.po',
            'uri' => 'translations://legal-7.x-1.5.de.po',
            'timestamp' => 1456735309,
            'directory' => 'translations://',
            'last_checked' => 1456735309,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'libraries' => array(
      'de' => (object) array(
        'name' => 'libraries',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.2',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'libraries',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1391968896,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'libraries',
            'langcode' => 'de',
            'version' => '7.x-2.2',
            'type' => 'remote',
            'filename' => 'libraries-7.x-2.2.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/libraries/libraries-7.x-2.2.de.po',
            'timestamp' => 1391968896,
          ),
          'local' => (object) array(
            'project' => 'libraries',
            'langcode' => 'de',
            'version' => '7.x-2.2',
            'type' => 'local',
            'filename' => 'libraries-7.x-2.2.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://libraries-7.x-2.2.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'link' => array(
      'de' => (object) array(
        'name' => 'link',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.3',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'link',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'link',
            'langcode' => 'de',
            'version' => '7.x-1.3',
            'type' => 'remote',
            'filename' => 'link-7.x-1.3.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/link/link-7.x-1.3.de.po',
          ),
          'local' => (object) array(
            'project' => 'link',
            'langcode' => 'de',
            'version' => '7.x-1.3',
            'type' => 'local',
            'filename' => 'link-7.x-1.3.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://link-7.x-1.3.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'linkit' => array(
      'de' => (object) array(
        'name' => 'linkit',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-3.4',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'linkit',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'linkit',
            'langcode' => 'de',
            'version' => '7.x-3.4',
            'type' => 'remote',
            'filename' => 'linkit-7.x-3.4.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/linkit/linkit-7.x-3.4.de.po',
          ),
          'local' => (object) array(
            'project' => 'linkit',
            'langcode' => 'de',
            'version' => '7.x-3.4',
            'type' => 'local',
            'filename' => 'linkit-7.x-3.4.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://linkit-7.x-3.4.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'machine_name' => array(
      'de' => (object) array(
        'name' => 'machine_name',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.0',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'machine_name',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1353013327,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'machine_name',
            'langcode' => 'de',
            'version' => '7.x-1.0',
            'type' => 'remote',
            'filename' => 'machine_name-7.x-1.0.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/machine_name/machine_name-7.x-1.0.de.po',
            'timestamp' => 1353013327,
          ),
          'local' => (object) array(
            'project' => 'machine_name',
            'langcode' => 'de',
            'version' => '7.x-1.0',
            'type' => 'local',
            'filename' => 'machine_name-7.x-1.0.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://machine_name-7.x-1.0.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'mail_edit' => array(
      'de' => (object) array(
        'name' => 'mail_edit',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.1',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'mail_edit',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1459354769,
        'last_checked' => 1459354768,
        'files' => array(
          'remote' => (object) array(
            'project' => 'mail_edit',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'remote',
            'filename' => 'mail_edit-7.x-1.1.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/mail_edit/mail_edit-7.x-1.1.de.po',
            'timestamp' => 1436164657,
          ),
          'local' => (object) array(
            'project' => 'mail_edit',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'local',
            'filename' => 'mail_edit-7.x-1.1.de.po',
            'uri' => 'translations://mail_edit-7.x-1.1.de.po',
            'timestamp' => 1459354769,
            'directory' => 'translations://',
            'last_checked' => 1459354768,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'markdown' => array(
      'de' => (object) array(
        'name' => 'markdown',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.2',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'markdown',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1378349326,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'markdown',
            'langcode' => 'de',
            'version' => '7.x-1.2',
            'type' => 'remote',
            'filename' => 'markdown-7.x-1.2.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/markdown/markdown-7.x-1.2.de.po',
            'timestamp' => 1378349326,
          ),
          'local' => (object) array(
            'project' => 'markdown',
            'langcode' => 'de',
            'version' => '7.x-1.2',
            'type' => 'local',
            'filename' => 'markdown-7.x-1.2.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://markdown-7.x-1.2.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'migrate' => array(
      'de' => (object) array(
        'name' => 'migrate',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.8',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'migrate',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'migrate',
            'langcode' => 'de',
            'version' => '7.x-2.8',
            'type' => 'remote',
            'filename' => 'migrate-7.x-2.8.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/migrate/migrate-7.x-2.8.de.po',
          ),
          'local' => (object) array(
            'project' => 'migrate',
            'langcode' => 'de',
            'version' => '7.x-2.8',
            'type' => 'local',
            'filename' => 'migrate-7.x-2.8.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://migrate-7.x-2.8.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'module_filter' => array(
      'de' => (object) array(
        'name' => 'module_filter',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.0',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'module_filter',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1456968847,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'module_filter',
            'langcode' => 'de',
            'version' => '7.x-2.0',
            'type' => 'remote',
            'filename' => 'module_filter-7.x-2.0.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/module_filter/module_filter-7.x-2.0.de.po',
            'timestamp' => 1456968847,
          ),
          'local' => (object) array(
            'project' => 'module_filter',
            'langcode' => 'de',
            'version' => '7.x-2.0',
            'type' => 'local',
            'filename' => 'module_filter-7.x-2.0.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://module_filter-7.x-2.0.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'oauth' => array(
      'de' => (object) array(
        'name' => 'oauth',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-3.2',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'oauth',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'oauth',
            'langcode' => 'de',
            'version' => '7.x-3.2',
            'type' => 'remote',
            'filename' => 'oauth-7.x-3.2.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/oauth/oauth-7.x-3.2.de.po',
          ),
          'local' => (object) array(
            'project' => 'oauth',
            'langcode' => 'de',
            'version' => '7.x-3.2',
            'type' => 'local',
            'filename' => 'oauth-7.x-3.2.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://oauth-7.x-3.2.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'options_element' => array(
      'de' => (object) array(
        'name' => 'options_element',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.12',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'options_element',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1434326075,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'options_element',
            'langcode' => 'de',
            'version' => '7.x-1.12',
            'type' => 'remote',
            'filename' => 'options_element-7.x-1.12.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/options_element/options_element-7.x-1.12.de.po',
            'timestamp' => 1434326075,
          ),
          'local' => (object) array(
            'project' => 'options_element',
            'langcode' => 'de',
            'version' => '7.x-1.12',
            'type' => 'local',
            'filename' => 'options_element-7.x-1.12.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://options_element-7.x-1.12.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'panels' => array(
      'de' => (object) array(
        'name' => 'panels',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-3.5',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'panels',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1454950874,
        'last_checked' => 1454950883,
        'files' => array(
          'remote' => (object) array(
            'project' => 'panels',
            'langcode' => 'de',
            'version' => '7.x-3.5',
            'type' => 'remote',
            'filename' => 'panels-7.x-3.5.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/panels/panels-7.x-3.5.de.po',
            'timestamp' => 1422769147,
          ),
          'local' => (object) array(
            'project' => 'panels',
            'langcode' => 'de',
            'version' => '7.x-3.5',
            'type' => 'local',
            'filename' => 'panels-7.x-3.5.de.po',
            'uri' => 'translations://panels-7.x-3.5.de.po',
            'timestamp' => 1454950874,
            'directory' => 'translations://',
            'last_checked' => 1454950883,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'pathauto' => array(
      'de' => (object) array(
        'name' => 'pathauto',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.3',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'pathauto',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1444459433,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'pathauto',
            'langcode' => 'de',
            'version' => '7.x-1.3',
            'type' => 'remote',
            'filename' => 'pathauto-7.x-1.3.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/pathauto/pathauto-7.x-1.3.de.po',
            'timestamp' => 1444459433,
          ),
          'local' => (object) array(
            'project' => 'pathauto',
            'langcode' => 'de',
            'version' => '7.x-1.3',
            'type' => 'local',
            'filename' => 'pathauto-7.x-1.3.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://pathauto-7.x-1.3.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'placeholder' => array(
      'de' => (object) array(
        'name' => 'placeholder',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.1',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'placeholder',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'placeholder',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'remote',
            'filename' => 'placeholder-7.x-1.1.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/placeholder/placeholder-7.x-1.1.de.po',
          ),
          'local' => (object) array(
            'project' => 'placeholder',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'local',
            'filename' => 'placeholder-7.x-1.1.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://placeholder-7.x-1.1.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'prepopulate' => array(
      'de' => (object) array(
        'name' => 'prepopulate',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.0',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'prepopulate',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'prepopulate',
            'langcode' => 'de',
            'version' => '7.x-2.0',
            'type' => 'remote',
            'filename' => 'prepopulate-7.x-2.0.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/prepopulate/prepopulate-7.x-2.0.de.po',
          ),
          'local' => (object) array(
            'project' => 'prepopulate',
            'langcode' => 'de',
            'version' => '7.x-2.0',
            'type' => 'local',
            'filename' => 'prepopulate-7.x-2.0.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://prepopulate-7.x-2.0.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'profiler_builder' => array(
      'de' => (object) array(
        'name' => 'profiler_builder',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.2',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'profiler_builder',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1458748533,
        'last_checked' => 1458748533,
        'files' => array(
          'remote' => (object) array(
            'project' => 'profiler_builder',
            'langcode' => 'de',
            'version' => '7.x-1.2',
            'type' => 'remote',
            'filename' => 'profiler_builder-7.x-1.2.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/profiler_builder/profiler_builder-7.x-1.2.de.po',
            'timestamp' => 1409129560,
          ),
          'local' => (object) array(
            'project' => 'profiler_builder',
            'langcode' => 'de',
            'version' => '7.x-1.2',
            'type' => 'local',
            'filename' => 'profiler_builder-7.x-1.2.de.po',
            'uri' => 'translations://profiler_builder-7.x-1.2.de.po',
            'timestamp' => 1458748533,
            'directory' => 'translations://',
            'last_checked' => 1458748533,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'r4032login' => array(
      'de' => (object) array(
        'name' => 'r4032login',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.8',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'r4032login',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1408004967,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'r4032login',
            'langcode' => 'de',
            'version' => '7.x-1.8',
            'type' => 'remote',
            'filename' => 'r4032login-7.x-1.8.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/r4032login/r4032login-7.x-1.8.de.po',
            'timestamp' => 1408004967,
          ),
          'local' => (object) array(
            'project' => 'r4032login',
            'langcode' => 'de',
            'version' => '7.x-1.8',
            'type' => 'local',
            'filename' => 'r4032login-7.x-1.8.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://r4032login-7.x-1.8.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'recaptcha' => array(
      'de' => (object) array(
        'name' => 'recaptcha',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.0',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'recaptcha',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1456149124,
        'last_checked' => 1456149123,
        'files' => array(
          'remote' => (object) array(
            'project' => 'recaptcha',
            'langcode' => 'de',
            'version' => '7.x-2.0',
            'type' => 'remote',
            'filename' => 'recaptcha-7.x-2.0.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/recaptcha/recaptcha-7.x-2.0.de.po',
            'timestamp' => 1440167499,
          ),
          'local' => (object) array(
            'project' => 'recaptcha',
            'langcode' => 'de',
            'version' => '7.x-2.0',
            'type' => 'local',
            'filename' => 'recaptcha-7.x-2.0.de.po',
            'uri' => 'translations://recaptcha-7.x-2.0.de.po',
            'timestamp' => 1456149124,
            'directory' => 'translations://',
            'last_checked' => 1456149123,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
        'filename' => '',
        'fileurl' => '',
        'uri' => '',
      ),
    ),
    'removeaddnewcommentteaserlink' => array(
      'de' => (object) array(
        'name' => 'removeaddnewcommentteaserlink',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.1',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'removeaddnewcommentteaserlink',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'removeaddnewcommentteaserlink',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'remote',
            'filename' => 'removeaddnewcommentteaserlink-7.x-1.1.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/removeaddnewcommentteaserlink/removeaddnewcommentteaserlink-7.x-1.1.de.po',
          ),
          'local' => (object) array(
            'project' => 'removeaddnewcommentteaserlink',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'local',
            'filename' => 'removeaddnewcommentteaserlink-7.x-1.1.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://removeaddnewcommentteaserlink-7.x-1.1.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'revisioning' => array(
      'de' => (object) array(
        'name' => 'revisioning',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.9',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'revisioning',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'revisioning',
            'langcode' => 'de',
            'version' => '7.x-1.9',
            'type' => 'remote',
            'filename' => 'revisioning-7.x-1.9.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/revisioning/revisioning-7.x-1.9.de.po',
          ),
          'local' => (object) array(
            'project' => 'revisioning',
            'langcode' => 'de',
            'version' => '7.x-1.9',
            'type' => 'local',
            'filename' => 'revisioning-7.x-1.9.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://revisioning-7.x-1.9.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'rules' => array(
      'de' => (object) array(
        'name' => 'rules',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.9',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'rules',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1459418763,
        'last_checked' => 1459418764,
        'files' => array(
          'remote' => (object) array(
            'project' => 'rules',
            'langcode' => 'de',
            'version' => '7.x-2.9',
            'type' => 'remote',
            'filename' => 'rules-7.x-2.9.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/rules/rules-7.x-2.9.de.po',
            'timestamp' => 1427444828,
          ),
          'local' => (object) array(
            'project' => 'rules',
            'langcode' => 'de',
            'version' => '7.x-2.9',
            'type' => 'local',
            'filename' => 'rules-7.x-2.9.de.po',
            'uri' => 'translations://rules-7.x-2.9.de.po',
            'timestamp' => 1459418763,
            'directory' => 'translations://',
            'last_checked' => 1459418764,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'search_api' => array(
      'de' => (object) array(
        'name' => 'search_api',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.16',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'search_api',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306204,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'search_api',
            'langcode' => 'de',
            'version' => '7.x-1.16',
            'type' => 'remote',
            'filename' => 'search_api-7.x-1.16.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/search_api/search_api-7.x-1.16.de.po',
            'timestamp' => 1454189647,
          ),
          'local' => (object) array(
            'project' => 'search_api',
            'langcode' => 'de',
            'version' => '7.x-1.16',
            'type' => 'local',
            'filename' => 'search_api-7.x-1.16.de.po',
            'uri' => 'translations://search_api-7.x-1.16.de.po',
            'timestamp' => 1465306204,
            'directory' => 'translations://',
            'last_checked' => 1465306183,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'search_api_db' => array(
      'de' => (object) array(
        'name' => 'search_api_db',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.5',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'search_api_db',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1441350812,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'search_api_db',
            'langcode' => 'de',
            'version' => '7.x-1.5',
            'type' => 'remote',
            'filename' => 'search_api_db-7.x-1.5.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/search_api_db/search_api_db-7.x-1.5.de.po',
            'timestamp' => 1441350812,
          ),
          'local' => (object) array(
            'project' => 'search_api_db',
            'langcode' => 'de',
            'version' => '7.x-1.5',
            'type' => 'local',
            'filename' => 'search_api_db-7.x-1.5.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://search_api_db-7.x-1.5.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'search_api_solr' => array(
      'de' => (object) array(
        'name' => 'search_api_solr',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.9',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'search_api_solr',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1456135410,
        'last_checked' => 1456135409,
        'files' => array(
          'remote' => (object) array(
            'project' => 'search_api_solr',
            'langcode' => 'de',
            'version' => '7.x-1.9',
            'type' => 'remote',
            'filename' => 'search_api_solr-7.x-1.9.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/search_api_solr/search_api_solr-7.x-1.9.de.po',
            'timestamp' => 1441177043,
          ),
          'local' => (object) array(
            'project' => 'search_api_solr',
            'langcode' => 'de',
            'version' => '7.x-1.9',
            'type' => 'local',
            'filename' => 'search_api_solr-7.x-1.9.de.po',
            'uri' => 'translations://search_api_solr-7.x-1.9.de.po',
            'timestamp' => 1456135410,
            'directory' => 'translations://',
            'last_checked' => 1456135409,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'search_autocomplete' => array(
      'de' => (object) array(
        'name' => 'search_autocomplete',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-4.7',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'search_autocomplete',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1444027198,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'search_autocomplete',
            'langcode' => 'de',
            'version' => '7.x-4.7',
            'type' => 'remote',
            'filename' => 'search_autocomplete-7.x-4.7.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/search_autocomplete/search_autocomplete-7.x-4.7.de.po',
            'timestamp' => 1444027198,
          ),
          'local' => (object) array(
            'project' => 'search_autocomplete',
            'langcode' => 'de',
            'version' => '7.x-4.7',
            'type' => 'local',
            'filename' => 'search_autocomplete-7.x-4.7.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://search_autocomplete-7.x-4.7.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'security_review' => array(
      'de' => (object) array(
        'name' => 'security_review',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.2',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'security_review',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'security_review',
            'langcode' => 'de',
            'version' => '7.x-1.2',
            'type' => 'remote',
            'filename' => 'security_review-7.x-1.2.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/security_review/security_review-7.x-1.2.de.po',
          ),
          'local' => (object) array(
            'project' => 'security_review',
            'langcode' => 'de',
            'version' => '7.x-1.2',
            'type' => 'local',
            'filename' => 'security_review-7.x-1.2.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://security_review-7.x-1.2.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'services' => array(
      'de' => (object) array(
        'name' => 'services',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-3.12',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'services',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1429357877,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'services',
            'langcode' => 'de',
            'version' => '7.x-3.12',
            'type' => 'remote',
            'filename' => 'services-7.x-3.12.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/services/services-7.x-3.12.de.po',
            'timestamp' => 1429357877,
          ),
          'local' => (object) array(
            'project' => 'services',
            'langcode' => 'de',
            'version' => '7.x-3.12',
            'type' => 'local',
            'filename' => 'services-7.x-3.12.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://services-7.x-3.12.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'short_scale_formatter' => array(
      'de' => (object) array(
        'name' => 'short_scale_formatter',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.1',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'short_scale_formatter',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'short_scale_formatter',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'remote',
            'filename' => 'short_scale_formatter-7.x-1.1.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/short_scale_formatter/short_scale_formatter-7.x-1.1.de.po',
          ),
          'local' => (object) array(
            'project' => 'short_scale_formatter',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'local',
            'filename' => 'short_scale_formatter-7.x-1.1.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://short_scale_formatter-7.x-1.1.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'smart_trim' => array(
      'de' => (object) array(
        'name' => 'smart_trim',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.5',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'smart_trim',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1430548519,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'smart_trim',
            'langcode' => 'de',
            'version' => '7.x-1.5',
            'type' => 'remote',
            'filename' => 'smart_trim-7.x-1.5.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/smart_trim/smart_trim-7.x-1.5.de.po',
            'timestamp' => 1430548519,
          ),
          'local' => (object) array(
            'project' => 'smart_trim',
            'langcode' => 'de',
            'version' => '7.x-1.5',
            'type' => 'local',
            'filename' => 'smart_trim-7.x-1.5.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://smart_trim-7.x-1.5.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'smtp' => array(
      'de' => (object) array(
        'name' => 'smtp',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.2',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'smtp',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1448881648,
        'last_checked' => 1448881647,
        'files' => array(
          'remote' => (object) array(
            'project' => 'smtp',
            'langcode' => 'de',
            'version' => '7.x-1.2',
            'type' => 'remote',
            'filename' => 'smtp-7.x-1.2.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/smtp/smtp-7.x-1.2.de.po',
            'timestamp' => 1446999272,
          ),
          'local' => (object) array(
            'project' => 'smtp',
            'langcode' => 'de',
            'version' => '7.x-1.2',
            'type' => 'local',
            'filename' => 'smtp-7.x-1.2.de.po',
            'uri' => 'translations://smtp-7.x-1.2.de.po',
            'timestamp' => 1448881648,
            'directory' => 'translations://',
            'last_checked' => 1448881647,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'stickynav' => array(
      'de' => (object) array(
        'name' => 'stickynav',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.0',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'stickynav',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1455888445,
        'last_checked' => 1455888445,
        'files' => array(
          'remote' => (object) array(
            'project' => 'stickynav',
            'langcode' => 'de',
            'version' => '7.x-1.0',
            'type' => 'remote',
            'filename' => 'stickynav-7.x-1.0.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/stickynav/stickynav-7.x-1.0.de.po',
            'timestamp' => 1413713035,
          ),
          'local' => (object) array(
            'project' => 'stickynav',
            'langcode' => 'de',
            'version' => '7.x-1.0',
            'type' => 'local',
            'filename' => 'stickynav-7.x-1.0.de.po',
            'uri' => 'translations://stickynav-7.x-1.0.de.po',
            'timestamp' => 1455888445,
            'directory' => 'translations://',
            'last_checked' => 1455888445,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'strongarm' => array(
      'de' => (object) array(
        'name' => 'strongarm',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.0',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'strongarm',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'strongarm',
            'langcode' => 'de',
            'version' => '7.x-2.0',
            'type' => 'remote',
            'filename' => 'strongarm-7.x-2.0.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/strongarm/strongarm-7.x-2.0.de.po',
          ),
          'local' => (object) array(
            'project' => 'strongarm',
            'langcode' => 'de',
            'version' => '7.x-2.0',
            'type' => 'local',
            'filename' => 'strongarm-7.x-2.0.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://strongarm-7.x-2.0.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'subscriptions' => array(
      'de' => (object) array(
        'name' => 'subscriptions',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.1',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'subscriptions',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1459354769,
        'last_checked' => 1459354774,
        'files' => array(
          'remote' => (object) array(
            'project' => 'subscriptions',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'remote',
            'filename' => 'subscriptions-7.x-1.1.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/subscriptions/subscriptions-7.x-1.1.de.po',
            'timestamp' => 1428670291,
          ),
          'local' => (object) array(
            'project' => 'subscriptions',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'local',
            'filename' => 'subscriptions-7.x-1.1.de.po',
            'uri' => 'translations://subscriptions-7.x-1.1.de.po',
            'timestamp' => 1459354769,
            'directory' => 'translations://',
            'last_checked' => 1459354774,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
        'filename' => '',
        'fileurl' => '',
        'uri' => '',
      ),
    ),
    'superfish' => array(
      'de' => (object) array(
        'name' => 'superfish',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.9',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'superfish',
        'langcode' => 'de',
        'type' => 'remote',
        'timestamp' => 1367055053,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'superfish',
            'langcode' => 'de',
            'version' => '7.x-1.9',
            'type' => 'remote',
            'filename' => 'superfish-7.x-1.9.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/superfish/superfish-7.x-1.9.de.po',
            'timestamp' => 1367055053,
          ),
          'local' => (object) array(
            'project' => 'superfish',
            'langcode' => 'de',
            'version' => '7.x-1.9',
            'type' => 'local',
            'filename' => 'superfish-7.x-1.9.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://superfish-7.x-1.9.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'tagclouds' => array(
      'de' => (object) array(
        'name' => 'tagclouds',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.10',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'tagclouds',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'tagclouds',
            'langcode' => 'de',
            'version' => '7.x-1.10',
            'type' => 'remote',
            'filename' => 'tagclouds-7.x-1.10.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/tagclouds/tagclouds-7.x-1.10.de.po',
          ),
          'local' => (object) array(
            'project' => 'tagclouds',
            'langcode' => 'de',
            'version' => '7.x-1.10',
            'type' => 'local',
            'filename' => 'tagclouds-7.x-1.10.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://tagclouds-7.x-1.10.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'taxonomy_access_fix' => array(
      'de' => (object) array(
        'name' => 'taxonomy_access_fix',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.3',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'taxonomy_access_fix',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1457090449,
        'last_checked' => 1457090449,
        'files' => array(
          'remote' => (object) array(
            'project' => 'taxonomy_access_fix',
            'langcode' => 'de',
            'version' => '7.x-2.3',
            'type' => 'remote',
            'filename' => 'taxonomy_access_fix-7.x-2.3.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/taxonomy_access_fix/taxonomy_access_fix-7.x-2.3.de.po',
            'timestamp' => 1447311174,
          ),
          'local' => (object) array(
            'project' => 'taxonomy_access_fix',
            'langcode' => 'de',
            'version' => '7.x-2.3',
            'type' => 'local',
            'filename' => 'taxonomy_access_fix-7.x-2.3.de.po',
            'uri' => 'translations://taxonomy_access_fix-7.x-2.3.de.po',
            'timestamp' => 1457090449,
            'directory' => 'translations://',
            'last_checked' => 1457090449,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'taxonomy_autocomplete_permission' => array(
      'de' => (object) array(
        'name' => 'taxonomy_autocomplete_permission',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.0',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'taxonomy_autocomplete_permission',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'taxonomy_autocomplete_permission',
            'langcode' => 'de',
            'version' => '7.x-1.0',
            'type' => 'remote',
            'filename' => 'taxonomy_autocomplete_permission-7.x-1.0.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/taxonomy_autocomplete_permission/taxonomy_autocomplete_permission-7.x-1.0.de.po',
          ),
          'local' => (object) array(
            'project' => 'taxonomy_autocomplete_permission',
            'langcode' => 'de',
            'version' => '7.x-1.0',
            'type' => 'local',
            'filename' => 'taxonomy_autocomplete_permission-7.x-1.0.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://taxonomy_autocomplete_permission-7.x-1.0.de.po',
          ),
        ),
        'language' => 'de',
        'filename' => '',
        'fileurl' => '',
        'uri' => '',
      ),
    ),
    'taxonomy_display' => array(
      'de' => (object) array(
        'name' => 'taxonomy_display',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.1',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'taxonomy_display',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'taxonomy_display',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'remote',
            'filename' => 'taxonomy_display-7.x-1.1.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/taxonomy_display/taxonomy_display-7.x-1.1.de.po',
          ),
          'local' => (object) array(
            'project' => 'taxonomy_display',
            'langcode' => 'de',
            'version' => '7.x-1.1',
            'type' => 'local',
            'filename' => 'taxonomy_display-7.x-1.1.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://taxonomy_display-7.x-1.1.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'taxonomy_manager' => array(
      'de' => (object) array(
        'name' => 'taxonomy_manager',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.0',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'taxonomy_manager',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306213,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'taxonomy_manager',
            'langcode' => 'de',
            'version' => '7.x-1.0',
            'type' => 'remote',
            'filename' => 'taxonomy_manager-7.x-1.0.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/taxonomy_manager/taxonomy_manager-7.x-1.0.de.po',
            'timestamp' => 1369043468,
          ),
          'local' => (object) array(
            'project' => 'taxonomy_manager',
            'langcode' => 'de',
            'version' => '7.x-1.0',
            'type' => 'local',
            'filename' => 'taxonomy_manager-7.x-1.0.de.po',
            'uri' => 'translations://taxonomy_manager-7.x-1.0.de.po',
            'timestamp' => 1465306213,
            'directory' => 'translations://',
            'last_checked' => 1465306183,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'term_merge' => array(
      'de' => (object) array(
        'name' => 'term_merge',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.2',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'term_merge',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306216,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'term_merge',
            'langcode' => 'de',
            'version' => '7.x-1.2',
            'type' => 'remote',
            'filename' => 'term_merge-7.x-1.2.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/term_merge/term_merge-7.x-1.2.de.po',
            'timestamp' => 1421665676,
          ),
          'local' => (object) array(
            'project' => 'term_merge',
            'langcode' => 'de',
            'version' => '7.x-1.2',
            'type' => 'local',
            'filename' => 'term_merge-7.x-1.2.de.po',
            'uri' => 'translations://term_merge-7.x-1.2.de.po',
            'timestamp' => 1465306216,
            'directory' => 'translations://',
            'last_checked' => 1465306183,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'term_search' => array(
      'de' => (object) array(
        'name' => 'term_search',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.0',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'term_search',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306216,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'term_search',
            'langcode' => 'de',
            'version' => '7.x-1.0',
            'type' => 'remote',
            'filename' => 'term_search-7.x-1.0.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/term_search/term_search-7.x-1.0.de.po',
            'timestamp' => 1407343846,
          ),
          'local' => (object) array(
            'project' => 'term_search',
            'langcode' => 'de',
            'version' => '7.x-1.0',
            'type' => 'local',
            'filename' => 'term_search-7.x-1.0.de.po',
            'uri' => 'translations://term_search-7.x-1.0.de.po',
            'timestamp' => 1465306216,
            'directory' => 'translations://',
            'last_checked' => 1465306183,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'textformatter' => array(
      'de' => (object) array(
        'name' => 'textformatter',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.3',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'textformatter',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306217,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'textformatter',
            'langcode' => 'de',
            'version' => '7.x-1.3',
            'type' => 'remote',
            'filename' => 'textformatter-7.x-1.3.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/textformatter/textformatter-7.x-1.3.de.po',
            'timestamp' => 1361606562,
          ),
          'local' => (object) array(
            'project' => 'textformatter',
            'langcode' => 'de',
            'version' => '7.x-1.3',
            'type' => 'local',
            'filename' => 'textformatter-7.x-1.3.de.po',
            'uri' => 'translations://textformatter-7.x-1.3.de.po',
            'timestamp' => 1465306217,
            'directory' => 'translations://',
            'last_checked' => 1465306183,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'title' => array(
      'de' => (object) array(
        'name' => 'title',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.0-alpha7',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'title',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306217,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'title',
            'langcode' => 'de',
            'version' => '7.x-1.0-alpha7',
            'type' => 'remote',
            'filename' => 'title-7.x-1.0-alpha7.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/title/title-7.x-1.0-alpha7.de.po',
            'timestamp' => 1363626840,
          ),
          'local' => (object) array(
            'project' => 'title',
            'langcode' => 'de',
            'version' => '7.x-1.0-alpha7',
            'type' => 'local',
            'filename' => 'title-7.x-1.0-alpha7.de.po',
            'uri' => 'translations://title-7.x-1.0-alpha7.de.po',
            'timestamp' => 1465306217,
            'directory' => 'translations://',
            'last_checked' => 1465306183,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'tmgmt' => array(
      'de' => (object) array(
        'name' => 'tmgmt',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.0-rc1',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'tmgmt',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465911716,
        'last_checked' => 1465911715,
        'files' => array(
          'remote' => (object) array(
            'project' => 'tmgmt',
            'langcode' => 'de',
            'version' => '7.x-1.0-rc1',
            'type' => 'remote',
            'filename' => 'tmgmt-7.x-1.0-rc1.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/tmgmt/tmgmt-7.x-1.0-rc1.de.po',
            'timestamp' => 1394004458,
          ),
          'local' => (object) array(
            'project' => 'tmgmt',
            'langcode' => 'de',
            'version' => '7.x-1.0-rc1',
            'type' => 'local',
            'filename' => 'tmgmt-7.x-1.0-rc1.de.po',
            'uri' => 'translations://tmgmt-7.x-1.0-rc1.de.po',
            'timestamp' => 1465911716,
            'directory' => 'translations://',
            'last_checked' => 1465911715,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'token' => array(
      'de' => (object) array(
        'name' => 'token',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.6',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'token',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306218,
        'last_checked' => 1465306183,
        'files' => array(
          'remote' => (object) array(
            'project' => 'token',
            'langcode' => 'de',
            'version' => '7.x-1.6',
            'type' => 'remote',
            'filename' => 'token-7.x-1.6.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/token/token-7.x-1.6.de.po',
            'timestamp' => 1425362389,
          ),
          'local' => (object) array(
            'project' => 'token',
            'langcode' => 'de',
            'version' => '7.x-1.6',
            'type' => 'local',
            'filename' => 'token-7.x-1.6.de.po',
            'uri' => 'translations://token-7.x-1.6.de.po',
            'timestamp' => 1465306218,
            'directory' => 'translations://',
            'last_checked' => 1465306183,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'translation_helpers' => array(
      'de' => (object) array(
        'name' => 'translation_helpers',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.0',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'translation_helpers',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306263,
        'last_checked' => 1465306262,
        'files' => array(
          'remote' => (object) array(
            'project' => 'translation_helpers',
            'langcode' => 'de',
            'version' => '7.x-1.0',
            'type' => 'remote',
            'filename' => 'translation_helpers-7.x-1.0.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/translation_helpers/translation_helpers-7.x-1.0.de.po',
            'timestamp' => 1322755829,
          ),
          'local' => (object) array(
            'project' => 'translation_helpers',
            'langcode' => 'de',
            'version' => '7.x-1.0',
            'type' => 'local',
            'filename' => 'translation_helpers-7.x-1.0.de.po',
            'uri' => 'translations://translation_helpers-7.x-1.0.de.po',
            'timestamp' => 1465306263,
            'directory' => 'translations://',
            'last_checked' => 1465306262,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'translation_overview' => array(
      'de' => (object) array(
        'name' => 'translation_overview',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.0-beta1',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'translation_overview',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306264,
        'last_checked' => 1465306262,
        'files' => array(
          'remote' => (object) array(
            'project' => 'translation_overview',
            'langcode' => 'de',
            'version' => '7.x-2.0-beta1',
            'type' => 'remote',
            'filename' => 'translation_overview-7.x-2.0-beta1.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/translation_overview/translation_overview-7.x-2.0-beta1.de.po',
            'timestamp' => 1371095888,
          ),
          'local' => (object) array(
            'project' => 'translation_overview',
            'langcode' => 'de',
            'version' => '7.x-2.0-beta1',
            'type' => 'local',
            'filename' => 'translation_overview-7.x-2.0-beta1.de.po',
            'uri' => 'translations://translation_overview-7.x-2.0-beta1.de.po',
            'timestamp' => 1465306264,
            'directory' => 'translations://',
            'last_checked' => 1465306262,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'translation_table' => array(
      'de' => (object) array(
        'name' => 'translation_table',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.0-beta1',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'translation_table',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306265,
        'last_checked' => 1465306262,
        'files' => array(
          'remote' => (object) array(
            'project' => 'translation_table',
            'langcode' => 'de',
            'version' => '7.x-1.0-beta1',
            'type' => 'remote',
            'filename' => 'translation_table-7.x-1.0-beta1.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/translation_table/translation_table-7.x-1.0-beta1.de.po',
            'timestamp' => 1333636911,
          ),
          'local' => (object) array(
            'project' => 'translation_table',
            'langcode' => 'de',
            'version' => '7.x-1.0-beta1',
            'type' => 'local',
            'filename' => 'translation_table-7.x-1.0-beta1.de.po',
            'uri' => 'translations://translation_table-7.x-1.0-beta1.de.po',
            'timestamp' => 1465306265,
            'directory' => 'translations://',
            'last_checked' => 1465306262,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'transliteration' => array(
      'de' => (object) array(
        'name' => 'transliteration',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-3.2',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'transliteration',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306266,
        'last_checked' => 1465306262,
        'files' => array(
          'remote' => (object) array(
            'project' => 'transliteration',
            'langcode' => 'de',
            'version' => '7.x-3.2',
            'type' => 'remote',
            'filename' => 'transliteration-7.x-3.2.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/transliteration/transliteration-7.x-3.2.de.po',
            'timestamp' => 1448904844,
          ),
          'local' => (object) array(
            'project' => 'transliteration',
            'langcode' => 'de',
            'version' => '7.x-3.2',
            'type' => 'local',
            'filename' => 'transliteration-7.x-3.2.de.po',
            'uri' => 'translations://transliteration-7.x-3.2.de.po',
            'timestamp' => 1465306266,
            'directory' => 'translations://',
            'last_checked' => 1465306262,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'twitter_block' => array(
      'de' => (object) array(
        'name' => 'twitter_block',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.3',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'twitter_block',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1455790890,
        'last_checked' => 1455790890,
        'files' => array(
          'remote' => (object) array(
            'project' => 'twitter_block',
            'langcode' => 'de',
            'version' => '7.x-2.3',
            'type' => 'remote',
            'filename' => 'twitter_block-7.x-2.3.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/twitter_block/twitter_block-7.x-2.3.de.po',
            'timestamp' => 1442559100,
          ),
          'local' => (object) array(
            'project' => 'twitter_block',
            'langcode' => 'de',
            'version' => '7.x-2.3',
            'type' => 'local',
            'filename' => 'twitter_block-7.x-2.3.de.po',
            'uri' => 'translations://twitter_block-7.x-2.3.de.po',
            'timestamp' => 1455790890,
            'directory' => 'translations://',
            'last_checked' => 1455790890,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'variable' => array(
      'de' => (object) array(
        'name' => 'variable',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.5',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'variable',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306267,
        'last_checked' => 1465306262,
        'files' => array(
          'remote' => (object) array(
            'project' => 'variable',
            'langcode' => 'de',
            'version' => '7.x-2.5',
            'type' => 'remote',
            'filename' => 'variable-7.x-2.5.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/variable/variable-7.x-2.5.de.po',
            'timestamp' => 1454279975,
          ),
          'local' => (object) array(
            'project' => 'variable',
            'langcode' => 'de',
            'version' => '7.x-2.5',
            'type' => 'local',
            'filename' => 'variable-7.x-2.5.de.po',
            'uri' => 'translations://variable-7.x-2.5.de.po',
            'timestamp' => 1465306267,
            'directory' => 'translations://',
            'last_checked' => 1465306262,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'viewfield' => array(
      'de' => (object) array(
        'name' => 'viewfield',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.0',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'viewfield',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306270,
        'last_checked' => 1465306262,
        'files' => array(
          'remote' => (object) array(
            'project' => 'viewfield',
            'langcode' => 'de',
            'version' => '7.x-2.0',
            'type' => 'remote',
            'filename' => 'viewfield-7.x-2.0.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/viewfield/viewfield-7.x-2.0.de.po',
            'timestamp' => 1362292456,
          ),
          'local' => (object) array(
            'project' => 'viewfield',
            'langcode' => 'de',
            'version' => '7.x-2.0',
            'type' => 'local',
            'filename' => 'viewfield-7.x-2.0.de.po',
            'uri' => 'translations://viewfield-7.x-2.0.de.po',
            'timestamp' => 1465306270,
            'directory' => 'translations://',
            'last_checked' => 1465306262,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'views' => array(
      'de' => (object) array(
        'name' => 'views',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-3.13',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'views',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306271,
        'last_checked' => 1465306329,
        'files' => array(
          'remote' => (object) array(
            'project' => 'views',
            'langcode' => 'de',
            'version' => '7.x-3.13',
            'type' => 'remote',
            'filename' => 'views-7.x-3.13.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/views/views-7.x-3.13.de.po',
            'timestamp' => 1459879142,
          ),
          'local' => (object) array(
            'project' => 'views',
            'langcode' => 'de',
            'version' => '7.x-3.13',
            'type' => 'local',
            'filename' => 'views-7.x-3.13.de.po',
            'uri' => 'translations://views-7.x-3.13.de.po',
            'timestamp' => 1465306271,
            'directory' => 'translations://',
            'last_checked' => 1465306329,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'views_bulk_operations' => array(
      'de' => (object) array(
        'name' => 'views_bulk_operations',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-3.3',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'views_bulk_operations',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306275,
        'last_checked' => 1465306262,
        'files' => array(
          'remote' => (object) array(
            'project' => 'views_bulk_operations',
            'langcode' => 'de',
            'version' => '7.x-3.3',
            'type' => 'remote',
            'filename' => 'views_bulk_operations-7.x-3.3.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/views_bulk_operations/views_bulk_operations-7.x-3.3.de.po',
            'timestamp' => 1435819290,
          ),
          'local' => (object) array(
            'project' => 'views_bulk_operations',
            'langcode' => 'de',
            'version' => '7.x-3.3',
            'type' => 'local',
            'filename' => 'views_bulk_operations-7.x-3.3.de.po',
            'uri' => 'translations://views_bulk_operations-7.x-3.3.de.po',
            'timestamp' => 1465306275,
            'directory' => 'translations://',
            'last_checked' => 1465306262,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'views_datasource' => array(
      'de' => (object) array(
        'name' => 'views_datasource',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.0-alpha2',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'views_datasource',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306277,
        'last_checked' => 1465306262,
        'files' => array(
          'remote' => (object) array(
            'project' => 'views_datasource',
            'langcode' => 'de',
            'version' => '7.x-1.0-alpha2',
            'type' => 'remote',
            'filename' => 'views_datasource-7.x-1.0-alpha2.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/views_datasource/views_datasource-7.x-1.0-alpha2.de.po',
            'timestamp' => 1424075062,
          ),
          'local' => (object) array(
            'project' => 'views_datasource',
            'langcode' => 'de',
            'version' => '7.x-1.0-alpha2',
            'type' => 'local',
            'filename' => 'views_datasource-7.x-1.0-alpha2.de.po',
            'uri' => 'translations://views_datasource-7.x-1.0-alpha2.de.po',
            'timestamp' => 1465306277,
            'directory' => 'translations://',
            'last_checked' => 1465306262,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
        'filename' => '',
        'fileurl' => '',
        'uri' => '',
      ),
    ),
    'views_ef_fieldset' => array(
      'de' => (object) array(
        'name' => 'views_ef_fieldset',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.6',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'views_ef_fieldset',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306277,
        'last_checked' => 1465306262,
        'files' => array(
          'remote' => (object) array(
            'project' => 'views_ef_fieldset',
            'langcode' => 'de',
            'version' => '7.x-1.6',
            'type' => 'remote',
            'filename' => 'views_ef_fieldset-7.x-1.6.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/views_ef_fieldset/views_ef_fieldset-7.x-1.6.de.po',
            'timestamp' => 1432276699,
          ),
          'local' => (object) array(
            'project' => 'views_ef_fieldset',
            'langcode' => 'de',
            'version' => '7.x-1.6',
            'type' => 'local',
            'filename' => 'views_ef_fieldset-7.x-1.6.de.po',
            'uri' => 'translations://views_ef_fieldset-7.x-1.6.de.po',
            'timestamp' => 1465306277,
            'directory' => 'translations://',
            'last_checked' => 1465306262,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'views_load_more' => array(
      'de' => (object) array(
        'name' => 'views_load_more',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.5',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'views_load_more',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306278,
        'last_checked' => 1465306262,
        'files' => array(
          'remote' => (object) array(
            'project' => 'views_load_more',
            'langcode' => 'de',
            'version' => '7.x-1.5',
            'type' => 'remote',
            'filename' => 'views_load_more-7.x-1.5.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/views_load_more/views_load_more-7.x-1.5.de.po',
            'timestamp' => 1412849160,
          ),
          'local' => (object) array(
            'project' => 'views_load_more',
            'langcode' => 'de',
            'version' => '7.x-1.5',
            'type' => 'local',
            'filename' => 'views_load_more-7.x-1.5.de.po',
            'uri' => 'translations://views_load_more-7.x-1.5.de.po',
            'timestamp' => 1465306278,
            'directory' => 'translations://',
            'last_checked' => 1465306262,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'wysiwyg' => array(
      'de' => (object) array(
        'name' => 'wysiwyg',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-2.2',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'wysiwyg',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306278,
        'last_checked' => 1465306262,
        'files' => array(
          'remote' => (object) array(
            'project' => 'wysiwyg',
            'langcode' => 'de',
            'version' => '7.x-2.2',
            'type' => 'remote',
            'filename' => 'wysiwyg-7.x-2.2.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/wysiwyg/wysiwyg-7.x-2.2.de.po',
            'timestamp' => 1443793457,
          ),
          'local' => (object) array(
            'project' => 'wysiwyg',
            'langcode' => 'de',
            'version' => '7.x-2.2',
            'type' => 'local',
            'filename' => 'wysiwyg-7.x-2.2.de.po',
            'uri' => 'translations://wysiwyg-7.x-2.2.de.po',
            'timestamp' => 1465306278,
            'directory' => 'translations://',
            'last_checked' => 1465306262,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'wysiwyg_filter' => array(
      'de' => (object) array(
        'name' => 'wysiwyg_filter',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-1.6-rc2',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'wysiwyg_filter',
        'langcode' => 'de',
        'type' => 'current',
        'timestamp' => 1465306282,
        'last_checked' => 1465306262,
        'files' => array(
          'remote' => (object) array(
            'project' => 'wysiwyg_filter',
            'langcode' => 'de',
            'version' => '7.x-1.6-rc2',
            'type' => 'remote',
            'filename' => 'wysiwyg_filter-7.x-1.6-rc2.de.po',
            'uri' => 'https://ftp.drupal.org/files/translations/7.x/wysiwyg_filter/wysiwyg_filter-7.x-1.6-rc2.de.po',
            'timestamp' => 1330509648,
          ),
          'local' => (object) array(
            'project' => 'wysiwyg_filter',
            'langcode' => 'de',
            'version' => '7.x-1.6-rc2',
            'type' => 'local',
            'filename' => 'wysiwyg_filter-7.x-1.6-rc2.de.po',
            'uri' => 'translations://wysiwyg_filter-7.x-1.6-rc2.de.po',
            'timestamp' => 1465306282,
            'directory' => 'translations://',
            'last_checked' => 1465306262,
            'language' => 'de',
          ),
        ),
        'language' => 'de',
      ),
    ),
    'xautoload' => array(
      'de' => (object) array(
        'name' => 'xautoload',
        'project_type' => 'module',
        'core' => '7.x',
        'version' => '7.x-5.5',
        'server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
        'status' => '1',
        'project' => 'xautoload',
        'langcode' => 'de',
        'type' => '',
        'timestamp' => 0,
        'last_checked' => 0,
        'files' => array(
          'remote' => (object) array(
            'project' => 'xautoload',
            'langcode' => 'de',
            'version' => '7.x-5.5',
            'type' => 'remote',
            'filename' => 'xautoload-7.x-5.5.de.po',
            'uri' => 'http://ftp.drupal.org/files/translations/7.x/xautoload/xautoload-7.x-5.5.de.po',
          ),
          'local' => (object) array(
            'project' => 'xautoload',
            'langcode' => 'de',
            'version' => '7.x-5.5',
            'type' => 'local',
            'filename' => 'xautoload-7.x-5.5.de.po',
            'directory' => 'translations://',
            'uri' => 'translations://xautoload-7.x-5.5.de.po',
          ),
        ),
        'language' => 'de',
      ),
    ),
  );
  $export['l10n_update_translation_status'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_data_set';
  $strongarm->value = 0;
  $export['language_content_type_data_set'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_faq';
  $strongarm->value = '4';
  $export['language_content_type_faq'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_forum';
  $strongarm->value = 0;
  $export['language_content_type_forum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_person';
  $strongarm->value = 0;
  $export['language_content_type_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_portal';
  $strongarm->value = '4';
  $export['language_content_type_portal'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_count';
  $strongarm->value = 2;
  $export['language_count'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_default';
  $strongarm->value = (object) array(
    'language' => 'en',
    'name' => 'English',
    'native' => 'English',
    'direction' => '0',
    'enabled' => 1,
    'plurals' => '0',
    'formula' => '',
    'domain' => '',
    'prefix' => 'en',
    'weight' => '0',
    'javascript' => '',
  );
  $export['language_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_negotiation_language';
  $strongarm->value = array(
    'locale-url' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_url',
        'switcher' => 'locale_language_switcher_url',
        'url_rewrite' => 'locale_language_url_rewrite_url',
      ),
      'file' => 'includes/locale.inc',
    ),
    'language-default' => array(
      'callbacks' => array(
        'language' => 'language_from_default',
      ),
    ),
  );
  $export['language_negotiation_language'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_negotiation_language_content';
  $strongarm->value = array(
    'locale-url' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_url',
        'switcher' => 'locale_language_switcher_url',
        'url_rewrite' => 'locale_language_url_rewrite_url',
      ),
      'file' => 'includes/locale.inc',
    ),
    'language-default' => array(
      'callbacks' => array(
        'language' => 'language_from_default',
      ),
    ),
  );
  $export['language_negotiation_language_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_negotiation_language_url';
  $strongarm->value = array(
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
  );
  $export['language_negotiation_language_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_types';
  $strongarm->value = array(
    'language' => TRUE,
    'language_content' => TRUE,
    'language_url' => FALSE,
  );
  $export['language_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lang_dropdown_language';
  $strongarm->value = array(
    'showall' => 1,
    'tohome' => 0,
    'width' => '75',
    'display' => '2',
    'widget' => '0',
    'msdropdown' => array(
      'visible_rows' => 5,
      'rounded' => 1,
      'animation' => 'slideDown',
      'event' => 'click',
      'skin' => 'ldsSkin',
      'custom_skin' => '',
    ),
    'chosen' => array(
      'disable_search' => 1,
      'no_results_text' => 'No language match',
    ),
    'ddslick' => array(
      'ddslick_height' => 0,
      'showSelectedHTML' => 1,
      'imagePosition' => 'left',
      'skin' => 'ddsDefault',
      'custom_skin' => '',
    ),
    'languageicons' => array(
      'flag_position' => '0',
    ),
  );
  $export['lang_dropdown_language'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'locale_field_language_fallback';
  $strongarm->value = 1;
  $export['locale_field_language_fallback'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'locale_language_negotiation_url_part';
  $strongarm->value = 0;
  $export['locale_language_negotiation_url_part'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'locale_language_providers_weight_language';
  $strongarm->value = array(
    'locale-url' => '-10',
    'locale-session' => '-6',
    'locale-user' => '-4',
    'locale-browser' => '-2',
    'language-default' => '-8',
  );
  $export['locale_language_providers_weight_language'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tagclouds_language_separation';
  $strongarm->value = 1;
  $export['tagclouds_language_separation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'translation_language_type';
  $strongarm->value = 'language_content';
  $export['translation_language_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'variable_realm_list_language';
  $strongarm->value = array(
    0 => 'site_name',
    1 => 'site_slogan',
  );
  $export['variable_realm_list_language'] = $strongarm;

  return $export;
}
