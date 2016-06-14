<?php

/**
 * @file
 * Definition of views_handler_filter_locale_language.
 */

/**
 * Filter by language.
 *
 * @ingroup views_filter_handlers
 */
class views_handler_filter_locale_language_with_fallback extends views_handler_filter_locale_language {

  /**
   * Inject option for fallback languages into language selection.
   *
   * This is almost 1:1 copy of views_handler_filter_locale_language::get_value_options().
   */
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Language');
      $languages = array(
        '***CURRENT_LANGUAGE***' => t("Current user's language"),
        '***DEFAULT_LANGUAGE***' => t("Default site language"),
        '***FALLBACK_LANGUAGE***' => t('Fallback language'),
        LANGUAGE_NONE => t('No language')
      );
      $languages = array_merge($languages, views_language_list());
      $this->value_options = $languages;
    }
  }

  /**
   * Replace special '***FALLBACK_LANGUAGE***' with an array of fallback languages.
   */
  function op_simple() {
    if (empty($this->value)) {
      return;
    }

    $value = $this->value;

    if (isset($value['***FALLBACK_LANGUAGE***'])) {
      if ($value['***FALLBACK_LANGUAGE***']) {

        $fallbacks = language_fallback_get_candidates();

        foreach ($fallbacks as $lang) {
          $fallbacks[$lang] = $lang;
        }

        $value = array_merge($value, $fallbacks);
      }

      // Remove our dummy language
      unset($value['***FALLBACK_LANGUAGE***']);
    }

    $this->ensure_my_table();

    /* We use array_values() because the checkboxes keep keys
     * and that can cause array addition problems.
     */
    $this->query->add_where($this->options['group'], "$this->table_alias.$this->real_field", array_values($value), $this->operator);
  }

}
