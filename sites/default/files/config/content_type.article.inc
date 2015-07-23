<?php
/**
 * @file
 * content_type.article.inc
 */

$api = '2.0.0';

$data = (object) array(
  'type' => 'article',
  'name' => 'Article',
  'description' => 'Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.',
  'has_title' => '1',
  'title_label' => 'Title',
  'base' => 'node_content',
  'help' => '',
);

$dependencies = array();

$optional = array(
  'field.node.body.article' => 'field.node.body.article',
  'field.node.field_tags.article' => 'field.node.field_tags.article',
  'field.node.field_image.article' => 'field.node.field_image.article',
  'permission.create_article_content' => 'permission.create_article_content',
  'permission.edit_own_article_content' => 'permission.edit_own_article_content',
  'permission.edit_any_article_content' => 'permission.edit_any_article_content',
  'permission.delete_own_article_content' => 'permission.delete_own_article_content',
  'permission.delete_any_article_content' => 'permission.delete_any_article_content',
);

$modules = array(
  0 => 'node',
);
