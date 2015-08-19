<?php

/**
 * @file
 * WsConfig type editing UI
 */

/**
 * Generate the wsconfig type editing form
 */
function wsconfig_type_form($form, &$form_state, $wsconfig_type, $op = 'edit') {
  if ($op == 'clone') {
    $wsconfig_type->label .= ' (cloned)';
    $wsconfig_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $wsconfig_type->label,
    '#description' => t('The human-readable name of this wsconfig type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($wsconfig_type->type) ? $wsconfig_type->type : '',
    '#maxlength' => 32,
//    '#disabled' => $wsconfig_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'wsconfig_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this wsconfig type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['data']['#tree'] = TRUE;
  $form['data']['endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Web service endpoint'),
    '#description' => t('Full URL to the service endpoint Ex: http://example.com/rest'),
    '#default_value' => !empty($wsconfig_type->data['endpoint']) ? $wsconfig_type->data['endpoint'] : '',
  );

  $connectors = variable_get('wsconfig_connectors');
  $connectors_options = array();
  foreach ($connectors as $connector) {
    $connectors_options[$connector['class']] = t($connector['name']);
  }

  if (empty($connectors_options)) {
    drupal_set_message(
      t('There are currently no Service Connectors available, a Service Connector is required to create a WS Configuration Type. Service Connectors provide the implementation for connecting remote data. See the WSData project page on Drupal.org for a list of modules that provide Service Connectors.'), 'warning');
  }

  $form['data']['connector'] = array(
    '#type' => 'select',
    '#title' => t('Service Connector'),
    '#description' => t('Connector to use to make the web service requests.'),
    '#options' => $connectors_options,
    '#required' => TRUE,
    '#default_value' => !empty($wsconfig_type->data['connector']) ? $wsconfig_type->data['connector'] : '',
  );

  if (!empty($wsconfig_type->data['connector'])) {
    $dummy_connector = new $wsconfig_type->data['connector']($wsconfig_type->data['endpoint']);
    $language_plugins = $dummy_connector->getSupportedLanguagePlugins();
    foreach ($language_plugins as $language_plugin) {
      $language_options[$language_plugin] = $language_plugin;
    }

    $form['data']['language plugin'] = array(
      '#type' => 'select',
      '#title' => t('Language Handler Plugin'),
      '#description' => t('Method to use to retrieve multilingual content.'),
      '#options' => $language_options,
      '#required' => TRUE,
      '#default_value' => !empty($wsconfig_type->data['language plugin']) ? $wsconfig_type->data['language plugin'] : 'default',
    );

    // Load the plugin settings form
    if (!empty($wsconfig_type->data['language plugin'])) {
      $form['data']['language always'] = array(
        '#type' => 'checkbox',
        '#title' => t('Always use the current user\'s language.'),
        '#description' => t('This probably should not be used with wsconfig_field_storage as the selected language with be the user language and not the content language.'),
        '#default_value' => !empty($wsconfig_type->data['language always']) ? $wsconfig_type->data['language always'] : 0,
      );
      $plugin = FALSE;
      if (isset($wsconfig_type->data['language plugin'])) {
        $plugin = wsdata_get_language_plugins($wsconfig_type->data['language plugin']);
      }
      if (FALSE !== $plugin) {
        module_load_include($plugin['file type'], $plugin['module'], $plugin['file']);
        $form['data']['language plugin settings'] = array(
          '#type' => 'fieldset',
          '#title' => t('Language Plugin Settings'),
          '#collapsible' => FALSE,
          '#collapsed' => FALSE,
        );
        $form_settings = array();
        if (isset($wsconfig_type->data['language plugin settings'])) {
          $form_settings = $wsconfig_type->data['language plugin settings'];
        }

        $plugin_form = $plugin['form']($form_settings);
        foreach ($plugin_form as $name => $form_element) {
          $form['data']['language plugin settings'][$name] = $form_element;
        }
      }
    }
  }

  // @todo add token support
  // @todo list available tokens

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Web Service Configuration type'),
    '#weight' => 40,
  );

  //Locking not supported yet
  /*if (!$wsconfig_type->isLocked() && $op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete wsconfig type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('wsconfig_type_form_submit_delete')
    );
  }*/
  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function wsconfig_type_form_submit(&$form, &$form_state) {
  $wsconfig_type = entity_ui_form_submit_build_entity($form, $form_state);
  $wsconfig_type->save();
  $form_state['redirect'] = 'admin/structure/wsconfig_types';
  drupal_set_message(t('Web Service Configuration Type saved successfully.'));
}

/**
 * Form API submit callback for the delete button.
 */
function wsconfig_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/wsconfig_types/manage/' . $form_state['wsconfig_type']->type . '/delete';
}
