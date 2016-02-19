<?php
/**
 * @file
 * Contains implementation of admin settings form for the sticky navigation
 */

/**
 * Admin form to set up the sticky nav logic.
 */
function stickynav_admin_form() {
  $form = array();
  $themes = list_themes();
  foreach ($themes as $name => $data) {
    // Only getting settings for enabled themes.
    if ($data->status == 1) {
      $form['stickynav-enabled-' . $name] = array(
        '#type' => 'checkbox',
        '#title' => check_plain($data->info['name']),
        '#default_value' => variable_get('stickynav-enabled-' . $name, FALSE),
      );
      // Selector is only visible when you activate sticky nav for the theme.
      $form['stickynav-selector-' . $name] = array(
        '#type' => 'textfield',
        '#title' => t('Selector'),
        '#description' => t('Place your selector for your menu that will be sticky on your theme. Use jquery format.'),
        '#default_value' => variable_get('stickynav-selector-' . $name, ''),
        '#states' => array(
          'visible' => array(
            ':input[name="stickynav-enabled-' . $name . '"]' => array('checked' => TRUE),
          ),
          'invisible' => array(
            ':input[name="stickynav-enabled-' . $name . '"]' => array('checked' => FALSE),
          ),
        ),
      );
      $form['stickynav-roles-' . $name] = array(
        '#type' => 'checkboxes',
        '#title' => t('Excluded Roles'),
        '#description' => t("Exclude specific roles from using sticky navigation."),
        '#options' => user_roles(),
        '#default_value' => variable_get('stickynav-roles-' . $name, array()),
        '#states' => array(
          'visible' => array(
            ':input[name="stickynav-enabled-' . $name . '"]' => array('checked' => TRUE),
          ),
          'invisible' => array(
            ':input[name="stickynav-enabled-' . $name . '"]' => array('checked' => FALSE),
          ),
        ),
      );
    }
  }

  return system_settings_form($form);
}
