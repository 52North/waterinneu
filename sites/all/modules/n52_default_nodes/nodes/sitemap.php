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
function _n52_default_nodes_sitemap() {
	return array (
		'title' => array (
				'en' => 'Site Map',
		),
		'alias' => 'sitemap',
		'text' => array ('en' => '
<ul>
	<li>
		<a href="#top">Home</a><br />The landingpage including
		<ul>
				<li>the product of the month,</li>
				<li>portal updates,</li>
				<li>tweets, and</li>
				<li>general information.</li>
		</ul>
	</li>
	<li><a href="product" title="Open products inventory">Products</a>
		<ul>
			<li>Get overview about useful products in the hydrology domain,</li>
			<li>find products by search criteria, and</li>
			<li>review products features and other additional metadat, e.g. licensing.</li>
		</ul>
	</li>
	<li><a href="organisation" title="Open organisations inventory">Organisations</a><br /> Search- and filterable inventory of organsations.</li>
	<li>
		<a href="matchmaking" title="Open matchmaking sections">Matchmaking</a><br />Seven different levels of matchmaking are available:
		<ul>
			<li><a href="matchmaking#search">Search</a></li>
			<li><a href="matchmaking#service-requests">Service Requests</a></li>
			<li><a href="matchmaking#alerts">Alerts</a></li>
			<li><a href="matchmaking#ask-the-expert">Ask the Expert</a></li>
			<li><a href="forum">Open discussions in Forum</a></li>
			<li><a href="matchmaking#events">Events</a></li>
		</ul>
	</li>
	<li><a href="e-learning">E-Learning</a><br />...TBC...</li>
	<li><a href="success-stories">Success Stories</a><br />...TBC...</li>
	<li>
		<a href="forum" title="Open the forum!">Forum</a>
		<ul>
			<li>
				Find <a href="forum/demand">products&nbsp;for	a certain problem category</a>,
			</li>
			<li>
				find <a href="forum/offering">users for your product</a>, and
			</li>
			<li>
				find experts for <a href="forum/discussion">discussing methods and models</a>.
			</li>
		</ul>
	</li>
	<li><a href="related-portals">Related Portals</a><br />A list of portals that deal with related topics.</li>
	<li><a href="api">API::JSON</a><br />A JSON endpoint to the content of this marketplace.</li>
</ul>',),
	);
}