<?php

/**
 * @file
 * Views hooks.
 */

/**
 * Implementats hook_field_views_data_alter().
 *
 * This function overwrites default 'views_handler_filter_locale_language'
 * filter handler with our own implementation that is fallback-aware.
 */
function language_fallback_field_views_data_alter(&$result, &$field, &$module) {
  // This is a fix for languagefield module
  if ($field['type'] == 'language_field') {
    $language_field_name = $field['field_name'] . '_value';

    foreach ($result as &$f) {
      if (isset($f[$language_field_name]) && isset($f[$language_field_name]['filter'])) {
        $f[$language_field_name]['filter']['handler'] = 'views_handler_filter_locale_language_with_fallback';
      }
    }
  }

  // This is a fix for core's field:language
  if (is_array($result) && $result) {
    foreach ($result as &$f) {
      if (isset($f['language'])) {
        if (isset($f['language']['filter'])) {
          $f['language']['filter']['handler'] = 'views_handler_filter_locale_language_with_fallback';
        }

        if (isset($f['language']['sort'])) {
          $f['language']['sort']['handler'] = 'views_handler_sort_fallback_chain';
        }
      }
    }
  }
}
