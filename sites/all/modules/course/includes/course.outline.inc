<?php

/**
 * @file course_outline.inc
 *
 * Functions to show and edit graphical course outline.
 */

/**
 * Form constructor for course outline form.
 *
 * @see course_menu()
 * @see _course_outline_object_form()
 * @see theme_course_outline_overview_form()
 */
function course_outline_overview_form($form, &$form_state) {
  $form = array();

  // Determine the default value of the 'usage' select. When nothing is stored
  // in $form_state['storage'] yet, it's the form hasn't been submitted yet,
  // thus it's the first time the form is being displayed.
  // Load the modal library and add the modal javascript.
  ctools_include('ajax');
  ctools_include('modal');
  ctools_include('object-cache');
  ctools_modal_add_js();

  // Wrapper for objects and more button.
  $form['#tree'] = TRUE;
  $form['#prefix'] = '<div class="clear-block" id="course-outline-wrapper">';
  $form['#suffix'] = '</div>';

  // Shortcut.
  $cform = &$form['course_outline'];

  if (isset($form_state['values']['nid'])) {
    $node = node_load($form_state['values']['nid']);
  }
  else {
    $node = node_load(arg(1));
  }

  $course = course_get_course($node);

  // Check if "Add object" was clicked.
  if (isset($form_state['values']['op']) && $form_state['values']['op'] == t('Add object') && !empty($form_state['values']['more']['object_type'])) {
    // Ensure that we cached the course.
    course_editing_start($course);

    // Create a new course object in the session, and let the rest of the form
    // builder handle it.
    $obj_uniqid = uniqid('course_object_');
    $_SESSION['course'][$node->nid]['editing'][$obj_uniqid] = array();

    // Populate temporary course object, save it in the session.
    $new = array();
    $new['weight'] = 0;

    // Get highest weight and add to it.
    if (isset($form_state['values']['course_outline']['objects'])) {
      foreach ($form_state['values']['course_outline']['objects'] as $key => $object) {
        if ($object['weight'] >= $new['weight']) {
          $new['weight'] = $object['weight'] + 1;
        }
      }
    }

    $new['nid'] = $node->nid;
    $new['coid'] = $obj_uniqid;
    list($new['module'], $new['object_type']) = explode('-', $form_state['values']['more']['object_type']);
    $_SESSION['course'][$node->nid]['editing'][$obj_uniqid] = $new;
  }

  $form['nid']['#type'] = 'hidden';
  $form['nid']['#value'] = $node->nid;

  // Grab initial list of objects from DB or session.
  if (!empty($_SESSION['course'][$node->nid]['editing'])) {
    $objects = $_SESSION['course'][$node->nid]['editing'];
  }
  else if ($objects = $course->getObjects()) {
    // Great.
  }
  else {
    $objects = array();
  }

  // Sort list of objects we pulled from session or DB by weight for proper
  // display.
  uasort($objects, '_course_outline_overview_form_cmp_function');

  $cform['#title'] = t('Course objects');
  $form['#theme'] = 'course_outline_overview_form';

  if (!empty($_SESSION['course'][$node->nid]['editing'])) {
    drupal_set_message('Changes to this course have not yet been saved.', 'warning', FALSE);
  }

  $handlers = course_get_handlers('object');

  // Wrapper for just the objects.
  $cform['objects']['#tree'] = TRUE;
  $object_counts = array();
  if (count($objects)) {
    foreach (array_keys($objects) as $uniqid) {
      if ($courseObject = course_get_course_object_by_id($uniqid)) {
        $rform = _course_outline_object_form($courseObject);

        // Keep track of how many of each course object we have.
        // @kludge probably some simpler way to do this effectively
        if (!isset($object_counts[$courseObject->getModule()][$courseObject->getComponent()])) {
          $object_counts[$courseObject->getModule()][$courseObject->getComponent()] = 1;
        }
        else {
          $object_counts[$courseObject->getModule()][$courseObject->getComponent()] ++;
        }

        // Don't allow user to change type of object.
        $rform['object_type'] = array(
          '#type' => 'hidden',
          '#value' => $courseObject->getOption('object_type'),
        );
        if (empty($handlers[$courseObject->getOption('module')][$courseObject->getOption('object_type')])) {
          $show_object_name = t('Missing CourseObject handler for <br/><i>@m/@t</i>', array('@m' => $courseObject->getOption('module'), '@t' => $courseObject->getOption('object_type')));
        }
        else {
          $show_object_name = $handlers[$courseObject->getOption('module')][$courseObject->getOption('object_type')]['name'] . '<br/><small><i>' . ucwords(str_replace('_', ' ', $courseObject->getOption('module'))) . '</i></small>';
        }
        $rform['object_type_show'] = array(
          '#type' => 'markup',
          '#markup' => filter_xss_admin($show_object_name),
        );
        $cform['objects'][$uniqid] = $rform;
      }
    }
  }

  // Add object button and select box for new objects.
  $object_types = array(
    '' => '- select object -',
  );
  foreach ($handlers as $module => $object_definitions) {
    if ($object_definitions) {
      foreach ($object_definitions as $key => $object_info) {
        $class = $object_info['class'];
        $max_object_count = call_user_func(array($class, 'getMaxOccurences'));
        $under_limit = !$max_object_count || !(isset($object_counts[$module][$key]) && $object_counts[$module][$key] >= $max_object_count);
        if ($under_limit && empty($object_info['legacy'])) {
          $object_types[$module . '-' . $key] = $object_info['name'];
        }
      }
    }
  }

  $form['more'] = array(
    '#type' => 'markup',
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>',
  );

  $form['more']['add_another'] = array(
    '#type' => 'button',
    '#value' => t('Add object'),
    '#ajax' => array(
      'method' => 'replace',
      'wrapper' => 'course-outline-wrapper',
      'callback' => 'course_outline_overview_form_rebuild',
    ),
    '#weight' => 20,
  );

  // Sort course object types
  asort($object_types);

  $form['more']['object_type'] = array(
    '#type' => 'select',
    '#options' => $object_types,
    '#weight' => 10,
  );

  $form['actions']['#type'] = 'actions';

  // Submit and reset buttons.
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save outline'),
    '#submit' => array('course_outline_overview_form_submit'),
  );

  if (!empty($_SESSION['course'][$node->nid]['editing'])) {
    $form['actions']['reset'] = array(
      '#type' => 'submit',
      '#value' => t('Revert'),
      '#submit' => array('course_outline_overview_form_reset'),
    );
  }

  $cform['objects']['#element_validate'] = array('_course_outline_overview_validate_objects');
  //return for form on tab
  return $form;
}

/**
 * Rebuild outline overview form.
 */
function course_outline_overview_form_rebuild($form, $form_state) {
  return $form;
}

/**
 * Submit handler for resetting a Course back to stored defaults.
 */
function course_outline_overview_form_reset(&$form, &$form_state) {
  unset($_SESSION['course'][$form['nid']['#value']]['editing']);
}

/**
 * Form constructor for a course object.
 *
 * To be re-used in listing and creating new course objects.
 */
function _course_outline_object_form($courseObject = NULL) {
  $rform['#tree'] = TRUE;
  $uniqid = $courseObject->getId();

  foreach (array('coid', 'instance', 'module', 'object_type', 'nid') as $key) {
    $rform[$key] = array(
      '#type' => 'value',
      '#default_value' => $courseObject->getOption($key),
    );
  }

  // Do not use prefix/suffix because markup only renders with a value, and we
  // need the wrapper before the title is saved for ajax population after each
  // settings modal update.
  $title = $courseObject->getTitle();
  $rform['title'] = array(
    '#prefix' => '<div id="title-' . $uniqid . '">',
    '#suffix' => '</div>',
    '#type' => 'markup',
    '#markup' => check_plain($title ? $title : ' '),
  );

  $summary = $courseObject->renderOptionsSummary();

  $rform['summary'] = array(
    '#prefix' => '<div id="summary-' . $uniqid . '">',
    '#suffix' => '</div>',
    '#type' => 'markup',
    '#markup' => filter_xss_admin($summary ? $summary : ' '),
  );

  // Placeholder for the settings link, it gets added after this function runs
  // in course_outline_overview_form(). #value needs a space for the prefix and
  // suffix to render.
  // Settings link for saved objects.
  $text = t('Settings');
  $path = "node/{$courseObject->getCourseNid()}/course-object/nojs/{$uniqid}/options";
  $l_options = array('query' => array('destination' => "node/{$courseObject->getCourseNid()}/course-outline"));
  $rform['options']['#markup'] = l($text, $path, $l_options);

  $rform['weight'] = array(
    '#type' => 'textfield',
    '#size' => 3,
    '#default_value' => $courseObject->getOption('weight'),
    '#attributes' => array(
      'class' => array('course-object-weight'),
    ),
  );

  return $rform;
}

/**
 * Theme the course outline overview form as a table.
 *
 * @see course_outline_overview_form()
 *
 * @ingroup themeable
 */
function theme_course_outline_overview_form(&$variables) {
  $form = &$variables['form'];
  $objects = &$form['course_outline']['objects'];
  drupal_add_tabledrag('course-objects', 'order', 'sibling', 'course-object-weight');
  drupal_add_css(drupal_get_path('module', 'course') . '/css/admin.css');

  $rows = array();

  foreach (element_children($objects) as $key) {
    $object = & $objects[$key];
    unset($objects[$key]['title']['#title']);
    unset($objects[$key]['object_type']['#title']);
    $rows[$key]['data'][] = array(
      'data' => NULL,
      'width' => 1,
    );
    $rows[$key]['data'][] = drupal_render($objects[$key]['title']) . drupal_render($objects[$key]['summary']);
    $rows[$key]['data'][] = drupal_render($objects[$key]['object_type']) . drupal_render($objects[$key]['object_type_show']);
    $rows[$key]['data'][] = drupal_render($objects[$key]['options']);

    // Add draggable settings to row.
    $rows[$key]['class'] = array('draggable');
    $rows[$key]['data'][] = drupal_render($objects[$key]['weight']);

    // Add id to row for per-row ajax handling.
    $rows[$key]['id'] = "row-{$key}";

    // Deletion handling.
    $nid = $object['nid']['#value'];
    // @kludge should we unify this, so we always use $courseObject->getOptions()
    // instead of pulling from the session?
    if (!empty($_SESSION['course'][$nid]['editing'][$key]['delete'])) {
      $rows[$key]['class'] = array('deleted');
    }

    // Mark everything else as printed.
    drupal_render($objects[$key]);
  }
  $table = theme('table', array('header' => array(), 'rows' => $rows, 'attributes' => array('id' => 'course-objects')));
  $table .= drupal_render_children($form);
  return $table;
}

/**
 * Validation callback.
 */
function _course_outline_overview_validate_objects(&$form, &$form_state) {

}

/**
 * Comparator function for course outline weights.
 */
function _course_outline_overview_form_cmp_function($a, $b) {
  if (is_object($a)) {
    if (isset($a->weight) && isset($b->weight)) {
      return $a->weight - $b->weight;
    }
  }
  else {
    if (isset($a['weight']) && isset($b['weight'])) {
      return $a['weight'] - $b['weight'];
    }
  }
}

/**
 * Submit handler.
 */
function course_outline_overview_form_submit(&$form, &$form_state) {
  if (empty($form_state['values']['course_outline']['objects'])) {
    // Empty form submitted.
    return;
  }

  $node = node_load($form['nid']['#value']);

  // Get form state values for object elements on the course outline overview:
  // - An associative array of course objects, keyed by ID. The ID for already
  //   saved objects is {course_outline}.coid, but for AHAH created objects the
  //   key is a generated unique ID until save.
  //   - coid: The key loaded from the database. If empty, the object is new.
  //   - module: The implementing module name (course_quiz etc).
  //   - object_type: The course object key as defined by
  //     hook_course_handlers().
  $objects = $form_state['values']['course_outline']['objects'];

  // Sort by weight so we can renumber.
  uasort($objects, '_course_outline_overview_form_cmp_function');

  foreach ($objects as $object_key => $object) {
    // Get each course object settings saved form values, which are not on the
    // outline overview form.
    if (!$courseObject = course_get_course_object_by_id($object_key)) {
      // For non-JS, no settings have been saved. We have to construct a new
      // course object.
      $courseObject = course_get_course_object($object);
    }
    $options = $courseObject->getOptions();
    foreach ($options as $option => $value) {
      $courseObject->setOption($option, $value);
    }

    // Renumber weights to the way draggable table would do it in case of no JS.
    $courseObject->setOption('weight', $object['weight']);

    // We only save overview objects with a selected component, whether loaded
    // from the database or AHAH created.
    if (isset($object['object_type'])) {
      // Delete database loaded objects that are on the chopping block.
      $is_loaded = $object['coid'];
      if ($options['delete'] && $is_loaded) {
        if ($options['delete_instance']) {
          // Also delete related object instance(s) if specified.
          $courseObject->delete();
        }
        course_outline_delete_object($object);
      }
      // If not slated for deletion, save the both db loaded and AHAH objects.
      elseif (!$options['delete']) {
        // If we get this far, save the object.
        $courseObject->save();
      }
    }
  }

  // Clear the editing session.
  unset($_SESSION['course'][$node->nid]['editing']);

  // Save the node to clear any caches.
  entity_get_controller('node')->resetCache(array($node->nid));

  drupal_set_message('Updated course.');

  $form_state['redirect'] = "node/$node->nid/course-outline";
}

/**
 * Generate HTML of the course outline.
 *
 * @param object $node
 *
 * @return course outline list.
 */
function course_outline_list($node) {
  global $user;

  $course = course_get_course($node, $user, TRUE);

  // Iterate over objects.
  $workflow = array();
  $img = NULL;
  foreach ($course->getObjects() as $key => $courseObject) {
    if ($courseObject->access('see')) {
      // The item will be in the list only if the user can see it. If they can
      // take it, entity_view() will output a link instead of text.
      $entity = entity_load_single('course_object', $courseObject->getId());
      $view = entity_view('course_object', array($entity));
      $data = drupal_render($view);

      $item = array(
        'data' => $data,
        'id' => $courseObject->getId(),
      );

      if ($courseObject->access('take')) {
        // User can take this course object.
        $item['class'][] = 'accessible';

        // Step is complete.
        if ($courseObject->getFulfillment()->isComplete()) {
          $item['class'][] = 'completed';
        }
        elseif ($courseObject->getFulfillment()->getId()) {
          $item['class'][] = 'in-progress';
        }
        if ($course->getActive() === $courseObject) {
          $item['class'][] = 'active';
        }
      }

      // Allow other modules to modify this list item.
      $courseObject->overrideOutlineListItem($item);

      // Add this item to the list.
      $workflow[] = $item;
    }
  }

  if ($course->getTracker()->getOption('complete')) {
    $img = theme('image', array('path' => 'misc/watchdog-ok.png'));
    $workflow[] = array(
      'data' => $img . l(t('Complete'), "node/$node->nid/course-complete", array('html' => TRUE)),
      'id' => 'complete',
    );
  }

  $output = '';
  if ($workflow) {
    return theme('course_outline', array('node' => $node, 'items' => $workflow));
  }
  return $output;
}

/**
 * Render a landing page for course completion.
 *
 * @param stdClass $course_node A course node.
 *
 * @return render array for the completion landing page.
 */
function course_completion_page($course_node) {
  global $user;
  $account = $user;

  // User's course record.
  $report = course_report_load($course_node, $account);

  // Render array.
  $page = array();

  // Links.
  $links = array();

  $links['course'] = array(
    t('Return to course'),
    "node/$course_node->nid/takecourse",
    t('Return to the course to view course details and material.'),
  );

  if ($report->getOption('complete')) {
    // Allow modules to add links to the course completion landing page, such as
    // post-course actions.
    drupal_alter('course_outline_completion_links', $links, $course_node, $account);
  }
  else {
    drupal_alter('course_outline_incomplete_links', $links, $course_node, $account);
  }


  drupal_set_title($report->getOption('complete') ? t('Course complete') : t('Remaining requirements'));

  $course = course_get_course($course_node, $account);
  $objects = $course->getObjects();
  $items = array();
  foreach ($objects as $courseObject) {
    if ($courseObject->access('see')) {
      // Find required course objects the user has not yet completed.
      $req = $courseObject->getFulfillment();
      $status_css = $req->isComplete() ? 'complete' : 'incomplete';
      $status_img = $req->isComplete() ? 'ok' : ($req->getCourseObject()->isRequired() ? 'error' : 'warning');
      $status_class = 'course-complete-item-' . $status_img;
      $status_optional = ($status_img == 'warning') ? ' (optional)' : ' (required)';
      if ($courseObject->access('take')) {
        $link = l($req->getCourseObject()->getTitle(), $courseObject->getUrl());
      }
      else {
        $link = $req->getCourseObject()->getTitle();
      }
      $items[] = array(
        'data' => array(
          array(
            'data' => theme('image', array('path' => "misc/watchdog-{$status_img}.png", 'width' => '', 'height' => '', 'alt' => $status_css)),
            'width' => 20,
            'class' => array('course-complete-item-status'),
          ),
          array(
            'data' => $link . $status_optional . '<br/>' . $req->getCourseObject()->getStatus(),
            'class' => array('course-complete-item-title'),
          ),
        ),
        'class' => array($status_class),
      );
    }
  }

  if ($report->getOption('complete')) {
    $message = t('You have completed the course. Use the links below to review the course content.');
  }
  else {
    $message = t('This course is not complete. Use the links below to access the remaining course content.');
  }

  $page['course_header'] = array(
    '#type' => 'item',
    '#title' => t('Thank you for participating in this course.'),
    '#description' => $message,
    '#weight' => 1,
  );

  $page['course_completion_requirements'] = array(
    '#theme' => 'table',
    '#header' => NULL,
    '#rows' => $items,
    '#weight' => 3,
    '#attributes' => array('class' => array('course-complete-items')),
  );

  foreach ($links as $key => $link) {
    $element = array(
      '#title' => l($link[0], $link[1], array('html' => TRUE)),
      '#description' => $link[2],
      '#type' => 'item',
    );
    $page['course_links'][$key] = $element;
  }

  $page['course_links']['#weight'] = 2;

  return $page;
}

/**
 * Delete a fulfillment.
 */
function course_outline_delete_fulfillment($mixed) {
  db_delete('course_outline_fulfillment')
    ->condition('coid', $mixed->coid)
    ->condition('uid', $mixed->uid)
    ->execute();
  return db_affected_rows() > 0;
}
