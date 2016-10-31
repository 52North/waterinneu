<?php

/**
 * Holds a user's total progress through a course and functionality to check
 * for completion of required objects.
 */
class CourseReport extends CourseHandler {

  /**
   * Get the course of this tracker.
   *
   * @return Course
   */
  public function getCourse() {
    return entity_load_single('course', $this->nid);
  }

  /**
   * Track the course (scan required objects, update progress, completion, etc).
   */
  public function track() {
    $required = 0;
    $required_complete = 0;
    $prev = NULL;
    $account = user_load($this->uid);
    foreach ($this->getCourse()->getObjects() as $courseObject) {
      if (!$courseObject->getOption('enabled')) {
        continue;
      }

      if (!$prev) {
        $this->setOption('section_name', $courseObject->getTitle());
        $this->setOption('coid', $courseObject->getId());
      }

      // Count required objects.
      $required += $courseObject->getOption('required');

      // Count completed required objects.
      $required_complete += ($courseObject->getOption('required') && $courseObject->getFulfillment($account)->isComplete());

      // Log last grade.
      if ($courseObject->isGraded() && $courseObject->getOption('grade_include')) {
        $this->setOption('grade_result', $courseObject->getFulfillment($account)->getOption('grade_result'));
      }

      if (!$courseObject->getFulfillment($account)->isComplete() && $prev && $prev->getFulfillment($account)->isComplete()) {
        $this->setOption('section_name', $courseObject->getTitle());
        $this->setOption('coid', $courseObject->getId());
      }

      $prev = clone $courseObject;
    }

    if ($required_complete >= $required) {
      // Course requirements have been met.
      $this->setOption('section', 'complete');
      $this->setOption('section_name', 'Complete');
      $this->setOption('complete', 1);
      if (!$this->getOption('date_completed')) {
        $this->setOption('date_completed', REQUEST_TIME);
      }
    }
    $this->save();
  }

  /**
   * Course report entity label callback.
   */
  function defaultLabel() {
    $node = node_load($this->nid);
    $account = user_load($this->uid);
    return t("@username's course report for @title", array('@username' => format_username($account), '@title' => $node->title));
  }

}
