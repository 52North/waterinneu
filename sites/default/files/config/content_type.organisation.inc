<?php
/**
 * @file
 * content_type.organisation.inc
 */

$api = '2.0.0';

$data = (object) array(
  'type' => 'organisation',
  'name' => 'Organisation',
  'description' => 'Organisation Description',
  'has_title' => '1',
  'title_label' => 'Name',
  'base' => 'node_content',
  'help' => 'Explanation or submission guidelines for organisation entities',
);

$dependencies = array();

$optional = array(
  'field.node.field_tags.organisation' => 'field.node.field_tags.organisation',
  'field.node.field_website.organisation' => 'field.node.field_website.organisation',
  'field.node.field_projects.organisation' => 'field.node.field_projects.organisation',
  'field.node.field_country_term.organisation' => 'field.node.field_country_term.organisation',
  'field.node.field_code.organisation' => 'field.node.field_code.organisation',
  'field.node.field_class.organisation' => 'field.node.field_class.organisation',
  'field.node.field_logo.organisation' => 'field.node.field_logo.organisation',
  'permission.create_organisation_content' => 'permission.create_organisation_content',
  'permission.edit_own_organisation_content' => 'permission.edit_own_organisation_content',
  'permission.edit_any_organisation_content' => 'permission.edit_any_organisation_content',
  'permission.delete_own_organisation_content' => 'permission.delete_own_organisation_content',
  'permission.delete_any_organisation_content' => 'permission.delete_any_organisation_content',
);

$modules = array(
  0 => 'node',
);
