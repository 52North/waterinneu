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

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = '"You can also" for e-learning context';
  $fe_block_boxes->format = 'full_html_plain_no_filter_';
  $fe_block_boxes->machine_name = 'n52_wieu_you_can_also_e_learning';
  $fe_block_boxes->body = '<div id="e-learning-you-can-also" class="you-can-also-block">
  <ul>
    <li>Browse our <a href="product">products</a> and <a href="matchmaking#service-requests">services</a> to find and implement new products</li>
    <li><a href="join-us">Join our community</a> to add your own product or organisation, find support or join a discussion</li>
    <li><a href="forum">Go to the forum</a> to see the latest debates on river basin management</li>
    <li><a href="matchmaking#alerts">Subscribe for alerts</a> to get informed about the latest changes depending on your requirements</li>
  </ul>
</div>';

  $export['n52_wieu_you_can_also_e_learning'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = '"You can also" for join-us page';
  $fe_block_boxes->format = 'full_html_plain_no_filter_';
  $fe_block_boxes->machine_name = 'n52_wieu_you_can_also_join_us';
  $fe_block_boxes->body = '<div id="join-us-you-can-also" class="you-can-also-block">
  <ul>
    <li>Browse our <a href="product">products</a> and <a href="matchmaking#service-requests">services</a> to find and implement new products</li>
    <li><a href="e-learning">Take a course</a> to help you implement a specific product</li>
    <li><a href="forum">Go to the forum</a> to see the latest debates on river basin management</li>
    <li><a href="matchmaking#alerts">Subscribe for alerts</a> to get informed about the latest changes depending on your requirements</li>
  </ul>
</div>';

  $export['n52_wieu_you_can_also_join_us'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = '"You can also" for products context';
  $fe_block_boxes->format = 'full_html_plain_no_filter_';
  $fe_block_boxes->machine_name = 'n52_wieu_you_can_also_products';
  $fe_block_boxes->body = '<div id="products-you-can-also" class="you-can-also-block">
  <ul>
    <li><a href="e-learning">Take a course</a> to help you implement a specific product</li>
    <li><a href="join-us">Join our community</a> to add your own product or organisation, find support or join a discussion</li>
    <li><a href="forum">Go to the forum</a> to see the latest debates on river basin management</li>
    <li><a href="matchmaking#alerts">Subscribe for alerts</a> to get informed about the latest changes depending on your requirements</li>
  </ul>
  <img title="You can also! Two boats on a flooded river" src="sites/default/files/pictures/you-can-also_products.png">
</div>';

  $export['n52_wieu_you_can_also_products'] = $fe_block_boxes;

  return $export;
}
