<?php
/**
 * Freelinking User Plugins
 *
 * @file
 *   Provides automatic link creation to user profile pages.
 */

$freelinking['user'] = array(
  'indicator' => '/(u|user|username|uid|userid)$/A',
  'tip' => t('Click to view user profile.'),
  'callback' => 'freelinking_user_callback',
  'failover' => array('search'),
);

/**
 * Builds a link to a user profile
 *
 * @return
 *   array to build the link
 */
function freelinking_user_callback($target, $plugin) {
  if (user_access('access user profiles')) {
    if (is_numeric($target['dest'])) {
      $user = user_load($target['dest']);
    }
    else {
      $foo = user_load_multiple(array(), array('name' => $target['dest']));
      $user = array_shift($foo);
    }
    if ($user) {
      $title = $target['text'] ? $target['text'] : $user->name;
      $url = 'user/' . $user->uid;
      $tooltip = $target['tooltip'] ? $target['tooltip'] : $plugin['tip'];

      return array(check_plain($title), $url, array('attributes' => array('title' => $tooltip)));
    }
    else {
      return array(
        'failover' => variable_get('freelinking_user_failover', 'error'),
        'message' => t('User “%user” not found', array('%user' => $target['dest']))
      );
    }
  }
  else {
    return array(
      'failover' => variable_get('freelinking_user_failover', 'error'),
      'message' => t('Unauthorized to view user profile', array('%user' => $target['dest']))
    );
  }
}
