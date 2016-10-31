<?php

/**
 * Parent class for poll tracking.
 */
class CourseObjectPoll extends CourseObjectNode {

  function getTakeType() {
    return 'redirect';
  }

  public function optionsDefinition() {
    $options = parent::optionsDefinition();
    $options['use_node_title'] = 1;
    return $options;
  }

  public function create($node = NULL) {
    $poll = new stdClass;
    $poll->choice = array(
      array(
        'chtext' => 'Yes',
        'chvotes' => 0,
        'weight' => 0,
      ),
      array(
        'chtext' => 'No',
        'chvotes' => 0,
        'weight' => 0,
      ),
    );
    $poll->type = 'poll';
    $poll->active = 1;
    $poll->runtime = 0;
    parent::create($poll);
  }

  public function getReports() {
    $reports = parent::getReports();
    $reports += array(
      'results' => array(
        'title' => 'Results',
      ),
      'all' => array(
        'title' => 'List votes',
      ),
    );
    return $reports;
  }

  public function getReport($key) {
    module_load_include('inc', 'poll', 'poll.pages');
    switch ($key) {
      case 'results':
        return array(
          'title' => $this->node->title,
          'content' => poll_view_results($this->node, NULL, NULL, NULL),
        );
      case 'all':
        $out = poll_votes($this->node);
        return array(
          'title' => 'All votes',
          'content' => drupal_render($out),
        );
    }
    return parent::getReport($key);
  }

  /**
   * Remove poll votes for this user.
   */
  function unEnroll() {
    $account = $this->getCourse()->getUser();

    db_delete('poll_vote')
      ->condition('nid', $this->getNode()->nid)
      ->condition('uid', $account->uid)
      ->execute();
    db_update('poll_choice')
      ->expression('chvotes', 'chvotes - 1')
      ->condition('chid', $this->getFulfillment($account)->getOption('instance'))
      ->execute();
  }

  function getNodeTypes() {
    return array('poll');
  }

  function getCloneAbility() {
    return TRUE;
  }

}
