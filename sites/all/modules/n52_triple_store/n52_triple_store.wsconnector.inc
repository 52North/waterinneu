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
 * Implementation of wsdata.WcConnector class
 */
 
if (class_exists('WsConnector')) {
	
	class N52TripleStoreWsConnector extends WsConnector {
		
		public function getMethods() {
			return array (
				'single' => array (
						'create' => t('52N TripleStore create method (POST)'),
						/*'read' => t('52N TripleStore read method (GET)'),
						'update' => t('52N TripleStore update method (POST)'),
						'delete' => t('52N TripleStore delete method (POST)'),
						'index' => t('52N TripleStore index method (GET)'),*/
				)	
			);
		}
		
		/**
		 * Implements WsConnector->wscall().
		 */
		public function wscall($type, $method, $argument, $options) {
			// check speficied error handling behaviour from options
			$errorHandling = array_key_exists('error_handling', $options);
			
			switch ($type) {
				case 'create' :
					return $this->tripleStoreCreate($type, $method, $argument, $options, $errorHandling);
				default:
					return FALSE;
			}
		}
		
		protected function tripleStoreCreate(&$type, &$method, &$argument, &$options, $errorHandling) {
			$variables = array ('endpoint' => $this->endpoint, 'body' => $argument) + $options;
			if (empty($argument)) {
				unset($variables['body']);
			}
			$response = tripleStorePost($method, $variables);
			if (tripleStoreGetResponseCode($response) != N52_TRIPLE_STORE_RESPONSE_SUCCESS) {
				if ($errorHandling) {
					// don't cache error responses
          			$this->expires = 0;
          			return $response;
				}
				else {
					return FALSE;
				}
			}
			else {
				return $response->data;
			}
		}
		
		protected function tripleStorePost($resource_path, $variables = array()) {
			// Map variables @todo move to own method tripleStoreMapVariables
			
			// Endpoint
			if (!empty($variables['endpoint'])) {
				// Do nothing
			}
			else {
				$variables['endpoint'] = variable_get('n52_triple_store_hostname', 'http://localhost:80/triplestore');
			}
			
			if(!empty($variables['parameters'])) {
				$this->tripleStorePrepareUrlParameters($resource_path, $variables);
			}
			
			// Set the method
			$variables['method'] = 'POST';
			
			// Append raw body data
			if (!empty($variables['body'])) {
				$variables['data'] = $variables['body'];
			}
			else {
				// Prepare any data variables
				$this->tripleStorePreparePostData($variables);
			}
			// Build the URL
			$url = $this->tripleStoreBuildResourcePath($resource_path, $variables);
			
			switch (N52_TRIPLE_STORE_ACTIVE_LIBRARY) {
				case N52_TRIPLE_STORE_LIBRARY_CURL:
					$response = chr_curl_http_request($url, $variables);
					break;
				case N52_TRIPLE_STORE_LIBRARY_DRUPAL:
				default;
				$response = drupal_http_request($url, $variables);
			}
			
			if (!isset($response->error) || (isset($response->errno) and $response->errno == 0)) {
				// No error occured, return the response
				return $response;
			}
			return FALSE;
		}
		
		/**
		 * Encodes and appends any URL parameters to the resource path
		 *
		 * @param string $resource_path [reference]
		 *  Resource path
		 * @param array $parameters [reference]
		 *  Array of URL parameters
		 *
		 */
		protected function tripleStorePrepareUrlParameters(&$resource_path, &$variables) {
			// URL Encode all parameters
			foreach ($variables['parameters'] as $key => $param) {
				$variables['parameters'][$key] = urlencode($param);
			}
		
			// Add the parameters to the resource path
			if (!empty($variables['parameters'])) {
				$resource_path = strtr($resource_path, $variables['parameters']);
			}
		}
		
		/**
		 * Encodes and sanitizes and body data
		 *
		 * @param array $variables [reference]
		 * <ul>
		 * 		<li>$variables['headers']<br>
		 *  		Current set of headers</li>
		 * 		<li>$variables['data']<br>
		 *  		Data to include in the POST request</li>
		 * 		<li>$variables['multipart'] [optional]<br>
		 *  		Treat the data as a multipart request</li>
		 *  </ul>
		 */
		protected function tripleStorePreparePostData(&$variables) {
		
			if (!isset($variables['data'])) {
				$variables['data'] = array();
			}
		
			// Detect content type
			if (empty($variables['headers']['Content-Type'])) {
				$variables['headers']['Content-Type'] = 'application/x-www-form-urlencoded';
			}
			else {
				// @todo detect which content type is set in the headers
				// Encode based on that. If we don't know what it is, default to 'Content-Type' => 'application/x-www-form-urlencoded'
				// If the body is present, leave the text as is.
			}
		
			// Check the library in use. If curl is set, let curl handle the post
			// data automatically. Otherwise, parse the data for drupal_http_request
			$body = '';
			if (N52_TRIPLE_STORE_LIBRARY_DRUPAL == N52_TRIPLE_STORE_ACTIVE_LIBRARY) {
				if (!empty($variables['multipart']) && FALSE !== $variables['multipart']) {
					// Build the boundary
					$boundary = uniqid();
		
					// Set the new header data
					$variables['headers']['Content-Type'] = "multipart/form-data; boundary=$boundary";
		
					// Build the multipart data
					$this->tripleStoreMultipartEncode($variables['data'], $boundary);
				}
				else {
					// Build the body string
					foreach ($variables['data'] as $param => $value) {
						$body .= urlencode($param) . '=' . urlencode($value) . '&';
					}
		
					// Set the value of data to the new string
					$variables['data'] = $body;
				}
			}
			elseif (N52_TRIPLE_STORE_LIBRARY_CURL == N52_TRIPLE_STORE_ACTIVE_LIBRARY) {
				// Build the body string
				foreach ($variables['data'] as $param => $value) {
					$body .= urlencode($param) . '=' . urlencode($value) . '&';
				}
		
				// Check for a file upload and add the '@' sign accordingly
				// @see http://php.net/function.curl-setopt.php
				if (isset($variables['data']['fid'])) {
					$file = file_load($variables['data']['fid']);
		
					// @todo check the user's access to this file
		
					if (isset($file->fid) && isset($file->status) && $file->status == 1) {
						// Load the file
						$file_content = file_get_contents(drupal_realpath($file->uri));
						$variables['data']['fid'] = '@' . drupal_realpath($file->uri);
					}
				}
		
				// Set the value of data to the new string
				$variables['data'] = $body;
			}
		}
		
		/**
		 * Build the multipart encoded header data
		 *
		 * @param array $data [reference]
		 *  Array of parameters to encode. Also the return data.
		 * @param string $boundary [optional]
		 *  Boundary string
		 *
		 *  If not value is specified, a string will be generated
		 */
		protected function tripleStoreMultipartEncode(&$data, $boundary = NULL) {
		
			// Copy the current parameters into a new variables
			// We use the $data reference to store the result. We use a reference to
			// avoid creating copies of large variables in memory. The file encode
			// function loads a complete file into memory as a string. We have to be
			// careful to avoid hitting memory limits.
			$params = $data;
		
			// Reset the data container
			$data = '';
		
			// Check the boundary text
			if (is_null($boundary)) {
				$boundary = uniqid("", TRUE);
			}
		
			foreach ($params as $key => $value) {
				// Check the type of data to be encoded
				if ($key == 'fid') {
					// @todo add support for an array of fids
					$file_encode = _restclient_multipart_encode_file($value);
					// Check the encoding
					if (FALSE !== $file_encode) {
						// Build the data
						$data .= "--$boundary\r\n";
						$data .= $file_encode;
						$data .="\r\n--$boundary--";
		
						// Clean up some memory
						unset($file_encode);
					}
				}
				// Treat the data as text
				else {
					$text_encode = $this->tripleStoreMultipartEncodeText($key, $value);
					// Check the encoding
					if (FALSE !== $text_encode) {
						// Build the data
						$data .= "--$boundary\r\n";
						$data .= $text_encode;
		
						// Clean up some memory
						unset($text_encode);
					}
				}
			}
		
			// Check that the data isn't empty and mark the last boundary
			if (!empty($data)) {
				$data .="--$boundary--";
			}
		}
		
		/**
		 * Multipart encode the given text
		 *
		 * @param string $name
		 *  Name of the text
		 * @param string $text
		 *  Text string
		 * @return string
		 *  Returns the header string.
		 */
		protected function tripleStoreMultipartEncodeText($name, $text) {
			return "Content-Disposition: form-data; name=\"$name\"\r\n\r\n$text\r\n";
		}
		
		/**
		 * Build the URL to connect to
		 *
		 * @param string $resource_path
		 *  Base path
		 * @param array $variables
		 *  Configuration variables
		 * @return string
		 *  Returns a full URL
		 */
		protected function tripleStoreBuildResourcePath(&$resource_path, &$variables) {
			if (!empty($resource_path)) {
				$url = $variables['endpoint'] . '/' . $resource_path;
			}
			else {
				$url = $variables['endpoint'];
			}
		
			// Set the options to be used by url()
			$options = array(
					'query' => isset($variables['query']) ? $variables['query'] : '',
					// 'fragment' => $variables['fragment'], @todo add fragment support
					'absolute' => TRUE,
					'alias' => TRUE,
					'external' => TRUE,
			);
		
			// @todo find a way to skip hook_url_outbound or migrate url() function
			// to internal function
			$url = url($url, $options);
		
			return $url;
		}
	}
	
}