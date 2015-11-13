<?php
/**
 * @file
 * text_format.full_html_tinymce.inc
 */

$api = '2.0.0';

$data = (object) array(
  'format' => 'full_html_tinymce',
  'name' => 'Full HTML - TinyMCE',
  'cache' => '0',
  'status' => '1',
  'weight' => '-7',
  'filters' => array(
    'atjs' => array(
      'weight' => '0',
      'status' => '1',
      'settings' => array(
        'atjs_listeners' => array(
          'harmony_users' => 'harmony_users',
        ),
      ),
    ),
    'codefilter' => array(
      'weight' => '0',
      'status' => '1',
      'settings' => array(
        'nowrap_expand' => 1,
      ),
    ),
    'entity_quote' => array(
      'weight' => '0',
      'status' => '1',
      'settings' => array(
        'quotable_types' => array(
          'comment:comment_node_article' => 0,
          'comment:comment_node_page' => 0,
          'comment:comment_node_organisation' => 0,
          'comment:comment_node_portal' => 0,
          'comment:comment_node_project' => 0,
          'comment:comment_node_tool' => 0,
          'flagging:harmony_likes' => 0,
          'harmony_thread:harmony_thread' => 0,
          'harmony_thread_type:' => 0,
          'harmony_post:' => 0,
          'i18n_translation:menu_link' => 0,
          'i18n_translation:path' => 0,
          'i18n_translation:taxonomy_term' => 0,
          'node:article' => 0,
          'node:page' => 0,
          'node:organisation' => 0,
          'node:portal' => 0,
          'node:project' => 0,
          'node:tool' => 0,
          'search_api_server:' => 0,
          'search_api_index:' => 0,
          'file:' => 0,
          'taxonomy_term:tags' => 0,
          'taxonomy_term:standards' => 0,
          'taxonomy_term:license' => 0,
          'taxonomy_term:countries' => 0,
          'taxonomy_term:harmony_category' => 0,
          'taxonomy_term:organisation_classification' => 0,
          'taxonomy_term:location' => 0,
          'taxonomy_term:administrative_levels' => 0,
          'taxonomy_term:hydrological_level' => 0,
          'taxonomy_vocabulary:' => 0,
          'user:' => 0,
          'wysiwyg_profile:' => 0,
          'rules_config:' => 0,
        ),
      ),
    ),
    'filter_autop' => array(
      'weight' => '0',
      'status' => '1',
      'settings' => array(),
    ),
    'filter_url' => array(
      'weight' => '0',
      'status' => '1',
      'settings' => array(
        'filter_url_length' => '72',
      ),
    ),
    'freelinking' => array(
      'weight' => '0',
      'status' => '1',
      'settings' => array(),
    ),
    'filter_htmlcorrector' => array(
      'weight' => '10',
      'status' => '1',
      'settings' => array(),
    ),
  ),
);

$dependencies = array();

$optional = array(
  'permission.use_text_format_full_html_tinymce' => 'permission.use_text_format_full_html_tinymce',
  'wysiwyg.full_html_tinymce' => 'wysiwyg.full_html_tinymce',
);

$modules = array(
  0 => 'atjs',
  1 => 'codefilter',
  2 => 'entity_quote',
  3 => 'filter',
  4 => 'freelinking',
);
