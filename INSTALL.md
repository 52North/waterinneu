# Installation Instructions

Replace ```http://localhost/``` with the hostname, port and scheme that match your environment.

1. **Base Installation**
    1. Fullfill Drupal requirements first: https://www.drupal.org/requirements
        * PHP environment
        * Running database server with own database for drupal (credentials are required during installation of drupal).
    1. Checkout this repo in the dedicated webserver directory with php support:

        ```user@host:/var/www$ git clone <git-url-of-this-repo> waterinneu```

    1. Open ```http://localhost/install.php?profile=n52_waterinneu&locale=en``` in any browser of your choice and follow the instructions for installing a Drupal default installation.
    1. Database configuration: Enter the database credentials and select the correct database management system.
    1. Site Configuration: Provide the required information.
    1. Click on **visit your new site**.
1. **WaterInnEU specific configuration**
    1. Increase the php script run time as the action that are performed within the next step might take a while. The according parameter is ```max_execution_time``` and should be set to ```300``` (5 minutes) in your server's or php environment's ```php.ini``` file, e.g. apache2 under debian stores this configuration under ```/etc/php5/apache2/php.ini```. Don't forget to restart your server to honour this configuration change and note the previous value somewhere because we need this high value only for the initial set-up!
    1. The next step if faster when using ```drush```.
        * Go to ```http://localhost/en/admin/structure/features``` and enabled/revert all the **52N - WaterInnEU** features. For every module that is not in the state ```Default``` perform the following steps:
          1. Click on the name of the feature that brings you to the view tab of it.
          1. Select all possible items in the right column that provide a checkbox.
          1. Click on **Revert** button on the bottom of the page.
          1. Go back to ```http://localhost/en/admin/structure/features``` and check if the state changed to ```Default```.
          <br />It might help to perform cash cleaning between the reverting of different features.
        * *or* ```drush```: <br />
          ```
          drush -y fr feature_service_requests_and_offerings waterinneu_feature_tools waterinneu_feature_organisation waterinneu_feature_projects feature_configuration feature_events feature_helpdesk feature_search  waterinneu_feature_menus waterinneu_feature_frontpage waterinneu_feature_roles_and_permissions
          ```
1. **Final steps**
    1. Delete all cache files. Go to ```http://localhost/en/admin``` and select **Admin** &rarr; **Flush all caches** from the admin menu.
    1. Run cron manually via ```http://localhost/en/admin/config/system/cron``` and click on **Run Cron**.
