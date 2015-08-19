<?php

class wsdata_simple_json_processor extends WsData {

  // Parse the web service response string, and returns a structured data array
  public function parse($data) {
    if (!isset($data) || empty($data)) {
      return;
    }
    $data = trim($data);
    return json_decode($data, TRUE);
  }

   function accepts() {
    return array('json');
  }
}
