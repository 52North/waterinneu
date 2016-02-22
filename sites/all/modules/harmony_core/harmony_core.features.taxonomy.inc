<?php
/**
 * @file
 * harmony_core.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function harmony_core_taxonomy_default_vocabularies() {
  return array(
    'harmony_category' => array(
      'name' => 'Category',
      'machine_name' => 'harmony_category',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => -10,
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
