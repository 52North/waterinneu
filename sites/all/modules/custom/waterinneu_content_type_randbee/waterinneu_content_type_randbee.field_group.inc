<?php
/**
 * @file
 * waterinneu_content_type_randbee.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function waterinneu_content_type_randbee_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_contacts|node|course|default';
  $field_group->group_name = 'group_course_contacts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_course';
  $field_group->data = array(
    'label' => 'Contacts',
    'weight' => '17',
    'children' => array(
      0 => 'field_course_contacts',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Contacts',
      'instance_settings' => array(
        'classes' => 'group-course-contacts field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_course_contacts|node|course|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_contacts|node|course|form';
  $field_group->group_name = 'group_course_contacts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course';
  $field_group->data = array(
    'label' => 'Contacts',
    'weight' => '34',
    'children' => array(
      0 => 'field_course_contacts',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Contacts',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-course-contacts field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_course_contacts|node|course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_structure|node|course|default';
  $field_group->group_name = 'group_course_structure';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_course';
  $field_group->data = array(
    'label' => 'Course Structure',
    'weight' => '18',
    'children' => array(
      0 => 'field_course_structure',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-course-structure field-group-tab',
      ),
    ),
  );
  $field_groups['group_course_structure|node|course|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_structure|node|course|form';
  $field_group->group_name = 'group_course_structure';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course';
  $field_group->data = array(
    'label' => 'Course Structure',
    'weight' => '41',
    'children' => array(
      0 => 'field_course_structure',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-course-structure field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_course_structure|node|course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_title_description|node|course|form';
  $field_group->group_name = 'group_course_title_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course';
  $field_group->data = array(
    'label' => 'Title and Description',
    'weight' => '29',
    'children' => array(
      0 => 'title_field',
      1 => 'body',
      2 => 'field_course_image',
      3 => 'path',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Title and Description',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-course-title-description field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_course_title_description|node|course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_title|node|course|default';
  $field_group->group_name = 'group_course_title';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_course';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '16',
    'children' => array(
      0 => 'body',
      1 => 'field_course_image',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Description',
      'instance_settings' => array(
        'classes' => 'group-course-title field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_course_title|node|course|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_type|node|course|form';
  $field_group->group_name = 'group_course_type';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course';
  $field_group->data = array(
    'label' => 'Type',
    'weight' => '35',
    'children' => array(
      0 => 'field_course_type',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Type',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-course-type field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_course_type|node|course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course|node|course|default';
  $field_group->group_name = 'group_course';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Course',
    'weight' => '2',
    'children' => array(
      0 => 'group_course_structure',
      1 => 'group_course_contacts',
      2 => 'group_course_title',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-course field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_course|node|course|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course|node|course|form';
  $field_group->group_name = 'group_course';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Course',
    'weight' => '0',
    'children' => array(
      0 => 'group_course_structure',
      1 => 'group_course_contacts',
      2 => 'group_course_title_description',
      3 => 'group_course_type',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_course|node|course|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contacts');
  t('Course');
  t('Course Structure');
  t('Description');
  t('Title and Description');
  t('Type');

  return $field_groups;
}
