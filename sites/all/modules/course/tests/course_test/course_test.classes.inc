<?php

/**
 * Dummy example course object.
 */
class CourseObjectTest extends CourseObject {

  public static function getMaxOccurences() {
    return 3;
  }

  public function take() {
    return t('I am a test course object with the title !title', array('!title' => $this->getOption('title')));
  }

  public function optionsDefinition() {
    $options = parent::optionsDefinition();
    $options['test_option'] = NULL;
    return $options;
  }

}

/**
 * Dummy example course object.
 */
class CourseObjectGradedTest extends CourseObjectTest {

  public function isGraded() {
    return TRUE;
  }

}

/**
 * Course fulfillment class for test.
 */
class CourseObjectTestFulfillment extends CourseObjectFulfillment {

  /**
   * Define storage for quiz result IDs.
   */
  function optionsDefinition() {
    return array('test_value' => NULL);
  }

}
