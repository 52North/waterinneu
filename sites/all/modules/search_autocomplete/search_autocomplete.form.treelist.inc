<?php

/**
 * @file
 * Search Autocomplete
 * Display the list of form to autocomplete and theme it as a draggable table.
 *
 * Sponsored by:
 * www.axiomcafe.fr
 */

// ---------------------------------------------------------------------------
/**
 * Menu Callback: create the form to list the search forms.
 *
 * @return array
 *   the form
 */
function search_autocomplete_treelist_form($form, &$form_state) {
  // Base URL for this module configurations.
  $base = "admin/config/search/search_autocomplete";

  // Get all forms ordered as a tree.
  $data = _search_autocomplete_get_items();
  $form['my_items'] = array();
  $form['my_items']['#tree'] = TRUE;

  // For each items to render in the form.
  foreach ($data as $values) {
    $fid            = $values->fid;
    $title          = $values->title;
    $weight         = $values->weight;
    $enabled        = $values->enabled;
    $parent_fid     = $values->parent_fid;
    $translite      = variable_get('sa_translite', TRUE);
    $admin_helper   = variable_get('sa_admin_helper', TRUE);

    $form['my_items'][$fid] = array(
      'title' => array(
        '#type' => 'item',
        '#title' => check_plain($title),
      ),
       // Defines if the autocompletion is enabled for this item.
      'enabled' => array(
        '#type' => 'checkbox',
        '#default_value' => $enabled,
      ),
      'operations' => array(
        'configure' => array(
          '#type' => 'item',
          '#title' => filter_xss(l(t('configure'), "$base/$fid/configure")),
        ),
        'delete' => array(
          '#type' => 'item',
          '#title' => filter_xss(l(t('delete'), "$base/$parent_fid/delete/$fid")),
        ),
      ),
      // Weight of the item in hierarchy.
      'weight' => array(
        '#type' => 'weight',
        '#delta' => count($data),
        '#default_value' => $weight,
      ),
      // The individual id if the item.
      'fid' => array(
        '#type' => 'hidden',
        '#value' => $fid,
      ),
      // Id of the parent item in hierarchy.
      'parent_fid' => array(
        '#type' => 'textfield',
        '#default_value' => $parent_fid,
      ),
      // Depth of the item.
      '#depth' => $values->depth,
    );
  }

  // Transliteration option settings.
  $title = t('Translite special characters.') . ' (' . t('Requires <a href="https://drupal.org/project/transliteration">Transliteration</a> module.') . ' :  ';
  $title .= module_exists('transliteration') ? '<b>' . t('Installed') . '</b>' : '<b>' . t('Not installed') . '</b>';
  $title .= ')';
  $form['translite'] = array(
    '#type'           => 'checkbox',
    '#title'          => $title,
    '#description'    => t('If enabled, the user will be suggested with all special characters suggestions when using standard characters. In other word, when entering "foo", suggestions may contain also "f&oacute;&ocirc;bar", "fo&otilde;bar", ...'),
    '#disabled'       => module_exists('transliteration') ? FALSE : TRUE,
    '#default_value'  => $translite,
  );

  // Use admin helper tool option settings.
  $title = t('Use autocompletion helper tool for Search Autocomplete administrators.');
  $form['admin_helper'] = array(
    '#type'           => 'checkbox',
    '#title'          => $title,
    '#description'    => t('If enabled, user with "administer Search Autocomplete" permission will be able to use admin helper tool on input fields (recommended).'),
    '#default_value'  => $admin_helper,
  );

  // Submit buton.
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

// ----------------------------------------------------------------------------.
/**
 * Implements hook_submit().
 *
 * Save the changes in the database.
 */
function search_autocomplete_treelist_form_submit($form, &$form_state) {
  // Update the database with the new values.
  foreach ($form_state['values']['my_items'] as $item) {
    db_update('search_autocomplete_forms')
      ->fields(array(
        'weight' => $item['weight'],
        'parent_fid' => $item['parent_fid'],
        'enabled' => $item['enabled'],
      ))
      ->condition('fid', $item['fid'])
      ->execute();
  }
  variable_set('sa_translite', $form_state['values']['translite']);
  variable_set('sa_admin_helper', $form_state['values']['admin_helper']);
  drupal_set_message(t('Configuration success'));
}

// ---------------------------------------------------------------------------.
/**
 * CALLBACK: Theme function for this treelist form.
 */
function theme_search_autocomplete_treelist_form($variables) {
  $form = $variables['form'];

  drupal_add_tabledrag('my-draggable-table', 'order', 'sibling', 'weight-group');
  drupal_add_tabledrag('my-draggable-table', 'match', 'parent', 'parent-group', 'parent-group', 'id-group');

  $rows = array();

  // For each elements to anchor in the form.
  foreach (element_children($form['my_items']) as $key) {

    $element                                        = &$form['my_items'][$key];
    $element['weight']['#attributes']['class']      = array('weight-group');
    $element['fid']['#attributes']['class']         = array('id-group');
    $element['parent_fid']['#attributes']['class']  = array('parent-group');

    $rows[] = array(
      'data' => array(
        theme('indentation', array('size' => $element['#depth'])) . drupal_render($element['title']),
        drupal_render($element['enabled']),
        drupal_render($element['weight']) .
        drupal_render($element['fid']) .
        drupal_render($element['parent_fid']),
        drupal_render($element['operations']['configure']),
        drupal_render($element['operations']['delete']),
      ),
      'class' => array('draggable'),
    );
  }
  // Create table headers.
  $header = array(t('Form name'),
    t('Enabled'),
    t('Weight'),
    array(
      'data' => t('Operations'),
      'colspan' => 2,
    ),
  );
  // Theme the table and render the form.
  $output  = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array(
      'id' => 'my-draggable-table',
    ),
  ));
  $output .= drupal_render_children($form);
  $output .= drupal_render($form['submit']);

  return $output;
}

// ////////////////////////////////////////////////////////////////////////////
// //                         HELPER FUNCTIONS                            // //

// ---------------------------------------------------------------------------.
/**
 * Helper function: get the forms from database and render them hierarchically.
 *
 * Return the items sorted.
 */
function _search_autocomplete_get_items() {

  // Get data in database and fetch it.
  $result = db_select('search_autocomplete_forms', 'f')
    ->fields('f')
    ->orderBy('weight')
    ->execute()
    ->fetchAllAssoc('fid');

  // Order the list.
  return _search_autocomplete_get_ordered_list(0, $result);
}

// --------------------------------------------------------------------------.
/**
 * HELPER function to order a list.
 *
 * Returns a tree list of all items in the $items array that are children
 * of the supplied parent, ordered appropriately.
 *
 * @return array
 *   the ordered tree
 */
function _search_autocomplete_get_ordered_list($parent, $items, $depth = 0) {

  $remnant = array(); $children = array();
  // Insert direct children in $children
  // and remaining in $remnant.
  foreach ($items as $item) {
    if ($item->parent_fid == $parent) {
      $item->depth = $depth;
      $children[] = $item;
    }
    else {
      $remnant[] = $item;
    }
  }

  // Sort the direct children by weight.
  usort($children, '_search_autocomplete_sort_by_weight');

  $ancestors = array();

  foreach ($children as $child) {
    // Order the child ancestors iteratively.
    $child_children = _search_autocomplete_get_ordered_list($child->fid, $remnant, $depth + 1);
    // Push the results into the main array below the child.
    $ancestors[] = $child;
    // Merge it if needed.
    if (count($child_children)) {
      $ancestors = array_merge($ancestors, $child_children);
    }
  }
  return $ancestors;
}

// ---------------------------------------------------------------------------.
/**
 * HELPER function : Usort function for sorting arrays by weight.
 *
 * @return bool
 *   1: if ($a < $b),
 *   0 if equal,
 *   -1 otherwise
 */
function _search_autocomplete_sort_by_weight($a, $b) {
  if ($a->weight == $b->weight) {
    return 0;
  }
  return ($a->weight < $b->weight) ? -1 : 1;
}