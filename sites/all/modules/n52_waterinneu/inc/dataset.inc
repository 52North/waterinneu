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
function dataset_form($form, $node = '') {
	//
	// DATASET form
	//
	$form['dataset'] = array (
			'#type' => 'fieldset',
			'#title' => t('Dataset Information'),
			'#states' => array (
					'visible' => array (
							':input[name="type"]' => array ('value' => 'dataset'),
					),
			),
			'#description' => t('This is the Dataset field set description.'),
	);
	
	$form['dataset']['charset_encoding'] = array (
			'#type' => 'select',
			'#title' => t('Charset Encoding'),
			// read options from file or system method
			'#options' => array (
					'UTF-8' => t('UTF-8'),
					'ISO-8859-1' => t('ISO-8859-1')
			),
			'#default_value' => 'UTF-8',
			'#description' => t('Select the charest encoding of the dataset.'),
			'#states' => array (
					'visible' => array (
							':input[name="type"]' => array ('value' => 'dataset')
					),
			),
	);
	
	$form['dataset']['url'] = array (
			'#type' => 'textfield',
			'#title' => t('Location of the dataset (URL)'),
			'#size' => 125,
			// http://stackoverflow.com/a/417184
			'#maxlength' => 2000,
			'#states' => array (
					'visible' => array (
							':input[name="type"]' => array ('value' => 'dataset' )
					),
					'required' => array (
							':input[name="type"]' => array ('value' => 'dataset')
					),
			),
			'#description' => t('Provide a URL which can be used to access the dataset.'),
	);
	
	$form['dataset']['author_email'] = array (
			'#type' => 'textfield',
			'#title' => t('E-Mail of the author or any other point of contact'),
			'#size' => 125,
			//http://stackoverflow.com/a/574698
			'#maxlength' => 254,
			'#states' => array (
					'visible' => array (
							':input[name="type"]' => array ('value' => 'dataset'),
					),
					'required' => array (
							':input[name="type"]' => array ('value' => 'dataset')
					),
			),
			'#description' => t('Provide an email that can be used to discuss any issue regards this dataset.'),
	);
	
	return $form;
}