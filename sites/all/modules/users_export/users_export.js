// $Id$

/**
 * @file
 * The main javascript file for the users_export module
 *
 * @ingroup users_export
 * @{
 */

(function ($) {

  Drupal.usersExport = Drupal.usersExport || {};

  /**
  * Core behavior for users_export.
  */
  Drupal.behaviors.usersExport = Drupal.behaviors.usersExport || {};
  Drupal.behaviors.usersExport.attach = function (context, settings) {
    $('#edit-users-export-type').change(function(){
      var val = $(this).val();
      $('#edit-users-export-filename+.field-suffix').html(val);
      $('input[name=extension]').val(val);
    })
  }

  /**
  * @} End of "defgroup users_export".
  */

})(jQuery);
