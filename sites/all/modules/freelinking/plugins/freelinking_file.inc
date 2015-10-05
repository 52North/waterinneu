<?php
/**
 * @file
 * File plugin. Builds links to files in the file system
 */

$freelinking['file'] = array(
  'indicator' => '/^file$/i',
  'callback' => 'freelinking_file_file_callback',
  'settings' => 'freelinking_file_file_settings',
  'tip' => t('Click to view a local file.'),
);

/**
 * File plugin callback.
 * Builds a link to a file.
 *
 * @return
 *   array with link settings.
 */
function freelinking_file_file_callback($target, $plugin) {
  // Remove slash if it's present at first character
  $path = preg_replace('/^\//', '', $target['dest']);
  if (isset($target['other']['file_path'])) {
    $path = $target['other']['file_path'] . '/' . $path;
  }
  else {
    $path = variable_get('freelinking_file_file_path', file_default_scheme() . '://') . $path;
  }

  if (!file_exists($path)) {
    return array(
      'failover' => 'error',
      'message' => t('File @name not found', array('@name' => basename($path))),
    );
  }

  // Check access permissions
  $headers = module_invoke_all('file_download', $path);
  if (in_array(-1, $headers)) {
    return array(
      'failover' => 'error',
      'message' => t('File not found')
    );
  }

  // Build link
  if ($target['text']) {
    $title = $target['text'];
  }
  else {
    $title = basename($path);
  }
  $url = file_create_url($path);

  return array(check_plain($title), $url);
}

/**
 * Form settings for file plugin
 *
 * @return
 *   array form structure
 */
function freelinking_file_file_settings() {
  $path = file_default_scheme() . '://';
  $form['freelinking_file_file_path'] = array(
    '#title' => t('File Basepath'),
    '#type' => 'textfield',
    '#default_value' => variable_get('freelinking_file_file_basepath', $path),
    '#description' => t('Set the base path for files. Files should usually begin with !path',
      array('!path' => $path)),
  );
  return $form;
}
