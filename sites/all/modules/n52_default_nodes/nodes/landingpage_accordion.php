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
function _n52_default_nodes_landingpage_accordion() {
	return array (
		'title' =>  array (
				'en' => 'Landing page - Content accordion',
				'de' => 'Startseite - Inhalts-Akkordeon',
		),
		'alias' => NULL,
		'text' => array (
				'de' => '<!--

YOU MUST NOT EDIT THIS CONTENT USING THE WEB UI! USE THE CODE!

-->

<div id="accordion" class="panel-group">
<!--
ABOUT
-->
<div class="panel panel-default panel-about panel-light-highlight">
<div class="panel-heading panel-heading-light-highlight collapsed" data-toggle="collapse" data-parent="#accordion" data-target="#about">
<h2 class="panel-title accordion-toggle">
  <span class="glyphicon glyphicon-info-sign">&nbsp;</span>&Uuml;ber
</h2>
</div>
<div id="about" class="panel-collapse collapse">
<div class="panel-body">
  <p>
    Der WaterInnEU Marktplatz ist eine marktgeleitete Innovations-Plattform,
    die die wichtigsten Produkte und
     Dienstleistungen f&uuml;r Flusseinzugsgebiets-Verwalter zeigt und deren
Aufnahme durch gezielte Verbreitung und Unterst&uuml;tzungsdienste beschleunigt.
  </p>
  <p>
    Die Plattform strebt danach, alle Akteure der
     Flussgebiets-Community zusammenzubringen, einschlie&szlig;lich Forscher, KMUs, Industrie
     und &ouml;ffentliche Einrichtungen. Dadurch soll die Nutzung und Marktreife
    von EU-gef&ouml;rderten Werkzeugen sowie die Umsetzung der Wasserrahmenrichtlinie
    verbessert werden.
  </p>
  <h3>Was leistet diese Plattform</h3>
  <ul>
    <li>
      Produkte: Die Plattform liefert detaillierte Informationen &uuml;ber
       eine ausgew&auml;hlte Anzahl von Produkten, inklusive
       erg&auml;nzender Materialien und Fallstudien sowie relevanten
       Kontakten f&uuml;r die weitere Kommunikation.
    </li>
    <li>
      Organisationen: eine Liste von Organisationen mit Bezug zu
       Flussgebiets-Verwaltung.
    </li>
    <li>
      Kontaktvermittlung und unterst&uuml;tzende Dienstleistungen:
      eine Reihe von Dienstleistungen ist verf&uuml;gbar, um die Kommunikation
       zwischen Produktanbietern in der Flussgebiets-Verwaltung und potenziellen Nutzern
       dieser Produkte sowie Dienstleistern, die bei der Umsetzung helfen, zu verbessern.
    </li>
    <li>
      E-Learning: die integrierte partizipative E-Learning-Funktion ist f&uuml;r bestimmte
      Werkzeuge erh&auml;ltlich und bietet einen schnellen Einstieg in die Produktf&auml;higkeiten.
    </li>
    <li>
      Erfolgsgeschichten : Beispiele f&uuml;r den Einsatz von Produkten und gewonnene Erkenntnisse.
    </li>
    <li>
      Forum: diskutieren Sie &uuml;ber spezifische Fragen rund um das Thema
      Flussgebiets-Verwaltung.
    </li>
  </ul>
  <p>
    Navigieren Sie zu <a data-toggle="collapse" data-parent="#accordion"
    data-target="#explore" style="cursor: pointer;">Erkunden</a>,
    um weitere Funktionen kennen zulernen.
  </p>
  <h3>Hinter den Kulissen - Wer organisiert WaterInnEU</h3>
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
</div>
</div>
</div>
<!--
EXPLORE
-->
<div class="panel panel-default panel-explore panel-dark-highlight">
<div class="panel-heading panel-heading-dark-highlight collapsed" data-toggle="collapse" data-parent="#accordion" data-target="#explore">
<h2 class="panel-title accordion-toggle">
  <span class="glyphicon glyphicon-search">&nbsp;</span>Erkunden
</h2>
</div>
<div id="explore" class="panel-collapse collapse">
<div class="panel-body">
  <div id="explore-search">
    <a href="matchmaking#search"><span class="glyphicon glyphicon-search">&nbsp;</span>Suche</a>:
    <div>Verwenden Sie die erweiterten Suchfunktionen, um ein Produkt oder eine Organisation zu finden.</div>
  </div>
  <div id="explore-service-requests">
    <a href="matchmaking#service-requests"><span class="glyphicon glyphicon-tasks">&nbsp;</span>Erstellen einer Service-Anfrage</a>:
    <div>Finden Sie eine Organisation oder Partner, der Ihnen bei der Verwendung bzw. Implementierung eines bestimmten Produkts helfen kann.</div>
  </div>
  <div id="explore-ask-experts">
    <a href="matchmaking#ask-the-expert"><span class="glyphicon glyphicon-question-sign">&nbsp;</span>Frag den Experten</a>:
    <div>Kontaktieren Sie uns direkt, wenn Sie Probleme haben oder Hilfe ben&ouml;tigen, Ihr Produkt auf den Markt zu bringen.</div>
  </div>
  <div id="explore-e-learning">
    <a href="e-learning"><span class="glyphicon glyphicon-plus-sign">&nbsp;</span>St&ouml;bern Sie in den E-learning-Angeboten</a>:
    <div>Holen Sie sich Hilfe bei der Verwendung von spezifischen Produkten.</div>
  </div>
  <div id="explore-alerts">
    <a href="matchmaking#alerts"><span class="glyphicon glyphicon-exclamation-sign">&nbsp;</span>Abonnieren Sie Benachrichtigungen</a>:
    <div>Sie erhalten Informationen &uuml;ber neue oder aktualisierte Produkte, Organisation, Service-Anfragen, Service-Angebote oder Veranstaltungen.</div>
  </div>
  <div id="explore-forum">
    <a href="forum"><span class="glyphicon glyphicon-comment">&nbsp;</span>Verwenden Sie das offene Forum</a>:
    <div>Starten Sie eine Diskussion zu einem bestimmten Thema oder treten Sie existierenden bei.</div>
  </div>
  <div id="explore-add-content">
    <a href="node/add"><span class="glyphicon glyphicon-plus">&nbsp;</span>Eintr&auml;ge hinzuf&uuml;gen</a>:
    <div>Laden Sie Ihr eigenes Produkt oder eine Veranstaltung hoch (wird zun&auml;chst durch unser Inhouse-Team gepr&uuml;ft).</div>
  </div>
</div>
</div>
</div>
<!--
OUR SERVICES
-->
<div class="panel panel-default panel-light-highlight">
<div class="panel-heading panel-heading-light-highlight collapsed" data-toggle="collapse" data-parent="#accordion" data-target="#our-services">
<h2 class="panel-title accordion-toggle">
  <span class="glyphicon glyphicon-shopping-cart">&nbsp;</span>Kontaktvermittlung und Unterst&uuml;tzung
</h2>
</div>
<div id="our-services" class="panel-collapse collapse">
<div class="panel-body">
  <p>
  Das prim&auml;re Ziel des WaterInnEU-Portal ist es, alle Akteure der
     Flussgebiets-Community zusammenzubringen, einschlie&szlig;lich Forscher, NROs, Industrie
     und &ouml;ffentliche Einrichtungen. Dadurch soll die Nutzung und Marktreife
von EU-gef&ouml;rderten Werkzeugen sowie die Umsetzung der Wasserrahmenrichtlinie
verbessert werden.
  </p>
  <p>
Die Plattform soll daher zur Verbesserung der Kommunikation zwischen
     diesen Akteuren dienen, um sicherzustellen, dass die
     Produkte und Dienstleistungen schnellstm&ouml;glich und mit hoher
     Effektivit&auml;t umgesetzt werden k&ouml;nnen.
  </p>
  <p>
    Navigieren Sie zu <a href="matchmaking">Kontaktvermittlung</a>, um automatisch eine Service-Anfrage
    oder ein Service-Angebot zu erstellen, oder kontaktieren Sie einen unserer Experten f&uuml;r individuellen Rat.
  </p>
</div>
</div>
</div>
<!--
UPCOMING EVENTS
-->
<div class="panel panel-default panel-upcoming-events panel-dark-highlight collapsed">
<div class="panel-heading panel-heading-dark-highlight collapsed" data-toggle="collapse" data-parent="#accordion" data-target="#events">
<h2 class="panel-title accordion-toggle">
  <span class="glyphicon glyphicon-calendar">&nbsp;</span>Kommende Veranstaltungen
</h2>
</div>
<div id="events" class="panel-collapse collapse">
<div class="panel-body">
  <p>
    Die Plattform zeigt regelm&auml;&szlig;ige Veranstaltungen, um die
    besten Produkte zu f&ouml;rdern, Fortbildungen anzubieten und um unterschiedliche
     Interessengruppen zusammenzubringen, damit bew&auml;hrte Praktiken und
     Erfahrungen ausgetauscht werden k&ouml;nnen.
  </p>
      <div id="upcoming-events"></div>
      <a href="node/add/event"><button type="button" class="btn btn-primary">Erstelle neue Veranstaltung</button></a>
  &nbsp;
  <a href="matchmaking/events"><button type="button" class="btn btn-default">Zeige alle Veranstaltungen</button></a>
</div>
</div>
</div>
</div>',
				'en' => '
<div id="accordion" class="panel-group">
	<!--
	ABOUT
	-->
	<div class="panel panel-default panel-about panel-light-highlight">
		<div class="panel-heading panel-heading-light-highlight collapsed" data-toggle="collapse" data-parent="#accordion" data-target="#about">
			<h2 class="panel-title accordion-toggle">
				<span class="glyphicon glyphicon-info-sign">&nbsp;</span>About
			</h2>
		</div>
		<div id="about" class="panel-collapse collapse">
			<div class="panel-body">
				<p>
					The WaterInnEU Marketplace is a market led innovation 
					platform that screens the most relevant products and 
					services for River Basin Managers and accelerates their 
					uptake through targeted dissemination and support services.
				</p>
				<p>
					The platform seeks to bring together all elements of the 
					river basin community including researchers, SMEs, industry 
					and public bodies in order to achieve better exploitation 
					and market translation of EU funded tools and improve 
					implementation of the Water Framework Directive.
				</p>
				<h3>How to use the platform</h3>
				<ul>
					<li>
						Products: the platform provides detailed information on 
						a select number of screened products, together with 
						supporting material and case studies, and relevant 
						contacts for further communication.
					</li>
					<li>
						Organisations: a list of organisations associated with 
						river basin management is available.
					</li>
					<li>
						Matchmaking and support services: a range of services 
						are available that seek to enhance communication 
						between organizations offering products which are 
						relevant to river basin management, the potential users 
						of these products, and service providers which can 
						support implementation.
					</li>
					<li>
						E-learning: the integrated participative e-learning 
						function is available for specific tools to enhance 
						rapid uptake and delivery.
					</li>
					<li>
						Success stories: examples of implementation of 
						products, and lessons learned.
					</li>
					<li>
						Forum: start or join a discussion around specific 
						issues of interest. We want to hear your questions and 
						views on all issues relating to river basin management.
					</li>
				</ul>
				<p>
					Go to <a data-toggle="collapse" data-parent="#accordion" 
					data-target="#explore" style="cursor: pointer;">Explore</a> 
					to see what other actions you can take.
				</p>
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
			</div>
		</div>
	</div>
    <!--
    EXPLORE
    -->
	<div class="panel panel-default panel-explore panel-dark-highlight">
		<div class="panel-heading panel-heading-dark-highlight collapsed" data-toggle="collapse" data-parent="#accordion" data-target="#explore">
			<h2 class="panel-title accordion-toggle">
				<span class="glyphicon glyphicon-search">&nbsp;</span>Explore
			</h2>
		</div>
		<div id="explore" class="panel-collapse collapse">
			<div class="panel-body">
				<div id="explore-search">
					<a href="matchmaking#search"><span class="glyphicon glyphicon-search">&nbsp;</span>Search</a>:
					<div>Use the advanced search tools to find the product or organisation you are looking for.</div>
				</div>
				<div id="explore-service-requests">
					<a href="matchmaking#service-requests"><span class="glyphicon glyphicon-tasks">&nbsp;</span>Put in a service request</a>:
					<div>Find an organisation or partner that can help you implement a product.</div>
				</div>
				<div id="explore-ask-experts">
					<a href="matchmaking#ask-the-expert"><span class="glyphicon glyphicon-question-sign">&nbsp;</span>Ask the expert</a>:
					<div>Contact us directly if you cannot find what you need or for help in bringing your product to market.</div>
				</div>
				<div id="explore-e-learning">
					<a href="e-learning"><span class="glyphicon glyphicon-plus-sign">&nbsp;</span>Take an E-learning module</a>:
					<div>Get help in implementing specific products.</div>
				</div>
				<div id="explore-alerts">
					<a href="matchmaking#alerts"><span class="glyphicon glyphicon-exclamation-sign">&nbsp;</span>Sign up for alerts</a>:
					<div>Receive information on new or updated products, organisations, services requests, service offers or events.</div>
				</div>
				<div id="explore-forum">
					<a href="forum"><span class="glyphicon glyphicon-comment">&nbsp;</span>Use the open forum</a>:
					<div>Start or join a discussion on a topic of interest.</div>
				</div>
				<div id="explore-add-content">
					<a href="node/add"><span class="glyphicon glyphicon-plus">&nbsp;</span>Add Entries</a>:
					<div>Upload your own product or event (screened by our in-house team before going live).</div>
				</div>
			</div>
		</div>
	</div>
	<!--
	OUR SERVICES
	-->
	<div class="panel panel-default panel-light-highlight">
		<div class="panel-heading panel-heading-light-highlight collapsed" data-toggle="collapse" data-parent="#accordion" data-target="#our-services">
			<h2 class="panel-title accordion-toggle">
				<span class="glyphicon glyphicon-shopping-cart">&nbsp;</span>Matchmaking and Support
			</h2>
		</div>
		<div id="our-services" class="panel-collapse collapse">
			<div class="panel-body">
				<p>
					The primary goal of the WaterInnEU Portal is to facilitate 
					matchmaking between organizations offering products which 
					are relevant to river basin management, the potential users 
					of these products, and service providers (consultants, 
					researchers, NGOs etc.) which can support implementation 
					(for example via adaptation of software for use in a 
					specific river basin).
				</p>
				<p>
					The platform therefore aims to enhance communication between
					these stakeholders in order to ensure that the appropriate 
					products and services are implemented as quickly and 
					effectively as possible.
				</p>
				<p>
					Go to the <a href="matchmaking">Matchmaking</a> tab to put in an automatic service 
					request or offer, or to contact one of our experts for 
					bespoke advice and support services.
				</p>
			</div>
		</div>
	</div>
	<!--
	UPCOMING EVENTS
	-->
	<div class="panel panel-default panel-upcoming-events panel-dark-highlight collapsed">
		<div class="panel-heading panel-heading-dark-highlight collapsed" data-toggle="collapse" data-parent="#accordion" data-target="#events">
			<h2 class="panel-title accordion-toggle">
				<span class="glyphicon glyphicon-calendar">&nbsp;</span>Upcoming Events
			</h2>
		</div>
		<div id="events" class="panel-collapse collapse">
			<div class="panel-body">
				<p>
					The platform hosts regular events designed to promote the 
					best products, offer enhanced training and bring different 
					stakeholders together to share best practice and 
					experiences.
				</p>
        		<div id="upcoming-events"></div>
        		<a href="node/add/event"><button type="button" class="btn btn-primary">Add new Event</button></a>
				&nbsp;
				<a href="matchmaking/events"><button type="button" class="btn btn-default">Show all Events</button></a>
			</div>
		</div>
	</div>
</div>',)
			,
	);
}