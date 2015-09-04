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
function webservice_form($form, $node = '') {
	//
	// WEBSERVICE from
	//
	$form ['webservice'] = array (
			'#type' => 'fieldset',
			'#title' => t ( 'Webservice Information' ),
			'#states' => array (
					'visible' => array (
							':input[name="type"]' => array (
									'value' => 'webservice' 
							) 
					) 
			) 
	);
	
	$form ['webservice'] ['url'] = array (
			'#type' => 'textfield',
			'#title' => t ( 'Webservice location (URL)' ),
			'#size' => 125,
			// http://stackoverflow.com/a/417184
			'#maxlength' => 2000,
			'#states' => array (
					'visible' => array (
							':input[name="type"]' => array ('value' => 'webservice') 
					),
					'required' => array (
							':input[name="type"]' => array ('value' => 'webservice')
					),
			),
			'#description' => t ( 'Provide a URL which can be used to access the webservice.' ) 
	);
	
	$form ['webservice'] ['auth_required'] = array (
			'#type' => 'checkbox',
			'#title' => t ( 'Authorization required?' ),
			'#states' => array (
					'visible' => array (
							':input[name="type"]' => array ('value' => 'webservice') 
					)
			),
			'#description' => t ( 'Is any additional authorization information required to access the service.' ) 
	);
	
	return $form;
}