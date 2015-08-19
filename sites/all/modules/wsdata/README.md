About
=====

Web Service Data is a collection of modules allowing you to interact with web services using entities and fields in Drupal.

Modules/Sub-Modules
==========

Web Service Data (wsdata)
-------------------------

- Defines abstract classes for Web Service Connectors (WsConnector) and Web Service Data Processors (WsData).

Web Service Configuration (wsconfig)
------------------------------------

- Defines an entity type called "wsconfig_type" which stores information about how the URL to the root of a web service and which connector type to use (ex: RESTClient for REST based services).

- Defines an entity called "wsconfig" which stores information about how to interact with a given service (ex: /service/user) and each of the CRUD operations.

Web Service Fields Storage (wsfields_storage)
---------------------------------------------

- Defines a field storage controller which uses the CRUD operations defined in a wsconfig to interact with remote data using Drupal Fields.

Caveat.
Since the field module caches loaded field data, you should use the provided cache backend for fields.
You can do this by adding the following to your settings.php file, updated to reflect the location of wsfields_storage:

$conf['cache_backends'][] = 'sites/all/modules/wsdata/modules/wsfields_storage/wsfields_storage.cache.inc';

Web Service Fields (wsfields)
-----------------------------

- Contains implementations of the core fields to parse data coming from an implementation of "WsData" into the proper format expected by each field type.

Web Service Beans (wsbeans)
---------------------------

- Adds a bean type called "wsbean" which is a bean that will render the results of a web service call.

Web Service Hybrid Fields (wshybridfield)
-----------------------------------------

Adds a new field type "WS Hybrid Field".  This field contains web service connection info, and the web service is result is rendered when the field is displayed.
This field should be used when it is ony desired that extra remote data should be displayed when a entity is viewed.

It cannot afford any of the integration available with wsfields and wsfields_storage, however the use and configuration is more straight forward.


Web Service Solr Integration (wsdata_solr)
------------------------------------------

Provides default processors for parsing JSON data returned by solr queries.


Web Service Entities (wsentities)
---------------------------------

**Not Yet Implemented**

Web Service Services (ws_services)
----------------------------------

- Sample implementation on connecting to web services of another Drupal site which is sharing data using the Services module.

- Includes a test suite for the wsdata module as a whole

Web Service Fields - Address Field (ws_addressfield)
----------------------------------------------------

- Adds data formatting for [Address Fields](http://drupal.org/project/addressfield)

Web Service Fields - Date Field (ws_datefield)
----------------------------------------------

- Adds data formatting for [Date Fields](http://drupal.org/project/date)

Web Service Fields - Entity Reference Field (ws_entityreferencefield)
---------------------------------------------------------------------

- Adds data formatting for [Entity Reference Fields](http://drupal.org/project/entityreference)

Installation
============

1. Download all dependencies
2. Enable the module

Usage
=====

Preface
-------

You need to determine two key factors:

1. What web service request method are you using (ex: SOAP, REST)
2. What data formats do your web services accept/reply (ex: XML, JSON, text)

Prerequisites
-------------

- Compatible 'Connector' module
    - You'll need a means of making the web service requests. A module which implements hook_wsconfig_connector_info() and an implementation of WsConnector which is compatible with your request method.
    
- Processor classes
    - For each web service, you'll need to implement and instance of WsData to parse the returned values into values compatible with Drupal. Typically, after writing a few you'll notice some patterns and be able to reuse significant portions of your code.
    
Implementation
--------------

For details on how to implement each individual API, please see their accompanying README.txt files. (ex: see wsdata/modules/wsfields_storage/README.txt on how to define fields to use the storage controller)

Example Implementations
=======================

See 'ws_services' module for an example implementation.

Connectors
----------

You can use the [RESTClient](https://drupal.org/project/restclient) module connector as a sample to build your connectors with.

Processors
----------

See wsdata/modules/ws_services/includes for a list of sample implementations of WsData.

History
=======

Below is an explanation of how and why wsdata came into existence and the types of solutions it can provide to developers working with Drupal and web services.

The Problem
-----------

Drupal gives developers and site builders a lot of power in its Entity and Field APIs. However, the default implementations assume that all your data exists within Drupal's tables; that Drupal is the primary data source.

When dealing with enterprises with a historical data set, it isn't always feasible or practical to migrate and/or copy this data into Drupal.

In these cases you have two options; build "dumb views" on the data. To display it to the user or expose it to parts of Drupal you write custom code to load the information from the service into custom tables or as temporarily cached data. But you lose all of the power and flexibility of having the data exist as entities/fields.

In the second case, you build a custom bit of code to import the data as entities (ex: nodes, comments, users) which gives you the use of the Entity and Field APIs but you're now disconnected from the data source. You need to maintain a data sync or run batch updates on data in Drupal and/or in the original data set. This also brings up the issue of "big data" in Drupal. The default table structure in Drupal normalizes the data. Which means running updates may be very expensive.

Not to mention, in the second case, most of this code is single purpose and not necessarily reusable.

Goal
----

Based on the problems above with the two current implementations we set out to make a solution that both allows the use of the Entity and Field APIs in Drupal and avoided the issue of syncing data and performing batch updates.

We also wanted to ensure that the solution would be compatible with existing contrib modules in Drupal. Meaning you could treat data from web services as you would data from Drupal's own tables.

Lastly, we wanted to ensure that the solution was reusable. Meaning it could be repurposed to work with nearly any web service with nearly any kind of data being returned.


Initial Concept Implementation
------------------------------

We came up with three components to generically describe each portion required for interacting with web service data.

- Connector: A tool or library which handled the request medium (ex: HTTP)
- Processor: An object which would convert the data from the web service into a standard format which could be interpreted by Drupal
- Configuration Type: An entity which told Drupal which connector to use with which web service, which processor to use to parse the data and what data we wanted to extract from that service

For the connector, we had an existing module we used to make REST based queries called RESTClient which we extended to support the "WsConnector" class. We created a hook called <code>hook_wsconfig_connector_info</code> which allowed modules to tell wsdata that they implement WsConnector.

Next, the configuration object. We created an entity type called "wsconfig" and a bundle entity type "wsconfig_type". This allowed us create a one-to-one relationship between connector types and configuration types. For example, you would create a wsconfig type called "My REST Services", set the root URL for the services and define the connector to use as "RESTClient". You could then create a second wsconfig type called "My SOAP Services" which pointed to the SOAP web service root URL and used a SOAP compatible connector.

Finally, we needed a way to map a local data container (ex: field instance) to a remote data point (ex: value from remote XML element). To accomplish this we created "wsfields". The goal being to map an individual field value to a value from a web service.

Using <code>hook_field_storage_pre_load</code> we told Drupal to ignore loading a value for the given field instance as we would load and format the data from the web service instead. This is where the processors come in. As an example, say you have a field on your user entities called "First Name". You would go to that field's settings form and set it to use a wsconfig instance to connect and load data. Next you set any query parameters or replacement patterns for the connector call (ex: /service/user/%uid would need %uid replace with the user's uid value). Then set which 'remote key' to use from the returned data as the value for the field itself.

Similarly, using <code>hook_field_storage_pre_insert</code> the same general process applies to writing data. The only difference being we send data to the service using the wsconfig information.

Best of all, you could have a mixed environment of field instances. Meaning an instance of the "body" field on a node article could use data from the database whereas the "body" on another node type could use wsdata instead.

Issues with the Concept
-----------------------

For very basic reads and writes the service code worked very well. It was configurable from the UI and was specific to Field Instances, rather than the field definition itself. However, problems quickly arose from using hook_field_storage_pre_load/insert.

The most glaring issue was dealing with EntityFieldQueries. In short, they could never work. Which meant modules such as efq_views and other complex modules such as Panels would not properly read and/or write data to said fields.

Search API also failed to index the data and actually caused exceptions to be thrown as it became confused by the data handling. The i18n module had similar issues dealing with the fields in their current implementation.

We had achieved two of the three goals we had original sought out, but missing the last part, the compatibility with contrib modules, was a deal breaker.

Second Attempt
--------------

After reviewing the issues with the first implementation, we came to the conclusion that most (if not all) of the issues revolved around EntityFieldQueries failing on wsdata fields. Meaning we needed to implement a proper Field Storage Controller with support for EntityFieldQueries (i.e implement hook_field_storage_query).

All the same principles applied. We used connectors, processors and configurations to interact with web service data. The specific field settings were moved into the "field settings" instead of "field instance settings". Using the "storage" array in the field settings, you define the storage settings, remote key and other information previously only found in the configuration entity. This allowed the configuration entities to act more generically. They could be mapped one-to-one per web service instead of per field.

Here's a snippet from a field definition using the Web Service Fields Storage controller:

<pre><code>
'storage' => array(
  'module' => 'wsfields_storage',
  'settings' => array(
    'processor' => 'myprocessor',
    'propertymap' => array(
      'read' => array(
        '%uid' => 'uid',
      ),
    ),
    'remotekey' => 'description',
    'translation' => FALSE,
    'wsconfig_name' => 'my_wsconfig',
  ),
  'type' => 'wsfields_storage',
</code></pre>

Issues with the Second Attempt
------------------------------

Our second implementation met all our primary goals. However we did lose some features we had from the initial implementation.

No longer were the settings defined on field instances. Instead they were defined in the "storage" sub array in the field settings. This meant two drawbacks:

- No longer configurable through the UI: Since Drupal cannot change a field's storage controller once it is defined, changes to a field defined by the UI are impossible
- All instances of a given field must use the storage controller. This more than likely means less sharing of fields between entities and entity types.

Future
======

The same concepts could be applied to entities themselves. Build a generic entity controller which uses web services to load all of it's data. This is more complex to accomplish than using fields. With fields, the entity to which they're attached can store information about how to load the appropriate data. If the entity itself is entirely remote, knowing how or where to load the data gets harder. Even knowing if the given entity exists at all is more difficult.

However we do have a basic implementation almost working. It can read from a service which supplies all the entity data already configured (using Services on another Drupal site).
