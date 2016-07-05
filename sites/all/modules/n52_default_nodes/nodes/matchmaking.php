<?php
/*
 * Copyright (C) 2016
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation.
 * 
 * If the program is linked with libraries which are licensed under one of
 * the following licenses, the combination of the program with the linked
 * library is not considered a "derivative work" of the program:
 * 
 *     - Apache License, version 2.0
 *     - Apache Software License, version 1.0
 *     - GNU Lesser General Public License, version 3
 *     - Mozilla Public License, versions 1.0, 1.1 and 2.0
 *     - Common Development and Distribution License (CDDL), version 1.0
 * 
 * Therefore the distribution of the program linked with libraries licensed
 * under the aforementioned licenses, is permitted by the copyright holders
 * if the distribution is compliant with both the GNU General Public
 * License version 2 and the aforementioned licenses.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 */
function _n52_default_nodes_matchmaking() {
	return array (
		'title' =>  array (
				'en' => 'Matchmaking',
		),
		'alias' => 'matchmaking',
		'text' => array ('en' => '
<p>
The primary goal of the WaterInnEU Portal is to facilitate matchmaking between 
organizations offering products which are relevant to river basin management, 
the potential users of these products, and service providers which can support 
implementation (for example via adaptation of software for use in a specific 
river basin).
</p>
<p>
We have a range of services available that seek to enhance communication 
between these groups by supporting product developers in the dissemination and 
commercialisation of their innovative products and services, and by ensuring 
that end users and service providers can access and implement those products.
</p>
<p>
To join or search our automatic matchmaking service, go to 
<a data-toggle="collapse" data-parent="#accordion" 
	data-target="#service-requests" style="cursor: pointer;"
>Service requests and offers</a>.
</p>
<p>
For bespoke support and advice, go to <a data-toggle="collapse" 
	data-parent="#accordion" data-target="#ask-the-expert" 
	style="cursor: pointer;">Ask the expert</a>.
</p>

<div id="accordion" class="panel-group">
  <!--
  SEARCH
  -->
  <div id="explore-search" class="panel panel-default panel-dark-hightlight">
    <div class="panel-heading panel-heading-dark-highlight collapsed" 
			data-toggle="collapse" data-parent="#accordion" 
			data-target="#search">
        <h3 class="panel-title accordion-toggle">
            <span class="glyphicon glyphicon-search">&nbsp;</span>Search
        </h3>
    </div>
    <div id="search" class="panel-collapse collapse">
      <div class="panel-body">
        In order to find a certain product, organization or service, you may utilize the search tool of the portal.
        <div id="search-form-duplicate">
        </div>
      </div>
    </div>
  </div>
  <!--
    SERVICE REQUESTS
  -->
  <div id="explore-service-requests" class="panel panel-default 
      panel-light-hightlight">
    <div class="panel-heading panel-heading-light-highlight collapsed" 
	      data-toggle="collapse" data-parent="#accordion" 
		  data-target="#service-requests">
        <h3 class="panel-title accordion-toggle">
            <span class="glyphicon glyphicon-tasks">&nbsp;</span>Service 
			Requests and Offers
        </h3>
    </div>
    <div id="service-requests" class="panel-collapse collapse">
      <div class="panel-body">
		<p>
        This is an automatic matchmaking service that allows you to communicate 
		specific problems or solutions.
		</p>
		<p>
		Add a service request or offering by using the forms below or browse to 
		see what it on offer.
		</p>
		<p>
		You can also sign up for alerts to hear when a new service or offering 
		has been added.
		</p>
        <h3>Latest Updates</h3>
          <!-- Nav tabs -->
          <ul class="nav nav-tabs" role="tablist">
            <li>
				<a href="#tab-service-requests" role="tab" data-toggle="tab">
					Service Requests
				</a>
			</li>
            <li class="active">
				<a href="#tab-service-offerings" role="tab" data-toggle="tab">
					Service Offerings
				</a>
			</li>
          </ul>
          <!-- Tab panes -->
          <div class="tab-content">
            <div class="tab-pane" id="tab-service-requests">
              <div id="latest-service-requests"></div>
              <hr />
              <a href="matchmaking/service-requests"><button type="button" 
				  class="btn btn-default">Show all Service Requests</button></a>
			  <a href="node/add/service-request"><button type="button" 
				  class="btn btn-primary">Add new Service Request</button></a>
            </div>
            <div class="tab-pane active" id="tab-service-offerings">
              <div id="latest-service-offerings"></div>
              <hr />
              <a href="matchmaking/service-offerings">
				<button type="button" 
				    class="btn btn-default">
				  Show all Service Offerings
				</button>
			  </a>
            </div>
          </div>
      </div>
    </div>
  </div>
  <!--
    ASK
  -->
  <div id="explore-ask-experts" class="panel panel-default 
      panel-light-hightlight">
    <div class="panel-heading panel-heading-light-highlight collapsed" 
			data-toggle="collapse" data-parent="#accordion" 
			data-target="#ask-the-expert">
        <h3 class="panel-title accordion-toggle">
            <span class="glyphicon glyphicon-question-sign">&nbsp;</span>Ask the
			expert
        </h3>
    </div>
    <div id="ask-the-expert" class="panel-collapse collapse">
      <div class="panel-body">
		<p>
        Please fill in a support request if you would like help with any of the 
		following. One of our experts will get in touch with you as soon as 
		possible.
		</p>
		<ul style="display:none">
			<li>
				Finding an appropriate product: help with product filtering and 
				evaluation
			</li>
			<li>
				Finding a supplier or consultant: help with identifying the type
				of support organisation that would fit your needs
			</li>
			<li>
				Bringing a product to market: we provide a range of bespoke 
				services that are tailored to the development phase of your 
				product. These range from producing promotional material and 
				disseminating to targeted audiences to supporting development 
				of strategic plans, review of your value proposition and 
				development of E-learning materials				
			</li>
			<li>
				Uploading a product or event
			</li>
			<li>
				Using the Forum
			</li>
			<li>
				The E-learning functionality
			</li>
		</ul>
        <br />
        <a href="contact">
			<button type="submit" class="btn btn-primary">
				Ask the expert
			</button>
		</a>
      </div>
    </div>
  </div>
  <!--
    ALERTS
  -->
  <div id="explore-alerts" class="panel panel-default panel-dark-hightlight">
    <div class="panel-heading panel-heading-dark-highlight collapsed" 
			data-toggle="collapse" data-parent="#accordion" 
			data-target="#alerts">
        <h3 class="panel-title accordion-toggle">
            <span class="glyphicon glyphicon-exclamation-sign">&nbsp;</span>Alerts
        </h3>
    </div>
    <div id="alerts" class="panel-collapse collapse">
      <div class="panel-body">
        Sign us to receive an alert when new service offerings and service 
		requests are added to the portal using the form below.
        <h4>Subscribe</h4>
        <div id="subscribe-form"></div>
      </div>
    </div>
  </div>
  <!--
  EVENTS
  -->
  <div id="explore-events" class="panel panel-default panel-light-hightlight">
    <div class="panel-heading panel-heading-light-highlight collapsed" 
			data-toggle="collapse" data-parent="#accordion" 
			data-target="#events">
        <h3 class="panel-title accordion-toggle">
           <span class="glyphicon glyphicon-calendar">&nbsp;</span>Events
       </h3>
    </div>
    <div id="events" class="panel-collapse collapse">
      <div class="panel-body">
        <p>
		The following events are anticipated to be of interest to those seeking 
		partners or support organisations for the development, commercialisation
		or implementation of products.
		</p>
        <br />
        <div id="upcoming-events"></div>
        <a href="node/add/event">
			<button type="button" class="btn btn-primary">Add new Event</button>
		</a> 
		<a href="matchmaking/events">
			<button type="button" class="btn btn-default">
				Show all Events
			</button>
		</a>
      </div>
    </div>
  </div>',),
	);
}