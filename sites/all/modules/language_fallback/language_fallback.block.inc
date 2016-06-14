<?php

/**
 * @file
 * Block hooks.
 */

/**
 * Implements hook_block_info().
 */
function language_fallback_block_info() {
  $blocks['country_selection'] = array(
    'info' => t('Country selection'),
    'cache' => DRUPAL_NO_CACHE,
  );

  $blocks['language_fallback'] = array(
    'info' => t('Language fallback selection'),
    'cache' => DRUPAL_NO_CACHE,
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function language_fallback_block_view($delta = '') {
  switch ($delta) {
    case 'country_selection':
      $block['subject'] = t('Select country');
      $block['content'] = drupal_get_form('language_fallback_country_select_block_form');
      return $block;

    case 'language_fallback':
      $block['subject'] = t('Select language fallback');
      $block['content'] = drupal_get_form('language_fallback_fallback_select_block_form');
      return $block;
  }
}

/**
 * Callback to generate form for user fallback block.
 *
 * @param unknown $form_id
 * @param unknown $form_state
 * @return multitype:string NULL
 */
function language_fallback_fallback_select_block_form($form_id, &$form_state) {
  $form = array();
  $key = '_fb_';
  $form['_key_'] = array('#value' => $key);
  $form[$key] = array('#tree' => 'true');

  /* 'key', langcode_view' and 'langcode' are to satisfy form building function.
   * See language_fallback_get_fallback_form function for details.
   */
  $form['langcode_view'] = array();
  $form['langcode'] = array('#value' => LANGUAGE_NONE);

  // Buld language fallback form with our reusable function.
  language_fallback_get_fallback_form($form, $form_state, $key, LANGUAGE_FALLBACK_ALL_COUNTRIES, FALSE, 'block');

  // Get information about current fallback chain
  $description = '';
  $prop = 'name'; // Change to "native" to use native names;
  $user_chain = language_fallback_get_user_chain();
  if (empty($user_chain)) {
    global $language;
    $global_chain = language_fallback_get_chain($language->language);
    $all_languages = locale_language_list($prop, TRUE);
    $display_chain = array();
    foreach ($global_chain as $langcode) {
      $display_chain[] = $all_languages[$langcode];
    }

    if (count($display_chain) > 0) {
      $description = t('Language fallback for content unavailable in %current is %fallback. Set your own fallback here.', array('%current' => $language->{$prop}, '%fallback' => implode(" => ", $display_chain)));
    }
    else {
      $description = t('Language fallback for content unavailable in %current is not set. Set your own fallback here.', array('%current' => $language->{$prop}));
    }
  }
  else {
    $description = t('Change language fallback for content unavailable in %current.', array('%current' => $language->{$prop}));
  }

  /*
   * Replace description from chain selection fieldset
   * with information about currently defined fallback
   */
  $form[$key]['fallback'][LANGUAGE_FALLBACK_ALL_COUNTRIES]['#description'] = $description;

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save')
  );

  return $form;
}

/**
 * Callback function for user fallback selection form submit.
 *
 * @param unknown $form
 * @param unknown $form_state
 */
function language_fallback_fallback_select_block_form_submit($form, $form_state) {
  // Read and fix user defined fallback chain.
  $key = $form['_key_']['#value'];
  $chain = language_fallback_fix_chain($form_state['values'][$key]['fallback'][LANGUAGE_FALLBACK_ALL_COUNTRIES]);

  language_fallback_set_user_chain($chain);
}

/**
 * Callback to generate form for country selection block.
 *
 * @param unknown $form_id
 * @param unknown $form_state
 * @return multitype:multitype:NULL  multitype:string NULL  multitype:string NULL unknown
 */
function language_fallback_country_select_block_form($form_id, $form_state) {

  /* There is no need for fancy AJAXification.
   * The page reload is needed anyway to view
   * content in another language.
   */
  $form = array();

  $countries = language_fallback_get_countries();

  if (count($countries) < 2) {
    $form[] = array('#markup' => t('Country selection is disabled'));
  }
  else {
    $form['country'] = array(
      '#type' => 'select',
      '#options' => $countries,
      '#default_value' => language_fallback_get_country()
    );
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save')
    );
  }

  return $form;
}

/**
 * Callback function for user country selection form submit.
 *
 * @param unknown $form
 * @param unknown $form_state
 */
function language_fallback_country_select_block_form_submit($form, $form_state) {
  language_fallback_set_country($form_state['values']['country']);
}
