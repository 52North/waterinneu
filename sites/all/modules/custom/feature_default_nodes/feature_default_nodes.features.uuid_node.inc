<?php
/**
 * @file
 * feature_default_nodes.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function feature_default_nodes_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'uid' => 1,
  'title' => 'Landing page - Content accordion',
  'log' => 'add links to explore accordion',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '4d803371-752e-46a6-9bd9-1c866d731df6',
  'type' => 'page',
  'language' => 'en',
  'created' => 1455028469,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '1d229e7a-4ca4-4c5f-86f2-97f531b7c7bd',
  'revision_uid' => 1,
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'waterinneu',
  'picture' => 0,
  'data' => 'a:2:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;}',
  'num_revisions' => 6,
  'current_revision_id' => 8836,
  'is_current' => TRUE,
  'is_pending' => FALSE,
  'revision_moderation' => TRUE,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<div id="accordion" class="panel-group">
	<div class="panel panel-default panel-explore panel-dark-hightlight">
		<div id="headingOne" class="panel-heading panel-heading-explore panel-heading-dark-highlight">
			<h2 class="panel-title">
				<a href="#collapseOne" class="collapsed" data-toggle="collapse"
					data-parent="#accordion"><span
					class="glyphicon glyphicon-search">&nbsp;</span>Explore</a>
			</h2>
		</div>
		<div id="collapseOne" class="panel-collapse collapse in">
			<div class="panel-body">
				<div id="explore-search">
					<a href="/matchmaking"><span class="glyphicon glyphicon-search">&nbsp;</span>Search</a>
				</div>
				<div id="explore-service-requests">
					<a href="/matchmaking"><span class="glyphicon glyphicon-tasks">&nbsp;</span>Service Requests</a>
				</div>
				<div id="explore-alerts">
					<a href="/matchmaking"><span class="glyphicon glyphicon-exclamation-sign">&nbsp;</span>Alerts</a>
				</div>
				<div id="explore-ask-experts">
					<a href="/matchmaking"><span class="glyphicon glyphicon-question-sign">&nbsp;</span>Ask the Expert</a>
				</div>
				<div id="explore-forum">
					<a href="/matchmaking"><span class="glyphicon glyphicon-comment">&nbsp;</span>Open Discussions in Forum</a>
				</div>
				<div id="explore-e-learning">
					<a href="/matchmaking"><span class="glyphicon glyphicon-plus-sign">&nbsp;</span>E-Learning</a>
				</div>
				<div id="explore-events">
					<a href="/matchmaking"><span class="glyphicon glyphicon-calendar">&nbsp;</span>Events</a>
				</div>
			</div>
		</div>
	</div>
	<div class="panel panel-default panel-about panel-light-highlight">
		<div id="headingTwo" class="panel-heading panel-heading-about panel-heading-light-highlight">
			<h2 class="panel-title">
				<a href="#collapseTwo" class="collapsed" data-toggle="collapse"
					data-parent="#accordion"><span
					class="glyphicon glyphicon-info-sign">&nbsp;</span>About</a>
			</h2>
		</div>
		<div id="collapseTwo" class="panel-collapse collapse">
			<div class="panel-body">
				<h3>
					<a id="intro"></a>Introduction
				</h3>
				<p>This sites provides means for finding products, documentation
					about these products, and experts for these products in the
					hydrology domain. In addition, an inventory of projects and
					organisations is available. General questions about tools and
					problems can be discussed in the forum.</p>
				<h3>Goal - What is our aim</h3>
				<div>
					<p>A marketplace to enhance the exploitation of EU funded ICT
						models, tools,&nbsp;protocols and policy briefs related to water
						and to establish suitable conditions for new market opportunities
						based on&nbsp;these offerings. Create the marketplace as a
						service:&nbsp;a forum formed by water research projects
						representatives, stakeholders in the water domain, and companies
						(in particular SMEs), who are capable of moving current products
						into the market and offer them to, for example, river basin
						managers, at different levels. The user segment will mainly
						benefit from the capability of the water partnerships (e.g. the
						Global Water Partnership), in bringing together a wide variety of
						water sector stakeholders and practitioners such as decision
						makers, public and private users, local, regional and
						international entities, multidisciplinary stakeholders.</p>
				</div>
				<h3>Sections - What is inside WaterInnEU</h3>
				<ul>
					<li><a href="#intro">About</a>
						<ul>
							<li>This page. <a href="#intro"></a></li>
							<li><a href="#faqs">FAQs</a> - see down below.</li>
						</ul></li>
					<li><a href="marketplace" title="Open the marketplace!">Forum</a>
						<ul>
							<li>Find <a href="marketplace/demand">products&nbsp;for
									a certain problem category</a>,
							</li>
							<li>Find <a href="marketplace/offering">users for your
									product</a>, and
							</li>
							<li>Find experts for <a href="marketplace/discussion">discussing
									methods and models</a>.
							</li>
						</ul></li>
					<li><a href="tools" title="Open tools inventory">Products</a>
						<ul>
							<li>Get overview about useful products in the hydrology
								domain,</li>
							<li>Find products by search criteria, and</li>
							<li>Review products features and other additional metadat,
								e.g. licensing</li>
						</ul></li>
				</ul>
				<h3>
					<a id="faqs"></a>Frequently asked questions
				</h3>
				<p>We provide an extra FAQ section for you.</p>
				<ul>
					<li><a href="user-guide/faq">Frequently Asked Questions</a></li>
				</ul>
				<h3>Backstage - Who is driving WaterInnEU</h3>
				<ul>
					<li><a href="http://52north.org/" target="_blank">52°North</a></li>
					<li><a href="https://www.adelphi.de/en" target="_blank">adelphi</a></li>
					<li><a href="http://www.anteagroup.be/en" target="_blank">Antea</a></li>
					<li><a href="http://www.creaf.cat/en" target="_blank">CREAF</a></li>
					<li><a
						href="http://www.gwp.org/gwp-in-action/Central-and-Eastern-Europe/"
						title="Global Water Partnership - Central and Eastern Europe">GWP-CEE</a></li>
					<li><a href="http://www.orioninnovations.co.uk/"
						target="_blank">Orion</a></li>
					<li><a href="http://www.randbee.com/" target="_blank">Randbee</a></li>
					<li><a href="http://www.tudelft.nl/en/" target="_blank">TU-Delft</a></li>
				</ul>
				<h3>Links - Who is Doing Related Work</h3>
				<ul>
					<li><a href="http://www.aquaknow.net/" target="_blank"
						title="aquaknow.net">Aquaknow</a></li>
					<li><a href="http://his.cuahsi.org/index.html" target="_blank">CUAHSI-HIS</a></li>
					<li><a href="http://datahub.io/">Datahub</a></li>
					<li><a href="http://www.eea.europa.eu/themes/water/dc">EEA
							Water Centre</a></li>
					<li><a href="http://www.eionet.europa.eu/">EIONET</a></li>
					<li><a href="http://www.eip-water.eu/">EIP Water</a></li>
					<li><a href="https://open-data.europa.eu/en/data"
						target="_blank">EU Open Data Portal</a></li>
					<li><a href="http://floods.jrc.ec.europa.eu/" target="_blank">European
							Floods Portal</a></li>
					<li><a href="http://ec.europa.eu/eurostat" target="_blank">EUROSTAT
							Open Data Portal</a></li>
					<li><a href="http://europeanwatercommunity.eu/"
						target="_blank">European Water Community (EWC)</a></li>
					<li><a
						href="http://ec.europa.eu/research/environment/index_en.cfm?section=geo&amp;pg=geoss"
						target="_blank">GEOSS</a></li>
					<li><a href="http://inspire-geoportal.ec.europa.eu/"
						target="_blank">INSPIRE Geoportal</a></li>
					<li><a href="http://www.water-switch-on.eu/" target="_blank">SWITCH-ON</a></li>
					<li><a href="http://water.europa.eu/" target="_blank">WISE</a></li>
					<li><a href="http://www.wise-rtd.info/en" target="_blank">WISE-RTD</a></li>
				</ul>
			</div>
		</div>
	</div>
	<div class="panel panel-default panel-our-services panel-dark-hightlight">
		<div id="headingThree"
			class="panel-heading panel-heading-our-services panel-heading-dark-highlight">
			<h2 class="panel-title">
				<a href="#collapseThree" class="collapsed" data-toggle="collapse"
					data-parent="#accordion"><span
					class="glyphicon glyphicon-shopping-cart">&nbsp;</span>Our Services</a>
			</h2>
		</div>
		<div id="collapseThree" class="panel-collapse collapse">
			<div class="panel-body">Anim pariatur cliche reprehenderit,
				enim eiusmod high life accusamus terry richardson ad squid. 3 wolf
				moon officia aute, non cupidatat skateboard dolor brunch. Food truck
				quinoa nesciunt laborum eiusmod. Brunch 3 wolf moon tempor, sunt
				aliqua put a bird on it squid single-origin coffee nulla assumenda
				shoreditch et. Nihil anim keffiyeh helvetica, craft beer labore wes
				anderson cred nesciunt sapiente ea proident. Ad vegan excepteur
				butcher vice lomo. Leggings occaecat craft beer farm-to-table, raw
				denim aesthetic synth nesciunt you probably haven\'t heard of them
				accusamus labore sustainable VHS.</div>
		</div>
	</div>
	<div class="panel panel-default panel-upcoming-events panel-light-highlight">
		<div id="headingThree1"
			class="panel-heading panel-heading-upcoming-events panel-heading-light-highlight">
			<h2 class="panel-title">
				<a href="#collapseThree1" class="collapsed" data-toggle="collapse"
					data-parent="#accordion"><span
					class="glyphicon glyphicon-calendar">&nbsp;</span>Upcoming Events</a>
			</h2>
		</div>
		<div id="collapseThree1" class="panel-collapse collapse">
			<div class="panel-body">Here we list the upcoming events during
				the next weeks or at least one.</div>
		</div>
	</div>
</div>
',
        'summary' => '',
        'format' => 'full_html_plain_no_filter_',
      ),
    ),
  ),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Landing page - Content accordion',
        'format' => NULL,
        'safe_value' => 'Landing page - Content accordion',
      ),
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2016-02-09 14:34:29 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Matchmaking',
  'log' => 'remove add service offering button',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '8a198686-5bda-4401-96cb-9f87f0d1bcb9',
  'type' => 'page',
  'language' => 'en',
  'created' => 1456744379,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '21a8977e-8b1e-4313-acb8-f3394268cb6c',
  'revision_uid' => 1,
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'waterinneu',
  'picture' => 0,
  'data' => 'a:2:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;}',
  'num_revisions' => 9,
  'current_revision_id' => 8837,
  'is_current' => TRUE,
  'is_pending' => FALSE,
  'revision_moderation' => TRUE,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => 'The primary goal of the WaterInnEU Portal is to facility a match making between organizations offering certain products for River Basin Management, potential users of these products, and service providers that provide specific services for these products, e.g. to customize a software for a particular river basin. To enable such a match making, the portal provides the functionalities listed below.
<!--
SEARCH
-->
<div id="accordion" class="panel-group">
  <div id="explore-search" class="panel panel-default panel-dark-hightlight">
    <div class="panel-heading panel-heading-dark-highlight">
      <div class="panel-title">
        <h3><a href="#search" class="collapsed" data-toggle="collapse" data-parent="#accordion"><span class="glyphicon glyphicon-search">&nbsp;</span>Search</a></h3>
      </div>
    </div>
    <div id="search" class="panel-collapse collapse">
      <div class="panel-body">
        In order to find a certain product, organization or service, you may utilize the search tool of the portal.
        <div id="search-form-duplicate">
          <form style="float: unset;" class="search-form" role="search" action="/matchmaking" method="post" id="custom-search-blocks-form-1" accept-charset="UTF-8" target="_self">
            <div>
              <div class="form-item form-type-searchfield form-item-custom-search-blocks-form-1">
                <label class="element-invisible" for="edit-custom-search-blocks-form-1--2">Search this site </label>
                <input title="Enter the terms you wish to search for." class="custom-search-box form-text form-search form-autocomplete ui-autocomplete-processed ui-autocomplete-input" placeholder="search portal" type="search" id="edit-custom-search-blocks-form-1--2" name="custom_search_blocks_form_1" value="" size="20" maxlength="128" data-sa-theme="basic-blue" autocomplete="off"><span role="status" aria-live="polite" class="ui-helper-hidden-accessible"></span>
                <ul class="ui-autocomplete ui-front ui-menu ui-widget ui-widget-content ui-corner-all" id="ui-id-1" tabindex="0" data-sa-theme="basic-blue" style="display: none;"></ul>
              </div>
              <fieldset class="custom_search-popup form-wrapper custom_search-processed opened" id="edit-popup" style="display: block;">
                <div class="fieldset-wrapper">
                  <a href="/en/search/wizard">Advanced Search</a>
                  <div class="form-item form-type-checkboxes form-item-custom-search-types">
                    <label for="edit-custom-search-types">Search for </label>
                    <div id="edit-custom-search-types" class="form-checkboxes custom-search-selector custom-search-types">
                      <div class="form-item form-type-checkbox form-item-custom-search-types-c-all">
                        <input class="custom-search-selector custom-search-types form-checkbox" type="checkbox" id="edit-custom-search-types-c-all" name="custom_search_types[c-all]" value="c-all" checked="checked">
                        <label class="option" for="edit-custom-search-types-c-all">-Any- </label>
                      </div>
                      <div class="form-item form-type-checkbox form-item-custom-search-types-c-organisation">
                        <input class="custom-search-selector custom-search-types form-checkbox" type="checkbox" id="edit-custom-search-types-c-organisation" name="custom_search_types[c-organisation]" value="c-organisation">
                        <label class="option" for="edit-custom-search-types-c-organisation">Organisation </label>
                      </div>
                      <div class="form-item form-type-checkbox form-item-custom-search-types-c-portal">
                        <input class="custom-search-selector custom-search-types form-checkbox" type="checkbox" id="edit-custom-search-types-c-portal" name="custom_search_types[c-portal]" value="c-portal">
                        <label class="option" for="edit-custom-search-types-c-portal">Portal </label>
                      </div>
                      <div class="form-item form-type-checkbox form-item-custom-search-types-c-tool">
                        <input class="custom-search-selector custom-search-types form-checkbox" type="checkbox" id="edit-custom-search-types-c-tool" name="custom_search_types[c-tool]" value="c-tool">
                        <label class="option" for="edit-custom-search-types-c-tool">Product </label>
                      </div>
                      <div class="form-item form-type-checkbox form-item-custom-search-types-c-project">
                        <input class="custom-search-selector custom-search-types form-checkbox" type="checkbox" id="edit-custom-search-types-c-project" name="custom_search_types[c-project]" value="c-project">
                        <label class="option" for="edit-custom-search-types-c-project">Project </label>
                      </div>
                    </div>
                  </div>
                </div>
                <a class="custom_search-popup-close" href="#">Close</a>
              </fieldset>
              <div class="form-actions form-wrapper" id="edit-actions--2">
                <input style="display:none;" type="submit" id="edit-submit--3" name="op" value="" class="form-submit">
              </div>
              <input type="hidden" name="delta" value="1">
              <input type="hidden" name="form_build_id" value="form-P5FY_hbZNrmjYFiyosxk_GRQLLgxSMnJcQ3sIYoBskE">
              <input type="hidden" name="form_token" value="VLCH3PgYmks2Apj7-8mNjvjXSw2xMOd65WIssa4IyEw">
              <input type="hidden" name="form_id" value="custom_search_blocks_form_1">
            </div>
          </form>
        </div>
      </div>
    </div>
  </div>
  <!--
    SERVICE REQUESTS
  -->
  <div id="explore-service-requests" class="panel panel-default panel-light-hightlight">
    <div class="panel-heading panel-heading-light-highlight">
      <div class="panel-title">
        <h3><a href="#service-requests" class="collapsed" data-toggle="collapse" data-parent="#accordion"><span class="glyphicon glyphicon-tasks">&nbsp;</span>Service Requests and Offers</a></h3>
      </div>
    </div>
    <div id="service-requests" class="panel-collapse collapse">
      <div class="panel-body">
        If you need a specific service, for a product, you may browse the service offers listed below or add a new service request.
        <h3>Latest Updates</h3>
          <!-- Nav tabs -->
          <ul class="nav nav-tabs" role="tablist">
            <li><a href="#tab-1" role="tab" data-toggle="tab">Service Requests</a></li>
            <li class="active"><a href="#tab-2" role="tab" data-toggle="tab">Service Offerings</a></li>
          </ul>
          <!-- Tab panes -->
          <div class="tab-content">
            <div class="tab-pane" id="tab-1">
              <div class="view">
                <div class="view-content">
                  <div class="item-list">
                    <ul>
                      <li class="views-row-odd views-row-first views-row">
                        7 min 11 sec ago a new request by waterinneu: <br /><a href="/en/javascript-required">Javascript Required</a>
                      </li>
                      <li class="views-row-even views-row">
                        1 min 33 sec ago a new request by waterinneu: <br /><a href="/en/matchmaking">Matchmaking</a>
                      </li>
                    </ul>
                  </div>
                </div>
              </div>
            </div>
            <div class="tab-pane active" id="tab-2">
              <div class="view">
                <div class="view-content">
                  <div class="item-list">
                    <ul>
                      <li class="views-row views-row-1 views-row-odd views-row-first">
                        Reply to <a href="/en/organisation/3d-environmental-change-3d-ec">3D-Environmental Change (3D-EC)</a> around 25.02.2016 - 15:52 UTC by  waterinneu: <br/><a href="/en/comment/3#comment-3">This organisation comes from...</a>
                      </li>
                      <li class="views-row views-row-2 views-row-even">
                        Reply to <a href="/en/product/52%C2%B0north-sos">52&deg;North SOS</a> around 18.02.2016 - 14:30 UTC by test-author: <br/> <a href="/en/comment/2#comment-2">This is a test comment title...</a></span>
                      </li>
                    </ul>
                  </div>
                </div>
              </div>
            </div>
          </div>
          <hr />
          <a href="/node/add/service-request"><button type="submit" class="btn btn-primary">Add new Service Request</button></a>
      </div>
    </div>
  </div>
  <!--
    ALERTS
  -->
  <div id="explore-alerts" class="panel panel-default panel-dark-hightlight">
    <div class="panel-heading panel-heading-dark-highlight">
      <div class="panel-title">
        <h3><a href="#alerts" class="collapsed" data-toggle="collapse" data-parent="#accordion"><span class="glyphicon glyphicon-exclamation-sign">&nbsp;</span>Alerts</h3></a>
      </div>
    </div>
    <div id="alerts" class="panel-collapse collapse">
      <div class="panel-body">
        In case you don’t want to miss a new product that is registered at the portal or a new service offer/request, you can subscribe for new products, service offers, and service requests. Therefore, please use the form below.
        <h4>Subscribe</h4>
        <form class="form-horizontal" role="form">
          <div class="form-group">
            <label for="inputEmail3" class="col-sm-2 control-label">Email<span class="form-required" title="This field is required.">*</span></label>
            <div class="col-sm-10">
              <input type="email" class="form-control" id="inputEmail3" placeholder="Email">
            </div>
          </div>
          <div class="form-group">
            <label for="service-request-category" class="col-sm-2 control-label">Service Request Category<span class="form-required" title="This field is required.">*</span></label>
            <div class="col-sm-10">
              <select multiple="multiple" class="form-control" id="service-request-category" style="-webkit-appearance: initial;">
                <option>Biological or chemical treatment</option>
                <option>Socio-economic analysis</option>
                <option>Electrical &amp; mechanical services</option>
                <option>Instrumentation and control (hardware)</option>
                <option>Monitoring, measuring &amp; data processing (software)</option>
                <option>Research</option>
                <option>Waste water treatment</option>
                <option>Water conservation and recycling</option>
                <option>Ecosystem services</option>
                <option>Finance and funding</option>
                <option>Irrigation &amp; drainage</option>
                <option>Modelling and decision support</option>
                <option>Pipes and pipelines</option>
                <option>Pumps, tanks &amp; valves</option>
                <option>Training</option>
                <option>Waste and sludge disposal</option>
                <option>Water supply and treatment</option>
                <option>GIS and remote sensing</option>
              </select>
              <span class="help-block">For selecting for than one entry, use <kbd>crtl + leftclick</kbd>.</span>
            </div>
          </div>
          <div class="form-group">
            <label for="request-description" class="col-sm-2 control-label">Request Description<span class="form-required" title="This field is required.">*</span></label>
            <div class="col-sm-10">
              <textarea class="form-control" rows="3" id="request-description"></textarea>
              <span class="help-block">Please give as much information as possible for making your request understandble for others.</span>
            </div>
          </div>
          <div class="form-group">
            <div class="col-sm-offset-2 col-sm-10">
              <div class="checkbox">
                <label>
                  <input type="checkbox"> Remember me
                </label>
              </div>
            </div>
          </div>
          <div class="form-group">
            <div class="col-sm-offset-2 col-sm-10">
              <button type="submit" class="btn btn-primary">Subscribe</button>
            </div>
          </div>
        </form>
      </div>
    </div>
  </div>
  <!--
    ASK
  -->
  <div id="explore-ask-experts" class="panel panel-default panel-light-hightlight">
    <div class="panel-heading panel-heading-light-highlight">
      <div class="panel-title">
        <h3><a href="#ask-the-expert" class="collapsed" data-toggle="collapse" data-parent="#accordion"><span class="glyphicon glyphicon-question-sign">&nbsp;</span>Ask the expert</a></h3>
      </div>
    </div>
    <div id="ask-the-expert" class="panel-collapse collapse">
      <div class="panel-body">
        In case the tools provided above did not help you to find the right product or service, you can contact the WaterInnEU expert panel with a <a href="/contact">contact form</a> with a specific request.
        <br />
        <a href="/contact"><button type="submit" class="btn btn-primary">Ask the expert</button></a>
      </div>
    </div>
  </div>
  <!--
  FORUM
  -->
  <div id="explore-forum" class="panel panel-default panel-dark-hightlight">
    <div class="panel-heading panel-heading-dark-highlight">
      <div class="panel-title">
        <h3><a href="#forum" class="collapsed" data-toggle="collapse" data-parent="#accordion"><span class="glyphicon glyphicon-comment">&nbsp;</span>Open discussions in Forum</a></h3>
      </div>
    </div>
    <div id="forum" class="panel-collapse collapse">
      <div class="panel-body">
        The WaterInnEU <a href="/forum">discussion forum</a> is meant to be used for open discussion on products or specific services. Feel free to add a new thread or contribute to existing threads.
        <h4>Latest Threads</h4>
        <ul>
          <li class="views-row views-row-1 views-row-odd views-row-first">
            <div class="views-field views-field-title">
              <span class="field-content"><a href="/en/forum/thread/5/52%C2%B0north-sos-testing-autocompletion">52°North SOS - Testing autocompletion</a></span>
            </div>
            <span class="views-field views-field-updated">
              <span class="field-content">12.11.2015 - 13:47 UTC</span>
            </span>
            <span class="views-field views-field-field-harmony-category">
              <span class="field-content"><a href="/en/forum/discussion" typeof="skos:Concept" property="rdfs:label skos:prefLabel">Discussion</a></span>
            </span>
            <span class="views-field views-field-harmony-thread-replies">
              <span class="field-content">1 reply</span>
            </span>
          </li>
          <li class="views-row views-row-2 views-row-even">
            <div class="views-field views-field-title">
              <span class="field-content"><a href="/en/forum/thread/4/i-want-more-rights">I want more rights!</a></span>
            </div>
            <span class="views-field views-field-updated">
              <span class="field-content">16.10.2015 - 11:44 UTC</span>
            </span>
            <span class="views-field views-field-field-harmony-category">
              <span class="field-content"><a href="/en/forum/discussion" typeof="skos:Concept" property="rdfs:label skos:prefLabel">Discussion</a></span>
            </span>
            <span class="views-field views-field-harmony-thread-replies">
              <span class="field-content">1 reply</span>
            </span>
          </li>
        </ul>
        <a href="/forum"><button type="submit" class="btn btn-primary">Enter forum</button></a>
      </div>
    </div>
  </div>
  <!--
  EVENTS
  -->
  <div id="explore-events" class="panel panel-default panel-light-hightlight">
    <div class="panel-heading panel-heading-light-highlight">
      <div class="panel-title">
        <h3><a href="#events" class="collapsed" data-toggle="collapse" data-parent="#accordion"><span class="glyphicon glyphicon-calendar">&nbsp;</span>Events</a></h3>
      </div>
    </div>
    <div id="events" class="panel-collapse collapse">
      <div class="panel-body">
        The following upcoming events may be used to find appropriate product or service providers as well users of them:
      </div>
    </div>
  </div>
</div>
',
        'summary' => '',
        'format' => 'full_html_plain_no_filter_',
      ),
    ),
  ),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Matchmaking',
        'format' => NULL,
        'safe_value' => 'Matchmaking',
      ),
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2016-02-29 11:12:59 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Success Stories',
  'log' => 'initial placeholder',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '4a7567a0-de50-4f1e-bb2a-30109223db66',
  'type' => 'page',
  'language' => 'en',
  'created' => 1457094216,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '2864c507-68d5-4a1a-b35f-cf8115741cfc',
  'revision_uid' => 1,
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'waterinneu',
  'picture' => 0,
  'data' => 'a:2:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;}',
  'num_revisions' => 1,
  'current_revision_id' => 8838,
  'is_current' => TRUE,
  'is_pending' => FALSE,
  'revision_moderation' => TRUE,
  'body' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Success Stories',
        'format' => NULL,
        'safe_value' => 'Success Stories',
      ),
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2016-03-04 12:23:36 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'E-Learning',
  'log' => 'initial version as place-holder',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '77f1b012-dcaa-498e-8197-49742a05d0d6',
  'type' => 'page',
  'language' => 'en',
  'created' => 1457094474,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '3671df96-e613-438f-a338-0326fc699d84',
  'revision_uid' => 1,
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'waterinneu',
  'picture' => 0,
  'data' => 'a:2:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;}',
  'num_revisions' => 1,
  'current_revision_id' => 8839,
  'is_current' => TRUE,
  'is_pending' => FALSE,
  'revision_moderation' => TRUE,
  'body' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'E-Learning',
        'format' => NULL,
        'safe_value' => 'E-Learning',
      ),
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2016-03-04 12:27:54 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Javascript Required',
  'log' => 'add missing domains.',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => 'b9bfffa3-d4a8-4979-b1ad-7ef37c88b279',
  'type' => 'page',
  'language' => 'en',
  'created' => 1456746004,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'be7ceb09-e94a-4a7e-82db-e6b22edfad29',
  'revision_uid' => 1,
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'waterinneu',
  'picture' => 0,
  'data' => 'a:2:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;}',
  'num_revisions' => 2,
  'current_revision_id' => 8825,
  'is_current' => TRUE,
  'is_pending' => FALSE,
  'revision_moderation' => TRUE,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => 'This page uses javascript to get interactive elements working. Hence, please allow javascript for
<ul>
  <li><code>this domain</code></li>
  <li><code>cdn.syndication.twimg.com</code></li>
  <li><code>fonts.googleapis.com</code></li>
  <li><code>maxcdn.bootstrapcdn.com</code></li>
  <li><code>pbs.twimg.com</code></li>
  <li><code>platform.twitter.com</code></li>
  <li><code>syndication.twitter.com</code></li>
</ul>
If you have any concerns about the used javascript sources, feel free to tell us using our <a href="/contact">contact form</a>!',
        'summary' => '',
        'format' => 'full_html_plain_no_filter_',
      ),
    ),
  ),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Javascript Required',
        'format' => NULL,
        'safe_value' => 'Javascript Required',
      ),
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2016-02-29 11:40:04 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Imprint',
  'log' => 'initial version',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => 'be23a290-582d-46b0-ac38-fe013cf9422e',
  'type' => 'page',
  'language' => 'en',
  'created' => 1456152513,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'f93e23d4-3109-4847-a583-c5e888c24c58',
  'revision_uid' => 1,
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'waterinneu',
  'picture' => 0,
  'data' => 'a:2:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;}',
  'num_revisions' => 1,
  'current_revision_id' => 8818,
  'is_current' => TRUE,
  'is_pending' => FALSE,
  'revision_moderation' => TRUE,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<p><a href="http://52north.org/" target="_blank">52°North GmbH</a> is responsible for this website.<br>52°North Initiative for Geospatial Open Source Software GmbH<br>Martin-Luther-King-Weg 24<br>48155 Münster, Deutschland</p><p>&nbsp;</p>',
        'summary' => '',
        'format' => 'full_html_tinymce',
      ),
    ),
  ),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Imprint',
        'format' => NULL,
        'safe_value' => 'Imprint',
      ),
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2016-02-22 14:48:33 +0000',
);
  return $nodes;
}
