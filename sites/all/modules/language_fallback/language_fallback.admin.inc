<?php
/**
 * @file
 * Alter the admin language form.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Setup language fallback for existing or new languages.
 */
function language_fallback_form_locale_languages_edit_form_alter(&$form, &$form_state, $form_id) {
  // Make AJAX to work on "add language" form.
  $langcode = isset($form['langcode_view']) ? $form['langcode']['#value'] : NULL;

  // Add select to create/edit form.
  $key = $form_id == 'locale_languages_predefined_form' ? 'language list' : 'custom language';
  $form['_key_'] = array(
    '#type' => 'value',
    '#value' => $key,
  );

  $form[$key]['fallback'] = array(
    '#type' => 'fieldset',
    '#title' => t('Language fallback'),
    '#tree' => TRUE,
    '#prefix' => '<div id="countries-fieldset-wrapper">',
    '#suffix' => '</div>',
  );

  $countries = language_fallback_get_countries();

  if (empty($form_state[$key]['fallback']['countries'])) {
    $form_state[$key]['fallback']['countries'] = array(LANGUAGE_FALLBACK_ALL_COUNTRIES);

    if ($langcode) {
      // Get all countries that we have a fallback for this language.
      $result = db_select('language_fallback', 'f')
          ->fields('f', array('country'))
          ->condition('language', $langcode, '=')
          ->condition('country', LANGUAGE_FALLBACK_ALL_COUNTRIES, '<>')
          ->execute();
      while ($c = $result->fetchField()) {
        $form_state[$key]['fallback']['countries'][] = $c;
      }
    }
  }

  foreach ($form_state[$key]['fallback']['countries'] as $country) {
    language_fallback_get_fallback_form($form, $form_state, $key, $country, $countries[$country]);

    // Unset countries that are in use.
    unset($countries[$country]);
  }

  if (count($countries) > 0) {
    $form[$key]['fallback']['country'] = array(
      '#type' => 'select',
      '#options' => $countries,
    );

    $form[$key]['fallback']['add_country'] = array(
      '#type' => 'submit',
      '#value' => t('Add country specific fallback'),
      '#submit' => array('language_fallback_country_add_another'),
      '#ajax' => array(
        'callback' => 'language_fallback_country_add_remove_ajax_callback',
        'wrapper' => 'countries-fieldset-wrapper',
      ),
    );
  }

  $form['#submit'][] = 'language_fallback_country_add_language_submit';
}

/**
 * Get the fallback form.
 */
function language_fallback_get_fallback_form(&$form, &$form_state, $key, $ccode = LANGUAGE_FALLBACK_ALL_COUNTRIES, $country = FALSE, $scope = 'admin') {
  $options = &drupal_static(__FUNCTION__);
  $langcode = isset($form['langcode_view']) ? $form['langcode']['#value'] : NULL;
  if (!$options) {
    // Cache the language options.
    $default_lang = language_default();
    $languages = language_list();
    $options = locale_language_list();

    // Alter label of default language.
    if (isset($options[$default_lang->language])) {
      $options[$default_lang->language] = t('Default language (@lang)', array('@lang' => $default_lang->name));
      $options = array('' => t('Select language')) + $options;
    }

    // Add native name.
    foreach ($options as $k => $option) {
      if (!empty($languages[$k]->native)) {
        $options[$k] .= " ({$languages[$k]->native})";
      }
    }
  }

  $description = '';
  if ($ccode == LANGUAGE_FALLBACK_ALL_COUNTRIES) {
    $description = (!variable_get('language_fallback_country', FALSE) ? t('Enable country specific fallback to create different fallbacks for each country.') : t('This is default fallback chain for all countries. It will be used only if no country specific fallback is available.'));
  }
  $form[$key]['fallback'][$ccode] = array(
    '#type' => 'fieldset',
    '#title' => check_plain($country),
    '#prefix' => '<div id="country-' . $ccode . '-fieldset-wrapper">',
  // This is unique to each country fallback chain.
    '#suffix' => '</div>',
    '#description' => $description,
  );

  $chain = ($langcode ? language_fallback_get_chain($langcode, $ccode, ($scope == 'admin')) : array());

  if (empty($form_state[$key]['fallback'][$ccode]['chain_length'])) {
    $form_state[$key]['fallback'][$ccode]['chain_length'] = count($chain) + 1;
  }

  for ($i = 0; $i < $form_state[$key]['fallback'][$ccode]['chain_length']; $i++) {
    $form[$key]['fallback'][$ccode][$i] = array(
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => ($i < count($chain) ? $chain[$i] : ''),
    );
  }

  /*
   * WARNING!
   * Due to the nature of AJAX FAPI the submit button value MUST be unique!
   * See this: https://drupal.org/node/1342066
   * Or try this workaround: http://stackoverflow.com/a/6521617/899092\
   *
   * This also applies to the "remove" button below.
   */
  $form[$key]['fallback'][$ccode]['add'] = array(
    '#type' => 'submit',
    '#value' => ($country ? t('Add another language for !country', array('!country' => $country)) : t('Add another language')),
    '#submit' => array('language_fallback_country_add_language_add_another'),
  // This is shared across all countries.
    '#ajax' => array(
      'callback' => 'language_fallback_country_add_language_ajax_callback',
  // This is shared across all countries.
      'wrapper' => 'country-' . $ccode . '-fieldset-wrapper',
  // This is unique to each country fallback chain.
    ),
  );

  if ($form_state[$key]['fallback'][$ccode]['chain_length'] > 1) {
    $form[$key]['fallback'][$ccode]['remove_one'] = array(
      '#type' => 'submit',
      '#value' => ($country ? t('Remove last language for !country', array('!country' => $country)) : t('Remove last language')),
      '#submit' => array('language_fallback_country_remove_last_submit'),
    // This is shared across all countries.
      '#ajax' => array(
        'callback' => 'language_fallback_country_add_language_ajax_callback',
    // This is shared across all countries.
        'wrapper' => 'country-' . $ccode . '-fieldset-wrapper',
    // This is unique to each country fallback chain.
      ),
    );
  }

  if ($ccode != LANGUAGE_FALLBACK_ALL_COUNTRIES) {
    $form[$key]['fallback'][$ccode]['remove'] = array(
      '#type' => 'submit',
      '#value' => t('Remove fallback chain for !country', array('!country' => $country)),
      '#submit' => array('language_fallback_country_remove_chain'),
    // This is shared across all countries.
      '#ajax' => array(
        'callback' => 'language_fallback_country_add_remove_ajax_callback',
    // This is shared across all countries.
        'wrapper' => 'countries-fieldset-wrapper',
      ),
    );
  }
}

/**
 * Ajax submit function for "Remove fallback chain for ..." button.
 */
function language_fallback_country_remove_chain($form, &$form_state) {
  $key = $form_state['values']['_key_'];
  // Country to remove.
  $remove = $form_state['triggering_element']['#parents'][1];
  if (($index = array_search($remove, $form_state[$key]['fallback']['countries'])) !== FALSE) {
    // Remove country.
    unset($form_state[$key]['fallback']['countries'][$index]);
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Callback function for ajax calls that add country specific fallback fieldset.
 */
function language_fallback_country_add_remove_ajax_callback($form, $form_state) {
  $key = $form_state['values']['_key_'];
  return $form[$key]['fallback'];
}

/**
 * Ajax submit function for "Add country specific fallback" button.
 */
function language_fallback_country_add_another($form, &$form_state) {
  $key = $form_state['values']['_key_'];
  $form_state[$key]['fallback']['countries'][] = $form_state['values']['fallback']['country'];
  $form_state['rebuild'] = TRUE;
}

/**
 * Callback function for ajax calls for select element to the country.
 */
function language_fallback_country_add_language_ajax_callback($form, $form_state) {
  $key = $form_state['values']['_key_'];
  /*
   * See language_fallback_country_add_language_add_another() function
   * for explanation of the followin line:
   */
  $id = count($form_state['triggering_element']['#parents']) - 2;
  $country = $form_state['triggering_element']['#parents'][$id];

  return $form[$key]['fallback'][$country];
}

/**
 * Ajax submit function for "Remove last language from ..." button.
 *
 * @see language_fallback_country_add_language_add_another()
 */
function language_fallback_country_remove_last_submit($form, &$form_state) {
  $key = $form_state['values']['_key_'];

  // @see function language_fallback_country_add_language_add_another().
  $id = count($form_state['triggering_element']['#parents']) - 2;
  $country = $form_state['triggering_element']['#parents'][$id];
  $form_state[$key]['fallback'][$country]['chain_length']--;

  $form_state['rebuild'] = TRUE;
}

/**
 * Ajax submit function for "Add another language to ..." button.
 */
function language_fallback_country_add_language_add_another($form, &$form_state) {

  $key = $form_state['values']['_key_'];

  /*
   * The element that triggered this callback is "described" here:
   * $form_state['triggering_element'].
   * We know that this is an array that looks like this:
   * array(
   *  0 => 'fallback',
   *  1 => [COUNTRY],
   *  2 => 'add'
   * );
   * So we need the '1' index to know wchich country needs another
   * select element.
   */
  $id = count($form_state['triggering_element']['#parents']) - 2;
  $country = $form_state['triggering_element']['#parents'][$id];
  $form_state[$key]['fallback'][$country]['chain_length']++;

  $form_state['rebuild'] = TRUE;
}

/**
 * Submit callback.
 */
function language_fallback_country_add_language_submit($form, &$form_state) {
  $fallbacks = $form_state['values']['fallback'];
  $language = $form_state['values']['langcode'];

  // Delete old entries. New entries will be added only if needed.
  db_delete('language_fallback')->condition('language', $language, '=')->execute();
  variable_del('locale_custom_strings_' . $language);
  $set_variable = FALSE;

  foreach ($fallbacks as $country => $fallback) {
    // Omit unwanted values.
    if (!is_array($fallback)) {
      continue;
    }

    // Fix fallback array.
    $fixed = language_fallback_fix_chain($fallback, $language);

    if (count($fixed) > 0) {
      // This stores our settings.
      db_insert('language_fallback')
        ->fields(
          array(
            'language' => $language,
            'country' => $country,
            'chain' => implode('|', $fixed),
          )
        )
        ->execute();
      $set_variable = TRUE;
    }
  }

  if ($set_variable) {
    // This tells drupal to use our fallback mechanism for string translation.
    variable_set('locale_custom_strings_' . $language, new localeWithFallback($language));
  }
}

/**
 * Sanitize fallback chain to remove duplicates and default language.
 *
 * @param array $fallback
 *   Array of fallback languages.
 * @param string $language
 *   Language code.
 *
 * @return array
 *   Clean fallback array.
 */
function language_fallback_fix_chain(array $fallback, $language = LANGUAGE_NONE) {
  $valid = &drupal_static(__FUNCTION__);

  if (empty($valid)) {
    $valid = locale_language_list();
  }

  // Fix fallback array.
  $fixed = array();
  foreach ($fallback as $id => $lang) {
    // Accept only valid languages.
    if (!isset($valid[$lang])) {
      continue;
    }

    // Prevent deadlocks.
    if ($lang == $language) {
      continue;
    }

    // Ignore languages that are already added.
    if (array_search($lang, $fixed) !== FALSE) {
      continue;
    }

    // Add language to the chain.
    $fixed[] = $lang;
  }
  return $fixed;
}
