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
function _n52_default_nodes_cookies() {
	return array (
		'title' => 'Cookies',
		'alias' => 'cookies',
		'text' => array ('und' => '
<p>
	The Marketplace uses cookies for storing user preferences and session 
	information for logged in users. By using it and agreeing to this policy, 
	you consent to WaterInnEU\'s use of cookies in accordance with the terms of 
	this policy.
</p>
<h2>About cookies</h2>
<p>
Cookies are files sent by web servers to web browsers, and stored by the web 
browsers. The information is then sent back to the server each time the browser 
requests a page from the server. This enables a web server to identify users 
and apply the stored preferences.
</p>
<p>
There are two main kinds of cookies:
<ul>
	<li>session cookies and </li>
	<li>persistent cookies.</li>
</ul>
Session cookies are deleted from your computer when you close your browser, 
whereas persistent cookies remain stored on your computer until deleted, or 
until they reach their expiry date.
</p>
<p>
Find out more about <a href="http://www.aboutcookies.org/" target="_blank">how 
to manage cookies</a>.
<h2>Cookies on the marketplace</h2>
<p>
The WaterInnEU marketplace uses the following cookies for the listed purposes:
<table>
	<thead>
		<tr>
			<th>Name</th>
			<th>Duration<sup><a href="#note_star">*</a></sup></th>
			<th>Description</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>has_js</td>
			<td>Session</td>
			<td>
				Allows the server to know if it can depend upon javascript. Set to "1" 
				if user has javascript enabled by whichever page a visitor arrives on.
			</td>
		</tr>
		<tr>
			<td>cookie-agreed</td>
			<td>14 weeks</td>
			<td>
				Stores the information about the cookie acceptance of the user if are 
				accepted.
			</td>
		</tr>
		<tr>
			<th colspan="3">When logged in</th>
		</tr>
		<tr>
			<td>SESS***</td>
			<td>3 weeks</td>
			<td>
				This cookie allows logging in and remembering which forms you have 
				submitted. This cookie is essential for site functionality and the user 
				experience.
			</td>
		</tr>
		<tr>
			<td>Drupal.***</td>
			<td>3 weeks</td>
			<td>
				The Content Management System sets these cookies to store user 
				interface preferences.
			</td>
		</tr>
	</tbody>
</table>
</p>
<h2>Third Party cookies</h2>
<p>
The WaterInnEU marketplace uses a widget from twitter.com. Hence, some cookies 
from twitter are stored, too. These are the following ones:
<table>
	<thead>
		<tr>
			<th>Name</th>
			<th>Duration<a href="#note_star">*</a></th>
			<th>Description</th>
			<th>Domain/Provider</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>lang</td>
			<td>Session</td>
			<td>
				Used to store the language of the user and to know which language to use
				for the widget interface.
			</td>
			<td>syndication.twitter.com</td>
		</tr>
		<tr>
			<td>metrics_token</td>
			<td>4 weeks</td>
			<td>Counts the number of users that have a specific embedded Tweet or timeline.</td>
			<td>syndication.twitter.com</td>
		</tr>
		<tr>
			<td>pid</td>
			<td>end of time</td>
			<td>
				Enables Twitter\'s suggestions feature that personalizes content and 
				suggestions for Twitter users based on their website visits.
			</td>
			<td>.twitter.com</td>
		</tr>
	</tbody>
</table>
</p>
<h2>Refusing cookies</h2>
<p>
	Most browsers allow you to refuse to accept cookies. Here are the 
	instructions for some browsers:
<ul>
	<li><a href="https://support.google.com/chrome/answer/95647?hl=en&p=cpn_cookies" target="_blank">Chrome</a></li>
	<li><a href="https://support.mozilla.org/en-US/kb/enable-and-disable-cookies-website-preferences" target="_blank">Firefox</a></li>
	<li><a href="https://support.microsoft.com/en-us/help/17442/windows-internet-explorer-delete-manage-cookies#ie=ie-11" target="_blank">Internet Explorer</a></li>
	<li><a href="https://support.apple.com/en-us/HT201265" target="_blank">Safari</a></li>
</ul>
</p>
<hr />
<p>
	<sup id="note_star"><strong>*</strong></sup> Any duration other then <code>Session</Code> denotes that this 
	cookie is not deleted after ending the current browser session.
</p>',),
	);
}