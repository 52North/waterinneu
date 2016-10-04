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
function _n52_default_nodes_join_us() {
	return array (
		'title' =>  array (
				'en' => 'Join Us',
		),
		'alias' => 'join-us',
		'text' => array ('en' => '
			<div id="join-us-button-logo">
				<img tile="Join Us! - handshake - male and femail" src="sites/default/files/pictures/join-us_shake-hands.png" />
			</div>
			<ul id="join-us-actions-list">
				<!--
				<li id="join-us-express-interest">
					<span class="glyphicon glyphicon-thumbs-up"></span>
					<strong>Express interest</strong>:
					<div>
						Express interest in a product and get 
						in touch with the product owner.
					</div>
				</li>
				-->
				<li id="join-us-add-content">
					<a href="node/add">
						<span class="glyphicon glyphicon-plus"></span>
						<strong>Contribute</strong>
					</a>:
					<div>
						Upload your own product or event, or add your organisation to 
						our community (screened by our in-house team before going live).
					</div>
				</li>
  			<li id="join-us-matchmaking-services">
					<a href="matchmaking">
						<span class="glyphicon glyphicon-link"></span>
						<strong>Use our matchmaking service</strong>
					</a>:
					<div>
						Find an organisation or partner that can help you implement 
						a product, or communicate your own service offering.
					</div>
				</li>
				<li id="join-us-alerts">
					<a href="matchmaking#alerts">
						<span class="glyphicon glyphicon-exclamation-sign"></span>
						<strong>Sign up for alerts</strong>
					</a>:
					<div>
						Receive information on new or updated products, 
						organisations, services requests, service offers or events.
					</div>
				</li>
				<li id="join-us-forum">
					<a href="forum">
						<span class="glyphicon glyphicon-comment"></span>
						<strong>Use the open forum</strong>
					</a>:
					<div>
						Start or join a discussion on a topic of interest.
					</div>
				</li>
			</ul>
			<div id="join-us-sign-up-button">
				<button type="button" class="btn btn-primary btn-lg">
  				<a href="user/register">Join <span class="glyphicon glyphicon-log-in"></span></a>
				</button>
			</div>
				',)
			,
	);
}
