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
 * Preprocess variables for page template.
 * 
 * Changes to bootstrap business:
  * - glyphicons for the pre-header.
 */
function n52_wieu_theme_preprocess_page(&$vars) {

	/**
	 * insert variables into page template.
	 */
	if($vars['page']['sidebar_first'] && $vars['page']['sidebar_second']) {
		$vars['sidebar_grid_class'] = 'col-md-3';
		$vars['main_grid_class'] = 'col-md-6';
	} elseif ($vars['page']['sidebar_first'] || $vars['page']['sidebar_second']) {
		$vars['sidebar_grid_class'] = 'col-md-4';
		$vars['main_grid_class'] = 'col-md-8';
	} else {
		$vars['main_grid_class'] = 'col-md-12';
	}

	if($vars['page']['header_top_left'] && $vars['page']['header_top_right']) {
		$vars['header_top_left_grid_class'] = 'col-md-8';
		$vars['header_top_right_grid_class'] = 'col-md-4';
	} elseif ($vars['page']['header_top_right'] || $vars['page']['header_top_left']) {
		$vars['header_top_left_grid_class'] = 'col-md-12';
		$vars['header_top_right_grid_class'] = 'col-md-12';
	}

	/**
	 * Add Javascript
	 */
	if($vars['page']['pre_header_first'] || $vars['page']['pre_header_second'] || $vars['page']['pre_header_third']) {
		drupal_add_js('
	function hidePreHeader(){
	jQuery(".toggle-control").html("<a href=\"javascript:showPreHeader()\"><span class=\"glyphicon glyphicon-chevron-down\"></span></a>");
	jQuery("#pre-header-inside").slideUp("fast");
	}

	function showPreHeader() {
	jQuery(".toggle-control").html("<a href=\"javascript:hidePreHeader()\"><span class=\"glyphicon glyphicon-chevron-up\"></span></a>");
	jQuery("#pre-header-inside").slideDown("fast");
	}
	',
				array('type' => 'inline', 'scope' => 'footer', 'weight' => 3));
	}
	//EOF:Javascript
}

/**
 * Implements hook_form_element($variables)
 * 
 * Changes to bootstrap business:
  * - Adjustment is to render the description before the fields and not after.
 * 
 * TODO fix bugs with certain fields types.
 * 
 *  @see includes/form.inc
 */
function n52_wieu_theme_form_element($variables) {
	$element = &$variables['element'];

	// This function is invoked as theme wrapper, but the rendered form element
	// may not necessarily have been processed by form_builder().
	$element += array(
			'#title_display' => 'before',
	);

	// Add element #id for #type 'item'.
	if (isset($element['#markup']) && !empty($element['#id'])) {
		$attributes['id'] = $element['#id'];
	}
	// Add element's #type and #name as class to aid with JS/CSS selectors.
	$attributes['class'] = array('form-item');
	if (!empty($element['#type'])) {
		$attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
	}
	if (!empty($element['#name'])) {
		$attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
	}
	// Add a class for disabled elements to facilitate cross-browser styling.
	if (!empty($element['#attributes']['disabled'])) {
		$attributes['class'][] = 'form-disabled';
	}
	$output = '<div' . drupal_attributes($attributes) . '>' . "\n";

	// If #title is not set, we don't display any label or required marker.
	if (!isset($element['#title'])) {
		$element['#title_display'] = 'none';
	}
	$prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
	$suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

	switch ($element['#title_display']) {
		case 'before':
		case 'invisible':
			$output .= ' ' . theme('form_element_label', $variables);
			if (!empty($element['#description'])) {
				$output .= '<div class="description">' . $element['#description'] . "</div>\n";
			}
			$output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
			break;

		case 'after':
			$output .= ' ' . $prefix . $element['#children'] . $suffix;
			if (!empty($element['#description'])) {
				$output .= '<div class="description">' . $element['#description'] . "</div>\n";
			}
			$output .= ' ' . theme('form_element_label', $variables) . "\n";
			break;

		case 'none':
		case 'attribute':
			// Output no label and no required marker, only the children.
			if (!empty($element['#description'])) {
				$output .= '<div class="description">' . $element['#description'] . "</div>\n";
			}
			$output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
			break;
	}

	$output .= "</div>\n";

	return $output;
}

/**
 * 
 * Changes to bootstrap business:
 * - Render the description of fields with glyphicon after the label if content 
 *   type is matching.
 * 
 * @param unknown $variables
 */
function n52_wieu_theme_field($variables) {
	$output = '';
	$field_bundle = $variables['element']['#bundle'];
	$description = '';
	
	if ($field_bundle === 'organisation' || $field_bundle === 'product' || $field_bundle === 'tool') {
	
		$field_info = field_info_instance(
				$variables['element']['#entity_type'],
				$variables['element']['#field_name'],
				$field_bundle);
		$description = $field_info['description'];
	}

	// Render the label, if it's not hidden.
	if (!$variables['label_hidden']) {
		$output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'];
		if (strlen($description)) {
			// add info glyphicon and popover stuff
			$output .= '&nbsp;<span class="glyphicon glyphicon-info-sign glyphicon-light" data-content="<div class=\'popover-light\'>' . $description . '</div>" rel="popover" data-toggle="popover" data-placement="right" data-original-title="Description" data-trigger="click" data-html="true"></span>';
		}
		$output .= ':&nbsp;</div>';
	}

	// Render the items.
	$output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
	foreach ($variables['items'] as $delta => $item) {
		$classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
		$output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
	}
	$output .= '</div>';

	// Render the top-level DIV.
	$output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

	return $output;
}

/**
 * Renders HTML element for the last updated value using the given parameters. 
 * The used timestamp format is 'c'.
 * 
 * @param unknown $changed the information when the node was last changed
 * @param unknown $user_name the name of the user that did the last change
 */
function n52_waterinneu_theme_node_last_updated($changed, $user_name) {
	$output = '<span property="dc:date" content="' .
		format_date($changed,'custom','c') .
		'" datatype="xsd:dateTime">' .
		t('Last updated by ') .
		$user_name .
		t(' on ') .
		format_date($changed) .
		'</span>';
	return $output;
}