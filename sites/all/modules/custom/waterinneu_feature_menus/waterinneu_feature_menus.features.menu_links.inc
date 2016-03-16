<?php
/**
 * @file
 * waterinneu_feature_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function waterinneu_feature_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_e-learning:node/8788.
  $menu_links['main-menu_e-learning:node/8788'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/8788',
    'router_path' => 'node/%',
    'link_title' => 'E-Learning',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'main-menu_e-learning:node/8788',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 6,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_forum:forum.
  $menu_links['main-menu_forum:forum'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'forum',
    'router_path' => 'forum',
    'link_title' => 'Forum',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'ignore_access_roles' => array(
        1 => 0,
        2 => 0,
        8 => 0,
        10 => 0,
        9 => 0,
        11 => 0,
        3 => 0,
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_forum:forum',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_home:<front>.
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_matchmaking:node/8784.
  $menu_links['main-menu_matchmaking:node/8784'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/8784',
    'router_path' => 'node/%',
    'link_title' => 'Matchmaking',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'main-menu_matchmaking:node/8784',
      'ignore_access_roles' => array(
        1 => 0,
        2 => 0,
        8 => 0,
        10 => 0,
        9 => 0,
        11 => 0,
        3 => 0,
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_organisations:organisation.
  $menu_links['main-menu_organisations:organisation'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'organisation',
    'router_path' => 'organisation',
    'link_title' => 'Organisations',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'main-menu_organisations:organisation',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_products:product.
  $menu_links['main-menu_products:product'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'product',
    'router_path' => 'product',
    'link_title' => 'Products',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_products:product',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_success-stories:node/8787.
  $menu_links['main-menu_success-stories:node/8787'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/8787',
    'router_path' => 'node/%',
    'link_title' => 'Success Stories',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'main-menu_success-stories:node/8787',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 7,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-author_add-content:node/add.
  $menu_links['menu-author_add-content:node/add'] = array(
    'menu_name' => 'menu-author',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add content',
    'options' => array(
      'attributes' => array(
        'title' => 'Add content to the site.',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-author_add-content:node/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-author_compose-tips:filter/tips.
  $menu_links['menu-author_compose-tips:filter/tips'] = array(
    'menu_name' => 'menu-author',
    'link_path' => 'filter/tips',
    'router_path' => 'filter/tips',
    'link_title' => 'Compose tips',
    'options' => array(
      'attributes' => array(
        'title' => 'Additional information about the activated filters and text formats.',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-author_compose-tips:filter/tips',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-author_event:node/add/event.
  $menu_links['menu-author_event:node/add/event'] = array(
    'menu_name' => 'menu-author',
    'link_path' => 'node/add/event',
    'router_path' => 'node/add/event',
    'link_title' => 'Event',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-author_event:node/add/event',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-author_add-content:node/add',
  );
  // Exported menu link: menu-author_my-content:user.
  $menu_links['menu-author_my-content:user'] = array(
    'menu_name' => 'menu-author',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'My Content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'menu_token_link_uuid' => 'menutoken/56e8491708988',
      'ignore_access_roles' => array(
        1 => 0,
        2 => 0,
        9 => 0,
        3 => 0,
      ),
      'fragment' => 'my-content',
      'identifier' => 'menu-author_my-content:user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-author_organisation:node/add/organisation.
  $menu_links['menu-author_organisation:node/add/organisation'] = array(
    'menu_name' => 'menu-author',
    'link_path' => 'node/add/organisation',
    'router_path' => 'node/add/organisation',
    'link_title' => 'Organisation',
    'options' => array(
      'attributes' => array(
        'title' => 'Add an \'organisation\' to the site',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-author_organisation:node/add/organisation',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-author_add-content:node/add',
  );
  // Exported menu link: menu-author_product:node/add/tool.
  $menu_links['menu-author_product:node/add/tool'] = array(
    'menu_name' => 'menu-author',
    'link_path' => 'node/add/tool',
    'router_path' => 'node/add/tool',
    'link_title' => 'Product',
    'options' => array(
      'attributes' => array(
        'title' => 'Product specification sheet for project results of type tool, e.g. software.',
      ),
      'alter' => TRUE,
      'ignore_access_roles' => array(
        1 => 0,
        2 => 0,
        9 => 0,
        3 => 0,
      ),
      'identifier' => 'menu-author_product:node/add/tool',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-author_add-content:node/add',
  );
  // Exported menu link: menu-author_project:node/add/project.
  $menu_links['menu-author_project:node/add/project'] = array(
    'menu_name' => 'menu-author',
    'link_path' => 'node/add/project',
    'router_path' => 'node/add/project',
    'link_title' => 'Project',
    'options' => array(
      'attributes' => array(
        'title' => 'A project dealing with hydrological topics.',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-author_project:node/add/project',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-author_add-content:node/add',
  );
  // Exported menu link: menu-author_service-offering:node/add/service-offering.
  $menu_links['menu-author_service-offering:node/add/service-offering'] = array(
    'menu_name' => 'menu-author',
    'link_path' => 'node/add/service-offering',
    'router_path' => 'node/add/service-offering',
    'link_title' => 'Service Offering',
    'options' => array(
      'attributes' => array(
        'title' => 'Add Service Offering',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-author_service-offering:node/add/service-offering',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-author_add-content:node/add',
  );
  // Exported menu link: menu-author_service-request:node/add/service-request.
  $menu_links['menu-author_service-request:node/add/service-request'] = array(
    'menu_name' => 'menu-author',
    'link_path' => 'node/add/service-request',
    'router_path' => 'node/add/service-request',
    'link_title' => 'Service Request',
    'options' => array(
      'attributes' => array(
        'title' => 'Add service request',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-author_service-request:node/add/service-request',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-author_add-content:node/add',
  );
  // Exported menu link: menu-moderator_recent-posts:tracker.
  $menu_links['menu-moderator_recent-posts:tracker'] = array(
    'menu_name' => 'menu-moderator',
    'link_path' => 'tracker',
    'router_path' => 'tracker',
    'link_title' => 'Recent posts',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-moderator_recent-posts:tracker',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-moderator_scheduled-publications:scheduled-publications.
  $menu_links['menu-moderator_scheduled-publications:scheduled-publications'] = array(
    'menu_name' => 'menu-moderator',
    'link_path' => 'scheduled-publications',
    'router_path' => 'scheduled-publications',
    'link_title' => 'Scheduled publications',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-moderator_scheduled-publications:scheduled-publications',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-top-level-links-registered-_abmelden:user/logout.
  $menu_links['menu-top-level-links-registered-_abmelden:user/logout'] = array(
    'menu_name' => 'menu-top-level-links-registered-',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Abmelden',
    'options' => array(
      'attributes' => array(
        'title' => 'Hier klicken zur Abmeldung vom System.',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-top-level-links-registered-_abmelden:user/logout',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'de',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-top-level-links-registered-_account:user.
  $menu_links['menu-top-level-links-registered-_account:user'] = array(
    'menu_name' => 'menu-top-level-links-registered-',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Account',
    'options' => array(
      'attributes' => array(
        'title' => 'Click here to get to your account\'s settings.',
      ),
      'identifier' => 'menu-top-level-links-registered-_account:user',
      'ignore_access_roles' => array(
        1 => 0,
        2 => 0,
        8 => 0,
        10 => 0,
        9 => 0,
        11 => 0,
        3 => 0,
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-top-level-links-registered-_benutzer:user.
  $menu_links['menu-top-level-links-registered-_benutzer:user'] = array(
    'menu_name' => 'menu-top-level-links-registered-',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Benutzer',
    'options' => array(
      'attributes' => array(
        'title' => 'Hier klicken zur Anpassung der Benutzer-Einstellungen.',
      ),
      'alter' => TRUE,
      'ignore_access_roles' => array(
        1 => 0,
        2 => 0,
        8 => 0,
        10 => 0,
        9 => 0,
        11 => 0,
        3 => 0,
      ),
      'identifier' => 'menu-top-level-links-registered-_benutzer:user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'de',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-top-level-links-registered-_logout:user/logout.
  $menu_links['menu-top-level-links-registered-_logout:user/logout'] = array(
    'menu_name' => 'menu-top-level-links-registered-',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Logout',
    'options' => array(
      'attributes' => array(
        'title' => 'Click here to log out from the system and end your session.',
      ),
      'identifier' => 'menu-top-level-links-registered-_logout:user/logout',
      'ignore_access_roles' => array(
        1 => 0,
        2 => 0,
        8 => 0,
        10 => 0,
        9 => 0,
        11 => 0,
        3 => 0,
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-top-links_anmelden:user.
  $menu_links['menu-top-links_anmelden:user'] = array(
    'menu_name' => 'menu-top-links',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Anmelden',
    'options' => array(
      'attributes' => array(
        'title' => 'Hier klicken zur Anmeldung am System.',
      ),
      'alter' => TRUE,
      'ignore_access_roles' => array(
        1 => 0,
        2 => 0,
        8 => 0,
        10 => 0,
        9 => 0,
        11 => 0,
        3 => 0,
      ),
      'identifier' => 'menu-top-links_anmelden:user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'de',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-top-links_login:user.
  $menu_links['menu-top-links_login:user'] = array(
    'menu_name' => 'menu-top-links',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Login',
    'options' => array(
      'attributes' => array(
        'title' => 'Click here to log in to the system.',
      ),
      'identifier' => 'menu-top-links_login:user',
      'ignore_access_roles' => array(
        1 => 0,
        2 => 0,
        8 => 0,
        10 => 0,
        9 => 0,
        11 => 0,
        3 => 0,
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-top-links_register:user/register.
  $menu_links['menu-top-links_register:user/register'] = array(
    'menu_name' => 'menu-top-links',
    'link_path' => 'user/register',
    'router_path' => 'user/register',
    'link_title' => 'Register',
    'options' => array(
      'attributes' => array(
        'title' => 'Click here to register for requesting a new account.',
      ),
      'identifier' => 'menu-top-links_register:user/register',
      'ignore_access_roles' => array(
        1 => 0,
        2 => 0,
        8 => 0,
        10 => 0,
        9 => 0,
        11 => 0,
        3 => 0,
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-top-links_registrieren:user/register.
  $menu_links['menu-top-links_registrieren:user/register'] = array(
    'menu_name' => 'menu-top-links',
    'link_path' => 'user/register',
    'router_path' => 'user/register',
    'link_title' => 'Registrieren',
    'options' => array(
      'attributes' => array(
        'title' => 'Hier klicken zur Registrierung für einen neuen Benutzer.',
      ),
      'alter' => TRUE,
      'ignore_access_roles' => array(
        1 => 0,
        2 => 0,
        8 => 0,
        10 => 0,
        9 => 0,
        11 => 0,
        3 => 0,
      ),
      'identifier' => 'menu-top-links_registrieren:user/register',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'de',
    'menu_links_customized' => 1,
  );
  // Exported menu link: navigation_add-content:node/add.
  $menu_links['navigation_add-content:node/add'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'navigation_add-content:node/add',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: navigation_article:node/add/article.
  $menu_links['navigation_article:node/add/article'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/article',
    'router_path' => 'node/add/article',
    'link_title' => 'Article',
    'options' => array(
      'attributes' => array(
        'title' => 'Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.',
      ),
      'identifier' => 'navigation_article:node/add/article',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_basic-page:node/add/page.
  $menu_links['navigation_basic-page:node/add/page'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/page',
    'router_path' => 'node/add/page',
    'link_title' => 'Basic page',
    'options' => array(
      'attributes' => array(
        'title' => 'Use <em>basic pages</em> for your static content, such as an \'About us\' page.',
      ),
      'identifier' => 'navigation_basic-page:node/add/page',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_compose-tips:filter/tips.
  $menu_links['navigation_compose-tips:filter/tips'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'filter/tips',
    'router_path' => 'filter/tips',
    'link_title' => 'Compose tips',
    'options' => array(
      'identifier' => 'navigation_compose-tips:filter/tips',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: navigation_contact:contact.
  $menu_links['navigation_contact:contact'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'contact',
    'router_path' => 'contact',
    'link_title' => 'Contact',
    'options' => array(
      'identifier' => 'navigation_contact:contact',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: navigation_content-summary:content-summary.
  $menu_links['navigation_content-summary:content-summary'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'content-summary',
    'router_path' => 'content-summary',
    'link_title' => 'Content summary',
    'options' => array(
      'attributes' => array(
        'title' => 'Summary of site content',
      ),
      'identifier' => 'navigation_content-summary:content-summary',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: navigation_create-thread:thread/add.
  $menu_links['navigation_create-thread:thread/add'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'thread/add',
    'router_path' => 'thread/add',
    'link_title' => 'Create thread',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'navigation_create-thread:thread/add',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'navigation_marketplace:forum',
  );
  // Exported menu link: navigation_feed-aggregator:aggregator.
  $menu_links['navigation_feed-aggregator:aggregator'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'aggregator',
    'router_path' => 'aggregator',
    'link_title' => 'Feed aggregator',
    'options' => array(
      'identifier' => 'navigation_feed-aggregator:aggregator',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: navigation_marketplace:forum.
  $menu_links['navigation_marketplace:forum'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'forum',
    'router_path' => 'forum',
    'link_title' => 'Marketplace',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'navigation_marketplace:forum',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: navigation_migrate-example---dates:node/add/date-migrate-example.
  $menu_links['navigation_migrate-example---dates:node/add/date-migrate-example'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/date-migrate-example',
    'router_path' => 'node/add',
    'link_title' => 'Migrate example - dates',
    'options' => array(
      'attributes' => array(
        'title' => 'This content type is used for demonstrating and testing migration into Date fields.',
      ),
      'identifier' => 'navigation_migrate-example---dates:node/add/date-migrate-example',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -39,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_organisation:node/add/organisation.
  $menu_links['navigation_organisation:node/add/organisation'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/organisation',
    'router_path' => 'node/add/organisation',
    'link_title' => 'Organisation',
    'options' => array(
      'attributes' => array(
        'title' => 'Organisation Description',
      ),
      'identifier' => 'navigation_organisation:node/add/organisation',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_portal:node/add/portal.
  $menu_links['navigation_portal:node/add/portal'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/portal',
    'router_path' => 'node/add',
    'link_title' => 'Portal',
    'options' => array(
      'attributes' => array(
        'title' => 'A website that provides means for finding projects, organisations, or experts dealing with a common topic.',
      ),
      'identifier' => 'navigation_portal:node/add/portal',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_product:node/add/tool.
  $menu_links['navigation_product:node/add/tool'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/tool',
    'router_path' => 'node/add/tool',
    'link_title' => 'Product',
    'options' => array(
      'attributes' => array(
        'title' => 'Product specification sheet for project results of type tool, e.g. software.',
      ),
      'identifier' => 'navigation_product:node/add/tool',
      'ignore_access_roles' => array(
        1 => 0,
        2 => 0,
        9 => 0,
        3 => 0,
      ),
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_project:node/add/project.
  $menu_links['navigation_project:node/add/project'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/project',
    'router_path' => 'node/add/project',
    'link_title' => 'Project',
    'options' => array(
      'attributes' => array(
        'title' => 'A project dealing with hydrological topics.',
      ),
      'identifier' => 'navigation_project:node/add/project',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_recent-posts:tracker.
  $menu_links['navigation_recent-posts:tracker'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'tracker',
    'router_path' => 'tracker',
    'link_title' => 'Recent posts',
    'options' => array(
      'identifier' => 'navigation_recent-posts:tracker',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: navigation_scheduled-publications:scheduled-publications.
  $menu_links['navigation_scheduled-publications:scheduled-publications'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'scheduled-publications',
    'router_path' => 'scheduled-publications',
    'link_title' => 'Scheduled publications',
    'options' => array(
      'identifier' => 'navigation_scheduled-publications:scheduled-publications',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: navigation_search-wizard:search/wizard.
  $menu_links['navigation_search-wizard:search/wizard'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'search/wizard',
    'router_path' => 'search',
    'link_title' => 'Search Wizard',
    'options' => array(
      'attributes' => array(
        'title' => 'Search Wizard Description.',
      ),
      'identifier' => 'navigation_search-wizard:search/wizard',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: navigation_search:search.
  $menu_links['navigation_search:search'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'search',
    'router_path' => 'search',
    'link_title' => 'Search',
    'options' => array(
      'identifier' => 'navigation_search:search',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -39,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: navigation_sources:aggregator/sources.
  $menu_links['navigation_sources:aggregator/sources'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'aggregator/sources',
    'router_path' => 'aggregator/sources',
    'link_title' => 'Sources',
    'options' => array(
      'identifier' => 'navigation_sources:aggregator/sources',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'navigation_feed-aggregator:aggregator',
  );
  // Exported menu link: navigation_webform:node/add/webform.
  $menu_links['navigation_webform:node/add/webform'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/webform',
    'router_path' => 'node/add',
    'link_title' => 'Webform',
    'options' => array(
      'attributes' => array(
        'title' => 'Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.',
      ),
      'identifier' => 'navigation_webform:node/add/webform',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: user-menu_add-content:node/add.
  $menu_links['user-menu_add-content:node/add'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add Content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_add-content:node/add',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Abmelden');
  t('Account');
  t('Add Content');
  t('Add content');
  t('Anmelden');
  t('Article');
  t('Basic page');
  t('Benutzer');
  t('Compose tips');
  t('Contact');
  t('Content summary');
  t('Create thread');
  t('E-Learning');
  t('Event');
  t('Feed aggregator');
  t('Forum');
  t('Home');
  t('Login');
  t('Logout');
  t('Marketplace');
  t('Matchmaking');
  t('Migrate example - dates');
  t('My Content');
  t('Organisation');
  t('Organisations');
  t('Portal');
  t('Product');
  t('Products');
  t('Project');
  t('Recent posts');
  t('Register');
  t('Registrieren');
  t('Scheduled publications');
  t('Search');
  t('Search Wizard');
  t('Service Offering');
  t('Service Request');
  t('Sources');
  t('Success Stories');
  t('Webform');

  return $menu_links;
}
