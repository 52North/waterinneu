<?php

/**
 * @file
 * Provides a controller for building an entity overview form.
 */

/**
 * Basic controller for providing an admin UI for remote entities.
 *
 * As with EntityDefaultUIController you need to provide an entity form
 * builder and an entity access callback.
 *
 * @see remote_entity_hook_entity_info().
 */
class RemoteEntityEntityUIController extends EntityDefaultUIController {

  /**
   * Provides definitions for implementing hook_menu().
   */
  public function hook_menu() {
    // For now at least, go with the tactic of getting the parent class stuff
    // and removing what we don't want.
    $items = parent::hook_menu();

    // Set a default wildcard if there isn't one specified.
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%entity_object';

    // We don't allow adding.
    unset($items[$this->path . '/add']);
    // We don't allow cloning.
    unset($items[$this->path . '/manage/' . $wildcard . '/clone']);

    return $items;
  }

  /**
   * Builds the entity overview form.
   */
  public function overviewForm($form, &$form_state) {
    // This is totally unsuitable for entity types that have a lot of
    // entities, so only show if requested.
    if (isset($this->entityInfo['admin ui']['form buttons']['fetch'])) {
      $form['fetch'] = array(
        '#type' => 'submit',
        '#value' => t('Fetch all remote entities'),
        // This is possibly the correct but undocumented way to tell which button
        // has been clicked. See http://drupal.org/node/274983#comment-5435828.
        '#name' => 'fetch',
      );
    }

    $form['table'] = $this->overviewTable();
    $form['pager'] = array('#theme' => 'pager');
    return $form;
  }

  /**
   * Override the parent method to prevent remote retrievals.
   *
   * @param $conditions
   *   An array of conditions as needed by entity_load().
   *
   * @return Array
   *   A renderable array.
   */
  public function overviewTable($conditions = array()) {
    // Set the controller to bypass remote retrievals, as we don't want the
    // loading of all entities to incur lots of remote calls.
    $controller = entity_get_controller($this->entityType);
    $controller->bypass_remote_retrieve = TRUE;

    $render = parent::overviewTable($conditions);

    // Restore the controller.
    $controller->bypass_remote_retrieve = FALSE;

    return $render;
  }

  /**
   * Overview form submit callback.
   *
   * @param $form
   *   The form array of the overview form.
   * @param $form_state
   *   The overview form state which will be used for submitting.
   */
  public function overviewFormSubmit($form, &$form_state) {
    if ($form_state['triggering_element']['#name'] == 'fetch') {
      // Get the main entity controller, and from that a query.
      $controller = entity_get_controller($this->entityType);
      $query = $controller->getRemoteEntityQuery();

      // Execute the query.
      $entities = $controller->executeRemoteEntityQuery($query);

      drupal_set_message(t('Retrieved !count entities from the remote server.', array(
        '!count' => count($entities),
      )));
    }
  }

}
