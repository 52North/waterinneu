<?php

/**
 * @file
 * Generates the PDF version using wkhtmltopdf
 *
 * This file is included by the print_pdf_wkhtmltopdf module and includes the
 * functions that interface with the wkhtmltopdf library
 *
 * @ingroup print
 */

/**
 * Implements hook_print_pdf_generate().
 */
function print_pdf_wkhtmltopdf_print_pdf_generate($html, $meta, $paper_size = NULL, $page_orientation = NULL) {
  $pdf_tool = explode('|', variable_get('print_pdf_pdf_tool', PRINT_PDF_PDF_TOOL_DEFAULT));
  if (empty($paper_size)) {
    $paper_size = variable_get('print_pdf_paper_size', PRINT_PDF_PAPER_SIZE_DEFAULT);
  }
  if (empty($page_orientation)) {
    $page_orientation = variable_get('print_pdf_page_orientation', PRINT_PDF_PAGE_ORIENTATION_DEFAULT);
  }
  $content_disposition = variable_get('print_pdf_content_disposition', PRINT_PDF_CONTENT_DISPOSITION_DEFAULT);
  $wkhtmltopdf_options = variable_get('print_pdf_wkhtmltopdf_options', PRINT_PDF_WKHTMLTOPDF_OPTIONS);

  $dpi = 96;

  if (!empty($wkhtmltopdf_options) && isset($meta['node'])) {
    $wkhtmltopdf_options = token_replace($wkhtmltopdf_options, array('node' => $meta['node']), array('clear' => TRUE));
  }

  $version = print_pdf_wkhtmltopdf_pdf_tool_version($pdf_tool[1]);

  // 0.10.0 beta2 identifies itself as 0.9.9
  if (version_compare($version, '0.9.9', '>=')) {
    //$wkhtmltopdf_options = '--allow-local-file-access ' . $wkhtmltopdf_options;
  }
  elseif (version_compare($version, '0.9.6', '>=')) {
    //$wkhtmltopdf_options = '--allow-local-file-access ' . $wkhtmltopdf_options;
  }
  else {
    drupal_goto($meta['url']);
    exit;
  }

  // use basic http authentication to fetch included CSS, etc
  if (isset($_SERVER['PHP_AUTH_USER']) && isset($_SERVER['PHP_AUTH_PW'])) {
    $wkhtmltopdf_options .= ' --username ' . check_plain($_SERVER['PHP_AUTH_USER']) . ' --password ' . check_plain($_SERVER['PHP_AUTH_PW']);
  }

  // Write the data to a temporary file.
  $temp_path = realpath(file_directory_temp()) . '/';
  $temp_html =  false;
  $temp_pdf = false;
  $retries=0;
  while (($temp_html==false) && ($retries<10)) {
  	$temp_html =  drupal_tempnam($temp_path, 'c_html_');
  	if (rename($temp_html, $temp_html.'.html')) {
  		$temp_html = $temp_html.'.html';
  	}
  
  	$retries++;
  }
  while (($temp_pdf==false) && ($retries<20)) {
  	$temp_pdf =  drupal_tempnam($temp_path, 'c_pdf_');
  	if (rename($temp_pdf, $temp_pdf.'.pdf')) {
  		$temp_pdf = $temp_pdf.'.pdf';
  	}
  	$retries++;
  }
  
  if (file_put_contents($temp_html, $html) === FALSE) {
  	return FALSE;
  }
  $cmd = '"' . realpath($pdf_tool[1]) . "\" --page-size $paper_size --orientation $page_orientation --dpi $dpi $wkhtmltopdf_options $temp_html $temp_pdf 2>&1";
  $output = array();
  $return_val = FALSE;
  exec($cmd, $output, $return_val);
  $pdf= file_get_contents($temp_pdf);
  unlink($temp_html);
  unlink($temp_pdf);

  if (!empty($pdf)) {
    return $pdf;
  }
  else {
    drupal_set_message(
    		t('Unable to generate PDF file') . 
    		': "' . 
    		((isset($output))?implode('; ', $output):'') .
    		'".'
    	, 'error');
    drupal_goto($meta['url']);
    return NULL;
  }
}
