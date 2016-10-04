<?php

/**
 * Create a relationship from the course report to course enrollment.
 */
class course_views_handler_relationship_cr_ce extends views_handler_relationship {

  /**
   * Called to implement a relationship in a query.
   */
  function query() {
    // Figure out what base table this relationship brings to the party.
    $join = new views_join_course();
    $join->definition = array(
      'table' => 'course_enrollment',
      'field' => 'uid',
      'left_table' => !empty($this->relationship) ? $this->relationship : 'course_report',
      'left_field' => 'uid',
      'extra' => array(
        array(
          'field' => 'nid',
          'value' => 'nid',
          'numeric' => TRUE,
        ),
      ),
    );

    $join->construct();
    $this->ensure_my_table();

    $alias = $join->definition['table'] . '_' . $join->definition['left_table'];
    $this->alias = $this->query->add_relationship($alias, $join, $this->definition['base'], $this->relationship);
  }

}
