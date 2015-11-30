<?php

/**
 * @file
 * The functions.
 */

/**
 * Theme function for the translation table.
 *
 * @ingroup themeable
 */
function theme_translation_table($variables) {
  $form = $variables['form'];
  $rows = array();
  $header = $form['header']['#value'];
  $languages = $form['languages']['#value'];

  foreach (element_children($form['strings']) as $key) {
    // Build the table row.
    $row = array();
    $row['data'][] = array('data' => drupal_render($form['strings'][$key]['source']), 'class' => 'translation-source');

    foreach ($languages as $lang_code => $lang_name) {
      $row['data'][] = array('data' => drupal_render($form['strings'][$key][$lang_code]), 'class' => 'translation-'. $lang_code);
    };
    $location = explode(':', $form['strings'][$key]['location']['#value']);
    if (count($location) == 4) {
      switch ($location[1]) {
        case 'term':
          $row['data'][] = l(t('Edit source'), 'admin/content/taxonomy/edit/term/'. $location[1], array('attributes' => array('title' => t('Edit term (@property)', array('@property' => t($location[2]))))));
          break;

        case 'vocabulary':
          $row['data'][] = l(t('Edit source'), 'admin/content/taxonomy/edit/vocabulary/'. $location[1], array('attributes' => array('title' => t('Edit vocabulary (@property)', array('@property' => t($location[2]))))));
          break;

        case 'item':
          $row['data'][] = l(t('Edit source'), 'admin/build/menu/item/'. $location[1] .'/edit', array('attributes' => array('title' => t('Edit menu item (@property)', array('@property' => t($location[2]))))));
          break;

        case 'type':
          $node_types = node_type_get_names();
          $node_type = isset($node_types[$location[1]]) ? $node_types[$location[1]] : $location[1];
          $row['data'][] = l(t('Edit source'), 'admin/content/node-type/'. $location[1], array('attributes' => array('title' => t('Edit @node_type (@property)', array('@node_type' => $node_type, '@property' => t($location[2]))))));
          break;

        default:
          $row['data'][] = '';
      }
    }
    else {
      $row['data'][] = '';
    }
    $row['data'][] = l(t('Translate'), 'admin/config/regional/translate/edit/'. $key);
    $row['data'][] = l(t('Delete string'), 'admin/config/regional/translate/delete/'. $key);

    $rows[] = $row;
  }
  
  $output = theme('table', array(
    'header' => $header, 
    'rows'   => $rows, 
    'attributes' => array('id' => 'translation-table')
  ));
  
  if ($form['pager']['#markup']) {
    $output .= drupal_render($form['pager']);
  }
  $output .= drupal_render_children($form);

  drupal_add_css(drupal_get_path('module', 'translation_table') .'/css/translation-table-admin.css');
  return $output;
}

/**
 * Theme function for the basic filter form.
 *
 * @ingroup themeable
 */
function theme_translation_table_filter($variables) {
  $form = $variables['form'];
  $output = '<div id="translation-table-filter">';
  foreach (element_children($form) as $key) {
    $attributes = drupal_attributes(array(
      'id' => 'translation-table-'. str_replace('_', '-', $key) .'-filter',
      'class' => 'translation-table-filter',
    ));
    $output .= "<div $attributes>";
    $output .= drupal_render($form[$key]);
    $output .= '</div>';
  }
  $output .= '</div>';

  return $output;
}

