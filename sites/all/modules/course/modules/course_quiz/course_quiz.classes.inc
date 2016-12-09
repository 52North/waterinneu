<?php

class CourseObjectQuiz extends CourseObjectNode {

  /**
   * Create the quiz node and set it as this object's instance.
   */
  function create($node = NULL) {
    if (!$node) {
      $node = new stdClass;
    }
    $node->auto_created = TRUE;
    parent::create($node);
  }

  /**
   * The take URL of the quiz is /take.
   */
  function getTakeUrl() {
    if ($this->getOption('quiz_goto') == "view") {
      return url("node/{$this->node->nid}");
    }
    else {
      return url("node/{$this->node->nid}/take");
    }
  }

  /**
   * Marks a user's fulfillment record for this object complete if the user
   * passed the quiz.
   */
  function grade($user, $rid) {
    $nid = (int) $this->getInstanceId();
    $fulfillment = $this->getFulfillment();

    $result_ids = (array) $fulfillment->getOption('quiz_result_ids');
    $result_ids[] = $rid;
    $fulfillment->setOption('instance', $rid);
    $fulfillment->setOption('quiz_result_ids', $result_ids);

    $results = quiz_get_score_data(array($nid), $user->uid);
    $result = reset($results);
    if ($result && ($result->percent_score >= $this->getOption('passing_grade'))) {
      $fulfillment->setGrade($result->percent_score)->setComplete()->save();
    }
    else {
      $fulfillment->setGrade($result->percent_score)->save();
    }
  }

  /**
   * Course quiz options.
   */
  public function optionsDefinition() {
    $options = parent::optionsDefinition();

    $options['quiz_goto'] = 'view';
    $options['passing_grade'] = 75;

    return $options;
  }

  /**
   * Add an option only pertinent to quiz?
   */
  public function optionsForm(&$form, &$form_state) {
    parent::optionsForm($form, $form_state);
    $defaults = $this->getOptions();

    $form['quiz_goto'] = array(
      '#type' => 'select',
      '#title' => t('Quiz entry point'),
      '#options' => array(
        'view' => t('View Quiz'),
        'take' => t('Take Quiz'),
      ),
      '#default_value' => $defaults['quiz_goto'],
      '#description' => t('Selecting "Take Quiz" will launch the user directly into taking the quiz, without viewing the quiz body.'),
    );

    $form['grading']['passing_grade'] = array(
      '#title' => t('Passing grade'),
      '#type' => 'textfield',
      '#size' => 4,
      '#default_value' => $defaults['passing_grade'],
      '#description' => t('The user will not be able to proceed past this object unless this grade is met.'),
    );
  }

  /**
   * Let the user know if they have a Quiz without questions.
   */
  public function getWarnings() {
    $warnings = parent::getWarnings();

    if ($this->getInstanceId()) {
      if (!quiz_get_number_of_questions($this->node->vid, $this->node->nid)) {
        if (course_quiz_quiz_version() >= 5) {
          $link = l('add questions', "node/{$this->getInstanceId()}/quiz/questions");
        }
        else {
          $link = l('add questions', "node/{$this->getInstanceId()}/questions");
        }
        $warnings[] = t('This Quiz does not have any questions. Please !link.', array('!link' => $link));
      }
    }

    return $warnings;
  }

  public function getReports() {
    $reports = parent::getReports();
    $reports['results'] = array(
      'title' => t('Results'),
    );
    if (module_exists('quiz_stats')) {
      $reports['statistics'] = array(
        'title' => t('Statistics'),
      );
    }
    return $reports;
  }

  public function getReport($key) {
    module_load_include('inc', 'quiz', 'quiz.admin');
    switch ($key) {
      case 'results':
        if (course_quiz_quiz_version() >= 5) {
          $out = views_embed_view('quiz_results', 'default', $this->node->nid);
        }
        else {
          $out = drupal_get_form('quiz_results_manage_results_form', $this->node);
        }
        return array(
          'title' => t('Quiz results'),
          'content' => $out,
        );
      case 'statistics':
        module_load_include('inc', 'quiz_stats', 'quiz_stats.admin');
        return array(
          'title' => t('Quiz statistics'),
          'content' => quiz_stats_get_adv_stats($this->node->vid),
        );
    }
    return parent::getReport($key);
  }

  /**
   * Remove all quiz attempts associated with this fulfillment.
   */
  public function unenroll() {
    parent::unenroll();
    $fulfillment = $this->getFulfillment();
    $result_ids = (array) $fulfillment->getOption('quiz_result_ids');
    if (course_quiz_quiz_version() >= 5) {
      entity_delete_multiple('quiz_result', $result_ids);
    }
    else {
      quiz_delete_results($result_ids);
    }
  }

  function getNodeTypes() {
    return array('quiz');
  }

  function isGraded() {
    return TRUE;
  }

  function getCloneAbility() {
    return t('%object can only be partially cloned. It will be created with the same settings, but without the questions.', array('%object' => $this->getTitle()));
  }

  /**
   * Exception for quiz: we need to set auto_created.
   */
  function thaw($ice) {
    $this->node = $ice->node;
    unset($this->node->nid);
    unset($this->node->vid);
    $this->node->auto_created = TRUE;
    node_save($this->node);
    return $this->node->nid;
  }

  function getOptionsSummary() {
    $summary = parent::getOptionsSummary();
    if ($this->getInstanceId()) {
      if (course_quiz_quiz_version() >= 5) {
        $summary['questions'] = l('Edit questions', "node/{$this->getInstanceId()}/quiz/questions");
      }
      else {
        $summary['questions'] = l('Edit questions', "node/{$this->getInstanceId()}/questions");
      }
    }
    return $summary;
  }

  /**
   * Get the status of this quiz for the requirements list.
   */
  function getStatus() {
    $grade = $this->isGraded() ? t('Your grade: %grade_result%<br/>Pass grade: %passing_grade%', array(
        '%grade_result' => $this->getFulfillment()->getOption('grade_result'),
        '%passing_grade' => $this->getOption('passing_grade'),
      )) : '';
    return $grade;
  }

  /**
   * Course node context handler callback.
   *
   * If this question is part of a quiz in a course, what quizzes do we belong
   * to?
   */
  public static function getNodeInstances($node) {
    $quizzes = array();

    // Finding quizzes this question already belongs to.
    $sql = 'SELECT n.nid, r.parent_vid AS vid, n.title FROM {quiz_node_relationship} r
            JOIN {node} n ON n.nid = r.parent_nid
            WHERE r.child_vid = :child_vid
            ORDER BY r.parent_vid DESC';
    $res = db_query($sql, array(':child_vid' => $node->vid));
    while ($row = $res->fetch()) {
      $quizzes[] = $row->nid;
    }

    return $quizzes;
  }

}

/**
 * Course fulfillment class for quizzes.
 */
class CourseObjectQuizFulfillment extends CourseObjectFulfillment {

  /**
   * Define storage for quiz result IDs.
   */
  function optionsDefinition() {
    return array('quiz_result_ids' => array());
  }

}
