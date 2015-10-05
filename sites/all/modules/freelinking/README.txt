CONTENTS OF THIS FILE

* Introduction
* Recommended modules
* Installation
* Configuration
* Maintainers


INTRODUCTION

Freelinking implements a filter for the easier creation of HTML links
to other pages in the site or external sites with a wiki style format
such as `[[indicator:identifier]]`.

For example: `[[nodetitle:Page One]]` becomes:

    <a href="/node/1" title="Click to view a local node."
    class="freelink freelink-nodetitle freelink-internal">Page One</a>

Note that there must be no space after the colon after the indicator.

A number of ready-to-use filters are included in the **Freelinking**
framework (e.g. Nodetitle. Nid, User, Google search, Drupal search,
Drupal projects, Wikipedia, etc.).

There is a framework that allow developers to add new plugins. Read
the help file “Creating plugins for Freelinking ver. 3” using
Advanced help[1] for instructions regarding how to add new plugin.


RECOMMENDED MODULES

* Advanced help[1]:<br>
  When this module is enabled, you will have access to extended online
  help.

INSTALLATION

1. Install as you would normally install a contributed drupal
   module. See: Installing modules[2] for further information.
2. Go to *Administration » Configuration » Text Formats* and activate
   the *Freelinking* filter for the text formats you want to
   facilitate freelinking for (e.g. Filtered HTML and Full HTML).
3. If you plan to use freelinking for External links, deactivate the
   *Convert URLs into links* filter for the same text formats.
4. Configure the module at *Administration » Configuration » Content
   authoring » Freelinking settings*.  See next section for details.
5. Clean the cache.

CONFIGURATION

To configure the module, navigate to *Administration » Configuration »
Content authoring » Freelinking settings*.

The first setting is a pull-down menu to let you set the default
indicator to use when no indicator is specified.  “Nodetitle” mimics
previous versions of **Freelinking**.

The global options and options to increase performance are global, and
apply to all plugins. Please see the description of each checkbox to
determine what each does.

The rest of the configuration pages are for plugin-specific options.

If you change the configiration, remember to press *Save
configuration* to make the changes effective.


MAINTAINERS

* eafarris - https://www.drupal.org/user/812 (original creator)
* grayside - https://www.drupal.org/u/grayside
* juampy - https://www.drupal.org/u/juampy
* gisle - https://www.drupal.org/u/gisle (current maintainer)

Any help with development (patches, reviews, comments) are welcome.


[1]: https://www.drupal.org/project/advanced_help
[2]: https://www.drupal.org/documentation/install/modules-themes/modules-7
