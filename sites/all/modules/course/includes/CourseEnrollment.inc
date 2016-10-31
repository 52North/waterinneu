<?php

class CourseEnrollment extends Entity {

  /**
   * Enrollment entity label callback.
   */
  function defaultLabel() {
    $node = node_load($this->nid);
    $account = user_load($this->uid);
    return t("@username's enrollment in @title", array('@username' => format_username($account), '@title' => $node->title));
  }

}
