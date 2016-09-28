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
function _n52_default_nodes_landing_page_action_buttons() {
	return array (
		'title' =>  array (
				'en' => 'Action Buttons',
		),
		'alias' => NULL,
		'text' => array ('en' => '
				<div id="landing-page-action-buttons" class="container-fluid">
 					<a class="col-lg-3 col-sm-6 col-xs-12" href="products-and-services">
						<div id="landing-page-button-products-and-services" class="landing-page-button alert alert-info">
							<div class="icon"><span class="glyphicon glyphicon-tasks"></span></div>
							<div class="caption">products&nbsp;&amp;&nbsp;services</div>
							<div class="explanation">Detailed information on a select number of screened products and offered services for matchmaking.</div>
						</div>
					</a>
					<a class="col-lg-3 col-sm-6 col-xs-12" href="search/advanced">
						<div id="landing-page-button-search" class="landing-page-button alert alert-info">
							<div class="icon"><span class="glyphicon glyphicon-search"></span></div>
							<div class="caption">search</div>
							<div class="explanation">Use the advanced search tools to find the product or organisation you are looking for.</div>
						</div>
					</a>
					<a class="col-lg-3 col-sm-6 col-xs-12" href="e-learning">
						<div id="landing-page-button-take-course" class="landing-page-button alert alert-info">
							<div class="icon"><span class="glyphicon glyphicon-plus-sign"></span></div>
							<div class="caption">take&nbsp;course</div>
							<div class="explanation">Get help in implementing specific products.</div>
						</div>
					</a>
					<a class="col-lg-3 col-sm-6 col-xs-12" href="join-us">
						<div id="landing-page-button-join-us" class="landing-page-button alert alert-info">
							<div class="icon"><span class="glyphicon glyphicon-log-in"></span></div>
							<div class="caption">join&nbsp;us</div>
							<div class="explanation">Become part of the community and add your own products or service requests.</div>
						</div>
					</a>
				</div>',)
			,
	);
}
