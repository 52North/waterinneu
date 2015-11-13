<?php
/**
 * @file
 * Views style plugin to render nodes in the JSON data format.
 *
 * @see views_plugin_style_json.inc
 * @ingroup views_plugins
 */

/**
 * Implements hook_views_plugins().
 */
function search_autocomplete_views_plugins() {

  $path = drupal_get_path('module', 'search_autocomplete') . '/views';
  return array(
    'module' => 'search_autocomplete',
    'style' => array(
      'search_autocomplete' => array(
        'title'             => t('Autocompletion JSON'),
        'path'              => $path . '/plugins',
        'help'              => t('Displays nodes in the JSON data format.'),
        'handler'           => 'SearchAutocompleteViewsPluginStyle',
        'theme'             => 'views_search_autocomplete_style',
        'theme file'        => 'views_search_autocomplete_style.theme.inc',
        'theme path'        => $path . '/theme',
        'uses row plugin'   => FALSE,
        'uses fields'       => TRUE,
        'uses options'      => TRUE,
        'type'              => 'normal',
        'help_topic'        => 'style-autocomplete',
        'even empty'        => TRUE,
      ),
    ),
  );
}
