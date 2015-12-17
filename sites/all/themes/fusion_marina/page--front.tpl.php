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
 * Fusion Marina theme implementation to display a page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation.
 *   At the very least, this will always default to /.
 * - $directory: The directory the template is located in,
 *   e.g. modules/system or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been
 *   disabled in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been
 *   disabled in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the site,
 *   if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links
 *   for the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears
 *   in the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node associated
 *   with the page, and the node ID is the second argument in the page's path
 *   (e.g. node/12345 and node/12345/revisions, but not comment/reply/12345).
 *
 * Regions:
 * - $page['header_top']: Items for the header top region.
 * - $page['header']: Items for the header region.
 * - $page['main_menu']: Main menu placement.
 * - $page['preface_top']: Items for the preface top region.
 * - $page['preface_bottom']: Items for the preface bottom region.
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['postcript_top']: Items for the postcript top region.
 * - $page['postscript_bottom']: Items for the postscript bottom region.
 * - $page['footer']: Items for the footer region.
 */
	/*
	 * The about node
	 */
	$node = node_load(8772);
	// TODO get right node by language code
	// 	$tnid = $node->tnid;
	// 	$node = translation_node_get_translations($tnid);
	$about_node = node_view($node,'teaser');
	/*
	 * The tool of the month block
	 * 
	 * SELECT *  FROM `drupal`.`block` WHERE `delta`LIKE '%tool_of_the_month%'
	 * 
	 */
	$tool_of_the_month_block = module_invoke('views', 'block_view', 'tool_of_the_month-block');
	unset($tool_of_the_month_block['subject']);
	/*
	 * Buttons menu
	 */
	$buttons_menu = menu_navigation_links('menu-front-page-buttons');
	/*
	 * Latest content block
	 * 
	 * SELECT *  FROM `drupal`.`block` WHERE `delta`LIKE '%frontpage_latest_content%'
	 */
	$latest_content_block = module_invoke('views', 'block_view', 'frontpage_latest_content-block');
	unset($latest_content_block['subject']);
	/*
	 * Latest questions block
	 *
	 * SELECT *  FROM `drupal`.`block` WHERE `delta`LIKE '%frontpage_latest_questions%'
	 */
	$latest_questions_block = module_invoke('views', 'block_view', 'frontpage_latest_questions-block');
	unset($latest_questions_block['subject']);
	/*
	 * Latest news block
	 *
	 * SELECT *  FROM `drupal`.`block` WHERE `delta`LIKE '%latest_news%'
	 */
	$latest_news_block = module_invoke('views', 'block_view', 'latest_news-block');
	unset($latest_news_block['subject']);
	/*
	 * Services block
	 *
	 * SELECT *  FROM `drupal`.`block` WHERE `title`LIKE '%services%'
	 */
	$services_block = module_invoke('block', 'block_view', '1');
	/*
	 * Hack to get home button activated (we assume it's the first element of 
	 * the main menu). The class "active-trail" is added, if not available.
	 */
	if (is_array($page['main_menu'])  && is_array($page['main_menu']['system_main-menu'])) {
		$keys = array_keys($page['main_menu']['system_main-menu']);
		if (is_array($keys) && count($keys) > 0) {
			$classes = &$page['main_menu']['system_main-menu'][$keys[0]]['#attributes']['class'];
			if (!in_array("active-trail", $classes)) {
				$classes[count($classes)] = "active-trail";
			}
		}
	}
?>
<div id="page" class="page">
	<div id="page-inner" class="page-inner">
		<?php print render($page['header_top']); ?>
		<!-- header-group region: width = grid_width -->
		<div id="header-group-wrapper" class="header-group-wrapper full-width clearfix">
			<div id="header-group"class="header-group region <?php print $grid_width; ?>">
				<div id="header-group-inner" class="header-group-inner inner clearfix">
				<?php if ($logo || $site_name || $site_slogan): ?>
					<div id="header-site-info" class="header-site-info clearfix">
						<div id="header-site-info-inner" class="header-site-info-inner gutter">
						<?php if ($logo): ?>
							<div id="logo">
								<a href="<?php print check_url($front_page); ?>" title="<?php print t('Home'); ?>"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
							</div>
						<?php endif; ?>
						<?php if ($site_name || $site_slogan): ?>
							<div id="site-name-wrapper" class="clearfix">
							<?php if ($site_name): ?>
								<?php if ($title): ?>
									<div id="site-name">
										<a href="<?php print check_url($front_page); ?>" title="<?php print t('Home'); ?>" rel="home"><?php print $site_name; ?></a>
									</div>
								<?php else: /* Use h1 when the content title is empty */ ?>
									<h1 id="site-name"><a href="<?php print check_url($front_page); ?>" title="<?php print t('Home'); ?>" rel="home"><?php print $site_name; ?></a></h1>
								<?php endif; ?>
							<?php endif; ?>
							<?php if ($site_slogan): ?>
								<span id="slogan"><?php print $site_slogan; ?></span>
							<?php endif; ?>
							</div><!-- /site-name-wrapper -->
						<?php endif; ?>
						</div><!-- /header-site-info-inner -->
					</div><!-- /header-site-info -->
				<?php endif; ?>
				<?php print render($page['header']); ?>
				</div><!-- /header-group-inner -->
			</div><!-- /header-group -->
		</div><!-- /header-group-wrapper -->
		<?php print render($page['main_menu']); ?>
		<div class="preface-top-outer"><?php print render($page['preface_top']); ?></div>
		<!-- main region: width = grid_width -->
		<div id="main-wrapper" class="main-wrapper full-width clearfix">
			<div id="main" class="main region <?php print $grid_width; ?>">
				<div id="main-inner" class="main-inner inner clearfix">
					<!-- main group: width = grid_width - sidebar_first_width -->
					<div id="main-group" class="main-group region nested <?php print $main_group_width; ?>">
						<div id="main-group-inner" class="main-group-inner inner">
							<?php print render($page['preface_bottom']); ?>
							<div id="main-content" class="main-content region nested">
								<div id="main-content-inner" class="main-content-inner inner">
									<!-- content group: width = grid_width - sidebar_first_width - sidebar_second_width -->
									<div id="content-group" class="content-group region nested <?php print $content_group_width; ?>">
										<div id="content-group-inner" class="content-group-inner inner">
											<?php print theme('grid_block', array('content' => $messages, 'id' => 'content-messages')); ?>
											<div id="content-region" class="content-region region nested">
												<div id="content-region-inner" class="content-region-inner inner">
													<a id="main-content-area"></a>
													<div id="frontpage-line-one" class="frontpage-line">
														<div id="frontpage-about">
															<?php print render($about_node); ?>
														</div><!-- /frontpage-about -->
														<div id="frontpage-tool-of-the-month">
															<?php print render($tool_of_the_month_block); ?>
														</div><!-- /frontpage-tool-of-the-month -->
													</div><!-- /frontpage-line-one -->
													<div id="frontpage-buttons">
														<?php print theme('links__menu_front_page_buttons', array('links' => $buttons_menu)); ?>
													</div><!-- /frontpage-buttons -->
													<div id="frontpage-line-three" class="frontpage-line">
														<div id="frontpage-news">
															<?php print render($latest_news_block); ?>
														</div><!-- /frontpage-news -->
														<div id="frontpage-line-three-column-two">
															<div id="frontpage-latest-content">
																<?php print render($latest_content_block); ?>
															</div><!-- /frontpage-latest-content -->
															<div id="frontpage-latest-questions">
																<?php print render($latest_questions_block); ?>
															</div><!-- /frontpage-latest-questions -->
														</div><!-- /frontpage-line-three-column-two -->
													</div><!-- /frontpage-line-three -->
													<?php print $services_block['content']; ?>
												</div><!-- /content-region-inner -->
											</div><!-- /content-region -->
										</div><!-- /content-group-inner -->
									</div><!-- /content-group -->
								</div><!-- /main-content-inner -->
							</div><!-- /main-content -->
							<?php print render($page['postscript_top']); ?>
						</div><!-- /main-group-inner -->
					</div><!-- /main-group -->
				</div><!-- /main-inner -->
			</div><!-- /main -->
		</div><!-- /main-wrapper -->
		<?php print render($page['postscript_bottom']); ?>
		<?php print render($page['footer']); ?>
	</div><!-- /page-inner -->
</div><!-- /page -->
