<?php
// $Id$

/**
 * @file
 * Administration page callbacks for the users_export module.
 *
 * @ingroup users_export
 * @{
 */

/**
 * Form builder. Configure my_module.
 *
 * @ingroup forms
 * @see system_settings_form()
 */

function users_export_form() {

  drupal_add_js(drupal_get_path('module', 'users_export') . '/users_export.js');

  $form = array();

  $type = variable_get('users_export_type', '.csv');
  $form['users_export_type'] = array(
    '#type' => 'select',
    '#title' => t('File format'),
    '#default_value' => $type,
    '#options' => array(
      '.csv' => t('Comma Separated (.csv)'),
      '.txt' => t('Tab Delimited (.txt)'),
      '.xls' => t('Excel (.xls)'),
    ),
  );

  //$form['options'] = array(
  //  '#type' => 'fieldset',
  //  '#title' => t('Options'),
  //  '#collapsible' => FALSE,
  //);
  //
  //$form['options']['field_end'] = array(
  //  '#type' => 'textfield',
  //  '#title' => t('Fields terminated by'),
  //  '#default_value' => ',',
  //  '#required' => TRUE,
  //);
  //
  //$form['options']['field_wrap'] = array(
  //  '#type' => 'textfield',
  //  '#title' => t('Fields enclosed by'),
  //  '#default_value' => '&quot;',
  //  '#required' => TRUE,
  //);
  //
  //$form['options']['field_escape'] = array(
  //  '#type' => 'textfield',
  //  '#title' => t('Fields escaped by'),
  //  '#default_value' => '\\',
  //  '#required' => TRUE,
  //);
  //
  //$form['options']['line_end'] = array(
  //  '#type' => 'textfield',
  //  '#title' => t('Lines terminated by'),
  //  '#default_value' => '\n',
  //  '#required' => TRUE,
  //);
  //
  $form['options']['users_export_header'] = array(
    '#type' => 'checkbox',
    '#title' => t('Put fields names in the first row'),
    '#default_value' => variable_get('users_export_header', TRUE),
  );

  $default = variable_get('users_export_filename', strtolower(preg_replace('/\W+/', '_', variable_get('site_name', 'users_export')) . '_users'));
  $form['users_export_filename'] = array(
    '#type' => 'textfield',
    '#title' => t('Filename to save as'),
    '#default_value' => $default,
    '#required' => TRUE,
    '#field_suffix' => $type,
  );

  $form['extension'] = array('#type' => 'hidden', '#value' => $type);

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Download File'),
  );


  return $form;
}

/**
 * Form submission handler
 */
function users_export_form_submit($form, &$form_state) {

  // Storage for next time
  variable_set('users_export_type', $form_state['values']['users_export_type']);
  variable_set('users_export_filename', $form_state['values']['users_export_filename']);
  variable_set('users_export_header', $form_state['values']['users_export_header']);

  // Load the users
  $query = db_select('users', 'u');
  $query
    ->fields('u', array('uid', 'name'))
    ->condition('status', 1)
    ->orderBy('uid');
  $query->addField('u', 'mail', 'email');
  $query->addField('u', 'created');
  $query->addField('u', 'access', 'last_access');
  $query->addField('u', 'login', 'last_login');
  $result = $query->execute();
  $date_format = 'c';
  foreach ($result as $row) {
    $row = (array) $row;
    $row['last_login']  = empty($row['last_login']) ? '' : date($date_format, $row['last_login']);
    $row['last_access'] = empty($row['last_access']) ? '' : date($date_format, $row['last_access']);
    $row['created']     = empty($row['created']) ? '' : date($date_format, $row['created']);

    drupal_alter('users_export_row', $row, $row['uid']);

    $output[] = $row;
  }

  //$format = new stdClass;
  //$format->eol    = $form_state['values']['line_end'];
  //$format->left   = $form_state['values']['field_wrap'];
  //$format->right  = $form_state['values']['field_wrap'];
  //$format->sep    = $form_state['values']['field_end'];

  if ($form_state['values']['users_export_header']) {
    $vars['header'] = array_keys($output[0]);
  }
  $vars['rows'] = $output;
  $vars['type'] = trim($form_state['values']['users_export_type'], '.');

  //output to the browser
  $filename = $form_state['values']['users_export_filename'] . $form_state['values']['extension'];

  drupal_alter('users_export_data', $vars);
  $output = theme('users_export_flatfile', $vars);

  drupal_add_http_header('Content-type', 'application/force-download');
  drupal_add_http_header('Content-Transfer-Encoding', 'Binary');
  drupal_add_http_header('Content-length', strlen($output));
  drupal_add_http_header('Content-disposition', 'attachment; filename=' . $filename);
  drupal_add_http_header('Pragma', 'no-cache');
  drupal_add_http_header('Expires', '0');
  exit($output);
}

/**
 * Formats export table data as a text delimited representation of table
 *
 * @param $header
 *   An array containing the table headers. Each element of the array can be
 *   either a localized string or an associative array with the following keys:
 *   - "data": The localized title of the table column.
 *   - "field": The database field represented in the table column (required if
 *     user is to be able to sort on this column).
 *   - "sort": A default sort order for this column ("asc" or "desc").
 *   - Any HTML attributes, such as "colspan", to apply to the column header cell.
 * @param $rows
 *   An array of table rows. Every row is an array of cells, or an associative
 *   array with the following keys:
 *   - "data": an array of cells
 *   - Any HTML attributes, such as "class", to apply to the table row.
 *
 *   Each cell can be either a string or an associative array with the following keys:
 *   - "data": The string to display in the table cell.
 *   - "header": Indicates this cell is a header.
 *   - Any HTML attributes, such as "colspan", to apply to the table cell.
 *
 *   Here's an example for $rows:
 *   @verbatim
 *   $rows = array(
 *     // Simple row
 *     array(
 *       'Cell 1', 'Cell 2', 'Cell 3'
 *     ),
 *     // Row with attributes on the row and some of its cells.
 *     array(
 *       'data' => array('Cell 1', array('data' => 'Cell 2', 'colspan' => 2)), 'class' => 'funky'
 *     )
 *   );
 *   @endverbatim
 * @param string $type
 *   Expecting 'csv', 'txt', 'xls'
 * @param bool $html
 *   Set to FALSE to apply strip_tags() on all cells
 * @param string $prefix
 *   A string to preceed the table data
 * @param string $suffix
 *   A string to follow the table data
 *
 * @return string
 *
 * @ingroup themeable
 */
function theme_users_export_flatfile($vars) {
  $output = '';

  $formatting = new stdClass();
  $format->eol = "\n";
  $format->html = $vars['html'];

  switch ($vars['type']) {
    case 'csv':
      $format->left   = '"';
      $format->right  = '"';
      $format->sep    = ',';
      $format->escape = '\\';
      break;

    case 'txt':
      $format->left   = '';
      $format->right  = '';
      $format->sep    = "\t";
      $format->escape = '\\';
      break;

    case 'xls':
      $format->left   = '"';
      $format->right  = '"';
      $format->sep    = "\t";
      $format->escape = '\\';
      break;
  }

  if (!empty($vars['prefix'])) {
    $output .= $vars['prefix'] . $format->eol;
  }

  // Format the header row:
  if (count($vars['header'])) {
    $output .= _users_export_collapse_row($vars['header'], $format);
  }

  // Format the rows:
  if (count($vars['rows'])) {
    foreach ($vars['rows'] as $row) {
      $output .= _users_export_collapse_row($row, $format);
    }
  }

  if (!empty($vars['suffix'])) {
    $output .= $vars['suffix'] . $format->eol;
  }
  return $output;
}

/**
 * Collapse a row into a line
 */
function _users_export_collapse_row($row, $format) {
  $output = '';

  // Check if we're dealing with a simple or complex row
  if (isset($row['data'])) {
    foreach ($row as $key => $value) {
      if ($key == 'data') {
        $cells = $value;
      }
    }
  }
  else {
    $cells = $row;
  }
  if (count($cells)) {
    foreach ($cells as $cell) {

      // Compress a complex cell
      if (is_array($cell)) {
        $cell = isset($cell['data']) ? $cell['data'] : '';
      }

      if (!$format->html) {
        $cell = strip_tags($cell);
      }

      // Escape the field wrappers as needed
      if (!empty($format->right)) {
        $cell = strstr($cell, $format->right) ? str_replace($format->right, $format->escape . $format->right, $cell) : $cell;
      }

      $output .= $format->left . $cell . $format->right . $format->sep;
    }
  }
  $output = trim($output, $format->sep) . $format->eol;
  return $output;
}

/** @} */ //end of group users_export1
