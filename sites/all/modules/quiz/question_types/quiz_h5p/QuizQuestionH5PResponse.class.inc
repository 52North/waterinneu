<?php

class QuizQuestionH5PResponse extends QuizQuestionResponse {

  /**
   * Delete result row for this question.
   */
  public function delete() {
    db_delete('quiz_h5p_user_results')
      ->condition('question_nid', $this->question->nid)
      ->condition('question_vid', $this->question->vid)
      ->condition('result_id', $this->rid)
      ->execute();
  }

  /**
   * Needs to be implemented, not used.
   */
  public function getResponse() {}

  /**
   * Save current score and xAPI response in db.
   */
  public function save() {
    global $user;

    // Decode xAPI answer data
    $data = new H5PReportXAPIData(json_decode($this->answer));

    // Parse data
    $this->saveXAPIData($data);
  }
  /**
   * Recusive save of xAPI data
   *
   * @param \H5P\XAPIData $data
   */
  private function saveXAPIData($data) {

    // Save statement data
    $dataID = db_insert('quiz_h5p_user_results')
      ->fields(array(
        'parent_id' => $data->getParentID(),
        'question_nid' => $this->question->nid,
        'question_vid' => $this->question->vid,
        'result_id' => $this->rid,
        'score_scaled' => $data->getScoreScaled(),
        'score_raw' => $data->getScoreRaw(),
        'score_min' => $data->getScoreMin(),
        'score_max' => $data->getScoreMax(),
        'interaction_type' => $data->getInteractionType(),
        'description' => $data->getDescription(),
        'correct_responses_pattern' => $data->getCorrectResponsesPattern(),
        'response' => $data->getResponse(),
        'additionals' => $data->getAdditionals(),
      ))
      ->execute();

    // Save sub content statements data
    if ($data->isCompound()) {
      foreach ($data->getChildren($dataID) as $subData) {
        $this->saveXAPIData($subData);
      }
    }
  }

  /**
   * Get scaled score for question
   *
   * @return int
   */
  public function score() {
    global $user;

    $percentScore = db_query(
      "SELECT score_scaled
         FROM {quiz_h5p_user_results}
        WHERE question_nid = :question_nid
          AND question_vid = :question_vid
          AND result_id = :result_id",
      array(
        'question_nid' => $this->question->nid,
        'question_vid' => $this->question->vid,
        'result_id' => $this->rid
      ))->fetchField();

    return round($percentScore * $this->getMaxScore());
  }

  /**
   * Implementation of getReportFormQuestion
   *
   * @see QuizQuestionResponse#getReportFormQuestion($showpoints, $showfeedback, $allow_scoring)
   */
  public function getReportFormQuestion($showpoints = TRUE, $showfeedback = TRUE, $allow_scoring = FALSE) {
    $title = db_query('SELECT title FROM {node} WHERE nid = :nid', array(':nid' => $this->question->nid))->fetchField();
    return array('#markup' => check_plain($title));
  }

  /**
   * Implements getReportFormResponse of QuizQuestionResponse interface
   */
  public function getReportFormResponse($showpoints = TRUE, $showfeedback = TRUE, $allow_scoring = FALSE) {

    $result = db_select('quiz_h5p_user_results', 'qhur')
        ->fields('qhur')
        ->condition('question_nid', $this->question->nid)
        ->condition('question_vid', $this->question->vid)
        ->condition('result_id', $this->rid)
        ->orderBy('id', 'ASC')
        ->execute();

    // Make it easy to map questions by id
    $questionsById = array();
    foreach ($result as $record) {
      $questionsById[$record->id] = $record;
    }

    // Assemble our question tree
    foreach ($questionsById as $question) {
      if ($question->parent_id === NULL) {
        // This is the root of our tree
        $baseQuestion = $question;
      }
      elseif (isset($questionsById[$question->parent_id])) {
        // Add to parent
        $questionsById[$question->parent_id]->children[] = $question;
      }
    }

    // Process question tree and create markup for report
    if (isset($baseQuestion)) {
      $report = theme('quiz_h5p_response', array(
        'question' => $baseQuestion
      ));

      if (!empty($report)) {
        return array('#markup' => $report);
      }
    }

    // No report available
    return array('#no-response' => TRUE);
  }

  /**
   * Needs to be implemented. Is not used.
   */
  public function getReportFormAnswerFeedback($showpoints = TRUE, $showfeedback = TRUE, $allow_scoring = FALSE) {
    return FALSE;
  }
}
