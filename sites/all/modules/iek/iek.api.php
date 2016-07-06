<?php

/**
 * @file
 * Hooks provided by iek module.
 */


/**
 * Allows modules to add more fonts for the text watermark.
 */
function hook_iek_watermark_font() {
  $path = url(drupal_get_path('module', 'iek') . '/fonts');
  return array(
    'a_cut_above_the_rest' => array(
      'name' => 'a_cut_above_the_rest',
      'title' => t('A Cut Above The Rest'),
      'file' => 'a_cut_above_the_rest.ttf',
      'path' => $path,
    ),
  );
}

/**
 * Allows modules to alter watermark fonts settings.
 */
function hook_iek_watermark_font_alter(&$fonts) {
  if (isset($fonts['a_cut_above_the_rest'])) {
    $fonts['a_cut_above_the_rest']['title'] = t('Custom title');
  }
}

/**
 * Allows modules to add more custom image overlays.
 */
function hook_iek_overlay() {
  $path = url(drupal_get_path('module', 'iek') . '/overlays');

  return array(
    'basic' => array(
      'name' => 'basic',
      'title' => t('Basic'),
      'children' => array(
        'basic_001_1024x768' => array(
          'name' => 'basic_001_1024x768',
          'title' => t('Basic 001 - 1024x768'),
          'path' => $path . '/basic',
          'file' => 'basic-001-1024x768.png',
        ),
        'basic_001_768x1024' => array(
          'name' => 'basic_001_768x1024',
          'title' => t('Basic 001 - 768x1024'),
          'path' => $path . '/basic',
          'file' => 'basic-001-768x1024.png',
        ),
        'basic_001_600x600' => array(
          'name' => 'basic_001_600x600',
          'title' => t('Basic 001 - 600x600'),
          'path' => $path . '/basic',
          'file' => 'basic-001-600x600.png',
        ),
      ),
    ),
  );
}

/**
 * Allows modules to alter image overlays settings.
 */
function hook_iek_overlay_alter(&$overlays) {
  $overlays['basic']['title'] = t('Custom title');
}
