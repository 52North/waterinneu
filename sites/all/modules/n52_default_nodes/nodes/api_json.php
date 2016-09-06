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
function _n52_default_nodes_api_json() {
	return array (
		'title' =>  array (
				'en' => 'JSON API',
				'de' => 'JSON API',
		),
		'alias' => 'api',
		'text' => array (
				'de' => '<p>
Der Marktplatz Inhalt ist zus&auml;tzlich zu der f&uuml;r Menschen lesbaren Form als JSON-API verf&uuml;gbar. Folgende Endpunkte werden zur Verf&uuml;gung gestellt:
</p>
<ul>
<li><a href="api/events">/api/events</a></li>
<li><a href="api/organisations">/api/organisations</a></li>
<li><a href="api/products">/api/products</a></li>
<li><a href="api/projects">/api/projects</a></li>
<li><a href="api/service-offerings">/api/service-offerings</a></li>
<li><a href="api/service-requests">/api/service-requests</a></li>
</ul>
<p>
Die API ist noch im Entwicklungsstadium. Hinterlassen Sie daher bei Bedarf gerne einen Kommentar oder stellen eine Frage an unseren
<a href="mailto:e.h.juerrens+wieu-json-api@52north.org">hauptverantwortlichen Entwicklungsleiter</a>.</p>',
				'en' => '
<p>
    The marketplace content is in addition to the human readable form available 
    via an JSON API. The following endpoints are provided:
</p>
<ul>
	<li><a href="api/events">/api/events</a></li>
	<li><a href="api/organisations">/api/organisations</a></li>
	<li><a href="api/products">/api/products</a></li>
	<li><a href="api/projects">/api/projects</a></li>
	<li><a href="api/service-offerings">/api/service-offerings</a></li>
	<li><a href="api/service-requests">/api/service-requests</a></li>
</ul>
<p>
    Consider this API as work in progress and feel free to comment on any issue 
	you find to our 
	<a href="mailto:e.h.juerrens+wieu-json-api@52north.org">head of development
	</a>.
</p>',),
	);
}