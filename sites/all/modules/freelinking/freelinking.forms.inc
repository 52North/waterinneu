<?php
/**
 * @file
 *   Constructs freelinking & module admin forms.
 */

/**
 * Build admin/settings page.
 */
function freelinking_settings($form, &$form_state) {
  $form = array();

  $plugins = freelinking_get_plugins();
  foreach ($plugins as $plugin => $definition) {
    $available_plugins[$plugin] = drupal_ucfirst($plugin);
    if (function_exists($definition['settings']) || isset($definition['token'])) {
      $plugin_with_settings[$plugin] = $definition['settings'];
    }
  }

  asort($available_plugins);
  $available_plugins = array_merge(array('NONE' => t('-None-')), $available_plugins);
  // set the default plugin
  $form['freelinking_default'] = array(
    '#title' => t('Plugin to use when not indicated in the freelink'),
    '#type' => 'select',
    '#multiple' => FALSE,
    '#options' => $available_plugins,
    '#default_value' => variable_get('freelinking_default', 'nodetitle'),
    '#description' => t('Default plugin to use when no indicator is specified. “Nodetitle” mimics previous versions of Freelinking.'),
  );

  $syntax['double_bracket'] = t('Standard') . ' - [[plugin:target|Title]]';
  $syntax['single_bracket'] = t('Single Bracket') . ' - [plugin:target|Title]';
  $syntax['markdown'] = 'Markdown - [Title](plugin:target)';

  $global_options = array(
    'ignore_upi' => t('Ignore unknown plugin indicators'),
    'ignore_code' => t('Ignore freelinking markup inside &lt;code&gt; blocks (N.I.)'),
  );

  $form['freelinking_options'] = array(
    '#title' => t('Freelinking global options'),
    '#type' => 'checkboxes',
    '#description' => t('These options are not specific to a plugin. Options marked "(N.I.)" are placeholders for planned new features and not implemented yet.'),
    '#options' => $global_options,
    '#default_value' => variable_get('freelinking_options', array()),
  );

  $form['markup'] = array(
    '#markup' => t('<div><strong>Increase performance</strong><br>Freelinking to nodes with access restrictions may cause access bypass if caching is enabled.</div>'),
  );

  $disable_cache = count(module_implements('node_grants'));
  if ($disable_cache) {
    variable_set('freelinking_enablecache', FALSE);
  }
  $form['freelinking_enablecache'] = array(
    '#title' => t('Enable cache for freelinks'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('freelinking_enablecache', FALSE),
    '#disabled' => $disable_cache,
    '#description' => $disable_cache ?
      t('Caching cannot be enabled because you have enabled modules defining node access restrictions.') :
      t('The cache may not be enabled even if this box is checked.'),
  );
  $form['freelinking_external_http_request'] = array(
    '#type' => 'checkbox',
    '#title' => t('Do not poll the URL for title and availability'),
    '#default_value' => variable_get('freelinking_external_http_request', FALSE),
    '#description' => t('Tick to not poll the URL (faster).  Will show URL, nid, or short name instead of title.  '),
  );

  // loop through plugin settings functions, adding a fieldset for each
  foreach ($plugin_with_settings as $plugin => $callback) {
    $form[$plugin] = array(
      '#title' => t('!plugin Plugin Settings', array('!plugin' => drupal_ucfirst($plugin))),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form[$plugin]['settings'] = call_user_func($callback);

    // If failover is already defined, let it be.
    $failover = 'freelinking_' . $plugin . '_failover';
    //    if (empty($form[$plugin]['settings'][$failover])) {
    _freelinking_failover_form($form, $plugin, $plugins[$plugin], $failover);
    //    }
  } // endforeach looping through plugins with settings

  $form['#submit'][] = 'freelinking_settings_submit';

  return system_settings_form($form);
}

/**
 * Custom submit handler for the freelinking_settings form.
 */
function freelinking_settings_submit($form, &$form_state) {
  $enablecache = $form_state['values']['freelinking_enablecache'];
    $oldenbcache = variable_get('freelinking_enablecache', FALSE);
  if ($oldenbcache != $enablecache) {
    $formats = db_select('filter', 'f')
      ->fields('f', array('format'))
      ->condition(db_and()->condition('module', 'freelinking')->condition('status', 1));

    $rrr = db_update('filter_format')
      ->expression('cache', $enablecache)
      ->condition('format', $formats, 'IN')
      ->execute();
  }
}

function _freelinking_failover_form(&$form, $plugin_name, $plugin, $setting_name) {
  if (isset($plugin['failover']) && is_array($plugin['failover'])) {
    foreach ($plugin['failover'] as $option) {
      $options[$option] = t('Use plugin !plugin', array('!plugin' => $option));
    }
    $options = array_merge($options, array('error' => t('Error Message'), 'NONE' => t('Do Nothing')));
    $form[$plugin_name]['settings'][$setting_name] = array(
      '#title' => t('Plugin Fallback Action'),
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => variable_get($setting_name, 'NONE'),
    );
  }
  elseif (isset($plugin['failover'])) {
    $form[$plugin_name]['settings'][$setting_name] = array(
      '#title' => t('Plugin Fallback Action'),
      '#type' => 'textfield',
      '#value' => variable_get($setting_name, $plugin['failover']),
      '#size' => 20,
      '#disabled' => TRUE,
    );
  }
}
