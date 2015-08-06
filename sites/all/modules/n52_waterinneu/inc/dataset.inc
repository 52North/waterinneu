<?php
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