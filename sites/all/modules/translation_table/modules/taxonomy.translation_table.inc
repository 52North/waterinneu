<?php

/**
 * @file
 * Translation table for the taxonomy module.
 */

/**
 * Implementation of hook_translation_table_data().
 */
function taxonomy_translation_table_data() {
  $items['taxonomy'] = array(
    'title' => 'Taxonomy',
    'description' => 'Edit taxonomy translations',
    'form' => 'taxonomy_translation_table_taxonomy_form',
    'file' => 'modules/taxonomy.translation_table.inc',
  );

  return $items;
}

/**
 * Menu callback; Admin form for taxonomy translation.
 */
function taxonomy_translation_table_taxonomy_form($form, &$form_state) {
  $languages_selected = isset($_SESSION['translation_table']['languages_selected']) ? $_SESSION['translation_table']['languages_selected'] : locale_language_list('name', FALSE);
  $vid = isset($_SESSION['translation_table']['vid']) ? $_SESSION['translation_table']['vid'] : -1;

  $form['filter'] = taxonomy_translation_table_taxonomy_filter($languages_selected, $vid);
  $form['filtered_form'] = taxonomy_translation_table_taxonomy_filtered_form($languages_selected, $vid);
  $form['#submit'][] = 'taxonomy_translation_table_taxonomy_form_submit';
  $form['#submit'][] = 'translation_table_submit_translations';
  return $form;
}

/**
 * Taxonomy filter.
 */
function taxonomy_translation_table_taxonomy_filter($languages_selected, $vid) {
  $form['languages_selected'] = array(
    '#type' => 'select',
    '#title' => t('Languages'),
    '#description' => t('Select the languages to display.'),
    '#options' => locale_language_list('name', TRUE),
    '#default_value' => array_keys($languages_selected),
    '#multiple' => TRUE,
  );

  $vocabulary_options[0] = t('- Display all taxonomy strings -');
  $vocabulary_options[-1] = t('- Display vocabulary strings -');

  if (module_exists('taxonomy')) {
    if ($vocabularies = taxonomy_get_vocabularies()) {
      foreach ($vocabularies as $key => $vocabulary) {
        $vocabulary_options[$key] = $vocabulary->name;
      }
    }
  }

  $form['vid'] = array(
    '#type' => 'select',
    '#title' => t('Vocabulary'),
    '#description' => t('Select the vocabulary.'),
    '#options' => $vocabulary_options,
    '#default_value' => $vid,
  );

  $form['filter'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
  );

//  $form['#theme'] = 'translation_table_filter';
  return $form;
}

/**
 * Form for taxonomy translation.
 * Note: If term and vocabulary strings are not in the locales_source table,
 * then they won't be displayed.
 *
 * @param $languages
 *   languages to translate to
 * @param $vid
 *   -1: show vocabulary names only
 *    0: show all
 *    else: filter by vocabulary ID
 */
function taxonomy_translation_table_taxonomy_filtered_form($languages, $vid) {
  $header = _translation_table_get_header($languages);

  switch ($vid) {
    case 0:
      $query = db_select('locales_source', 'ls');
      $query->fields('ls', array('lid', 'source', 'location'))
        ->extend('PagerDefault')
        ->extend('TableSort')
        ->condition('ls.textgroup', 'taxonomy')
        ->orderByHeader($header)
        ->limit(50);
      $result = $query->execute();
      break;

    case -1:
      $query = db_select('locales_source', 'ls');
      $query->join('i18n_string', 's', 'ls.lid = s.lid');
      $query->fields('ls', array('lid', 'source', 'location'))
        ->extend('PagerDefault')
        ->extend('TableSort')
        ->condition('s.type', 'vocabulary')
        ->orderByHeader($header)
        ->limit(50);
      $result = $query->execute();
      break;

    default:
      
      // FIXME: D7
//      $subselect = db_query("SELECT td.tid FROM {taxonomy_term_data} td WHERE td.vid = :vid", array("vid" => $vid));
      $subselect = db_select('taxonomy_term_data', 'td')
        ->fields('td', array('tid'))
        ->condition('td.vid', $vid);
      
      $query = db_select('locales_source', 'ls');
      $query->join('i18n_string', 's', 'ls.lid = s.lid');
      $query->fields('ls', array('lid', 'source', 'location'))
        ->extend('PagerDefault')
        ->extend('TableSort')
        ->condition('s.type', 'term')
        ->condition('s.objectid', $subselect, 'IN')
        ->orderByHeader($header)
        ->limit(50);
      $result = $query->execute();
      break;
  }

  $form['strings']['#tree'] = TRUE;
//  $form['#cache'] = TRUE;
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
 * Submit handler for the taxonomy translation form.
 */
function taxonomy_translation_table_taxonomy_form_submit($form, &$form_state) {
  switch ($form_state['triggering_element']['#id']) {
    case 'edit-filter--2':
    case 'edit-filter':
    case 'edit-submit':
      $_SESSION['translation_table']['vid'] = $form_state['values']['vid'];
      $_SESSION['translation_table']['languages_selected'] = array_intersect_key(locale_language_list('name', TRUE), $form_state['values']['languages_selected']);
      break;
  }
}
