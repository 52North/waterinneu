<?php

/**
 * @file
 * Search Autocomplete
 * Sets the admin part of the module: permissions, hooks, callbacks, etc...
 *
 * Sponsored by:
 * www.axiomcafe.fr
 */


/**
 * Implements hook_permission().
 *
 * Valid permissions for this module.
 */
function search_autocomplete_permission() {
  return array(
    'administer Search Autocomplete' => array(
      'title' => t('Administer Search Autocomplete'),
      'description' => t('Access administration panel for autocompletion settings.'),
    ),
    'use Search Autocomplete' => array(
      'title' => t('Use Search Autocomplete'),
      'description' => t('Allow usage of autocompletion on forms.'),
    ),
  );
}

/**
 * Implements hook_theme().
 *
 * Define the function to render our forms.
 */
function search_autocomplete_theme($existing, $type, $theme, $path) {
  // Register theme function for draggable treelist search forms.
  return array(
    'search_autocomplete_treelist_form' => array(
      'render element' => 'form',
    ),
  );
}

/**
 * Implements hook_menu().
 *
 * Create an administration page to access admin form.
 */
function search_autocomplete_menu() {

  // Create the admin setting page: list of forms.
  $items['admin/config/search/search_autocomplete'] = array(
    'title'             => 'Search Autocomplete settings',
    'description'       => 'Choose settings and suggestion items for autocompletion in input forms.',
    'page callback'     => 'drupal_get_form',
    'page arguments'    => array('search_autocomplete_treelist_form'),
    'access arguments'  => array('administer Search Autocomplete'),
    'file'              => 'search_autocomplete.form.treelist.inc',
    'type'              => MENU_NORMAL_ITEM,
    'weight'            => 0,
  );
  // Create a tab for settings.
  $items['admin/config/search/search_autocomplete/settings'] = array(
    'title'             => 'Search Autocomplete settings',
    'description'       => 'Search Autocompletion main tab on setting page.',
    'type'              => MENU_DEFAULT_LOCAL_TASK,
    'weight'            => 1,
  );
  // Create an admin setting page: add a new form.
  $items['admin/config/search/search_autocomplete/add'] = array(
    'title'             => 'Add a form',
    'description'       => 'Create a new autocompletion form tab on setting page.',
    'page callback'     => 'drupal_get_form',
    'page arguments'    => array('search_autocomplete_form_add'),
    'access arguments'  => array('administer Search Autocomplete'),
    'file'              => 'search_autocomplete.form.add.inc',
    'type'              => MENU_LOCAL_TASK,
    'weight'            => 2,
  );
  // Create an admin setting page: configure a form.
  $items['admin/config/search/search_autocomplete/%/configure'] = array(
    'title'             => 'Search Autocomplete - Configuration',
    'page callback'     => 'drupal_get_form',
    'page arguments'    => array('search_autocomplete_form_configure'),
    'access arguments'  => array('administer Search Autocomplete'),
    'file'              => 'search_autocomplete.form.configure.inc',
  );
  // Create an admin setting page: delete a form.
  $items['admin/config/search/search_autocomplete/%/delete/%'] = array(
    'title'             => 'Search Autocomplete - Delete',
    'page callback'     => 'drupal_get_form',
    'page arguments'    => array('search_autocomplete_form_delete', 4, 6),
    'access arguments'  => array('administer Search Autocomplete'),
    'file'              => 'search_autocomplete.form.delete.inc',
  );
  // Create a callback page for JSON suggestions.
  $items['search_autocomplete/autocomplete'] = array(
    'title' => 'Autocompleton when using view',
    'page callback' => 'search_autocomplete_autocomplete',
    'type' => MENU_CALLBACK,
    'access callback' => TRUE,
    'access arguments' => array('access content'),
    'file' => 'search_autocomplete.autocomplete.inc',
  );

  $items['views/autocomplete'] = array(
    'title' => 'Autocomplete view selector',
    'page callback' => 'search_autocomplete_views_autocomplete',
    // Access not properly checked on callbacks (see function).
    'type' => MENU_CALLBACK,
    'access callback' => TRUE,
    'access arguments' => array('access content'),
    'file' => 'search_autocomplete.autocomplete.inc',
  );
  return $items;
}

/**
 * Implements hook_help().
 */
function search_autocomplete_help($path, $arg) {
  $help = '';
  switch ($path) {

    case 'admin/modules#description':
      $help = t('Allows the users with the right permission to use advanced autocompletion features on forms.');
      break;

    case 'admin/config/search/search_autocomplete':
      $help  = '<div>' . t('Search Autocomplete helps you to enhance your search forms with autocompleted suggestions.') . '</div>';
      $help .= '<div>' . t('Use this form to activate the forms you want to autocomplete.') . '</div>';
      $help .= '<div>' . t('You may want to add new possible form to autocomplete. To do so, please use the tab <a href="search_autocomplete/add">Add a form</a>.') . '</div>';
      break;

    case 'admin/config/search/search_autocomplete/add':
      $help  = '<div>' . t('This page allows you to add a new form to be autocompleted with the Search Autocomplete module.') . '</div>';
      $help .= '<div>' . t('This is an advanced feature configuration. Use it only if you know what you are doing and after reading <a href="http://drupal-addict.com/nos-projets/search-autocomplete">documentation</a>. If you wish help, please ask for a new default form to be added in the next release of Search Autocomplete module.') . '</div>';
      break;

    case 'admin/config/search/search_autocomplete/%/configure':
      $help  = '<div>' . t('You are currently configuring the options to autocomplete a form.') . '</div>';
      $help .= '<div>' . t('Every children forms will be modified as well.') . '</div>';
      break;

  }
  return $help;
}
