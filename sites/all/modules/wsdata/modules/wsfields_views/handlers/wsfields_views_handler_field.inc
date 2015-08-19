<?php

/**
 * @file
 * Definition of wsfields_views_handler_field.
 */

/**
 * Field handler to present data from wsfields
 *
 * @ingroup views_field_handlers
 */
class wsfields_views_handler_field extends views_handler_field_entity {

  function get_value($values, $field = NULL) {
    $field = $this->field;

    if (isset($this->entities[$this->view->row_index])) {
      $entity = $this->entities[$this->view->row_index];

      // Support to get a certain part of the entity.
      if (isset($field) && isset($entity->{$field})) {
        $ret = array();

        foreach ($entity->{$field} as $lang => $deltas) {
          foreach ($deltas as $values) {
            $ret[] = $values['safe_value'];
          }
        }
        $ret = implode(', ', $ret);
        return $ret;
      }
    }
    return FALSE;
  }

  function render($values) {
    return $this->get_value($values);
  }

}
