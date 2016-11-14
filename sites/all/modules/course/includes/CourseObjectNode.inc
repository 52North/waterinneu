<?php

/**
 * A course object that uses a node as a base.
 */
abstract class CourseObjectNode extends CourseObject {

  protected $node;

  public function __construct($values, $entityType) {
    parent::__construct($values, $entityType);
    if ($this->getInstanceId()) {
      if ($node = node_load($this->getInstanceId())) {
        $this->setNode($node);
      }
    }
  }

  /**
   * Course context handler callback.
   */
  public static function context() {
    // Get node from URL.
    if (arg(0) == 'node' && $node = node_load(arg(1))) {

      // This node might not be in a course, so let's check for related nodes.
      $instances = static::getNodeInstances($node);
      if (!empty($instances)) {
        $node = node_load($instances[0]);
      }

      if (isset($node->nid)) {
        return array(
          'object_type' => $node->type,
          'instance' => $node->nid,
        );
      }
    }
  }

  /**
   * When passed a node, this method should return the "parent" nodes that are
   * contained in a course outline.
   *
   * For example, if the passed node was a question in a quiz, all the quiz node
   * IDs should be returned.
   */
  public static function getNodeInstances($node) {
    return array();
  }

  public function hasNodePrivacySupport() {
    return module_exists('content_access') && module_exists('acl');
  }

  /**
   * Return a list of valid node types.
   *
   * @return array
   *   An array with node type machine names.
   */
  public abstract function getNodeTypes();

  /**
   * Simple node course object behavior is to just redirect to the node.
   */
  public function getTakeType() {
    return 'redirect';
  }

  public function getTakeUrl() {
    if ($this->getNode()) {
      return url("node/{$this->getNode()->nid}");
    }
  }

  public function getEditUrl() {
    if ($this->getNode()) {
      return url("node/{$this->getNode()->nid}/edit");
    }
  }

  public function getViewUrl() {
    if ($this->getNode()) {
      return url("node/{$this->getNode()->nid}");
    }
  }

  /**
   * Create a node and set it as this course object's node.
   *
   * @param stdClass $node
   *   A node to be processed for creation, or none to create a generic node. If
   *   a node is provided, it must have at least a type.
   */
  public function create($node = NULL) {
    global $user;
    if (!$node) {
      $node = new stdClass;
    }
    if (!isset($node->type)) {
      $node->type = $this->getOption('node_type');
    }
    $node->title = $this->getTitle();
    $node->uid = $user->uid;
    $node->language = LANGUAGE_NONE;
    node_object_prepare($node);
    node_save($node);
    $this->setNode($node);
  }

  /**
   * Set the node and instance ID (node ID) of this CourseObjectNode.
   *
   * @param mixed $node
   *   A node or node ID.
   */
  public function setNode($node) {
    $this->node = clone $node;
    $this->setInstanceId($this->node->nid);
  }

  /**
   * Destroy the node instance.
   */
  public function delete() {
    node_delete($this->getInstanceId());
  }

  public function optionsDefinition() {
    $defaults = parent::optionsDefinition();

    $defaults['private'] = !isset($this->node) && $this->hasNodePrivacySupport();

    $options = array_intersect_key(node_type_get_names(), drupal_map_assoc($this->getNodeTypes()));
    $defaults['node_type'] = key($options);

    $defaults['use_node_title'] = 0;

    $defaults['clone_and_reference'] = 0;

    $defaults['use_existing_node'] = 0;

    return $defaults;
  }

  public function optionsForm(&$form, &$form_state) {
    parent::optionsForm($form, $form_state);

    $form['node'] = array(
      '#type' => 'fieldset',
      '#title' => t('Content'),
      '#description' => ('Settings for course object content.'),
      '#group' => 'course_tabs',
      '#weight' => 2,
    );

    $config = $this->getOptions();

    $types = drupal_map_assoc($this->getNodeTypes());
    $options = array_intersect_key(node_type_get_names(), $types);

    $form['node']['use_existing_node'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use existing content'),
      '#default_value' => $this->getOption('use_existing_node'),
      '#weight' => 1,
      '#access' => $this->isTemporary(),
    );

    $form['node']['node_type'] = array(
      '#title' => t('Create node'),
      '#type' => 'select',
      '#options' => $options,
      '#description' => t('Selecting a node type will automatically create this node and link it to this course object.'),
      '#default_value' => $config['node_type'],
      '#states' => array(
        'visible' => array(
          ':input[name="use_existing_node"]' => array('checked' => FALSE),
        ),
      ),
      '#weight' => 2,
      '#access' => $this->isTemporary(),
    );
    if (count($options) > 1) {
      $form['node']['node_type']['#required'] = TRUE;
    }

    $form['node']['instance'] = array(
      '#title' => t('Existing content'),
      '#autocomplete_path' => 'course/autocomplete/node/' . implode(',', $this->getNodeTypes()),
      '#type' => 'textfield',
      '#description' => t('Use existing content instead of creating a new one.'),
      '#default_value' => !empty($this->node->nid) ? check_plain($this->node->title) . " [nid: {$this->node->nid}]" : NULL,
      '#maxlength' => 255,
      '#states' => array(
        'visible' => array(
          ':input[name="use_existing_node"]' => array('checked' => TRUE),
        ),
      ),
      '#weight' => 3,
    );

    if (module_exists('clone') && !$this->getInstanceId()) {
      $form['node']['clone_and_reference'] = array(
        '#title' => t('Clone and reference'),
        '#type' => 'checkbox',
        '#description' => t('This will clone the selected content first.'),
        '#default_value' => $config['clone_and_reference'],
        '#weight' => 4,
        '#states' => array(
          'visible' => array(
            ':input[name="use_existing_node"]' => array('checked' => TRUE),
          ),
        ),
      );
    }

    $form['node']['use_node_title'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use existing title'),
      '#description' => t("Use the referenced content's title as this course object's title."),
      '#default_value' => $config['use_node_title'],
      '#weight' => 5,
    );

    $form['node']['private'] = array(
      '#title' => t('Private'),
      '#description' => $this->hasNodePrivacySupport() ? t('This content will not be available to users who are not enrolled in this course.') : t('You must enable content_access and acl in order to restrict course content to users who are enrolled in this course.'),
      '#type' => 'checkbox',
      '#default_value' => $config['private'],
      '#disabled' => !($this->hasNodePrivacySupport()),
      '#weight' => 6,
    );

    $nid = $this->getInstanceId();
    if ($nid) {
      $node = node_load($nid);
      $link = l(t("'%title' [node id %nid]", array('%title' => $node->title, '%nid' => $node->nid)), "node/$node->nid", array('attributes' => array('target' => '_blank', 'title' => t('Open in new window')), 'html' => TRUE));
      $form['node']['instance']['#description'] = t('Currently set to !link', array('!link' => $link));
    }

    // Block deletion of self-referencing node instances.
    if (!empty($config['instance']) && ($config['instance'] == $this->getCourseNid())) {
      $form['delete']['delete_instance']['#disabled'] = TRUE;
      $form['delete']['delete_instance']['#description'] = t('You cannot delete this instance, as it references this Course.');
    }
  }

  /**
   * Validate the options form. Check the node type.
   */
  public function optionsValidate(&$form, &$form_state) {
    parent::optionsValidate($form, $form_state);
    $nid = $form_state['values']['instance'];

    if (empty($nid) && isset($form_state['values']['node_type']) && empty($form_state['values']['node_type'])) {
      form_set_error('node_type', t('Please select a node type.'));
    }

    $missing_node = !preg_match('/^(?:\s*|(.*) )?\[\s*nid\s*:\s*(\d+)\s*\]$/', $nid);
    if (($form_state['values']['use_existing_node'] || !$this->isTemporary()) && $missing_node) {
      form_set_error('instance', t('Please select a node.'));
    }
  }

  public function optionsSubmit(&$form, &$form_state) {
    if (isset($form_state['values']['instance'])) {
      $nid = $form_state['values']['instance'];

      if (!is_numeric($nid)) {
        if (preg_match('/^(?:\s*|(.*) )?\[\s*nid\s*:\s*(\d+)\s*\]$/', $nid, $matches)) {
          $nid = $matches[2];
        }
      }

      if ($nid) {
        $form_state['values']['instance'] = $nid;
      }
      else {
        // Unset it, or we'll erase the relationship (since the textfield is
        // actually blank).
        unset($form_state['values']['instance']);
      }
    }

    parent::optionsSubmit($form, $form_state);
  }

  /**
   * Grant access to course content before going to it.
   */
  function grant() {
    if ($this->hasNodePrivacySupport()) {
      if ($this->getOption('private')) {
        $uid = $this->user->uid;
        module_load_include('inc', 'content_access', 'content_access.admin');
        $acl_id = content_access_get_acl_id($this->node, 'view');
        acl_add_user($acl_id, $uid);
        acl_node_add_acl($this->node->nid, $acl_id, 1, 0, 0, content_access_get_settings('priority', $this->node->type));
        node_access_acquire_grants($this->node);
      }
    }
  }

  /**
   * Duration expired (or something) - CourseObject is telling us so.
   */
  function revoke() {
    if ($this->hasNodePrivacySupport()) {
      if ($this->getOption('private')) {
        $uid = $this->user->uid;
        module_load_include('inc', 'content_access', 'content_access.admin');
        $acl_id = content_access_get_acl_id($this->node, 'view');
        acl_remove_user($acl_id, $uid);
        node_access_acquire_grants($this->node);
      }
    }
  }

  /**
   * On object write, set privacy on this node.
   */
  function save() {
    if ($this->getOption('clone_and_reference')) {
      module_load_include('inc', 'clone', 'clone.pages');
      $new_nid = clone_node_save($this->getOption('instance'));
      $this->setInstanceId($new_nid);
      $this->setOption('clone_and_reference', 0);
    }

    parent::save();

    $privacy_enabled = $this->hasNodePrivacySupport() && $this->getOption('private');
    $external_node = $this->getInstanceId() > 0 && $this->getInstanceId() != $this->getCourseNid();
    if ($privacy_enabled && $external_node) {
      // Ensure that per-node access is enabled.
      $type_settings = content_access_get_settings('all', $this->node->type);
      $type_settings['per_node'] = 1;
      content_access_set_settings($type_settings, $this->node->type);

      // Remove "view" permissions to everyone on this node.
      $settings = content_access_get_per_node_settings($this->node);
      $grant_roles = array_filter(variable_get('course_object_private_roles', array()));
      $settings['view'] = $grant_roles;
      content_access_save_per_node_settings($this->node, $settings);

      // Resave node to update access.
      node_access_acquire_grants($this->node);
    }
  }

  /**
   * Freeze data to persist over cloning/exporting.
   * @return array
   *   An array of data to be frozen.
   */
  function freeze() {
    if ($this->node->nid != $this->getCourse()->getNode()->nid) {
      // Don't freeze the course, if this course is part of the objects.
      $ice = new stdClass;
      $ice->node = $this->node;
      return $ice;
    }
  }

  /**
   * Thaw data frozen from an earlier export/clone.
   *
   * @param array $data
   *   Unfrozen data.
   *
   * @return int
   *   The new instance ID.
   */
  function thaw($ice) {
    $this->node = $ice->node;
    unset($this->node->nid);
    unset($this->node->vid);
    node_save($this->node);
    return $this->node->nid;
  }

  function getCloneAbility() {
    return t('%object will be cloned as a node. Results may vary.', array('%object' => $this->getTitle()));
  }

  /**
   * Get the object title, or return this object's node's title if the option
   * is set.
   */
  function getTitle() {
    if ($this->getOption('use_node_title') && $this->node) {
      return $this->node->title;
    }
    else {
      return parent::getTitle();
    }
  }

  function getNode() {
    return node_load($this->instance);
  }

  function getOptionsSummary() {
    $summary = parent::getOptionsSummary();
    if ($this->getOption('instance') == $this->getCourseNid()) {
      // Don't show the edit instance link when the instance is
      // self-referencing.
      unset($summary['instance']);
    }
    return $summary;
  }

  /**
   * When setting our instance ID, also set the node.
   */
  function setInstanceId($id) {
    parent::setInstanceId($id);
    $this->node = node_load($id, NULL, TRUE);
  }

  /**
   * Show a warning if this object has an instance, but the node does not exist.
   */
  function getWarnings() {
    $warnings = parent::getWarnings();
    if ($this->getInstanceId() && !$this->getNode()) {
      $warnings[] = t('The content associated with this object has been deleted.<br/>Saving the course will create new content from the object settings.');
    }
    return $warnings;
  }

  /**
   * Deny access to objects without content.
   */
  function access($op = 'view', $account = NULL) {
    if ($op == 'take' && !$this->getNode()) {
      return FALSE;
    }
    return parent::access($op, $account);
  }

}
