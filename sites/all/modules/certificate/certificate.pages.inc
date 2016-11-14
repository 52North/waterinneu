<?php

/**
 * @file certificate.pages.inc
 * Functions for generating certificates.
 */

/**
 * Get certificate for a specific node.
 */
function certificate_node_certificate($node) {
  global $user;

  $admin = user_access('administer certificates');
  $view_all = user_access('view all user certificates');

  // Use account of a different user if allowed.
  if (($admin || $view_all) && arg(3) > 0) {
    $account = user_load(arg(3));
  }
  else {
    $account = $user;
  }

  $perm = certificate_can_access_certificate($node, $account);

  if ($perm != 1) {
    //$perm is a string! show error.
    return $perm;
  }

  return certificate_single($account, $node);
}

/**
 * Generate a single certificate.
 *
 * Check to see if user already has a certificate for a course. If so, serve it from the DB. If not, generate one and save it to the DB.
 */
function certificate_single($account, $node) {
  $output = '';

  // Preview.
  $preview = isset($_GET['preview']) && user_access('administer certificates');

  $map_options = module_invoke_all('certificate_map_options');
  drupal_alter('certificate_map_options', $map_options);
  $sql = "SELECT * FROM {certificate_node} WHERE nid = 0 or nid = :nid ORDER BY nid ASC";
  $result = db_query($sql, array(':nid' => $node->nid));
  $mapping = array();
  while ($row = $result->fetch()) {
    $mapping[$row->mapper][$row->type] = $row->template;
  }

  $template_ids = array();
  foreach (array_keys($map_options) as $map_type) {
    if (!empty($mapping[$map_type])) {
      $matches = module_invoke_all('certificate_map', $node, $account, $map_type, array_keys(array_filter((array) $mapping[$map_type])), array());
      drupal_alter('certificate_map', $matches, $node, $account, $map_type, array_keys(array_filter((array) $mapping[$map_type])), array());
      if (count($matches)) {
        foreach ($matches as $match_key) {
          if ($mapping[$map_type][$match_key] > 0) {
            // This is a valid certificate ID.
            $template_ids[$mapping[$map_type][$match_key]] = $map_options[$map_type]['options'][$match_key];
          }
        }
      }
    }
  }

  // Alter the list of certificates the user is eligible to choose.
  drupal_alter('certificate_template_ids', $template_ids, $node, $account);

  if (count($template_ids) > 1) {
    if (is_numeric(arg(4))) {
      // User requested certificate.
      if (isset($template_ids[arg(4)])) {
        // User is eligible for this certificate.
        $template_id = arg(4);
      }
      else {
        return t('Not eligible for certificate.');
      }
    }
    else {
      // More than one certificate. Display a selection page.
      $page = array();
      $page['header'] = array(
        '#type' => 'item',
        '#markup' => t('You are eligible for multiple certificates.'),
      );
      foreach ($template_ids as $template_id => $name) {
        $name = filter_xss_admin(t($name));
        $rows[] = array(
          $name,
          l(t('Download'), "node/$node->nid/certificate/$account->uid/$template_id"),
        );
      }
      $page['certificates'] = array(
        '#type' => 'item',
        '#theme' => 'table',
        '#rows' => $rows,
      );
      return $page;
    }
  }
  else {
    $template_id = key($template_ids);
  }

  // Alter the final certificate template to load.
  drupal_alter('certificate_template_id', $template_id, $node, $account);

  $template = node_load($template_id);
  if ($template && $node) {
    // See if user already has a snapshotted certificate for a course. If so, grab
    // from the DB. If not, generate a new one.
    if (variable_get('certificate_snapshots', 0) && $snapshot = certificate_snapshot_load($account, $node, $template->nid)) {
      $output = $snapshot['snapshot'];
    }
    else {
      // Prepend output with UTF 8 meta tag.
      // See http://code.google.com/p/wkhtmltopdf/issues/detail?id=556
      // Print module gets around this because the meta tag in Drupal is already
      // set - but here, we have to add it since we are only delivering the node
      // body.
      $output = '<html><head><meta charset="utf-8"/></head><body>' . theme('certificate_certificate', array('node' => $node, 'account' => $account, 'template' => $template)) . '</body></html>';

      // Now save this generated certificate as a 'snapshot' in the database.
      $snapshot['uid'] = $account->uid;
      $snapshot['nid'] = $node->nid;
      $snapshot['cid'] = $template->nid;
      $date = getdate();
      $snapshot['date'] = $date[0];
      $snapshot['snapshot'] = $output;
      if (!$preview && variable_get('certificate_snapshots', 0)) {
        certificate_snapshot_save($snapshot);
      }
    }
  }
  else {
    return t('Sorry, there is no certificate available.');
  }

  $print_pdf_pdf_tool = variable_get('print_pdf_pdf_tool', '');
  if ($print_pdf_pdf_tool == '') {
    if ($account->uid == 1) {
      drupal_set_message(t('Certificate cannot be displayed because you have not selected a PDF generation tool in !link.', array('!link' => l('Printer, e-mail and PDF versions', 'admin/config/user-interface/print/pdf'))) . '.', 'error');
    }
    else {
      drupal_set_message(t('PDF generation tool is not configured.'));
    }
    return ' ';
  }

  module_load_include('pages.inc', 'print_pdf', 'print_pdf');

  if ($preview) {
    print $output;
  }
  else {
    certificate_print_pdf_wrapper($node->title . '.pdf', $output, isset($template) ? $template->certificate['orientation'] : variable_get('print_pdf_page_orientation', PRINT_PDF_PAGE_ORIENTATION_DEFAULT));
  }
}

/**
 * Preview certificate template as PDF.
 */
function certificate_preview($template_id) {
  global $user;
  $template = node_load($template_id);
  if ($template) {
    $output = '<html><head><meta charset="utf-8"/></head><body>' . theme('certificate_certificate', array('node' => NULL, 'account' => $user, 'template' => $template)) . '</body></html>';
  }

  $print_pdf_pdf_tool = variable_get('print_pdf_pdf_tool', '');
  if ($print_pdf_pdf_tool == '') {
    drupal_set_message(t('Certificate cannot be displayed because you have not selected a PDF generation tool in !link.', array('!link' => l('Printer, e-mail and PDF versions', 'admin/config/user-interface/print/pdf'))) . '.', 'error');
    return '';
  }

  certificate_print_pdf_wrapper($template->title . '.pdf', $output, $template->certificate['orientation']);
}

/**
 * Theme a single certificate.
 *
 * Does token replace (new style [], and old style %)
 *
 * @param $account
 *   The user account being viewed.
 *
 * @ingroup themeable
 *
 * @return The certificate HTML with all tokens translated.
 */
function theme_certificate_certificate($variables) {
  $node = $variables['node'];
  $account = $variables['account'];
  $template = $variables['template'];
  $types = array(
    'global' => NULL,
    'node' => $node,
    'user' => $account,
  );

  $field_items = field_get_items('node', $template, 'body');
  $body = $field_items[0]['value'];

  // Invoke hook_certificate_body_alter() to allow all modules to alter the template body.
  drupal_alter('certificate_body', $body, $account, $node);

  if (module_exists('token')) {
    if (module_exists('purl')) {
      purl_disable(TRUE);
    }

    // Clear out un-replaced tokens and use a custom callback, so that we can
    // have HTML tokens render in the PDF. We probably do not need to sanitize
    // here as the output is PDF, but it doesn't hurt.
    $options = array();
    $options['clear'] = TRUE;
    $options['sanitize'] = FALSE;
    $options['callback'] = '_certificate_sanitize_tokens';

    $body = token_replace($body, $types, $options);
  }

  $format = $field_items[0]['format'];
  $body = check_markup($body, $format);

  return $body;
}

/**
 * Wrapper to use correct Print API functions across versions.
 */
function certificate_print_pdf_wrapper($filename, $html, $orientation) {
  module_load_include('pages.inc', 'print_pdf', 'print_pdf');
  module_load_include('inc', 'print', 'includes/print');

  // Rewrite image URLs using Print.
  $pattern = '!<(img\s[^>]*?)>!is';
  $html = preg_replace_callback($pattern, '_print_rewrite_urls', $html);

  if (function_exists('_print_scan_libs')) {
    // Print 2.x
    $meta = array(
      'url' => url(current_path(), array('absolute' => TRUE)),
      'name' => '',
      'title' => '',
      'node' => NULL,
    );
    print_pdf_generate_html($html, $meta, $filename, NULL, $orientation);
  }
  else {
    // Print 1.x
    global $conf;
    $conf['print_pdf_page_orientation'] = $orientation;
    $print = array(
      'url' => url(current_path(), array('absolute' => TRUE)),
      'node' => NULL,
    );
    print_pdf_generate_html($print, $html, $filename);
  }

  exit;
}

/**
 * Call filter_xss on each of the items in the replacements array.
 */
function _certificate_sanitize_tokens(&$replacements) {
  foreach ($replacements as $token => &$replacement) {
    $replacement = filter_xss_admin($replacement);
  }
}
