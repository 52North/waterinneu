<?php
/**
 * @file
 * wsclient_service.google.inc
 */

$api = '2.0.0';

$data = entity_import('wsclient_service', '{
    "settings" : [],
    "operations" : { "translate" : {
        "label" : "Translate text",
        "url" : "language\\/translate",
        "parameter" : {
          "q" : { "type" : "text", "label" : "Text" },
          "langpair" : {
            "type" : "text",
            "label" : "Language pair",
            "description" : "The language pair used for translating, such as de|en."
          },
          "v" : { "type" : "hidden", "default value" : "1.0" }
        },
        "result" : {
          "type" : "wsclient_google_translation_result",
          "label" : "Translation result"
        }
      }
    },
    "datatypes" : { "translation_result" : {
        "label" : "Translation result",
        "property info" : { "responseData" : {
            "type" : "struct",
            "label" : "Response data",
            "property info" : { "translatedText" : { "type" : "text", "label" : "Translated text" } }
          }
        }
      }
    },
    "global_parameters" : [],
    "name" : "google",
    "label" : "Google Ajax APIs",
    "url" : "http:\\/\\/ajax.googleapis.com\\/ajax\\/services\\/",
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
