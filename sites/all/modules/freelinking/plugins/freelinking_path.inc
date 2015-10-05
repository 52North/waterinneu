<?php
/**
 * Freelinking Path Plugin
 *
 * @file
 *   Supports the creation of links by url or internal path.
 *
 *   Syntax:
 *     [[path:/node/321]]
 *     [[path:breaking-news]]
 *     [[path:../wiki/moderators/bill]]
 *
 * Note that if the current path alias (or menu path) is changed,
 * relative links will not be updated to reflect the new location.
 */

$freelinking['path'] = array(
  'indicator' => '/path|alias/i',
  'callback' => 'freelinking_path_callback',
  'settings' => 'freelinking_path_settings',
  'tip' => t('Click to view a local node.'),
  'failover' => array('search'),
);

/**
 * Builds a link to an internal url 
 *
 * @return
 *   array with link properties
 */
function freelinking_path_callback($target, $plugin) {
  // the first character is not a forward slash
  $pos = strpos($target['dest'], '/');
  if ($pos === FALSE || $pos > 0) {
    $path = variable_get('freelinking_path_basepath', $_GET['q'])
      . '/' . $target['dest'];
  }
  elseif ($pos == 0) {
    // scrape off the starting slash that marks this as an unmodified path from site root.
    $path = substr($target['dest'], 1);
  }

  //$node_cache_path = &drupal_static(__FUNCTION__ . '_node_cache', array());
  // Check if we already loaded this node.

  $item = menu_get_item(drupal_get_normal_path($path));
  if (NULL == $item || !$item['access']) {
    return array(
      'failover' => variable_get('freelinking_path_failover', 'error'),
      'message' => t('path “%path” not found', array('%path' => $target['dest'])),
    );
  }
  if ($target['text']) {
    $title = $target['text'];
  }
  elseif ($item) {
    $title = $item['title'];
  }
  else {
    $title = $path;
  }

  $value = array(
    $title,
    $path,
    array('attributes' => array('title' => $target['tooltip']))
  );
  return $value;
}

/**
 * Settings form for path module 
 * 
 * @return
 *   array form properties
 */
function freelinking_path_settings() {
  $form['freelinking_path_basepath'] = array(
    '#type' => 'textfield',
    '#title' => t('Starting path for relative links'),
    '#default_value' => variable_get('freelinking_path_basepath', ''),
    '#description' => t('Set the  “base directory” internal to the site that all relative path links will build from (e.g. “node”). Leave empty for site root. (Relative path links have no initial slash or ending slash.)'),
  );

  return $form;
}

