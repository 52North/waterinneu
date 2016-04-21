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
 * Changes to bootstrap business:
 * - We surround the comments and form with a accordion element and hide it by
 *   default
 */
?>
<div id="comments-accordion" class="panel-group">
	<section id="comments" class="<?php print $classes; ?>"<?php print $attributes; ?>>
		<div class="panel panel-default panel-comments">
			<div class="panel-heading collapsed" data-toggle="collapse" data-parent="#comments-accordion" data-target="#comments-panel">
				<?php print render($title_prefix); ?>
				<h2 class="title panel-title accordion-toggle"><?php print t('Comments'); ?> <span class="background">- (<?php print $node->comment_count;?>)</span></h2>
				<?php print render($title_suffix); ?>
	    	</div>
			<div id="comments-panel" class="panel-collapse collapse">
				<div class="panel-body">
					<?php if ($node->comment_count > 0) {?>
						<?php print render($content['comments']); ?>
	  				<?php } ?>
					<?php if ($content['comment_form']){ ?>
	    				<h3 class="title comment-form"><?php print t('Add your Comment'); ?></h3>
	    				<?php print render($content['comment_form']); ?>
	  				<?php } ?>
	   			</div>
			</div>
		</div>
	</section>
</div>