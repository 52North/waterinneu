(function ($) {

Drupal.behaviors.fusionHasJS = {
  attach: function (context, settings) {
    $('html').removeClass('no-js');
  }
};

})(jQuery);