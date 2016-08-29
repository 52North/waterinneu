<?php

$plugin = array(
  'title' => t('Event'),
  'description' => t('Controls access by conditional dates'),
  'handler' => array(
    'class' => 'CourseObjectAccessConditional',
  ),
);

class CourseObjectAccessConditional extends CourseObjectAccess {

  function view() {
    return $this->take();
  }

  function see() {
    if ($this->getOption('conditional_hidden')) {
      return $this->view();
    }
  }

  function take() {
    $type = $this->getOption('conditional_type');
    $offset = $this->getOption('conditional_time');
    $time = REQUEST_TIME;
    $access = TRUE;
    if ($type) {
      foreach ($this->getCourseObject()->getCourse()->getObjects() as $courseObject) {
        if ($courseObject->getId() == $this->getOption('conditional_object')) {
          switch ($type) {
            case 'completed':
              $completed = $courseObject->getFulfillment()->getOption('date_completed');
              if (!$completed) {
                $access = FALSE;
              }
              else {
                $access = $time >= ($completed + $offset);
              }
              break;
            case 'started':
              $started = $courseObject->getFulfillment()->getOption('date_started');
              if (!$started) {
                $access = FALSE;
              }
              else {
                $access = $time >= ($started + $offset);
              }
              break;
          }
        }
      }
    }

    return $access;
  }

  function optionsDefinition() {
    $defaults = parent::optionsDefinition();

    $defaults += array(
      'conditional_type' => NULL,
      'conditional_time' => NULL,
      'conditional_object' => NULL,
      'conditional_hidden' => NULL,
    );

    return $defaults;
  }

  function optionsForm(&$form, &$form_state) {
    $config = $this->getOptions();
    ctools_include('dependent');

    $form['conditional_type'] = array(
      '#title' => t('Event'),
      '#type' => 'select',
      '#options' => array(
        '',
        'started' => t('User started course object'),
        'completed' => t('User completed course object'),
      ),
      '#description' => t('This sets the conditional behavior.'),
    );

    if (module_exists('timeperiod')) {
      $form['conditional_time'] = array(
        '#title' => t('Time'),
        '#type' => 'timeperiod_select',
        '#units' => array(
          '86400' => array('max' => 30, 'step size' => 1),
          '3600' => array('max' => 24, 'step size' => 1),
          '60' => array('max' => 60, 'step size' => 1),
        ),
        '#description' => t('Length of time after the event happens when this course object should be accessible.'),
        '#default_value' => $config['conditional_time'],
      );
    }
    else {
      $form['conditional_time'] = array(
        '#title' => t('Time'),
        '#type' => 'textfield',
        '#size' => 8,
        '#description' => t('Length of time in seconds after the event happens when this course object should be accessible.'),
        '#default_value' => $config['conditional_time'],
      );
    }

    $form['conditional_object'] = array(
      '#title' => t('Course object'),
      '#type' => 'select',
      '#options' => $this->getObjectOptions(),
      '#description' => t('The course object to check for the type and time of conditional display.'),
    );

    $form['conditional_hidden'] = array(
      '#title' => t('Hide object until ready'),
      '#type' => 'checkbox',
      '#description' => t('This will prevent the course object from appearing in the course outline until it is ready.'),
    );

    $conditional_dependent = array(
      '#dependency' => array('edit-plugins-access-conditional-conditional-type' => array('completed', 'started')),
    );

    foreach (element_children($form) as $key) {
      if ($key != 'conditional_time') {
        $form[$key]['#default_value'] = $config[$key];
      }

      if ($key != 'conditional_type' && $key != 'conditional_time') {
        $form[$key] += $conditional_dependent;
      }
    }

    return $form;
  }

}
