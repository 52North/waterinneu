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
class OrganisationMigration extends N52Migration {

	public function __construct($arguments) {
		parent::__construct($arguments);
			
		$this->description =
		t('Migrate organisations from WaterInnEU Inventory');
			
		//
		// SOURCE
		//
		$columns = array (
				// "Source": ('Fieldname', 'Description')
				0 => array ('Code', t('Numeric identifier of the Organisation in the Inventory')),
				1 => array ('Class', t('Classification')),
				2 => array ('Name', t('Organisation Name/Title')),
				3 => array ('Country', t('The name of the home country in English')),
				4 => array ('Country_code', t('2char Country Code ')),
				5 => array ('Homepage', t('Website URL')),
				6 => array ('Keywords', t('String with comma separated keywords')),
		);
		$options = array ('header_rows' => 1);
		$path = DRUPAL_ROOT . '/' .
				drupal_get_path('module', 'n52_migrate_waterinneu')	.
				'/csv_files/organisations.csv';
			
		$this->source = new MigrateSourceCSV($path, $columns, $options);
			
		//
		// DESTINATION
		//
		$this->destination = new MigrateDestinationNode('organisation');
			
		//
		// MAPPING
		//
		$source_key = array (
				'Code' => array (
						'type' => 'int',
						'not null' => TRUE,
						'unsigned' => TRUE,
						'description' => t('Numeric identifier of the Organisation in the Inventory'),
				)
					
		);
		$destination_key = MigrateDestinationNode::getKeySchema();
		$machine_name = $this->machineName;

		$this->map = new MigrateSQLMap($machine_name, $source_key, $destination_key);

		$this->addFieldMapping('language', NULL)
			->description(t('Language is not available in inventory. Set to en by default'))
			->defaultValue('en')
			->issueGroup(t('Done'));
			
		$this->addFieldMapping('field_class', 'Class')
			->description(t('Organisation classification'))
			->issueGroup(t('Done'));
			
		$this->addFieldMapping('title', 'Name')
			->description(t('Incoming "Name" is mapped to drupal "title"'))
			->issueGroup(t('Done'));

		$this->addFieldMapping('field_country_term', 'Country')
			->description(t('English name of the home country of the organisation.'))
			->issueGroup(t('Done'));

		$this->addFieldMapping('field_country_term:create_term')
			->defaultValue(true);
		
		$this->addFieldMapping('field_country_term:ignore_case')
			->defaultValue(true);

		$this->addFieldMapping('field_tags', 'Keywords')
			->separator(",")
			->description(t('Keywords like tags for the organisation.'))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_website', 'Homepage')
			->description(t('Homepage-URL of the organisation'))
			->issueGroup(t('Implementor Issues'));
		
		$this->addFieldMapping('field_website:title', NULL)
			->defaultValue(t('Website'))
			->issueGroup(t('Done'));

		$this->addFieldMapping('field_code', 'Code')
			->description(t('Inventory internal ID used for linking projects with organisations.'))
			->issueGroup(t('Done'));
		
		$this->addUnmigratedSources(array ('Country_code'));
		
		$this->addUnmigratedDestinations(array (
			'uid',
			'created',
			'changed',
			'status',
			'promote',
			'sticky',
			'revision',
			'log',
			'tnid',
			'translate',
			'revision_uid',
			'is_new',
			'field_tags:source_type',
			'field_tags:create_term',
			'field_tags:ignore_case',
			'field_type',
			'field_website:attributes',
			'field_website:language',
			'field_portals',
			'field_projects',
			'field_country_term:source_type',
			'path',
			'pathauto',
			'comment'
		));
	}
}