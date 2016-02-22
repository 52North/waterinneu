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
        "search_api_language" : { "type" : "string" }
      }
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
