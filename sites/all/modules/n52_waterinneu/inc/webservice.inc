<?php
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