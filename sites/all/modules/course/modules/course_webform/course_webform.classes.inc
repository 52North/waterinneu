<?php

/**
 * Parent class for webform course tracking.
 */
class CourseObjectWebform extends CourseObjectNode {

  public function getWarnings() {
    $warnings = parent::getWarnings();

    if ($this->getInstanceId()) {
      if (!$this->node->webform['components']) {
        $warnings[] = t('The Webform has no questions. Please !link.', array('!link' => l('add questions', "node/{$this->getInstanceId()}/webform")));
      }
    }

    return $warnings;
  }

  public function getReports() {
    $reports = parent::getReports();
    $reports += array(
      'submissions' => array(
        'title' => t('Submissions'),
      ),
      'analysis' => array(
        'title' => t('Analysis'),
      ),
      'download' => array(
        'title' => t('Download'),
      ),
    );
    return $reports;
  }

  public function getReport($key) {
    module_load_include('inc', 'webform', 'includes/webform.report');
    switch ($key) {
      case 'submissions':
        return array(
          'title' => t('Webform results'),
          'content' => webform_results_submissions($this->node, FALSE, 50),
        );
      case 'analysis':
        return array(
          'title' => t('Webform results'),
          'content' => webform_results_analysis($this->node),
        );
      case 'download':
        $out = drupal_get_form('webform_results_download_form', $this->node);
        return array(
          'title' => t('Webform results'),
          'content' => drupal_render($out),
        );
    }
    return parent::getReport($key);
  }

  function getNodeTypes() {
    return webform_node_types();
  }

  function getCloneAbility() {
    return TRUE;
  }

  function getOptionsSummary() {
    $summary = parent::getOptionsSummary();
    if ($this->getInstanceId()) {
      $summary['questions'] = l('Edit questions', "node/{$this->getInstanceId()}/webform");
    }
    return $summary;
  }

  /**
   * Remove all webform submissions associated with this fulfillment.
   */
  public function unEnroll() {
    parent::unEnroll();
    $fulfillment = $this->getFulfillment();
    $node = $this->getNode();
    if ($sids = $fulfillment->getOption('sids')) {
      module_load_include('inc', 'webform', 'includes/webform.submissions');
      foreach ($sids as $sid) {
        $submission = webform_get_submission($node->nid, $sid);
        webform_submission_delete($node, $submission);
      }
    }
  }

}

/**
 * Course fulfillment class for webforms.
 */
class CourseObjectWebformFulfillment extends CourseObjectFulfillment {

  /**
   * Define storage for submission IDs.
   */
  function optionsDefinition() {
    return array('sids' => array());
  }

}
