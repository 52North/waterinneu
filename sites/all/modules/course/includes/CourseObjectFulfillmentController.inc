<?php

class CourseObjectFulfillmentController extends EntityAPIController {

  /**
   * Fork of Entity API's "merge" functionality.
   *
   * Merge the serialized field to the entity object.
   */
  function load($ids = array(), $conditions = array()) {
    $entities = parent::load($ids, $conditions);


    $base_table = $this->entityInfo['base table'];
    $schema = drupal_get_schema($base_table);
    foreach ($schema['fields'] as $field_name => $info) {
      if (!empty($info['serialize'])) {
        $serialized_field = $field_name;
      }
    }

    foreach ($entities as $courseObject) {
      $reflect = new ReflectionClass($courseObject);
      foreach ($reflect->getProperties(ReflectionProperty::IS_PRIVATE | ReflectionProperty::IS_PROTECTED) as $prop) {
        $props[] = $prop->getName();
      }
      if (isset($courseObject->$serialized_field) && is_array($courseObject->$serialized_field)) {
        foreach ($courseObject->$serialized_field as $field => $value) {
          if (!in_array($field, $props)) {
            $courseObject->setOption($field, $value);
          }
        }
      }
      $courseObject->setOption('is_new', 0);
    }
    return $entities;
  }

}
