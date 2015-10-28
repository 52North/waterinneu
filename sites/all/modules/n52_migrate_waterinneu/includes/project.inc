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

	public function __construct($arguments) {
		parent::__construct($arguments);
		
// 		$domains = variable_get('link_extra_domains');
// 		$merged_domains = array_unique(array_merge($domains,array('media','wales')));
// 		variable_set('link_extra_domains', $merged_domains);
			
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
				28 => array ('Company names', t(''))
		);
		$options = array ('header_rows' => 1);
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
				'Code' => array (
						'type' => 'varchar',
						'not null' => TRUE,
						'legnth' => TRUE,
						'description' => t('Name as identifier of the Project in the Inventory'),
				)
					
		);
		$destination_key = MigrateDestinationNode::getKeySchema();
		$machine_name = $this->machineName;

		$this->map = new MigrateSQLMap($machine_name, $source_key, $destination_key);
		
		$this->addUnmigratedSources(array ('Partners from', 'Aggr. level', 'Data coll.', 'Project', 'Companies'));
		
		$this->addUnmigratedDestinations(array (
			'path',
			'pathauto',
			'comment'
		));
	}
}