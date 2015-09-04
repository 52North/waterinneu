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
 * Implements wsdata.WsData => aws_processor for processing the webservice results 
 *
 */
class N52TripleStoreWsProcessor extends WsData {
	
	/**
	 * Returns structured array of supported types:
	 * <ul><li><pre>application/xml</pre></li></ul>
	 */
	public function accepts() {
		return array ('application/xml');
	}
	
	/**
	 * parses the webservice XML response into a structured array that can be 
	 * handled by drupal core or other modules.
	 */
	public function parse($data) {
		// Source: http://www.webomelette.com/comment/76#comment-76
		// See more at: http://www.webomelette.com/xml-to-php-drupal#sthash.OxgRbok7.dpuf
		$parsedData = new SimpleXMLElement($data);
		$parsedData = drupal_json_decode(drupal_json_encode($parsedData));
		
		// now, we have XML in json and can handle it.
		// @todo CONTINUE implementation here on Monday
	}
}