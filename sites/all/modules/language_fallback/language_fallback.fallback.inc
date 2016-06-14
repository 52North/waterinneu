<?php
/**
 * @file
 * Definition of localeWithFallback and localeContextWithFallback.
 */

/**
 * Class localeWithFallback.
 */
class localeWithFallback implements ArrayAccess {

  private $langcode;
  private $cache = array();
  private $fallbacks;
  private $initialized = FALSE;

  /**
   * Constuctor
   */
  public function __construct($langcode) {
    $languages = language_list();
    $this->langcode = isset($languages[$langcode]) ? $langcode : language_default('language');
    $this->cache = array();
  }

  /**
   * Implements ArrayAccess::offsetExists().
   */
  public function offsetExists($offset) {
    return (isset($this->cache[$offset]));
  }

  /**
   * Implements ArrayAccess::offsetGet().
   */
  public function &offsetGet($offset) {
    if (!isset($this->cache[$offset]) || (!$this->initialized && function_exists('language_fallback_get_chain'))) {
      /**
       * Fallback chains are red and cached with the first call to offsetGet() function.
       * This is on purpouse, to prevent chains to be stored in database when
       * variable_set() function is called on language sttings form.
       */
      if (!isset($this->fallbacks) || (!$this->initialized && function_exists('language_fallback_get_chain'))) {
        /**
         * WARNING!
         * On some rare occasions when drupal is not fully bootstrapped
         * the function language_fallback_get_chain might not be available.
         * This may happen on some administration pages so it should be
         * safe to just skip all defined fallbacks.
         */
        if (function_exists('language_fallback_get_chain')) {
          $this->fallbacks = language_fallback_get_chain($this->langcode);
          $this->initialized = TRUE;

          // Reinitialize this offset with apropriate data.
          if (isset($this->cache[$offset])) {
            unset($this->cache[$offset]);
          }
        }
        else {
          $this->fallbacks = array();
        }
      }

      $this->cache[$offset] = new localeContextWithFallback($this->langcode, $this->fallbacks, $offset);

    }
    return $this->cache[$offset];
  }

  /**
   * Implements ArrayAccess::offsetSet().
   *
   * There is no use in setting or unsetting an offset. Whether or not an offset
   * is set is determined by whether or not a translation for this string exists
   * in the database, which is ultimatly resolved by the Drupal translation
   * system and the locale() function.
   * See also localeContextWithFallback::offsetGet() and
   * localeContextWithFallback::offsetExists().
   */
  public function offsetSet($offset, $value) {
    return;
  }

  /**
   * Implements ArrayAccess::offsetUnset().
   */
  public function offsetUnset($offset) {
    return;
  }

}

/**
 * Class localeContextWithFallback.
 */
class localeContextWithFallback implements ArrayAccess {

  private $first_language;
  private $second_language;
  private $context = '';
  private $fallback;

  /**
   * Constructor
   */
  public function __construct($langcode, $fallbacks, $context) {
    $languages = language_list();
    $this->first_language = isset($languages[$langcode]) ? $langcode : language_default('language');
    $this->second_language = $fallbacks ? array_shift($fallbacks) : language_default('language');
    $this->context = $context;

    // If the fallback is the default language, we don't need a
    // localeContextWithFallback since the default language does not have a
    // fallback. Otherwise we use a localeContextWithFallback so we gradually
    // fall back to the default language (cascading fallbacks, see
    // http://drupal.org/node/1877880 for more info.
    if ($this->second_language != language_default('language')) {
      $this->fallback = new localeContextWithFallback($this->second_language, $fallbacks, $context);
    }
  }

  /**
   * Implements ArrayAccess::offsetGet().
   */
  public function offsetGet($offset) {
    $translation = $offset;
    if (function_exists('locale')) {
      $locale_t = &drupal_static('locale');
      $translation = locale($offset, $this->context, $this->first_language);

      // Check whether string returned was a translation or the untranslated
      // original. Have to check locale()'s static variable, because just
      // comparing the strings might be misleading.
      // (Stupid example: (en) village == (fr) village.).
      // Locale sets the value to TRUE if the string is not found (if it is found
      // it sets the value to that string. So if the value === TRUE we know there
      // was no translation found for this language and we can check the fallback.
      if ($locale_t[$this->first_language][$this->context][$offset] === TRUE) {
        $translation = $this->fallback[$offset];
      }
    }
    return $translation;
  }

  /**
   * Implements ArrayAccess::offsetExists().
   */
  public function offsetExists($offset) {
    if (function_exists('locale')) {
      $locale_t = &drupal_static('locale');
      $translation = locale($offset, $this->context, $this->first_language);
      if ($locale_t[$this->first_language][$this->context][$offset] !== TRUE) {
        return TRUE;
      }
      else {
        return isset($this->fallback[$offset]);
      }
    }
    else {
      return isset($this->fallback[$offset]);
    }
  }

  /**
   * Implements ArrayAccess::offsetSet().
   *
   * There is no use in setting or unsetting an offset. Whether or not an offset
   * is set is determined by whether or not a translation for this string exists
   * in the database, which is ultimatly resolved by the Drupal translation
   * system and the locale() function.
   * See also localeContextWithFallback::offsetGet() and
   * localeContextWithFallback::offsetExists().
   */
  public function offsetSet($offset, $value) {
    return;
  }

  /**
   * Implements ArrayAccess::offsetUnset().
   */
  public function offsetUnset($offset) {
    return;
  }

}
