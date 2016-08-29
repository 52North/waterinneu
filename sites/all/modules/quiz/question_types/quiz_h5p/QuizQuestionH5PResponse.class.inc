<?php

class QuizQuestionH5PResponse extends QuizQuestionResponse {

  public function delete() {

  }

  public function getResponse() {
    return 'In H5P';
  }

  public function save() {
    global $user;

    $percentScore = 0;
    if ($this->answer !== 1 && is_numeric($this->answer)) {
      // Answer is the "encrypted" percentScore. Let's "decrypt" it...
      $percentScore = $this->answer / 1.234 - 32.17;
    }    
    if ($percentScore < 0) {
      $percentScore = 0;
    }
    elseif ($percentScore > 1) {
      $percentScore = 0;
    }

    db_merge('quiz_h5p_user_results')
      ->key(array(
        'question_nid' => $this->question->nid,
        'question_vid' => $this->question->vid,
        'result_id' => $this->rid,
      ))
      ->fields(array(
        'question_nid' => $this->question->nid,
        'question_vid' => $this->question->vid,
        'result_id' => $this->rid,
        'percent_score' => $percentScore,
      ))
      ->execute();
  }

  public function score() {
    global $user;
    
    $percentScore = db_query(
      "SELECT percent_score
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
  
  public function getReportFormResponse($showpoints = TRUE, $showfeedback = TRUE, $allow_scoring = FALSE) {
    return array('#no-response' => TRUE);
  }
	

  public function getReportFormAnswerFeedback($showpoints = TRUE, $showfeedback = TRUE, $allow_scoring = FALSE) {
    return FALSE;
  }
}
