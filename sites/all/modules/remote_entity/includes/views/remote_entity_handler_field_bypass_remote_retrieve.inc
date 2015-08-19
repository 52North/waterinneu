<?php

/**
 * Dummy Views field handler for bypassing remote retrieval of entities.
 *
 * This should be placed as the first field, so that it affects all field
 * handlers. This is a bit clumsy from a UI point of view, but the alternatives
 * are not that palatable either: a) subclass views_plugin_query_default, which
 * then prevents use of other specialised query handlers, or b) subclass
 * views_handler_field_field for all fields on Remote Entities, which doesn't
 * cover everything and isn't a brilliant UI either.
 */
class remote_entity_handler_field_bypass_remote_retrieve extends views_handler_field {

  function option_definition() {
    $options = parent::option_definition();

    $options['remote_entity_bypass_entity_types'] = array('default' => array());

    // Force a default on some of the options from the parent class.
    $options['exclude'] = array('default' => TRUE, 'bool' => TRUE);

    return $options;
  }

  /**
   * The options form for this handler.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $relationship_handlers = $this->view->display_handler->get_handlers('relationship');
    //dsm($relationship_handlers);

    // Assemble a list of tables that bring entities: the base table, and those
    // from relationships.
    $tables = array();
    $tables[] = $this->view->base_table;
    foreach ($relationship_handlers as $relationship_id => $relationship_handler) {
      // The 'base' of a relationship is the table it brings.
      $tables[] = $relationship_handler->definition['base'];
    }

    $entity_info = entity_get_info();
    $entity_type_options = array();
    foreach ($tables as $table) {
      // Get the entity type from the table.
      $table_data = views_fetch_data($table);
      if (isset($table_data['table']['entity type'])) {
        $entity_type = $table_data['table']['entity type'];

        // Only take entities that are remote entities.
        if (isset($entity_info[$entity_type]['remote base table'])) {
          $entity_type_options[$entity_type] = $entity_info[$entity_type]['label'];
        }
      }
    }

    $form['remote_entity_bypass_entity_types'] = array(
      '#type' => 'checkboxes',
      '#title' => t("Entity types to bypass"),
      '#description' => t("Entities of the selected types will not be loaded from remote even if they are expired."),
      '#options' => $entity_type_options,
      '#default_value' => $this->options['remote_entity_bypass_entity_types'],
    );

    // Hide some of the options from the parent class.
    $form['custom_label']['#access'] = FALSE;
    $form['label'] = FALSE;
    $form['element_label_colon'] = FALSE;
    $form['exclude'] = FALSE;
  }

  /**
   * Provide extra data to the administration form
   */
  function admin_summary() {
    // Show the list of selected entity types.
    $entity_info = entity_get_info();
    $entity_type_labels = array();
    foreach (array_filter($this->options['remote_entity_bypass_entity_types']) as $entity_type) {
      $entity_type_labels[] = $entity_info[$entity_type]['label'];
    }

    return implode(', ', $entity_type_labels);
  }

  function query() {
    // Fake field, don't query.
  }

  /**
   * Run after the view is executed, before the result is cached.
   *
   * This is the same method that views_handler_field_field uses to load
   * entities, so provided we are before any of those in the field order, we
   * get to the entity controller in time.
   */
  function post_execute(&$values) {
    foreach (array_filter($this->options['remote_entity_bypass_entity_types']) as $entity_type) {
      // Get the controller and set it to bypass remote retrievals. Drupal core
      // caches controllers statically, so any subsequent entity load will of
      // this entity type will be affected.
      $controller = entity_get_controller($entity_type);

      $controller->bypass_remote_retrieve = TRUE;
    }

  }

}
