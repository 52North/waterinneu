<?php

/**
 * @file
 * Search Autocomplete
 * Add a new form to Search Autocomplete form list.
 *
 * Sponsored by:
 * www.axiomcafe.fr
 */

/**
 * MENU CALLBACK: Define the page to add a form.
 *
 * @return array
 *   A rendered form
 */
function search_autocomplete_form_add() {

  $selector = '';

  if (isset($_REQUEST['selector'])) {
    $selector = urldecode($_REQUEST['selector']);
  }
  $form = array();
  // ------------------------------------------------------------------.
  $form['title'] = array(
    '#title'          => t('Title'),
    '#description'    => 'Please enter a title for this form',
    '#type'           => 'textfield',
    '#default_value'  => '',
    '#maxlength'      => 255,
    '#required'       => TRUE,
  );
  $descr = t('Enter a valid query selector for the form. This should be an id or a class surrounding the input box.') . '<br/>' . t('Do not include input. In case of a doubt, refer to the <a href="http://drupal-addict.com/nos-projets/search-autocomplete">documentation</a>');
  $form['selector'] = array(
    '#title'          => t('Selector'),
    '#description'    => $descr,
    '#type'           => 'textfield',
    '#default_value'  => $selector,
    '#maxlength'      => 255,
    '#required'       => TRUE,
  );
  // Submit button.
  $form['submit'] = array(
    '#type'           => 'submit',
    '#value'          => t('Save'),
  );
  return $form;
}

// ----------------------------------------------------------------------------.
/**
 * Implements hook_submit().
 *
 * Save the new form in database.
 */
function search_autocomplete_form_add_submit($form, &$form_state) {
  // So far so good!
  $ok_query = TRUE;

  // Get the form values.
  $values = $form_state['values'];

  // Check if already existing records.
  $result = db_select('search_autocomplete_forms', 'f')
    ->fields('f')
    ->condition('title', $values['title'])
    ->condition('selector', $values['selector'])
    ->execute()
    ->fetchAll();

  foreach ($result as $selector) {
    drupal_set_message(t("The title or the selector @selector already exists. Please choose another one.", array('@selector' => $selector)), 'error');
    return;
  }

  // Insert the new form in database.
  $fid = db_insert('search_autocomplete_forms')
    ->fields(array(
      'title'       => $values['title'],
      'selector'    => $values['selector'],
      'no_results'  => json_encode(array( // manually add no_results default
        'label' => t('No results found for [search-phrase]. Click to perform full search.'),
        'value' => '[search-phrase]',
        'link'  => '',
        'group' => array(
          'group_id' => 'no_results',
        ),
      )),
      'all_results'  => json_encode(array( // manually add all_results default
        'label' => t('View all results for [search-phrase].'),
        'value' => '[search-phrase]',
        'link'  => '',
        'group' => array(
          'group_id' => 'all_results',
        ),
      )),
    ))
    ->execute();

  // Redirect to configuration page.
  $form_state['redirect'] = 'admin/config/search/search_autocomplete/' . $fid . '/configure';

  // Give a return to the user.
  $ok_query ? drupal_set_message(t('The form has been created successfully!') . '<br/>' . t('Please check its configuration.')) : drupal_set_message(t("An error has occurred while creating the form. Please, double check your settings!"), 'error');
}