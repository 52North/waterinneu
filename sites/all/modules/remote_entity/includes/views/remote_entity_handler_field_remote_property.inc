<?php

/**
 * Generic Views field handler for showing remote entity properties.
 */
class remote_entity_handler_field_remote_property extends views_handler_field_entity {

  /**
   * Render the field.
   */
  function render($values) {
    if ($entity = $this->get_value($values)) {
      // Go via the wrapper in case entity type modules set their own property
      // getter callback.
      $wrapper = entity_metadata_wrapper($this->entity_type, $entity);
      $property = $this->definition['property name'];

      return $wrapper->{$property}->value();
    }
  }

}
