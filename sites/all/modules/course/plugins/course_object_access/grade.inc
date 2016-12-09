<?php

$plugin = array(
  'title' => t('Grade'),
  'description' => t('Controls access by grade'),
  'handler' => array(
    'class' => 'CourseObjectAccessGrade',
  ),
);

class CourseObjectAccessGrade extends CourseObjectAccess {

  public function optionsDefinition() {
    $defaults = parent::optionsDefinition();

    $defaults += array(
      'course_grade_range' => array('low' => NULL, 'high' => NULL),
      'course_grade_hidden' => NULL,
      'conditional_object' => NULL,
    );

    return $defaults;
  }

  public function optionsValidate($form, &$form_state) {
    if (!empty($form_state['course_grade_range']['low']) || !empty($form_state['course_grade_range']['high'])) {
      // If user filled out at least one.
      if (is_numeric($form_state['course_grade_range']['low']) && is_numeric($form_state['course_grade_range']['high'])) {
        // User filled out both.
        if ($form_state['course_grade_range']['low'] > $form_state['course_grade_range']['high']) {
          form_error($form['course_grade_range'], t('High range cannot be lower than the low range.'));
        }
      }
      else {
        // User did not fill out both.
        form_error($form['course_grade_range'], t('You must enter a numeric value for both the low and high grade range.'));
      }
    }
  }

  function take() {
    $config = $this->getOptions();

    if (is_numeric($config['course_grade_range']['low']) && is_numeric($config['course_grade_range']['high'])) {
      $grade = NULL;
      $conditional_object = NULL;

      if ($this->getOption('conditional_object')) {
        // Check object grade.
        $conditional_object = course_object_load($config['conditional_object']);
        $grade = $conditional_object->getFulfillment()->getOption('grade_result');
      }
      else {
        $grade = $this->getCourseObject()->getCourse()->getTracker()->getOption('grade_result');
      }

      $low_range = $grade >= $config['course_grade_range']['low'];
      $high_range = $grade <= $config['course_grade_range']['high'];

      if ($low_range && $high_range) {
        return TRUE;
      }
      else if (isset($conditional_object)) {
        $this->getCourseObject()->setAccessMessage('grade', t('%title requires a grade between @grade_low% and @grade_high% to continue.', array(
          '@grade_low' => $config['course_grade_range']['low'],
          '@grade_high' => $config['course_grade_range']['high'],
          '%title' => $conditional_object->getTitle(),
        )));
        return FALSE;
      }
      else {
        $this->getCourseObject()->setAccessMessage('grade', t('You must have a grade between @grade_low% and @grade_high% to continue.', array(
          '@grade_low' => $config['course_grade_range']['low'],
          '@grade_high' => $config['course_grade_range']['high']
        )));
        return FALSE;
      }
    }
  }

  function see() {
    if (!$this->take() && $this->getOption('course_grade_hidden')) {
      return FALSE;
    }
  }

  function view() {
    return $this->take();
  }

  function optionsForm(&$form, &$form_state) {
    $config = $this->getOptions();

    $form['#description'] = t('The user will not be able to access this object unless the course grade is within the set range.');

    $form['course_grade_range'] = array(
      '#type' => 'container',
    );

    $form['course_grade_range']['low'] = array(
      '#title' => t('Percentage low'),
      '#type' => 'textfield',
      '#size' => 4,
      '#default_value' => isset($config['course_grade_range']['low']) ? $config['course_grade_range']['low'] : '',
    );

    $form['course_grade_range']['high'] = array(
      '#title' => t('Percentage high'),
      '#type' => 'textfield',
      '#size' => 4,
      '#default_value' => isset($config['course_grade_range']['high']) ? $config['course_grade_range']['high'] : '',
    );

    $options = $this->getObjectOptions();
    $options[0] = '(this course)';
    $form['conditional_object'] = array(
      '#title' => t('Grade to check'),
      '#type' => 'select',
      '#options' => $options,
      '#description' => t('This grade will be checked.'),
      '#default_value' => $config['conditional_object'],
    );

    $form['course_grade_hidden'] = array(
      '#title' => t('Hide until grade met'),
      '#description' => t('The user will not see this object until the grade is met.'),
      '#type' => 'checkbox',
      '#default_value' => $config['course_grade_hidden'],
    );

    return $form;
  }

  /**
   * Helper method to get possible graded objects.
   */
  public function getObjectOptions() {
    $options = array('');
    foreach ($this->getCourseObject()->getCourse()->getObjects() as $courseObject) {
      if ($courseObject->getId() != $this->getCourseObject()->getId() && $courseObject->isGraded()) {
        $options[$courseObject->getId()] = $courseObject->getTitle();
      }
    }
    return $options;
  }

}
