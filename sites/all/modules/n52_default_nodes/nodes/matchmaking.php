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
		'title' => 'Matchmaking',
		'alias' => 'matchmaking',
		'text' => array ('und' => '
The primary goal of the WaterInnEU Portal is to facility a match making between organizations offering certain products for River Basin Management, potential users of these products, and service providers that provide specific services for these products, e.g. to customize a software for a particular river basin. To enable such a match making, the portal provides the functionalities listed below.

<div id="accordion" class="panel-group">
  <!--
  SEARCH
  -->
  <div id="explore-search" class="panel panel-default panel-dark-hightlight">
    <div class="panel-heading panel-heading-dark-highlight collapsed" data-toggle="collapse" data-parent="#accordion" data-target="#search">
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
  <div id="explore-service-requests" class="panel panel-default panel-light-hightlight">
    <div class="panel-heading panel-heading-light-highlight collapsed" data-toggle="collapse" data-parent="#accordion" data-target="#service-requests">
        <h3 class="panel-title accordion-toggle">
            <span class="glyphicon glyphicon-tasks">&nbsp;</span>Service Requests and Offers
        </h3>
    </div>
    <div id="service-requests" class="panel-collapse collapse">
      <div class="panel-body">
        If you need a specific service, for a product, you may browse the service offers listed below or add a new service request.
        <h3>Latest Updates</h3>
          <!-- Nav tabs -->
          <ul class="nav nav-tabs" role="tablist">
            <li><a href="#tab-service-requests" role="tab" data-toggle="tab">Service Requests</a></li>
            <li class="active"><a href="#tab-service-offerings" role="tab" data-toggle="tab">Service Offerings</a></li>
          </ul>
          <!-- Tab panes -->
          <div class="tab-content">
            <div class="tab-pane" id="tab-service-requests">
              <div id="latest-service-requests"></div>
              <hr />
              <a href="matchmaking/service-requests"><button type="button" class="btn btn-default">Show all Service Requests</button></a> <a href="node/add/service-request"><button type="button" class="btn btn-primary">Add new Service Request</button></a>
            </div>
            <div class="tab-pane active" id="tab-service-offerings">
              <div id="latest-service-offerings"></div>
              <hr />
              <a href="matchmaking/service-offerings"><button type="button" class="btn btn-default">Show all Service Offerings</button></a>
            </div>
          </div>
      </div>
    </div>
  </div>
  <!--
    ALERTS
  -->
  <div id="explore-alerts" class="panel panel-default panel-dark-hightlight">
    <div class="panel-heading panel-heading-dark-highlight collapsed" data-toggle="collapse" data-parent="#accordion" data-target="#alerts">
        <h3 class="panel-title accordion-toggle">
            <span class="glyphicon glyphicon-exclamation-sign">&nbsp;</span>Alerts
        </h3>
    </div>
    <div id="alerts" class="panel-collapse collapse">
      <div class="panel-body">
        In case you don’t want to miss a new product that is registered at the portal or a new service offer/request, you can subscribe for new products, service offers, and service requests. Therefore, please use the form below.
        <h4>Subscribe</h4>
        <div id="subscribe-form"></div>
      </div>
    </div>
  </div>
  <!--
    ASK
  -->
  <div id="explore-ask-experts" class="panel panel-default panel-light-hightlight">
    <div class="panel-heading panel-heading-light-highlight collapsed" data-toggle="collapse" data-parent="#accordion" data-target="#ask-the-expert">
        <h3 class="panel-title accordion-toggle">
            <span class="glyphicon glyphicon-question-sign">&nbsp;</span>Ask the expert
        </h3>
    </div>
    <div id="ask-the-expert" class="panel-collapse collapse">
      <div class="panel-body">
        In case the tools provided above did not help you to find the right product or service, you can contact the WaterInnEU expert panel with a contact form with a specific request.
        <br />
        <a href="contact"><button type="submit" class="btn btn-primary">Ask the expert</button></a>
      </div>
    </div>
  </div>
  <!--
  FORUM
  -->
  <div id="explore-forum" class="panel panel-default panel-dark-hightlight">
    <div class="panel-heading panel-heading-dark-highlight collapsed" data-toggle="collapse" data-parent="#accordion" data-target="#forum">
        <h3 class="panel-title accordion-toggle">
            <span class="glyphicon glyphicon-comment">&nbsp;</span>Open discussions in Forum
        </h3>
    </div>
    <div id="forum" class="panel-collapse collapse">
      <div class="panel-body">
        The WaterInnEU <a href="forum">discussion forum</a> is meant to be used for open discussion on products or specific services. Feel free to add a new thread or contribute to existing threads.
        <h4>Latest Threads</h4>
        <div id="latest-forum-threads"></div>
        <a href="forum"><button type="submit" class="btn btn-primary">Enter forum</button></a>
      </div>
    </div>
  </div>
  <!--
  EVENTS
  -->
  <div id="explore-events" class="panel panel-default panel-light-hightlight">
    <div class="panel-heading panel-heading-light-highlight collapsed" data-toggle="collapse" data-parent="#accordion" data-target="#events">
        <h3 class="panel-title accordion-toggle">
           <span class="glyphicon glyphicon-calendar">&nbsp;</span>Events
       </h3>
    </div>
    <div id="events" class="panel-collapse collapse">
      <div class="panel-body">
        The following upcoming events may be used to find appropriate product or service providers as well users of them:
        <br />
        <div id="upcoming-events"></div>
        <a href="node/add/event"><button type="button" class="btn btn-primary">Add new Event</button></a> <a href="matchmaking/events"><button type="button" class="btn btn-default">Show all Events</button></a>
      </div>
    </div>
  </div>',),
	);
}