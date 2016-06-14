<?php
/**
 * @file
 * Definition of views_handler_sort_fallback_chain.
 */

/**
 * Sort by language fallback chain.
 */
class views_handler_sort_fallback_chain extends views_handler_sort {

  /**
   * Adds language fallback chain sorting to a query.
   */
  function query() {
    $this->ensure_my_table();

    global $language;
    $chain = language_fallback_get_chain($language->language);

    // Make sure that current UI language is not in the chain.
    // This shouldn't happen but double checking won't hurt.
    if (!empty($chain) && (($current = array_search($language->language, $chain)) !== FALSE)) {
      unset($chain[$current]);
    }

    $chain = array_merge(array($language->language), array_values($chain));

    // This was default behavior
    // $this->query->add_orderby($this->table_alias, $this->real_field, $this->options['order']);
    // This is simple "CASE" formula built using fallback chain.
    $formula = " CASE " . $this->table_alias . '.' . $this->real_field;
    for ($i = 0; $i < count($chain); $i++) {
      $formula .= " WHEN '" . $chain[$i] . "' THEN " . $i;
    }
    $formula .= " ELSE " . count($chain) . " END ";

    // Add order by
    // Note that since this is a formula we provide null values for table and field name!
    $this->query->add_orderby(NULL, NULL, $this->options['order'], $formula);
  }

}
