<?php

/**
 * Master class for anything Course related.
 *
 * Anything implementing CourseHandler is expected to have a table and a
 * serialized field for storing options defined by other modules.
 */
class CourseHandler extends Entity {

  function __construct($values, $entityType) {
    parent::__construct($values, $entityType);
    foreach ($this->optionsDefinition() as $key => $value) {
      if (!isset($this->$key)) {
        $this->$key = $value;
      }
    }
  }

  // Handlers must have an ID.
  function getId() {
    return $this->identifier();
  }

  /**
   * Get the summary of an object's options.
   *
   * @return array
   *   An associative array of summary keys and values.
   */
  public function getOptionsSummary() {
    $summary = array();

    foreach ($this->getWarnings() as $warning) {
      $warning = '<span class="error">' . $warning . '</span>';
      $summary['warnings'] = filter_xss_admin($warning);
    }

    return $summary;
  }

  /**
   * Get an object's configuration.
   *
   * This can be overridden. For example, values stored in courseobject sessions
   * need to have priority over those in the database.
   *
   * @return array
   */
  public function getOptions() {
    return get_object_vars($this);
  }

  /**
   * Get an handler option's value.
   *
   * @return mixed
   */
  public function getOption($key) {
    $options = $this->getOptions();
    if (isset($options[$key])) {
      return $options[$key];
    }
    else {
      return NULL;
    }
  }

  /**
   * Set an option for this handler.
   *
   * @param string $option
   *   An option key.
   * @param mixed $value
   *   The option value.
   *
   * @return CourseHandler
   */
  public function setOption($option, $value) {
    if (!preg_match('/\*/', $option) && is_scalar($option)) {
      $this->$option = $value;
    }
    return $this;
  }

  /**
   * Set this entire handler's options.
   *
   * Deserialize the serialized column if necessary.
   *
   * @param array $options
   *   An array of options.
   *
   * @return CourseHandler
   */
  public final function setOptions($options) {
    foreach ($options as $key => $option) {
      $this->setOption($key, $option);
    }
  }

  /**
   * Merge an array of options onto the existing options.
   *
   * @param array $options
   *
   * @return CourseHandler
   *   Some type of CourseHandler (probably CourseObject or
   *   CourseObjectFulfillment)
   */
  public final function addOptions(array $options) {
    $this->setOptions($this->optionsMerge($this->getOptions(), $options));
    return $this;
  }

  /**
   * Merge arrays with replace, not append.
   *
   * @see http://www.php.net/manual/en/function.array-merge-recursive.php#102379
   */
  private function optionsMerge($Arr1, $Arr2) {
    foreach ($Arr2 as $key => $Value) {
      if (array_key_exists($key, $Arr1) && is_array($Value)) {
        $Arr1[$key] = $this->optionsMerge($Arr1[$key], $Arr2[$key]);
      }
      else {
        $Arr1[$key] = $Value;
      }
    }

    return $Arr1;
  }

  /**
   * Handlers can declare their defaults if they have a configuration form.
   */
  protected function optionsDefinition() {
    return array();
  }

  /**
   * Handlers can declare a form.
   */
  public function optionsForm(&$form, &$form_state) {

  }

  /**
   * Validate?
   */
  public function optionsValidate(&$form, &$form_state) {

  }

  /**
   * Save data somewhere.
   *
   * This can be overridden. For example, values stored in CourseObject sessions
   * need to have priority over those in the database.
   */
  public function optionsSubmit(&$form, &$form_state) {

  }

  /**
   * Return an array of database fields. This determines what fields should be
   * serialized instead of stored.
   */
  protected function getDatabaseFields() {
    $schema = drupal_get_schema($this->entityInfo['base table']);
    $fields = field_info_instances($this->entityType());
    $fields = $fields[$this->entityType()];
    return array_keys($fields + $schema['fields']);
  }

  /**
   * Return a list of warning strings about this handler.
   *
   * For example, if a user adds a quiz to a course with no questions, trigger a
   * message.
   *
   * @see CourseObjectQuiz
   * @see CourseObjectWebform
   */
  public function getWarnings() {
    return array();
  }

  /**
   * Set an access message to be displayed along with the course object when it
   * is in the outline. For example, "This activity will open on XYZ" or "Please
   * complete Step 1 to take this activity."
   *
   * @param string $key
   *   Message key.
   * @param string $message
   *   Message text.
   */
  public function setAccessMessage($key = NULL, $message = NULL) {
    if ($key == NULL) {
      return $this->accessMessages;
    }
    if (empty($message)) {
      unset($this->accessMessages[$key]);
    }
    else {
      $this->accessMessages[$key] = $message;
    }
  }

  /**
   * Get an array of access messages.
   *
   * @return array
   */
  public function getAccessMessages() {
    return $this->setAccessMessage();
  }

  public function save() {
    $info = $this->entityInfo();
    $schema = drupal_get_schema($info['base table']);
    foreach ($schema['fields'] as $field_name => $info) {
      if (!empty($info['serialize'])) {
        $serialized_field = $field_name;
      }
      $real_fields[$field_name] = $field_name;
    }
    $options = $this->getOptions();
    $strict_options = array_intersect_key($options, $this->optionsDefinition());
    $this->$serialized_field = array_diff_key($strict_options, $real_fields);

    parent::save();
  }

}
