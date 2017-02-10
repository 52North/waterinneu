<?php

/**
 * Parent abstract base class of all course objects.
 *
 * Represents a course object in the database.
 *
 * Also holds a fulfillment record if a user is given.
 */
abstract class CourseObject extends CourseHandler {

  protected $accessMessages = array();

  /**
   * Override navigation links.
   *
   * @return array
   *   An array of navigation links. Keyed values will override matching items
   *   in Course::getNavigation().
   */
  public function overrideNavigation() {
    return array();
  }

  /**
   * Specify whether fulfillment uses asynchronous polling.
   *
   * @return bool
   *   Whether this object uses polling. Defaults to FALSE.
   */
  public function hasPolling() {
    return FALSE;
  }

  /**
   * Overrides a course outline list item.
   *
   * @param array $item
   *   A course outline list item. The structure mirrors an array element from
   *   the $items param from theme_item_list().
   */
  public function overrideOutlineListItem(&$item) {

  }

  /**
   * Access functionality for course objects.
   *
   * Possible values for $op are 'see', 'view', 'take'.
   *
   * "see" means see it in a course outline. For example, a conditional survey
   * should not be seen in the course outline. A quiz at the end of the course,
   * should show up, but the user must not be able to take it.
   *
   * "view" means view and interact with the object, but nothing would be
   * recorded. For example, accessing a quiz but not being able to submit
   * responses.
   *
   * "take" means interact with the object in a way that records data.
   *
   * Subclasses may override this functionality.
   */
  public function access($op = 'view', $account = NULL) {
    ctools_include('plugins');
    $access = FALSE;

    if (!$account) {
      global $user;
      $account = $user;
    }

    if (!$this->getOption('enabled') || $this->getOption('hidden')) {
      // Object is disabled or hidden so it should never be visible.
      return FALSE;
    }

    switch ($op) {
      case 'see':
        // User can see this object in the outline.
        $access = TRUE;
        break;
      case 'take':
      case 'view':
        if (!$account->uid) {
          // Not logged in. Should never be accessible.
          return FALSE;
        }

        // Stock access: check for completion of previous object.
        // Get a copy of the course, so we can run setActive() without changing
        // the global course.
        $course = clone $this->getCourse();
        $course->setActive($this->getId());
        $courseObjects = $course->getObjects();

        // Deny object access to non-enrolled users or users who cannot take
        // this course.
        $result = course_access_course('take', $this->getCourse()->getNode(), $account);
        if (!course_enrollment_check($this->getCourseNid(), $account->uid) || !$result['success']) {
          return FALSE;
        }
        else if (reset($courseObjects)->getId() == $this->getId()) {
          // User is enrolled. Grant access if first object.
          $access = TRUE;
        }

        if ($course->getPrev() && (!$course->getPrev()->isRequired() || ($course->getPrev()->isRequired() && $course->getPrev()->isSkippable()))) {
          // Previous step was not required.
          $access = TRUE;

          // But we need to see if at least one required step was completed (or the start of the course).
          $objects = array_reverse($course->getObjects());
          $check = FALSE;
          foreach ($objects as $object) {
            if (!$object->getOption('enabled')) {
              // Do not check this object.
              // Note that hidden objects are still counted when doing
              // fulfillment checks.
              continue;
            }

            if ($check) {
              if ($object->isRequired() && !$object->isSkippable()) {
                // Object is required.
                if (!$object->getFulfillment()->isComplete()) {
                  // Found a required object that was not complete.
                  $access = FALSE;
                  break;
                }
                else {
                  // The last required object was completed.
                  $access = TRUE;
                  break;
                }
              }
            }
            if ($object->getId() == $this->getId()) {
              // We found the object we are trying to check access on.
              // Now we want to go backwards.
              $check = 1;
            }
          }
        }

        if ($course->getPrev() && $course->getPrev()->getFulfillment()->isComplete()) {
          // If last object was complete, and we are on the current object,
          // grant access.
          $access = TRUE;
        }
    }

    // Plugin access.
    foreach (ctools_get_plugins('course', 'course_object_access') as $key => $plugin) {
      $class = ctools_plugin_get_class($plugin, 'handler');
      $accessPlugin = new $class();
      $accessPlugin->setCourseObject($this);
      $accessPlugin->setType($key);

      // Run access check.
      $ret = $accessPlugin->$op();

      if ($ret === FALSE) {
        // If previous access was granted, revoke it.
        $access = $ret;
      }
    }

    return $access;
  }

  public function isActive() {
    return $this->getCourse()->current()->getId() == $this->getId();
  }

  /**
   * Define configuration elements and their defaults.
   *
   * Extended classes should call parent::optionsDefinition first to get the
   * parent's configuration.
   */
  public function optionsDefinition() {
    $defaults = parent::optionsDefinition();

    $defaults += array(
      'uniqid' => NULL,
      'nid' => NULL,
      'title' => NULL,
      'enabled' => 1,
      'hidden' => 0,
      'required' => 1,
      'skippable' => 0,
      'delete' => 0,
      'delete_instance' => 0,
      'grade_include' => 0,
      'instance' => NULL,
      'data' => '',
      'plugins' => array(),
    );

    return $defaults;
  }

  /**
   * Default options form for all course objects.
   */
  public function optionsForm(&$form, &$form_state) {
    ctools_include('plugins');
    parent::optionsForm($form, $form_state);

    $config = $this->getOptions();

    $form['header']['#markup'] = t("<h2>Settings for %t</h2>", array('%t' => $this->getTitle()));

    $form['uniqid'] = array(
      '#type' => 'value',
      '#value' => $this->getId(),
    );

    $form['nid'] = array(
      '#type' => 'value',
      '#value' => $this->getCourseNid(),
    );

    $form['course_tabs']['#type'] = 'vertical_tabs';

    $form['title'] = array(
      '#title' => t('Title & description'),
      '#type' => 'fieldset',
      '#group' => 'course_tabs',
      '#weight' => 0,
    );

    $form['outline'] = array(
      '#type' => 'fieldset',
      '#title' => t('Settings'),
      '#group' => 'course_tabs',
      '#weight' => 1,
    );

    $form['plugins']['access'] = array(
      '#type' => 'fieldset',
      '#title' => 'Access',
      '#group' => 'course_tabs',
      '#weight' => 4,
    );

    $form['delete'] = array(
      '#type' => 'fieldset',
      '#title' => 'Delete',
      '#group' => 'course_tabs',
      '#weight' => 5,
    );

    $form['title']['title'] = array(
      '#title' => t('Title'),
      '#type' => 'textfield',
      '#description' => t('The title of this course object as it will appear to users in the course outline.'),
      '#size' => 100,
      '#default_value' => check_plain($config['title']),
      '#group' => 'description',
      '#required' => TRUE,
    );

    $form['outline']['enabled'] = array(
      '#title' => t('Enabled'),
      '#type' => 'checkbox',
      '#description' => t('Enabled course objects will become part of the course. Uncheck this box if you are not using this course object.'),
      '#default_value' => $config['enabled'],
    );

    $form['outline']['hidden'] = array(
      '#title' => t('Visible in outline'),
      '#type' => 'checkbox',
      '#description' => t('Objects that are not visible will not be seen by the learner. Uncheck this box for course objects that you do not want the learner to see.'),
      '#default_value' => !$config['hidden'],
      '#group' => 'course',
    );

    $form['outline']['required'] = array(
      '#title' => t('Completion required'),
      '#type' => 'checkbox',
      '#description' => t('Users must complete required objects. Uncheck this box if this is an optional course object.'),
      '#default_value' => $config['required'],
    );

    $form['outline']['skippable'] = array(
      '#title' => t('Skippable'),
      '#type' => 'checkbox',
      '#default_value' => $config['skippable'],
      '#states' => array('visible' => array('#edit-required' => array('checked' => TRUE))),
      '#description' => t('Users can proceed past this object but it will still be required for course completion.'),
    );

    // Delete object
    $form['delete']['delete_button'] = array(
      '#value' => t('Delete'),
      '#weight' => 999,
      '#type' => 'submit',
      '#submit' => array(
        array($this, 'setDelete'),
        array($this, 'optionsSubmit'),
      ),
      '#limit_validation_errors' => array(),
    );

    // Only allow deletion of existing instances.
    if (!empty($config['instance'])) {
      $form['delete']['delete_instance'] = array(
        '#title' => t('Also delete the referenced content.'),
        '#type' => 'checkbox',
        '#default_value' => $config['delete_instance'],
        '#stats' => array('visible' => array('#edit-delete' => array('checked' => TRUE))),
        '#group' => 'delete',
      );

      // Check for multiple instances.
      if (db_query("SELECT count(coid) FROM {course_outline} WHERE module = :module AND object_type = :object_type AND instance = :instance", array(':module' => $config['module'], ':object_type' => $config['object_type'], ':instance' => $config['instance']))->fetchField() > 1) {
        $form['delete']['delete_instance']['#description'] = t('<span class="error"><strong>WARNING</strong></span>: multiple course objects link to this instance. Deleting the instance might break the other course objects that use it.');
      }
    }

    if ($this->isGraded()) {
      $form['grading'] = array(
        '#title' => t('Grading'),
        '#type' => 'fieldset',
        '#description' => t('Settings for graded objects.'),
        '#group' => 'course_tabs',
      );

      $form['grading']['grade_include'] = array(
        '#title' => t('Include in final course grade'),
        '#description' => t('Include this grade result for calculation of the final course grade.<br/>Currently, only the last grade result per Course will be used.'),
        '#default_value' => $config['grade_include'],
        '#type' => 'checkbox',
      );
    }

    // Bring in access plugin configuration.
    $form['plugins']['#tree'] = TRUE;
    $form['plugins']['access']['#title'] = t('Access');
    $form['plugins']['access']['#description'] = t('By default, all required objects appearing before this object in the course outline must be completed before the user may access this object. Conditional access allows for additional conditions to be applied.');
    $form['plugins']['access']['#type'] = 'fieldset';
    foreach (ctools_get_plugins('course', 'course_object_access') as $key => $plugin) {
      $form['plugins']['access']['#tree'] = TRUE;
      $form['plugins']['access'][$key] = array(
        '#title' => $plugin['title'],
        '#type' => 'fieldset',
        '#tree' => TRUE,
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );

      // Initialize access class.
      $class = ctools_plugin_get_class($plugin, 'handler');
      $courseAccess = new $class();
      $courseAccess->setCourseObject($this);
      $courseAccess->setType($key);

      // Add access plugin form to our form.
      $access_form = $access_form_state = array();
      $form['plugins']['access'][$key] += $courseAccess->optionsForm($access_form, $access_form_state);
    }

    // Update settings
    $form['actions']['update'] = array(
      '#value' => t('Update'),
      '#weight' => 999,
      '#type' => 'submit',
      '#validate' => array(
        array($this, 'optionsValidate'),
      ),
      '#submit' => array(
        array($this, 'optionsSubmit'),
      ),
    );
  }

  /**
   * Mark this object for deletion.
   */
  public function setDelete(&$form, &$form_state) {
    $form_state['values']['delete'] = 1;
  }

  public function optionsValidate(&$form, &$form_state) {
    // Pass validation to plugins.
    ctools_include('plugins');
    foreach (ctools_get_plugins('course', 'course_object_access') as $key => $plugin) {
      $values = & $form_state['values']['plugins']['access'][$key];
      $class = ctools_plugin_get_class($plugin, 'handler');
      $instance = new $class($values);
      $instance->setCourseObject($this);
      $instance->setType($key);
      $instance->optionsValidate($form['plugins']['access'][$key], $form_state['values']['plugins']['access'][$key]);
    }
  }

  /**
   * Save object configs to cache.
   */
  public function optionsSubmit(&$form, &$form_state) {
    ctools_include('plugins');

    $uniqid = $this->getId();
    $nid = $this->getCourseNid();

    // Start editing session.
    course_editing_start($this->getCourse());

    // Flip 'visible' so it behaves like 'hidden'.
    if (isset($form_state['values']['hidden'])) {
      $form_state['values']['hidden'] = ($form_state['values']['hidden'] != 1);
    }

    // Object-specific settings
    foreach (array_keys($this->getOptions()) as $key) {
      if (isset($form_state['values'][$key]) && !is_null($form_state['values'][$key])) {
        $_SESSION['course'][$nid]['editing'][$uniqid][$key] = $form_state['values'][$key];
      }
    }

    // Save plugin info.
    if (isset($form_state['values']['plugins'])) {
      foreach (ctools_get_plugins('course', 'course_object_access') as $key => $plugin) {
        $_SESSION['course'][$nid]['editing'][$uniqid]['plugins']['access'][$key] = $form_state['values']['plugins']['access'][$key];
      }
    }

    // Update the options.
    $this->setOptions($_SESSION['course'][$nid]['editing'][$uniqid]);
  }

  /**
   * Get core options summary.
   *
   * @return array
   *   An associative array of summary keys and values.
   */
  public function getOptionsSummary() {
    $summary = parent::getOptionsSummary();

    // Get options.
    $options = $this->getOptions();

    // Add course object core options to summary individually, because there are
    // options we don't want to display, and others that require special logic.
    $uniqid = $options['uniqid'];

    // Enabled.
    if ($options['enabled']) {
      $summary['enabled'] = t('Enabled');
    }
    else {
      $summary['enabled'] = '<span class="warning">' . t('Not enabled') . '</span>';
    }

    // Hidden.
    if (!$options['hidden']) {
      $summary['hidden'] = t('Visible in outline');
    }
    else {
      $summary['hidden'] = '<span class="warning">' . t('Not visible in outline') . '</span>';
    }

    // Required.
    if ($options['required']) {
      $summary['required'] = t('Completion required');
      if ($options['skippable']) {
        $summary['skippable'] = '<span class="warning">' . t('Skippable') . '</span>';
      }
    }
    else {
      $summary['required'] = '<span class="warning">' . t('Completion not required') . '</span>';
    }

    // Instance edit link.
    $editUrl = $this->getEditUrl();
    if (!empty($editUrl)) {
      $text = t('Edit instance');
      $summary['instance'] = l($text, $editUrl, array('external' => TRUE, 'query' => drupal_get_destination()));
    }
    elseif ($this->isTemporary()) {
      $summary['instance'] = '<span class="warning">' . t('Save course to edit object') . '</span>';
    }

    // Instance view link.
    $viewUrl = $this->getViewUrl();
    if (!empty($viewUrl)) {
      $text = t('View instance');
      $summary['instance_view'] = l($text, $viewUrl, array('external' => TRUE, 'query' => drupal_get_destination()));
    }

    // Required.
    if (!empty($options['delete'])) {
      $dest = "node/{$options['nid']}/course-object/nojs/{$this->getId()}/restore";
      $text = t('Object will be removed from outline');
      $restore_text = t('Restore this object to the course outline.');
      if ($options['delete_instance']) {
        $text = t('Object will be removed from outline, and related instance(s) will be deleted');
        $restore_text = t('Restore this object and related instance(s) to the course outline.');
      }
      $restore = ctools_ajax_text_button(t('Restore'), $dest, $restore_text);
      $summary['delete'] = '<span class="error">' . $text . '</span>' . ' ' . $restore;
    }

    return $summary;
  }

  /**
   * Get all course object implementations of getOptionsSummary().
   */
  public function renderOptionsSummary() {
    ctools_include('plugins');
    $summary = $this->getOptionsSummary();

    // Get summaries from plugins, and merge into the summary.
    foreach (ctools_get_plugins('course', 'course_object_access') as $key => $plugin) {
      // @todo how do we get these?
    }

    // @todo make this a themeable function.
    //return theme('course_object_summary');
    $rendered_summary = '';
    if (!empty($summary)) {
      $rendered_summary = $html = '<div class="description">' . theme('item_list', array('title' => '', 'items' => $summary)) . '</div>';
    }

    return $rendered_summary;
  }

  /**
   * Get options, with session options, except weight, having precedence.
   */
  public function getOptions() {
    $options = parent::getOptions();
    $sessionDefaults = array();
    if (isset($options['nid']) && isset($options['coid']) && isset($_SESSION['course'][$options['nid']]['editing'][$options['coid']])) {
      $sessionDefaults += array_filter((array) $_SESSION['course'][$options['nid']]['editing'][$options['coid']], array($this, 'optionFilter'));
      unset($sessionDefaults['weight']);
    }
    return array_merge($options, (array) $sessionDefaults);
  }

  private function optionFilter($a) {
    return !is_null($a);
  }

  /**
   * Take a course object.
   *
   * - Set the session of this course object being taken. This allows for
   *   non-node objects to be tracked.
   * - Delegate the course object take functionality
   *
   * @return mixed
   *   HTML content or a redirect.
   */
  public final function takeCourseObject() {
    $_SESSION['course']['active'] = $this->getCourseNid();
    $_SESSION['course'][$this->getCourseNid()]['taking']['active'] = $this->getId();

    // Run access checks.
    if ($this->access('take')) {
      // Grant access to external course object.
      $this->grant();

      // Record start date.
      if (!$this->getFulfillment()->getOption('date_started')) {
        $this->getFulfillment()->setOption('date_started', REQUEST_TIME)->save();
      }
    }
    else {
      // User can't access this object, revoke access.
      $this->revoke();
      return FALSE;
    }

    // If we're not displaying any content but we want to fire take() anyway, to
    // let the course object know we sent the user.
    $out = $this->take();

    $url = $this->getTakeUrl();
    switch ($this->getTakeType()) {
      case 'iframe':
        return course_iframe($url);
      case 'popup':
        return "will popup $url";
      case 'content':
        return $out;
      case 'redirect':
      default:
        // This URL should have already been url()'d (it might be external).
        drupal_goto($url, array('external' => TRUE));
    }
  }

  /**
   * How should this course object be executed?
   *
   * - iframe: display an iframe with getTakeUrl() in it
   * - popup: launch getTakeUrl() in a popup
   * - modal: launch getTakeUrl() in a modal
   * - content: print the value from take() (or do whatever the module wants to
   *   do)
   */
  public function getTakeType() {
    return 'content';
  }

  /**
   *
   */
  public function take() {
    return t('This should be overridden by the module to return course content.');
  }

  /**
   * Return the URL to the course object router.
   */
  public function getUrl() {
    return 'node/' . $this->getCourseNid() . '/course-object/' . $this->getId();
  }

  /**
   * Get the URL to take this course object, if any.
   *
   * Outline handlers or subclasses should use getUrl().
   *
   * @return string
   */
  protected function getTakeUrl() {

  }

  /**
   * Get the URL to edit this course object, if any.
   *
   * @return string
   */
  public function getEditUrl() {

  }

  /**
   * Get the URL to view this course object, if any.
   *
   * @return string
   */
  public function getViewUrl() {

  }

  /**
   * Is this course object required for course completion?
   *
   * @return bool
   */
  public function isRequired() {
    return (bool) $this->getOption('required');
  }

  /**
   * If this course object is required, can be it skipped?
   *
   * @return bool
   */
  public function isSkippable() {
    return (bool) $this->getOption('skippable');
  }

  /**
   * Is this object graded?
   *
   * Returning TRUE here will cause some more configurations to show on the
   * object's form.
   *
   * @return bool
   */
  function isGraded() {
    return FALSE;
  }

  /**
   * Get the user's status in this course object.
   *
   * This is how an object would notify the user why they cannot proceed to the
   * next step from the course outline. For example, if this was a quiz and
   * they failed, this should let them know.
   */
  public function getStatus() {

  }

  /**
   * Get the user's fulfillment for this course object.
   *
   * @return CourseObjectFulfillment
   */
  public function getFulfillment($account = NULL) {
    if (!$account) {

      /** @deprecated */
      if (!empty($this->user)) {
        $account = $this->user;
      }
      else {
        global $user;
        $account = $user;
      }
    }

    if ($entities = entity_load('course_object_fulfillment', FALSE, array('coid' => $this->identifier(), 'uid' => $account->uid), TRUE)) {
      return reset($entities);
    }
    else {
      return entity_create('course_object_fulfillment', array('coid' => $this->identifier(), 'uid' => $account->uid, 'module' => $this->module, 'object_type' => $this->object_type));
    }
  }

  /**
   * Get the instance ID. This could be the external component ID, a Node ID...
   *
   * @return string
   */
  function getInstanceId() {
    return $this->getOption('instance');
  }

  /**
   * Set this object's instance ID.
   *
   * @param mixed $id The external ID of this course object.
   */
  function setInstanceId($id) {
    return $this->setOption('instance', $id);
  }

  /**
   * Get the course node ID this CourseObject belongs to.
   *
   * @return int
   */
  function getCourseNid() {
    return intval($this->getOption('nid'));
  }

  /**
   * Set the Course for this CourseObject.
   *
   * @param Course|int $course
   *   A Course or node ID.
   *
   * @return CourseObject
   */
  public function setCourse($course) {
    if (is_numeric($course)) {
      $this->setOption('nid', $course);
    }
    else {
      $this->setOption('nid', $course->getNode()->nid);
    }
    return $this;
  }

  /**
   * Get the Course that contains this CourseObject.
   *
   * @return Course
   */
  function getCourse() {
    $course = entity_load_single('course', $this->nid);

    /** @deprecated */
    if (!empty($this->user)) {
      $account = $this->user;
    }
    else {
      global $user;
      $account = $user;
    }
    $course->setUser($account);

    return $course;
  }

  /**
   * Get the module that provides this course object.
   *
   * @return string
   */
  function getModule() {
    return $this->getOption('module');
  }

  /**
   * Get the object component title for this course object.
   *
   * @return string
   */
  function getComponentName() {
    $handlers = course_get_handlers('object');
    return $handlers[$this->getModule()][$this->getComponent()]['name'];
  }

  /**
   * Get the object component for this course object.
   *
   * @return string
   */
  function getComponent() {
    return $this->getOption('object_type');
  }

  /**
   * Set the module that provides this course object.
   *
   * @return CourseObject
   */
  function setModule($module) {
    return $this->setOption('module', $module);
  }

  /**
   * Set the object component for this course object.
   *
   * @return CourseObject
   */
  function setComponent($component) {
    return $this->setOption('object_type', $component);
  }

  /**
   * Set the internal course object ID.
   *
   * @param int $coid
   *   ID of the course object.
   */
  function setId($coid) {
    return $this->setOption('coid', $coid);
  }

  /**
   * Creates a course object.
   *
   * For example, this would create the new node and return the node ID if this
   * was a CourseObjectNode.
   *
   * Do not confuse this with save(), which saves the course outline record for
   * tracking.
   *
   * Course objects should call setInstanceId() if this is a course object
   * that creates external resources.
   */
  public function create() {
    //$this->setInstanceId($id);
  }

  /**
   * Deletes a course object's external resources.
   *
   * For example, this would delete the associated node (if this was a
   * CourseObjectNode) and delete all other associated data.
   */
  public function delete() {
    //something_delete($this->getInstanceId());
  }

  function getTitle() {
    $object_info = course_get_handlers('object');

    // If title is not specified, set title from component.
    if (!$this->getOption('title')) {
      // Get the component name from object info.
      $title = $object_info[$this->getOption('module')][$this->getOption('object_type')]['name'];
      $this->setOption('title', $title);
    }

    return $this->getOption('title');
  }

  /**
   * Give the course object a chance do asynchronous polling and set completion
   * on demand.
   *
   * Useful for external objects.
   */
  function poll() {

  }

  /**
   * Grant access to the external course object.
   *
   * For example, adding a user to an access control list.
   *
   * @see CourseObjectNode::grant()
   */
  function grant() {

  }

  /**
   * Revoke access to the external course object.
   *
   * For example, removing a user to an access control list.
   *
   * @see CourseObjectNode::revoke()
   */
  function revoke() {

  }

  /**
   * Let the course object provide its own reports.
   *
   * @return array
   *   An array indexed by report key, containing 'title' which is the menu link
   *   in the course object reports.
   *
   * @see CourseObjectQuiz::getReports()
   */
  function getReports() {
    return array(
      'default' => array(
        'title' => 'Overview',
      ),
    );
  }

  /**
   * Let the course object provide its own reports.
   *
   * @return array
   *   An array containing:
   *     - title: The title of this report as show on the page
   *     - content: Content to be displayed.
   *     - url: URL to be loaded in an iframe.
   *   Reports should return either 'content' or 'url'.
   *
   * @see CourseObjectQuiz::getReports()
   */
  function getReport($key) {
    if ($key == 'default') {
      return array(
        'title' => 'Overview',
        'content' => views_embed_view('course_object_report', 'default', $this->getCourseNid(), $this->getId()),
      );
    }
  }

  function freeze() {

  }

  function thaw($ice) {

  }

  /**
   * Returns an translated error message if this object has issues with cloning.
   *
   * @return mixed
   *   TRUE if cloning is supported, FALSE if cloning is not supported. A string
   *   if the object can clone but with caveats.
   */
  function getCloneAbility() {
    return FALSE;
  }

  /**
   * Let objects create their instances before saving the course object.
   */
  public function save() {
    // If there is no title, set it.
    $this->getTitle();

    if ($ice = $this->getOption('freeze')) {
      // Found frozen data.
      $this->setInstanceId($this->thaw($ice));
      $this->setOption('freeze', NULL);
    }

    // If there is no instance ID, create one.
    if (!$this->getInstanceId()) {
      $this->create();
    }

    // Set the ID to NULL because this is a temporary course object being
    // created for the first time.
    if (strpos($this->getId(), 'course_object_') !== FALSE) {
      $this->setId(NULL);
    }

    return parent::save();
  }

  /**
   * Remove any records associated with this course object for the user.
   *
   * For example, deleting quiz results when a user is removed from the course.
   */
  function unEnroll() {

  }

  /**
   * Checks the temporary status of a course object.
   */
  function isTemporary() {
    return strpos($this->getId(), 'course_object_') === 0;
  }

  /**
   * Return the number of occurances that can be in a course at the same time.
   * For example, the design of the Certificate module can only have 1 set of
   * mappings per node. The same goes for Course Credit. We may also want a
   * course object that can only be added twice (for example, a before/after
   * comparison).
   *
   * This method is static because we might have to call it without an object
   * being instantiated.
   */
  public static function getMaxOccurences() {
    return FALSE;
  }

  /**
   * Set the context of which course this course object belongs to.
   *
   * The return parameters should be compliant with course_determine_context().
   */
  public static function context() {

  }

  /**
   * @deprecated
   */
  public function setUser($account) {
    $this->user = $account;
  }

  /**
   * @deprecated
   */
  public function getUser() {
    return $this->user;
  }

  function buildContent($view_mode = 'full', $langcode = NULL) {
    $content = parent::buildContent($view_mode, $langcode);

    $step = array();
    $step['id'] = 'course-object-' . $this->getId();
    $step['image'] = '';
    $step['status'] = '';

    if ($this->access('see')) {
      if ($this->access('take')) {
        // User can take this course object.
        $step['link'] = $this->getUrl();
        $step['class'][] = 'accessible';
        $step['status'] = t('Not started');

        // Step is complete.
        if ($this->getFulfillment()->isComplete()) {
          $step['class'][] = 'completed';
          $step['status'] = t('Complete');
          $step['image'] = 'misc/watchdog-ok.png';
        }
        elseif ($this->getFulfillment()->getId()) {
          $step['status'] = t('In progress');
          $step['class'][] = 'in-progress';
          $step['image'] = '';
        }
        if ($this->getCourse()->getActive() === $this) {
          $step['class'][] = 'active';
        }
      }
      else {
        // User cannot access this step yet.
        $step['class'] = array('not-accessible');
        $step['status'] = implode('<br/>', $this->getAccessMessages());
      }

      if ($this->isRequired()) {
        $step['class'][] = 'required';
      }

      $step['class'][] = drupal_html_class($this->getComponent() . '_' . $this->getModule());

      $img = !empty($step['image']) ? theme('image', array('path' => $step['image'])) : '';


      $content['course_outline_image'] = array(
        '#markup' => $img,
      );
      $content['course_outline_link'] = array(
        '#markup' => $this->access('take') ? l($this->getTitle(), $this->getUrl()) : $this->getTitle(),
      );
      $content['course_outline_status'] = array(
        '#markup' => $step['status'],
        '#prefix' => '<div>',
        '#suffix' => '</div>',
      );
    }

    return $content;
  }

  /**
   * Generate URI from course object.
   */
  public function uri() {
    return array(
      'path' => 'node/' . $this->nid . '/course-object/' . $this->identifier(),
    );
  }

}
