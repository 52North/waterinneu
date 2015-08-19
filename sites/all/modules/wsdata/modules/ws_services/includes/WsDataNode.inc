<?php
class WsDataNode extends WsData {
  // Returns an array of the content type of the data this processor accepts
  public function accepts() {
    return array('json');
  }

  // Parse the web service response string into a structured array and return the array
  protected function parse($data) {
    $data = $this->unwrap(json_decode($data));

    foreach ($data as $name => $value) {
      if (is_array($value)) {
        foreach ($data[$name] as $lang => $list) {
          if (is_array($list)) {
            foreach ($list as $id => $val) {
              if (is_array($val) and isset($val['value'])) {
                $data[$name][$lang][$id] = $val['value'];
              }
            }
          }
        }
      }
    }
    return $data;
  }

  private function unwrap($data) {
    if (is_object($data)) {
      $data = get_object_vars($data);
    }
    if (is_array($data)) {
      foreach ($data as $k => $v) {
        $data[$k] = $this->unwrap($v);
      }
    }
    return $data;
  }

}
