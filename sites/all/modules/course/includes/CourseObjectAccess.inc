<?php

/**
 * Access handler for CourseObjects.
 *
 * Subtypes must define take(), see(), and view().
 */
abstract class CourseObjectAccess {

  private $courseObject;
  private $type;

  public function setType($type) {
    $this->type = $type;
  }

  /**
   * Helper method to get possible objects.
   */
  public function getObjectOptions() {
    $options = array('');
    foreach ($this->getCourseObject()->getCourse()->getObjects() as $courseObject) {
      if ($courseObject->getId() != $this->getCourseObject()->getId()) {
        $options[$courseObject->getId()] = $courseObject->getTitle();
      }
    }
    return $options;
  }

  public function setCourseObject($courseObject) {
    $this->courseObject = $courseObject;
  }

  public function getCourseObject() {
    return $this->courseObject;
  }

  abstract public function take();

  abstract public function see();

  abstract public function view();

  public function getOptions() {
    $plugins = $this->getCourseObject()->getOption('plugins');
    if (isset($plugins['access'][$this->type])) {
      return $plugins['access'][$this->type];
    }
    else {
      return $this->optionsDefinition();
    }
  }

  public function getOption($option) {
    $options = $this->getOptions();
    if (isset($options[$option])) {
      return $options[$option];
    }
    else {
      return NULL;
    }
  }

  public function optionsValidate($form, &$form_state) {

  }

  public function optionsDefinition() {
    return array();
  }

}
