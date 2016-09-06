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
				'en' => 'Matchmaking and Support Services',
				'de' => 'Kontaktvemittlung',
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
		see what is on offer.
		</p>
		<p>
		You can also sign up for alerts to hear when a new service request or offering 
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
    <div class="panel-heading panel-heading-dark-highlight collapsed" 
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
		<ul>
			<li>
				<strong>Finding an appropriate product:</strong> help with product 
				filtering and evaluation
			</li>
			<li>
				<strong>Finding a supplier or consultant:</strong> help with 
				identifying the type of support organisation that would fit your needs
			</li>
			<li>
				<strong>Bringing a product to market:</strong> we provide a range of 
				bespoke services that are tailored to the development phase of your 
				product. These range from producing promotional material and 
				disseminating to targeted audiences to supporting development 
				of strategic plans, review of your value proposition and 
				development of E-learning materials				
			</li>
			<li>
				<strong>For technical support:</strong> please use the Contact/Helpdesk 
				button below	
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
    <div class="panel-heading panel-heading-light-highlight collapsed" 
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
    <div class="panel-heading panel-heading-dark-highlight collapsed" 
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
  </div>',
		'de' => '<p>
Das prim&auml;re Ziel des WaterInnEU Portal ist es, eine Partnervermittlung zwischen
Organisationen, die Produkte im Bereich der Flussgebiets-Verwaltung anbieten, und
potenziellen Nutzern dieser Produkte sowie Dienstleistern, die bei der Umsetzung
unterst&uuml;tzen (beispielsweise durch Anpassung der Software f&uuml;r den Einsatz in einem bestimmten
Flussbecken), zu erm&ouml;glichen.
</p>
<p>
Wir verf&uuml;gen &uuml;ber eine Reihe von Diensten, die die Kommunikation
zwischen diesen Gruppen zu verbessern, indem Produktentwickler bei der Verbreitung und
Vermarktung ihrer innovativen Produkte und Dienstleistungen unterst&uuml;tzt werden, und indem
sichergestellt wird, dass die Endnutzer und Dienstleister
auf diese Produkte zugreifen k&ouml;nnen.
</p>
<p>
Um an unserem automatischen Vermittlungsdienst teilzunehmen oder diesen zu durchsuchen, gehen Sie zu
<a data-toggle="collapse" data-parent="#accordion"
data-target="#service-requests" style="cursor: pointer;"
>Service-Anfragen und -Angebote</a>.
</p>
<p>
F&uuml;r ma&szlig;geschneiderte Unterst&uuml;tzung und Beratung, gehen Sie zu <a data-toggle="collapse"
data-parent="#accordion" data-target="#ask-the-expert"
style="cursor: pointer;">Frag den Experten</a>.
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
      <span class="glyphicon glyphicon-search">&nbsp;</span>Suche
  </h3>
</div>
<div id="search" class="panel-collapse collapse">
<div class="panel-body">
  Um ein bestimmtes Produkt, eine Organisation oder eine Dienstleistung zu finden, k&ouml;nnen Sie das Suchwerkzeug des Portals nutzen.
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
      <span class="glyphicon glyphicon-tasks">&nbsp;</span>Service-Anfragen und -Angebote
  </h3>
</div>
<div id="service-requests" class="panel-collapse collapse">
<div class="panel-body">
<p>
Dies ist ein automatischer Vermittlungsdienst, der Ihnen erlaubt,
spezifische Probleme oder L&ouml;sungen zu kommunizieren.
</p>
<p>
F&uuml;gen Sie mit Hilfe der unten stehenden Formulare eine Service-Anfrage oder ein Service-Angebot hinzu oder durchsuchen die die vorhandenen Elemente.
</p>
<p>
Sie k&ouml;nnen sich auch f&uuml;r Benachrichtigungen anmelden, um zu erfahren, wenn ein neues Service-Angebot oder eine Service-Anfrage
hinzugef&uuml;gt wurde.
</p>
  <h3>Letzte &Auml;nderungen</h3>
    <!-- Nav tabs -->
    <ul class="nav nav-tabs" role="tablist">
      <li>
  <a href="#tab-service-requests" role="tab" data-toggle="tab">
    Service-Anfragen
  </a>
</li>
      <li class="active">
  <a href="#tab-service-offerings" role="tab" data-toggle="tab">
    Service-Angebote
  </a>
</li>
    </ul>
    <!-- Tab panes -->
    <div class="tab-content">
      <div class="tab-pane" id="tab-service-requests">
        <div id="latest-service-requests"></div>
        <hr />
        <a href="matchmaking/service-requests"><button type="button"
    class="btn btn-default">Zeige alle Service-Anfragen</button></a>
  <a href="node/add/service-request"><button type="button"
    class="btn btn-primary">Erstelle neue Service-Anfrage</button></a>
      </div>
      <div class="tab-pane active" id="tab-service-offerings">
        <div id="latest-service-offerings"></div>
        <hr />
        <a href="matchmaking/service-offerings">
  <button type="button"
      class="btn btn-default">
    Zeige alle Service-Angebote
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
<div class="panel-heading panel-heading-dark-highlight collapsed"
data-toggle="collapse" data-parent="#accordion"
data-target="#ask-the-expert">
  <h3 class="panel-title accordion-toggle">
      <span class="glyphicon glyphicon-question-sign">&nbsp;</span>Frag den Experten
  </h3>
</div>
<div id="ask-the-expert" class="panel-collapse collapse">
<div class="panel-body">
<p>
Bitte erstellen Sie eine Support-Anfrage, wenn Sie bei einem der folgenden Punkte Hilfe ben&ouml;tigen.
Einer unserer Experten wird sich mit Ihnen schnellstm&ouml;glich in Verbindung setzen.
</p>
<ul>
<li>
  <strong>Finden eines passenden Produkts:</strong>
  Helfen Sie bei der Produktfilterung und -auswertung
</li>
<li>
  <strong>Finden eines Lieferanten oder Beraters:</strong> Helfen Sie
  beim Identifizieren des Typs der Hilfsorganisation, die Ihren Bed&uuml;rfnissen gen&uuml;gt
</li>
<li>
  <strong>Bringen Sie ein Produkt auf den Markt:</strong>
  Wir bieten eine Reihe von
   ma&szlig;geschneiderten Dienstleistungen, die auf die Entwicklungsphase Ihres
   Produkts zugeschnitten sind. Diese reichen von der Herstellung von Werbematerial und
   Verteilung an Zielgruppen bis hin zu Unterst&uuml;tzung bei der Entwicklung
  von strategischen Pl&auml;nen, Pr&uuml;fen Ihrer Leistungsversprechen und
   Erstellung von E-Learning-Materialien
</li>
<li>
  <strong>Bei technischen R&uuml;ckfragen:</strong> Bitte benutzen Sie den unten stehenden
  Kontakt/Helpdesk Button
</li>
</ul>
  <br />
  <a href="contact">
<button type="submit" class="btn btn-primary">
  Frag den Experten
</button>
</a>
</div>
</div>
</div>
<!--
ALERTS
-->
<div id="explore-alerts" class="panel panel-default panel-dark-hightlight">
<div class="panel-heading panel-heading-light-highlight collapsed"
data-toggle="collapse" data-parent="#accordion"
data-target="#alerts">
  <h3 class="panel-title accordion-toggle">
      <span class="glyphicon glyphicon-exclamation-sign">&nbsp;</span>Benachrichtigungen
  </h3>
</div>
<div id="alerts" class="panel-collapse collapse">
<div class="panel-body">
Melden Sie sich an, um Benachrichtigungen zu erhalten, wenn neue Service-Angebote
und Service-Anfragen zum Portal hinzugef&uuml;gt werden. Nutzen Sie dazu das nachstehende Formular.
  <h4>Abonnieren</h4>
  <div id="subscribe-form"></div>
</div>
</div>
</div>
<!--
EVENTS
-->
<div id="explore-events" class="panel panel-default panel-light-hightlight">
<div class="panel-heading panel-heading-dark-highlight collapsed"
data-toggle="collapse" data-parent="#accordion"
data-target="#events">
  <h3 class="panel-title accordion-toggle">
     <span class="glyphicon glyphicon-calendar">&nbsp;</span>Veranstaltungen
 </h3>
</div>
<div id="events" class="panel-collapse collapse">
<div class="panel-body">
  <p>
Die folgenden Veranstaltungen sollten von Interesse f&uuml;r diejenigen sind, die nach
Partnern oder Hilfs-Organisationen f&uuml;r die Entwicklung, Vermarktung
oder Umsetzung von Produkten suchen.
</p>
  <br />
  <div id="upcoming-events"></div>
  <a href="node/add/event">
<button type="button" class="btn btn-primary">Erstelle ein neue Veranstaltung</button>
</a>
<a href="matchmaking/events">
<button type="button" class="btn btn-default">
  Zeige alle Verstanltungen
</button>
</a>
</div>
</div>
</div>',),
	);
}