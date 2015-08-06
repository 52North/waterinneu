<?php

/**
 * This class is a wrapper around all the hooks used for getting pluigns.
 *
 * Currently supported plugin-types are:
 * - form types: hook_form_builder_form_types().
 * - element types: hook_form_builder_types().
 * - properties: hook_form_builder_properties().
 */
class FormBuilderLoader {

  protected static $instance = NULL;
  protected $formTypeInfo;
  protected $paletteGroupInfo = array();
  protected $elementTypeInfo = array();
  protected $propertyInfo = array();
  protected $formCache = array();

  /**
   * Get a singleton-like class instance.
   */
  public static function instance() {
    if (!static::$instance) {
      static::$instance = new static();
    }
    return static::$instance;
  }

  public function __construct() {
    module_load_include('api.inc', 'form_builder', 'includes/form_builder');
    $this->loadFormTypeInfo();
  }

  protected function loadFormTypeInfo() {
    $defaults = array(
      'class' => 'FormBuilderFormBase',
      'property class' => 'FormBuilderPropertyBase',
      'element class' => 'FormBuilderElementBase',
    );

    $form_types = module_invoke_all('form_builder_form_types');
    foreach ($form_types as $form_type => &$info) {
      $info += $defaults;
    }
    drupal_alter('form_builder_form_types', $form_types);

    $this->formTypeInfo = $form_types;
  }

  public function getElementTypeInfo($form_type, $form_id) {
    if (!isset($this->elementTypeInfo[$form_type][$form_id])) {
      $element_types = module_invoke_all('form_builder_element_types', $form_type, $form_id);
      $groups = $this->getPaletteGroupInfo($form_type);
      // Add default values for undefined properties.
      foreach ($element_types as $key => &$type) {
        $type += array(
          'class' => $this->formTypeInfo[$form_type]['element class'],
          'configurable' => TRUE,
          'removable' => TRUE,
          'palette_group' => 'default',
          'properties' => array(),
        );
        $type += array(
          'addable' => $type['removable'] && isset($type['default']),
        );
        $type['unique'] = !empty($type['unique']);
        $type['palette_group'] = isset($groups[$type['palette_group']]) ? $type['palette_group'] : 'default';

        // All fields must support weight.
        if (!in_array('weight', $type['properties'])) {
          $type['properties'][] = 'weight';
        }

        // Update the default elements with some defaults.
        // Note that if a field is not removable, it doesn't have a default.
        $type['default'] += array('#form_builder' => array());
        if ($type['addable']) {
          $type['default']['#form_builder'] += array('element_type' => $key);
          if ($type['unique']) {
            $type['default']['#form_builder']['element_id'] = $key;
          }
        }
      }
      // Sort fields by weight and title.
      uasort($element_types, '_form_builder_sort');
      drupal_alter('form_builder_element_types', $element_types, $form_type, $form_id);
      $this->elementTypeInfo[$form_type][$form_id] = $element_types;
    }
    return $this->elementTypeInfo[$form_type][$form_id];
  }

  public function getPaletteGroupInfo($form_type, $reset = FALSE) {
    if (!isset($this->paletteGroupInfo[$form_type]) || $reset) {
      $this->paletteGroupInfo[$form_type] = module_invoke_all('form_builder_palette_groups', $form_type);
    }
    return $this->paletteGroupInfo[$form_type];
  }

  public function getPropertyInfo($form_type, $reset = FALSE) {
    if (!isset($this->propertyInfo[$form_type]) || $reset) {
      // Don't use module_invoke_all here as it uses array_merge_recursive()
      // which creates sub-arrays for duplicate array keys.
      $properties = array();
      foreach (module_implements('form_builder_properties') as $module) {
        $new_properties = module_invoke($module, 'form_builder_properties', $form_type);
        $properties += $new_properties;
        foreach ($new_properties as $k => $v) {
          $properties[$k] = array_merge($properties[$k], $new_properties[$k]);
        }
      }
      drupal_alter('form_builder_properties', $properties, $form_type);
      $defaults['class'] = $this->formTypeInfo[$form_type]['property class'];
      foreach ($properties as $property => &$params) {
        $params += $defaults;
      }
      $this->propertyInfo[$form_type] = $properties;
    }

    return $this->propertyInfo[$form_type];
  }

  /**
   * Get a form object.
   */
  public function getForm($form_type, $form_id, $sid, $form = array()) {
    if (!isset($this->formTypeInfo[$form_type])) {
      return FALSE;
    }
    $info = $this->formTypeInfo[$form_type];
    $class = $info['class'];
    return new $class($this, $form_type, $form_id, $sid, $info, $form);
  }

  /**
   * Load a form from storage.
   */
  public function fromStorage($form_type, $form_id, $sid = NULL) {
    if (!isset($this->formTypeInfo[$form_type])) {
      return FALSE;
    }
    $info = $this->formTypeInfo[$form_type];
    $class = $info['class'];
    return $class::loadFromStorage($this, $form_type, $form_id, $sid, $info);
  }

  /**
   * Load a form from the form_builder_cache.
   */
  public function fromCache($form_type, $form_id, $sid = NULL, $reset = FALSE) {
    if ($reset) {
      $this->formCache = array();
    }

    if ($form_type && $form_id) {
      if (empty($this->formCache[$form_type][$form_id])) {
        $this->formCache[$form_type][$form_id] = FALSE;

        if (isset($this->formTypeInfo[$form_type])) {
          $info = $this->formTypeInfo[$form_type];
          $class = $info['class'];
          $sid = $sid ? $sid : session_id();
          if ($form = $class::load($this, $form_type, $form_id, $sid, $info)) {
            $this->formCache[$form_type][$form_id] = $form;
          }
        }
      }
      return $this->formCache[$form_type][$form_id];
    }
    return NULL;
  }

  /**
   * Get element instance.
   */
  public function getElement($form_type, $form_id, $element_type, $form, &$element) {
    $types = $this->getElementTypeInfo($form_type, $form_id);
    if (!isset($types[$element_type])) {
      throw new UnexpectedValueException("Unknown element_type: $form_type - $element_type");
    }
    $info = $types[$element_type];
    $class = $info['class'];
    return new $class($this, $info, $form, $element);
  }
}


interface FormBuilderFormInterface {

  /**
   * Load form data from the storage backend (ie. webform components).
   *
   * @param object $loader
   *   A FormBuilderLoader instance.
   * @param string $form_type
   *   Name of the form_type.
   * @param mixed $form_id
   *   Primary identifier for the form. (ie. node id)
   * @param string $sid
   *   User session ID. If NULL session_id() is assumed.
   * @param array $params
   *   Additional parameters passed to hook_form_builder_form_types().
   */
  public static function loadFromStorage($loader, $form_type, $form_id, $sid, $params);

  /**
   * Save form data to the storage backend.
   */
  public function saveToStorage();

  /**
   * Load a form configuration cache.
   *
   * @param object $loader
   *   A FormBuilderLoader instance.
   * @param string $form_type
   *   The type of form being edited.
   * @param mixed $form_id
   *   The unique identifier for the form (within the form_type).
   * @param string $sid
   *   User session ID. If NULL session_id() is assumed.
   * @param array $params
   *   Additional parameters passed to hook_form_builder_properties().
   * @param array $form
   *   A Form-API array.
   *
   * @return
   *   A FAPI array if a cache entry was found. Boolean FALSE if an entry does not
   *   yet exist. Note that an empty FAPI array may exist, so be sure to use
   *   strict comparison (===) when checking return values.
   */
  public static function load($loader, $form_type, $form_id, $sid, $params);


  /**
   * Construct a new instance of this form type class..
   *
   * @param object $loader
   *   A FormBuilderLoader instance.
   * @param string $form_type
   *   Name of the form_type.
   * @param mixed $form_id
   *   The form's primary key.
   * @param string $sid
   *   User session ID.
   * @param array $params
   *   Additional parameters passed to hook_form_builder_properties().
   */
  public function __construct($loader, $form_type, $form_id, $sid, $params, $form);

  /**
   * Save a form builder cache based on the form structure.
   */
  public function save();

  /**
   * Delete this cache entry from the form_builder_cache table.
   */
  public function delete();

 /**
   * Get a specific element from the form.
   *
   * @param string $elment_id
   *   Unique ID of the element.
   *
   * @return FormBuilderElementInterface
   *   Object representing the form element.
   */
  public function getElement($element_id);

  /**
   * Get the internal element array for an element.
   *
   * @deprecated This is only here for backwards compatibility. It will be
   *   removed in 2.0.
   *
   * @param string $element_id
   *   Unique ID of the element.
   *
   * @return array
   *   The array representing the internal state of the element.
   */
  public function getElementArray($element_id);

  /**
   * Get an array of element arrays.
   *
   * @deprecated This is only here for backwards compatibility. It will be
   *   removed in 2.0.
   *
   * @param array $element_ids
   *   Array of unique element IDs.
   *
   * @return array
   *   The array representing the internal state of the element.
   */
  public function getElementArrays($element_ids);

  /**
   * Get the complete form array (FORM_BUILDER_ROOT).
   */
  public function getFormArray();

  /**
   * Set an element array.
   *
   * @deprecated This is only here for backwards compatibility. It will be
   *   removed in 2.0.
   */
  public function setElementArray($element_a, $parent_id = FORM_BUILDER_ROOT, $alter = FALSE);

  /**
   * Remove an element from the form.
   *
   * @param string $element_id
   *   Unique ID of the element.
   */
  public function unsetElement($element_id);

  /**
   * Get the list of currently used element ids.
   *
   * @return array
   *   List of element ids.
   */
  public function getElementIds();

  /**
   * Get the list of currently used element types.
   *
   * @return array
   *   List of element types.
   */
  public function getElementTypes();

}

class FormBuilderFormBase implements FormBuilderFormInterface, Serializable {
  const CACHE_NAME = 'form_builder_cache';
  protected $loader;
  protected $formType;
  protected $params;
  protected $properties;
  protected $form;
  protected $formId;
  protected $sid;
  protected $elements = array();

  /**
   * Shortcut for creating a form object from a form array.
   */
  public static function fromArray($form) {
    $fb = $form['#form_builder'] + array('sid' => NULL);
    return FormBuilderLoader::instance()
      ->getForm($fb['form_type'], $fb['form_id'], $fb['sid'], $form);
  }

  /**
   * {@inheritdoc}
   */
  public static function loadFromStorage($loader, $form_type, $form_id, $sid, $params) {
    $form = module_invoke_all('form_builder_load', $form_type, $form_id);
    drupal_alter('form_builder_load', $form, $form_type, $form_id);
    return new static($loader, $form_type, $form_id, $sid, $params, $form);
  }

  /**
   * {@inheritdoc}
   */
  public function saveToStorage() {
    module_invoke_all('form_builder_save', $this->form, $this->formType, $this->formId);
    $this->delete();
  }

  /**
   * {@inheritdoc}
   */
  public static function load($loader, $form_type, $form_id, $sid, $params) {
    ctools_include('object-cache');
    $obj = "$form_type:$form_id";
    $form = ctools_object_cache_get($obj, self::CACHE_NAME, FALSE, $sid);
    if ($form && is_array($form)) {
      $form['#form_builder']['form_type'] = $form_type;
      $form['#form_builder']['form_id'] = $form_id;
      $form['#form_builder']['sid'] = $sid;
      $form = new static($loader, $form_type, $form_id, $sid, $params, $form);
    }
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function __construct($loader, $form_type, $form_id, $sid, $params, $form) {
    $this->loader = $loader;
    $this->formType = $form_type;
    $this->formId = $form_id;
    $this->sid = $sid ? $sid : session_id();
    $this->params = $params;
    $this->properties = NULL;
    $form += array('#form_builder' => array());
    $form['#form_builder'] += array(
      'form_type' => $this->formType,
      'form_id' => $this->formId,
      'sid' => $this->sid,
    );
    $this->addDefaults($form);
    $this->form = $this->createElements($form);
    $this->indexElements($this->form);
    $this->elements[FORM_BUILDER_ROOT] = $this->form;
  }

  /**
   * Serialize the form.
   *
   * NOTE: This should only be used for short-term storage.
   */
  public function serialize() {
    return serialize(array(
      'formType' => $this->formType,
      'formId' => $this->formId,
      'sid' => $this->sid,
      'params' => $this->params,
      'form' => $this->form,
      // Don't save element-arrays and the loader.
    ));
  }

  /**
   * Unserialize a stored version of this form.
   */
  public function unserialize($data) {
    $data = unserialize($data);
    $this->loader = FormBuilderLoader::instance();
    $this->formType = $data['formType'];
    $this->formId = $data['formId'];
    $this->sid = $data['sid'];
    $this->params = $data['params'];
    $this->form = $data['form'];
    $this->properties = array();
    if (!($this->form instanceof FormBuilderFormApiNode)) {
      $this->addDefaults($this->form);
      $this->createElements($this->form);
    }
    $this->indexElements($this->form);
    $this->elements[FORM_BUILDER_ROOT] = $this->form;
  }

  /**
   * {@inheritdoc}
   */
  public function save() {
    ctools_include('object-cache');
    $obj = "{$this->formType}:{$this->formId}";
    ctools_object_cache_set($obj, self::CACHE_NAME, $this, $this->sid);
  }

  /**
   * {@inheritdoc}
   */
  public function delete() {
    ctools_include('object-cache');
    $obj = "{$this->formType}:{$this->formId}";
    ctools_object_cache_clear($obj, self::CACHE_NAME, FALSE, $this->sid);
  }

  /**
   * Purge old cache entries.
   *
   * @param int $max_age
   *   All form_builder_cache entries older than $max_age seconds are purged.
   */
  public static function purge($max_age = NULL) {
    $expire = isset($max_age) ? $max_age : ini_get('session.cache_expire');
    return db_delete('ctools_object_cache')
      ->condition('name', 'form_builder_cache')
      ->condition('updated', REQUEST_TIME - $max_age, '<')
      ->execute();
    drupal_static_reset('ctools_object_cache_get');
  }

  /**
   * Recurse through the form array and add defaults to their element arrays.
   *
   * This function ensures the following properties:
   * $element['#pre_render'] includes 'form_builder_pre_render'
   * In $element['#form_builder']:
   *   - 'form_type'
   *   - 'form_id'
   *   - 'parent_id'
   */
  protected function addDefaults(&$element, $parent_id = FORM_BUILDER_ROOT, $key = NULL, &$element_info = NULL) {
    if (!$element_info) {
      $element_info = FormBuilderLoader::instance()->getElementTypeInfo($this->formType, $this->formId);
    }
    if (isset($element['#form_builder']['element_id'])) {
      $element_id = $element['#form_builder']['element_id'];
      if (isset($element['#type']) && (!isset($element['#pre_render']) || !in_array('form_builder_pre_render', $element['#pre_render']))) {
        $element['#pre_render'] = array_merge(
          element_info_property($element['#type'], '#pre_render', array()),
          array('form_builder_pre_render')
        );
      }
      $element += array('#key' => $key);
      $element['#form_builder']['form_type'] = $this->formType;
      $element['#form_builder']['form_id'] = $this->formId;
      $element['#form_builder']['parent_id'] = $parent_id;

      // Set defaults based on the form type.
      $settings = array();
      if (isset($element_info[$element_id]) && $element_info[$element_id]['unique']) {
        $element['#form_builder']['unique'] = TRUE;
        $element['#form_builder'] += array('element_type' => $element_id);
        $settings = $element_info[$element_id];
      }
      else {
        $element['#form_builder'] += array('element_type' => $element['#type']);
        if (isset($element_info[$element['#form_builder']['element_type']])) {
          $settings = $element_info[$element['#form_builder']['element_type']];
        }
        else {
          // If the type cannot be found, prevent editing of this field.
          unset($element['#form_builder']);
          return;
        }
      }

      // Set defaults for configurable and removable.
      $settings += array('configurable' => TRUE, 'removable' => TRUE);
      $element['#form_builder'] += array(
        'configurable' => $settings['configurable'],
        'removable' => $settings['removable'],
      );
      $parent_id = $element_id;
    }
    foreach (element_children($element) as $key) {
      $this->addDefaults($element[$key], $parent_id, $key, $element_info);
    }
  }

  /**
   * Create a tree of element objects out of an array.
   */
  protected function createElements(&$element) {
    $child_keys = element_children($element);
    $element_array = $element;
    foreach ($child_keys as $key) {
      unset($element_array[$key]);
    }
    // Create the element.
    if (isset($element['#form_builder']['element_type'])) {
      $type = $element['#form_builder']['element_type'];
      $e = $this->loader->getElement($this->formType, $this->formId, $type, $this, $element_array);
    }
    else {
      $e = new FormBuilderFormApiNode($element_array);
    }
    // Add all childs.
    foreach ($child_keys as $key) {
      $child = $this->createElements($element[$key]);
      $e->insertChild($child);
      $child->setParent($e);
    }
    return $e;
  }

  /**
   * Index elements.
   */
  protected function indexElements($element) {
    if ($element instanceof FormBuilderElementInterface) {
      $this->elements[$element->getId()] = $element;
    }
    foreach ($element->getChildren() as $child) {
      $this->indexElements($child);
    }
  }

  /**
   * Remove an element and it's children from the index.
   */
  protected function unindexElements($element) {
    if ($element instanceof FormBuilderElementInterface) {
      unset($this->elements[$element->getId()]);
    }
    foreach ($element->getChildren() as $child) {
      $this->unindexElements($child);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getElement($element_id) {
    if (isset($this->elements[$element_id])) {
      return $this->elements[$element_id];
    }
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function getElementArray($element_id) {
    if ($element = $this->getElement($element_id)) {
      return $element->render();
    }
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function getElementArrays($element_ids) {
    $elements = array();
    foreach ($element_ids as $element_id) {
      if ($element = $this->getElementArray($element_id)) {
        $elements[$element_id] = $element;
      }
    }
    return $elements;
  }

  /**
   * {@inheritdoc}
   */
  public function getFormArray() {
    return $this->form->render();
  }

  /**
   * (@inheritdoc}
   */
  public function setElementArray($element, $parent_id = FORM_BUILDER_ROOT, $alter = FALSE) {
    $return = FALSE;
    $element += array('#form_builder' => array('element_id' => NULL));
    $element_id = $element['#form_builder']['element_id'];
    $element['#form_builder'] += array('parent_id' => $parent_id);
    $parent_id = $element['#form_builder']['parent_id'];

    if ($alter) {
      drupal_alter('form_builder_add_element', $element, $this->formType, $this->formId);
      // Save any element ID set by the hook_form_builder_add_element_alter().
      $element_id = $element['#form_builder']['element_id'];
      $parent_id = $element['#form_builder']['parent_id'];
      // Re-run addDefaults in case something has changed
    }
    $this->addDefaults($element, $parent_id);
    $element = $this->createElements($element);

    if (!($parent = $this->getElement($parent_id))) {
      return FALSE;
    }

    $old_element = FALSE;
    if ($element_id) {
      if ($old_element = $this->getElement($element_id)) {
        // Remove element from old parent if needed.
        if ($old_parent = $old_element->getParent()) {
          if ($old_parent != $parent) {
            $old_parent->removeChild($old_element);
          }
        }
        $this->unindexElements($old_element);
      }
    }

    $old_key = $old_element ? $old_element->getKey() : FALSE;
    $parent->insertChild($element, $old_key);
    $element->setParent($parent);
    $this->indexElements($element);

    return $element;
  }

  /**
   * {@inheritdoc}
   */
  public function unsetElement($element_id) {
    $element = $this->elements[$element_id];
    if ($parent = $element->getParent()) {
      $parent->removeChild($element);
    }
    $this->unindexElements($element);
  }

  /**
   * {@inheritdoc}
   */
  public function getElementIds() {
    $ids = array();
    foreach (array_keys($this->elements) as $id) {
      if ($id !== FORM_BUILDER_ROOT) {
        $ids[] = $id;
      }
    }
    return $ids;
  }

  /**
   * {@inheritdoc}
   */
  public function getElementTypes() {
    $types = array();
    foreach ($this->elements as $element) {
      $a = $element->render();
      if (isset($a['#form_builder']['element_type'])) {
        $types[$a['#form_builder']['element_type']] = TRUE;
      }
    }
    return array_keys($types);
  }

  /**
   * {@inheritdoc}
   */
  public function getProperties($reset = FALSE) {
    if (!$this->properties || $reset) {
      $properties = FormBuilderLoader::instance()->getPropertyInfo($this->formType, $reset);
      foreach ($properties as $property => $params) {
        $class = $params['class'];
        $this->properties[$property] = new $class($property, $params, $this->formType);
      }
    }

    return $this->properties;
  }

}

interface FormBuilderFormNodeInterface {
  public function getKey();
  public function setParent($parent);
  public function getParent();
  public function insertChild($node);
  public function removeChild($key_or_node);
  public function getChildren();


  public function render();
}

class FormBuilderFormNode implements FormBuilderFormNodeInterface {
  protected $parent = NULL;
  protected $children = array();
  protected $element;

  /**
   * {@inheritdoc}
   */
  public function getKey() {
    return $this->element['#key'];
  }

  /**
   * {@inheritdoc}
   */
  public function setParent($node) {
    $this->parent = $node;
  }

  /**
   * {@inheritdoc}
   */
  public function getParent() {
    return $this->parent;
  }

  /**
   * {@inheritdoc}
   */
  public function insertChild($node, $old_key = FALSE) {
    $new_key = $node->getKey();
    if ($old_key && $old_key != $new_key) {
      $children = array();
      foreach($this->children as $key => $child) {
        if ($key == $old_key) {
          $children[$new_key] = $node;
        }
        else {
          $children[$key] = $child;
        }
      }
      $this->children = $children;
    }
    else {
      $this->children[$node->getKey()] = $node;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function removeChild($node_or_key) {
    if ($node_or_key instanceof FormBuilderFormNodeInterface) {
      $node_or_key = $node_or_key->getKey();
    }
    unset($this->children[$node_or_key]);
  }

  /**
   * {@inheritdoc}
   */
  public function getChildren() {
    return $this->children;
  }

  /**
   * (Re-)Render an element.
   *
   * @return array
   *   New FAPI array reflecting all the changes made prior to callig this
   *   method.
   */
  public function render() {
    $element = $this->element;
    foreach ($this->children as $key => $child) {
      $element[$key] = $child->render();
    }
    return $element;
  }

  public function formParents() {
    if (!$this->parent) {
      return array();
    }
    $parents = $this->parent->formParents();
    $parents[] = $this->getKey();
    return $parents;
  }

}

class FormBuilderFormApiNode extends FormBuilderFormNode {
  public function __construct(&$element) {
    $this->element = $element;
  }
}

interface FormBuilderElementInterface {
  public function __construct($loader, $params, $form, &$element);

  public function getId();

  /**
   * Get a list of properties available for this element.
   *
   * @return
   *   An associative array of properties keyed by the property name.
   *   Property classes must implementing FormBuilderPropertyInterface.
   */
  public function getProperties();

  /**
   * Get a list of properties that are supported in any way by this element.
   *
   * This returns a list of all supported properties within an element, even
   * if some of those properties do not have an interface for editing or are
   * only used internally by the module providing the form type this element
   * is being saved in.
   *
   * @return
   *   A non-indexed list of properties that may be saved for this element.
   **/
  public function getSaveableProperties();

  /**
   * Get the configuration form for this element.
   */
  public function configurationForm($form, &$form_state);

  /**
   * Submit handler for the configuration form.
   */
  public function configurationSubmit(&$form, &$form_state);
}


class FormBuilderElementBase extends FormBuilderFormNode implements FormBuilderElementInterface {
  protected $form;
  protected $params;
  protected $loader;
  public function __construct($loader, $params, $form, &$element) {
    $this->form = $form;
    $this->params = $params;
    // @TODO Don't assume that $element has defaults set.
    $this->element = $element;
    $this->loader = $loader;
  }

  /**
   * {@inheritdoc}
   */
  public function getId() {
    return $this->element['#form_builder']['element_id'];
  }

  /**
   * {@inheritdoc}
   */
  public function getProperties() {
    $return = array();
    $properties = $this->form->getProperties();
    // Order of the properties is important because of a form-API bug.
    // See: https://www.drupal.org/node/990218.
    foreach ($this->params['properties'] as $name) {
      if (isset($properties[$name])) {
        $return[$name] = $properties[$name];
      }
    }
    return $return;
  }

  /**
   * Set the value of a property.
   *
   * This method must update the $element for rendering as well as for
   * later storage.
   *
   * @param string $property
   *   Key of the property.
   * @param mixed $value
   *   New value for the property.
   */
  protected function setProperty($property, $value) {
    // Remove empty properties entirely.
    if ($value === '' || is_null($value)) {
      unset($this->element['#'. $property]);
    }
    else {
      $this->element['#'. $property] = $value;
    }
  }

  public function getSaveableProperties() {
    return $this->params['properties'];
  }

  /**
   * {@inheritdoc}
   */
  public function configurationForm($form, &$form_state) {
    $form['#_edit_element'] = $this->element;
    foreach ($this->getProperties() as $property) {
      $form = array_merge($form, $property->form($form_state, $this->element));
    }
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function configurationSubmit(&$form, &$form_state) {
    // Allow each property to do any necessary submission handling.
    foreach ($this->getProperties() as $property) {
      $property->submit($form, $form_state);
    }

    // Update the field according to the settings in $form_state['values'].
    $saveable = $this->getSaveableProperties();
    foreach ($form_state['values'] as $property => $value) {
      if (in_array($property, $saveable)) {
        $this->setProperty($property, $value);
      }
    }
  }
}


interface FormBuilderPropertyInterface {

  /**
   * Construct a new instance of this property class.
   *
   * @param string $property
   *   Name of the property to be manipulated by this object.
   * @param array $params
   *   Additional parameters passed to hook_form_builder_properties().
   */
  public function __construct($property, $params, $form_type_name);

  /**
   * Generate form-API elements for editing this property.
   *
   * @param array $form_state
   *   Form API form_state of the field configure form.
   * @param array $element
   *   Form-API array representing the currently stored value of all properties
   *   on this form $element. Use this to get the "current" values.
   *
   * @return array
   *   Form-API array that will be merged into the field configure form.
   */
  public function form(&$form_state, $element);

  /**
   * Submit handler for the editing form().
   *
   * This function is responsible to store the new value into the $form_state.
   * The value must be located at $form_state['values'][$property].
   *
   * @param array $form_state
   *   Form API form_state of the field configure form.
   */
  public function submit($form, &$form_state);

}


class FormBuilderPropertyBase implements FormBuilderPropertyInterface {

  protected $property;
  protected $params;
  protected $formTypeName;

  /**
   * {@inheritdoc}
   */
  public function __construct($property, $params, $form_type_name) {
    $this->property = $property;
    $this->params = $params;
    $this->formTypeName = $form_type_name;
  }

  /**
   * {@inheritdoc}
   */
  public function form(&$form_state, $element) {
    if (isset($this->params['form']) && function_exists($this->params['form'])) {
      $function = $this->params['form'];
      $p = $this->property;
      // Set a default value on the property to avoid notices.
      $element['#' . $p] = isset($element['#' . $p]) ? $element['#' . $p] : NULL;
      return $function($form_state, $this->formTypeName, $element, $p);
    }
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function submit($form, &$form_state) {
    if (isset($this->params['submit'])) {
      foreach ($this->params['submit'] as $function) {
        if (function_exists($function)) {
          $function($form, $form_state);
        }
      }
    }
  }

}
