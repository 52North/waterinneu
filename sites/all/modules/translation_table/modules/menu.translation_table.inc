<?php

/**
 * @file
 * Translation table for the menu module.
 */

/**
 * Implementation of hook_translation_table_data().
 */
function menu_translation_table_data() {
  $items['menu'] = array(
    'title' => 'Menu',
    'description' => 'Edit menu translations',
    'form' => 'menu_translation_table_menu_form',
    'file' => 'modules/menu.translation_table.inc',
  );

  return $items;
}

/**
 * Menu callback; Admin form for menu translation.
 */
function menu_translation_table_menu_form($form, &$form_state) {
  $languages_selected = isset($_SESSION['translation_table']['languages_selected']) ? $_SESSION['translation_table']['languages_selected'] : locale_language_list('name', FALSE);

  $form['filter'] = menu_translation_table_menu_filter($languages_selected);
  $form['filtered_form'] = menu_translation_table_menu_filtered_form($languages_selected);
  $form['#submit'][] = 'menu_translation_table_menu_form_submit';
  $form['#submit'][] = 'translation_table_submit_translations';
  return $form;
}

/**
 * Menu filter.
 */
function menu_translation_table_menu_filter($languages_selected) {
  $form['languages_selected'] = array(
    '#type' => 'select',
    '#title' => t('Languages'),
    '#description' => t('Select the languages to display.'),
    '#options' => locale_language_list('name', TRUE),
    '#default_value' => array_keys($languages_selected),
    '#multiple' => TRUE,
  );

  $form['filter'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
  );

  $form['#theme'] = 'translation_table_filter';
  return $form;
}

/**
 * Form for menu translation.
 * Note: If the menu string is not in the locales_source table, then it won't be
 * displayed.
 *
 * @param $languages
 *   languages to translate to
 */
function menu_translation_table_menu_filtered_form($languages) {
  $header = _translation_table_get_header($languages);
    
  $query = db_select('locales_source', 'ls');
  $query->fields('ls', array('lid', 'source', 'location'))
    ->extend('PagerDefault')
    ->extend('TableSort')
    ->condition('ls.textgroup', 'menu')
    ->orderByHeader($header)
    ->limit(50);
  $result = $query->execute();
  

  $form['strings']['#tree'] = TRUE;
  $form['#cache'] = FALSE;

  $form['header'] = array(
    '#type' => 'value',
    '#value' => $header,
  );

  while ($source = $result->fetch()) {
    if (strlen(trim($source->source)) > 0) {
      $form['strings'][$source->lid] = _translation_table_row($source, $languages);
    }
  }

  $form['languages'] = array(
    '#type' => 'value',
    '#value' => $languages,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  $form['pager'] = array('#markup' => theme('pager'));
  $form['#theme'] = 'translation_table';
  return $form;
}

/**
 * Submit handler for the menu translation form.
 */
function menu_translation_table_menu_form_submit($form, &$form_state) {
  switch ($form_state['triggering_element']['#id']) {
    case 'edit-filter--2':
    case 'edit-filter':
    case 'edit-submit':
      $_SESSION['translation_table']['languages_selected'] = array_intersect_key(locale_language_list('name', TRUE), $form_state['values']['languages_selected']);
      break;
  }
}

