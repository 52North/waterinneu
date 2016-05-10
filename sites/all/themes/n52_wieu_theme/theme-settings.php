<?php
/*
 * Copyright (C) 2016
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
 * Implements hook_form_FORM_ID_alter().
*
* @param $form
*   The form.
* @param $form_state
*   The form state.
*/
function n52_wieu_theme_form_system_theme_settings_alter(&$form, &$form_state) {
	
	$form['mtt_settings']['#title'] = t('52°North - WaterInnEU Theme Settings');
	
	unset($form['mtt_settings']['tabs']['ie8_support']);

	$form['mtt_settings']['tabs']['basic_settings']['n52_header_background_images']  = array (
		'#type' => 'checkbox',
		'#title' => t('Show header background images'),
		'#description' => t('Render randomly choosen header background images '
			. 'taken from "sites/all/themes/n52_wieu_theme/images". '
			. 'The filename MUST start with "header-background-".'),
		'#default_value' => theme_get_setting('n52_header_background_images', 'n52_wieu_theme'),
	);
	
}