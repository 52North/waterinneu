<?php

class CourseObjectManual extends CourseObject {

  /**
   * Display status message as course content.
   */
  public function take() {
    return $this->getStatus();
  }

  /**
   * Return a message about the user's status in this object, for when this
   * object is hidden.
   */
  public function getStatus() {
    $grade = $this->getFulfillment()->getGrade();
    $config = $this->getOptions();
    if ($this->getFulfillment()->isComplete()) {
      // User has a completed fulfillment (passed).
      return check_plain(t($config['complete_msg']));
    }
    elseif ($this->getFulfillment()->getGrade() == '') {
      // User has a fulfillment but no grade (incomplete).
      return check_plain(t($config['incomplete_msg']));
    }
    else {
      // User has a grade but not complete (failed).
      return check_plain(t($config['failed_msg']));
    }
  }

  public function optionsDefinition() {
    $defaults = parent::optionsDefinition();

    $defaults['complete_msg'] = 'Your instructor has marked you as passed.';
    $defaults['incomplete_msg'] = 'Your instructor has not given you a pass/fail grade yet.';
    $defaults['failed_msg'] = 'Your instructor has marked you as failed.';

    return $defaults;
  }

  public function optionsForm(&$form, &$form_state) {
    parent::optionsForm($form, $form_state);

    $config = $this->getOptions();

    $form['complete_msg'] = array(
      '#type' => 'textfield',
      '#title' => t('Complete message'),
      '#default_value' => $config['complete_msg'],
    );

    $form['failed_msg'] = array(
      '#type' => 'textfield',
      '#title' => t('Failed message'),
      '#default_value' => $config['failed_msg'],
    );

    $form['incomplete_msg'] = array(
      '#type' => 'textfield',
      '#title' => t('Incomplete message'),
      '#default_value' => $config['incomplete_msg'],
    );
  }

}
