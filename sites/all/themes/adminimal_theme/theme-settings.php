<?php


/**
 * @file
 * Theme setting callbacks for the Adminimal theme.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */
function adminimal_form_system_theme_settings_alter(&$form, &$form_state) {

  // Get adminimal theme path.
  global $base_url;
  $adminimal_path = drupal_get_path('theme', 'adminimal');
  $old_css_path = $adminimal_path . '/css/custom.css';
  $custom_css_path = 'public://adminimal-custom.css';
  $custom_css_dir = str_replace($base_url . '/', "", file_create_url($custom_css_path));
  $custom_css_url = file_create_url($custom_css_path);

  // Try to create the adminimal-custom.css file automatically.
  if (!file_exists($custom_css_path)) {

    // Try to migrate from the old css.
    if (file_exists($old_css_path)) {
      file_unmanaged_copy($old_css_path, $custom_css_path, FILE_EXISTS_ERROR);
    }
    // Else create e new blank css file.
    else {
      file_unmanaged_save_data("", $custom_css_path, FILE_EXISTS_ERROR);
    }

  }

  // Notify user to remove his old css file.
  if (file_exists($old_css_path)) {
    drupal_set_message(t('Please delete the old @css_location file, as its no longer used.', array('@css_location file' => $old_css_path)), 'warning');
  }

  $form['adminimal_custom'] = array(
    '#type' => 'fieldset',
    '#title' => t('Adminimal Customization'),
    '#weight' => -10,
  );

  $form['adminimal_custom']['display_icons_config'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display icons in Configuration page'),
    '#default_value' => theme_get_setting('display_icons_config'),
  );

  $form['adminimal_custom']['use_custom_media_queries'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Custom Media Queries'),
    '#description' => t('You can override the mobile and tablet media queries from this option. Use it only if you know what media queries are and how to use them.'),
    '#default_value' => theme_get_setting('use_custom_media_queries'),
  );

  $form['adminimal_custom']['media_queries'] = array(
    '#type' => 'fieldset',
    '#title' => t('Custom Media Queries'),
    '#states' => array(
      // Hide the settings when the cancel notify checkbox is disabled.
      'visible' => array(
       ':input[name="use_custom_media_queries"]' => array('checked' => TRUE),
      ),
     ),
  );

  $form['adminimal_custom']['media_queries']['media_query_mobile'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile media query'),
    '#description' => t('The media query to load the mobile.css styles.'),
    '#default_value' => theme_get_setting('media_query_mobile'),
  );

  $form['adminimal_custom']['media_queries']['media_query_tablet'] = array(
    '#type' => 'textfield',
    '#title' => t('Tablet media query'),
    '#description' => t('The media query to load the tablet.css styles.'),
    '#default_value' => theme_get_setting('media_query_tablet'),
  );

  $form['adminimal_custom']['custom_css'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use "adminimal-custom.css"'),
    '#description' => t('Include adminimal-custom.css file to override or add custom css code without subthememing/hacking Adminimal Theme.'),
    '#default_value' => theme_get_setting('custom_css'),
  );

  $form['adminimal_custom']['adminimal_custom_check'] = array(
    '#type' => 'fieldset',
    '#title' => t('Custom CSS file check'),
    '#weight' => 50,
    '#states' => array(
      // Hide the settings when the cancel notify checkbox is disabled.
      'visible' => array(
       ':input[name="custom_css"]' => array('checked' => TRUE),
      ),
     ),
  );

  if (file_exists($custom_css_path)) {
    $form['adminimal_custom']['adminimal_custom_check']['custom_css_description'] = array(
      '#markup' => t('Custom CSS file Found in: !css', array('!css' => "<span class='css_path'>" . $custom_css_dir . "</span>")),
      '#prefix' => '<div class="messages status custom_css_found">',
      '#suffix' => '</div>',
    );
  }
  else {
    $form['adminimal_custom']['adminimal_custom_check']['custom_css_not_found'] = array(
      '#markup' => t('Custom CSS file not found. You must create the !css file manually.', array('!css' => "<span class='css_path'>" . $custom_css_dir . "</span>")),
      '#prefix' => '<div class="messages error custom_css_not_found">',
      '#suffix' => '</div>',
    );
  }
}
