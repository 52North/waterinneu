<?php
/**
 * @file
 * feature_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function feature_search_default_search_api_index() {
  $items = array();
  $items['event_index'] = entity_import('search_api_index', '{
    "name" : "Event Index",
    "machine_name" : "event_index",
    "description" : null,
    "server" : "search_server_solr_localhost",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "event" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "field_date_year_month_day:duration" : { "type" : "duration" },
        "field_date_year_month_day:value" : { "type" : "date" },
        "field_date_year_month_day:value2" : { "type" : "date" },
        "field_description" : { "type" : "text" },
        "field_venue" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "title_field" : { "type" : "text", "boost" : "2.0" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title_field" : true, "field_description" : true, "field_venue" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title_field" : true, "field_description" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "title_field" : true, "field_description" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title_field" : true, "field_description" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title_field" : true, "field_description" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
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
        "comment:subject_field" : { "type" : "text" },
        "comment:url" : { "type" : "uri" },
        "harmony_thread:field_harmony_category" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "harmony_thread:title" : { "type" : "text", "boost" : "2.0" },
        "harmony_thread:uid" : { "type" : "integer", "entity_type" : "user" },
        "node:author" : { "type" : "integer", "entity_type" : "user" },
        "node:field_application_scale" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_best_practices" : { "type" : "text" },
        "node:field_category" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "node:field_class" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_combinability" : { "type" : "text", "boost" : "0.8" },
        "node:field_contact_details" : { "type" : "text", "boost" : "0.8" },
        "node:field_costinfo" : { "type" : "text", "boost" : "0.5" },
        "node:field_costs" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "node:field_description" : { "type" : "text" },
        "node:field_end_date" : { "type" : "date" },
        "node:field_innovative_advantages" : { "type" : "text", "boost" : "0.8" },
        "node:field_issue" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_issue_info" : { "type" : "text", "boost" : "0.8" },
        "node:field_license" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "node:field_licenseinfo" : { "type" : "text", "boost" : "0.5" },
        "node:field_organisation" : { "type" : "integer", "entity_type" : "node" },
        "node:field_product" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "node:field_project" : { "type" : "integer", "entity_type" : "node" },
        "node:field_projects" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "node:field_purpose" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_purpose_info" : { "type" : "text", "boost" : "0.8" },
        "node:field_relevant_water_bodies" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_relevant_water_bodies_info" : { "type" : "text", "boost" : "0.8" },
        "node:field_service_category" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "node:field_service_offerings" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "node:field_standard_category" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_supported_data_discovery_s" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_supported_data_downloading" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_supported_data_encoding_st" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_supported_data_visualizati" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_supported_legacy_systems" : { "type" : "text", "boost" : "0.8" },
        "node:field_supported_other_standards" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_supported_processes_and_mo" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_supported_sensor_data_stan" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_target_user_group" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_target_user_group_info" : { "type" : "text", "boost" : "0.8" },
        "node:field_technology_readiness_level" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "node:field_tool_of_the_month" : { "type" : "boolean" },
        "node:field_type_of_hardware" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "node:field_type_of_input_requirements" : { "type" : "text", "boost" : "0.8" },
        "node:field_type_of_output" : { "type" : "text", "boost" : "0.8" },
        "node:field_type_of_software" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "node:field_venue" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "node:field_version" : { "type" : "text", "boost" : "0.8" },
        "node:language" : { "type" : "string" },
        "node:title" : { "type" : "text", "boost" : "2.0" },
        "node:title_field" : { "type" : "text", "boost" : "2.0" },
        "node:type" : { "type" : "string" },
        "node:url" : { "type" : "uri" },
        "search_api_language" : { "type" : "string" }
      }
    },
    "enabled" : "0",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['organisation_index'] = entity_import('search_api_index', '{
    "name" : "Organisation Index",
    "machine_name" : "organisation_index",
    "description" : null,
    "server" : "search_server_solr_localhost",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "organisation" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "field_class" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_description" : { "type" : "text" },
        "field_product" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_projects" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "search_api_language" : { "type" : "string" },
        "title_field" : { "type" : "text", "boost" : "2.0" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title_field" : true, "field_description" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title_field" : true, "field_description" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "title_field" : true, "field_description" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title_field" : true, "field_description" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title_field" : true, "field_description" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cmark\\u003E",
            "suffix" : "\\u003C\\/mark\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['product_index'] = entity_import('search_api_index', '{
    "name" : "Product Index",
    "machine_name" : "product_index",
    "description" : null,
    "server" : "search_server_solr_localhost",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "tool" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "field_application_scale" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_best_practices" : { "type" : "text" },
        "field_category" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_contact_details" : { "type" : "text" },
        "field_costinfo" : { "type" : "text" },
        "field_costs" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_description" : { "type" : "text" },
        "field_innovative_advantages" : { "type" : "text" },
        "field_issue" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_issue_info" : { "type" : "text" },
        "field_license" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_licenseinfo" : { "type" : "text" },
        "field_purpose" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_purpose_info" : { "type" : "text" },
        "field_relevant_water_bodies" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_relevant_water_bodies_info" : { "type" : "text" },
        "field_standard_category" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_supported_data_discovery_s" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_supported_data_downloading" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_supported_data_encoding_st" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_supported_data_visualizati" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_supported_other_standards" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_supported_processes_and_mo" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_supported_sensor_data_stan" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_target_user_group" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_target_user_group_info" : { "type" : "text" },
        "field_technology_readiness_level" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_type_of_hardware" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_type_of_input_requirements" : { "type" : "text" },
        "field_type_of_output" : { "type" : "text" },
        "field_type_of_software" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_version" : { "type" : "text" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "title_field" : { "type" : "text", "boost" : "2.0" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title_field" : true,
              "field_description" : true,
              "field_version" : true,
              "field_licenseinfo" : true,
              "field_costinfo" : true,
              "field_type_of_input_requirements" : true,
              "field_type_of_output" : true,
              "field_innovative_advantages" : true,
              "field_best_practices" : true,
              "field_contact_details" : true,
              "field_purpose_info" : true,
              "field_issue_info" : true,
              "field_relevant_water_bodies_info" : true,
              "field_target_user_group_info" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title_field" : true,
              "field_description" : true,
              "field_version" : true,
              "field_licenseinfo" : true,
              "field_costinfo" : true,
              "field_type_of_input_requirements" : true,
              "field_type_of_output" : true,
              "field_innovative_advantages" : true,
              "field_best_practices" : true,
              "field_contact_details" : true,
              "field_purpose_info" : true,
              "field_issue_info" : true,
              "field_relevant_water_bodies_info" : true,
              "field_target_user_group_info" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : {
              "title_field" : true,
              "field_description" : true,
              "field_version" : true,
              "field_licenseinfo" : true,
              "field_costinfo" : true,
              "field_type_of_input_requirements" : true,
              "field_type_of_output" : true,
              "field_innovative_advantages" : true,
              "field_best_practices" : true,
              "field_contact_details" : true,
              "field_purpose_info" : true,
              "field_issue_info" : true,
              "field_relevant_water_bodies_info" : true,
              "field_target_user_group_info" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title_field" : true,
              "field_description" : true,
              "field_version" : true,
              "field_licenseinfo" : true,
              "field_costinfo" : true,
              "field_type_of_input_requirements" : true,
              "field_type_of_output" : true,
              "field_innovative_advantages" : true,
              "field_best_practices" : true,
              "field_contact_details" : true,
              "field_purpose_info" : true,
              "field_issue_info" : true,
              "field_relevant_water_bodies_info" : true,
              "field_target_user_group_info" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title_field" : true,
              "field_description" : true,
              "field_version" : true,
              "field_licenseinfo" : true,
              "field_costinfo" : true,
              "field_type_of_input_requirements" : true,
              "field_type_of_output" : true,
              "field_innovative_advantages" : true,
              "field_best_practices" : true,
              "field_contact_details" : true,
              "field_purpose_info" : true,
              "field_issue_info" : true,
              "field_relevant_water_bodies_info" : true,
              "field_target_user_group_info" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cmark\\u003E",
            "suffix" : "\\u003C\\/mark\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['service_offering_index'] = entity_import('search_api_index', '{
    "name" : "Service Offering Index",
    "machine_name" : "service_offering_index",
    "description" : null,
    "server" : "search_server_solr_localhost",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "service_offering" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "field_description" : { "type" : "text" },
        "field_organisation" : { "type" : "integer", "entity_type" : "node" },
        "field_product" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_service_category" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "title_field" : { "type" : "text" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title_field" : true, "field_description" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title_field" : true, "field_description" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "title_field" : true, "field_description" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title_field" : true, "field_description" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title_field" : true, "field_description" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cmark\\u003E",
            "suffix" : "\\u003C\\/mark\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['service_requests_index'] = entity_import('search_api_index', '{
    "name" : "Service Requests Index",
    "machine_name" : "service_requests_index",
    "description" : null,
    "server" : "search_server_solr_localhost",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "service_request" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "field_description" : { "type" : "text" },
        "field_product" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_service_category" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "title_field" : { "type" : "text", "boost" : "2.0" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title_field" : true, "field_description" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title_field" : true, "field_description" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "title_field" : true, "field_description" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title_field" : true, "field_description" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title_field" : true, "field_description" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cmark\\u003E",
            "suffix" : "\\u003C\\/mark\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
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
