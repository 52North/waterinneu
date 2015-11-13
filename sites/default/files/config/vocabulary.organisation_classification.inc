<?php
/**
 * @file
 * vocabulary.organisation_classification.inc
 */

$api = '2.0.0';

$data = (object) array(
  'vid' => '8',
  'name' => 'Organisation Classification',
  'machine_name' => 'organisation_classification',
  'description' => 'Classification of an organiziation',
  'hierarchy' => '0',
  'module' => 'taxonomy',
  'weight' => '0',
  'language' => 'und',
  'i18n_mode' => '1',
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
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'taxonomy',
);
