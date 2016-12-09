<?php

/**
 * Special join handler to allow join on two colums.
 *
 * Do not sanitize the extra data coming from our course.views.inc. See
 * http://drupal.org/node/560492
 */
class views_join_course extends views_join {

  /**
   * Build the SQL for the join this object represents.
   *
   * When possible, try to use table alias instead of table names.
   *
   * @param $select_query
   *   An implementation of SelectQueryInterface.
   * @param $table
   *   The base table to join.
   * @param $view_query
   *   The source query, implementation of views_plugin_query.
   */
  function build_join($select_query, $table, $view_query) {
    if (empty($this->definition['table formula'])) {
      $right_table = $this->table;
    }
    else {
      $right_table = $this->definition['table formula'];
    }

    if ($this->left_table) {
      $left = $view_query->get_table_info($this->left_table);
      $left_field = "$left[alias].$this->left_field";
    }
    else {
      // This can be used if left_field is a formula or something. It should be used only *very* rarely.
      $left_field = $this->left_field;
    }

    $condition = "$left_field = $table[alias].$this->field";
    $condition2 = "{$left['alias']}.{$this->extra[0]['field']} = {$table['alias']}.{$this->extra[0]['value']}";
    $condition = "($condition AND $condition2)";
    $arguments = array();

    $select_query->addJoin($this->type, $right_table, $table['alias'], $condition, $arguments);
  }

}
