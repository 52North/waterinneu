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
  * - display of the submitted value adjusted
  */
 ?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if ($title_prefix || $title_suffix || $display_submitted || !$page): ?>
  <header>
    <?php print render($title_prefix); ?>
    <?php if (!$page): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <?php if ($display_submitted && $view_mode === 'full'): ?>
      <div class="submitted">
        <?php print $user_picture; ?>
        <span class="glyphicon glyphicon-calendar"></span> 
        <?php 
        if ($changed <= $created) {
        	print $submitted;
		}
        if ($changed > $created) {
        	print n52_waterinneu_theme_node_last_updated($changed, $name);
        }
        ?>
      </div>
    <?php endif; ?>
  </header>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_tags']);
      // on the match making page, we want to display some dynamic content
      if (n52_endsWith($node_url, 'matchmaking')) {
      	/*
      	 * Latest service requests block
      	 *
      	 * SELECT *  FROM `drupal`.`block` WHERE `delta`LIKE '%frontpage_latest_content%'
      	 */
      	$latest_service_requests_block = module_invoke('views', 'block_view', 'matchmaking_latest_service_requests-block');
      	unset($latest_service_requests_block['subject']);
      	$latest_service_requests_content = render($latest_service_requests_block);
      	$content['body'][0]['#markup'] = str_replace('<div id="latest-service-requests" />', $latest_service_requests_content, $content['body'][0]['#markup']);
      	/*
      	 * Latest service offerings block
      	 *
      	 * SELECT *  FROM `drupal`.`block` WHERE `delta`LIKE '%offerings%'
      	 */
      	$latest_service_offerings_block = module_invoke('views', 'block_view', 'matchmaking_latest_service_offerings-block');
      	unset($latest_service_offerings_block['subject']);
      	$latest_service_offerings_content = render($latest_service_offerings_block);
      	$content['body'][0]['#markup'] = str_replace('<div id="latest-service-offerings" />', $latest_service_offerings_content, $content['body'][0]['#markup']);
      	/*
      	 * Latest forum threads block
      	 *
      	 * SELECT *  FROM `drupal`.`block` WHERE `delta`LIKE '%frontpage_latest_questions%'
      	 */
      	$latest_threads_block = module_invoke('views', 'block_view', 'frontpage_latest_questions-block');
      	unset($latest_threads_block['subject']);
      	$latest_forum_threads_content = render($latest_threads_block);
      	$content['body'][0]['#markup'] = str_replace('<div id="latest-forum-threads"></div>', '<div id="latest-forum-threads">' . $latest_forum_threads_content . '</div>', $content['body'][0]['#markup']);
      }
      print render($content);
    ?>
  </div>
    
    <?php if (($tags = render($content['field_tags'])) || ($links = render($content['links']))): ?>
    <footer>
    <?php print render($content['field_tags']); ?>
    <?php print render($content['links']); ?>
    </footer>
    <?php endif; ?> 

  <?php print render($content['comments']); ?>

</article>