<?php
/**
 * @file
 * feature_search.features.inc
 */

/**
 * Implements hook_default_search_api_index().
 */
function feature_search_default_search_api_index() {
  $items = array();
  $items['global_index'] = entity_import('search_api_index', '{
    "name" : "Global Index",
    "machine_name" : "global_index",
    "description" : null,
    "server" : "search_server_solr_localhost",
    "item_type" : "multiple",
    "options" : {
      "datasource" : { "types" : [
          "comment",
          "node",
          "harmony_thread",
          "taxonomy_term",
          "user",
          "harmony_post",
          "taxonomy_vocabulary",
          "file"
        ]
      },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "comment:author" : { "type" : "integer", "entity_type" : "user" },
        "comment:homepage" : { "type" : "text" },
        "comment:mail" : { "type" : "text" },
        "comment:name" : { "type" : "text" },
        "comment:parent" : { "type" : "integer", "entity_type" : "comment" },
        "comment:subject" : { "type" : "text" },
        "comment:url" : { "type" : "uri" },
        "node:author" : { "type" : "integer", "entity_type" : "user" },
        "node:field_administrative_aggregation" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "node:field_administrative_data" : { "type" : "boolean" },
        "node:field_administrative_data_collec" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "node:field_application_scale" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "node:field_approach" : { "type" : "text" },
        "node:field_category" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "node:field_class" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_comments" : { "type" : "text" },
        "node:field_costs" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "node:field_country_term" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "node:field_guideline" : { "type" : "boolean" },
        "node:field_hardware" : { "type" : "boolean" },
        "node:field_hydrolocagical_aggregation" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "node:field_hydrological_data_collecti" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "node:field_license" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "node:field_metadata_level" : { "type" : "integer" },
        "node:field_model" : { "type" : "boolean" },
        "node:field_model_data" : { "type" : "boolean" },
        "node:field_observation_data" : { "type" : "boolean" },
        "node:field_organisations" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "node:field_partners_countries_of_orig" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_partners_from" : { "type" : "list\\u003Ctext\\u003E" },
        "node:field_policy_brief" : { "type" : "boolean" },
        "node:field_projects" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "node:field_published_tools" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "node:field_purpose" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_raw_data" : { "type" : "boolean" },
        "node:field_report_available_" : { "type" : "boolean" },
        "node:field_software" : { "type" : "boolean" },
        "node:field_standards_accounted_for" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_tool_of_the_month" : { "type" : "boolean" },
        "node:title" : { "type" : "text", "boost" : "2.0" },
        "node:title_field" : { "type" : "text", "boost" : "2.0" },
        "node:url" : { "type" : "uri" },
        "search_api_language" : { "type" : "string" }
      },
      "additional fields" : { "harmony_thread" : "harmony_thread" }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function feature_search_default_search_api_server() {
  $items = array();
  $items['search_server_solr_localhost'] = entity_import('search_api_server', '{
    "name" : "Local Solr Server",
    "machine_name" : "search_server_solr_localhost",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr\\/drupal",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO"
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
