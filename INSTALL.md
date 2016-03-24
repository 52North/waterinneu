# Installation Instructions

Replace ```http://localhost/``` with the hostname, port and scheme and ```/var/www/``` with the folder that match your environment.

1. Fullfill Drupal requirements first: https://www.drupal.org/requirements
    * PHP environment
    * Running database server with own database for drupal (credentials are required during installation of drupal).

1. Checkout this repo in the dedicated webserver directory with php support:

    ```user@host:/var/www$ git clone <git-url-of-this-repo> waterinneu```

1. Set-Up database: Install the MySQL script

    ```/var/www/waterinneu/config-backup/WaterInnEUMarketplacePrototype_installation.mysql.zip``` (Extract before).

    into the database, e.g. by using phpMyAdmin.

1. Configure the database for drupal:
    1. Create the file ```/var/www/waterinneu/sites/default/settings.php``` with the following content:

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
    ```
    1. Ensure that the file is protected, e.g.

      ```user@host:/var/www$ chmod 440 /var/www/waterinneu/sites/default/settings.php```

       More detailed instructions regarding secure file permission set-up for Drupal can be found at

       https://www.drupal.org/node/244924.

1. Access the site ```http://localhost/en/user``` and login with the example credentials:

  **Username**: ```waterinneu```

  **Password**: ```waterinneu```

1. Update the administrator account to match your set-up. Change the password and e-mail address at the following page:

  ```http://localhost/en/user/1/edit```

1. Configure SMTP module for sending and receiving system mails. Change the STMP configuration at the following page:

    ```http://localhost/en/admin/config/system/smtp```

1. Set-Up drupal cron: For testing the so called poor man's cron is enough. Go to

     ```http://localhost/en/admin/config/system/cron```

  and select ```1 hour```. This will result in the execution of cron tasks every hour at the end of any request. For production set-up, follow these instructions:

  http://drupal.org/cron

1. Adjust the imprint: Go to the following page and adjust the imprint to your needs:

  ```http://localhost/en/node/8782/edit```

1. Update the _widget ID_ and _username_ of the twitter block to your needs:

   ```http://localhost/en/admin/structure/block/manage/twitter_block/1/configure```

1. Adjust the e-mail that receives comment handling requests at the following page:

   ```http://localhost/en/admin/config/system/actions/configure/111```

1. Clear cache: Select ```Flush all caches``` from the black admin menu on top. Mouse over the house icon.

1. Test contact form: Open the following link and try to send a mail via the global contact form:

    ```http://localhost/en/contact```

  If the mails doesn't reach your inbox, you should review the configuration of the STMP module (see according section above).
