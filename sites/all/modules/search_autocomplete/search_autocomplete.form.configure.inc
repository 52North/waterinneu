<?php

/**
 * @file
 * Search Autocomplete
 * Helper functions to retrieve suggestions from database
 *
 * Sponsored by:
 * www.axiomcafe.fr
 */

/**
 * MENU CALLBACK: Define the form to configure the suggestions.
 *
 * @return array
 *   A rendered form.
 */
function search_autocomplete_form_configure($form, &$form_state) {

  // Get data from database.
  $fid = arg(4);

  $result = db_select('search_autocomplete_forms', 'f')
    ->fields('f')
    ->condition('fid', $fid)
    ->execute()
    ->fetchAllAssoc('fid');

  foreach ($result as $item) {
    $form['fid'] = array(
      '#type' => 'hidden',
      '#value' => $fid,
    );
    // ------------------------------------------------------------------.
    // HOW - How to display Search Autocomplete suggestions.
    $form['search_autocomplete_how'] = array(
      '#type'           => 'fieldset',
      '#title'          => t('HOW - How to display Search Autocomplete suggestions?'),
      '#collapsible'    => TRUE,
      '#collapsed'      => TRUE,
    );
    // Minimum characters to set autocompletion on.
    $form['search_autocomplete_how']['min_char'] = array(
      '#type'           => 'textfield',
      '#title'          => t('Minimum keyword size that uncouple autocomplete search'),
      '#description'    => t('Please enter the minimum number of character a user must input before autocompletion starts.'),
      '#default_value'  => $item->min_char,
      '#maxlength'      => 2,
      '#required'       => TRUE,
    );
    // Number of suggestions to display.
    $form['search_autocomplete_how']['max_sug'] = array(
      '#type'           => 'textfield',
      '#title'          => t('Limit of the autocomplete search result'),
      '#description'    => t('Please enter the maximum number of suggestion to display.'),
      '#default_value'  => $item->max_sug,
      '#maxlength'      => 2,
      '#required'       => TRUE,
    );

    // Check if form should be auto submitted.
    $form['search_autocomplete_how']['auto_submit'] = array(
      '#type'           => 'checkbox',
      '#title'          => t('Auto Submit'),
      '#description'    => t('If enabled, the form will be submitted automatically as soon as your user choose a suggestion in the popup list.'),
      '#default_value'  => $item->auto_submit,
    );
    // Check if form should be auto redirected.
    $form['search_autocomplete_how']['auto_redirect'] = array(
      '#type'           => 'checkbox',
      '#title'          => t('Auto Redirect'),
      '#description'    => t('If enabled, the user will be directly routed to the suggestion he chooses instead of performing form validation process. Only works if "link" attribute is existing and if "Auto Submit" is enabled.'),
      '#default_value'  => $item->auto_redirect,
    );

    // ###
    $all_results = json_decode($item->all_results);
    // "View all results" custom configurations
    $form['search_autocomplete_how']['view_all_results'] = array(
        '#type'           => 'fieldset',
        '#title'          => t('Custom behaviour when some suggestions are available'),
        '#collapsible'    => TRUE,
        '#collapsed'      => TRUE,
    );
    // Check if form should be auto submitted.
    $form['search_autocomplete_how']['view_all_results']['all_results_label'] = array(
        '#type'           => 'textfield',
        '#title'          => t('Custom "view all results" message label'),
        '#description'    => t('This message is going to be displayed at the end of suggestion list when suggestions are found. Leave empty to disable this functionality. You can use HTML tags as well as the token [search-phrase] to replace user input.'),
        '#default_value'  => t($all_results->label),
        '#maxlength'      => 255,
        '#required'       => FALSE,
    );
    // Check if form should be auto submitted.
    $form['search_autocomplete_how']['view_all_results']['all_results_value'] = array(
        '#type'           => 'textfield',
        '#title'          => t('Custom "view all results" message value'),
        '#description'    => t('If a label is filled above, this is the value that will be picked when the message is selected. Leave empty if you don\'t want the message to be selectable. You can use the token [search-phrase] to replace user input.'),
        '#default_value'  => $all_results->value,
        '#maxlength'      => 255,
        '#required'       => FALSE,
    );
    // Check if form should be auto submitted.
    $form['search_autocomplete_how']['view_all_results']['all_results_link'] = array(
        '#type'           => 'textfield',
        '#title'          => t('Custom "view all results" URL redirection'),
        '#description'    => t('If "Auto redirect" is checked and a label is given for this configuration, the user will be redirected to this URL when the message is selected. Leave empty if you rather like a standard Drupal search to be performed on the "value" given above.'),
        '#default_value'  => $all_results->link,
        '#maxlength'      => 255,
        '#required'       => FALSE,
    );

    // ###
    $no_results = json_decode($item->no_results);
    // "No resuls" custom configurations
    $form['search_autocomplete_how']['no_results'] = array(
        '#type'           => 'fieldset',
        '#title'          => t('Custom behaviour when no suggestions are found'),
        '#collapsible'    => TRUE,
        '#collapsed'      => TRUE,
    );
    // Check if form should be auto submitted.
    $form['search_autocomplete_how']['no_results']['no_results_label'] = array(
        '#type'           => 'textfield',
        '#title'          => t('Custom "no result" message label'),
        '#description'    => t('This message is going to be displayed when no suggestions can be found. Leave empty to disable this functionality. You can use HTML tags as well as the token [search-phrase] to replace user input.'),
        '#default_value'  => t($no_results->label),
        '#maxlength'      => 255,
        '#required'       => FALSE,
    );
    // Check if form should be auto submitted.
    $form['search_autocomplete_how']['no_results']['no_results_value'] = array(
        '#type'           => 'textfield',
        '#title'          => t('Custom "no result" message value'),
        '#description'    => t('If a label is filled above, this is the value that will be picked when the message is selected. Leave empty if you don\'t want the message to be selectable. You can use the token [search-phrase] to replace user input.'),
        '#default_value'  => $no_results->value,
        '#maxlength'      => 255,
        '#required'       => FALSE,
    );
    // Check if form should be auto submitted.
    $form['search_autocomplete_how']['no_results']['no_results_link'] = array(
        '#type'           => 'textfield',
        '#title'          => t('Custom "no result" URL redirection'),
        '#description'    => t('If "Auto redirect" is checked and a label is given for this configuration, the user will be redirected to this URL when the message is selected. Leave empty if you rather like a standard Drupal search to be performed on the "value" given above.'),
        '#default_value'  => $no_results->link,
        '#maxlength'      => 255,
        '#required'       => FALSE,
    );

    // ------------------------------------------------------------------.
    // WHAT - What to display in Search Autocomplete suggestions.
    $form['search_autocomplete_what'] = array(
      '#type'           => 'fieldset',
      '#title'          => t('WHAT - What to display in Search Autocomplete suggestions?'),
      '#description'    => t('Choose which data should be added to autocompletion suggestions.'),
      '#collapsible'    => TRUE,
      '#collapsed'      => FALSE,
    );
    $form['search_autocomplete_what']['suggestions'] = array(
      '#type'           => 'item',
      '#title'          => t('Suggestion source'),
      '#description'    => t('Choose the source of suggestions to display in this form'),
    );

    // Use a callback.
    $form['search_autocomplete_what']['suggestions']['callback'] = array();
    $form['search_autocomplete_what']['callback']['callback_option'] = array(
      '#type'           => 'radio',
      '#title'          => t('Callback URL:'),
      '#return_value'   => 'callback',
      '#default_value'  => $item->data_source,
      '#prefix'         => '<div class="form-radios">',
      '#parents'        => array('suggestions'),
    );
    $descr = t('Enter the url where to retrieve suggestions. It can be internal (absolute or relative) or external.');
    $form['search_autocomplete_what']['callback']['callback_textfield'] = array(
      '#type'           => 'textfield',
      '#description'    => $descr,
      '#default_value'  => $item->data_source == 'callback' ? $item->data_callback : '',
      // The default size is a bit large...
      '#size'           => 80,
      // End of the "form-radios" style.
      '#suffix'        => '',
      '#attributes'     => array('onClick' => '$("input[name=suggestions][value=1]").attr("checked", true);'),
    );

    // Use static resources.
    $form['search_autocomplete_what']['suggestions']['staticresource'] = array();
    $form['search_autocomplete_what']['staticresource']['staticresource_option'] = array(
      '#type'           => 'radio',
      '#title'          => t('Static resource :'),
      '#return_value'   => 'static',
      '#default_value'  => $item->data_source,
      '#parents'        => array('suggestions'),
    );
    $form['search_autocomplete_what']['staticresource']['staticresource_textfield'] = array(
      '#type'           => 'textarea',
      '#description'    => t('Please enter one suggestion per line. You can use the syntax: "foo => http://bar" per line if you wish to add a jumping to URL for the suggestion. Please refer to <a href="http://drupal-addict.com/nos-projets/search-autocomplete">documentation</a>.'),
      '#default_value'  => $item->data_static,
      '#size'           => 20,
      '#attributes'     => array('onClick' => '$("input[name=suggestions][value=2]").attr("checked", true);'),
    );

    // Use a view.
    $form['search_autocomplete_what']['suggestions']['view'] = array();
    $form['search_autocomplete_what']['view']['view_option'] = array(
      '#type'           => 'radio',
      '#title'          => t('Use an existing view:'),
      '#return_value'   => 'view',
      '#default_value'  => $item->data_source,
      '#suffix'         => '</div>',
      '#parents'        => array('suggestions'),
      '#attributes'     => array('onClick' => '$("input[name=suggestions][value=3]").attr("checked", true);'),
    );
    $form['search_autocomplete_what']['view']['view_textfield'] = array(
      '#type'           => 'textfield',
      '#description'    => t('Use autocompletion to match an eligible view.'),
      '#default_value'  => $item->data_view,
      '#autocomplete_path' => 'views/autocomplete',
      // The default size is a bit large...
      '#size'           => 80,
      '#attributes'     => array('onClick' => '$("input[name=suggestions][value=3]").attr("checked", true);'),
    );

    // Template to use.
    $themes = array();
    $files = file_scan_directory(drupal_get_path('module', 'search_autocomplete') . '/css/themes', '/.*\.css\z/', array('recurse' => FALSE));
    foreach ($files as $file) {
      if ($file->name != 'jquery.autocomplete') {
        $themes[$file->filename] = $file->name;
      }
    }
    $form['search_autocomplete_what']['theme'] = array(
      '#type'           => 'select',
      '#title'          => t('Select a theme for your suggestions'),
      '#options'        => $themes,
      '#default_value'  => $item->theme,
      '#description'    => t('Choose the theme to use for autocompletion dropdown popup. Read <a href="http://drupal-addict.com/nos-projets/search-autocomplete">documentation</a> to learn how to make your own.'),
    );

    // ------------------------------------------------------------------.
    // ADVANCED - Advanced options.
    $form['search_autocomplete_advanced'] = array(
      '#type'             => 'fieldset',
      '#title'            => t('ADVANCED - Advanced options'),
      '#collapsible'      => TRUE,
      '#collapsed'        => TRUE,
    );
    $form['search_autocomplete_advanced']['selector'] = array(
      '#type'             => 'textfield',
      '#title'            => t('ID selector for this form'),
      '#description'      => t('Please change only if you know what you do, read <a href="http://drupal-addict.com/nos-projets/search-autocomplete">documentation</a> first.'),
      '#default_value'    => $item->selector,
      '#maxlength'        => 255,
      '#size'             => 35,
    );
    // Add button validation.
    $form['submit'] = array(
      '#type'             => 'submit',
      '#value'            => t('Save configuration'),
    );
  }
  return $form;
}
// --------------------------------------------------------------------------.
/**
 * Implements hook_validate().
 *
 * Save the changes in the database.
 */
function search_autocomplete_form_configure_validate($form, &$form_state) {

  $values = $form_state['values'];
  if ($values['suggestions'] == 1) {
    $new_url = preg_replace('/\?[^=]*=[^&]*/', '', $values['callback_textfield']);
    if (!drupal_valid_path($new_url)) {
      form_set_error('url', t('callback url is not valid: @new_url', array('@new_url' => $new_url)));
    }
  }
}

// -------------------------------------------------------------------------.
/**
 * Implements hook_submit().
 *
 * Save the changes in the database.
 */
function search_autocomplete_form_configure_submit($form, &$form_state) {
  global $base_url;

  $ok_query = TRUE;
  // Get form submission values.
  $values = $form_state['values'];

  // Analyse incoming callback.
  $callback = $values['callback_textfield'];
  // Static resource => type = 2.
  $data_type = $values['suggestions'];
  // In the case of view, we use a custom callback to retrieve the view data.
  if ($data_type == 'view') {
    $callback = 'search_autocomplete/autocomplete/' . $values['fid'] . '/';
  }

  $all_results = array(
    'label' => $values['all_results_label'],
    'value' => $values['all_results_value'],
    'link' => $values['all_results_link'],
    'group' => array(
      'group_id' => 'all_results',
    ),
  );
  $no_results = array(
    'label' => $values['no_results_label'],
    'value' => $values['no_results_value'],
    'link' => $values['no_results_link'],
    'group' => array(
      'group_id' => 'no_results',
    ),
  );

  // ###.
  // UPDATE THE FORM.
  // -> update form.
  db_update('search_autocomplete_forms')
    ->fields(array(
      'min_char'        => $values['min_char'],
      'max_sug'         => $values['max_sug'],
      'auto_submit'     => $values['auto_submit'],
      'auto_redirect'   => $values['auto_redirect'],
      'all_results'     => json_encode($all_results),
      'no_results'      => json_encode($no_results),
      'selector'        => $values['selector'],
      'data_source'     => $values['suggestions'],
      'data_callback'   => $callback,
      'data_static'     => $values['staticresource_textfield'],
      'data_view'       => $values['view_textfield'],
      'theme'           => $values['theme'],
    ))
    ->condition('fid', $values['fid'])
    ->execute();
  // ###
  // UPDATE CHILD LIST BUT NOT THE ADVANCED OPTIONS.
  $fids = _search_autocomplete_get_all_children($values['fid']);
  // Update the settings for this form + every children form.
  foreach ($fids as $fid) {
    // -> update form.
    db_update('search_autocomplete_forms')
      ->fields(array(
        'min_char'        => $values['min_char'],
        'max_sug'         => $values['max_sug'],
        'no_results'      => $values['no_results'],
        'auto_submit'     => $values['auto_submit'],
        'auto_redirect'   => $values['auto_redirect'],
        'theme'           => $values['theme'],
      ))
      ->condition('fid', $fid)
      ->execute();
  }
  // ###.
  drupal_clear_css_cache();
  $form_state['redirect'] = 'admin/config/search/search_autocomplete';
  $ok_query ? drupal_set_message(t("Configuration success!")) : drupal_set_message(t("An error has occurred while saving the settings. Please double check your settings!"), 'error');
}

// ///////////////////////////////////////////////////////////////////////// //
// //                        HELPER FUNCTIONS                             // //

// ----------------------------------------------------------------------------.
/**
 * Get the fids from all the children of the caller, excluding the caller.
 */
function _search_autocomplete_get_all_children($fid, &$items = array(), $depth = 0) {
  if ($depth) {
    $items[] = $fid;
  }

  $result = db_select('search_autocomplete_forms', 'f')
      ->fields('f')
      ->condition('parent_fid', $fid)
      ->execute()
      ->fetchAllAssoc('fid');

  foreach ($result as $item) {
    ++$depth;
    _search_autocomplete_get_all_children($item->fid, $items, $depth);
  }
  return $items;
}
