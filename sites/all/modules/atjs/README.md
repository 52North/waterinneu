# Introduction

This module allows the [standalone At.js library](https://github.com/ichord/At.js) to integrate with Drupal. This allows for customisable auto-completion for any kind of entity.

* For a more in-depth description of the module, visit the project page: [](https://drupal.org/project/atjs)

* To submit bug reports and feature suggestions: (https://drupal.org/project/issues/atjs)

This document will refer to the At.js Drupal module as 'At.js module' and the standalone JavaScript library as 'At.js library'.

# Requirements

## Modules

* CTools
* Libraries
* jQuery Update
* Entity

jQuery update is required so that jQuery 1.7 is available to the Caret.js & At.js libraries - they won't work without it! This will require you configuring jQuery Update at: /admin/config/development/jquery_update

## Libraries

* [Caret.js (0.3.1)](https://github.com/ichord/Caret.js/releases/tag/v0.3.1)
* [At.js (1.5.0)](https://github.com/ichord/At.js/releases/tag/v1.5.0)

Download both of the above libraries and copy them to your libraries path (typically `sites/all/libraries`).

Your structure should look like:
sites/all/libraries/caret.js/
sites/all/libraries/at.js/

Both libraries should have a "dist" directory within which contains the JavaScript files, for example:
sites/all/libraries/caret.js/dist/jquery.caret.js

Be sure to check the Status Report page (/admin/reports/status) which will verify that the correct versions of these libraries have been loaded.

# Installation

Follow the [standard Drupal module installation steps](https://www.drupal.org/docs/7/extending-drupal-7/installing-contributed-modules-find-import-enable-configure-drupal-7) to successfully install the At.js module. Make sure that both Caret.js & At.js are installed as per the above Libraries section.

# Configuration

The At.js module works through the use of At.js listeners.

For a basic use case of allowing mentions of users by name in a Basic page body field, follow these steps:

1. Go to /admin/structure/atjs/list
2. Click 'Add'
3. Set the 'Administrative title' of your listener
4. Scroll down to 'Target entity' and set to 'User'
5. In 'Search and template settings', set 'Entity property or field to search against' to 'name'
6. Under 'Data to supply to template', check 'Property: name'
7. Click 'Save'

You now have a listener you can attach to fields like so:

1. Go to /admin/structure/types
2. Under 'Basic page', click 'manage fields'
3. Click 'edit' on the 'Body' field
4. Check 'Enable At.js listeners for this field'
5. Under 'At.js Listeners that should be active on this field', select the listener named as in step 3 above
6. Click 'Save settings'

If you create a new Basic page and type in the body field '@' and the first letter of a user in your Drupal site, you should see a list of users starting with that letter.

# FAQ
Q: Clicking a matched entity from the dropdown adds the text 'undefined' to the field. What gives?

A: This is because of a change in the way the At.js library handles what it calls 'insert templates'. An insert templates is the markup that will be output when you choose and entity from the dropdown.

If you are getting 'undefined', it is possible that your At.js listener was created before we upgraded the required library versions. To fix this, you'll need to update your At.js listener to use the insert template `<span>${atwho-at}${name}</span>`.

# Maintainers

Current maintainers:
* [Alli Price](https://www.drupal.org/u/heylookalive)
* [David Hughes](https://www.drupal.org/u/david.hughes)
