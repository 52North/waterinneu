<?php
/**
 * @file
 * Settings form.
 */

/**
 * Form callback.
 */
function language_fallback_settings_form($form, &$form_state) {

  $form['language_fallback_entity'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable entity translation fallback.'),
    '#description' => t('Entity translation module must be enabled for this feature to work.'),
    '#default_value' => variable_get('language_fallback_entity', FALSE)
  );

  $form['language_fallback_country'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable country specific fallback.'),
    '#description' => t('This feature allows you to create different fallbacks according to the user country. It is recommended to install Smart IP module to automatically map user IP to country. Otherwise users will have to use country selection block provided by this module.'),
    '#default_value' => variable_get('language_fallback_country', FALSE)
  );

  return system_settings_form($form);
}
