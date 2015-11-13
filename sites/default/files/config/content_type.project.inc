<?php
/**
 * @file
 * content_type.project.inc
 */

$api = '2.0.0';

$data = (object) array(
  'type' => 'project',
  'name' => 'Project',
  'description' => 'A project dealing with hydrological topics.',
  'has_title' => '1',
  'title_label' => 'Name',
  'base' => 'node_content',
  'help' => '',
);

$dependencies = array();

$optional = array(
  'field.node.field_website.project' => 'field.node.field_website.project',
  'field.node.field_end_date.project' => 'field.node.field_end_date.project',
  'field.node.field_location.project' => 'field.node.field_location.project',
  'field.node.field_raw_data.project' => 'field.node.field_raw_data.project',
  'field.node.field_metadata_level.project' => 'field.node.field_metadata_level.project',
  'field.node.field_policy_brief.project' => 'field.node.field_policy_brief.project',
  'field.node.field_guideline.project' => 'field.node.field_guideline.project',
  'field.node.field_report.project' => 'field.node.field_report.project',
  'field.node.field_administrative_data.project' => 'field.node.field_administrative_data.project',
  'field.node.field_model_data.project' => 'field.node.field_model_data.project',
  'field.node.field_model.project' => 'field.node.field_model.project',
  'field.node.field_observation_data.project' => 'field.node.field_observation_data.project',
  'field.node.field_software.project' => 'field.node.field_software.project',
  'field.node.field_hardware.project' => 'field.node.field_hardware.project',
  'field.node.field_approach.project' => 'field.node.field_approach.project',
  'field.node.field_comments.project' => 'field.node.field_comments.project',
  'field.node.field_tags.project' => 'field.node.field_tags.project',
  'field.node.field_organisations.project' => 'field.node.field_organisations.project',
  'field.node.field_partners_from.project' => 'field.node.field_partners_from.project',
  'field.node.field_standards_accounted_for.project' => 'field.node.field_standards_accounted_for.project',
  'field.node.field_published_tools.project' => 'field.node.field_published_tools.project',
  'field.node.field_partners_countries_of_orig.project' => 'field.node.field_partners_countries_of_orig.project',
  'field.node.field_bounding_box.project' => 'field.node.field_bounding_box.project',
  'field.node.field_logo.project' => 'field.node.field_logo.project',
  'field.node.field_hydrolocagical_aggregation.project' => 'field.node.field_hydrolocagical_aggregation.project',
  'field.node.field_administrative_aggregation.project' => 'field.node.field_administrative_aggregation.project',
  'field.node.field_hydrological_data_collecti.project' => 'field.node.field_hydrological_data_collecti.project',
  'field.node.field_administrative_data_collec.project' => 'field.node.field_administrative_data_collec.project',
  'field.node.field_report_available_.project' => 'field.node.field_report_available_.project',
  'permission.create_project_content' => 'permission.create_project_content',
  'permission.edit_own_project_content' => 'permission.edit_own_project_content',
  'permission.edit_any_project_content' => 'permission.edit_any_project_content',
  'permission.delete_own_project_content' => 'permission.delete_own_project_content',
  'permission.delete_any_project_content' => 'permission.delete_any_project_content',
);

$modules = array(
  0 => 'node',
);
