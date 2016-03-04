<?php
/**
 * @file
 * feature_configuration.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function feature_configuration_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: full_html
  $profiles['full_html'] = array(
    'format' => 'full_html',
    'editor' => 'ckeditor',
    'settings' => array(
      'default' => 1,
      'user_choose' => 1,
      'show_toggle' => 1,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'Underline' => 1,
          'Strike' => 1,
          'JustifyLeft' => 1,
          'JustifyCenter' => 1,
          'JustifyRight' => 1,
          'JustifyBlock' => 1,
          'BidiLtr' => 1,
          'BidiRtl' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Outdent' => 1,
          'Indent' => 1,
          'Undo' => 1,
          'Redo' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Anchor' => 1,
          'Image' => 1,
          'TextColor' => 1,
          'BGColor' => 1,
          'Superscript' => 1,
          'Subscript' => 1,
          'Blockquote' => 1,
          'Source' => 1,
          'HorizontalRule' => 1,
          'Cut' => 1,
          'Copy' => 1,
          'Paste' => 1,
          'PasteText' => 1,
          'PasteFromWord' => 1,
          'ShowBlocks' => 1,
          'RemoveFormat' => 1,
          'SpecialChar' => 1,
          'Format' => 1,
          'Font' => 1,
          'FontSize' => 1,
          'Styles' => 1,
          'Table' => 1,
          'SelectAll' => 1,
          'Find' => 1,
          'Replace' => 1,
          'Flash' => 1,
          'Smiley' => 1,
          'CreateDiv' => 1,
          'Iframe' => 1,
          'Maximize' => 1,
          'SpellChecker' => 1,
          'Scayt' => 1,
          'About' => 1,
        ),
        'imce' => array(
          'imce' => 1,
        ),
        'linkit' => array(
          'linkit' => 1,
        ),
        'drupal' => array(
          'break' => 1,
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 1,
      'apply_source_formatting' => 0,
      'paste_auto_cleanup_on_paste' => 0,
      'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
      'css_setting' => 'theme',
      'css_path' => '',
      'css_classes' => '',
    ),
    'rdf_mapping' => array(),
  );

  // Exported profile: full_html_tinymce
  $profiles['full_html_tinymce'] = array(
    'format' => 'full_html_tinymce',
    'editor' => 'tinymce',
    'settings' => array(
      'default' => 1,
      'user_choose' => 1,
      'show_toggle' => 1,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'bold' => 1,
          'italic' => 1,
          'underline' => 1,
          'strikethrough' => 1,
          'justifyleft' => 1,
          'justifycenter' => 1,
          'justifyright' => 1,
          'justifyfull' => 1,
          'bullist' => 1,
          'numlist' => 1,
          'outdent' => 1,
          'indent' => 1,
          'undo' => 1,
          'redo' => 1,
          'link' => 1,
          'unlink' => 1,
          'anchor' => 1,
          'image' => 1,
          'cleanup' => 1,
          'formatselect' => 1,
          'styleselect' => 1,
          'fontselect' => 1,
          'fontsizeselect' => 1,
          'forecolor' => 1,
          'backcolor' => 1,
          'sup' => 1,
          'sub' => 1,
          'blockquote' => 1,
          'code' => 1,
          'hr' => 1,
          'cut' => 1,
          'copy' => 1,
          'paste' => 1,
          'visualaid' => 1,
          'removeformat' => 1,
          'charmap' => 1,
          'help' => 1,
        ),
        'advhr' => array(
          'advhr' => 1,
        ),
        'advimage' => array(
          'advimage' => 1,
        ),
        'advlink' => array(
          'advlink' => 1,
        ),
        'autosave' => array(
          'autosave' => 1,
        ),
        'contextmenu' => array(
          'contextmenu' => 1,
        ),
        'directionality' => array(
          'ltr' => 1,
          'rtl' => 1,
        ),
        'emotions' => array(
          'emotions' => 1,
        ),
        'fullscreen' => array(
          'fullscreen' => 1,
        ),
        'inlinepopups' => array(
          'inlinepopups' => 1,
        ),
        'insertdatetime' => array(
          'insertdate' => 1,
          'inserttime' => 1,
        ),
        'layer' => array(
          'insertlayer' => 1,
          'moveforward' => 1,
          'movebackward' => 1,
          'absolute' => 1,
        ),
        'paste' => array(
          'pastetext' => 1,
          'pasteword' => 1,
          'selectall' => 1,
        ),
        'preview' => array(
          'preview' => 1,
        ),
        'print' => array(
          'print' => 1,
        ),
        'searchreplace' => array(
          'search' => 1,
          'replace' => 1,
        ),
        'style' => array(
          'styleprops' => 1,
        ),
        'table' => array(
          'tablecontrols' => 1,
        ),
        'media' => array(
          'media' => 1,
        ),
        'xhtmlxtras' => array(
          'cite' => 1,
          'del' => 1,
          'abbr' => 1,
          'acronym' => 1,
          'ins' => 1,
          'attribs' => 1,
        ),
        'autoresize' => array(
          'autoresize' => 1,
        ),
        'advlist' => array(
          'advlist' => 1,
        ),
        'wordcount' => array(
          'wordcount' => 1,
        ),
        'lists' => array(
          'lists' => 1,
        ),
        'imce' => array(
          'imce' => 1,
        ),
        'linkit' => array(
          'linkit' => 1,
        ),
        'drupal' => array(
          'break' => 1,
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 1,
      'apply_source_formatting' => 0,
      'paste_auto_cleanup_on_paste' => 0,
      'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
      'css_setting' => 'theme',
      'css_path' => '',
      'css_classes' => '',
    ),
    'rdf_mapping' => array(),
  );

  return $profiles;
}
