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

  /**
   * Overrides EntityAPIController::query().
   */
  public function query($ids, $conditions, $revision_id = FALSE) {
    $query = $this->buildQuery($ids, $conditions, $revision_id);
    $query->join('course_outline', 'co', 'base.coid = co.coid');
    $query->fields('co', array('module', 'object_type'));
    $result = $query->execute();
    $result->setFetchMode(PDO::FETCH_ASSOC);

    // Build the resulting objects ourselves, since the standard PDO ways of
    // doing that are completely useless.
    $objects = array();
    foreach ($result as $row) {
      $row['is_new'] = FALSE;
      $objects[] = $this->create($row);
    }
    return $objects;
  }

  /**
   * Overrides EntityAPIController::create().
   */
  public function create(array $values = array()) {

    // Add is_new property if it is not set.
    $values += array('is_new' => TRUE);

    $available = course_get_handlers('object');
    $ret = $available[$values['module']][$values['object_type']];
    if (isset($ret['fulfillment class'])) {
      $class = $ret['fulfillment class'];
    }
    else {
      // Base class which minimally handles fulfillments.
      $class = 'CourseObjectFulfillment';
    }


    return new $class($values, $this->entityType);
  }

}
