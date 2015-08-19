<?php
/**
 * Handle a NPS sort.
 *
 * @ingroup views_sort_handlers
 */
class wsfields_views_handler_sort extends views_handler_sort {

  function query() {
  }

  function post_execute(&$values) {
    $field = substr($this->field, 0, -1 * strlen('_sort'));
    $entity_type = $this->table;
    $entity_info = entity_get_info($entity_type);
    $key = $entity_info['entity keys']['id'];

    $ids = array();
    foreach ($values as $value) {
      $ids[] = $value->$key;
    }

    $entities = entity_load($entity_type, $ids);
    $index = array();
    foreach ($entities as $id => $entity) {
      $lang = current($entity->$field);
      $delta = current($lang);
      $index[$id] = $delta['value'];
    }
    asort($index);

    $newvalues = array();
    foreach($index as $id => $tmp) {
      foreach($values as $location => $value) {
        if ($value->$key == $id) {
          $newvalues[] = $value;
          break;
        }
      }
    }
    $values = $newvalues;
  }
}
