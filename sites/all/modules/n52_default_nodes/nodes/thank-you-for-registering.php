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
function _n52_default_nodes_thank_you_for_registering() {
	return array (
		'title' =>  array (
				'en' => 'Thank you for registering',
		),
		'alias' => 'thank-you-registering',
		'text' => array ('en' => '
					<div id="thank-you-image">
						<img tile="Thank you for registering" src="sites/default/files/pictures/thank-you-for-registering.png" />
					</div>
					<p>
						Thank you for signing up with WaterInnEU.
						We are delighted to welcome you to our community. 
						The following will happen now:
					</p>
					<ul id="thank-you-actions-list">
						<li>
							<span class="glyphicon glyphicon-envelope"></span>
							We send you an information mail within the next hour 
							from:<br />
							<center style="margin: 1em;"><code>wieu-admins at 52north dot org</code></center>
							Please check your spam folder.
						</li>
						<li>
							<span class="glyphicon glyphicon-user"></span>
							One of our administrators will check and approve your account.
						</li>
						<li>
							<span class="glyphicon glyphicon-envelope"></span>
							Afterwards, we will send you an information mail that explains
							the next steps to be performed by you:
							<ul id="thank-you-first-actions-list">
								<li>
									<span class="glyphicon glyphicon-link"></span>
									Follow the one time password link.
								</li>
								<li>
									<span class="glyphicon glyphicon-pencil"></span>
									Set your password and optionally update your profile.
								</li>
								<li>
									<span class="glyphicon glyphicon-log-in"></span>
									Log-in to the marketplace.
								</li>
							</ul>
						</li>
					</ul>
					<p>
						In the meantime, <a href="join-us">click here</a> to 
						see how you can get involved.
					</p>
				',)
			,
	);
}
