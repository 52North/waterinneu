<?php
/**
 * @file
 * content_type.tool.inc
 */

$api = '2.0.0';

$data = (object) array(
  'type' => 'tool',
  'name' => 'Tool',
  'description' => 'Product specification sheet for project results of type tool, e.g. software.',
  'has_title' => '1',
  'title_label' => 'Title',
  'base' => 'node_content',
  'help' => '',
);

$dependencies = array();

$optional = array(
  'field.node.field_description.tool' => 'field.node.field_description.tool',
  'field.node.field_logo.tool' => 'field.node.field_logo.tool',
  'field.node.field_website.tool' => 'field.node.field_website.tool',
  'field.node.field_case_studies.tool' => 'field.node.field_case_studies.tool',
  'field.node.field_manuals_training.tool' => 'field.node.field_manuals_training.tool',
  'field.node.field_license.tool' => 'field.node.field_license.tool',
  'field.node.field_purpose.tool' => 'field.node.field_purpose.tool',
  'field.node.field_climate_change_revelance.tool' => 'field.node.field_climate_change_revelance.tool',
  'field.node.field_application_scale.tool' => 'field.node.field_application_scale.tool',
  'field.node.field_category.tool' => 'field.node.field_category.tool',
  'field.node.field_type_of_input_data.tool' => 'field.node.field_type_of_input_data.tool',
  'field.node.field_supported_legacy_systems.tool' => 'field.node.field_supported_legacy_systems.tool',
  'field.node.field_standards_accounted_for.tool' => 'field.node.field_standards_accounted_for.tool',
  'field.node.field_combinability.tool' => 'field.node.field_combinability.tool',
  'field.node.field_tool_of_the_month.tool' => 'field.node.field_tool_of_the_month.tool',
  'permission.create_tool_content' => 'permission.create_tool_content',
  'permission.edit_own_tool_content' => 'permission.edit_own_tool_content',
  'permission.edit_any_tool_content' => 'permission.edit_any_tool_content',
  'permission.delete_own_tool_content' => 'permission.delete_own_tool_content',
  'permission.delete_any_tool_content' => 'permission.delete_any_tool_content',
);

$modules = array(
  0 => 'node',
);
