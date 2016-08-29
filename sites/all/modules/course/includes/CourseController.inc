<?php

class CourseController extends EntityAPIController {

  function load($ids = array(), $conditions = array()) {
    $entities = parent::load($ids, $conditions);
    return $entities;
  }

}
