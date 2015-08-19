<?php
/**
 * API Documentation for WSData
 */

/**
 * List of data processors available for parsing web service data.
 *
 * Processors have two components:
 *  - data parsing format
 *  - data output structure
 *
 * Data parsing format refers to the type of data this processor can parse.
 * For example json, xml, ical, etc...
 *
 * The output structure refers to the Drupal object which can be fed by
 * the parsed data. Your options are:
 *
 * - fields
 * - form
 * - data
 *
 * Fields imply that this processor can feed information into wsfields.
 * Form is for wsbeans, and any other object which renders Form API data.
 * Data is to simply return the raw parsed data. Meaning if you pass in
 * a JSON array for example, you'll be returned a PHP array representation
 * of that JSON data.
 *
 * The return array is keyed on the class name of the processor (please use
 * proper class casing. Our naming scheme is from the legacy class formats
 * in Drupal)
 *
 * Be sure to include your classes in the .info file if they aren't stored
 * in your .module file
 *
 * @return array
 *  Returns an array of processor info.
 * @see wsdata.info
 */
function hook_wsconfig_processor_info() {
  return array(
    'WsDataSimpleXmlProcessor' => array(
      'fields' => array(
        'list_boolean' => t('WSData Simple XML Processor'),
        'text_with_summary' => t('WSData Simple XML Processor'),
        'text' => t('WSData Simple XML Processor'),
      ),
      'data' => t('WSData Simple XML Processor'),
      'form' => t('WSData Simple XML Form API Processor'),
    ),
    'WsDataSimpleJsonProcessor' => array(
      'fields' => array(
        'list_boolean' => t('WSData Simple JSON Processor'),
        'text_with_summary' => t('WSData Simple JSON Processor'),
        'text' => t('WSData Simple JSON Processor'),
      ),
      'data' => t('WSData Simple JSON Processor'),
    ),
  );
}

/**
 * List of language handler plugins
 *
 * Adds to the list of available language handling plugins.
 * The plugins do nothing on their own. They simply define
 * a set of functionality which the WsConnector implementations
 * can reference.
 *
 * Language plugins define how multilingual data is requested
 * from a web service. There are two classes of plugins:
 *
 * 1. Single request plugins
 * 2. Multi request plugins
 *
 * Single request plugins mean that all language data is captured
 * in a single request. Usually this means the data processor
 * is responsible for parsing keyed values in the return data
 * per language. This is the default language handler.
 *
 * Multi request handlers imply that multiple web service requests
 * are required to capture all languages available. The default
 * methods defined for this are "header", "argument", "path" and "uri".
 * It is the responsibility of the WsConnector to support these plugins.
 *
 * You may define your own plugins if you have a particularly unique
 * language request mechanism (ex: post body data)
 *
 * For an example implementation
 * @see http://drupal.org/project/restclient
 */
function hook_wsdata_language_plugin() {
  return array(
    /**
     * Header language plugin
     *
     * The header plugin adds a header value to the request
     * which sets the language of the request.
     *
     * The value is the language key of the enabled languages on your site.
     * You may override this in the settings array.
     */
    'header' => array(
      'settings' => array(
        'name' => 'Accept-Language',
        'en' => 'en',  // Each language plugin will list the enabled languages on your site to set values when requesting data for that given language.
        'fr' => 'fr',
      ),
      'form' => 'wsdata_language_plugin_header_form',
      'file' => 'wsdata.admin',
      'file type' => 'inc',
      'module' => 'wsdata',
    ),
    /**
     * Argument language plugin
     *
     * The argument plugin adds a query string argument (ex: ?lang=en).
     */
    'argument' => array(
      'settings' => array(
        'name' => 'lang',
        'en' => 'en',
        'fr' => 'fr',
      ),
      'form' => 'wsdata_language_plugin_argument_form',
      'file' => 'wsdata.admin',
      'file type' => 'inc',
      'module' => 'wsdata',
    ),
    /**
     * Path language plugin
     *
     * The path plugin puts the language into the request path at the given position.
     * Ex:
     *   position = 0, http://example.com/en/my/webservice/request
     *   position = 2, http://example.com/my/webservice/en/request
     *
     * By default, it acts as a path prefix. (i.e. position 0)
     */
    'path' => array(
      'settings' => array(
        'position' => 0,
        'en' => 'en',
        'fr' => 'fr',
      ),
      'form' => 'wsdata_language_plugin_path_form',
      'file' => 'wsdata.admin',
      'file type' => 'inc',
      'module' => 'wsdata',
    ),
    /**
     * URI language plugin
     *
     * The URI plugin changes the URI to a different one based on the requesting language.
     */
    'uri' => array(
      'settings' => array(
        'en' => 'example.com',
        'fr' => 'fr.example.com',
      ),
      'form' => 'wsdata_language_plugin_path_form',
      'file' => 'wsdata.admin',
      'file type' => 'inc',
      'module' => 'wsdata',
    ),
    /**
     * Default language plugin
     *
     * By default, do nothing. Assume the WsProcessor will have all the language data
     * in a single request.
     */
    'default' => array(
      'settings' => array(),
      'form' => 'wsdata_language_plugin_default_form',
      'file' => 'wsdata.admin',
      'file type' => 'inc',
      'module' => 'wsdata',
    ),
  );
}
