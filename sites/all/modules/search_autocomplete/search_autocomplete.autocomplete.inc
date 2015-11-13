<?php

/**
 * @file
 * Function to compute the various autocomplete features.
 */


/**
 * Autocomplete the view selection in admin.
 *
 * The function does not return if the auto-complete feature
 * worked. Otherwise, it returns NULL.
 *
 * The user string so far
 */
function search_autocomplete_views_autocomplete($user_input = '') {

  // Anything yet?
  if (!$user_input) {
    echo drupal_json_encode(array());
    exit();
  }
  // Current user has the right to do that?!
  if (!user_access('access content')) {
    drupal_access_denied();
    return;
  }

  // Load all views.
  $views = views_get_all_views();
  // Select views with an according name.
  $matches = array();
  foreach ($views as $view_id => $view) {
    if (strpos($view->human_name, $user_input) !== FALSE) {
      $matches[$view_id] = $view->human_name;
    }
  }
  // Return the json inputs.
  echo drupal_json_encode($matches);
  exit();
}

/**
 * Page callback: Returns JSON data of content that matches the user's input.
 *
 * @param string $fid
 *   Description of a parameter for this page.
 * @param string $user_input
 *   The data
 *
 * @return NULL
 *   Never returns; calls exit().
 *
 * @see search_autocomplete_menu()
 */
function search_autocomplete_autocomplete($fid) {

  $user_input = filter_xss($_GET['term']);

  $result = db_select('search_autocomplete_forms', 'f')
  ->fields('f', array('data_view', 'no_results', 'all_results'))
  ->condition('f.fid', $fid, '=')
  ->execute()
  ->fetchAssoc();

  $view = views_get_view($result['data_view']);
  $view_exposed_filters = views_get_view($result['data_view']);
  $view_exposed_filters->set_display('default');
  $view_exposed_filters->is_cacheable = FALSE;
  $view_exposed_filters->execute();
  foreach ($view_exposed_filters->exposed_raw_input as $key => $value) {
    $view->exposed_input[$key] = $user_input;
  }

  // Add our custom data in the view for rendering.
  $view->autocompletion_data['user_input'] = $user_input;
  $view->autocompletion_data['no_results'] = $result['no_results'];
  $view->autocompletion_data['all_results'] = $result['all_results'];

  if (method_exists($view, 'render')) {
    echo $view->render();
  }
  else {
    echo drupal_json_encode(array());
  }
  exit();
}
