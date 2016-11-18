<?php
/**
 * @file
 * waterinneu_content_type_randbee.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function waterinneu_content_type_randbee_taxonomy_default_vocabularies() {
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
