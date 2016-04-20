<?php
/**
 * @file
 * n52_feature_products.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function n52_feature_products_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function n52_feature_products_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function n52_feature_products_node_info() {
  $items = array(
    'tool' => array(
      'name' => t('Product'),
      'base' => 'node_content',
      'description' => t('Product description missing. If you have any, send it to e.h.juerrens@52north.org'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('The submission of product specification sheets underlies a moderation workflow. Hence, adding new content might cost some time. Get in touch with the administrator for speeding things up using the <a href="/contact">helpdesk form</a>. <br/>
Please consider the following additional instructions to some of the fields below.

<table>
<tr>
<th class="table-label">Field</th>
<th>Additional Information</th>
</tr>
<tr>
<td class="table-label">Description:</td>
<td>Short description of the product and background information</td>
</tr>
<tr>
<td class="table-label">Related Links and Supporting Material:</td>
<td>Links to websites of the product or to projects where the product has been implemented.<br />Download material such as worksheets by the supplier of the product.</td>
</tr>
<tr>
<td class="table-label">License / Copyright:</td>
<td>Please give details of accessibility criteria in the free text box when selecting <b>other</b>.</td>
</tr>
<tr>
<td class="table-label">Costs:</td>
<td>For example, licence costs, costs for implementation and development of the product.<br />Please give cost details in the free text box.</td>
</tr>
<tr>
<td class="table-label">Type of output:</td>
<td>For example, analysed and prepared data qualitative data of stakeholder dialogues, model visualisation, alerts etc.</td>
</tr>
<tr>
<td class="table-label">Potential to combine this tool with other tools:</td>
<td>For example, products in support of better integration e.g. an integrated model for linkage between surface waters and groundwater or climate models; software tools etc.</td>
</tr>
<tr>
<td class="table-label">Contact details:</td>
<td>E-mail, telephone, country etc.</td>
</tr>
<tr>
<td class="table-label">Comments:</td>
<td>Recommendations by product supplier and users.</td>
</tr>
</table>

Product deletion is only possible by admins. If you want to have a product deleted, please use the <a href="/contact">contact form</a>.
Get in touch with our <a href="helpdeskt">helpdesk</a> if your content does not fit in this form.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
