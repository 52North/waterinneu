<?php
/**
 * @file
 * feature_configuration.backup_migrate_exportables.inc
 */

/**
 * Implements hook_exportables_backup_migrate_destinations().
 */
function feature_configuration_exportables_backup_migrate_destinations() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'server_configuration_backup';
  $item->name = 'server_configuration_backup';
  $item->subtype = 'file';
  $item->location = './config-backup/';
  $item->settings = array(
    'chmod' => '',
    'chgrp' => '',
  );
  $export['server_configuration_backup'] = $item;

  return $export;
}

/**
 * Implements hook_exportables_backup_migrate_profiles().
 */
function feature_configuration_exportables_backup_migrate_profiles() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'uncompressed';
  $item->name = 'Uncompressed_without-timestamp';
  $item->filename = '[site:name]';
  $item->append_timestamp = FALSE;
  $item->timestamp_format = 'Y-m-d\\TH-i-s';
  $item->filters = array(
    'compression' => 'none',
    'notify_success_enable' => 0,
    'notify_success_email' => 'e.h.juerrens@52north.org',
    'notify_failure_enable' => 0,
    'notify_failure_email' => 'e.h.juerrens@52north.org',
    'utils_site_offline' => 0,
    'utils_site_offline_message' => 'WaterInnEU Development Server is currently under maintenance. We should be back shortly. Thank you for your patience.',
    'utils_description' => '',
    'use_cli' => 0,
    'ignore_errors' => 0,
    'sources' => array(
      'db' => array(
        'exclude_tables' => array(),
        'nodata_tables' => array(
          'cache' => 'cache',
          'cache_admin_menu' => 'cache_admin_menu',
          'cache_block' => 'cache_block',
          'cache_bootstrap' => 'cache_bootstrap',
          'cache_field' => 'cache_field',
          'cache_filter' => 'cache_filter',
          'cache_form' => 'cache_form',
          'cache_image' => 'cache_image',
          'cache_menu' => 'cache_menu',
          'cache_page' => 'cache_page',
          'cache_path' => 'cache_path',
          'cache_update' => 'cache_update',
          'cache_views' => 'cache_views',
          'cache_views_data' => 'cache_views_data',
          'search_dataset' => 'search_dataset',
          'search_index' => 'search_index',
          'search_total' => 'search_total',
          'sessions' => 'sessions',
          'watchdog' => 'watchdog',
        ),
        'utils_lock_tables' => 1,
      ),
      'files' => array(
        'exclude_filepaths' => 'backup_migrate
styles
css
js
ctools
less',
      ),
      'archive' => array(
        'exclude_filepaths' => 'public://backup_migrate
public://styles
public://css
public://js
public://ctools
public://less
private://backup_migrate
sites/default/settings.php
/tmp',
      ),
    ),
  );
  $export['uncompressed'] = $item;

  return $export;
}

/**
 * Implements hook_exportables_backup_migrate_schedules().
 */
function feature_configuration_exportables_backup_migrate_schedules() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'waterinneu_config_backup_schedule';
  $item->name = 'waterinneu_config_backup_schedule';
  $item->source_id = 'db';
  $item->destination_id = 'server_configuration_backup';
  $item->copy_destination_id = '';
  $item->profile_id = 'uncompressed';
  $item->keep = 1;
  $item->period = 86400;
  $item->enabled = TRUE;
  $item->cron = 'builtin';
  $item->cron_schedule = '0 4 * * *';
  $export['waterinneu_config_backup_schedule'] = $item;

  return $export;
}
