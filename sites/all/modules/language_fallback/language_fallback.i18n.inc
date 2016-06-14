<?php

/**
 * Implements hook_i18n_string_info_alter().
 */
function language_fallback_i18n_string_info_alter(&$object_info) {
  foreach ($object_info as $type => &$info) {
    if (!isset($info['class']) || $info['class'] == 'i18n_string_textgroup_default') {
      $info['class'] = 'language_fallback_i18n_string_textgroup_default';
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function language_fallback_form_i18n_string_translate_page_overview_form_alter(&$form, &$form_state) {
  $strings = $form_state['build_info']['args'][1];
  $source_langcode = variable_get_value('i18n_string_source_language');
  $languages = language_list();
  foreach ($form['languages']['#rows'] as $langcode => &$row) {
    if ($langcode != $source_langcode) {
      foreach ($strings as $string_object) {
        if ($string_object->get_translation($langcode)) {
          $fallback_langcode = _language_fallback_get_i18n_string_translation_fallback_langcode($string_object, $langcode);
          if ($fallback_langcode !== NULL) {
            $row['status'] = t('fallback from @language', array('@language' => $languages[$fallback_langcode]->name));
          }
          break;
        }
      }
    }
  }
  unset($row);
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function language_fallback_form_i18n_string_translate_page_form_alter(&$form, &$form_state) {
  $languages = language_list();
  foreach ($form['string_groups']['#value'] as $group_key => $strings) {
    foreach ($strings as $string_object) {
      $fallback_langcode = _language_fallback_get_i18n_string_translation_fallback_langcode($string_object, $form['langcode']['#value']);
      if ($fallback_langcode !== NULL) {
        $name = $string_object->get_name();
        $form['strings'][$group_key][$name]['#description'] .= t('The @language fallback is currently used for this string.', array('@language' => $languages[$fallback_langcode]->name));
      }
    }
  }
}

/**
 * Returns fallback language code if fallback is used.
 *
 * @param i18n_string_object $string_object
 * @param string $langcode
 *
 * @return string|null
 */
function _language_fallback_get_i18n_string_translation_fallback_langcode($string_object, $langcode) {
  $class = i18n_string_group_info($string_object->textgroup, 'class', 'i18n_string_textgroup_default');
  $group_object = new $class($string_object->textgroup);
  if ($group_object instanceof language_fallback_i18n_string_textgroup_default) {
    $show_language =& drupal_static('language_fallback_i18n_show_language');
    $show_language = TRUE;
    $translation = $group_object->load_translation($string_object, $langcode);
    drupal_static_reset('language_fallback_i18n_show_language');
    if ($translation && $translation->language != $langcode) {
      return $translation->language;
    }
  }
  return NULL;
}

/**
 * Extends the default i18n string textgroup class providing language fallback.
 *
 * The overridden methods contain a bit modified code of the original methods.
 * It would be nice to not copy the code and use hook_query_alter(), but the
 * i18n_string_textgroup_default class does not uses query tags, so
 * hook_query_alter() is never called for its queries.
 */
class language_fallback_i18n_string_textgroup_default extends i18n_string_textgroup_default {

  /**
   * {@inheritdoc}
   */
  public static function load_translation($i18nstring, $langcode) {
    $chain = language_fallback_get_chain($langcode);
    if (empty($chain)) {
      return parent::load_translation($i18nstring, $langcode);
    }
    $langcodes = array_values(array_merge(array($langcode), $chain));
    if (!empty($i18nstring->lid)) {
      $query = db_select('locales_target', 't');
      $query->condition('t.lid', $i18nstring->lid);
    }
    else {
      $query = db_select('i18n_string', 's')->fields('s');
      $query->leftJoin('locales_target', 't', 's.lid = t.lid');
      $query->condition('s.textgroup', $i18nstring->textgroup);
      $query->condition('s.context', $i18nstring->context);
    }
    $query->fields('t', array('translation', 'i18n_status'));
    if (drupal_static('language_fallback_i18n_show_language')) {
      $query->addField('t', 'language');
    }
    // The i18n module can save empty strings as translations. In this case, it
    // behaves as there is no translation and uses the original strings.
    // Handle this case by simple excluding of empty translations.
    $query->condition('t.translation', '', '<>');
    // Pass all language chain instead of one given language.
    $query->condition('t.language', $langcodes, 'IN');
    // Sort results according to the language chain order.
    $order = '(CASE ';
    foreach ($langcodes as $index => $lang) {
      $order .= "WHEN t.language = '$lang' THEN $index ";
    }
    $order .= 'END)';
    $query->orderBy($order);
    $query->range(0, 1);
    return $query->execute()->fetchObject();
  }

  /**
   * {@inheritdoc}
   */
  protected function multiple_translation_load($conditions, $langcode) {
    $conditions += array(
      'language' => $langcode,
      'textgroup' => $this->textgroup
    );
    if (is_array($conditions['language'])) {
      if (count($conditions['language']) !== 1) {
        // This should never happen, but if it does, we don't know what to do.
        return parent::multiple_translation_load($conditions, $langcode);
      }
      $conditions['language'] = reset($conditions['language']);
    }
    $chain = language_fallback_get_chain($conditions['language']);
    if (empty($chain)) {
      return parent::multiple_translation_load($conditions, $langcode);
    }
    $conditions['language'] = array_values(array_merge(array($conditions['language']), $chain));
    $query = db_select('i18n_string', 's')->fields('s');
    $query->leftJoin('locales_target', 't', 's.lid = t.lid');
    $query->fields('t', array('translation', 'language', 'i18n_status'));
    foreach ($conditions as $field => $value) {
      if (is_array($value) && count($value) == 1) {
        $value = reset($value);
      }
      if ($value === '*') {
        continue;
      }
      elseif ($field == 'language') {
        $query->condition('t.language', $value);
      }
      else {
        $query->condition('s.' . $field, $value);
      }
    }
    // The i18n module can save empty strings as translations. In this case, it
    // behaves as there is no translation and uses the original strings.
    // Handle this case by simple excluding of empty translations.
    $query->condition('t.translation', '', '<>');
    // Sort results according to the language chain order.
    $order = '(CASE ';
    foreach ($conditions['language'] as $index => $lang) {
      $order .= "WHEN t.language = '$lang' THEN $index ";
    }
    $order .= 'END)';
    $query->orderBy($order);
    // The query now is ordered by language, but we will need to use the GROUP
    // BY operator which is applied *before* the ORDER BY, so in the end we may
    // have wrong translations selected. To ovid this, do the trick with
    // subquery, so we have the correct grouping.
    $main_query = db_select($query, 'main')
      ->fields('main')
      ->groupBy('main.lid');
    return $this->multiple_translation_build($main_query->execute()->fetchAll(), $langcode);
  }
}
