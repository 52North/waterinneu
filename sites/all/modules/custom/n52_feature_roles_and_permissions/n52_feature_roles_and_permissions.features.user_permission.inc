<?php
/**
 * @file
 * n52_feature_roles_and_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function n52_feature_roles_and_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'accept translation jobs'.
  $permissions['accept translation jobs'] = array(
    'name' => 'accept translation jobs',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'tmgmt',
  );

  // Exported permission: 'access PDF version'.
  $permissions['access PDF version'] = array(
    'name' => 'access PDF version',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'print_pdf',
  );

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access atjs'.
  $permissions['access atjs'] = array(
    'name' => 'access atjs',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'atjs',
  );

  // Exported permission: 'access backup and migrate'.
  $permissions['access backup and migrate'] = array(
    'name' => 'access backup and migrate',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access backup files'.
  $permissions['access backup files'] = array(
    'name' => 'access backup files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'access harmony admin pages'.
  $permissions['access harmony admin pages'] = array(
    'name' => 'access harmony admin pages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'harmony_core',
  );

  // Exported permission: 'access harmony rebuild actions'.
  $permissions['access harmony rebuild actions'] = array(
    'name' => 'access harmony rebuild actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'harmony_core',
  );

  // Exported permission: 'access news feeds'.
  $permissions['access news feeds'] = array(
    'name' => 'access news feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'aggregator',
  );

  // Exported permission: 'access own authorizations'.
  $permissions['access own authorizations'] = array(
    'name' => 'access own authorizations',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'access own consumers'.
  $permissions['access own consumers'] = array(
    'name' => 'access own consumers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'access print'.
  $permissions['access print'] = array(
    'name' => 'access print',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'print',
  );

  // Exported permission: 'access security review list'.
  $permissions['access security review list'] = array(
    'name' => 'access security review list',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'security_review',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site-wide contact form'.
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access user contact forms'.
  $permissions['access user contact forms'] = array(
    'name' => 'access user contact forms',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'add terms in costs'.
  $permissions['add terms in costs'] = array(
    'name' => 'add terms in costs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in data_discovery_standards'.
  $permissions['add terms in data_discovery_standards'] = array(
    'name' => 'add terms in data_discovery_standards',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in data_downloading_standards'.
  $permissions['add terms in data_downloading_standards'] = array(
    'name' => 'add terms in data_downloading_standards',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in data_encoding_standards'.
  $permissions['add terms in data_encoding_standards'] = array(
    'name' => 'add terms in data_encoding_standards',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in data_visualization_standards'.
  $permissions['add terms in data_visualization_standards'] = array(
    'name' => 'add terms in data_visualization_standards',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in harmony_category'.
  $permissions['add terms in harmony_category'] = array(
    'name' => 'add terms in harmony_category',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in issue'.
  $permissions['add terms in issue'] = array(
    'name' => 'add terms in issue',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in license'.
  $permissions['add terms in license'] = array(
    'name' => 'add terms in license',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in n52_commercial_development'.
  $permissions['add terms in n52_commercial_development'] = array(
    'name' => 'add terms in n52_commercial_development',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in n52_event_categories'.
  $permissions['add terms in n52_event_categories'] = array(
    'name' => 'add terms in n52_event_categories',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in organisation_classification'.
  $permissions['add terms in organisation_classification'] = array(
    'name' => 'add terms in organisation_classification',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in other_standards'.
  $permissions['add terms in other_standards'] = array(
    'name' => 'add terms in other_standards',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in processes_and_models_standards'.
  $permissions['add terms in processes_and_models_standards'] = array(
    'name' => 'add terms in processes_and_models_standards',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in product_categories'.
  $permissions['add terms in product_categories'] = array(
    'name' => 'add terms in product_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in purpose'.
  $permissions['add terms in purpose'] = array(
    'name' => 'add terms in purpose',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in sensor_data_standards'.
  $permissions['add terms in sensor_data_standards'] = array(
    'name' => 'add terms in sensor_data_standards',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in service_categories'.
  $permissions['add terms in service_categories'] = array(
    'name' => 'add terms in service_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in standard_category'.
  $permissions['add terms in standard_category'] = array(
    'name' => 'add terms in standard_category',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in type_of_hardware'.
  $permissions['add terms in type_of_hardware'] = array(
    'name' => 'add terms in type_of_hardware',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in type_of_software'.
  $permissions['add terms in type_of_software'] = array(
    'name' => 'add terms in type_of_software',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in user'.
  $permissions['add terms in user'] = array(
    'name' => 'add terms in user',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in waterbodies'.
  $permissions['add terms in waterbodies'] = array(
    'name' => 'add terms in waterbodies',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add_terms_costs'.
  $permissions['add_terms_costs'] = array(
    'name' => 'add_terms_costs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_data_discovery_standards'.
  $permissions['add_terms_data_discovery_standards'] = array(
    'name' => 'add_terms_data_discovery_standards',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_data_downloading_standards'.
  $permissions['add_terms_data_downloading_standards'] = array(
    'name' => 'add_terms_data_downloading_standards',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_data_encoding_standards'.
  $permissions['add_terms_data_encoding_standards'] = array(
    'name' => 'add_terms_data_encoding_standards',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_data_visualization_standards'.
  $permissions['add_terms_data_visualization_standards'] = array(
    'name' => 'add_terms_data_visualization_standards',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_harmony_category'.
  $permissions['add_terms_harmony_category'] = array(
    'name' => 'add_terms_harmony_category',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_issue'.
  $permissions['add_terms_issue'] = array(
    'name' => 'add_terms_issue',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_license'.
  $permissions['add_terms_license'] = array(
    'name' => 'add_terms_license',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_n52_commercial_development'.
  $permissions['add_terms_n52_commercial_development'] = array(
    'name' => 'add_terms_n52_commercial_development',
    'roles' => array(),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_n52_event_categories'.
  $permissions['add_terms_n52_event_categories'] = array(
    'name' => 'add_terms_n52_event_categories',
    'roles' => array(),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_organisation_classification'.
  $permissions['add_terms_organisation_classification'] = array(
    'name' => 'add_terms_organisation_classification',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_other_standards'.
  $permissions['add_terms_other_standards'] = array(
    'name' => 'add_terms_other_standards',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_processes_and_models_standards'.
  $permissions['add_terms_processes_and_models_standards'] = array(
    'name' => 'add_terms_processes_and_models_standards',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_product_categories'.
  $permissions['add_terms_product_categories'] = array(
    'name' => 'add_terms_product_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_purpose'.
  $permissions['add_terms_purpose'] = array(
    'name' => 'add_terms_purpose',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_sensor_data_standards'.
  $permissions['add_terms_sensor_data_standards'] = array(
    'name' => 'add_terms_sensor_data_standards',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_service_categories'.
  $permissions['add_terms_service_categories'] = array(
    'name' => 'add_terms_service_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_standard_category'.
  $permissions['add_terms_standard_category'] = array(
    'name' => 'add_terms_standard_category',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_type_of_hardware'.
  $permissions['add_terms_type_of_hardware'] = array(
    'name' => 'add_terms_type_of_hardware',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_type_of_software'.
  $permissions['add_terms_type_of_software'] = array(
    'name' => 'add_terms_type_of_software',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_user'.
  $permissions['add_terms_user'] = array(
    'name' => 'add_terms_user',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'add_terms_waterbodies'.
  $permissions['add_terms_waterbodies'] = array(
    'name' => 'add_terms_waterbodies',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_autocomplete_permission',
  );

  // Exported permission: 'administer CAPTCHA settings'.
  $permissions['administer CAPTCHA settings'] = array(
    'name' => 'administer CAPTCHA settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'captcha',
  );

  // Exported permission: 'administer EU Cookie Compliance popup'.
  $permissions['administer EU Cookie Compliance popup'] = array(
    'name' => 'administer EU Cookie Compliance popup',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eu_cookie_compliance',
  );

  // Exported permission: 'administer Search Autocomplete'.
  $permissions['administer Search Autocomplete'] = array(
    'name' => 'administer Search Autocomplete',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_autocomplete',
  );

  // Exported permission: 'administer Terms and Conditions'.
  $permissions['administer Terms and Conditions'] = array(
    'name' => 'administer Terms and Conditions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'legal',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer atjs'.
  $permissions['administer atjs'] = array(
    'name' => 'administer atjs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'atjs',
  );

  // Exported permission: 'administer backup and migrate'.
  $permissions['administer backup and migrate'] = array(
    'name' => 'administer backup and migrate',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer consumers'.
  $permissions['administer consumers'] = array(
    'name' => 'administer consumers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'administer contact forms'.
  $permissions['administer contact forms'] = array(
    'name' => 'administer contact forms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer contexts'.
  $permissions['administer contexts'] = array(
    'name' => 'administer contexts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'administer custom search'.
  $permissions['administer custom search'] = array(
    'name' => 'administer custom search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'custom_search',
  );

  // Exported permission: 'administer custom search blocks'.
  $permissions['administer custom search blocks'] = array(
    'name' => 'administer custom search blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'custom_search_blocks',
  );

  // Exported permission: 'administer date tools'.
  $permissions['administer date tools'] = array(
    'name' => 'administer date tools',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'date_tools',
  );

  // Exported permission: 'administer dependencies'.
  $permissions['administer dependencies'] = array(
    'name' => 'administer dependencies',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'conditional_fields',
  );

  // Exported permission: 'administer entity quote'.
  $permissions['administer entity quote'] = array(
    'name' => 'administer entity quote',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_quote',
  );

  // Exported permission: 'administer entity translation'.
  $permissions['administer entity translation'] = array(
    'name' => 'administer entity translation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'administer entity view modes'.
  $permissions['administer entity view modes'] = array(
    'name' => 'administer entity view modes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_view_mode',
  );

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'facetapi',
  );

  // Exported permission: 'administer faq'.
  $permissions['administer faq'] = array(
    'name' => 'administer faq',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'faq',
  );

  // Exported permission: 'administer faq order'.
  $permissions['administer faq order'] = array(
    'name' => 'administer faq order',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'faq',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer fields'.
  $permissions['administer fields'] = array(
    'name' => 'administer fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'administer freelinking'.
  $permissions['administer freelinking'] = array(
    'name' => 'administer freelinking',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'freelinking',
  );

  // Exported permission: 'administer harmony_access settings'.
  $permissions['administer harmony_access settings'] = array(
    'name' => 'administer harmony_access settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'harmony_access',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer imce'.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'imce',
  );

  // Exported permission: 'administer language fallback'.
  $permissions['administer language fallback'] = array(
    'name' => 'administer language fallback',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'language_fallback',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'administer linkit'.
  $permissions['administer linkit'] = array(
    'name' => 'administer linkit',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'linkit',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer mini panels'.
  $permissions['administer mini panels'] = array(
    'name' => 'administer mini panels',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer news feeds'.
  $permissions['administer news feeds'] = array(
    'name' => 'administer news feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'aggregator',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer oauth'.
  $permissions['administer oauth'] = array(
    'name' => 'administer oauth',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panel-nodes'.
  $permissions['administer panel-nodes'] = array(
    'name' => 'administer panel-nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer print'.
  $permissions['administer print'] = array(
    'name' => 'administer print',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'print',
  );

  // Exported permission: 'administer profiler builder'.
  $permissions['administer profiler builder'] = array(
    'name' => 'administer profiler builder',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'profiler_builder',
  );

  // Exported permission: 'administer recaptcha'.
  $permissions['administer recaptcha'] = array(
    'name' => 'administer recaptcha',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'recaptcha',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api',
  );

  // Exported permission: 'administer services'.
  $permissions['administer services'] = array(
    'name' => 'administer services',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer smtp module'.
  $permissions['administer smtp module'] = array(
    'name' => 'administer smtp module',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'smtp',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer stickynav'.
  $permissions['administer stickynav'] = array(
    'name' => 'administer stickynav',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'stickynav',
  );

  // Exported permission: 'administer superfish'.
  $permissions['administer superfish'] = array(
    'name' => 'administer superfish',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'superfish',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer taxonomy display'.
  $permissions['administer taxonomy display'] = array(
    'name' => 'administer taxonomy display',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_display',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer tmgmt'.
  $permissions['administer tmgmt'] = array(
    'name' => 'administer tmgmt',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'tmgmt',
  );

  // Exported permission: 'administer translation tasks'.
  $permissions['administer translation tasks'] = array(
    'name' => 'administer translation tasks',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'tmgmt_local',
  );

  // Exported permission: 'administer twitter block'.
  $permissions['administer twitter block'] = array(
    'name' => 'administer twitter block',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'twitter_block',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'advanced migration information'.
  $permissions['advanced migration information'] = array(
    'name' => 'advanced migration information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'migrate',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'context ajax block access'.
  $permissions['context ajax block access'] = array(
    'name' => 'context ajax block access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create event content'.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create faq content'.
  $permissions['create faq content'] = array(
    'name' => 'create faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create mini panels'.
  $permissions['create mini panels'] = array(
    'name' => 'create mini panels',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: 'create n52_sucess_story content'.
  $permissions['create n52_sucess_story content'] = array(
    'name' => 'create n52_sucess_story content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create organisation content'.
  $permissions['create organisation content'] = array(
    'name' => 'create organisation content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create panel content'.
  $permissions['create panel content'] = array(
    'name' => 'create panel content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create project content'.
  $permissions['create project content'] = array(
    'name' => 'create project content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create service_offering content'.
  $permissions['create service_offering content'] = array(
    'name' => 'create service_offering content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create service_request content'.
  $permissions['create service_request content'] = array(
    'name' => 'create service_request content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create translation jobs'.
  $permissions['create translation jobs'] = array(
    'name' => 'create translation jobs',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'tmgmt',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any event content'.
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any faq content'.
  $permissions['delete any faq content'] = array(
    'name' => 'delete any faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any n52_sucess_story content'.
  $permissions['delete any n52_sucess_story content'] = array(
    'name' => 'delete any n52_sucess_story content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any organisation content'.
  $permissions['delete any organisation content'] = array(
    'name' => 'delete any organisation content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any panel content'.
  $permissions['delete any panel content'] = array(
    'name' => 'delete any panel content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any project content'.
  $permissions['delete any project content'] = array(
    'name' => 'delete any project content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any service_offering content'.
  $permissions['delete any service_offering content'] = array(
    'name' => 'delete any service_offering content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any service_request content'.
  $permissions['delete any service_request content'] = array(
    'name' => 'delete any service_request content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete backup files'.
  $permissions['delete backup files'] = array(
    'name' => 'delete backup files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own event content'.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own faq content'.
  $permissions['delete own faq content'] = array(
    'name' => 'delete own faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own n52_sucess_story content'.
  $permissions['delete own n52_sucess_story content'] = array(
    'name' => 'delete own n52_sucess_story content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own organisation content'.
  $permissions['delete own organisation content'] = array(
    'name' => 'delete own organisation content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own panel content'.
  $permissions['delete own panel content'] = array(
    'name' => 'delete own panel content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own project content'.
  $permissions['delete own project content'] = array(
    'name' => 'delete own project content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own service_offering content'.
  $permissions['delete own service_offering content'] = array(
    'name' => 'delete own service_offering content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own service_request content'.
  $permissions['delete own service_request content'] = array(
    'name' => 'delete own service_request content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in costs'.
  $permissions['delete terms in costs'] = array(
    'name' => 'delete terms in costs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in data_discovery_standards'.
  $permissions['delete terms in data_discovery_standards'] = array(
    'name' => 'delete terms in data_discovery_standards',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in data_downloading_standards'.
  $permissions['delete terms in data_downloading_standards'] = array(
    'name' => 'delete terms in data_downloading_standards',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in data_encoding_standards'.
  $permissions['delete terms in data_encoding_standards'] = array(
    'name' => 'delete terms in data_encoding_standards',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in data_visualization_standards'.
  $permissions['delete terms in data_visualization_standards'] = array(
    'name' => 'delete terms in data_visualization_standards',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in harmony_category'.
  $permissions['delete terms in harmony_category'] = array(
    'name' => 'delete terms in harmony_category',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in issue'.
  $permissions['delete terms in issue'] = array(
    'name' => 'delete terms in issue',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in license'.
  $permissions['delete terms in license'] = array(
    'name' => 'delete terms in license',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in n52_commercial_development'.
  $permissions['delete terms in n52_commercial_development'] = array(
    'name' => 'delete terms in n52_commercial_development',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in n52_event_categories'.
  $permissions['delete terms in n52_event_categories'] = array(
    'name' => 'delete terms in n52_event_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in organisation_classification'.
  $permissions['delete terms in organisation_classification'] = array(
    'name' => 'delete terms in organisation_classification',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in other_standards'.
  $permissions['delete terms in other_standards'] = array(
    'name' => 'delete terms in other_standards',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in processes_and_models_standards'.
  $permissions['delete terms in processes_and_models_standards'] = array(
    'name' => 'delete terms in processes_and_models_standards',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in product_categories'.
  $permissions['delete terms in product_categories'] = array(
    'name' => 'delete terms in product_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in purpose'.
  $permissions['delete terms in purpose'] = array(
    'name' => 'delete terms in purpose',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in sensor_data_standards'.
  $permissions['delete terms in sensor_data_standards'] = array(
    'name' => 'delete terms in sensor_data_standards',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in service_categories'.
  $permissions['delete terms in service_categories'] = array(
    'name' => 'delete terms in service_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in standard_category'.
  $permissions['delete terms in standard_category'] = array(
    'name' => 'delete terms in standard_category',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in type_of_hardware'.
  $permissions['delete terms in type_of_hardware'] = array(
    'name' => 'delete terms in type_of_hardware',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in type_of_software'.
  $permissions['delete terms in type_of_software'] = array(
    'name' => 'delete terms in type_of_software',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in user'.
  $permissions['delete terms in user'] = array(
    'name' => 'delete terms in user',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in waterbodies'.
  $permissions['delete terms in waterbodies'] = array(
    'name' => 'delete terms in waterbodies',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'disable new harmony content'.
  $permissions['disable new harmony content'] = array(
    'name' => 'disable new harmony content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'harmony_core',
  );

  // Exported permission: 'display EU Cookie Compliance popup'.
  $permissions['display EU Cookie Compliance popup'] = array(
    'name' => 'display EU Cookie Compliance popup',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'eu_cookie_compliance',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any event content'.
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any faq content'.
  $permissions['edit any faq content'] = array(
    'name' => 'edit any faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any n52_sucess_story content'.
  $permissions['edit any n52_sucess_story content'] = array(
    'name' => 'edit any n52_sucess_story content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any organisation content'.
  $permissions['edit any organisation content'] = array(
    'name' => 'edit any organisation content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any panel content'.
  $permissions['edit any panel content'] = array(
    'name' => 'edit any panel content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any project content'.
  $permissions['edit any project content'] = array(
    'name' => 'edit any project content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any service_offering content'.
  $permissions['edit any service_offering content'] = array(
    'name' => 'edit any service_offering content',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any service_request content'.
  $permissions['edit any service_request content'] = array(
    'name' => 'edit any service_request content',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own event content'.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own faq content'.
  $permissions['edit own faq content'] = array(
    'name' => 'edit own faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own n52_sucess_story content'.
  $permissions['edit own n52_sucess_story content'] = array(
    'name' => 'edit own n52_sucess_story content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own organisation content'.
  $permissions['edit own organisation content'] = array(
    'name' => 'edit own organisation content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own panel content'.
  $permissions['edit own panel content'] = array(
    'name' => 'edit own panel content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own project content'.
  $permissions['edit own project content'] = array(
    'name' => 'edit own project content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own service_offering content'.
  $permissions['edit own service_offering content'] = array(
    'name' => 'edit own service_offering content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own service_request content'.
  $permissions['edit own service_request content'] = array(
    'name' => 'edit own service_request content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit revisions'.
  $permissions['edit revisions'] = array(
    'name' => 'edit revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'edit terms in costs'.
  $permissions['edit terms in costs'] = array(
    'name' => 'edit terms in costs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in data_discovery_standards'.
  $permissions['edit terms in data_discovery_standards'] = array(
    'name' => 'edit terms in data_discovery_standards',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in data_downloading_standards'.
  $permissions['edit terms in data_downloading_standards'] = array(
    'name' => 'edit terms in data_downloading_standards',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in data_encoding_standards'.
  $permissions['edit terms in data_encoding_standards'] = array(
    'name' => 'edit terms in data_encoding_standards',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in data_visualization_standards'.
  $permissions['edit terms in data_visualization_standards'] = array(
    'name' => 'edit terms in data_visualization_standards',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in harmony_category'.
  $permissions['edit terms in harmony_category'] = array(
    'name' => 'edit terms in harmony_category',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in issue'.
  $permissions['edit terms in issue'] = array(
    'name' => 'edit terms in issue',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in license'.
  $permissions['edit terms in license'] = array(
    'name' => 'edit terms in license',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in n52_commercial_development'.
  $permissions['edit terms in n52_commercial_development'] = array(
    'name' => 'edit terms in n52_commercial_development',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in n52_event_categories'.
  $permissions['edit terms in n52_event_categories'] = array(
    'name' => 'edit terms in n52_event_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in organisation_classification'.
  $permissions['edit terms in organisation_classification'] = array(
    'name' => 'edit terms in organisation_classification',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in other_standards'.
  $permissions['edit terms in other_standards'] = array(
    'name' => 'edit terms in other_standards',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in processes_and_models_standards'.
  $permissions['edit terms in processes_and_models_standards'] = array(
    'name' => 'edit terms in processes_and_models_standards',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in product_categories'.
  $permissions['edit terms in product_categories'] = array(
    'name' => 'edit terms in product_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in purpose'.
  $permissions['edit terms in purpose'] = array(
    'name' => 'edit terms in purpose',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in sensor_data_standards'.
  $permissions['edit terms in sensor_data_standards'] = array(
    'name' => 'edit terms in sensor_data_standards',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in service_categories'.
  $permissions['edit terms in service_categories'] = array(
    'name' => 'edit terms in service_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in standard_category'.
  $permissions['edit terms in standard_category'] = array(
    'name' => 'edit terms in standard_category',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in type_of_hardware'.
  $permissions['edit terms in type_of_hardware'] = array(
    'name' => 'edit terms in type_of_hardware',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in type_of_software'.
  $permissions['edit terms in type_of_software'] = array(
    'name' => 'edit terms in type_of_software',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in user'.
  $permissions['edit terms in user'] = array(
    'name' => 'edit terms in user',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in waterbodies'.
  $permissions['edit terms in waterbodies'] = array(
    'name' => 'edit terms in waterbodies',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'get a system variable'.
  $permissions['get a system variable'] = array(
    'name' => 'get a system variable',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get any binary files'.
  $permissions['get any binary files'] = array(
    'name' => 'get any binary files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get own binary files'.
  $permissions['get own binary files'] = array(
    'name' => 'get own binary files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'manage bg translation overview priorities'.
  $permissions['manage bg translation overview priorities'] = array(
    'name' => 'manage bg translation overview priorities',
    'roles' => array(),
    'module' => 'translation_overview',
  );

  // Exported permission: 'manage de translation overview priorities'.
  $permissions['manage de translation overview priorities'] = array(
    'name' => 'manage de translation overview priorities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'translation_overview',
  );

  // Exported permission: 'manage en translation overview priorities'.
  $permissions['manage en translation overview priorities'] = array(
    'name' => 'manage en translation overview priorities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'translation_overview',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'merge costs terms'.
  $permissions['merge costs terms'] = array(
    'name' => 'merge costs terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge data_discovery_standards terms'.
  $permissions['merge data_discovery_standards terms'] = array(
    'name' => 'merge data_discovery_standards terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge data_downloading_standards terms'.
  $permissions['merge data_downloading_standards terms'] = array(
    'name' => 'merge data_downloading_standards terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge data_encoding_standards terms'.
  $permissions['merge data_encoding_standards terms'] = array(
    'name' => 'merge data_encoding_standards terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge data_visualization_standards terms'.
  $permissions['merge data_visualization_standards terms'] = array(
    'name' => 'merge data_visualization_standards terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge harmony_category terms'.
  $permissions['merge harmony_category terms'] = array(
    'name' => 'merge harmony_category terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge issue terms'.
  $permissions['merge issue terms'] = array(
    'name' => 'merge issue terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge license terms'.
  $permissions['merge license terms'] = array(
    'name' => 'merge license terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge n52_commercial_development terms'.
  $permissions['merge n52_commercial_development terms'] = array(
    'name' => 'merge n52_commercial_development terms',
    'roles' => array(),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge n52_event_categories terms'.
  $permissions['merge n52_event_categories terms'] = array(
    'name' => 'merge n52_event_categories terms',
    'roles' => array(),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge organisation_classification terms'.
  $permissions['merge organisation_classification terms'] = array(
    'name' => 'merge organisation_classification terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge other_standards terms'.
  $permissions['merge other_standards terms'] = array(
    'name' => 'merge other_standards terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge processes_and_models_standards terms'.
  $permissions['merge processes_and_models_standards terms'] = array(
    'name' => 'merge processes_and_models_standards terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge product_categories terms'.
  $permissions['merge product_categories terms'] = array(
    'name' => 'merge product_categories terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge purpose terms'.
  $permissions['merge purpose terms'] = array(
    'name' => 'merge purpose terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge sensor_data_standards terms'.
  $permissions['merge sensor_data_standards terms'] = array(
    'name' => 'merge sensor_data_standards terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge service_categories terms'.
  $permissions['merge service_categories terms'] = array(
    'name' => 'merge service_categories terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge standard_category terms'.
  $permissions['merge standard_category terms'] = array(
    'name' => 'merge standard_category terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge terms'.
  $permissions['merge terms'] = array(
    'name' => 'merge terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge type_of_hardware terms'.
  $permissions['merge type_of_hardware terms'] = array(
    'name' => 'merge type_of_hardware terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge type_of_software terms'.
  $permissions['merge type_of_software terms'] = array(
    'name' => 'merge type_of_software terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge user terms'.
  $permissions['merge user terms'] = array(
    'name' => 'merge user terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge waterbodies terms'.
  $permissions['merge waterbodies terms'] = array(
    'name' => 'merge waterbodies terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'migration information'.
  $permissions['migration information'] = array(
    'name' => 'migration information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'migrate',
  );

  // Exported permission: 'node-specific print configuration'.
  $permissions['node-specific print configuration'] = array(
    'name' => 'node-specific print configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'print_ui',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'oauth authorize any consumers'.
  $permissions['oauth authorize any consumers'] = array(
    'name' => 'oauth authorize any consumers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'oauth register any consumers'.
  $permissions['oauth register any consumers'] = array(
    'name' => 'oauth register any consumers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'perform backup'.
  $permissions['perform backup'] = array(
    'name' => 'perform backup',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'perform unlimited index queries'.
  $permissions['perform unlimited index queries'] = array(
    'name' => 'perform unlimited index queries',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'provide translation services'.
  $permissions['provide translation services'] = array(
    'name' => 'provide translation services',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'tmgmt_local',
  );

  // Exported permission: 'publish revisions'.
  $permissions['publish revisions'] = array(
    'name' => 'publish revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of any article content'.
  $permissions['publish revisions of any article content'] = array(
    'name' => 'publish revisions of any article content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of any event content'.
  $permissions['publish revisions of any event content'] = array(
    'name' => 'publish revisions of any event content',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of any faq content'.
  $permissions['publish revisions of any faq content'] = array(
    'name' => 'publish revisions of any faq content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of any n52_sucess_story content'.
  $permissions['publish revisions of any n52_sucess_story content'] = array(
    'name' => 'publish revisions of any n52_sucess_story content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of any organisation content'.
  $permissions['publish revisions of any organisation content'] = array(
    'name' => 'publish revisions of any organisation content',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of any page content'.
  $permissions['publish revisions of any page content'] = array(
    'name' => 'publish revisions of any page content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of any project content'.
  $permissions['publish revisions of any project content'] = array(
    'name' => 'publish revisions of any project content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of any service_offering content'.
  $permissions['publish revisions of any service_offering content'] = array(
    'name' => 'publish revisions of any service_offering content',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of any service_request content'.
  $permissions['publish revisions of any service_request content'] = array(
    'name' => 'publish revisions of any service_request content',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of own article content'.
  $permissions['publish revisions of own article content'] = array(
    'name' => 'publish revisions of own article content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of own event content'.
  $permissions['publish revisions of own event content'] = array(
    'name' => 'publish revisions of own event content',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of own faq content'.
  $permissions['publish revisions of own faq content'] = array(
    'name' => 'publish revisions of own faq content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of own n52_sucess_story content'.
  $permissions['publish revisions of own n52_sucess_story content'] = array(
    'name' => 'publish revisions of own n52_sucess_story content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of own organisation content'.
  $permissions['publish revisions of own organisation content'] = array(
    'name' => 'publish revisions of own organisation content',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of own page content'.
  $permissions['publish revisions of own page content'] = array(
    'name' => 'publish revisions of own page content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of own project content'.
  $permissions['publish revisions of own project content'] = array(
    'name' => 'publish revisions of own project content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of own service_offering content'.
  $permissions['publish revisions of own service_offering content'] = array(
    'name' => 'publish revisions of own service_offering content',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of own service_request content'.
  $permissions['publish revisions of own service_request content'] = array(
    'name' => 'publish revisions of own service_request content',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'rebuild harmony_access records'.
  $permissions['rebuild harmony_access records'] = array(
    'name' => 'rebuild harmony_access records',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'harmony_access',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'restore from backup'.
  $permissions['restore from backup'] = array(
    'name' => 'restore from backup',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'run security checks'.
  $permissions['run security checks'] = array(
    'name' => 'run security checks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'security_review',
  );

  // Exported permission: 'save file information'.
  $permissions['save file information'] = array(
    'name' => 'save file information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'set a system variable'.
  $permissions['set a system variable'] = array(
    'name' => 'set a system variable',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'show format selection for comment'.
  $permissions['show format selection for comment'] = array(
    'name' => 'show format selection for comment',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for flagging'.
  $permissions['show format selection for flagging'] = array(
    'name' => 'show format selection for flagging',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for harmony_post'.
  $permissions['show format selection for harmony_post'] = array(
    'name' => 'show format selection for harmony_post',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for harmony_thread'.
  $permissions['show format selection for harmony_thread'] = array(
    'name' => 'show format selection for harmony_thread',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for node'.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for rules_config'.
  $permissions['show format selection for rules_config'] = array(
    'name' => 'show format selection for rules_config',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for taxonomy_term'.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for user'.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format tips'.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show more format tips link'.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'skip CAPTCHA'.
  $permissions['skip CAPTCHA'] = array(
    'name' => 'skip CAPTCHA',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'captcha',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'submit translation jobs'.
  $permissions['submit translation jobs'] = array(
    'name' => 'submit translation jobs',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'tmgmt',
  );

  // Exported permission: 'submit translations to localization server'.
  $permissions['submit translations to localization server'] = array(
    'name' => 'submit translations to localization server',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'l10n_client',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'toggle field translatability'.
  $permissions['toggle field translatability'] = array(
    'name' => 'toggle field translatability',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate admin strings'.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'translate any entity'.
  $permissions['translate any entity'] = array(
    'name' => 'translate any entity',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate comment entities'.
  $permissions['translate comment entities'] = array(
    'name' => 'translate comment entities',
    'roles' => array(),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate content'.
  $permissions['translate content'] = array(
    'name' => 'translate content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'translation',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'translate node entities'.
  $permissions['translate node entities'] = array(
    'name' => 'translate node entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate taxonomy_term entities'.
  $permissions['translate taxonomy_term entities'] = array(
    'name' => 'translate taxonomy_term entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate user-defined strings'.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'unpublish current revision'.
  $permissions['unpublish current revision'] = array(
    'name' => 'unpublish current revision',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'use Search Autocomplete'.
  $permissions['use Search Autocomplete'] = array(
    'name' => 'use Search Autocomplete',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'search_autocomplete',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use bulk exporter'.
  $permissions['use bulk exporter'] = array(
    'name' => 'use bulk exporter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bulk_export',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ctools',
  );

  // Exported permission: 'use custom search'.
  $permissions['use custom search'] = array(
    'name' => 'use custom search',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'custom_search',
  );

  // Exported permission: 'use custom search blocks'.
  $permissions['use custom search blocks'] = array(
    'name' => 'use custom search blocks',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'custom_search_blocks',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use on-page translation'.
  $permissions['use on-page translation'] = array(
    'name' => 'use on-page translation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'l10n_client',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html_plain_no_filter_'.
  $permissions['use text format full_html_plain_no_filter_'] = array(
    'name' => 'use text format full_html_plain_no_filter_',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html_tinymce'.
  $permissions['use text format full_html_tinymce'] = array(
    'name' => 'use text format full_html_tinymce',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view Terms and Conditions'.
  $permissions['view Terms and Conditions'] = array(
    'name' => 'view Terms and Conditions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'legal',
  );

  // Exported permission: 'view date repeats'.
  $permissions['view date repeats'] = array(
    'name' => 'view date repeats',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'date_repeat_field',
  );

  // Exported permission: 'view devel_node_access information'.
  $permissions['view devel_node_access information'] = array(
    'name' => 'view devel_node_access information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel_node_access',
  );

  // Exported permission: 'view faq page'.
  $permissions['view faq page'] = array(
    'name' => 'view faq page',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'faq',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view revision status messages'.
  $permissions['view revision status messages'] = array(
    'name' => 'view revision status messages',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view revisions of any article content'.
  $permissions['view revisions of any article content'] = array(
    'name' => 'view revisions of any article content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of any event content'.
  $permissions['view revisions of any event content'] = array(
    'name' => 'view revisions of any event content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of any faq content'.
  $permissions['view revisions of any faq content'] = array(
    'name' => 'view revisions of any faq content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of any n52_sucess_story content'.
  $permissions['view revisions of any n52_sucess_story content'] = array(
    'name' => 'view revisions of any n52_sucess_story content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of any organisation content'.
  $permissions['view revisions of any organisation content'] = array(
    'name' => 'view revisions of any organisation content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of any page content'.
  $permissions['view revisions of any page content'] = array(
    'name' => 'view revisions of any page content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of any project content'.
  $permissions['view revisions of any project content'] = array(
    'name' => 'view revisions of any project content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of any service_offering content'.
  $permissions['view revisions of any service_offering content'] = array(
    'name' => 'view revisions of any service_offering content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of any service_request content'.
  $permissions['view revisions of any service_request content'] = array(
    'name' => 'view revisions of any service_request content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of own article content'.
  $permissions['view revisions of own article content'] = array(
    'name' => 'view revisions of own article content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of own event content'.
  $permissions['view revisions of own event content'] = array(
    'name' => 'view revisions of own event content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of own faq content'.
  $permissions['view revisions of own faq content'] = array(
    'name' => 'view revisions of own faq content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of own n52_sucess_story content'.
  $permissions['view revisions of own n52_sucess_story content'] = array(
    'name' => 'view revisions of own n52_sucess_story content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of own organisation content'.
  $permissions['view revisions of own organisation content'] = array(
    'name' => 'view revisions of own organisation content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of own page content'.
  $permissions['view revisions of own page content'] = array(
    'name' => 'view revisions of own page content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of own project content'.
  $permissions['view revisions of own project content'] = array(
    'name' => 'view revisions of own project content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of own service_offering content'.
  $permissions['view revisions of own service_offering content'] = array(
    'name' => 'view revisions of own service_offering content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of own service_request content'.
  $permissions['view revisions of own service_request content'] = array(
    'name' => 'view revisions of own service_request content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'view translation overview assignments'.
  $permissions['view translation overview assignments'] = array(
    'name' => 'view translation overview assignments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'translation_overview',
  );

  return $permissions;
}
