SUMMARY:
Allows admins to export users to a flatfile, e.g. .csv, .txt, .xls. Also adds a
handy screen to help locate users by email or username.


INSTALLATION:
* Download and unzip this module into your modules directory.
* Goto Administer > Site Building > Modules and enable this module.


CONFIGURATION:
* The functions of this module are given to users with the permission
  "administer users".


EXPORTING:
* Visit admin/people/export, adjust your settings and click Download File


SEARCHING:
* Visit admin/people/find, enter search criteria and submit the form.


API:
* Other modules may alter the export row using hook_users_export_row_alter()
* This would be useful to add any fields that are not a part of the core user
  table, such as user (profile) fields.


--------------------------------------------------------
CONTACT:
In the Loft Studios
Aaron Klump - Web Developer
PO Box 29294 Bellingham, WA 98228-1294
aim: theloft101
skype: intheloftstudios

http://www.InTheLoftStudios.com
