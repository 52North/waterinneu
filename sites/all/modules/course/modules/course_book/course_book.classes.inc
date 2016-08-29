<?php

class CourseObjectBook extends CourseObjectNode {

  /**
   * Course node context handler callback.
   */
  public static function getNodeInstances($node) {
    if (!empty($node->book['bid'])) {
      return array($node->book['bid']);
    }
  }

  function getNodeTypes() {
    if (user_access('administer book outlines')) {
      return array_keys(node_type_get_names());
    }
    else {
      return variable_get('book_allowed_types', array('book'));
    }
  }

  /**
   * Make the book.
   */
  public function create($node = NULL) {
    $node = new stdClass;
    $node->type = $this->getOption('node_type');
    $node->book['bid'] = 'new';
    $node->book['mlid'] = NULL;
    parent::create($node);
  }

  function optionsDefinition() {
    $defaults = parent::optionsDefinition();
    $defaults['node_type'] = variable_get('course_book_default_node_type', 'book');
    $defaults['book_tracking'] = 'all';
    $defaults['outline_list_item_type'] = 'active_tree';
    return $defaults;
  }

  function optionsForm(&$form, &$form_state) {
    $config = $this->getOptions();
    parent::optionsForm($form, $form_state);
    $form['book_tracking'] = array(
      '#title' => t('Completion criteria'),
      '#type' => 'select',
      '#options' => array(
        'one' => t('View any page'),
        'all' => t('View all pages'),
      ),
      '#default_value' => $config['book_tracking'],
    );

    // Add a book-specific configuration for course outline list item type, only
    // if the standard course list outline handler is selected.
    if ($this->getCourse()->getNode()->course['outline'] == 'course') {
      $form['outline_list_item_type'] = array(
        '#title' => t('Course outline list item type'),
        '#type' => 'select',
        '#options' => array(
          'all_pages' => t('All book pages as an expanded, nested list'),
          'active_tree' => t('Only the active book menu tree items, with a count indicator'),
          'count' => t('A count indicator only'),
        ),
        '#default_value' => $config['outline_list_item_type'],
      );
    }

    if (!module_exists('node_access_book')) {
      $form['node']['private']['#description'] .= '<br/><span style="color: #d00">If using "private", you should install <a href="http://drupal.org/project/node_access_book">Node access book</a> to ensure that book sub-pages obey the content access on the book parent.';
    }
  }

  /**
   * Grade (track) the book based on the fulfillment data.
   */
  function grade() {
    if (course_book_count($this->node->nid) == 0) {
      // Book has no pages. Complete object.
      $this->getFulfillment()->setComplete(1)->save();
      return;
    }

    if ($this->getOption('book_tracking') == 'all') {
      // Possibly a bug here. book_toc doesn't return inaccessible book pages.
      $mlids = array_keys(book_toc($this->node->nid, 99));
      $fulfillment = $this->getFulfillment()->getOption('book_fulfillment');
      $viewed = $fulfillment ? array_keys(array_filter($fulfillment)) : array();
      if (!array_diff($mlids, $viewed)) {
        $this->getFulfillment()->setComplete(1)->save();
      }
    }
    elseif ($this->getOption('book_tracking') == 'one') {
      $this->getFulfillment()->setComplete(1)->save();
    }
  }

  /**
   * Overrides navigation links.
   */
  public function overrideNavigation() {
    $links = parent::overrideNavigation();

    $node = node_load(arg(1));
    if (isset($node->book)) {
      $book_link = $node->book;
      if ($prev = book_prev($book_link)) {
        $links['prev'] = l('Previous', $prev['href']);
      }
      if ($next = book_next($book_link)) {
        $links['next'] = l('Next', $next['href']);
      }
    }

    return $links;
  }

  /**
   * Overrides a course outline list item.
   */
  public function overrideOutlineListItem(&$item) {
    // Check that course list outline handler is selected.
    if ($this->getCourse()->getNode()->course['outline'] == 'course') {
      $type = $this->getOption('outline_list_item_type');
      // Override the list item by reference.
      course_book_override_outline_list_item($item, $this, $type);
    }
  }

  public function getCloneAbility() {
    return t('%title will only clone the first page.', array('%title' => $this->getTitle()));
  }

  /**
   * Override of CourseObjectNode::save()
   *
   * We have to remove the stock "view" content access permissions on Books, if
   * node_access_book is enabled. Otherwise, users outside of the course can
   * still access child book pages of a private book parent.
   */
  public function save() {
    // Take care of the parent book page.
    parent::save();

    if ($this->hasNodePrivacySupport() && $this->getOption('private') && module_exists('node_access_book')) {
      // Remove "view" permissions on all the child pages.
      $flat = array();
      $tree = menu_tree_all_data($this->node->book['menu_name']);
      _book_flatten_menu($tree, $flat);
      foreach ($flat as $item) {
        $nid = str_replace('node/', '', $item['link_path']);
        $node = node_load($nid);

        $settings = content_access_get_per_node_settings($node);
        $settings['view'] = array();
        content_access_save_per_node_settings($node, $settings);

        // Resave node to update access.
        node_access_acquire_grants($node);
      }
    }
  }

  /**
   * Override of CourseObjectNode::freeze().
   *
   * Do not freeze the parent book ID.
   *
   * course_book_node_insert() stumbles if this is set and we are cloning a
   * book.
   */
  public function freeze() {
    $ice = parent::freeze();
    unset($ice->node->book['bid']);
    return $ice;
  }

}
