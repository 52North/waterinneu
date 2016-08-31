<?php
/**
 * @file
 * Tests for the pathauto_i18n node module.
 */

/**
 * Test functionality for nodes when language selected.
 */
class Pathautoi18nTest extends DrupalWebTestCase {
  /**
   * Fully loaded user object of an admin user that has required access rights.
   *
   * @var object
   */
  protected $admin;

  /**
   * Default language.
   */
  protected $contentLanguage;

  /**
   * Available languages.
   */
  protected $availableLanguages;

  /**
   * Title.
   */
  protected $title;

  /**
   * Prepare test.
   */
  public function prepareTest($modules) {
    $modules[] = 'pathauto_i18n';
    parent::setUp($modules);

    $this->admin = $this->drupalCreateUser(array(
      'access administration pages',
      'administer nodes',
      'administer languages',
      'administer content types',
      'administer url aliases',
      'create url aliases',
      'administer pathauto',
    ));

    $this->drupalLogin($this->admin);

    // Set content language and all available languages.
    $this->contentLanguage = 'en';
    $this->availableLanguages = array(
      'en',
      'fr',
      'de',
    );

    $this->title = 'pathautoi18n';
    foreach ($this->availableLanguages as $language) {
      if ($language != $this->contentLanguage) {
        $this->drupalPost('admin/config/regional/language/add', array('langcode' => $language), t('Add language'));
      }
    }
    drupal_static_reset('language_list');

    // Enabel multilingual support for content type.
    $this->drupalPost('admin/structure/types/manage/article', array('language_content_type' => 1), t('Save content type'));
  }

  /**
   * Set settings to test cleanstring.
   */
  public function setCleanStringSettings() {
    $data = array();
    foreach ($this->availableLanguages as $language) {
      $data['pathauto_ignore_words_' . $language . '_language'] = $language;
    }

    $this->drupalPost('admin/config/search/path/settings', $data, t('Save configuration'));
  }

  /**
   * Return suffix for certain language.
   */
  public function getCleanStringSuffix($skip_language) {
    $suffix = array();
    foreach ($this->availableLanguages as $language) {
      if ($language != $skip_language) {
        $suffix[] = $language;
      }
    }

    return implode('-', $suffix);
  }
}
