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
 * @file
 * Default theme implementation to display a printer-friendly version page.
 *
 * This file is akin to Drupal's page.tpl.php template. The contents being
 * displayed are all included in the $content variable, while the rest of the
 * template focuses on positioning and theming the other page elements.
 *
 * All the variables available in the page.tpl.php template should also be
 * available in this template. In addition to those, the following variables
 * defined by the print module(s) are available:
 *
 * Arguments to the theme call:
 * - $node: The node object. For node content, this is a normal node object.
 *   For system-generated pages, this contains usually only the title, path
 *   and content elements.
 * - $format: The output format being used ('html' for the Web version, 'mail'
 *   for the send by email, 'pdf' for the PDF version, etc.).
 * - $expand_css: TRUE if the CSS used in the file should be provided as text
 *   instead of a list of @include directives.
 * - $message: The message included in the send by email version with the
 *   text provided by the sender of the email.
 *
 * Variables created in the preprocess stage:
 * - $print_logo: the image tag with the configured logo image.
 * - $content: the rendered HTML of the node content.
 * - $scripts: the HTML used to include the JavaScript files in the page head.
 * - $footer_scripts: the HTML  to include the JavaScript files in the page
 *   footer.
 * - $sourceurl_enabled: TRUE if the source URL infromation should be
 *   displayed.
 * - $url: absolute URL of the original source page.
 * - $source_url: absolute URL of the original source page, either as an alias
 *   or as a system path, as configured by the user.
 * - $cid: comment ID of the node being displayed.
 * - $print_title: the title of the page.
 * - $head: HTML contents of the head tag, provided by drupal_get_html_head().
 * - $robots_meta: meta tag with the configured robots directives.
 * - $css: the syle tags contaning the list of include directives or the full
 *   text of the files for inline CSS use.
 * - $sendtoprinter: depending on configuration, this is the script tag
 *   including the JavaScript to send the page to the printer and to close the
 *   window afterwards.
 *
 * print[--format][--node--content-type[--nodeid]].tpl.php
 *
 * The following suggestions can be used:
 * 1. print--format--node--content-type--nodeid.tpl.php
 * 2. print--format--node--content-type.tpl.php
 * 3. print--format.tpl.php
 * 4. print--node--content-type--nodeid.tpl.php
 * 5. print--node--content-type.tpl.php
 * 6. print.tpl.php
 *
 * Where format is the ouput format being used, content-type is the node's
 * content type and nodeid is the node's identifier (nid).
 *
 * @see print_preprocess_print()
 * @see theme_print_published
 * @see theme_print_breadcrumb
 * @see theme_print_footer
 * @see theme_print_sourceurl
 * @see theme_print_url_list
 * @see page.tpl.php
 * @ingroup print
 */
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN"
  "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0" dir="<?php print $language->dir; ?>">
  <head>
    <?php print $head; ?>
    <base href='<?php print $url ?>' />
    <title><?php print $print_title; ?></title>
    <?php if (isset($sendtoprinter)) print $sendtoprinter; ?>
    <?php print $robots_meta; ?>
    <?php if (theme_get_setting('toggle_favicon')): ?>
      <link rel='shortcut icon' href='<?php print theme_get_setting('favicon') ?>' type='image/x-icon' />
    <?php endif; ?>
    <link href='//fonts.googleapis.com/css?family=Titillium+Web:900,700italic,700,600italic,600,400italic,400,300italic,300,200italic,200&subset=latin,latin-ext' rel='stylesheet' type='text/css'>
    <?php print $css; ?>
    <link type="text/css" rel="stylesheet" href="//maxcdn.bootstrapcdn.com/bootstrap/<?php print theme_get_setting('bootstrap_css_cdn'); ?>/css/bootstrap.min.css" media="all" />
  </head>
  <body class="print">
    <?php if (!empty($message)): ?>
      <div class="print-message"><?php print $message; ?></div><p />
    <?php endif; ?>
    <div class="print-header">
	    <?php if ($print_logo): ?>
	    <div class="print-logo"><?php print $print_logo; ?></div>
	    <div class="print-logo-eu">
	    	<figure>
	    		<img class="print-log-eu" id="eu-logo" typeof="foaf:Image" src="<?php print file_create_url(variable_get('file_public_path', conf_path() . '/files') . '/logos/eu_flag_yellow_low_75x112.png'); ?>" alt="EU Flag" />
	    		<figcaption>GA number: 641821</figcaption>
    		</figure>
	    </div>
	    <?php endif; ?>
	    <div class="print-site_name"><?php print theme('print_published'); ?></div>
	    <?php if (!isset($node->type)): ?>
      <h2 class="print-title"><?php print $print_title; ?></h2>
      <?php endif; ?>
    </div>
    <div class="print-content <?php print $main_grid_class; ?>"><?php print $content; ?></div>
    <div class="print-meta-partner">
        <div class="print-meta-title">
      		<h2><?php print t('Partners'); ?></h2>
    		</div>
    			<table id="meta-partner">
    				<tbody>
    					<tr>
    						<td><img class="print-log-eu" id="52n-logo" typeof="foaf:Image" src="<?php print file_create_url(variable_get('file_public_path', conf_path() . '/files') . '/logos/52n-logo-and-name-color_75x161.png'); ?>" alt="52North" /></td>
    						<td><img class="print-log-eu" id="adelphi-logo" typeof="foaf:Image" src="<?php print file_create_url(variable_get('file_public_path', conf_path() . '/files') . '/logos/adelphi_logo.png'); ?>" alt="adelphi" /></td>
    						<td><img class="print-log-eu" id="creaf-logo" typeof="foaf:Image" src="<?php print file_create_url(variable_get('file_public_path', conf_path() . '/files') . '/logos/CREAF_logo.png'); ?>" alt="CREAF" /></td>
    						<td><img class="print-log-eu" id="orion-logo" typeof="foaf:Image" src="<?php print file_create_url(variable_get('file_public_path', conf_path() . '/files') . '/logos/orionlogo_small.png'); ?>" alt="Orion" /></td>
    					</tr>
    					<tr>
    						<td><img class="print-log-eu" id="52n-logo-2" typeof="foaf:Image" src="<?php print file_create_url(variable_get('file_public_path', conf_path() . '/files') . '/logos/52n-logo-and-name-color_75x161.png'); ?>" alt="52North" /></td>
    						<td><img class="print-log-eu" id="52n-logo-3" typeof="foaf:Image" src="<?php print file_create_url(variable_get('file_public_path', conf_path() . '/files') . '/logos/52n-logo-and-name-color_75x161.png'); ?>" alt="52North" /></td>
    						<td><img class="print-log-eu" id="52n-logo-4" typeof="foaf:Image" src="<?php print file_create_url(variable_get('file_public_path', conf_path() . '/files') . '/logos/52n-logo-and-name-color_75x161.png'); ?>" alt="52North" /></td>
    						<td><img class="print-log-eu" id="52n-logo-5" typeof="foaf:Image" src="<?php print file_create_url(variable_get('file_public_path', conf_path() . '/files') . '/logos/52n-logo-and-name-color_75x161.png'); ?>" alt="52North" /></td>
    					</tr>
    				</tbody>
    			</table>
    	</div>
    </div>
    <div class="print-meta-footer">
      <table id="meta-text-table">
    		<tbody>
    			<tr>
    				<td class="meta-text-table-cell"><p><?php print t('This project has received funding from the European Union\'s  Horizon 2020 research and innovation programm under grant agreement No G41821.'); ?></p></td>
    				<td class="table-cell-centered"><a href="http://www.waterinneu.org/" target="_blank">www.waterinneu.org</a></td>
    			</tr>
    			<?php if ($sourceurl_enabled): ?>
    			<tr>
    				<td colspan="2"><div class="print-source_url"><?php print theme('print_sourceurl', array('url' => $source_url, 'node' => $node, 'cid' => $cid)); ?></div></td>
    		  </tr>
    		  <?php endif; ?>
    		</tbody>
    	</table>
    	<div class="print-links"><?php print theme('print_url_list'); ?></div>
    </div>
  </body>
</html>
