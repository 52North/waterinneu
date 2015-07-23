<?php
/**
 * @file
 * wsclient_service.twitter_search.inc
 */

$api = '2.0.0';

$data = entity_import('wsclient_service', '{
    "settings" : [],
    "operations" : { "search" : {
        "label" : "Search",
        "parameter" : { "q" : { "type" : "text", "label" : "Search text" } },
        "result" : { "type" : "wsclient_twitter_search_result", "label" : "Search result" }
      }
    },
    "datatypes" : {
      "result" : {
        "label" : "Search result",
        "property info" : {
          "results" : { "type" : "list\\u003Ctweet\\u003E", "label" : "Tweet list" },
          "query" : { "type" : "text", "label" : "Requested query text" }
        }
      },
      "tweet" : {
        "label" : "Tweet data",
        "property info" : { "text" : { "type" : "text", "label" : "Tweet text" } }
      }
    },
    "global_parameters" : [],
    "name" : "twitter_search",
    "label" : "Twitter Search",
    "url" : "http:\\/\\/search.twitter.com\\/search.json",
    "type" : "rest",
    "authentication" : null,
    "rdf_mapping" : []
  }');

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'entity',
  1 => 'wsclient',
);
