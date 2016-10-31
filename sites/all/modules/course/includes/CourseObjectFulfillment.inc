<?php

/**
 * Parent class for course object fulfillment.
 *
 * Represents the fulfillment record in the database.
 *
 */
class CourseObjectFulfillment extends CourseHandler {

  /**
   * Is this fulfillment complete?
   *
   * @return bool
   */
  function isComplete() {
    return (bool) $this->getOption('complete');
  }

  /**
   * Set this fulfillment complete.
   *
   * @param bool $complete
   *   Set to 0 to un-complete, 1 or omit to complete.
   *
   * @return CourseObjectFulfillment
   */
  function setComplete($complete = 1) {
    if (!$this->getOption('date_completed')) {
      $this->setOption('date_completed', REQUEST_TIME);
    }

    return $this->setOption('complete', $complete);
  }

  /**
   * Set this fulfillment's grade.
   *
   * @param float $grade
   *
   * @return CourseObjectFulfillment
   */
  function setGrade($grade) {
    return $this->setOption('grade_result', $grade);
  }

  /**
   * Get this fulfillment's grade.
   *
   * @return float
   *   A float value of the user's grade for this fulfillment.
   */
  function getGrade() {
    return $this->getOption('grade_result');
  }

  /**
   * Get this fulfillment's course object.
   */
  function getCourseObject() {
    return entity_load_single('course_object', $this->coid);
  }

  /**
   * Track course after saving fulfillment.
   */
  public function save() {
    // Make sure the user is enrolled first.
    if (course_enrollment_check($this->getCourseObject()->getCourseNid(), $this->uid)) {
      parent::save();
      $this->getCourseObject()->getCourse()->track();
    }
  }

  /**
   * Allow arbitrary data to be stored on the fulfillment, without explicitly
   * defining optionsDefinition() in a custom class.
   *
   * It is suggested that modules provide their own fulfillment classes and
   * specify the valid extra options through their own optionsDefinition(). See
   * CourseObjectWebformFulfillment for an example of this.
   */
  function optionsDefinition() {
    $options = get_object_vars($this);
    unset($options['entityInfo']);
    return $options;
  }

  /**
   * Get the instance ID. This could be the external component ID, a Node ID...
   *
   * @return string
   */
  function getInstanceId() {
    return $this->getOption('instance');
  }

}
