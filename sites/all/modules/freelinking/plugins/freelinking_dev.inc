<?php
/**
 * Drupal Developer Plugins
 *
 * drupalorg, drupalproject
 */

/*
 * Allows for a link like [[drupalorg:12345]] to be expanded to
 * a link to www.drupal.org/node/12345
 */
$freelinking['drupalorg'] = array(
  'indicator' => '/^d(rupal)?o(rg)?$/',
  'callback' => 'freelinking_drupaldev_callback',
  'tip' => t('Click to view node on Drupal.org.'),
  'replacement' => 'https://www.drupal.org/node/%1',
);

/*
 * Allows for a link like [[drupalproject:freelinking]] to be expanded to
 * www.drupal.org/project/freelinking
 */
$freelinking['drupalproject'] = array(
  'indicator' => '/^d(rupal)?project/',
  'callback' => 'freelinking_drupaldev_callback',
  'tip' => t('Click to view project on Drupal.org.'),
  'replacement' => 'https://www.drupal.org/project/%1',
);

/**
 * Builds a link to a node in Drupal.org.
 *
 * @return
 *   array with link details.
 */
function freelinking_drupaldev_callback($target, $plugin) {
  if ('/^d(rupal)?project/' == $plugin['indicator']) {
    $message = t('Drupal.org/project/@project not found', array('@project' => $target['dest']));
  }
  else {
    if (!is_numeric($target['dest'])) {
      return array(
        'failover' => 'error',
        'message' => t('Invalid node id @nid', array('@nid' => $target['dest'])),
      );
    }
    $message = t('Drupal.org/node/@nid not found', array('@nid' => $target['dest']));
  }
  $scrape = !variable_get('freelinking_external_http_request', TRUE);
  $url = check_url(preg_replace('/%1/', $target['dest'], $plugin['replacement']));
  if ($scrape) {
    $result = drupal_http_request($url, array('headers' => array()));
    if (!$result->code || (400 <= $result->code)) {
      return array(
        'failover' => 'error',
        'message' => $message,
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
        t('Drupal.org: “@title”', array('@title' => $matches[1])),
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
    $prefix = is_numeric($target['dest']) ? '#' : '';
    $replacement = array(
      t('Drupal.org: “!prefix@title”', array('!prefix' => $prefix, '@title' => $target['dest'])),
      check_url($url),
      array('attributes' => array('title' => $tooltip))
    );
  }
  return $replacement;
}
