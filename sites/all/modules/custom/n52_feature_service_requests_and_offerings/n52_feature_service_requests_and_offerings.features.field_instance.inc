<?php
/**
 * @file
 * n52_feature_service_requests_and_offerings.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function n52_feature_service_requests_and_offerings_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'comment-comment_node_service_offering-comment_body'.
  $field_instances['comment-comment_node_service_offering-comment_body'] = array(
    'bundle' => 'comment_node_service_offering',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'comment_body',
    'label' => 'Comment',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'full_html_plain_no_filter_' => 'full_html_plain_no_filter_',
          'full_html_tinymce' => 'full_html_tinymce',
          'harmony_filtered' => 'harmony_filtered',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -8,
            ),
            'full_html_plain_no_filter_' => array(
              'weight' => 0,
            ),
            'full_html_tinymce' => array(
              'weight' => -7,
            ),
            'harmony_filtered' => array(
              'weight' => 0,
            ),
            'plain_text' => array(
              'weight' => -10,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'atjs_fieldset' => array(
          'atjs' => 0,
          'atjs_listeners' => array(
            'harmony_users' => 0,
          ),
        ),
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => -4,
    ),
  );

  // Exported field_instance:
  // 'comment-comment_node_service_offering-subject_field'.
  $field_instances['comment-comment_node_service_offering-subject_field'] = array(
    'bundle' => 'comment_node_service_offering',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'subject_field',
    'label' => 'Subject',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => 0,
        'page' => 0,
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -5,
    ),
  );

  // Exported field_instance:
  // 'comment-comment_node_service_request-comment_body'.
  $field_instances['comment-comment_node_service_request-comment_body'] = array(
    'bundle' => 'comment_node_service_request',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'comment_body',
    'label' => 'Comment',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'full_html_plain_no_filter_' => 'full_html_plain_no_filter_',
          'full_html_tinymce' => 'full_html_tinymce',
          'harmony_filtered' => 'harmony_filtered',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -8,
            ),
            'full_html_plain_no_filter_' => array(
              'weight' => 0,
            ),
            'full_html_tinymce' => array(
              'weight' => -7,
            ),
            'harmony_filtered' => array(
              'weight' => 0,
            ),
            'plain_text' => array(
              'weight' => -10,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'atjs_fieldset' => array(
          'atjs' => 0,
          'atjs_listeners' => array(
            'harmony_users' => 0,
          ),
        ),
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => -4,
    ),
  );

  // Exported field_instance:
  // 'comment-comment_node_service_request-subject_field'.
  $field_instances['comment-comment_node_service_request-subject_field'] = array(
    'bundle' => 'comment_node_service_request',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'subject_field',
    'label' => 'Subject',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => 0,
        'page' => 0,
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -5,
    ),
  );

  // Exported field_instance: 'node-service_offering-field_description'.
  $field_instances['node-service_offering-field_description'] = array(
    'bundle' => 'service_offering',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'What is your offering regarding the selected product?',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'smart_trim',
        'settings' => array(
          'more_link' => 0,
          'more_text' => 'Read more',
          'summary_handler' => 'full',
          'trim_length' => 150,
          'trim_link' => 0,
          'trim_options' => array(
            'text' => 'text',
          ),
          'trim_preserve_tags' => '',
          'trim_suffix' => '...',
          'trim_type' => 'chars',
        ),
        'type' => 'smart_trim_format',
        'weight' => 0,
      ),
      'tool_of_the_month' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_description',
    'label' => 'Description',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 0,
          'full_html_plain_no_filter_' => 0,
          'full_html_tinymce' => 'full_html_tinymce',
          'harmony_filtered' => 0,
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -8,
            ),
            'full_html_plain_no_filter_' => array(
              'weight' => 0,
            ),
            'full_html_tinymce' => array(
              'weight' => -7,
            ),
            'harmony_filtered' => array(
              'weight' => 0,
            ),
            'plain_text' => array(
              'weight' => -10,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'atjs_fieldset' => array(
          'atjs' => 0,
          'atjs_listeners' => array(
            'harmony_users' => 0,
          ),
        ),
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-service_offering-field_organisation'.
  $field_instances['node-service_offering-field_organisation'] = array(
    'bundle' => 'service_offering',
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'Which organisation offers this service?',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 3,
      ),
      'tool_of_the_month' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_organisation',
    'label' => 'Organisation',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference_view_widget',
      'settings' => array(
        'allow_duplicates' => 0,
        'close_modal' => 1,
        'pass_argument' => 0,
        'pass_arguments' => '',
        'rendered_entity' => 0,
        'view' => 'organisations_for_referencing|entityreference_view_widget_2',
        'view_mode' => 'full',
      ),
      'type' => 'entityreference_view_widget',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-service_offering-field_product'.
  $field_instances['node-service_offering-field_product'] = array(
    'bundle' => 'service_offering',
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'For which product do you offer services?',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
      'tool_of_the_month' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_product',
    'label' => 'Product',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference_view_widget',
      'settings' => array(
        'allow_duplicates' => 0,
        'close_modal' => 1,
        'pass_argument' => 0,
        'pass_arguments' => '',
        'rendered_entity' => 0,
        'view' => 'products_for_referencing|entityreference_view_widget_2',
        'view_mode' => 'full',
      ),
      'type' => 'entityreference_view_widget',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-service_offering-field_service_category'.
  $field_instances['node-service_offering-field_service_category'] = array(
    'bundle' => 'service_offering',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Which category fits your request?',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 1,
      ),
      'tool_of_the_month' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_service_category',
    'label' => 'Category',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-service_offering-title_field'.
  $field_instances['node-service_offering-title_field'] = array(
    'bundle' => 'service_offering',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'tool_of_the_month' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'title_field',
    'label' => 'Title',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => 0,
        'page' => 0,
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-service_request-field_description'.
  $field_instances['node-service_request-field_description'] = array(
    'bundle' => 'service_request',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please describe your demand as detailed as possible, but be reminded that is request will be published.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'smart_trim',
        'settings' => array(
          'more_link' => 0,
          'more_text' => '',
          'summary_handler' => 'full',
          'trim_length' => 150,
          'trim_link' => 0,
          'trim_options' => array(
            'text' => 'text',
          ),
          'trim_preserve_tags' => '',
          'trim_suffix' => '...',
          'trim_type' => 'chars',
        ),
        'type' => 'smart_trim_format',
        'weight' => 0,
      ),
      'tool_of_the_month' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_description',
    'label' => 'Description',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 0,
          'full_html_plain_no_filter_' => 0,
          'full_html_tinymce' => 'full_html_tinymce',
          'harmony_filtered' => 0,
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -8,
            ),
            'full_html_plain_no_filter_' => array(
              'weight' => 0,
            ),
            'full_html_tinymce' => array(
              'weight' => -7,
            ),
            'harmony_filtered' => array(
              'weight' => 0,
            ),
            'plain_text' => array(
              'weight' => -10,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'atjs_fieldset' => array(
          'atjs' => 0,
          'atjs_listeners' => array(
            'harmony_users' => 0,
          ),
        ),
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-service_request-field_product'.
  $field_instances['node-service_request-field_product'] = array(
    'bundle' => 'service_request',
    'default_value' => array(),
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'Which product is your inquiry about?',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'textformatter',
        'settings' => array(
          'textformatter_class' => 'textformatter-list',
          'textformatter_comma_and' => 1,
          'textformatter_comma_full_stop' => 1,
          'textformatter_comma_override' => 0,
          'textformatter_comma_tag' => 0,
          'textformatter_contrib' => array(
            'entityreference_link' => 1,
          ),
          'textformatter_separator_custom' => '',
          'textformatter_separator_custom_class' => 'textformatter-separator',
          'textformatter_separator_custom_tag' => 'span',
          'textformatter_term_plain' => 0,
          'textformatter_type' => 'comma',
        ),
        'type' => 'textformatter_list',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'textformatter',
        'settings' => array(
          'textformatter_class' => 'textformatter-list',
          'textformatter_comma_and' => 1,
          'textformatter_comma_full_stop' => 1,
          'textformatter_comma_override' => 0,
          'textformatter_comma_tag' => 0,
          'textformatter_contrib' => array(
            'entityreference_link' => 1,
          ),
          'textformatter_separator_custom' => '',
          'textformatter_separator_custom_class' => 'textformatter-separator',
          'textformatter_separator_custom_tag' => 'span',
          'textformatter_term_plain' => 0,
          'textformatter_type' => 'comma',
        ),
        'type' => 'textformatter_list',
        'weight' => 2,
      ),
      'tool_of_the_month' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_product',
    'label' => 'Product',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference_view_widget',
      'settings' => array(
        'allow_duplicates' => 0,
        'close_modal' => 1,
        'pass_argument' => 0,
        'pass_arguments' => '',
        'rendered_entity' => 0,
        'view' => 'products_for_referencing_multi|entityreference_view_widget_2',
        'view_mode' => 'full',
      ),
      'type' => 'entityreference_view_widget',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-service_request-field_service_category'.
  $field_instances['node-service_request-field_service_category'] = array(
    'bundle' => 'service_request',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Which category fits your inquiry',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 1,
      ),
      'tool_of_the_month' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_service_category',
    'label' => 'Category',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-service_request-title_field'.
  $field_instances['node-service_request-title_field'] = array(
    'bundle' => 'service_request',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'tool_of_the_month' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'title_field',
    'label' => 'Title',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => 0,
        'page' => 0,
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'taxonomy_term-service_categories-name_field'.
  $field_instances['taxonomy_term-service_categories-name_field'] = array(
    'bundle' => 'service_categories',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_index' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'name_field',
    'label' => 'Name',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => 0,
        'page' => 0,
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Category');
  t('Comment');
  t('Description');
  t('For which product do you offer services?');
  t('Name');
  t('Organisation');
  t('Please describe your demand as detailed as possible, but be reminded that is request will be published.');
  t('Product');
  t('Subject');
  t('Title');
  t('What is your offering regarding the selected product?');
  t('Which category fits your inquiry');
  t('Which category fits your request?');
  t('Which organisation offers this service?');
  t('Which product is your inquiry about?');

  return $field_instances;
}
