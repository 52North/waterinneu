# 52°North - Drupal "WaterInnEU" Distribution

## Introduction

This repo contains the development of [52°North](http://52north.org/) for the [WaterInnEU](http://waterinneu.org/) project. It is a [fork of drupal](https://github.com/drupal/drupal).  See [README.txt](README.txt) for more details on [drupal](https://www.drupal.org/).


## License

The license is GPL v2.0. See [LICENSE.txt](LICENSE.txt) for more details on the license.


## Description

**Marketplace providing access to EU innovation for river basin management.**

*The WaterInnEU Marketplace is a market led innovation platform that screens the most relevant products and services for River Basin Managers and accelerates their uptake through targeted dissemination and support services.*


## Features

The features of the marketplace are described in a deliverable of the project: [D6.1 First virtual Marketplace report (PDF, 70p, 5.9MB)](http://ddd.uab.cat/record/148387) and in the [user guide (PDF, 97p, 9.1MB)](https://marketplace.waterinneu.org/sites/default/files/documents/WaterInnEU_Marketplace_User-Guide.pdf) available from the [prototype demonstrator instance](https://marketplace.waterinneu.org/).

The marketplace provides the following core functionalities:
  * browsing by linked categories through products, organisations, service requests, and service offerings
  * common panel for upcoming events
  * collaborative creation and editing of products, organisations, service requests/offerings and events
  * a common place for adding and browsing service requests and service offerings
  * option to subscribe for new products, service offerings, or service requests
  * simple keyword search and advanced search facilities
  * option to provide user feedback in the form of comments
  * forum for open discussions about products or other related information
  * learning tutorials on usage of certain products
  * use the matchmaking functionality
  * contact an expert with special requests
  * read about success stories of product application


## Contact

   * Christoph Stasch [(staschc)](https://github.com/staschc)
   * Eike Hinderk Jürrens [(EHJ-52n)](https://github.com/EHJ-52n/)


## Installation Instructions

These instructions contains 19 steps until your own WaterInnEU marketplace instance. Please follow the steps carefully and report any issues you have. Replace ```http://localhost/``` with the hostname, port and scheme and ```/var/www/``` with the folder that match your environment.

1. Fullfill requirements first:

    * [Drupal requirements](https://www.drupal.org/requirements),
    * HTTP server with **PHP** environment,
    * Running **database server** with own **database for drupal** (credentials are required during installation of drupal) and
    * **[Apache solr](http://lucene.apache.org/solr/) server** instance (to be configured [following the handbook](https://www.drupal.org/node/1999386) after the installation).

1. Checkout this repository in the dedicated webserver directory with php support:

    ```
    user@host:/var/www$ git clone <git-url-of-this-repo> waterinneu
    ```

1. Update to the latest drupal version of the 7.x branch:

    ```
user@host:/var/www$ git fetch --all
[...]
user@host:/var/www$ git tag -l "7.*" | sort -n | tail
7.40
7.41
7.42
7.43
7.44
7.50
7.51
7.52
7.53
7.54
user@host:/var/www$ git merge --no-ff -m "Update to drupal 7.54" 7.54
```

1. Set-Up database: Install the MySQL script  ```/var/www/waterinneu/config-backup/WaterInnEUMarketplacePrototype_installation.mysql.zip``` (Extract beforehand) into the database, e.g. by using phpMyAdmin. Adjust the database name in the file using your favorite text editor:

   ```sql
   CREATE DATABASE IF NOT EXISTS `YOUR_DB_NAME` DEFAULT CHARACTER SET utf8 COLLATE utf8_bin;
   USE `YOUR_DB_NAME`;
   ```

   *Replace ```YOUR_DB_NAME``` with the name you want to have.*

1. Configure the database for drupal: Create the file ```/var/www/waterinneu/sites/default/settings.php``` with the following content:

    ```php
<?php

    $databases['default']['default'] = array (
      'database' => 'YOUR_DATABASE_NAME_HERE',
      'username' => 'YOUR_DATABASE_USER_HERE',
      'password' => 'YOUR_DATABASE_USER_PASSWORD_HERE',
      'host' => 'localhost',
      'driver' => 'mysql',
      'prefix' => '',
    );

    $update_free_access = FALSE;

    /*
     * Use something like
     *     http://www.lorem-ipsum.co.uk/hasher.php
     * for creation of the hash value. Enter any ramdom value in the form.
     */
    $drupal_hash_salt = 'ENTER_RANDOM_TOKEN_HERE';

    ini_set('session.gc_probability', 1);
    ini_set('session.gc_divisor', 100);
    ini_set('session.gc_maxlifetime', 200000);
    ini_set('session.cookie_lifetime', 2000000);

    $conf['404_fast_paths_exclude'] = '/\/(?:styles)\//';
    $conf['404_fast_paths'] = '/\.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';
    $conf['404_fast_html'] = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN" "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd"><html xmlns="http://www.w3.org/1999/xhtml"><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL "@path" was not found on this server.</p></body></html>';
    $base_url = "http://localhost/your-contenxt-path";
    ```

1. Ensure that the file is protected, e.g.

  ```
  user@host:/var/www$ chmod 440 /var/www/waterinneu/sites/default/settings.php
  ```

  More detailed instructions regarding secure file permission set-up for drupal can be found at https://www.drupal.org/node/244924.

1. Access the site

  ```
  http://localhost/en/user
  ```

  and login with the example credentials:

  **Username**: ```admin```

  **Password**: ```admin```

1. Update the administrator account to match your set-up. Change the password and e-mail address at the following page:

    ```
    http://localhost/en/user/1/edit
    ```

1. Configure SMTP module for sending and receiving system mails. Change the SMTP configuration at the following page:

    ```
    http://localhost/en/admin/config/system/smtp
    ```

1. Set-Up drupal cron: For testing the so called poor man's cron is enough. Go to

     ```
     http://localhost/en/admin/config/system/cron
     ```

  and select ```1 hour```. This will result in the execution of cron tasks every hour at the end of any request. For production set-up, follow these instructions:
  http://drupal.org/cron

1. Adjust the imprint: Go to the following page and adjust the imprint to your needs:

  ```
  http://localhost/en/imprint
  ```

1. Update the _widget ID_ and _username_ of the twitter block to your needs:

   ```
   http://localhost/en/admin/structure/block/manage/twitter_block/1/configure
   ```

1. Adjust the e-mail that receives comment handling requests at the following page:

   ```
   http://localhost/en/admin/config/system/actions/configure/111
   ```

1. Clear cache: Select ```Flush all caches``` from the black admin menu on top. Mouse over the house icon.

1. Update mail address in

   1. ...subscription from under **Mail settings**:

     ```
     http://localhost/en/admin/config/system/subscriptions
     ```

   1. ...in the **maintenance mode** message:

     ```
     http://localhost/en/admin/config/development/maintenance
     ```

   1. ...in the **site information** form:

     ```
     http://localhost/en/admin/config/system/site-information
     ```

   1. ...for all **contact form categories**:

     ```
     http://localhost/en/admin/structure/contact
     ```

1. Test the contact form: Open the following link and try to send a mail via the global contact form:

    ```
    http://localhost/en/contact
    ```

  If the mails doesn't reach your inbox, you should review the configuration of the SMTP module (see according section above).

1. Update all dependencies: Open the following URL

    ```
    http://localhost/drupal/en/admin/reports/updates/update
    ```

  If the latest check is not 0 seconds ago, click on the link "check manually".

1. Configure solr server in search API:

    ```
    http://localhost/drupal/en/admin/config/search/search_api/server/search_server_solr_localhost
    ```
1. The installation is finished. You can start adjusting the system to your requirements. Feel free to provide your findings and new features as a [pull request](https://github.com/52North/waterinneu/compare).

If you have any comments regarding this instructions, feel free to [create a new issue](https://github.com/52North/waterinneu/issues/new) in the according [github repository](https://github.com/52North/waterinneu).
