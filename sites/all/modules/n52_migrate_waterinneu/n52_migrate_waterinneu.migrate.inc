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
// TODO use orga code for referencing -> use sourceMigration in Projekt-Migration
function n52_migrate_waterinneu_migrate_api() {
 	$api = array (
 		'api' => 2,
 		'groups' => array (
			'waterinneu' => array (
				'title' => t('WaterInnEU'),
			),
 		),
 		'migrations' => array (
 			'Countries' => array (
				'class_name' => 'CountryTermMigration',
 				'group_name' => 'waterinneu',
 			),
 			'Keywords' => array (
 				'class_name' => 'KeywordTermMigration',
 				'group_name' => 'waterinneu',
 			),
 			'Organisations' => array (
 				'class_name' => 'OrganisationMigration',
 				'group_name' => 'waterinneu',
 				'soft_dependencies' => array ('Countries', 'Keywords'), 
 			),
 			'Projects' => array (
 				'class_name' => 'ProjectMigration',
 				'group_name' => 'waterinneu',
 				'soft_dependencies' => array ('Organisations'),
 			),
 		),
 	);
 	return $api;
}

//
// ROOT for all our migrations
//
abstract class N52Migration extends Migration {
	
	public function __construct($arguments) {
		parent::__construct ( $arguments );
		
		$this->team = array (
				new MigrateTeamMember ( 'Eike Hinderk Jürrens', 'e.h.juerrens@52north.org', t ( 'Product Owner' ) ),
				new MigrateTeamMember ( 'Eike Hinderk Jürrens', 'e.h.juerrens@52north.org', t ( 'Implementor' ) ) 
		);
		
		ini_set ( 'auto_detect_line_endings', TRUE );
	}
}
