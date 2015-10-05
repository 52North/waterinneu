<?php
/**
 * Nodetitle plugin for Freelinking
 *
 * @file
 * Allows for a link like [[nodetitle:Freelinking filter]] to be expanded to
 * a link to the node titled "Freelinking filter" or a link to create the node.
 */

$freelinking['nodetitle'] = array(
  'indicator' => '/nt$|nodetitle|title/A',
  'callback' => 'freelinking_nodetitle_callback',
  'tip' => t('Click to view a local node.'),
  'run on view' => TRUE,
  'weight' => -10,
);

/**
 * Replacement callback for nodetitle plugin
 *
 * Resolve $target into a link to the node or display failure.
 *
 * @param $target
 * @param $plugin
 *
 * @return array|bool
 *   an array with node properties to build the link.
 */
function freelinking_nodetitle_callback($target, $plugin) {
  $link = _freelinking_nodetitle_prepare_link($target, $plugin['tip']);
  // If no node was found, identify proceed with configured failover.
  if (empty($link)) {
    return _freelinking_nodetitle_failure($target);
  }

  // Update defaults if needed.
  if (isset($target['text'])) {
    $link['title'] = check_plain($target['text']);
  }
  if (isset($target['tooltip'])) {
    $link['tooltip'] = $target['tooltip'];
  }

  // Return link structure.
  return array(
    $link['title'],
    $link['url'],
    array(
      'language' => $link['language'],
      'attributes' => array(
        'title' => $link['tooltip']
      ),
    ),
  );
}

/**
 * Nodetitle Settings Callback
 */
function freelinking_nodetitle_settings() {
  // Restrict nodetitle plugin to search specified content type
  $form['freelinking_nodetitle_linkcontenttype'] = array(
    '#title' => t('Only link to nodes belonging to the following content types:'),
    '#type' => 'checkboxes',
    '#options' => node_type_get_names(),
    '#default_value' => variable_get('freelinking_nodetitle_linkcontenttype', array()),
    '#description' => t('Lookup by title to will be restricted to this content type or these content types.'),
  );

  $failover_option['none'] = t('Do nothing');
  $failover_option['showtext'] = t('Show text (remove markup)');

  $extra_description = '';

  // if Create Node plugin is available, it's an option!
  if (module_exists('freelinking_prepopulate')) {
    $failover_option['create'] = t('Add a link to create content. (Without Permission: Access Denied)');
  }
  else {
    $extra_description .= '<br />'
      . t('Note: Enable the <strong>Freelinking Prepopulate</strong> submodule to add a content creation failover option.');
  }

  // if search is available, have a search failover
  if (module_exists('search')) {
    $failover_option['search'] = t('Add a link to Search Content');
  }
  else {
    $extra_description .= '<br /><strong>'
      . t('Note: Enable the %module module for internal search option.', array('%module' => 'Search'))
      . '</strong>';
    // if search is unavailable offer it's own (applicable)search fallback. [Google, etc]
    if (($search_plugin = variable_get('freelinking_search_failover', 'error')) != 'error') {
      $failover_option['search'] = t('Add a link to %search Search Content.',
        array('%search' => drupal_ucfirst($search_plugin)));
    }
  }
  $failover_option['error'] = t('Insert an error message');

  $form['freelinking_nodetitle_failover'] = array(
    '#title' => t('If a suitable content is not found'),
    '#type' => 'select',
    '#options' => $failover_option,
    '#default_value' => variable_get('freelinking_nodetitle_failover',
      _freelinking_nodetitle_default_failover()),
    '#description' => t('What should freelinking do when the page is not found?')
      . $extra_description,
  );
  return $form;
}

/**
 * Grab the nid associated with the title.
 * Attempt some degree of language sensibility.
 * @param array $target
 *
 * @return array
 */
function _freelinking_nodetitle_prepare_link($target, $tip) {
  $link_cache = &drupal_static(__FUNCTION__, array());
  $id = md5($target['dest']);
  if (!isset($link_cache[$id])) {
    $output = array();

    // First time accessing this node. Process it.
    $params['title'] = $target['dest'];
    $linktypes = variable_get('freelinking_nodetitle_linkcontenttype', array());

    // EntityFieldQuery does not support OR. We solve this by looping
    // through linktypes, halting when we've found a usable node.
    $all = $none = TRUE;
    foreach ($linktypes as $linktype => $value) {
      if ($value) {
        $none = FALSE;
      }
      else {
        $all = FALSE;
      }
    }

    $found = FALSE;
    if (!$none) {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node')
        ->propertyCondition('title', $target['dest'])
        ->propertyCondition('status', 1); // published nodes
      $result = $query->execute();
      if (isset($result['node'])) {
        foreach ($result['node'] as $item => $value) {
          if (!empty($linktypes[$value->type])) {
            $nodex = node_load($item);
            if (node_access('view', $nodex)) {
              $found = TRUE;
              break;
	    }
	  }
        }
      }
    }
    if ($found && isset($nodex)) {
      $tooltip = $target['tooltip'] ? $target['tooltip'] : $tip;
      $output = array(
        'title' => $nodex->title,
        'url' => 'node/' . $nodex->nid,
        'language' => isset($nodex->language) ? $nodex->language : LANGUAGE_NONE,
        'tooltip' => $tooltip,
      );
    }
    // Save processed data in static cache.
    $link_cache[$id] = $output;
  }

  return $link_cache[$id];
}

/**
 * Determining the proper failure response per plugin configuration
 */
function _freelinking_nodetitle_failure($target) {
  $failover = variable_get('freelinking_nodetitle_failover',
    _freelinking_nodetitle_default_failover());

  switch ($failover) {
    case 'create':
      return array('failover' => 'freelinking_prepopulate', 'target' => $target);
    case 'showtext':
      return array('failover' => 'showtext', 'target' => $target);
    case 'search':
      return array('failover' => 'search', 'target' => $target);
    case 'error':
      return array('failover' => 'error', 'message' => t('node title “%title” does not exist',
        array('%title' => $target['dest'])));

  }
  // do nothing
  return FALSE;
}

/**
 * Find the best default failover
 */
function _freelinking_nodetitle_default_failover() {
  if (module_exists('freelinking_prepopulate')) {
    return 'create node';
  }
  elseif (module_exists('search')) {
    return 'search';
  }
  return 'none';
}
