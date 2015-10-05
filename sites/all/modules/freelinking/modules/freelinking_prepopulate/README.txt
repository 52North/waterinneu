CONTENTS OF THIS FILE

* Introduction
* Requirements
* Recommended modules
* Installation
* API and utilities
* Createnode
* Maintainers


INTRODUCTION

This module create a prepopulated link to a create node. It is used
primarily as a failover for the *Nodetitle* plugin.  When this module
is enabled, the failure option “”Add a link to create content” is
added to the failover pull down menu for *Nodetitle*.

The following items will be inherited from the the parent node and
used to prepopulate the new node:

* Title (inherited from the *target* of the freelink markup).
* Book outline (requires the **Book** module to be enabled).
* Taxonomy term  (requires the **Taxonomy** module to be enabled). [N.I.]
* OG context  (requires the **OG Context** module to be enabled). [N.I.]

**Note:** *Taxonomy term* and *OG context* does not work and is currently disabled.

For example, the following freelink: `[[nodetitle:Does not exist]]`,  produces:

    <a class="freelink freelink-createnode notfound freelink-internal" title="node/add/article" href="/node/add/article?edit%5Btitle%5D=Does%20not%20exist&parent=836">Does not exist</a>

Here, the `parent=836` identifies the book the new node shall be part of.


REQUIREMENTS

Requires [Prepopulate][1].


RECOMMENDED MODULES

* Book:<br>
  When the core Book module is enabled, create node links will be
  prepopulated as being part of the same book as the parent node.

* [Markdown filter][2]:<br>
  When this module is enabled, display of the project's `README.md` will be
  rendered with markdown when you visit `/admin/help/freelinking_prepopulate`.


INSTALLATION

1. Install as you would normally install a contributed drupal
   module. See: [Installing modules][3] for further information.
2. To configure the module, navigate to Configuration > Content
   authoring > Freelinking settings.  There should be a panel headed
   *Freelinking_prepopulate Plugin Settings*, abd a new option ("Add a
   link to create content") added to the failover menu for
   *Nodetitle*.


API AND UTILITIES

For API functions and examples of their use, see
`freelinking_prepopulate.api.php`.

The Freelinking Prepopulate Utilities
(`freelinking_prepopulate.utilities.inc`) are intended to help with
the centralized definition of form fields that may be of interest for
Prepopulate-based plugins, and automating the process of extracting
information for such fields.


MAINTAINERS

* grayside - https://www.drupal.org/u/grayside
* juampy - https://www.drupal.org/u/juampy
* gisle - https://www.drupal.org/u/gisle (current maintainer)

Any help with development (patches, reviews, comments) are welcome.

[1]: https://www.drupal.org/project/prepopulate
[2]: https://www.drupal.org/project/markdown
[3]: https://drupal.org/documentation/install/modules-themes/modules-7
