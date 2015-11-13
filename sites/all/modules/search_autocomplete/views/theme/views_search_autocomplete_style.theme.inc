<?php

/**
 * @file
 * Views theme to render view fields as JSON.
 *
 * - $view: The view in use.
 * - $rows: Array of row objects as rendered by
 * _search_autocomplete_render_fields
 * - $options: The options for the style passed in from the UI.
 *
 * @ingroup views_templates
 * @see search_autocomplete.views.inc
 */

/**
 * Prepares variables for views search autocomplete styles templates.
 *
 * Default template: views-search-autocomplete-style.tpl.php
 *
 * @param array $vars
 *   An associative array containing:
 *   - view: The view object to style.
 *   - rows: An array of rows to render.
 *   - options: An array of style options.
 *
 * @ingroup themeable
 */
function template_preprocess_views_search_autocomplete_style(&$vars) {
  global $base_root;

  $view = $vars['view'];
  $rows = $vars['rows'];
  $style_options = $vars['options'];

  $arg = '';
  if (array_key_exists(0, $view->args)) {
    $arg = $view->args[0] ? $view->args[0] : '';
  }

  $objects = array();

  $vars['bitmask'] = NULL;

  foreach ($rows as $row) {

    $object = array();

    /* ----------------
     * Build the link...
     * ----------------  */

    // Extract the URL...
    $regexp = "<a\s[^>]*href=(\"??)([^\" >]*?)\\1[^>]*>(.*)<\/a>";
    $link_value = $row[$style_options['input_link']]->raw;
    if (preg_match("/$regexp/siU", htmlspecialchars_decode($row[$style_options['input_link']]->content, ENT_QUOTES), $matches)) {
        $link_value = $matches[2];
    }
    if (url_is_external($link_value) || valid_url($link_value, TRUE)) {
      $link = $link_value;
    }
    else {
      $link = $base_root . $link_value;
    }
    // And build the link object.
    $object['link'] = trim($link);

    /* ----------------
     * Build the value...
     * ----------------  */
    $object['value'] = trim($row[$style_options['input_label']]->content);

    /* ----------------
     * Build the array of output fields...
     * ----------------  */
    $object['fields'] = array();
    foreach ($style_options['output_fields'] as $field_name) {
      // Add the field if the value is not null.
      if (array_key_exists($field_name, $row) && $row[$field_name] && $row[$field_name]->content) {
        $object['fields'][$field_name] = htmlspecialchars_decode(trim($row[$field_name]->label . ' ' . $row[$field_name]->content), ENT_QUOTES);
      }
    }

    /* ----------------
     * Sort by group objects if needed.
     * ----------------  */
    if ($style_options['group_by']) {
      $group_type = $style_options['group_by'];
      $group_name = $row[$group_type]->content;
      if (!isset($objects[$group_name])) {
        $objects[$group_name] = array();
      }
      $objects[$group_name][] = $object;
    }
    else {
      $objects[] = $object;
    }
  }

  /* ----------------
   * Build group info if grouping is enabled.
   * ----------------  */
  $returns = array();
  if ($style_options['group_by']) {
    foreach ($objects as $group_name => $group) {
      $group[0]['group']['group_id'] = preg_replace('/\W+/', '', strtolower(strip_tags($group_name)));;
      $group[0]['group']['group_name'] = trim($group_name);
      $returns = array_merge($returns, $group);
    }
    $vars["rows"] = $returns;
  }
  else {
    // Check if user wants nested arrays.
    $vars["rows"] = $objects;
  }

 /* ----------------
  * Add $no_results and $all_results if needed.
  * ----------------  */
  if (!empty($view->autocompletion_data)) {
    str_replace('[search-phrase]', $view->autocompletion_data['user_input'], $view->autocompletion_data['no_results']);

    // Check case between $no_results and $all_results
    if (empty($vars["rows"])) {
      // No results case
      $no_result_json = str_replace('[search-phrase]', $view->autocompletion_data['user_input'], $view->autocompletion_data['no_results']);
      $suggestion = json_decode($no_result_json);
      $group_id = 'no_results';
    }
    else {
      // All results case
      $all_results_json = str_replace('[search-phrase]', $view->autocompletion_data['user_input'], $view->autocompletion_data['all_results']);
      $suggestion = json_decode($all_results_json);
    }
    if (!empty($suggestion->label)) {
      $suggestion->fields['label'] = $suggestion->label;
    }
    $vars["rows"][] = $suggestion;
  }

}
