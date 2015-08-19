<?php
/**
 * @file
 * Administrator forms for wsdata
 */

/**
 * Language Plugins
 */

/**
 * Default language plugin form
 */
function wsdata_language_plugin_default_form($settings = array()) {
  $form['value'] = array(
    '#markup' => t('No configuration required.'),
    '#prefix' => '<p>',
    '#suffix' => '</p>',
  );

  return $form;
}

/**
 * Header language plugin form
 */
function wsdata_language_plugin_header_form($settings = array()) {

  $form['header'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Name of the header to set. Default is "Accept-Language"'),
    '#size' => 40,
    '#maxlength' => 255,
    '#default_value' => isset($settings['header']) ? $settings['header'] : 'Accept-Language',
  );

  $languages = language_list();

  foreach ($languages as $language) {
    $form[$language->language] = array(
      '#type' => 'textfield',
      '#title' => $language->native,
      '#description' => t('Value to use when requesting @lang values.', array('@lang' => $language->native)),
      '#size' => 40,
      '#maxlength' => 255,
      '#default_value' => isset($settings[$language->language]) ? $settings[$language->language] : $language->language,
    );
  }

  return $form;
}

/**
 * Argument language plugin form
 */
function wsdata_language_plugin_argument_form($settings = array()) {

  $form['argument'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Name of the argument to set. Default is "lang"'),
    '#size' => 40,
    '#maxlength' => 255,
    '#default_value' => isset($settings['name']) ? $settings['name'] : 'lang',
  );

  $languages = language_list();

  foreach ($languages as $language) {
    $form[$language->language] = array(
      '#type' => 'textfield',
      '#title' => $language->native,
      '#description' => t('Value to use when requesting @lang values.', array('@lang' => $language->native)),
      '#size' => 40,
      '#maxlength' => 255,
      '#default_value' => isset($settings[$language->language]) ? $settings[$language->language] : $language->language,
    );
  }

  return $form;
}

/**
 * Path language plugin form
 */
function wsdata_language_plugin_path_form($settings = array()) {
  $form['position'] = array(
    '#type' => 'textfield',
    '#title' => t('Position'),
    '#description' => t('Position within the path to insert the language value.'),
    '#size' => 40,
    '#maxlength' => 255,
    '#default_value' => isset($settings['position']) ? $settings['position'] : 0,
    '#element_validate' => array('element_validate_integer'),
  );

  $languages = language_list();

  foreach ($languages as $language) {
    $form[$language->language] = array(
      '#type' => 'textfield',
      '#title' => $language->native,
      '#description' => t('Value to use when requesting @lang values.', array('@lang' => $language->native)),
      '#size' => 40,
      '#maxlength' => 255,
      '#default_value' => isset($settings[$language->language]) ? $settings[$language->language] : $language->language,
    );
  }

  return $form;
}

/**
 * Replacement language plugin form
 */
function wsdata_language_plugin_replace_form($settings = array()) {
  $form['default'] = array(
    '#type' => 'textfield',
    '#title' => t('Default value'),
    '#description' => t('Default value if language replacement is not available.'),
    '#size' => 40,
    '#maxlength' => 255,
    '#default_value' => isset($settings['default']) ? $settings['default'] : '',
  );

  $languages = language_list();

  foreach ($languages as $language) {
    $form[$language->language] = array(
      '#type' => 'textfield',
      '#title' => $language->native,
      '#description' => t('Value to use when requesting @lang values.', array('@lang' => $language->native)),
      '#size' => 40,
      '#maxlength' => 255,
      '#default_value' => isset($settings[$language->language]) ? $settings[$language->language] : $language->language,
    );
  }

  return $form;
}

/**
 * URI language plugin form
 */
function wsdata_language_plugin_uri_form($settings = array()) {
  $languages = language_list();

  foreach ($languages as $language) {
    $form[$language->language] = array(
      '#type' => 'textfield',
      '#title' => $language->native,
      '#description' => t('Value to use when requesting @lang values.', array('@lang' => $language->native)),
      '#size' => 40,
      '#maxlength' => 255,
      '#default_value' => isset($settings[$language->language]) ? $settings[$language->language] : $language->language,
    );
  }

  return $form;
}
