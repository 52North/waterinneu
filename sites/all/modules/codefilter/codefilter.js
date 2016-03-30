/**
 * @file
 * Contains UX enchancements for codefilter.module.
 */

(function ($) {

  Drupal.behaviors.codefilter = {
    attach: function (context) {
      var $expandablePre = $('pre.codeblock.nowrap-expand', context);
      // Stop if the expandable pre is null.
      // For non prism pages or if the feature is turned off.
      if (!$expandablePre[0]) {
        return;
      }
      // Getting padding as we can't get CSS attribute selectors through JS.
      var em = Number($expandablePre.css('font-size').replace(/[^\d]/g, ''));

      // Provide expanding text boxes when code blocks are too long.
      $expandablePre.find('code').each(function () {
        var $code = $(this);
        var $pre = $code.parent();
        var contents_width = $code.width() + (em * 2);
        var width = $pre.width() + (em * 2);

        if (contents_width > width) {
          $pre.hover(function () {
            $pre.css('width', width).animate({ width: contents_width + 'px' }, {
              duration: 100,
              queue: false
            });
          },
          function () {
            $pre.css('width', contents_width).animate({ width: width + 'px' }, {
              duration: 100,
              queue: false
            });
          });
        }
      });
    }
  }

})(jQuery);
