<?php
/** nid plugin for freelinking
 * Originially by [grayside](http://drupal.org/user/346868)
 * See http://drupal.org/node/486954
 *
 * @file
 * Allows for a link like [[node:<nid>]], [[n:<nid>]], or [[node:<nid>]] to be
 * expanded to a link to the node with the title associated with that nid.
 * A "could not find nid" message is displayed if the nid could not be found.
 */

$freelinking['nid'] = array(
  'indicator' => '/(n(id|ode)?)$/A',
  'callback' => 'freelinking_nid_callback',
  'tip' => t('Click to view a local node.'),
  'run on view' => TRUE,
);

/**
 * Replacement callback for nid plugin.
 *
 * Resolve $target into a link to the node or display failure.
 *
 * @return
 *   an array with node properties to build the link.
 */
function freelinking_nid_callback($target, $plugin) {
  $node_cache_nid = &drupal_static(__FUNCTION__ . '_node_cache', array());
  // Check if we already loaded this node.
  $nid = $target['dest'];
  $nodes = &drupal_static(__FUNCTION__, array());
  if (in_array($nid, $nodes)) {
    // Return TRUE to avoid infinite recursion.
    $key = array_search($nid, $node_cache_nid['nid']);
    $value = array(
      $target['text'],
      'node/' . $nid,
      array('attributes' => array('title' => $target['tooltip']))
    );
    return $value;
  }
  // New node to process. Cache it at the end.
  $node = node_load($nid);
  if ($node) {
    if (node_access('view', $node)) {
      $title = $target['text'] ? $target['text'] : $node->title;
      $tooltip = $target['tooltip'] ? $target['tooltip'] : $plugin['tip'];
      $value = array(
        check_plain($title),
        'node/' . $nid,
        array('attributes' => array('title' => $tooltip))
      );
      // Add the nid to the list of cached nodes.
      $nodes[] = $nid;
      $node_cache_nid['nid'][] = $node->nid;
    }
  }
  if (!isset($value)) {
    $value = array(
      'failover' => 'error',
      'message' => t('Invalid Node ID “!nid”', array('!nid' => $nid)),
    );
  }
  return $value;
}
