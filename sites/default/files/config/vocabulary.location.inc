<?php
/**
 * @file
 * vocabulary.location.inc
 */

$api = '2.0.0';

$data = (object) array(
  'vid' => '9',
  'name' => 'Location',
  'machine_name' => 'location',
  'description' => 'Textual description of the location a project was performed at.',
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
