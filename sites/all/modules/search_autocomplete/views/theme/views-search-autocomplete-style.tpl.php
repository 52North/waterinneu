<?php
/**
 * @file
 * This template file is never used. The switch for choosing among the different
 * views_search_autocomplete_* themes based on format is done in
 * views_plugin_style_json->theme_functions()
 *
 * - $view: The View object.
 * - $rows: Array of row objects as rendered by
 *   _search_autocomplete_render_fields
 * - $options: Array of plugin style options
 *
 * @ingroup views_templates
 * @see views_plugin_style_json.inc
 * @see views_search_autocomplete_style.theme.inc
 */

if ($view->override_path) :
  // We're inside a live preview where the JSON is pretty-printed.
  $json = _search_autocomplete_encode_formatted($rows);
  print "<code>$json</code>";
else :
  $json = json_encode($rows);

  // We want to send the JSON as a server response so switch the content
  // type and stop further processing of the page.
  $content_type = 'application/json';
  drupal_add_http_header("Content-Type", "$content_type; charset=utf-8");
  print $json;
  // Don't think this is needed in .tpl.php files: module_invoke_all('exit');
  exit;
endif;
