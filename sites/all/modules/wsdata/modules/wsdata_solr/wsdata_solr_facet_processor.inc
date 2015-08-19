<?php

/**
 * WSData Processor for Solr Facets
 *  Get the names and counts of the facets returned
 */
class wsdata_solr_facet_processor extends WsData {
  public function parse($data) {
    if (!isset($data) || empty($data)) {
      return;
    }
    $data = trim($data);
    $data = json_decode($data, TRUE);
    return $data['facet_counts'];
  }

  public function accepts() {
   return array('json');
  }
}
