<?php

/**
 * @file
 * A basic example of using the Migrate module to import taxonomy, users, nodes,
 * and comments.
 *
 * The basic idea is
 * - The users in the source application are listed in the
 *   migrate_example_beer_account table and are transformed into Drupal users.
 * - Drupal "beer" nodes describe beers; The information to create the nodes
 *   comes from the migrate_example_beer_node table.
 * - Taxonomy terms for the beer nodes (ale, pilsner) come from the
 *   migrate_example_beer_topic table and they are applied to nodes using the
 *   source information in the migrate_example_beer_topic_node table.
 * - Comments to be attached to the beer nodes are described in the source
 *   migrate_example_beer_comment table.
 *
 * We will use the Migrate API to import and transform this data and turn it
 * into a working Drupal site.
 */

/**
 * To define a migration process from a set of source data to a particular
 * kind of Drupal object (for example, a specific node type), you define
 * a class derived from Migration. You must define a constructor to initialize
 * your migration object.
 *
 * For your classes to be instantiated so they can be used to import content,
 * you must register them - look at migrate_example.migrate.inc to see how
 * registration works. Right now, it's important to understand that each
 * migration will have a unique "machine name", which is displayed in the UI
 * and is used to reference the migration in drush commands.
 *
 * In any serious migration project, you will find there are some options
 * which are common to the individual migrations you're implementing. You can
 * define an abstract intermediate class derived from Migration, then derive your
 * individual migrations from that, to share settings, utility functions, etc.
 */
abstract class N52WaterInnEUMigration extends Migration {
  // A Migration constructor takes an array of arguments as its first parameter.
  // The arguments must be passed through to the parent constructor.
  public function __construct($arguments) {
    parent::__construct($arguments);

    // With migrate_ui enabled, migration pages will indicate people involved in
    // the particular migration, with their role and contact info. We default the
    // list in the shared class; it can be overridden for specific migrations.
    $this->team = array(
      new MigrateTeamMember('Eike Hinderk Jürrens', 'e.h.juerrens@52north.org',
                            t('Product Owner')),
      new MigrateTeamMember('Eike Hinderk Jürrens', 'e.h.juerrens@52north.org',
                            t('Implementor')),
    );

    // Individual mappings in a migration can be linked to a ticket or issue
    // in an external tracking system. Define the URL pattern here in the shared
    // class with ':id:' representing the position of the issue number, then add
    // ->issueNumber(1234) to a mapping.
    // $this->issuePattern = 'http://drupal.org/node/:id:';
  }
}

// TODO add country terms
// TODO use country terms for referencing
// TODO use orga code for referencing

 class WaterInnEUOrganisationMigration extends N52WaterInnEUMigration {
 	public function __construct($arguments) {
 		parent::__construct($arguments);
 		
 		$this->description = 
 			t('Migrate organisations from WaterInnEU Inventory');
 		ini_set('auto_detect_line_endings', TRUE);
 		
 		//
 		// SOURCE
 		//
 		$columns = array (
 			// "Source": ('Fieldname', 'Description')
 			0 => array ('Code'), t('Numeric identifier of the Organisation in the Inventory'),
 			1 => array ('Name', t('Organisation Name/Title')),
 			2 => array ('Class', t('Classification')),
 			3 => array ('Country', t('2char Country Code ')),
 			4 => array ('Website', t('Website URL')),
 			5 => array ('Keywords', t('String with comma separated keywords')),
 		);
 		$options = array ( 'header_rows' => 1 );
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
 			->description(t('Language is not available in inventory'))
 			->issueGroup(t('DNM'));
 		
 		$this->addFieldMapping('field_class', 'Class')
 			->description(t('Organisation classification'))
 			->issueGroup(t('Done'));
 		
		$this->addFieldMapping('title', 'Name')
			->description(t('Incoming "Name" is mapped to drupal "title"'))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_country_term', NULL)
			->description(t('English name of the home country of the organisation. ' .
					'Missing workflow to use value from country code to name map.'))
			->issueGroup(t('Implementor Issues'));
		
		$this->addFieldMapping('field_country', 'Country')
			->description(t('Two char country code.'))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_tags', 'Keywords')
			->separator(",")
			->description(t('Keywords like tags for the organisation.'))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_type', NULL)
			->description(t('The type of organisation. Currently: Company, Research Institute, or NGO.'))
			->issueGroup(t('DNM'));
		
		$this->addFieldMapping('field_website:URL','Website')
			->description(t('The URL of the organization homepage'))
			->issueGroup(t('Done'));
		$this->addFieldMapping('field_website:Title')
			->defaultValue(t('Website'))
			->issueGroup(t('Done'));
		
		$this->addFieldMapping('field_portals', NULL)
			->description(t('The portals that contain data from/about/linked with this organisation.'))
			->issueGroup(t('DNM'));
		
		$this->addFieldMapping('field_projects', NULL)
			->description(t('The projects this organisation is involved in.' . 
				' Not mapped because the data is not available atm.'))
			->issueGroup(t('DNM'));
		
		$this->addFieldMapping('path', NULL)
			->description(t('URL of the node. Should be generated after import for all nodes.'))
			->issueGroup(t('DNM'));
		
		$this->addFieldMapping('field_code', 'Code')
			->description(t('Inventory internal ID used for linking projects with organisations.'))
			->issueGroup(t('Done'));
 	}
 }