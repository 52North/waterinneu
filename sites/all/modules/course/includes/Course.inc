<?php

/**
 * An object that holds CourseObjects and tracker functions?
 */
class Course extends CourseHandler {

  // Node of course.
  private $node;
  // User in course.
  /** @deprecated */
  private $user;
  // Ordered list of course objects.
  private $courseObjects;
  // Course report tracker
  private $tracker;
  // The active course object.
  private $active = NULL;
  // The next course object.
  private $next;
  // The previous course object.
  private $prev;

  /**
   * Get the course tracker for this course/user.
   *
   * @return CourseReport
   */
  public function getTracker($account = NULL) {
    if (!$account) {
      /** @deprecated */
      if (!empty($this->user)) {
        $account = $this->user;
      }
      else {
        global $user;
        $account = $user;
      }
    }

    if ($entities = entity_load('course_report', FALSE, array('nid' => $this->getNode()->nid, 'uid' => $account->uid))) {
      return reset($entities);
    }
    else {
      return entity_create('course_report', array('nid' => $this->getNode()->nid, 'uid' => $account->uid));
    }
  }

  /**
   * The Drupal path to take this course.
   *
   * @return string
   */
  public function getUrl() {
    return "node/{$this->nid}/takecourse";
  }

  /**
   * Set the active CourseObject in this Course.
   *
   * @param int $id
   *   A numeric course object ID.
   */
  public function setActive($id = NULL) {
    if (!$id && isset($_SESSION['course'][$this->getNode()->nid]['taking']['active'])) {
      $id = $_SESSION['course'][$this->getNode()->nid]['taking']['active'];
    }

    $old = NULL;
    $storeNext = FALSE;
    foreach ($this->getObjects() as $courseObject) {
      if (!$courseObject->getOption('enabled')) {
        // Skip disabled objects.
        continue;
      }

      if ($id == $courseObject->getId()) {
        // Active - save old, store next.
        if ($old) {
          $this->prev = $old;
        }

        $storeNext = TRUE;
        $this->active = $courseObject;
      }
      elseif ($storeNext) {
        $this->next = clone $courseObject;
        $storeNext = FALSE;
      }

      $old = clone $courseObject;
    }
  }

  /**
   * Get the active CourseObject.
   *
   * @return CourseObject
   */
  public function getActive() {
    if (!$this->active) {
      $this->setActive();
    }

    return $this->active;
  }

  /**
   * Get the next course object, from the active course object.
   *
   * @return CourseObject
   */
  public function getNext() {
    if (!$this->active) {
      $this->setActive();
    }

    return $this->next;
  }

  /**
   * Get the previous course object, from the active course object.
   *
   * @return CourseObject
   */
  public function getPrev() {
    if (!$this->active) {
      $this->setActive();
    }

    return $this->prev;
  }

  /**
   * Generate navigation links.
   */
  public function getNavigation() {
    // Initialize the active Course.
    $this->setActive();

    $prev = $this->getPrev();
    $next = $this->getNext();

    $links = array();

    if ($prev && $prev->access('take')) {
      $links['prev'] = l(t('Previous'), $prev->getUrl(), array('html' => TRUE));
    }

    $links['back'] = l(t('Back to course'), $this->getUrl());

    if ($next && $next->access('take')) {
      $links['next'] = l(t('Next'), $next->getUrl(), array('html' => TRUE));
    }
    elseif (!$next && $this->getTracker()->getOption('complete')) {
      $links['next'] = l(t('Next'), 'node/' . $this->getOption('nid') . '/course-complete', array('html' => TRUE));
    }

    // Ask course objects if they want to override the navigation.
    if ($active = $this->getActive()) {
      foreach ($active->overrideNavigation() as $key => $link) {
        $links[$key] = $link;
      }
    }

    return $links;
  }

  /**
   * Track the course (scan required objects, update progress, completion, etc).
   */
  public function track($account = NULL) {
    $this->getTracker($account)->track();
  }

  /**
   * Get the course objects in this course.
   *
   * @return CourseObject[]
   *   An array of course objects.
   */
  public function getObjects() {
    $courseObjects = array();

    $efq = new EntityFieldQuery;
    $result = $efq->entityCondition('entity_type', 'course_object')
      ->propertyCondition('nid', $this->getNode()->nid)
      ->propertyOrderBy('weight')
      ->execute();

    if (!empty($result['course_object'])) {
      if ($courseObjects = entity_load('course_object', array_keys($result['course_object']))) {
        foreach ($courseObjects as $courseObject) {
          /** @deprecated do not use set|getUser() */
          $courseObject->setUser($this->getUser());
        }
      }
    }

    return $courseObjects;
  }

  public function getNode() {
    return node_load($this->nid);
  }

  /**
   * Un-enroll the user from all course objects and revoke access.
   *
   * Course object should clean up
   * and delete records related to this Course and user.
   *
   * NOT a top level class of CourseObject::unEnroll.
   *
   * @see CourseObjectNode::revoke()
   */
  public function unEnroll() {
    foreach ($this->getObjects() as $courseObject) {
      // Remove access.
      $courseObject->revoke();
      $courseObject->unEnroll();
    }
  }

  /**
   * @deprecated
   */
  public function setUser($account) {
    $this->user = $account;
  }

  /**
   * @deprecated
   */
  public function getUser() {
    return $this->user;
  }

}
