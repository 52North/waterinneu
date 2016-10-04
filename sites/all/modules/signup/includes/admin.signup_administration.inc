<?php
/**
 * @file
 * Code related to the Signup administration page (admin/content/signup).
 */

/**
 * Print the admin signup overview page located at admin/people/signup.
 */
function signup_admin_page() {
  $filter_status_form = drupal_get_form('signup_filter_status_form');
  $signup_admin_form = drupal_get_form('signup_admin_form');
  return array(
    '#theme' => 'signup_admin_page',
    '#attached' => array(
      'css' => array(drupal_get_path('module', 'signup') . '/signup.css'),
    ),
    '#filter_status_form' => $filter_status_form,
    '#signup_admin_form' => $signup_admin_form,
  );
}

/**
 * Form builder for the signup status filter on the signup administration page.
 */
function signup_filter_status_form($form, &$form_state) {
  $options = array(
    'all' => t('All'),
    'open' => t('Open'),
    'closed' => t('Closed'),
  );
  if (empty($_SESSION['signup_status_filter'])) {
    $_SESSION['signup_status_filter'] = 'all';
  }
  $form['filter'] = array(
    '#type' => 'select',
    '#title' => t('Filter by signup status'),
    '#options' => $options,
    '#default_value' => $_SESSION['signup_status_filter'],
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
  );
  return $form;
}

/**
 * Submit handler for the status filter on the signup administration page.
 */
function signup_filter_status_form_submit($form, &$form_state) {
  $_SESSION['signup_status_filter'] = $form_state['values']['filter'];
}

/**
 * Form builder for the main form on the signup administration page.
 */
function signup_admin_form($form, &$form_state) {
  // Build the sortable table header.
  $header = array(
    'title' => array('data' => t('Title'), 'field' => 'n.title', 'sort' => 'asc'),
    'total' => array('data' => t('Signups'), 'field' => 'signup_total'),
    'limit' => array('data' => t('Limit'), 'field' => 'signup_close_signup_limit'),
    'status' => array('data' => t('Status'), 'field' => 'signup_status'),
    'operations' => array('data' => t('Operations')),
  );
 
  $start_column = signup_admin_form_header();
  if (!empty($start_column)) {
   $header = array('start' => $start_column) + $header;
  }

  // Prepare the list of nodes.
  $nodes = signup_admin_form_query($header);
  $destination = drupal_get_destination();
  $options = array();
  foreach ($nodes as $node) {
    $form['limit'][$node->nid] = array(
      '#type' => 'textfield',
      '#title' => t('Limit'),
      '#title_display' => 'invisible',
      '#default_value' => $node->signup_close_signup_limit,
      '#size' => 3,
    );
    $form['status'][$node->nid] = array(
      '#type' => 'select',
      '#title' => t('Status'),
      '#title_display' => 'invisible',
      '#options' => array(
        0 => t('Closed'),
        1 => t('Open'),
       ),
      '#default_value' => $node->signup_status,
    );
    $options[$node->nid] = array(
      'start' => signup_format_date($node),
      'title' => array(
        'data' => array(
          '#type' => 'link', 
          '#title' => check_plain($node->title), 
          '#href' => 'node/' . $node->nid, 
        ),
      ),
      'total' => $node->signup_total,
      'limit' => $node->signup_close_signup_limit,
      'status' => $node->signup_status ? t('Open') : t('Closed'),
    );

    // Build a list of all the accessible operations for the current node.
    $operations = array();
    $operations['view'] = array(
      'title' => t('View signups'), 
      'href' => 'node/' . $node->nid . '/signups', 
      'query' => $destination,
    );
    if (user_access('email all signed up users')) {
      $operations['broadcast'] = array(
        'title' => t('Broadcast'), 
        'href' => 'node/' . $node->nid . '/signups/broadcast', 
        'query' => $destination,
      );
    }

    $options[$node->nid]['operations'] = array();
    if (count($operations) > 1) {
      // Render an unordered list of operations links.
      $options[$node->nid]['operations'] = array(
        'data' => array(
          '#theme' => 'links__node_operations', 
          '#links' => $operations, 
          '#attributes' => array('class' => array('links', 'inline')),
        ),
      );
    }
    elseif (!empty($operations)) {
      // Render the first and only operation as a link.
      $link = reset($operations);
      $options[$node->nid]['operations'] = array(
        'data' => array(
          '#type' => 'link', 
          '#title' => check_plain($link['title']), 
          '#href' => $link['href'], 
          '#options' => array('query' => $link['query']),
        ),
      );
     }
   }

  $form['nodes'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No content available.'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
  );

  $form['pager'] = array('#markup' => theme('pager'));

  $form['#tree'] = TRUE;
  $form['#after_build'] = array('signup_admin_form_after_build');

  return $form;
}

/*
 * Move some form elements to their right place.
 */
function signup_admin_form_after_build($form) {
  $limit = $form['limit'];
  $status = $form['status'];
  $options = $form['nodes']['#options'];

  foreach ($options as $nid => $node) {
    $options[$nid]['limit'] = array('data' => $limit[$nid]);
    $options[$nid]['status'] = array('data' => $status[$nid]);
  }

  $form['nodes']['#options'] = $options;
  unset($form['limit'], $form['status']);

  return $form;
}

/**
 * Helper function to determine if we need to display a date for the events.
 */
function signup_admin_form_header() {
  if (module_exists('date')) {
    // If we're using date, we can't sort since the date field used for
    // each content type can come from different tables.
    return array('data' => t('Start'), 'field' => NULL);
  }
  elseif (module_exists('event')) {
    // If we've got event, but not date, we can sort by e.event_start.
    return array('data' => t('Start'), 'field' => 'e.event_start');
  }
  // If we've got no scheduling backend at all, there's no start time column.
  return array();
}

/**
 * The database query to get the needed information of nodes with signups. 
 */
function signup_admin_form_query($header) {
  $query = db_select('node', 'n')->extend('PagerDefault')->extend('TableSort');

  if (isset($_SESSION['signup_status_filter']) && $_SESSION['signup_status_filter'] != 'all') {
    $status = ($_SESSION['signup_status_filter'] == 'open') ? 1 : 0;
    $query->condition('s.status', $status);
   }

  $query->innerJoin('signup', 's', 's.nid = n.nid');
  $query->leftJoin('signup_log', 's_l', 's.nid = s_l.nid');

  $query->fields('n', array('nid', 'title', 'type', 'language'));

  $query->addField('s', 'status', 'signup_status');
  $query->addField('s', 'close_signup_limit', 'signup_close_signup_limit');

  $query->addExpression('COUNT(s_l.nid)', 'signup_total');

  $query->groupBy('nid');
  $query->groupBy('title');
  $query->groupBy('type');
  $query->groupBy('signup_status');
  $query->groupBy('signup_close_signup_limit');

  // Get the right query elements from the currently installed scheduler backend.
  foreach (signup_content_types() as $content_type) {
    signup_admin_query($query, $content_type);
  }

  $nodes = $query
    ->limit(25)
    ->orderByHeader($header)
    ->execute();

  return $nodes;
}

/**
 * Form submission handler for signup_admin_form().
 *
 * @see signup_admin_form()
 */
function signup_admin_form_submit($form, &$form_state) {
  $limit = $form_state['values']['limit'];
  $status = $form_state['values']['status'];
  $nodes = $form_state['values']['nodes'];

  module_load_include('inc', 'signup', 'includes/node_admin_summary');
  foreach ($nodes as $nid => $selected) {
    if ($selected) {
      $temp_state['values'] = array(
        'nid' => $nid,
        'limit' => $limit[$nid],
        'status' => $status[$nid],
      );
      signup_node_admin_summary_form_submit($form, $temp_state);
    }
  }
}
