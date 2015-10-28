<?php
/*
 * Copyright (C) 2015
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation.
 * 
 * If the program is linked with libraries which are licensed under one of
 * the following licenses, the combination of the program with the linked
 * library is not considered a "derivative work" of the program:
 * 
 *     - Apache License, version 2.0
 *     - Apache Software License, version 1.0
 *     - GNU Lesser General Public License, version 3
 *     - Mozilla Public License, versions 1.0, 1.1 and 2.0
 *     - Common Development and Distribution License (CDDL), version 1.0
 * 
 * Therefore the distribution of the program linked with libraries licensed
 * under the aforementioned licenses, is permitted by the copyright holders
 * if the distribution is compliant with both the GNU General Public
 * License version 2 and the aforementioned licenses.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 */
class ProjectMigration extends N52Migration {
	
	public function handleSourceMigration($source_migrations, $source_keys, $default = NULL, $migration = NULL) {
		// should return any aaray of destination ids
		if (in_array(null, $source_keys)) {
			return array ();
		}
		$query = new EntityFieldQuery();
		$result = $query->entityCondition('entity_type', 'node')
		->entityCondition('bundle', 'organisation')
		->execute();
		$nodes = node_load_multiple(array_keys($result['node']));
		// get all nodes of type organisation and filter by name
		// return node id
		$result = array ();
		foreach ($nodes as &$node) {
			foreach ($source_keys as &$company_title) {
				$title = $node->title;
				$company_title;
				if (strpos($title, $company_title) > -1) {
					$result[] = $node->nid;
				}
			}
		}
		$i = 42;
		return $result;
	}

	public function __construct($arguments) {
		parent::__construct($arguments);
		
// 		$domains = variable_get('link_extra_domains');
// 		$merged_domains = array_unique(array_merge($domains,array('media','wales')));
// 		variable_set('link_extra_domains', $merged_domains);

// 		$vocabularies = taxonomy_get_vocabularies();
		// 1 = tags
		// 9 = location
// 		$tags = taxonomy_get_tree(9);
		
// 		foreach ($tags as &$tag) {
// 			if (strpos($tag->name,",")) {
// 				// tag name contains "," => remove it
// 				taxonomy_term_delete($tag->tid);
// 			}
// 		}
			
		$this->description =
			t('Migrate projects from WaterInnEU Inventory');
			
		//
		// SOURCE
		//
		$columns = array (
				// "Source": ('Fieldname', 'Description')
				0 => array ('Name', t('Project Name/Title')),
				1 => array ('URL', t('')),
				2 => array ('Partners from', t('')),
				3 => array ('Partners_from_country_names', t('')),
				4 => array ('Location', t('')),
				5 => array ('bbox', t('')),
				6 => array ('Administrative Aggregation Level', t('')),
				7 => array ('Hydrological Aggregation Level', t('')),
				8 => array ('Aggr. level', t('')),
				9 => array ('Administrative Data Collection', t('')),
				10 => array ('Hydrological Data Collection', t('')),
				11 => array ('Data coll.', t('')),
				12 => array ('End date', t('')),
				13 => array ('Report', t('')),
				14 => array ('Raw data', t('')),
				15 => array ('Metadata level', t('')),
				16 => array ('Project', t('')),
				17 => array ('Hardware', t('')),
				18 => array ('Softw./appl.', t('')),
				19 => array ('Model', t('')),
				20 => array ('Pol./Guide', t('')),
				21 => array ('Meas. data', t('')),
				22 => array ('Model data', t('')),
				23 => array ('Admin. data', t('')),
				24 => array ('Keywords', t('')),
				25 => array ('Approach', t('')),
				26 => array ('Comments', t('')),
				27 => array ('Companies', t('')),
				28 => array ('Company names', t('')),
		);
		$options = array (
			'header_rows' => 1,
			'escape' => '\\',
			'enclosure' => '|',
			'delimter' => ',',
		);
		$path = DRUPAL_ROOT . '/' .
			drupal_get_path('module', 'n52_migrate_waterinneu')	.
			'/csv_files/projects.csv';
			
		$this->source = new MigrateSourceCSV($path, $columns, $options);
			
		//
		// DESTINATION
		//
		$this->destination = new MigrateDestinationNode('project');
			
		//
		// MAPPING
		//
		$source_key = array (
				'Name' => array (
						'type' => 'varchar',
						'not null' => TRUE,
						'length' => 255,
						'description' => t('Name as identifier of the Project in the Inventory.'),
				)
					
		);
		$destination_key = MigrateDestinationNode::getKeySchema();
		$machine_name = $this->machineName;

		$this->map = new MigrateSQLMap($machine_name, $source_key, $destination_key);
		
		$this->addFieldMapping('title','Name')
			->description(t(''))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_website', 'URL')
			->description(t('Homepage-URL of the project'))
			->issueGroup(t('Done'));
		$this->addFieldMapping('field_website:title', NULL)
			->defaultValue(t('Website'))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_partners_countries_of_orig','Partners_from_country_names')
			->separator(",")
			->description(t(''))
			->issueGroup(t('Done'));
		$this->addFieldMapping('field_partners_countries_of_orig:create_term')
			->defaultValue(TRUE)
			->issueGroup(t('Done'));
		$this->addFieldMapping('field_partners_countries_of_orig:ignore_case')
			->defaultValue(TRUE)
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_location','Location')
			->separator(",")
			->description(t(''))
			->issueGroup(t('Done'));
		$this->addFieldMapping('field_location:create_term')
			->defaultValue(TRUE)
			->issueGroup(t('Done'));
		$this->addFieldMapping('field_location:ignore_case')
			->defaultValue(TRUE)
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_bounding_box','bbox')
			->description(t(''))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_administrative_aggregation','Administrative Aggregation Level')
			->description(t(''))
			->issueGroup(t('Done'));
		$this->addFieldMapping('field_administrative_aggregation:create_term')
			->defaultValue(TRUE)
			->issueGroup(t('Done'));
		$this->addFieldMapping('field_administrative_aggregation:ignore_case')
			->defaultValue(TRUE)
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_hydrolocagical_aggregation','Hydrological Aggregation Level')
			->description(t(''))
			->issueGroup(t('Done'));
		$this->addFieldMapping('field_hydrolocagical_aggregation:create_term')
			->defaultValue(TRUE)
			->issueGroup(t('Done'));
		$this->addFieldMapping('field_hydrolocagical_aggregation:ignore_case')
			->defaultValue(TRUE)
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_administrative_data_collec','Administrative Data Collection')
			->description(t(''))
			->issueGroup(t('Done'));
		$this->addFieldMapping('field_administrative_data_collec:create_term')
			->defaultValue(TRUE)
			->issueGroup(t('Done'));
		$this->addFieldMapping('field_administrative_data_collec:ignore_case')
			->defaultValue(TRUE)
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_hydrological_data_collecti','Hydrological Data Collection')
			->description(t(''))
			->issueGroup(t('Done'));
		$this->addFieldMapping('field_hydrological_data_collecti:create_term')
			->defaultValue(TRUE)
			->issueGroup(t('Done'));
		$this->addFieldMapping('field_hydrological_data_collecti:ignore_case')
			->defaultValue(TRUE)
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_end_date','End date')
			->description(t(''))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_report_available_','Report')
			->description(t(''))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_raw_data','Raw data')
			->description(t(''))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_metadata_level','Metadata level')
			->description(t(''))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_hardware','Hardware')
			->description(t(''))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_software','Softw./appl.')
			->description(t(''))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_model','Model')
			->description(t(''))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_policy_brief','Pol./Guide')
			->description(t(''))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_guideline','Pol./Guide')
		->description(t(''))
		->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_observation_data','Meas. data')
			->description(t(''))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_model_data','Model data')
			->description(t(''))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_administrative_data','Admin. data')
			->description(t(''))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_tags','Keywords')
			->separator(",")
			->description(t(''))
			->issueGroup(t('Done'));
		$this->addFieldMapping('field_tags:create_term')
			->defaultValue(TRUE)
			->issueGroup(t('Done'));
		$this->addFieldMapping('field_tags:ignore_case')
			->defaultValue(TRUE)
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_approach','Approach')
			->description(t(''))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_comments','Comments')
			->description(t(''))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_organisations','Company names')
			->separator(",")
			->sourceMigration('Organisations')
			->description(t(''))
			->issueGroup(t('Done'));
		
		$this->addUnmigratedSources(array ('Partners from', 'Aggr. level', 'Data coll.', 'Project', 'Companies'));
		
		$this->addUnmigratedDestinations(array (
            'changed',
            'comment',
            'created',
            'field_administrative_aggregation:source_type',
            'field_administrative_data_collec:source_type',
            'field_bounding_box:bottom',
            'field_bounding_box:geo_type',
            'field_bounding_box:geohash',
            'field_bounding_box:lat',
            'field_bounding_box:left',
            'field_bounding_box:lon',
            'field_bounding_box:right',
            'field_bounding_box:top',
            'field_end_date:rrule',
            'field_end_date:timezone',
            'field_end_date:to',
            'field_hydrolocagical_aggregation:source_type',
            'field_hydrological_data_collecti:source_type',
            'field_location:source_type',
            'field_logo',
            'field_logo:alt',
            'field_logo:destination_dir',
            'field_logo:destination_file',
            'field_logo:file_class',
            'field_logo:file_replace',
            'field_logo:preserve_files',
            'field_logo:source_dir',
            'field_logo:title',
            'field_logo:urlencode',
            'field_partners_countries_of_orig:source_type',
            'field_partners_from',
            'field_published_tools',
            'field_report',
            'field_report:attributes',
            'field_report:language',
            'field_report:title',
            'field_standards_accounted_for',
            'field_standards_accounted_for:create_term',
            'field_standards_accounted_for:ignore_case',
            'field_standards_accounted_for:source_type',
            'field_tags:source_type',
            'field_website:attributes',
            'field_website:language',
            'is_new',
            'language',
            'log',
            'path',
            'pathauto',
            'promote',
            'revision',
            'revision_uid',
            'status',
            'sticky',
            'tnid',
            'translate',
            'uid',
		));
	}
}