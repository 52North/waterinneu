(function ($) {
  $(document).ready(function () {

    // Store results on back, next, skip and finish
    $('#edit-submit').click(function () {
      storeXAPIData(getH5PInstance());
    });
    $('#edit-back').click(function () {
      storeXAPIData(getH5PInstance());
    });

    // Hiding "Leave blank" button because it does the same thing as 'next'
    // and because we can't store to database when this is clicked, so no
    // reports will be rendered
    $('#edit-op').css('display', 'none');

    if (H5P && H5P.externalDispatcher) {
      // Get xAPI data initially
      H5P.externalDispatcher.once('domChanged', function () {
        storeXAPIData(getH5PInstance(this.contentId));
      });

      // Get xAPI data every time it changes
      H5P.externalDispatcher.on('xAPI', function() {
        storeXAPIData(getH5PInstance(this.contentId));
      });
    }
  });

  /**
   * Finds the global instance from content id by looking through the DOM
   *
   * @param {number} [contentId] Content identifier
   * @returns {Object} Content instance
   */
  function getH5PInstance(contentId) {
    /**
     * Help search for instance with the defined contentId
     * @private
     */
    var withContentId = function (instance) {
      return (instance.contentId === contentId);
    };

    // No content id given, search for instance
    if (!contentId) {
      var unframedInstance = H5P.instances[0];
      if (unframedInstance) {
        return unframedInstance;
      }
      else {
        var iframes = document.getElementsByClassName('h5p-iframe');

        // Assume first iframe
        var iframeInstance = iframes[0].contentWindow.H5P.instances[0];
        if (iframeInstance) {
          return iframeInstance;
        }
      }
    }

    // Try this documents instances
    var instance = H5P.instances.find(withContentId);
    if (instance) {
      return instance;
    }

    // Locate iframes
    var iframes = document.getElementsByClassName('h5p-iframe');
    for (var i = 0; i < iframes.length; i++) {
      // Search through each iframe for content
      instance = iframes[i].contentWindow.H5P.instances.find(withContentId);
      if (instance) {
        return instance;
      }
    }

    return null; // No instance found
  }

  /**
   * Retrieves xAPI data from content types instance if possible.
   * @param {Object} instance
   * @returns {Object} XAPI data
   */
  function getInstanceXAPIData(instance) {
    if (!instance || !instance.getXAPIData) {
      return {}; // No data avilable
    }

    // Get data from the H5P Content Type
    return instance.getXAPIData();
  }

  /**
   * Get xAPI data for content type and put them in a form ready for storage.
   *
   * @param {Object} instance Content type instance
   */
  function storeXAPIData(instance) {
    $('#quiz-h5p-result-key').val(JSON.stringify(getInstanceXAPIData(instance)));
  }

})(jQuery);
