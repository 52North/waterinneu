<?php
/**
 * @file
 * randbee_feature_e_learning_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function randbee_feature_e_learning_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'course_type' => array(
      'name' => 'Course Type',
      'machine_name' => 'course_type',
      'description' => 'Describes the Course type',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
