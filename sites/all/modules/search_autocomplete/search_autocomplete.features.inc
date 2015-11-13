<?php

/**
 * @file
 * Search Autocomplete
 * Add support for CTools and feature import/export.
 *
 * Sponsored by:
 * www.axiomcafe.fr
 */

/**
 * Implements hook_features_export_options().
 *
 * This hook will alert features of which specific items of this component may
 * be exported. For instances, in this case, we want to make available all the
 * existing items.  If there are no items to be exported, this component will
 * not be made available in the features export page.
 *
 * @return array
 *   A keyed array of items, suitable for use with a FormAPI select or
 *   checkboxes element.
 */
function search_autocomplete_config_features_export_options() {
  $data = search_autocomplete_get_data();
  $options = array();
  foreach ($data as $value) {
    $options[$value->fid] = $value->title;
  }
  return $options;
}

/**
 * Implements hook_features_export().
 *
 * This is a component hook, rather then a module hook, therefore this is the
 * callback from hook_features_api which relates to the specific component we
 * are looking to export.  When a specific instance of the component we are
 * looking to export is selected, this will include the necessary item, plus
 * any dependencies into our export array.
 *
 * @param array $data
 *   this is the machine name for the component in question
 * @param array &$export
 *   array of all components to be exported
 * @param string $module_name
 *   The name of the feature module to be generated.
 * @return array
 *   The pipe array of further processors that should be called
 */
function search_autocomplete_config_features_export($data, &$export, $module_name) {


  foreach ($data as $component) {
    $export['features']['search_autocomplete_config'][$component] = $component;
  }
  return array();
}

/**
 * Implements hook_features_export_render().
 *
 * This hook will be invoked in order to export
 * Component hook. The hook should be implemented using the name ot the
 * component, not the module, eg. [component]_features_export() rather than
 * [module]_features_export().
 *
 * Render one or more component objects to code.
 *
 * @param string $module_name
 *   The name of the feature module to be exported.
 * @param array $data
 *   An array of machine name identifiers for the objects to be rendered.
 * @param array $export
 *   The full export array of the current feature being exported. This is only
 *   passed when hook_features_export_render() is invoked for an actual feature
 *   update or recreate, not during state checks or other operations.
 * @return array
 *   An associative array of rendered PHP code where the key is the name of the
 *   hook that should wrap the PHP code. The hook should not include the name
 *   of the module, for example the key for `hook_example` should simply be
 *   `example`.
 */
function search_autocomplete_config_features_export_render($module_name, $data, $export = NULL) {
  $code = array();
  $i = 0;
  foreach ($data as $component) {
    //here 11it is just a variable_get, in other cases, it could be a query!
    $search_obj = search_autocomplete_row_data($component);
    foreach ($search_obj as $key => $value) {
      $code[$i][$key] = $value;
    }
    $i++;
  }
  $code = "  return " . features_var_export($code, '  ') . ";";
  return array('search_autocomplete_config_features_default_settings' => $code);
}

/**
 * Implements hook_features_revert().
 */
function search_autocomplete_config_features_revert($module) {
  search_autocomplete_config_features_rebuild($module);
}

/**
 * Implements rebuild function
 */
function search_autocomplete_config_features_rebuild($module) {
  $items = module_invoke($module, 'search_autocomplete_config_features_default_settings');
  $new = FALSE;
  foreach ($items as $value) {
    try {
      $result = search_autocomplete_row_data($value['fid']);
      if (!is_array($result)) {
        $new = TRUE;
      }
      drupal_write_record('search_autocomplete_forms', $value, $new ? array() : 'fid');
    } catch (Exception $e) {
      watchdog("Error in updating", $e->getMessage(), array(), WATCHDOG_ERROR);
    }
  }
}

/**
 * Get machine name of all search data.
 * @return
 *   An associative array, or FALSE if there is no next row.
 */
function search_autocomplete_get_data() {
  $codes = db_select('search_autocomplete_forms', 'sa')
      ->fields('sa', array())
      ->execute();
  return $codes->fetchAll();
}

/**
 * Will retrieve data on basis of fid.
 * @param type $fid
 * @return type
 */
function search_autocomplete_row_data($fid) {
  $codes = db_select('search_autocomplete_forms', 'sa')
      ->fields('sa', array())
      ->condition('fid', $fid)
      ->execute();
  return $codes->fetchAssoc();
}