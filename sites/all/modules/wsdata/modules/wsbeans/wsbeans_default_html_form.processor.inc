<?php

class wsbeans_default_html_form extends WsData {

  // Parse the web service response string, and returns a structured data array
  public function parse($data) {
    $form = array(
      '#markup' => $data,
    );
    return $form;
  }

   function accepts() {
    return array('html');
  }

}

