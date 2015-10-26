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
class KeywordTermMigration extends N52Migration {
	public function __construct($arguments) {
		parent::__construct($arguments);

		$this->description = t('Migrate Keywords.');

		//
		// SOURCE
		//
		$columns = array (
				0 => array ('Keyword', t('Keyword (English)')),
		);
		$options = array ('header_rows' => 1);
		$path = DRUPAL_ROOT . '/' .
				drupal_get_path('module', 'n52_migrate_waterinneu')	.
				'/csv_files/keywords.csv';

		$this->source = new MigrateSourceCSV($path, $columns, $options);

		//
		// Destination
		//
		$this->destination = new MigrateDestinationTerm('tags');

		//
		// MAPPING
		//
		$source_key = array (
				'Keyword' => array (
						'type' => 'varchar',
						'not null' => TRUE,
						'length' => 255,
						'description' => t('Textual Identifier of a Keyword term'),
				)
		);

		$destination_key = MigrateDestinationTerm::getKeySchema();
		$machine_name = $this->machineName;

		$this->map = new MigrateSQLMap($machine_name, $source_key, $destination_key);

		$this->addFieldMapping('name', 'Keyword')
		->description(t('The keyword in English.'))
		->issueGroup(t('Done'));
		
		$this->addUnmigratedDestinations(array (
			'parent',
			'parent_name',
			'format',
			'weight',
			'description',
			'path',
			'pathauto',
		));
	}
}