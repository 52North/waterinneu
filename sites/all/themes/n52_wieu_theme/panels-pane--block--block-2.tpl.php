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
/*
 * Implementation of "Updates" block/section on the landing page
 */
?>
<?php 
	/*
	 * Latest content block
	 *
	 * SELECT *  FROM `drupal`.`block` WHERE `delta`LIKE '%frontpage_latest_content%'
	 */
	$latest_content_block = module_invoke('views', 'block_view', 'frontpage_latest_content-block');
	unset($latest_content_block['subject']);
	/*
	 * Latest comments block
	 *
	 * SELECT *  FROM `drupal`.`block` WHERE `delta`LIKE '%comments_recent%'
	 */
	$latest_comments_block = module_invoke('views', 'block_view', 'comments_recent-block');
	unset($latest_comments_block['subject']);
	/*
	 * Latest questions block
	 *
	 * SELECT *  FROM `drupal`.`block` WHERE `delta`LIKE '%frontpage_latest_posts%'
	 */
	$latest_posts_block = module_invoke('views', 'block_view', 'frontpage_latest_posts-block');
	unset($latest_posts_block['subject']);
	/*
	 * Latest questions block
	 *
	 * SELECT *  FROM `drupal`.`block` WHERE `delta`LIKE '%frontpage_latest_questions%'
	 */
	$latest_threads_block = module_invoke('views', 'block_view', 'frontpage_latest_questions-block');
	unset($latest_threads_block['subject']);
?>
<div class="left-column">
	<div id="landingpage-updates-block" class="panel-pane pane-block pane-block-2">
		<h2 class="pane-title" id="updates"><?php print t('Updates'); ?></h2>
		<div class="pane-content">
			<!-- Nav tabs -->
			<ul class="nav nav-tabs" role="tablist">
				<li class="active"><a href="#tab-1" role="tab" data-toggle="tab"><?php print t('Content'); ?></a></li>
				<li><a href="#tab-2" role="tab" data-toggle="tab"><?php print t('Comments'); ?></a></li>
				<li><a href="#tab-3" role="tab" data-toggle="tab"><?php print t('Threads'); ?></a></li>
				<li><a href="#tab-4" role="tab" data-toggle="tab"><?php print t('Posts'); ?></a></li>
			</ul>
			<!-- Tab panes -->
			<div class="tab-content">
				<div class="tab-pane active" id="tab-1">
					<?php print render($latest_content_block); ?>
				</div>
				<div class="tab-pane" id="tab-2">
					<?php print render($latest_comments_block); ?>
				</div>
				<div class="tab-pane" id="tab-3">
					<?php print render($latest_threads_block); ?>
				</div>
				<div class="tab-pane" id="tab-4">
					<?php print render($latest_posts_block); ?>
				</div>
			</div>
		</div>
	</div>
</div>
<div class="right-column">
	<div id="landingpage-updates-image">
		<img title="Updates! Water based image" src="sites/default/files/pictures/landingpage_updates.png" />
	</div>
</div>
<div style="clear: both;"></div>