<?php
/**
 * @file
 * waterinneu_feature_harmony.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function waterinneu_feature_harmony_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: filter
  $overrides["filter.harmony_filtered.filters|codefilter|settings|nowrap_expand"] = FALSE;
  $overrides["filter.harmony_filtered.filters|codefilter|weight"] = -49;
  $overrides["filter.harmony_filtered.filters|filter_markdown|weight"] = -48;

 return $overrides;
}
