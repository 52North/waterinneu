<?php

/**
 * @file
 * Provides a controller building upon the core controller but providing more
 * features like full CRUD functionality.
 */

/**
 * Interface for WSEntityControllers compatible with the entity API.
 */
interface WSEntityAPIControllerInterface extends EntityAPIControllerInterface {
}

/**
 * WSEntityAPIController extends and overrides most EntityAPIController features
 **/
class WSEntityAPIController extends EntityAPIController implements WSEntityAPIControllerInterface {

  protected $cacheComplete = FALSE;
  protected $bundleKey;


  public function __construct($entityType) {
  /**
     TODO: Load entity config object here
     TODO: Find a method of finding out which config object goes with this entity.
  **/


    parent::__construct($entityType);
  }

  /**
   * WS Get's the entity
   */
  public function query($ids, $conditions, $revision_id = FALSE) {

/*
  TODO: WS RETRIEVE
*/

    return $result;
  }

  /**
   * Implements EntityAPIControllerInterface.
   *
   *  WS Delete's the entity
   *
   * @param $transaction
   *   Optionally a DatabaseTransaction object to use. Allows overrides to pass
   *   in their transaction object.
   */
  public function delete($ids, DatabaseTransaction $transaction = NULL) {
    $entities = $ids ? $this->load($ids) : FALSE;
    if (!$entities) {
      // Do nothing, in case invalid or no ids have been passed.
      return;
    }
    // This transaction causes troubles on MySQL, see
    // http://drupal.org/node/1007830. So we deactivate this by default until
    // is shipped in a point release.
    // $transaction = isset($transaction) ? $transaction : db_transaction();

    try {
      $ids = array_keys($entities);
/*
  TODO: WS delete

      db_delete($this->entityInfo['base table'])
        ->condition($this->idKey, $ids, 'IN')
        ->execute();

*/
      // Reset the cache as soon as the changes have been applied.
      $this->resetCache($ids);

      foreach ($entities as $id => $entity) {
        $this->invoke('delete', $entity);
      }
      // Ignore slave server temporarily.
      db_ignore_slave();
    }
    catch (Exception $e) {
      if (isset($transaction)) {
        $transaction->rollback();
      }
      watchdog_exception($this->entityType, $e);
      throw $e;
    }
  }

  /**
   * Implements EntityAPIControllerInterface.
   *
   * @param $transaction
   *   Optionally a DatabaseTransaction object to use. Allows overrides to pass
   *   in their transaction object.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $transaction = isset($transaction) ? $transaction : db_transaction();
    try {
      // Load the stored entity, if any.
      if (!empty($entity->{$this->idKey}) && !isset($entity->original)) {
        // In order to properly work in case of name changes, load the original
        // entity using the id key if it is available.
        $entity->original = entity_load_unchanged($this->entityType, $entity->{$this->idKey});
      }

      $this->invoke('presave', $entity);

      if (!empty($entity->{$this->idKey}) && empty($entity->is_new)) {

/*
  TODO: WS PUT
        $return = drupal_write_record($this->entityInfo['base table'], $entity, $this->idKey);
*/
        $this->resetCache(array($entity->{$this->idKey}));
        $this->invoke('update', $entity);
      }
      else {
/*
  TODO: WS POST
        $return = drupal_write_record($this->entityInfo['base table'], $entity);
*/
        $this->invoke('insert', $entity);
      }
      // Ignore slave server temporarily.
      db_ignore_slave();
      unset($entity->is_new);
      unset($entity->original);

      return $return;
    }
    catch (Exception $e) {
      $transaction->rollback();
      watchdog_exception($this->entityType, $e);
      throw $e;
    }
  }
}
