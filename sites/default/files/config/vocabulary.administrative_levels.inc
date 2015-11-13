<?php
/**
 * @file
 * vocabulary.administrative_levels.inc
 */

$api = '2.0.0';

$data = (object) array(
  'vid' => '10',
  'name' => 'Administrative Levels',
  'machine_name' => 'administrative_levels',
  'description' => '',
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
