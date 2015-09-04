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
/**
 * @file
 * Administration pages for n52_triple_store module
 */

/**
 * Administration form for n52_triple_store module
 */
function n52_triple_store_admin_settings($form, &$form_state) {
	
	$options = array(
			N52_TRIPLE_STORE_LIBRARY_DRUPAL => t('Drupal'),
	);
	
	if (module_exists('chr')) {
		$options[N52_TRIPLE_STORE_LIBRARY_CURL] = t('cURL');
	}
	
	$form['n52_triple_store_active_library'] = array(
			'#type' => 'radios',
			'#title' => t('Active Library'),
			'#description' => t('Select which function to use to make HTTP requests. cURL is more feature rich and supports more authentication methods however it requires php-curl to be installed. Drupal has an internal HTTP request function which will work on any installation but has fewer options. Defaults to Drupal.'),
			'#options' => $options,
			'#default_value' => variable_get('n52_triple_store_active_library', N52_TRIPLE_STORE_LIBRARY_DRUPAL),
	);
	
	$form['location'] = array(
			'#type' => 'fieldset',
			'#title' => t('Location'),
			'#description' => t('Enter the location of the server.'),
			'#collapsible' => FALSE,
			'#collapsed' => FALSE,
	);
	
	$form['location']['n52_triple_store_hostname'] = array(
			'#type' => 'textfield',
			'#title' => t('Hostname'),
			'#description' => t('The hostname for the server with no trailing slash. Ex: http://localhost:80/triplestore'),
			'#size' => 40,
			'#maxlength' => 255,
			'#default_value' => isset($form_state['values']['n52_triple_store_hostname']) ? $form_state['values']['n52_triple_store_hostname'] : variable_get('n52_triple_store_hostname', 'http://localhost'),
	);
	
	$form['#access'] = array('administer 52n triple store');
	$form['#validate'][] = 'n52_triple_store_admin_settings_validate';
	
	return system_settings_form($form);
}

/**
 * Implements hook_form_validate()
 *
 * Form validation
 */
function n52_triple_store_admin_settings_validate($form, &$form_state) {
	$url = $form_state['values']['n52_triple_store_hostname'];
	if (!valid_url($url, TRUE)) {
		form_set_error('$url',
			t('Please enter a valid URL.
				The according <a href="@url-spec">Specification</a>
				and <a href="@url-spec-updates">some updates</a> are available online.',
				array (
					'@url-spec' => 'https://tools.ietf.org/html/rfc1738',
					'@url-spec-updates' => 'https://www.rfc-editor.org/errata_search.php?rfc=1738' 
				) 
			)
		);
	}
}