<?php
/**
 * @file
 * randbee_feature_course_object.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function randbee_feature_course_object_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_material|node|course_object|default';
  $field_group->group_name = 'group_course_material';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_object';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_course_object';
  $field_group->data = array(
    'label' => 'Course material',
    'weight' => '7',
    'children' => array(
      0 => 'field_data',
      1 => 'field_notes',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-course-material field-group-tab',
      ),
    ),
  );
  $field_groups['group_course_material|node|course_object|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_material|node|course_object|form';
  $field_group->group_name = 'group_course_material';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_object';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course_object';
  $field_group->data = array(
    'label' => 'Course material',
    'weight' => '3',
    'children' => array(
      0 => 'field_data',
      1 => 'field_notes',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-course-material field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_course_material|node|course_object|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_object|node|course_object|default';
  $field_group->group_name = 'group_course_object';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_object';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Course object	',
    'weight' => '0',
    'children' => array(
      0 => 'group_course_material',
      1 => 'group_links',
      2 => 'group_video',
      3 => 'group_software',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-course-object field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_course_object|node|course_object|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_object|node|course_object|form';
  $field_group->group_name = 'group_course_object';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_object';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Course object',
    'weight' => '1',
    'children' => array(
      0 => 'group_software',
      1 => 'group_course_material',
      2 => 'group_links',
      3 => 'group_video',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-course-object field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_course_object|node|course_object|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_links|node|course_object|default';
  $field_group->group_name = 'group_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_object';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_course_object';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '10',
    'children' => array(
      0 => 'field_link',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-links field-group-tab',
      ),
    ),
  );
  $field_groups['group_links|node|course_object|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_links|node|course_object|form';
  $field_group->group_name = 'group_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_object';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course_object';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '7',
    'children' => array(
      0 => 'field_link',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-links field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_links|node|course_object|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_software|node|course_object|default';
  $field_group->group_name = 'group_software';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_object';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_course_object';
  $field_group->data = array(
    'label' => 'Software',
    'weight' => '9',
    'children' => array(
      0 => 'field_installation_file',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-software field-group-tab',
      ),
    ),
  );
  $field_groups['group_software|node|course_object|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_software|node|course_object|form';
  $field_group->group_name = 'group_software';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_object';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course_object';
  $field_group->data = array(
    'label' => 'Software',
    'weight' => '5',
    'children' => array(
      0 => 'field_installation_file',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-software field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_software|node|course_object|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video|node|course_object|default';
  $field_group->group_name = 'group_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_object';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_course_object';
  $field_group->data = array(
    'label' => 'Video',
    'weight' => '8',
    'children' => array(
      0 => 'field_course_video',
      1 => 'field_video_description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-video field-group-tab',
      ),
    ),
  );
  $field_groups['group_video|node|course_object|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video|node|course_object|form';
  $field_group->group_name = 'group_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_object';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course_object';
  $field_group->data = array(
    'label' => 'Video',
    'weight' => '4',
    'children' => array(
      0 => 'field_course_video',
      1 => 'field_video_description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-video field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_video|node|course_object|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Course material');
  t('Course object');
  t('Course object	');
  t('Links');
  t('Software');
  t('Video');

  return $field_groups;
}
