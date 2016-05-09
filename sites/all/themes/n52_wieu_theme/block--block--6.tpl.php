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

// TODO: get list of content types to search for? dynamic search possible?
// 

?>
<div id="advanced-search-block" class="<?php print $classes; ?>"<?php print $attributes; ?>>
	<h2 class="pane-title"><?php print $block->subject; ?></h2>
	<div id="advanced-search-instructions">
	 	<?php print $content ?>
	</div>
	<div class="pane-content">
		<!-- Nav tabs -->
		<ul class="nav nav-tabs" role="tablist">
			<li class="active"><a href="#products" role="tab" data-toggle="tab"><?php print t('Products'); ?></a></li>
			<li><a href="#organisations" role="tab" data-toggle="tab"><?php print t('Organisations'); ?></a></li>
			<li><a href="#service-requests" role="tab" data-toggle="tab"><?php print t('Service Requests'); ?></a></li>
			<li><a href="#service-offerings" role="tab" data-toggle="tab"><?php print t('Service Offerings'); ?></a></li>
			<li><a href="#events" role="tab" data-toggle="tab"><?php print t('Events'); ?></a></li>
			<li><a href="#posts" role="tab" data-toggle="tab"><?php print t('Forum Posts'); ?></a></li>
<?php /* ?>
			<li><a href="#other" role="tab" data-toggle="tab"><?php print t('Other'); ?></a></li>
<?php */ ?>
		</ul>
		
		<!-- Tab panes -->
		<div class="tab-content">
			<div class="tab-pane active" id="products">
				<?php print views_embed_view('advanced_search_products','block'); ?>
			</div>
			<div class="tab-pane" id="organisations">
				<?php print views_embed_view('view_advanced_search_organsations','block'); ?>
			</div>
			<div class="tab-pane" id="service-requests">
				<?php print views_embed_view('advanced_search_service_requests','block'); ?>
			</div>
			<div class="tab-pane" id="service-offerings">
				<?php print views_embed_view('advanced_search_service_offerings','block'); ?>
			</div>
			<div class="tab-pane" id="events">
				<?php print views_embed_view('advanced_event_search','block'); ?>
			</div>
			<div class="tab-pane" id="posts">
				<?php print views_embed_view('n52_views_advanced_search_forum','block'); ?>
			</div>
<?php /* ?>
			<div class="tab-pane" id="other">
				<?php print views_embed_view('advanced_search_other','block'); ?>
			</div>
<?php */ ?>
		</div>
	</div>
</div>