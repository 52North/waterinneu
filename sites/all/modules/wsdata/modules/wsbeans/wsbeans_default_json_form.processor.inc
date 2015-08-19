<?php

class wsbeans_default_json_form extends wsdata_simple_json_processor {

  // Parse the web service response string, and returns a structured data array
  public function parse($data) {
    $data = parent::parse($data);
    $list = $this->sublist('', $data);
    $form = array(
      '#theme' => 'item_list',
      '#items' => $list['children'],
      '#type' => 'ul',
    );
    return $form;
  }

/**
 * Method for generating sublist
 */
  private function sublist($key, $data) {
    $list = array();
    if (is_array($data)) {
      $list = array();
      foreach ($data as $key => $val) {
        $list[$key] = $this->sublist($key, $val);
      }
      return array('children' => $list);
    }
    return $key . ': ' . $data;
  }
}

