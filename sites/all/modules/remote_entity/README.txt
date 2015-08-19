Remote Entity API
===================

This module provides an API for working with data on a remote server by treating records as entities. Multiple remote entity types can be declared on multiple remote servers.

With a remote entity type defined, you can:

* Execute queries on the remote data,
* Load remote entities by a remote ID,
* Load local copies of remote entities,
* Save remote entities (not yet implemented!)

Both querying and loading remote entities causes a local copy to be saved, which speeds up later loading. After a set time, local copies expire, and loading an expired entity will cause the remote version to be retrieved again (and also re-saved locally).

The Entity Metadata Property API is used to access properties of the remote entity.

There is no UI yet for editing the remote properties of entities locally.

Requirements
-----------

* EntityAPI
* Clients
* An implementation of a remote entity resource.

Implementations
--------------

So far only the MS Dynamics remote entity resource exists.

Usage
-----

To define a remote entity type:

1. Create a Clients connection to the remote server
2. Create a Clients resource for the remote entity type
3. In a custom module, implement hook_entity_info() for your remote entity type. See remote_entity.api.php for the properties that need to be specified.
4. Define the base table for your entity in your custom module's hook_schema(). You should use the schema given in remote_entity_schema_table() as a starting point.

Querying:

// Get the query via the controller. This sets the base entity for you.
$controller = entity_get_controller($entity_type);
$query = $controller->getRemoteEntityQuery();
// Set conditions.
$query->propertyCondition($property_name, 'value');
// It is essential to execute the query via the controller, so the remote
// data can be processed into entities and saved.
$entities = $controller->executeRemoteEntityQuery($query);
// $entities is an array of normal Drupal entities. All remote data is in
// $entity->entity_data, and can be accessed with the Entity Metadata API.

Loading:

// Once entities have been retrieved, they are saved with local ids.
// This will refresh the entity from remote if it has expired.
$entity = entity_load($entity_type, 1);

// Whether an entity has been previously retrieved or not, it can be loaded
// by remote id. This will try to load the local version if available and
// not expired, and fall back to a remote query.
$entity = remote_entity_load_by_remote_id($entity_type, $remote_id);
// Note that remote IDs need not be numeric; for example they can be GUIDs.

Extras: Admin UI
----------------

An admin UI can be provided for a remote entity type using an extension of the Entity API admin UI. To make use of this:

- define the 'access callback' in hook_entity_info(), and implement it.
- define the 'admin ui' array in hook_entity_info() (see Entity API
  documentation for more on this)

See the documentation for remote_entity_hook_entity_info() for further details and Remote Entity API additions.

Extras: Entity Operations
-------------------------

The following operations handlers are provided for use with the Entity Operations module:

- remote devel: fetches the remote entity and outputs it using Devel module.
- remote save: provides a form to remotely save the entity.

Extras: Views
-------------

By default, only the locally-cached copies of remote entities are exposed to
Views.  It is possible, however, for Views to do the remote querying.  To set
that up, do the following:

  1. Install the EntityFieldQuery Views Backend (efq_views) module.
  2. Implement the buildFromEFQ() method in your select query class.  See the
     method documentation in RemoteEntitySelectQuery::buildFromEFQ().

Note: A current limitation is that remote properties must be identical to local
  ones.  This is because EntityFieldQuery will only allow property conditions
  to be set on properties it knows about.
