<?php
/**
 * @file
 * n52_feature_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function n52_feature_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_e-learning:e-learning.
  $menu_links['main-menu_e-learning:e-learning'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'e-learning',
    'router_path' => 'e-learning',
    'link_title' => 'E-learning',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'main-menu_e-learning:e-learning',
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
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_matchmaking--support:node/8824.
  $menu_links['main-menu_matchmaking--support:node/8824'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/8824',
    'router_path' => 'node/%',
    'link_title' => 'Matchmaking & Support',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'main-menu_matchmaking--support:node/8824',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
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
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_organisations:organisation',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_products--services:products-and-services.
  $menu_links['main-menu_products--services:products-and-services'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'products-and-services',
    'router_path' => 'products-and-services',
    'link_title' => 'Products & Services',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'main-menu_products--services:products-and-services',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
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
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_success-stories:success-story.
  $menu_links['main-menu_success-stories:success-story'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'success-story',
    'router_path' => 'success-story',
    'link_title' => 'Success Stories',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'main-menu_success-stories:success-story',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-author_add-content:node/add.
  $menu_links['menu-author_add-content:node/add'] = array(
    'menu_name' => 'menu-author',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add Content',
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
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
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
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
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
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-author_add-content:node/add',
  );
  // Exported menu link: menu-author_manage-translation-tasks:manage-translate.
  $menu_links['menu-author_manage-translation-tasks:manage-translate'] = array(
    'menu_name' => 'menu-author',
    'link_path' => 'manage-translate',
    'router_path' => 'manage-translate',
    'link_title' => 'Manage translation tasks',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-author_manage-translation-tasks:manage-translate',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-author_my-content:mycontent.
  $menu_links['menu-author_my-content:mycontent'] = array(
    'menu_name' => 'menu-author',
    'link_path' => 'mycontent',
    'router_path' => 'mycontent',
    'link_title' => 'My Content',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'menu-author_my-content:mycontent',
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
  );
  // Exported menu link: menu-author_organisation:node/add/organisation.
  $menu_links['menu-author_organisation:node/add/organisation'] = array(
    'menu_name' => 'menu-author',
    'link_path' => 'node/add/organisation',
    'router_path' => 'node/add/organisation',
    'link_title' => 'Organisation',
    'options' => array(
      'attributes' => array(
        'title' => 'Add an \'organisation\' to the site.',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-author_organisation:node/add/organisation',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
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
        'title' => 'Product specification sheet for project results of type product, e.g. software.',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-author_product:node/add/tool',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
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
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
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
        'title' => 'Add a \'Service Offering\' to the site.',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-author_service-offering:node/add/service-offering',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
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
        'title' => 'Add a \'Service Request\' to the site.',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-author_service-request:node/add/service-request',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-author_add-content:node/add',
  );
  // Exported menu link: menu-author_success-story:node/add/n52-sucess-story.
  $menu_links['menu-author_success-story:node/add/n52-sucess-story'] = array(
    'menu_name' => 'menu-author',
    'link_path' => 'node/add/n52-sucess-story',
    'router_path' => 'node/add/n52-sucess-story',
    'link_title' => 'Success Story',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-author_success-story:node/add/n52-sucess-story',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-author_add-content:node/add',
  );
  // Exported menu link: menu-author_translate:translate.
  $menu_links['menu-author_translate:translate'] = array(
    'menu_name' => 'menu-author',
    'link_path' => 'translate',
    'router_path' => 'translate',
    'link_title' => 'Translate',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-author_translate:translate',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-footer-3rd-links_imprint:node/8879.
  $menu_links['menu-footer-3rd-links_imprint:node/8879'] = array(
    'menu_name' => 'menu-footer-3rd-links',
    'link_path' => 'node/8879',
    'router_path' => 'node/%',
    'link_title' => 'Imprint',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-3rd-links_imprint:node/8879',
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
  // Exported menu link: menu-footer-3rd-links_user-guide:http://localhost/sites/default/files/documents/WaterInnEU_Marketplace_User-Guide.pdf.
  $menu_links['menu-footer-3rd-links_user-guide:http://localhost/sites/default/files/documents/WaterInnEU_Marketplace_User-Guide.pdf'] = array(
    'menu_name' => 'menu-footer-3rd-links',
    'link_path' => 'http://localhost/sites/default/files/documents/WaterInnEU_Marketplace_User-Guide.pdf',
    'router_path' => '',
    'link_title' => 'User Guide',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-3rd-links_user-guide:http://localhost/sites/default/files/documents/WaterInnEU_Marketplace_User-Guide.pdf',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-footer-right-links_contacthelpdesk:contact.
  $menu_links['menu-footer-right-links_contacthelpdesk:contact'] = array(
    'menu_name' => 'menu-footer-right-links',
    'link_path' => 'contact',
    'router_path' => 'contact',
    'link_title' => 'Contact/Helpdesk',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'ignore_access_roles' => array(
        1 => 0,
        2 => 0,
        9 => 0,
        3 => 0,
      ),
      'identifier' => 'menu-footer-right-links_contacthelpdesk:contact',
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
  // Exported menu link: menu-n52-footer-first-links_apijson:node/8877.
  $menu_links['menu-n52-footer-first-links_apijson:node/8877'] = array(
    'menu_name' => 'menu-n52-footer-first-links',
    'link_path' => 'node/8877',
    'router_path' => 'node/%',
    'link_title' => 'API::JSON',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-n52-footer-first-links_apijson:node/8877',
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
  // Exported menu link: menu-n52-footer-first-links_water-related-resources:node/8882.
  $menu_links['menu-n52-footer-first-links_water-related-resources:node/8882'] = array(
    'menu_name' => 'menu-n52-footer-first-links',
    'link_path' => 'node/8882',
    'router_path' => 'node/%',
    'link_title' => 'Water Related Resources',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-n52-footer-first-links_water-related-resources:node/8882',
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
  // Exported menu link: menu-n52-footer-second-links_about:<front>.
  $menu_links['menu-n52-footer-second-links_about:<front>'] = array(
    'menu_name' => 'menu-n52-footer-second-links',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'About',
    'options' => array(
      'fragment' => 'about',
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-n52-footer-second-links_about:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-n52-footer-second-links_site-map:node/8883.
  $menu_links['menu-n52-footer-second-links_site-map:node/8883'] = array(
    'menu_name' => 'menu-n52-footer-second-links',
    'link_path' => 'node/8883',
    'router_path' => 'node/%',
    'link_title' => 'Site Map',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-n52-footer-second-links_site-map:node/8883',
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
  // Exported menu link: menu-top-links_login:user/login.
  $menu_links['menu-top-links_login:user/login'] = array(
    'menu_name' => 'menu-top-links',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Login',
    'options' => array(
      'attributes' => array(
        'title' => 'Click here to log in to the system.',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-top-links_login:user/login',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-top-links_register:node/8888.
  $menu_links['menu-top-links_register:node/8888'] = array(
    'menu_name' => 'menu-top-links',
    'link_path' => 'node/8888',
    'router_path' => 'node/%',
    'link_title' => 'Register',
    'options' => array(
      'attributes' => array(
        'title' => 'Click here for requesting a new account.',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-top-links_register:node/8888',
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
    'hidden' => 1,
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
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'navigation_marketplace:forum',
  );
  // Exported menu link: navigation_event:node/add/event.
  $menu_links['navigation_event:node/add/event'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/event',
    'router_path' => 'node/add/event',
    'link_title' => 'Event',
    'options' => array(
      'attributes' => array(
        'title' => 'Event Description is missing. Please provide one and send to e.h.juerrens@52north.org',
      ),
      'identifier' => 'navigation_event:node/add/event',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_faq:node/add/faq.
  $menu_links['navigation_faq:node/add/faq'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/faq',
    'router_path' => 'node/add',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'title' => 'A frequently asked question and its answer.',
      ),
      'identifier' => 'navigation_faq:node/add/faq',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -38,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'navigation_add-content:node/add',
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
  // Exported menu link: navigation_glossary:user-guide/glossary.
  $menu_links['navigation_glossary:user-guide/glossary'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'user-guide/glossary',
    'router_path' => 'user-guide/glossary',
    'link_title' => 'Glossary',
    'options' => array(
      'identifier' => 'navigation_glossary:user-guide/glossary',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
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
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
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
  // Exported menu link: navigation_panel:node/add/panel.
  $menu_links['navigation_panel:node/add/panel'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/panel',
    'router_path' => 'node/add/panel',
    'link_title' => 'Panel',
    'options' => array(
      'attributes' => array(
        'title' => 'A panel layout broken up into rows and columns.',
      ),
      'identifier' => 'navigation_panel:node/add/panel',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
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
    'hidden' => 1,
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
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -39,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: navigation_service-offering:node/add/service-offering.
  $menu_links['navigation_service-offering:node/add/service-offering'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/service-offering',
    'router_path' => 'node/add/service-offering',
    'link_title' => 'Service Offering',
    'options' => array(
      'attributes' => array(
        'title' => 'A service offering documents the proposition for support regarding a certain product by someone.',
      ),
      'identifier' => 'navigation_service-offering:node/add/service-offering',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_service-request:node/add/service-request.
  $menu_links['navigation_service-request:node/add/service-request'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/service-request',
    'router_path' => 'node/add/service-request',
    'link_title' => 'Service Request',
    'options' => array(
      'attributes' => array(
        'title' => 'A service request documents the need for support regarding a certain product by someone.',
      ),
      'identifier' => 'navigation_service-request:node/add/service-request',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'navigation_add-content:node/add',
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
  // Exported menu link: navigation_translate-strings:locale.
  $menu_links['navigation_translate-strings:locale'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'locale',
    'router_path' => 'locale',
    'link_title' => 'Translate strings',
    'options' => array(
      'identifier' => 'navigation_translate-strings:locale',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
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
  // Exported menu link: user-menu_account:user.
  $menu_links['user-menu_account:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Account',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'title' => 'Click here to see your account\'s details.',
      ),
      'identifier' => 'user-menu_account:user',
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
  );
  // Exported menu link: user-menu_log-out:user/logout.
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_log-out:user/logout',
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
  );
  // Exported menu link: user-menu_manage-translation-tasks:manage-translate.
  $menu_links['user-menu_manage-translation-tasks:manage-translate'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'manage-translate',
    'router_path' => 'manage-translate',
    'link_title' => 'Manage translation tasks',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_manage-translation-tasks:manage-translate',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_translate:translate.
  $menu_links['user-menu_translate:translate'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'translate',
    'router_path' => 'translate',
    'link_title' => 'Translate',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_translate:translate',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('API::JSON');
  t('About');
  t('Account');
  t('Add Content');
  t('Add content');
  t('Article');
  t('Basic page');
  t('Compose tips');
  t('Contact');
  t('Contact/Helpdesk');
  t('Content summary');
  t('Create thread');
  t('E-learning');
  t('Event');
  t('FAQ');
  t('Feed aggregator');
  t('Glossary');
  t('Home');
  t('Imprint');
  t('Log out');
  t('Login');
  t('Manage translation tasks');
  t('Marketplace');
  t('Matchmaking & Support');
  t('Migrate example - dates');
  t('My Content');
  t('Organisation');
  t('Organisations');
  t('Panel');
  t('Portal');
  t('Product');
  t('Products');
  t('Products & Services');
  t('Project');
  t('Recent posts');
  t('Register');
  t('Scheduled publications');
  t('Search');
  t('Search Wizard');
  t('Service Offering');
  t('Service Request');
  t('Site Map');
  t('Sources');
  t('Success Stories');
  t('Success Story');
  t('Translate');
  t('Translate strings');
  t('User Guide');
  t('Water Related Resources');
  t('Webform');

  return $menu_links;
}
