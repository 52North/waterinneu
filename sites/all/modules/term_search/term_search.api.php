<?php
/**
 * @file
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * Hooks provided by the Term Search module.
 *
 * This module provides two hooks to customize the indexing and searching
 * of term entities from the core Taxonomy module:
 *
 *   - hook_term_update_index
 *   - hook_term_search_result
 *
 * These are documented below.  In addition, anyone trying to theme or
 * extend this module might find hook_taxonomy_term_view_alter or other
 * hooks from taxonomy.api.php useful.
 */

/**
 * Act on a term being indexed for search.
 *
 * Modules implementing this hook will return additional html text
 * to add to the search index for a specific term.  Note that
 * the term has already been rendered using the 'search_index'
 * view mode.
 *
 * @param $term
 *   The term object that is being indexed for search.
 *
 * @return
 *   A string (can include html) that will be added to the rendered term
 *   before indexing for search.
 */
function hook_term_update_index($term) {
  $text = '';
  $query = db_select('users', 'u');
  $query->rightJoin('field_data_field_affiliation', 'a', 'a.entity_id=u.uid');
  $uids = $query->addField('u', 'uid')
    ->condition('a.field_affiliation_tid', $term->tid)
    ->countQuery()
    ->execute()
    ->fetchField();

  foreach ($uids as $uid) {
    $account = user_load($uid);
    $text .= user_view($account, 'department_index');
  }
  return $text;
}

/**
 * Act on a term being displayed as a search result.
 *
 * This hook is invoked from term_search_search_execute(), after
 * taxonomy_term_load() and taxonomy_term_view() have been called.
 *
 * @param $term
 *   The term object being display in a search result.
 *
 * @return
 *   A string (can include html) that will be added to the rendered search
 *   result for this term.
 */
function hook_term_search_result($term) {
  $text = '';
  $query = db_select('users', 'u');
  $query->rightJoin('field_data_field_affiliation', 'a', 'a.entity_id=u.uid');
  $uids = $query->addField('u', 'uid')
    ->condition('a.field_affiliation_tid', $term->tid)
    ->countQuery()
    ->execute()
    ->fetchField();

  foreach ($uids as $uid) {
    $account = user_load($uid);
    $text .= user_view($account, 'department_search_result');
  }
  return $text;
}
