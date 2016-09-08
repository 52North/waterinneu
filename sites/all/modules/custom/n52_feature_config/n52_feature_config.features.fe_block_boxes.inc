<?php
/**
 * @file
 * n52_feature_config.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function n52_feature_config_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Funding disclaimer';
  $fe_block_boxes->format = 'full_html_plain_no_filter_';
  $fe_block_boxes->machine_name = 'n52_funding_footer';
  $fe_block_boxes->body = '<div id="eu-funding-footer">
    <div id="eu-funding-footer-centralizer">
        <div id="eu-funding-footer-text">This project has received funding from the European Union\'s Horizon 2020 research and innovation programm under grant agreement No G41821.</div>
        <div id="eu-funding-footer-logo"><img class="print-log-eu" id="eu-logo" typeof="foaf:Image" src="/sites/default/files/logos/eu_flag_yellow_low_75x112.png" alt="EU Flag"></div>
    </div>
</div>';

  $export['n52_funding_footer'] = $fe_block_boxes;

  return $export;
}
