<?php

/**
 * @file
 * Translation table for fields
 */

/**
 * Implementation of hook_translation_table_data().
 */
function field_translation_table_data() {
  $items['field'] = array(
    'title' => 'Field',
    'description' => 'Edit field translations',
    'form' => 'field_translation_table_form',
    'file' => 'modules/field.translation_table.inc',
  );

  return $items;
}

/**
 * Menu callback; Admin form for field translation.
 */
function field_translation_table_form($form, &$form_state) {
  $languages_selected = isset($_SESSION['translation_table']['languages_selected']) ? $_SESSION['translation_table']['languages_selected'] : locale_language_list('name', FALSE);
  $bundle = isset($_SESSION['translation_table']['bundle']) ? $_SESSION['translation_table']['bundle'] : 0;

  $form['filter'] = field_translation_table_filter($languages_selected, $bundle);
  $form['filtered_form'] = field_translation_table_filtered_form($languages_selected, $bundle);
  $form['#submit'][] = 'field_translation_table_form_submit';
  $form['#submit'][] = 'translation_table_submit_translations';
  return $form;
}

/**
 * Field filter.
 */
function field_translation_table_filter($languages_selected, $bundle) {
  $form['languages_selected'] = array(
    '#type' => 'select',
    '#title' => t('Languages'),
    '#description' => t('Select the languages to display.'),
    '#options' => locale_language_list('name', TRUE),
    '#default_value' => array_keys($languages_selected),
    '#multiple' => TRUE,
  );

  $res = db_query("SELECT DISTINCT objectid FROM {i18n_string} WHERE textgroup = 'field'");

  $scope_options = array(0 => t('- All -'));
  while ($bundle_opt = $res->fetchField()) {
    $scope_options[$bundle_opt] = $bundle_opt;
  }

  $form['bundle'] = array(
    '#type' => 'select',
    '#title' => t('Attached to'),
    '#description' => t('Select the kind of strings to display.'),
    '#options' => $scope_options,
    '#default_value' => $bundle,
  );

  $form['filter'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
  );

  $form['#theme'] = 'translation_table_filter';
  return $form;
}

/**
 * Form for field translation.
 *
 * @param $languages
 *   languages to translate to
 * @param $bundle
 */
function field_translation_table_filtered_form($languages, $bundle) {
  $header = _translation_table_get_header($languages);

  switch ($bundle) {
    case '0':
     $query = db_select('locales_source', 'ls');
     $query->fields('ls', array('lid', 'source', 'location'))
       ->extend('PagerDefault')
       ->extend('TableSort')
       ->condition('ls.textgroup', 'field')
       ->orderByHeader($header)
       ->limit(50);
     $result = $query->execute();
    break;

    default:
      $query = db_select('locales_source', 'ls');
      $query->join('i18n_string', 'i18ns', 'ls.lid = i18ns.lid');
      $query->fields('ls', array('lid', 'source', 'location'))
        ->extend('PagerDefault')
        ->extend('TableSort')
        ->condition('ls.textgroup', 'field')
        ->condition('i18ns.objectid', $bundle);
      // $query->orderByHeader($header);
      // $query->limit(50);
      
      $result = $query->execute();
      break;
  }

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
 * Submit handler for the field translation form.
 */
function field_translation_table_form_submit($form, &$form_state) {
  switch ($form_state['clicked_button']['#id']) {
    case 'edit-filter--2':
    case 'edit-filter':
    case 'edit-submit':
      $_SESSION['translation_table']['bundle'] = $form_state['values']['bundle'];
      $_SESSION['translation_table']['languages_selected'] = array_intersect_key(locale_language_list('name', TRUE), $form_state['values']['languages_selected']);
      break;
  }
}
