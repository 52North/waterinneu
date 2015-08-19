<?php
/**
 * @file remote_entity.info.inc
 * TODO: Enter file description here.
 */

/**
 * Implements hook_entity_property_info().
 */
 // NO! NOT NEEDED! See controller!
function XXXXXXremote_entity_entity_property_info() {
  $info = array();
  $properties = &$info['node']['properties'];

  // ALL WRONG TODO TODO!!!!!!!!!
  $properties['nid'] = array(
    'label' => t("Content ID"),
    'type' => 'integer',
    'description' => t("The unique content ID."),
  );
  return $info;
}
