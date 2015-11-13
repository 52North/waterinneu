<?php
/**
 * @file
 * field.node.field_class.organisation.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'translatable' => '0',
    'entity_types' => array(),
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'organisation_classification',
          'parent' => '0',
        ),
      ),
      'options_list_callback' => 'i18n_taxonomy_allowed_values',
    ),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_field_class' => array(
              'tid' => 'field_class_tid',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_class' => array(
              'tid' => 'field_class_tid',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(
      'tid' => array(
        'table' => 'taxonomy_term_data',
        'columns' => array(
          'tid' => 'tid',
        ),
      ),
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'field_name' => 'field_class',
    'type' => 'taxonomy_term_reference',
    'module' => 'taxonomy',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '-1',
    'deleted' => '0',
    'columns' => array(
      'tid' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Class',
    'widget' => array(
      'weight' => '12',
      'type' => 'taxonomy_autocomplete',
      'module' => 'taxonomy',
      'active' => 0,
      'settings' => array(
        'size' => 60,
        'autocomplete_path' => 'taxonomy/autocomplete',
      ),
    ),
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'type' => 'textformatter_list',
        'weight' => '9',
        'settings' => array(
          'textformatter_type' => 'comma',
          'textformatter_comma_and' => 0,
          'textformatter_comma_full_stop' => 0,
          'textformatter_comma_override' => 0,
          'textformatter_separator_custom' => '',
          'textformatter_separator_custom_tag' => 'span',
          'textformatter_separator_custom_class' => 'textformatter-separator',
          'textformatter_comma_tag' => 'span',
          'textformatter_class' => 'textformatter-list',
          'textformatter_term_plain' => 0,
          'textformatter_contrib' => array(),
        ),
        'module' => 'textformatter',
      ),
      'teaser' => array(
        'label' => 'above',
        'type' => 'textformatter_list',
        'weight' => '1',
        'settings' => array(
          'textformatter_type' => 'comma',
          'textformatter_comma_and' => 0,
          'textformatter_comma_full_stop' => 0,
          'textformatter_comma_override' => 0,
          'textformatter_separator_custom' => '',
          'textformatter_separator_custom_tag' => 'span',
          'textformatter_separator_custom_class' => 'textformatter-separator',
          'textformatter_comma_tag' => 'span',
          'textformatter_class' => 'textformatter-list',
          'textformatter_term_plain' => 1,
          'textformatter_contrib' => array(),
        ),
        'module' => 'textformatter',
      ),
    ),
    'required' => 0,
    'description' => 'Classification of the organisation. Currently available: SME, Large Enterprise, Trade Association, Consulting, Research Institute and Remaining. Combinations are allowed if useful.',
    'default_value' => array(
      0 => array(
        'tid' => '1830',
        'vid' => '8',
        'name' => 'Remaining',
        'description' => NULL,
        'format' => NULL,
        'weight' => '0',
        'language' => 'und',
        'i18n_tsid' => '0',
        'vocabulary_machine_name' => 'organisation_classification',
        'rdf_mapping' => array(
          'rdftype' => array(
            0 => 'skos:Concept',
          ),
          'name' => array(
            'predicates' => array(
              0 => 'rdfs:label',
              1 => 'skos:prefLabel',
            ),
          ),
          'description' => array(
            'predicates' => array(
              0 => 'skos:definition',
            ),
          ),
          'vid' => array(
            'predicates' => array(
              0 => 'skos:inScheme',
            ),
            'type' => 'rel',
          ),
          'parent' => array(
            'predicates' => array(
              0 => 'skos:broader',
            ),
            'type' => 'rel',
          ),
        ),
      ),
    ),
    'field_name' => 'field_class',
    'entity_type' => 'node',
    'bundle' => 'organisation',
    'deleted' => '0',
  ),
);

$dependencies = array(
  'content_type.organisation' => 'content_type.organisation',
  'vocabulary.organisation_classification' => 'vocabulary.organisation_classification',
);

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'taxonomy',
);
