<?php
/**
 * @file
 * n52_feature_organisations.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function n52_feature_organisations_taxonomy_default_vocabularies() {
  return array(
    'organisation_classification' => array(
      'name' => 'Organisation Classification',
      'machine_name' => 'organisation_classification',
      'description' => 'Classification of an organiziation',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 8,
      'language' => 'und',
      'i18n_mode' => 1,
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
