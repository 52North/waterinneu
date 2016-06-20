<?php

/**
 * @file
 * Contains AtjsViewsHandlerRelationship.
 */

class AtjsViewsHandlerRelationship extends views_handler_relationship {
  private $to_entity = FALSE;
  /**
   * Init handler to let relationships live on tables other than
   * the table they operate on.
   */
  function init(&$view, &$options) {
    parent::init($view, $options);
    if (isset($this->definition['relationship table'])) {
      $this->table = $this->definition['relationship table'];
    }
    if (isset($this->definition['relationship field'])) {
      // Set both real_field and field so custom handler
      // can rely on the old field value.
      $this->real_field = $this->field = $this->definition['relationship field'];
    }
    // Determine if this is a relationship from an entity to a mention
    // or a relationship from a mention to an entity.
    $this->to_entity = $this->definition['base'] != 'atjs_listener_usage';
  }

  /**
   * Overrides views_handler_relationship::option_definition().
   *
   * Add in option definition.
   */
  function option_definition() {
    $options = parent::option_definition();
    if (!$this->to_entity) {
      $options['listeners'] = array('default' => array());
    }
    return $options;
  }

  /**
   * Overrides views_handler_relationship::options_form().
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    if ($this->to_entity) {
      return;
    }

    $form['listeners'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Listeners'),
      '#options' => atjs_listener_load_all_flat(),
      '#default_value' => $this->options['listeners'],
    );
  }

  /**
   * Overrides views_handler_relationship::query().
   *
   * Called to implement a relationship in a query.
   */
  function query() {
    if (!$this->to_entity) {
      parent::query();
      return;
    }

    /**
     * Include the extra where stuff.
     */
    $listeners = array_filter($this->options['listeners']);
    if (!empty($listeners)) {
      $this->definition['extra'][] = array(
        'field' => 'listener',
        'value' => $listeners,
      );
    }

    /**
     * Do the standard relationship query construction.
     */
    parent::query();
  }
}
