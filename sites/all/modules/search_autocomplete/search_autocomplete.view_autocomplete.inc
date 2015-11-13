<?php

/**
 * @file
 * Search Autocomplete
 * Enables autocomplete functionality on search fields.
 *
 * Sponsored by:
 * www.axiomcafe.fr
 */

/**
 * Implements hook_views_api().
 */
function search_autocomplete_views_api() {
  return array(
    'api' => '3.0',
    'path' => drupal_get_path('module', 'search_autocomplete') . '/views',
  );
}

/**
 * Renders each field in a row object using a field's theme.
 *
 * Takes each field from a row object and renders the field as determined by the
 * field's theme
 *
 * @param object $view
 *   View the row belongs to.
 * @param object $row
 *   Row object.
 *
 * @return array
 *   Object containing all the raw and rendered fields.
 */
function _search_autocomplete_render_fields($view, $row) {
  $field_ids = array_keys($view->field);
  $rendered_fields = array();
  foreach ($field_ids as $id) {
    $field = $view->field[$id];
    $field_is_multiple = FALSE;
    $field_raw = array();
    if ((isset($field->options['multiple']['group']))&& isset($field->field_values)) {
      $field_output = _search_autocomplete_render_multiple_field($field, $row);
      $n = 0;
      if (is_array($field_output)) {
        foreach ($field->field_values[$row->{$field->field_alias}] as $item) {
          $field_raw[++$n] = $item["value"];
        }
        $field_is_multiple = TRUE;
      }
      else {
        $field_raw = $view->field[$field->options['id']]->advanced_render($row);
      }
    }
    else {
      $field_output = $view->field[$field->options['id']]->advanced_render($row);
      $field_raw = (isset($view->field[$id]->field_alias) && isset($row->{$view->field[$id]->field_alias})) ? $row->{$view->field[$id]->field_alias} : NULL;
    }

    if (empty($field->options['exclude'])) {
      if (empty($field->options['exclude']) && !($field->options['hide_empty'] && (empty($field_output)))) {
        $object = new stdClass();
        $object->id = $id;
        // Respect the 'empty' value if empty and "No results text" is given.
        if (empty($field_output) && $field->options['empty']) {
          $object->content = $field->options['empty'];
        }
        else {
          $object->content = $field_output;
        }
        $object->raw = $field_raw;
        $object->class = drupal_clean_css_identifier(strtolower($id));

        $object->label = check_plain($view->field[$id]->label());

        if ($object->label) {
          if ($view->field[$id]->options['element_label_colon']) {
            $object->label .= ': ';
          }
          else {
            $object->label .= ' ';
          }
        }

        $object->is_multiple = $field_is_multiple;
        $rendered_fields[$id] = $object;

      }
    }
  }
  return $rendered_fields;
}

/**
 * Encodes JSON in a pretty-printed fashion.
 *
 * Only used inside the preview on the view configuration page.
 * @deprecated The $option parameter in PHP 5.4.0 json_encode() deprecates this
 * function.
 *
 * @see _search_autocomplete_json_encode()
 */
function _search_autocomplete_encode_formatted($json, $depth = 0) {

  $base_indent  = '&nbsp;&nbsp;';
  $eol          = '<br />';
  $indent       = str_repeat($base_indent, $depth);

  // This is based on the drupal_to_js() function.
  switch (gettype($json)) {
    case 'boolean':
      // Lowercase is necessary!
      return $json ? 'true' : 'false';

    case 'integer':
    case 'double':
      return $json;

    case 'resource':
    case 'string':
      $search   = array(
        '"',
        chr(92),
        chr(8),
        chr(12),
        chr(13) . chr(10),
        chr(10),
        chr(13),
        chr(9),
      );
      $replace  = array('\"', '\\', '\b', '\f', '\n', '\n', '\r', '\t');
      $output   = str_replace($search, $replace, $json);

      return '"' . check_plain($output) . '"';

    case 'array':
      // Arrays in JSON can't be associative.  If the array is empty or if it
      // has sequential whole number keys starting with 0, it's not associative
      // so we can go ahead and convert it as an array.
      if (empty($json) || array_keys($json) === range(0, count($json) - 1)) {
        $output = array();
        foreach ($json as $val) {
          $output[] = $indent . $base_indent . _search_autocomplete_encode_formatted($val, $depth + 1);
        }
        return '[' . (!empty($output) ? $eol . implode(',' . $eol, $output) . $eol . $indent : '') . ']';
      }
      // Otherwise, fall through to convert the array as an object.

    case 'object':
      $output = array();
      foreach ($json as $key => $val) {
        $output[] = $indent . $base_indent . _search_autocomplete_encode_formatted(strval($key)) . ' : ' . _search_autocomplete_encode_formatted($val, $depth + 1);
      }
      return '{' . (!empty($output) ? $eol . implode(',' . $eol, $output) . $eol . $indent : '') . '}';

    default:
      return 'null';
  }
}

/**
 * Implements hook_views_default_views().
 */
function search_autocomplete_views_default_views() {
  // Creates a defaults view as a user helper.
  return search_autocomplete_view_autocomplete();
}

/**
 * Begin view.
 */
function search_autocomplete_view_autocomplete() {

  // AUTOCOMPLETE NODES VIEW
  $view_nodes = new view();
  $view_nodes->name = 'nodes_autocomplete';
  $view_nodes->description = '';
  $view_nodes->tag = 'default';
  $view_nodes->base_table = 'node';
  $view_nodes->human_name = 'nodes-autocomplete';
  $view_nodes->core = 7;
  $view_nodes->api_version = '3.0';
  $view_nodes->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view_nodes->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Node title suggestions for autocompletion';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sort by';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'search_autocomplete';
  $handler->display->display_options['style_options']['group_by'] = 'type';
  $handler->display->display_options['style_options']['input_label'] = 'title';
  $handler->display->display_options['style_options']['input_link'] = 'view_node';
  $handler->display->display_options['style_options']['output_fields'] = array(
    'title' => 'title',
    'name' => 'name',
    'comment_count' => 'comment_count',
  );
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'author';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['comment_count']['separator'] = ' ';
  $handler->display->display_options['fields']['comment_count']['suffix'] = ' comment(s)';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content revision: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node_revision';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'filter';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view_nodes->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nodes-autocomplete';
  /* Add the view */
  $views[$view_nodes->name] = $view_nodes;

  // -------------------------------------------------------------
  // AUTOCOMPLETE USER VIEW
  $view_users = new view();
  $view_users->name = 'users_autocomplete';
  $view_users->description = '';
  $view_users->tag = 'default';
  $view_users->base_table = 'users';
  $view_users->human_name = 'users-autocomplete';
  $view_users->core = 7;
  $view_users->api_version = '3.0';
  $view_users->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view_users->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'users_autocomplete';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sort by';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'search_autocomplete';
  $handler->display->display_options['style_options']['group_by'] = 'rid';
  $handler->display->display_options['style_options']['input_label'] = 'name';
  $handler->display->display_options['style_options']['input_link'] = 'view_user';
  $handler->display->display_options['style_options']['output_fields'] = array(
    'picture' => 'picture',
    'name' => 'name',
  );
  /* Field: User: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['label'] = '';
  $handler->display->display_options['fields']['view_user']['element_label_colon'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'autocompletion_style';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['hide_empty'] = TRUE;
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Nom (brut)';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'filter';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view_users->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'users-autocomplete';
  $views[$view_users->name] = $view_users;

  // AUTOCOMPLETE NODE WORDS
  $view_words = new view();
  $view_words->name = 'words_autocomplete';
  $view_words->description = '';
  $view_words->tag = 'default';
  $view_words->base_table = 'node';
  $view_words->human_name = 'words-autocomplete';
  $view_words->core = 7;
  $view_words->api_version = '3.0';
  $view_words->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view_words->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'words-autocomplete';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sort by';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['style_plugin'] = 'search_autocomplete';
  $handler->display->display_options['style_options']['input_label'] = 'title';
  $handler->display->display_options['style_options']['input_link'] = 'view_node';
  $handler->display->display_options['style_options']['output_fields'] = array(
    'title' => 'title',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'is contained in';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Body (body) */
  $handler->display->display_options['filters']['body_value']['id'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['table'] = 'field_data_body';
  $handler->display->display_options['filters']['body_value']['field'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['body_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['body_value']['expose']['operator_id'] = 'body_value_op';
  $handler->display->display_options['filters']['body_value']['expose']['label'] = 'Body (body)';
  $handler->display->display_options['filters']['body_value']['expose']['operator'] = 'body_value_op';
  $handler->display->display_options['filters']['body_value']['expose']['identifier'] = 'filter';
  $handler->display->display_options['filters']['body_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view_words->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'words-autocomplete';

  $views[$view_words->name] = $view_words;

  return $views;
}
