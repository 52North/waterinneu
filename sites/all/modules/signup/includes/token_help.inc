<?php
/**
 * @file
 * Code for building help text for token.module support on various forms.
 */

/**
 * Private function to generate HTML for showing the available tokens.
 *
 * @param array $form
 *   Reference to the form array to include the help fieldset in.
 * @param string $element_name
 *   Name of the form element to use for the help fieldset.
 */
function _signup_token_help(&$form, $element_name) {
  $form[$element_name] = array(
    '#type' => 'fieldset',
    '#title' => t('Replacement tokens'),
    '#description' => t("Since these tokens will be used in plain text e-mail, it is better to use the '-raw' versions of any tokens that provide them."),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form[$element_name]['help_text'] = array(
    '#markup' => _signup_build_token_help(),
  );
}

/**
 * Private function to generate HTML for showing the available tokens
 *
 * @return The themed representation of the available tokens.
 */
function _signup_build_token_help() {
  static $help_html = '';
  if (empty($help_html) && module_exists('token')) {
    $help_html = theme('token_tree', array('token_types' => array('signup', 'node', 'global'), 'click_insert' => TRUE, 'show_restricted' => TRUE));
  }
  return $help_html;
}
