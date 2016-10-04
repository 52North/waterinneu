<?php

/**
 * @file
 * Administrative pages for Certificate module.
 */

/**
 * Returns the form for the per-node certificate settings.
 *
 * This is shared by the settings page and the node edit page.
 *
 * @param $node
 *   The fully loaded node object if we've got it.
 *
 * @return
 *   The form array for the per-node certificate settings.
 *
 */
function certificate_type_mapping_form($form_state, $node = NULL) {
  // Get existing node-specific template settings.
  $node_template_settings = $node->certificate['node_settings'];

  // Get existing templates.
  $templates = certificate_certificate_load_all();
  $template_options[0] = 'Global';
  foreach ($templates as $key => $template) {
    $template_options[$key] = $template['title'];
  }

  if (variable_get('certificate_field_grouping', 0)) {
    // Group stuff
    $fieldgroups = variable_get('certificate_field_groups', array());

    // Generate form elements based on selected field's allowed values.
    if (count($fieldgroups)) {
      foreach ($fieldgroups as $key => $fieldgroup) {
        // We don't care about $fieldgroup - just the key.
        // Get node-based setting, if not set, use global.
        if ($node) {
          $template = $node_template_settings[$key];
          $template = $template ? $template : 0;
        }
        else {
          $template = variable_get("certificate_type_{$key}_template", 0);
        }

        $form[$key] = array(
          '#type' => 'select',
          '#title' => check_plain($key),
          '#options' => $template_options,
          '#default_value' => $template,
        );
      }
    }
    else {
      $form['nogroups'] = array(
        '#prefix' => '<p>',
        '#suffix' => '</p>',
        '#value' => t("Please go to !groups to configure certificate field mapping groups.", array('!groups' => l('groups', 'admin/structure/certificates/mapping/groups'))),
      );
    }
  }
  else {
    // Get field's options from types selection.
    $field_options_array = certificate_get_selected_type_options();
    if (arg(0) == 'node' && !count($field_options_array)) {
      $form['#type'] = 'markup';
      $form['#markup'] = "<div>" . t("Please !link before using certificates.", array('!link' => l('set up field mappings', 'admin/structure/certificates/mapping'))) . "</div>";
    }

    // Generate form elements based on selected field's allowed values.
    if ($field_options_array) {
      foreach ($field_options_array as $key => $option_name) {
        // Get node-based setting, if not set, use global.
        if ($node) {
          $template = $node_template_settings[$key];
          $template = $template ? $template : 0;
        }
        else {
          $template = variable_get("certificate_type_{$key}_template", 0);
        }

        $form[$key] = array(
          '#type' => 'select',
          '#title' => check_plain($option_name),
          '#options' => $template_options,
          '#default_value' => $template,
        );
      }
    }
  }

  return $form;
}

/**
 * Alters the node form to inject the appropriate per-node template settings.
 */
function certificate_alter_node_form(&$form, &$form_state) {
  global $user;

  // Add template-mapping form.
  // Note, make sure to set #tree to TRUE.
  if (user_access('administer certificates') || user_access('assign certificates')) {
    $form['certificate'] = array(
      '#type' => 'fieldset',
      '#title' => t('Certificate settings'),
      '#tree' => TRUE,
      '#description' => t('Set up the selection criteria for awarding certificates.'),
    );

    certificate_mapping_form($form, $form_state);
  }
}

/**
 * Add mapping elements to a form.
 */
function certificate_mapping_form(&$form, &$form_state) {
  if (!empty($form_state['node']->certificate['node_settings'])) {
    $stored = $form_state['node']->certificate['node_settings'];
  }
  else {
    $stored = array();
    $sql = "SELECT * FROM {certificate_node} cn WHERE nid = 0";
    $result = db_query($sql);
    while ($row = $result->fetch()) {
      $stored[$row->mapper][$row->type] = $row->template;
    }
  }

  // Custom (module-provided) mappings.
  $mappings = module_invoke_all('certificate_map_options');

  $options = array(
    '-1' => t('- prevent certificate -'),
    '' => t('- no action -'),
  );
  foreach (certificate_certificate_load_all() as $cert) {
    $options[$cert['nid']] = check_plain($cert['title']);
  }

  foreach ($mappings as $map_type => $map) {
    $form['certificate']['map'][$map_type] = array(
      '#title' => check_plain($map['title']),
      '#type' => 'fieldset',
      '#group' => TRUE,
      '#description' => filter_xss_admin($map['description']),
      '#collapsed' => TRUE,
      '#collapsible' => TRUE,
    );

    if (count($map['options'])) {
      foreach ($map['options'] as $key => $title) {
        $form['certificate']['map'][$map_type][$key] = array(
          '#type' => 'select',
          '#title' => filter_xss($title),
          '#options' => $options,
          '#default_value' => isset($stored[$map_type][$key]) ? $stored[$map_type][$key] : NULL,
        );
      }
    }
    else {
      $form['certificate']['map'][$map_type]['empty'] = array(
        '#value' => '<p>' . t('There are no mappings available for %title.', array('%title' => $map['title'])) . '</p>',
      );
    }
  }
}

/**
 * Form for global mappings.
 */
function certificate_settings_form($form, &$form_state) {
  $form['certificate']['#tree'] = TRUE;

  module_load_include('inc', 'certificate', 'certificate.admin');
  certificate_mapping_form($form, $form_state);

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
  );

  return $form;
}

/**
 * Save the certificate mappings. For global mappings, we use node ID zero to
 * store it in the database.
 */
function certificate_settings_form_submit($form, &$form_state) {
  certificate_update_node_mappings(0, $form_state['values']['certificate']['map']);

  drupal_set_message(t('The certificate mapping options have been saved.'));
}

/**
 * Theme the form as a table.
 */
function theme_certificate_history_form($form) {
  // TODO: Should this theme certificate_history_form be declared in hook_theme()?
  $rows = array();
  $header = array(t('User'), t('Course'), t('Operations'));
  $rows = array(
    // Simple row
    array('Fred Flintstone', 'Course 101', 'View | Edit | Email'),
    array('Fred Flintstone', 'Course 102', 'View | Edit | Email'),
    array('Joan Smith', 'Course 102', 'View | Edit | Email'),
  );

  $caption = t('');
  $output = theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'certificates-history'), 'caption' => $caption));
  $output .= drupal_render($form);

  return $output;
}

/**
 * Form to select which content profile field values are part of which group.
 */
function certificate_field_grouping_form($form, &$form_state) {
  $form = array();
  $types = field_info_instances('profile2');
  $types += field_info_instances('user');
  if (!empty($types)) {

    $groupsinfo = variable_get('certificate_field_groups', array());
    $fieldgroups = variable_get('certificate_field_grouping', array());

    $form['map']['#tree'] = TRUE;
    // Create multiselect box for each field key.
    foreach ($groupsinfo as $key => $title) {
      $form['map'][$key] = array(
        '#type' => 'fieldset',
        '#title' => check_plain($title),
        '#tree' => TRUE,
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      foreach ($types as $bundle_name => $fields) {
        foreach ($fields as $field) {
          $field_info = field_info_field($field['field_name']);
          if ($field_info['module'] == 'list') {
            $options = list_allowed_values($field_info);
            if (!empty($options)) {
              $form['map'][$key][$field['field_name']] = array(
                '#title' => check_plain($field['label']),
                '#type' => 'select',
                '#multiple' => TRUE,
                '#options' => $options,
                // This is a trick to set the default value to ' ', which doesn't
                // match anything. This was accidentally causing 'None' to
                // actually be selected as a mapping.
                '#default_value' => isset($fieldgroups[$key][$field['field_name']]) ? $fieldgroups[$key][$field['field_name']] : array(),
              );
            }
          }
        }
      }
    }
  }
  else {
    $form['disabled']['#markup'] = '<p>' . t('No valid profile fields found on either the core profile entity or Profile2 profiles.') . '</p>';
  }

  $form['submit'] = array(
    '#value' => 'Submit',
    '#type' => 'submit',
  );

  return $form;
}

/**
 * Save content profile field grouping.
 */
function certificate_field_grouping_form_submit(&$form, &$form_state) {
  variable_set('certificate_field_grouping', $form_state['values']['map']);

  drupal_set_message(t('Grouping settings updated.'));
}

/**
 * Form to add a field grouping.
 */
function certificate_field_grouping_add_form($form, &$form_state) {
  $form = array();

  $form['fieldgroup_title'] = array(
    '#title' => 'Title of field group',
    '#type' => 'textfield',
    '#required' => TRUE,
  );

  $form['fieldgroup_name'] = array(
    '#type' => 'machine_name',
    '#title' => 'Machine name of field group',
    '#required' => TRUE,
    '#machine_name' => array(
      'source' => array('fieldgroup_title'),
      'label' => 'Machine name',
      'exists' => 'certificate_field_grouping_machine_name_exists',
    ),
  );


  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Create',
  );

  return $form;
}

/**
 * Validate the fieldgroup machine name.
 */
function certificate_field_grouping_machine_name_exists($value) {
  $fieldgroups = variable_get('certificate_field_groups', array());
  return isset($fieldgroups[$value]);
}

/**
 * Form to add another field group.
 */
function certificate_field_grouping_add_form_submit(&$form, &$form_state) {
  $fieldgroup_name = $form_state['values']['fieldgroup_name'];
  $fieldgroup_title = $form_state['values']['fieldgroup_title'];

  $fieldgroups = variable_get('certificate_field_groups', array());
  $fieldgroups[$fieldgroup_name] = $fieldgroup_title;
  variable_set('certificate_field_groups', $fieldgroups);
  drupal_set_message(t('Fieldgroup %f created.', array('%f' => $fieldgroup_name)));
  drupal_goto('admin/structure/certificates/mapping/groups');
}

/**
 * Fieldgroup deletion.
 */
function certificate_field_grouping_delete_form_submit(&$form, &$form_state) {
  $fieldgroup_name = $form_state['values']['fieldgroup_name'];
  $fieldgroup_title = $form_state['values']['fieldgroup_title'];
  $fieldgroups = variable_get('certificate_field_groups', array());
  unset($fieldgroups[$fieldgroup_name]);
  variable_set('certificate_field_groups', $fieldgroups);

  drupal_set_message(t('Fieldgroup %f deleted.', array('%f' => $fieldgroup_name)));
  drupal_goto('admin/structure/certificates/mapping/groups');
}

/**
 * Fieldgroup deletion form.
 */
function certificate_field_grouping_delete_form($form, $key) {
  $form = array();

  $form['fieldgroup_name'] = array(
    '#type' => 'hidden',
    '#value' => $key,
    '#access' => FALSE,
  );

  return confirm_form($form, "Delete field group $key?", 'admin/structure/certificates/mapping/groups', 'This action cannot be undone. Access to matched certificates will be lost.', 'Delete', 'Cancel');
}

/**
 * List of certificates with links to add and edit.
 */
function certificate_templates_list() {
  $certificates = array();
  $sql = "SELECT * FROM {node} WHERE type = 'certificate' ORDER BY title";
  $result = db_query($sql);
  while ($row = $result->fetch(PDO::FETCH_ASSOC)) {
    $destination = drupal_get_destination();
    $certificates[] = array(
      'title' => filter_xss_admin($row['title']),
      'edit' => l(t('edit'), "node/{$row['nid']}/edit", array('query' => $destination, 'attributes' => array('class' => 'edit-link'))),
      'delete' => l(t('delete'), "node/{$row['nid']}/delete", array('query' => $destination, 'attributes' => array('class' => 'delete-link'))),
      'preview' => l(t('PDF'), "admin/structure/certificates/templates/preview/" . $row['nid'], array('attributes' => array('class' => 'preview-link'))),
    );
  }
  return theme('table', array('header' => array(t('Title'), t('Edit'), t('Delete'), t('Preview')), 'rows' => $certificates, 'empty' => t('No certificate templates have been added.')));
}

/**
 * General settings form.
 *
 * Currently only has the option to enable snapshots.
 */
function certificate_admin_settings_form($form, &$form_state) {
  $form = array();

  $form['certificate_snapshots'] = array(
    '#title' => 'Use certificate snapshots?',
    '#description' => 'Certificates will only be generated once per node/user.',
    '#type' => 'checkbox',
    '#default_value' => variable_get('certificate_snapshots', 0),
  );

  return system_settings_form($form);
}

/**
 * Form to clear certificate snapshots.
 */
function certificate_admin_clear_form($form, &$form_state) {
  $form = array();

  $header = array(
    array(),
    array(
      'data' => 'Title',
      'field' => 'n.title',
    ),
    array(
      'data' => 'Count',
      'field' => 'count',
    ),
  );

  $sql = "SELECT *, count(cs.uid) AS count FROM {certificate_snapshots} cs
  INNER JOIN {node} n ON (cs.nid = n.nid)
  GROUP BY cs.nid";

  $result = db_query($sql);
  $nids = array();
  while ($row = $result->fetch()) {
    $nids[$row->nid] = '';
    $form['cs']['title'][$row->nid]['#markup'] = $row->title;
    $form['cs']['count'][$row->nid]['#markup'] = $row->count;
  }

  $form['cs']['nids'] = array(
    '#type' => 'checkboxes',
    '#options' => $nids,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Clear',
  );

  return $form;
}

/**
 * Theme certificate_admin_clear_form.
 */
function theme_certificate_admin_clear_form($variables) {
  $form = $variables['form'];
  // TODO Please change this theme call to use an associative array for the $variables parameter.
  $header = array(
    theme('table_select_header_cell'),
    array(
      'data' => 'Title',
      'field' => 'n.title',
    ),
    array(
      'data' => 'Count',
      'field' => 'cs_count',
    ),
  );
  $rows = array();
  if (!empty($form['cs']['title'])) {
    foreach (element_children($form['cs']['title']) as $key) {
      $rows[] = array(
        drupal_render($form['cs']['nids'][$key]),
        drupal_render($form['cs']['title'][$key]),
        drupal_render($form['cs']['count'][$key]),
      );
    }
  }

  return theme('table', array('header' => $header, 'rows' => $rows, 'empty' => t('No snapshots to clear.'))) . drupal_render_children($form);
}

/**
 * Delete selected certificate snapshots.
 */
function certificate_admin_clear_form_submit(&$form, &$form_state) {
  $nids = array();

  foreach ($form_state['values']['nids'] as $nid => $delete) {
    if ($delete) {
      $nids[] = $nid;
    }
  }

  if (count($nids)) {
    db_delete('certificate_snapshots')
      ->condition('nid', $nids, 'IN')
      ->execute();
    drupal_set_message(t('Cleared certificate snapshots.'));
  }
  else {
    drupal_set_message(t('No items selected.'), 'error');
  }
}
