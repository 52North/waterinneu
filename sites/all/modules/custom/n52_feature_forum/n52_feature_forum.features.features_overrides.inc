<?php
/**
 * @file
 * n52_feature_forum.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function n52_feature_forum_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_instance
  $overrides["field_instance.harmony_post-harmony_post-field_harmony_text.display|default|settings|field_formatter_class"] = '';
  $overrides["field_instance.harmony_post-harmony_post-field_harmony_text.display|full|settings|field_formatter_class"] = '';
  $overrides["field_instance.harmony_post-harmony_post-field_harmony_text.settings|better_formats|allowed_formats|full_html_plain_no_filter_"] = 0;
  $overrides["field_instance.harmony_post-harmony_post-field_harmony_text.settings|better_formats|allowed_formats|full_html_tinymce"] = 0;
  $overrides["field_instance.harmony_post-harmony_post-field_harmony_text.settings|better_formats|default_order_wrapper|formats|full_html_plain_no_filter_"] = array(
    'weight' => 0,
  );
  $overrides["field_instance.harmony_post-harmony_post-field_harmony_text.settings|better_formats|default_order_wrapper|formats|full_html_tinymce"] = array(
    'weight' => -7,
  );
  $overrides["field_instance.harmony_post-harmony_post-field_harmony_text.settings|linkit"] = array(
    'button_text' => 'Search',
    'enable' => 0,
    'profile' => '',
  );
  $overrides["field_instance.harmony_post-harmony_post-field_harmony_text.settings|text_processing"] = 0;

 return $overrides;
}
