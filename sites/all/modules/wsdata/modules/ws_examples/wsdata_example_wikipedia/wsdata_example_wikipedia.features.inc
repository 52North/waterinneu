<?php
/**
 * @file
 * wsdata_example_wikipedia.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function wsdata_example_wikipedia_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function wsdata_example_wikipedia_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function wsdata_example_wikipedia_node_info() {
  $items = array(
    'linked_data' => array(
      'name' => t('Linked Data'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function wsdata_example_wikipedia_default_search_api_index() {
  $items = array();
  $items['node'] = entity_import('search_api_index', '{
    "name" : "node",
    "machine_name" : "node",
    "description" : null,
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "title" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "field_remote_text:value" : { "type" : "text" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "field_remote_text:value" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "field_remote_text:value" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "field_remote_text:value" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "field_remote_text:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function wsdata_example_wikipedia_default_search_api_server() {
  $items = array();
  $items['solr'] = entity_import('search_api_server', '{
    "name" : "solr",
    "machine_name" : "solr",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "http_method" : "POST"
    },
    "enabled" : "1"
  }');
  return $items;
}

/**
 * Implements hook_default_wsconfig().
 */
function wsdata_example_wikipedia_default_wsconfig() {
  $items = array();
  $items['wikipedia_read'] = entity_import('wsconfig', '{
    "connector" : {},
    "type" : "wikipedia",
    "language" : "",
    "name" : "wikipedia_read",
    "title" : "wikipedia_read",
    "created" : "1361494917",
    "changed" : "1361494917",
    "data" : {
      "create_data_method" : "",
      "read_data_method" : "api.php?format=xml\\u0026action=parse\\u0026prop=text\\u0026page=%title",
      "update_data_method" : "",
      "delete_data_method" : ""
    }
  }');
  return $items;
}

/**
 * Implements hook_default_wsconfig_type().
 */
function wsdata_example_wikipedia_default_wsconfig_type() {
  $items = array();
  $items['wikipedia'] = entity_import('wsconfig_type', '{
    "type" : "wikipedia",
    "label" : "Wikipedia",
    "weight" : "0",
    "data" : {
      "endpoint" : "http:\\/\\/en.wikipedia.org\\/w",
      "connector" : "restclient_wsconnector"
    }
  }');
  return $items;
}
