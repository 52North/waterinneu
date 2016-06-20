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
function _n52_default_nodes_landingpage_accordion() {
	return array (
		'title' => 'Landing page - Content accordion',
		'alias' => 'test/my-path/yo-wrapper',
		'text' => array ('und' => '
<div id="accordion" class="panel-group">
    <!--
    EXPLORE
    -->
	<div class="panel panel-default panel-explore panel-dark-hightlight">
		<div class="panel-heading panel-heading-dark-highlight" data-toggle="collapse" data-parent="#accordion" data-target="#explore">
			<h2 class="panel-title accordion-toggle">
				<span class="glyphicon glyphicon-search">&nbsp;</span>Explore
			</h2>
		</div>
		<div id="explore" class="panel-collapse collapse in">
			<div class="panel-body">
				<div id="explore-search">
					<a href="matchmaking#search"><span class="glyphicon glyphicon-search">&nbsp;</span>Search</a>
				</div>
				<div id="explore-service-requests">
					<a href="matchmaking#service-requests"><span class="glyphicon glyphicon-tasks">&nbsp;</span>Service Requests</a>
				</div>
				<div id="explore-alerts">
					<a href="matchmaking#alerts"><span class="glyphicon glyphicon-exclamation-sign">&nbsp;</span>Alerts</a>
				</div>
				<div id="explore-ask-experts">
					<a href="matchmaking#ask-the-expert"><span class="glyphicon glyphicon-question-sign">&nbsp;</span>Ask the Expert</a>
				</div>
				<div id="explore-forum">
					<a href="matchmaking#forum"><span class="glyphicon glyphicon-comment">&nbsp;</span>Open Discussions in Forum</a>
				</div>
				<div id="explore-e-learning">
					<a href="e-learning"><span class="glyphicon glyphicon-plus-sign">&nbsp;</span>E-Learning</a>
				</div>
				<div id="explore-events">
					<a href="matchmaking#events"><span class="glyphicon glyphicon-calendar">&nbsp;</span>Events</a>
				</div>
				<div id="explore-add-content">
					<a href="node/add"><span class="glyphicon glyphicon-plus">&nbsp;</span>Add Entries</a>
				</div>
			</div>
		</div>
	</div>
	<!--
	ABOUT
	-->
	<div class="panel panel-default panel-about panel-light-highlight">
		<div class="panel-heading panel-heading-light-highlight collapsed" data-toggle="collapse" data-parent="#accordion" data-target="#about">
			<h2 class="panel-title accordion-toggle">
				<span class="glyphicon glyphicon-info-sign">&nbsp;</span>About
			</h2>
		</div>
		<div id="about" class="panel-collapse collapse">
			<div class="panel-body">
				<h3>
					<a id="intro"></a>Introduction
				</h3>
				<p>
					The virtual Market Place provides innovative products, documentation
					about these products, and contacts to experts for these products in
					the integrated water resources management domain. In addition, an
					inventory of projects and organisations is available. The integrated
					participative e-learning function of the Market Place facilitates the
					selection and application of tools. Questions on products can be
					discussed in the forum.
				</p>
				<h3>Vision</h3>
				<p>
					To create a virtual Market Place, and associated professional
					community, for knowledge exchange in support of the exploitation
					and market translation of EU funded ICT models, products, and
					supporting know-how and intellectual property relevant to river
					basin management and the implementation of the Water Framework
					Directive (WFD).
				</p>
				<h3>Sections - What is inside the virtual Market Place</h3>
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
							<li><a href="matchmaking#forum">Open discussions in Forum</a></li>
							<li><a href="matchmaking#events">Events</a></li>
						</ul>
					</li>
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
					<li><a href="e-learning">E-Learning</a><br />...TBC...</li>
					<li><a href="success-stories">Success Stories</a><br />...TBC...</li>
				</ul>
				<h3>Backstage - Who is driving WaterInnEU</h3>
				<ul>
					<li><a href="http://52north.org/" target="_blank">52°North</a></li>
					<li><a href="https://www.adelphi.de/en" target="_blank">adelphi</a></li>
					<li><a href="http://www.anteagroup.be/en" target="_blank">Antea</a></li>
					<li><a href="http://www.creaf.cat/en" target="_blank">CREAF</a></li>
					<li><a
						href="http://www.gwp.org/gwp-in-action/Central-and-Eastern-Europe/"
						title="Global Water Partnership - Central and Eastern Europe">GWP-CEE</a></li>
					<li><a href="http://www.orioninnovations.co.uk/"
						target="_blank">Orion</a></li>
					<li><a href="http://www.randbee.com/" target="_blank">Randbee</a></li>
					<li><a href="http://www.tudelft.nl/en/" target="_blank">TU-Delft</a></li>
				</ul>
				<h3>Links - Who is Doing Related Work</h3>
				<ul>
					<li><a href="http://www.aquaknow.net/" target="_blank"
						title="aquaknow.net">Aquaknow</a></li>
					<li><a href="http://his.cuahsi.org/index.html" target="_blank">CUAHSI-HIS</a></li>
					<li><a href="http://datahub.io/">Datahub</a></li>
					<li><a href="http://www.eea.europa.eu/themes/water/dc">EEA
							Water Centre</a></li>
					<li><a href="http://www.eionet.europa.eu/">EIONET</a></li>
					<li><a href="http://www.eip-water.eu/">EIP Water</a></li>
					<li><a href="https://open-data.europa.eu/en/data"
						target="_blank">EU Open Data Portal</a></li>
					<li><a href="http://floods.jrc.ec.europa.eu/" target="_blank">European
							Floods Portal</a></li>
					<li><a href="http://ec.europa.eu/eurostat" target="_blank">EUROSTAT
							Open Data Portal</a></li>
					<li><a href="http://europeanwatercommunity.eu/"
						target="_blank">European Water Community (EWC)</a></li>
					<li><a
						href="http://ec.europa.eu/research/environment/index_en.cfm?section=geo&amp;pg=geoss"
						target="_blank">GEOSS</a></li>
					<li><a href="http://inspire-geoportal.ec.europa.eu/"
						target="_blank">INSPIRE Geoportal</a></li>
					<li><a href="http://www.water-switch-on.eu/" target="_blank">SWITCH-ON</a></li>
					<li><a href="http://water.europa.eu/" target="_blank">WISE</a></li>
					<li><a href="http://www.wise-rtd.info/en" target="_blank">WISE-RTD</a></li>
				</ul>
			</div>
		</div>
	</div>
	<!--
	OUR SERVICES
	-->
	<div class="panel panel-default panel-dark-hightlight">
		<div class="panel-heading panel-heading-dark-highlight collapsed" data-toggle="collapse" data-parent="#accordion" data-target="#our-services">
			<h2 class="panel-title accordion-toggle">
				<span class="glyphicon glyphicon-shopping-cart">&nbsp;</span>Our Services
			</h2>
		</div>
		<div id="our-services" class="panel-collapse collapse">
			<div class="panel-body">
				The primary goal of the WaterInnEU Portal is to facility a match making
				between organizations offering certain products for River Basin
				Management, potential users of these products, and service providers
				that provide specific services for these products, e.g. to customize a
				software for a particular river basin. To enable such a match making,
				the portal provides the functionalities listed above in the explore
				section.
			</div>
		</div>
	</div>
	<!--
	UPCOMING EVENTS
	-->
	<div class="panel panel-default panel-upcoming-events panel-light-highlight collapsed">
		<div class="panel-heading panel-heading-light-highlight collapsed" data-toggle="collapse" data-parent="#accordion" data-target="#events">
			<h2 class="panel-title accordion-toggle">
				<span class="glyphicon glyphicon-calendar">&nbsp;</span>Upcoming Events
			</h2>
		</div>
		<div id="events" class="panel-collapse collapse">
			<div class="panel-body">
				The next upcoming events:
				<br />
        <div id="upcoming-events"></div>
        <a href="node/add/event"><button type="button" class="btn btn-primary">Add new Event</button></a>
				&nbsp;
				<a href="matchmaking/events"><button type="button" class="btn btn-default">Show all Events</button></a>
			</div>
		</div>
	</div>
</div>',)
			,
	);
}