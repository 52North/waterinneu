<?php
/**
 * @file
 * wsclient_service.geocoder.inc
 */

$api = '2.0.0';

$data = entity_import('wsclient_service', '{
    "settings" : [],
    "operations" : {
      "geocode" : {
        "label" : "geocode",
        "result" : {
          "type" : "list\\u003CGeocoderResult\\u003E",
          "label" : "list\\u003CGeocoderResult\\u003E"
        },
        "parameter" : { "location" : { "type" : "text" } }
      },
      "geocode_address" : {
        "label" : "geocode_address",
        "result" : {
          "type" : "list\\u003CGeocoderAddressResult\\u003E",
          "label" : "list\\u003CGeocoderAddressResult\\u003E"
        },
        "parameter" : { "address" : { "type" : "text" } }
      },
      "geocode_intersection" : {
        "label" : "geocode_intersection",
        "result" : {
          "type" : "list\\u003CGeocoderIntersectionResult\\u003E",
          "label" : "list\\u003CGeocoderIntersectionResult\\u003E"
        },
        "parameter" : { "intersection" : { "type" : "text" } }
      }
    },
    "datatypes" : {
      "GeocoderResult" : {
        "label" : "GeocoderResult",
        "property info" : {
          "zip" : { "type" : "integer" },
          "state" : { "type" : "text" },
          "city" : { "type" : "text" },
          "lat" : { "type" : "decimal" },
          "long" : { "type" : "decimal" },
          "number" : { "type" : "integer" },
          "suffix" : { "type" : "text" },
          "prefix" : { "type" : "text" },
          "type" : { "type" : "text" },
          "street" : { "type" : "text" },
          "suffix1" : { "type" : "text" },
          "prefix1" : { "type" : "text" },
          "type1" : { "type" : "text" },
          "street1" : { "type" : "text" },
          "suffix2" : { "type" : "text" },
          "prefix2" : { "type" : "text" },
          "type2" : { "type" : "text" },
          "street2" : { "type" : "text" }
        }
      },
      "GeocoderAddressResult" : {
        "label" : "GeocoderAddressResult",
        "property info" : {
          "number" : { "type" : "integer" },
          "zip" : { "type" : "integer" },
          "suffix" : { "type" : "text" },
          "prefix" : { "type" : "text" },
          "type" : { "type" : "text" },
          "street" : { "type" : "text" },
          "state" : { "type" : "text" },
          "city" : { "type" : "text" },
          "lat" : { "type" : "decimal" },
          "long" : { "type" : "decimal" }
        }
      },
      "GeocoderIntersectionResult" : {
        "label" : "GeocoderIntersectionResult",
        "property info" : {
          "zip" : { "type" : "integer" },
          "suffix1" : { "type" : "text" },
          "prefix1" : { "type" : "text" },
          "type1" : { "type" : "text" },
          "street1" : { "type" : "text" },
          "suffix2" : { "type" : "text" },
          "prefix2" : { "type" : "text" },
          "type2" : { "type" : "text" },
          "street2" : { "type" : "text" },
          "state" : { "type" : "text" },
          "city" : { "type" : "text" },
          "lat" : { "type" : "decimal" },
          "long" : { "type" : "decimal" }
        }
      }
    },
    "global_parameters" : [],
    "name" : "geocoder",
    "label" : "Geocoder.us",
    "url" : "http:\\/\\/geocoder.us\\/dist\\/eg\\/clients\\/GeoCoderPHP.wsdl",
    "type" : "soap",
    "authentication" : null,
    "rdf_mapping" : []
  }');

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'entity',
  1 => 'wsclient',
);
