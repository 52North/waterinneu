<?php

class CourseObjectUbercart extends CourseObjectNode {

  /**
   * Specify that this object needs a navigation listener.
   */
  public function hasPolling() {
    return TRUE;
  }

  function getTakeType() {
    return 'content';
  }

  /**
   * Display the add to cart button, or a message that it was already purchased.
   *
   * Implementing classes should override me if a custom display is desired.
   */
  function take() {
    if (!($this->node->sell_price > 0) && variable_get('course_access_bypass_checkout', 1)) {
      $this->getFulfillment()->setComplete(1)->save();
    }

    if ($this->getFulfillment()->isComplete()) {
      return "You've already purchased this activity.";
    }
    else {
      $node_view = node_view($this->node);
      $atc = t('You must purchase this course before proceeding.') . drupal_render($node_view['display_price']) . drupal_render($node_view['add_to_cart']);
      if (!$atc) {
        // The add to cart form was hidden?
        return "Something isn't right...";
      }
      else {
        return $atc;
      }
    }
  }

  public function optionsForm(&$form, &$form_state) {
    parent::optionsForm($form, $form_state);

    $form['node']['instance']['#title'] = t('Product to check');
    $form['node']['instance']['#description'] .= '</br>' . t('Use an existing ubercart-enabled product for checking payment. Defaults to this course.');
  }

  /**
   * Set a specialized instance ID.
   *
   * Either the course node ID, or another ubercart node ID.
   */
  public function optionsSubmit(&$form, &$form_state) {
    if (isset($form_state['values']['instance'])) {
      if (!$form_state['values']['instance']) {
        $form_state['values']['instance'] = $this->getCourseNid();
      }
    }
    parent::optionsSubmit($form, $form_state);
  }

  /**
   * Don't create new products.
   */
  public function create($node = NULL) {
    if (!$this->getInstanceId()) {
      $this->setOption('instance', $this->getCourseNid());
    }
  }

  function getNodeTypes() {
    return uc_product_types();
  }

  function getCloneAbility() {
    return t('Payment objects will be created as a reference to the new course');
  }

  public function freeze() {
    return TRUE;
  }

  function thaw($ice) {
    // Not creating a new product. Using this course.
    return $this->getCourseNid();
  }

}
