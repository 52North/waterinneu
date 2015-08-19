<?php

/**
 * @file
 * Contains handler classes for Entity Operations.
 */

/**
 * Operation handler class to show the remote source of an entity as devel
 * output, without affecting the local copy.
 *
 * Requires Entity Operations module.
 */
class RemoteEntityEntityOperationsOperationRemoteDevel extends EntityOperationsOperationDevel {

  /**
   * Returns strings for the operations.
   *
   * @return
   *  An array containing the following keys:
   *  - 'form': An array of strings for the operation form, containing:
   *    - 'button label'
   *    - 'confirm question'
   *    - 'submit message'
   */
  function operationStrings() {
    return array(
      'tab title' => 'Devel remote',
    ) + parent::operationStrings();
  }

  /**
   * Page callback.
   */
  function build($entity_type, $entity, $params = array()) {
    if (!isset($entity->remote_id)) {
      return t('This entity does not exist remotely.');
    }

    // Go via the connection so we don't touch the local entity.
    $resource = clients_resource_get_for_component('remote_entity', $entity_type);
    $connection = $resource->getConnection();
    $remote_entity = $connection->remote_entity_load($entity_type, $entity->remote_id);

    $output = kprint_r($remote_entity, TRUE, t('This loads the remote data from the remote source, without affecting the local copy.'));

    return $output;
  }

}

/**
 * Operation handler class to save the entity remotely.
 *
 * Requires Entity Operations module.
 */
class RemoteEntityEntityOperationsOperationRemoteSave extends EntityOperationsOperationAction {

  /**
   * The operation for entity_access().
   */
  public $access_verb = 'remote save';

  /**
   * Returns strings for the operations.
   *
   * @return
   *  An array containing the following keys:
   *  - 'form': An array of strings for the operation form, containing:
   *    - 'button label'
   *    - 'confirm question'
   *    - 'submit message'
   */
  function operationStrings() {
    return array(
      'tab title' => 'Remote save',
      'button label' => t('Save remotely'),
      'confirm question' => t('Are you sure you want to save this %entity-type to the remote source?'),
      'submit message' => t('%entity-type %label has been saved remotely.'),
    ) + parent::operationStrings();
  }

  /**
   * Form builder for this operation.
   */
  function form($form, &$form_state, $entity_type, $entity, $operation_path) {
    // We don't have anything useful to do here really, but it's the only
    // place we can look at the entity and output different text based on it.
    $form = array();

    if (isset($entity->remote_id)) {
      $message = t("This entity has previously been saved remotely, and will be updated on the remote source.");
    }
    else {
      $message = t("This entity has not yet been saved remotely, and will be inserted as a new record on the remote source.");
    }

    $form['message'] = array(
      '#prefix' => '<p>',
      '#markup' => $message,
      '#suffix' => '</p>',
    );

    return $form;
  }

  /**
   * Perform the action.
   */
  function execute($entity_type, $entity, $parameters = array()) {
    remote_entity_save($entity_type, $entity);
  }

}

/**
 * Operation handler class to check the results of remote save unpacking.
 *
 * Requires Entity Operations module.
 */
class RemoteEntityEntityOperationsOperationRemoteSaveUnpack extends EntityOperationsOperationDevel {

  /**
   * Returns strings for the operations.
   */
  function operationStrings() {
    return array(
      'tab title' => 'Remote unpack',
    ) + parent::operationStrings();
  }

  /**
   * Page callback.
   */
  function build($entity_type, $entity, $params = array()) {
    $controller = entity_get_controller($entity_type);
    $controller->unpack($entity);

    $output = '<p>' . t("This shows the entity as the Remote Entity controller has prepared it for remote saving. No actual changes have been made.") . '</p>';

    $output .= kprint_r($entity, TRUE);

    return $output;
  }

}
