<?php

class wsdata_simple_xml_processor extends WsData {

  // Parse the web service response string, and returns a structured data array
  public function parse($data) {
    if (!isset($data) || empty($data)) {
      return;
    }
    $data = trim($data);
    libxml_use_internal_errors(TRUE);
    try {
      $data = new SimpleXMLElement($data);
      if ($data->count() == 0) {
        return array($data->getName() => $data->__toString());
      }
      $data = get_object_vars($data);
      foreach( $data as $key => $value) {
        $data[$key] = $this->_parsexml($value);
      }
    }
    catch (exception $e) {
      return FALSE;
    }
    libxml_use_internal_errors(FALSE);
    return $data;
  }


   function accepts() {
    return array('xml');
  }

  // XML Parsing helper function, converts nested XML objects into arrays
  private function _parsexml($value) {
    if (is_object($value) and get_class($value)) {
      $value = get_object_vars($value);
      foreach ($value as $k => $v) {
        $value[$k] = $this->_parsexml($v);
      }
    }
    elseif (is_array($value)) {
      foreach($value as $key => $xml) {
        $value[$key] = $this->_parsexml($xml);
      }
    }

    return $value;
  }
}
