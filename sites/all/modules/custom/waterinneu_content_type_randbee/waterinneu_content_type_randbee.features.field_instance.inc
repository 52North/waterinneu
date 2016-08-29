<?php
/**
 * @file
 * waterinneu_content_type_randbee.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function waterinneu_content_type_randbee_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-course-body'.
  $field_instances['node-course-body'] = array(
    'bundle' => 'course',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A short description of this Course must be written.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
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
    'field_name' => 'body',
    'label' => 'Description',
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
      'course_enrollment' => FALSE,
      'display_summary' => 1,
      'entity_translation_sync' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 1,
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
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => -3,
    ),
  );

  // Exported field_instance: 'node-course-field_course_contacts'.
  $field_instances['node-course-field_course_contacts'] = array(
    'bundle' => 'course',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Information and contacts about the Course designer should be written here.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_course_contacts',
    'label' => 'Contacts',
    'required' => 0,
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
      'course_enrollment' => FALSE,
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
        'rows' => 10,
      ),
      'type' => 'text_textarea',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-course-field_course_data'.
  $field_instances['node-course-field_course_data'] = array(
    'bundle' => 'course',
    'deleted' => 0,
    'description' => 'Course Data should be uploaded here.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 5,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_course_data',
    'label' => 'Data',
    'required' => 0,
    'settings' => array(
      'course_enrollment' => FALSE,
      'description_field' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'csv txt xls xlsx doc docx ppt pptx pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-course-field_course_image'.
  $field_instances['node-course-field_course_image'] = array(
    'bundle' => 'course',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'medium',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_course_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'course_enrollment' => FALSE,
      'default_image' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => -2,
    ),
  );

  // Exported field_instance: 'node-course-field_course_links'.
  $field_instances['node-course-field_course_links'] = array(
    'bundle' => 'course',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The reference links of the Course should be written here.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 6,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_course_links',
    'label' => 'Links',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'course_enrollment' => FALSE,
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'rel_remove' => 'default',
      'title' => 'required',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'node-course-field_course_notes'.
  $field_instances['node-course-field_course_notes'] = array(
    'bundle' => 'course',
    'deleted' => 0,
    'description' => 'The PDF Course must be uploaded here.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 4,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_course_notes',
    'label' => 'Notes',
    'required' => 1,
    'settings' => array(
      'course_enrollment' => FALSE,
      'description_field' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-course-field_course_product_ref'.
  $field_instances['node-course-field_course_product_ref'] = array(
    'bundle' => 'course',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 4,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_course_product_ref',
    'label' => 'Product Ref',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'course_enrollment' => FALSE,
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

  // Exported field_instance: 'node-course-field_course_type'.
  $field_instances['node-course-field_course_type'] = array(
    'bundle' => 'course',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_course_type',
    'label' => 'Type',
    'required' => 0,
    'settings' => array(
      'course_enrollment' => FALSE,
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
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'node-course-field_course_video'.
  $field_instances['node-course-field_course_video'] = array(
    'bundle' => 'course',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'video_embed_field',
        'settings' => array(
          'description' => 1,
          'description_position' => 'bottom',
          'video_style' => 'normal',
        ),
        'type' => 'video_embed_field',
        'weight' => 17,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_course_video',
    'label' => 'Video',
    'required' => 0,
    'settings' => array(
      'allowed_providers' => array(
        'vimeo' => 'vimeo',
        'youtube' => 'youtube',
      ),
      'course_enrollment' => FALSE,
      'description_field' => 0,
      'description_length' => 128,
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'video_embed_field',
      'settings' => array(),
      'type' => 'video_embed_field_video',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'node-course-field_video_description'.
  $field_instances['node-course-field_video_description'] = array(
    'bundle' => 'course',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 16,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_video_description',
    'label' => 'Video Description',
    'required' => 0,
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
      'course_enrollment' => FALSE,
      'entity_translation_sync' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 1,
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
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-course-title_field'.
  $field_instances['node-course-title_field'] = array(
    'bundle' => 'course',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'title',
        'settings' => array(
          'title_class' => '',
          'title_link' => '',
          'title_style' => '',
        ),
        'type' => 'title_linked',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
      'weight' => -5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('A short description of this Course must be written.');
  t('Contacts');
  t('Course Data should be uploaded here.');
  t('Data');
  t('Description');
  t('Image');
  t('Information and contacts about the Course designer should be written here.');
  t('Links');
  t('Notes');
  t('Product Ref');
  t('The PDF Course must be uploaded here.');
  t('The reference links of the Course should be written here.');
  t('Title');
  t('Type');
  t('Video');
  t('Video Description');

  return $field_instances;
}
