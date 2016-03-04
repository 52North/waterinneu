INTRODUCTION
------------
The Taxonomy Autocomplete Permission module provides role-based permissions to
allow adding new taxonomy terms via the taxonomy autocomplete widget.

 * For a full description of the module, visit the project page:
   https://drupal.org/project/taxonomy_autocomplete_permission


INSTALLATION
------------
 * Install as you would normally install a contributed Drupal module. See:
   https://drupal.org/documentation/install/modules-themes/modules-7
   for further information.


CONFIGURATION
-------------
 * Configure user permissions in Administration » People » Permissions »
 Taxonomy Autocomplete Permission (admin/people/permissions).

Granting a role "Add terms in [taxonomy] via autocomplete" will allow users with that role to add terms via any widget instances for that taxonomy.

All roles that have permission to add content to the entity or content type that
contains the widget will still be able to use existing terms.


FAQ
---
Q: Can I export these permissions with Features?

A: Yes. Since the permissions are based on the taxonomy machine name (rather
than the vid), permissions can safely be featurized and will not break during
re-installation or migration.

Q: How do I limit users from adding terms via admin/structure/taxonomy?

A: The module "Taxonomy Access Fix" defines permissions for adding new taxonomy
terms via the Admin interface, but does not account for autocomplete adding.
Rather than duplicating that module's logic here, use the two modules in
conjunction.


MAINTAINERS
-----------
Current maintainers:
 * Mark Fullmer (mark_fullmer) - https://www.drupal.org/u/mark_fullmer
