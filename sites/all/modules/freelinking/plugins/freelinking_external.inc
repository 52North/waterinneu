<?php
/**
 * Freelinking External Plugin
 * 
 * @file
 *   Supports the creation of links by url
 * 
 *   Syntax:
 *     [[http://yourlink|Your Title]]
 *     [[https://yourlink|Your Title]]
 *     [[ext:yourlink|Your Title]]
 */
$freelinking['external'] = array(
  'indicator' => '/^http$|^ext/',
  'callback' => 'freelinking_external_callback',
  'tip' => t('Click to visit an external URL.'),
  'protocol' => ''
);
$freelinking['external_ssl'] = array(
  'indicator' => '/^https/',
  'callback' => 'freelinking_external_callback',
  'tip' => t('Click to visit an external secure URL.'),
  'protocol' => 's'
);

function freelinking_external_callback($target, $plugin) {
  $dest = ltrim ($target['dest'], '/');
  $url = "http$plugin[protocol]://$dest";
  $scrape = !variable_get('freelinking_external_http_request', TRUE);
  if ($scrape) {
    $result = drupal_http_request($url, array('headers' => array()));
    if (!$result->code || (400 <= $result->code)) {
      return array(
        'failover' => 'error',
        'message' => t('External target “@url” not found', array('@url' => $url)),
      );
    }
  }
  $tooltip = $target['tooltip'] ? $target['tooltip'] : $plugin['tip'];

  if (!$target['text'] && $scrape) {
    $found_title = preg_match('/<h1.*>(.*)<\/h1>/', $result->data, $matches);
    if ($found_title) {
      if (strlen($matches[1]) < 3) {
        $found_title = preg_match('/<h2.*>(.*)<\/h2>/', $result->data, $matches);
      }
    }
    if ($found_title) { // regex to scrape title from page worked.
      $replacement = array(
       t('Ext. link: “@title”', array('@title' => $matches[1])),
        check_url($url),
        array('attributes' => array('title' => $tooltip))
      );
    }
  }
  elseif ($target['text']) {
    $replacement = array(
      check_plain($target['text']),
      check_url($url),
      array('attributes' => array('title' => $tooltip))
    );
  }
  if (empty($replacement)) {
    $replacement = array(
      check_plain($url),
      check_url($url),
      array('attributes' => array('title' => $tooltip))
    );
  }
  return $replacement;
}
