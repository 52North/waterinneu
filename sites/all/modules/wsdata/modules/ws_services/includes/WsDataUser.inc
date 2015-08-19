<?php
class WsDataUser extends WsData {
  // Returns an array of the content type of the data this processor accepts
  public function accepts() {
    return array('json');
  }

  // Parse the web service response string into a structured array and return the array
  protected function parse($data) {
    return array();
  }
}
