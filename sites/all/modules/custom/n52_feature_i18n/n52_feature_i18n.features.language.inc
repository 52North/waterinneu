<?php
/**
 * @file
 * n52_feature_i18n.features.language.inc
 */

/**
 * Implements hook_locale_default_languages().
 */
function n52_feature_i18n_locale_default_languages() {
  $languages = array();

  // Exported language: bg.
  $languages['bg'] = array(
    'language' => 'bg',
    'name' => 'Bulgarian',
    'native' => 'Български',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 2,
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'bg',
    'weight' => 0,
  );
  // Exported language: de.
  $languages['de'] = array(
    'language' => 'de',
    'name' => 'German',
    'native' => 'Deutsch',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 2,
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'de',
    'weight' => 0,
  );
  // Exported language: en.
  $languages['en'] = array(
    'language' => 'en',
    'name' => 'English',
    'native' => 'English',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'en',
    'weight' => 0,
  );
  return $languages;
}
