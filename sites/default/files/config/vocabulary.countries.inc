<?php
/**
 * @file
 * vocabulary.countries.inc
 */

$api = '2.0.0';

$data = (object) array(
  'vid' => '4',
  'name' => 'Countries',
  'machine_name' => 'countries',
  'description' => 'Country Names groupe by continent',
  'hierarchy' => '1',
  'module' => 'taxonomy',
  'weight' => '0',
  'language' => 'und',
  'i18n_mode' => '4',
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
