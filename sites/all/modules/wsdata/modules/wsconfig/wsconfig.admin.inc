<?php

/**
 * @file
 * Admin forms for wsconfig
 */

/**
 * Form callback wrapper: create or edit a wsconfig.
 *
 * @param $wsconfig
 *   The wsconfig object being edited by this form.
 *
 * @see wsconfig_edit_form()
 */
function wsconfig_form_wrapper($wsconfig) {
  // Add the breadcrumb for the form's location.
  wsconfig_set_breadcrumb();
  return drupal_get_form('wsconfig_edit_form', $wsconfig);
}

/**
 * Form callback wrapper: view a wsconfig.
 *
 * @param $wsconfig
 *   The wsconfig object being viewed by this form.
 *
 * @see wsconfig_view_form()
 */
function wsconfig_view_form_wrapper($wsconfig) {
  return drupal_get_form('wsconfig_view_form', $wsconfig);
}

/**
 * Form callback wrapper: delete a wsconfig.
 *
 * @param $wsconfig
 *   The wsconfig object being edited by this form.
 *
 * @see wsconfig_edit_form()
 */
function wsconfig_delete_form_wrapper($wsconfig) {
  // Add the breadcrumb for the form's location.
  //wsconfig_set_breadcrumb();
  return drupal_get_form('wsconfig_delete_form', $wsconfig);
}

/**
 *  Entity UI Callback
 */
function wsconfig_form($form, &$form_state, $wsconfig, $op = 'edit') {
  return wsconfig_edit_form($form, $form_state, $wsconfig, $op);
}

/**
 * Form callback: create or edit a wsconfig.
 *
 * @param $wsconfig
 *   The wsconfig object to edit or for a create form an empty wsconfig object
 *     with only a wsconfig type defined.
 */
function wsconfig_edit_form($form, &$form_state, $wsconfig, $op = 'edit') {
  if (isset($_GET['remove']) and isset($wsconfig->data[$_GET['remove']])) {
    unset($wsconfig->data[$_GET['remove']]);
    $wsconfig->save();
    drupal_set_message(t('Method !METHOD removed', array('!METHOD' => $_GET['remove'])));
  }

  $form['endpoint'] = array(
    '#type' => 'item',
    '#title' => t('Endpoint'),
    '#markup' => $wsconfig->type . ' (' . $wsconfig->getEndpoint() . ')',
    '#weight' => -5,
  );

  // Add the default field elements.
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Web Service Configuration Title'),
    '#default_value' => isset($wsconfig->title) ? $wsconfig->title : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );

  $form['name'] = array(
    '#type' => 'machine_name',
    '#title' => t('Web Service Configuration Machine Name'),
    '#default_value' => isset($wsconfig->name) ? $wsconfig->name : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -4,
    '#machine_name' => array(
      'exists' => 'wsconfig_exists_by_name',
      'source' => array('title'),
    ),
  );

  foreach ($wsconfig->getOperations() as $operation) {
    $op = $wsconfig->getMethodKey($operation);
    $op_name = $wsconfig->getMethodName($operation);
    $remove_link = l(
      'Remove',
      current_path(),
      array(
        'query' => array('remove' => $op),
      )
    );

    $form['data'][$op] = array(
      '#type' => 'textfield',
      '#title' => t('!NAME Data Method (!OP) - !REMOVE', array('!NAME' => $op_name, '!OP' => $op, '!REMOVE' => $remove_link)),
      '#description' => t('The method call for "!OP". If keys are included in the method name, include them as tokens starting with a "%".  Example: user/%id/course', array('!OP' => $operation)),
      '#size' => 80,
      '#maxlength' => 255,
      '#default_value' => !empty($wsconfig->data[$op]) ? $wsconfig->data[$op] : '',
    );

    $form['data'][$op . '_options'] = array(
      '#type' => 'textfield',
      '#title' => t('Options'),
      '#description' => t('Options as a JSON array  (Example: {"headers":{"Content-Type":"application/json"}} )'),
      '#default_value' => isset($form_state['values'][$op . '_options']) ? $form_state['values'][$op . '_options'] : isset($wsconfig->data['options'][$op]) ? drupal_json_encode($wsconfig->data['options'][$op]): '',
      '#element_validate' => array('_wsconfig_element_validate_json'),
    );
  }

  if (!empty($wsconfig->wsconfig_id)) {
    $addmethod_items = $wsconfig->getPossibleMethods();

    if (count($addmethod_items) > 0) {
      $form['addmethod'] = array(
        '#type' => 'select',
        '#title' => t('Add method'),
        '#options' => $wsconfig->getPossibleMethods(),
      );

      $allmethods = $wsconfig->connector->getMethods();
      foreach ($allmethods['multiple'] as $key => $method) {
        $form['addmethod_name_' . $key] = array(
          '#type' => 'textfield',
          '#title' => t('!METHOD Name', array('!METHOD' => $method)),
          '#description' => t('Must contain only lowercase letters, numbers, or underscores'),
          '#states' => array(
            'visible' => array(
              ':input[name="addmethod"]' => array('value' => $key),
            ),
          ),
        );
      }

      $form['addmethod_submit'] = array(
          '#type' => 'submit',
          '#value' => t('Add method'),
      );
    }
  }

  if ($wsconfig->connector->supportsCaching()) {
    $form['cache_default_time'] = array(
      '#type' => 'textfield',
      '#title' => t('Default Cache Time'),
      '#description' => t('Number of seconds query results should be cached for.'),
      '#default_value' => isset($wsconfig->data['cache_default_time']) ? $wsconfig->data['cache_default_time'] : 0,
    );

    $form['cache_default_override'] = array(
      '#type' => 'checkbox',
      '#title' => t('Override Cache Time'),
      '#description' => t('Override cache time with default value even if another value is returned by the service.'),
      '#default_value' => isset($wsconfig->data['cache_default_override']) ? $wsconfig->data['cache_default_override'] : 0,
    );

  }

  // Add the field related form elements.
  $form_state['wsconfig'] = $wsconfig;
  field_attach_form('wsconfig', $wsconfig, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Web Service Configuration'),
    '#submit' => $submit + array('wsconfig_edit_form_submit'),
  );

  if (!empty($wsconfig->name)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete Web Service Configuration'),
      '#suffix' => l(t('Cancel'), 'admin/structure/wsconfig'),
      '#submit' => $submit + array('wsconfig_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'wsconfig_edit_form_validate';
  $form['#submit'][] = 'wsconfig_edit_form_submit';
  return $form;
}

/**
 * Form API validate callback for the wsconfig form
 */
function wsconfig_edit_form_validate(&$form, &$form_state) {
  $wsconfig = $form_state['wsconfig'];

  // Notify field widgets to validate their data.
  field_attach_form_validate('wsconfig', $wsconfig, $form, $form_state);

  if ($form_state['triggering_element']['#id'] == 'edit-addmethod-submit') {
    $name = 'addmethod_name_' . $form_state['values']['addmethod'];

    if (isset($form[$name])) {
      $methodname = preg_replace('/\W/', '', $form_state['values'][$name]);
      if (empty($methodname) or !preg_match('/[A-Za-z0-9]/', $methodname)) {
        form_error($form[$name], t('Method requires a name'));
      } elseif (isset($wsconfig->data[$wsconfig->getMethodKey($form_state['values']['addmethod'] . '_' . $methodname)])) {
        form_error($form[$name], t('Method name already used'));
      }
    }
  }
}

/**
 * Form API submit callback for the wsconfig form.
 *
 * @todo remove hard-coded link
 */
function wsconfig_edit_form_submit(&$form, &$form_state) {

  $wsconfig = entity_ui_controller('wsconfig')->entityFormSubmitBuildEntity($form, $form_state);

  $wsconfig->data['cache_default_time'] = (int) $form_state['values']['cache_default_time'];
  $wsconfig->data['cache_default_override'] = (int) $form_state['values']['cache_default_override'];


  // Save the wsconfig and go back to the list of wsconfigs
  foreach ($wsconfig->getOperations() as $operation) {
    $op = $wsconfig->getMethodKey($operation);
    $wsconfig->data[$op] = $wsconfig->$op;

    // Save the defined options if any
    if (!empty($form_state['values'][$op . '_options'])) {
      $wsconfig->data['options'][$op] = drupal_json_decode($form_state['values'][$op . '_options']);
    }
  }

  if ($form_state['triggering_element']['#id'] == 'edit-addmethod-submit') {
    $methodname = '';
    $name = 'addmethod_name_' . $form_state['values']['addmethod'];

    if (isset($form[$name])) {
      $methodname = $form_state['values'][$name];
    }

    $wsconfig->addMethod($form_state['values']['addmethod'], $methodname);
    drupal_set_message(t('Added !METHOD', array('!METHOD' => $form_state['values']['addmethod'])));
  }

  $new_wsconfig = FALSE;

  // Add in created and changed times.
  if (isset($wsconfig->is_new) and $wsconfig->is_new){
    $new_wsconfig = TRUE;
    $wsconfig->created = time();
  }

  $wsconfig->changed = time();

  $wsconfig->save();

  if ($new_wsconfig or $form_state['triggering_element']['#id'] == 'edit-addmethod-submit') {
    $form_state['redirect'] = 'admin/structure/wsconfig/manage/' . $wsconfig->wsconfig_id . '/edit';
  }
  else {
    drupal_set_message(t('WsConfig saved'));
    $form_state['redirect'] = 'admin/structure/wsconfig';
  }
}

/**
 * Form API submit callback for the delete button.
 *
 * @todo Remove hard-coded path
 */
function wsconfig_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/wsconfig/manage/' . $form_state['wsconfig']->wsconfig_id . '/delete';
}

/**
 * Form callback: to view a wsconfig.
 *
 * @param $wsconfig
 *   The wsconfig to use to view
 *
 */
function wsconfig_view_form($form, &$form_state, $wsconfig) {

  $form_state['wsconfig'] = $wsconfig;
  $ws_endpoint = wsconfig_get_types($wsconfig->type);

  //ws endpoint display
  $form['endpoint'] = array(
    '#type' => 'item',
    '#title' => t('Endpoint'),
    '#markup' => $wsconfig->type . ' (' . $ws_endpoint->data['endpoint'] . ')',
  );

  foreach ($wsconfig->getOperations() as $op) {
    $method = $wsconfig->getMethod($op);
    if(!empty($method)) {
      $form[$op] = array(
        '#type' => 'fieldset',
        '#title' => $wsconfig->getMethodName($op),
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
      );

      $form[$op]['method'] = array(
        '#type' => 'item',
        '#title' => $wsconfig->getMethodName($op),
        '#markup' => $method,
      );

      $matches = array();
      preg_match_all("/(%\w+)/", $method, $matches);

      foreach ($matches[0] as $var) {
        $form[$op][$op . ':' . $var] = array(
          '#type' => 'textfield',
          '#title' => $var,
          '#default_value' => isset($form_state['values'][$var]) ? $form_state['values'][$var] : '',
        );
      }

      $form[$op]['arguments'] = array(
        '#type' => 'textfield',
        '#title' => t('Arguments'),
        '#description' => t('Arguments as a JSON array'),
        '#default_value' => isset($form_state['values']['arguments']) ? $form_state['values']['arguments'] : '',
        '#element_validate' => array('_wsconfig_element_validate_json'),
        '#maxlength' => 512,
      );

      $form[$op]['options'] = array(
        '#type' => 'textfield',
        '#title' => t('Options'),
        '#description' => t('Options as a JSON array  (Example: {"headers":{"Content-Type":"application/json"}} )'),
        '#default_value' => isset($form_state['values']['options']) ? $form_state['values']['options'] : isset($wsconfig->data['options'][$op]) ? drupal_json_encode($wsconfig->data['options'][$op]): '',
        '#element_validate' => array('_wsconfig_element_validate_json'),
        '#maxlength' => 512,
      );

      $form[$op]['submit'] = array(
        '#type' => 'submit',
        '#name' => $op,
        '#value' => $wsconfig->getMethodName($op),
      );
    }
  }

  return $form;
}


/**
 * Submit callback for wsconfig_view_form
 */
function wsconfig_view_form_submit($form, &$form_state) {
  $wsconfig = $form_state['wsconfig'];

  if (isset($form_state['triggering_element']['#name'])) {
    $op = $form_state['triggering_element']['#name'];

    if (in_array($op, $wsconfig->getOperations())) {
      $variables = array();
      foreach ($form_state['values'] as $key => $value) {
        if (drupal_substr($key, 0, drupal_strlen($op . ':')) == $op . ':') {
           $variables[drupal_substr($key, drupal_strlen($op . ':'))] = $value;
        }
      }
      $arguments = array();
      if (isset($form_state['values']['arguments']) and !empty($form_state['values']['arguments'])) {
        $arguments = json_decode($form_state['values']['arguments'], TRUE);
      }

      $options = array();
      if (isset($form_state['values']['options']) and !empty($form_state['values']['options'])) {
        $options = json_decode($form_state['values']['options'], TRUE);
      }
      $url = '';
      $results = $wsconfig->call($op, $variables, $arguments, $options, $url);
      drupal_set_message(
        t('Method: !method<br>Variables: !variables<br>Arguments: !arguments<br>Options: !options<br>Result: !results',
          array(
            '!method' => $url,
            '!variables' => print_r($variables, TRUE),
            '!arguments' => print_r($arguments, TRUE),
            '!options' => print_r($options, TRUE),
            '!results' => htmlspecialchars($results),
          )
        )
      );
      $form_state['rebuild'] = TRUE;
    }
  }
}


/**
 * Form callback: confirmation form for deleting a wsconfig.
 *
 * @param $wsconfig
 *   The wsconfig to delete
 *
 * @see confirm_form()
 */
function wsconfig_delete_form($form, &$form_state, $wsconfig) {
  $form_state['wsconfig'] = $wsconfig;

  $form['#submit'][] = 'wsconfig_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete the Web Service Configuration %title?', array('%title' => $wsconfig->title)),
    'admin/structure/wsconfig',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

/**
 * Submit callback for wsconfig_delete_form
 */
function wsconfig_delete_form_submit($form, &$form_state) {
  $wsconfig = $form_state['wsconfig'];

  wsconfig_delete($wsconfig);

  drupal_set_message(t('The Web Service Configuration %title has been deleted.', array('%title' => $wsconfig->title)));
  watchdog('wsconfig', 'Deleted web service configuration %name.', array('%name' => $wsconfig->name));

  $form_state['redirect'] = 'admin/structure/wsconfig';
}

/**
 * Page to add Model Entities.
 *
 * @todo Pass this through a proper theme function
 */
function wsconfig_add_page() {
  $controller = entity_ui_controller('wsconfig');
  return $controller->addPage();
}

/**
 * Displays the list of available wsconfig types for wsconfig creation.
 *
 * @ingroup themeable
 */
function theme_wsconfig_add_list($variables) {
  $wsinfo = entity_get_info("wsconfig");

  $content = $variables['content'];

  $output = '';
  if ($content) {
    $output .= '<H1>' . t('Web Service Configuration') . '</H1>';
    $output .= '<dl class="wsconfig-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item->label, $wsinfo['admin ui']['path'] . '/add/' . $item->type) . '</dt>';
      $description = array();
      foreach ($item->data as $key => $val) {
        $description[] = drupal_ucfirst($key) . ": $val";
      }
      $output .= '<dd>' . filter_xss_admin(implode('<br>', $description)) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer wsconfig types')) {
      $output = '<p>' . t('Web Service Configuration Entities cannot be added because you have not created any wsconfig types yet. Go to the <a href="@create-wsconfig-type">wsconfig type creation page</a> to add a new wsconfig type.', array('@create-wsconfig-type' => url('admin/structure/wsconfig_types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No web service configuration types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}

/**
 * Sets the breadcrumb for administrative wsconfig pages.
 */
function wsconfig_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Structure'), 'admin/structure'),
    l(t('Web Service Configurations'), 'admin/structure/wsconfig'),
  );

  drupal_set_breadcrumb($breadcrumb);
}

/**
 * Validate json input
 */
function _wsconfig_element_validate_json($element, &$form_state, $form) {
  if (is_null(drupal_json_decode($element['#value'])) and !empty($element['#value'])) {
    form_error($element, t('Invalid json format.'));
  }
}
