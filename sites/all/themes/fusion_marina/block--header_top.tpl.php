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
* Fusion theme implementation to display a block.
* 
* This is an override created by 52N to display blocks in the header_top region
*
* Available variables:
* - $block->subject: Block title.
* - $content: Block content.
* - $block->module: Module that generated the block.
* - $block->delta: An ID for the block, unique within each module.
* - $block->region: The block region embedding the current block.
* - $classes: String of classes that can be used to style contextually through
*   CSS. It can be manipulated through the variable $classes_array from
*   preprocess functions. The default values can be one or more of the
*   following:
*   - block: The current template type, i.e., "theming hook".
*   - block-[module]: The module generating the block. For example, the user
*     module is responsible for handling the default user navigation block. In
*     that case the class would be "block-user".
* - $title_prefix (array): An array containing additional output populated by
*   modules, intended to be displayed in front of the main title tag that
*   appears in the template.
* - $title_suffix (array): An array containing additional output populated by
*   modules, intended to be displayed after the main title tag that appears in
*   the template.
*
* Helper variables:
* - $classes_array: Array of html class attribute values. It is flattened
*   into a string within the variable $classes.
* - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
* - $zebra: Same output as $block_zebra but independent of any block region.
* - $block_id: Counter dependent on each block region.
* - $id: Same output as $block_id but independent of any block region.
* - $is_front: Flags true when presented in the front page.
* - $logged_in: Flags true when the current user is a logged-in member.
* - $is_admin: Flags true when the current user is an administrator.
*
* @see template_preprocess()
* @see template_preprocess_block()
* @see template_process()
*/
?>
<?php if (strcmp($block->region, 'header_top') === 0 && strpos($classes, 'first')): ?>
<div id="headertopcontainer">
<?php endif;?>
	<div id="block-<?php print $block->module . '-' . $block->delta; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
		<div class="inner clearfix gutter" style="float: right;">
			<div class="inner-wrapper">
				<div class="inner-inner">
					<div class="content clearfix"<?php print $content_attributes; ?>>
						<?php print $content ?>
					</div>
				</div><!-- /inner-inner -->
			</div><!-- /inner-wrapper -->
		</div><!-- /block-inner -->
	</div><!-- /block -->
<?php if (strcmp($block->region, 'header_top') === 0 && strpos($classes,'last')): ?>
</div>
<?php endif;?>

 