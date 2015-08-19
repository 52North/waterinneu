<?php

/**
 * @file
 * Plugin to provide an relationship handler for string to a data set
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Web Service Data'),
  'keyword' => 'wsdata',
  'description' => t('Makes a web service call and provides the parsed result as a new context.'),
  'required context' => new ctools_context_required(t('String'), 'string'),
  'context' => 'wscpmfog_wsdata_from_string',
  'edit form' => 'wsconfig_wsdata_from_string_edit_form',
);

/**
 * Return a new wsdata context based on an existing string context.
 */
function wsdata_wsprocessor_from_string($context, $conf) {
  // If unset it wants a generic, unfilled context, which is just NULL.
  if (empty($context->data) || !isset($context->data->uid)) {
    return ctools_context_create_empty('wsdata', NULL);
  }

  if (isset($context->data)) {

    // Send it to ctools.
    return ctools_context_create('wsdata', $processor);
  }  
}

function wsconfig_wsdata_from_string_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['wsconfig'] = array(
    '#type' => 'select',
    '#title' => t('Web Service Config'),
    '#description' => t('The web service config to use to retrieve the data'),
    '#options' => wsconfig_get_list_by_name(),
    '#default_value' => isset($conf['wsconfig']) ? $conf['wsconfig'] : '',
  );

  $form['wsprocessor'] = array(
    '#type' => 'select',
    '#title' => t('Web Service Processor'),
    '#description' => t('The web service processor to parse the data'),
    '#options' => wsconfig_get_field_processors(),
    '#default_value' => isset($conf['wsprocessor']) ? $conf['wsprocessor'] : '',
  );

  return $form;
}
