<?php
/**
 * @file remote_entity.admin.inc
 *
 * Contains admin page callbacks.
 */

/**
 * Admin form: overview of remote entities, retry failed remote saves.
 */
function remote_entity_page_report_form($form, &$form_state) {
  // Show a summary of entities' remote save status.
  $options = array();

  // Array of entity types that have failed entities for the batch operation.
  $form['#entity_types_failed'] = array();

  foreach (entity_get_info() as $entity_type => $entity_info) {
    // Skip entities that are not remote entities.
    if (!isset($entity_info['remote base table'])) {
      continue;
    }

    // Skip entities that don't have the 'needs remote save' property.
    if (!isset($entity_info['entity keys']['needs remote save'])) {
      continue;
    }

    $table = $entity_info['base table'];
    $id_key = $entity_info['entity keys']['id'];
    $needs_remote_save_key  = $entity_info['entity keys']['needs remote save'];

    $query = db_query("SELECT $needs_remote_save_key, count($id_key) FROM $table WHERE $needs_remote_save_key != 0 GROUP BY $needs_remote_save_key");
    $counts = $query->fetchAllKeyed();

    // Add in defaults for tables which don't have the full range of values.
    $counts += array(
      REMOTE_ENTITY_REMOTE_SAVE_NEEDED => 0,
      REMOTE_ENTITY_REMOTE_SAVE_FAILED => 0,
    );

    $row = array();
    $row['entity_type'] = $entity_info['label'];
    $row['remote_save'] = $counts[REMOTE_ENTITY_REMOTE_SAVE_NEEDED];
    $row['remote_save_failed'] = $counts[REMOTE_ENTITY_REMOTE_SAVE_FAILED];

    $options[$entity_type] = $row;

    // Save the value in the form for the batch operation.
    $form['#entity_types_failed'][$entity_type] = $counts[REMOTE_ENTITY_REMOTE_SAVE_FAILED];
  }

  $form['entity_types'] = array(
    '#type' => 'tableselect',
    '#header'  => array(
      'entity_type' => t('Entity type'),
      'remote_save' => t('Need remote save'),
      'remote_save_failed' => t('Remote save failed'),
    ),
    '#options' => $options,
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Re-attempt remote save of failed entities'),
    '#access' => user_access('re-attempt remote save of remote entities'),
  );

  return $form;
}

/**
 * Submit handler: start a batch to re-save failed entities.
 */
function remote_entity_page_report_form_submit($form, &$form_state) {
  $operations = array();

  // The stored array only has items for entity types with failed entities,
  // so the value is never 0.
  foreach (array_filter($form_state['values']['entity_types']) as $entity_type) {
    $failed_count = $form['#entity_types_failed'][$entity_type];

    $operations[] = array('remote_entity_batch_operation_resave_failed_entities', array($entity_type, $failed_count));
  }

  $batch = array(
    'operations' => $operations,
    'finished' => 'remote_entity_batch_finished_resave_failed_entities',
    'file' => drupal_get_path('module', 'remote_entity') . '/includes/remote_entity.admin.inc',
  );

  batch_set($batch);
}

/**
 * Implementation of callback_batch_operation().
 *
 * Attempt to save remote entities that are marked as having failed to save
 * previously.
 *
 * @param $entity_type
 *  The entity type to process.
 * @param $failed_count
 *  The number of entities that are flagged as having failed to save remotely.
 *  This is non-zero.
 */
function remote_entity_batch_operation_resave_failed_entities($entity_type, $failed_count, &$context) {
  if (empty($context['sandbox'])) {
    // We need to use a highwater mark, as otherwise an entity that fails during
    // this operation will get picked up every time this operation is called,
    // and it will never know to terminate.
    $context['sandbox']['highwater'] = 0;
    $context['sandbox']['processed'] = 0;

    $context['results'][$entity_type]['success'] = array();
    $context['results'][$entity_type]['failed'] = array();
  }

  // Batch size per run.
  $batch_size = 10;

  // Load a batch of entities that failed to remote save.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', $entity_type)
    ->propertyCondition('needs_remote_save', REMOTE_ENTITY_REMOTE_SAVE_FAILED)
    ->propertyCondition('eid', $context['sandbox']['highwater'], '>')
    ->propertyOrderBy('eid', 'ASC')
    ->range(0, $batch_size);

  $result = $query->execute();
  if (!isset($result[$entity_type])) {
    // No entities of this type left: let this operation finish.
    $context['finished'] = 1;
    return;
  }

  $entities = entity_load($entity_type, array_keys($result[$entity_type]));

  foreach ($entities as $eid => $entity) {
    try {
      // Use the single save.
      remote_entity_save($entity_type, $entity);

      $context['results'][$entity_type]['success'][] = $eid;
    }
    catch (Exception $e) {
      // Store a list of the failed entities for output.
      // Get the path to the entity now while we have it loaded.
      $uri = $entity->uri();
      $context['results'][$entity_type]['failed'][] = array($eid, $uri['path']);
    }

    // Advance the highwater to the entity we just saw.
    $context['sandbox']['highwater'] = $eid;

    $context['sandbox']['processed']++;
  }

  // Come back here next time.
  $context['finished'] = $context['sandbox']['processed'] / $failed_count;
}

/**
 * Implementation of callback_batch_finished().
 */
function remote_entity_batch_finished_resave_failed_entities($success, $results, $operations) {
  foreach ($results as $entity_type => $entity_type_results) {
    // Show a list of the entities that failed again, with links.
    // This assumes that the list of not humungous and will break Drupal with a
    // giant message!
    // TODO: look at other ways to output this.
    $failed_entities_links = array();
    foreach ($entity_type_results['failed'] as $data) {
      list ($eid, $path) = $data;
      $failed_entities_links[] = l($eid, $path);
    }

    $replacements = array(
      '!type' => $entity_type,
      '!count-saved' => count($entity_type_results['success']),
      '!ids-failed' => implode(', ', $failed_entities_links),
    );
    if (count($entity_type_results['failed'])) {
      drupal_set_message(t("Successfully remotely saved !count-saved !type entities. The following entities failed to save: !ids-failed.", $replacements));
    }
    else {
      drupal_set_message(t("Successfully remotely saved !count-saved !type entities. No entities failed to save.", $replacements));
    }
  }
}
