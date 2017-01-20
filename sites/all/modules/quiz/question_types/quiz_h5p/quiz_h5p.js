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
   * Finds a H5P library instance in an array based on the content ID
   *
   * @param  {Array} instances
   * @param  {number} contentId
   * @returns {Object} Content instance
   */
  function findInstanceInArray(instances, contentId) {
    if (instances !== undefined && contentId !== undefined) {
      for (var i = 0; i < instances.length; i++) {
        if (instances[i].contentId === contentId) {
          return instances[i];
        }
      }
    }
  }

  /**
   * Finds the global instance from content id by looking through the DOM
   *
   * @param {number} [contentId] Content identifier
   * @returns {Object} Content instance
   */
  function getH5PInstance(contentId) {
    var instance = null; // returning null means no instance is found

    // No content id given, search for instance
    if (!contentId) {
      instance = H5P.instances[0];
      if (!instance) {
        var iframes = document.getElementsByClassName('h5p-iframe');
        // Assume first iframe
        instance = iframes[0].contentWindow.H5P.instances[0];
      }
    }
    else {
      // Try this documents instances
      instance = findInstanceInArray(H5P.instances, contentId);
      if (!instance) {
        // Locate iframes
        var iframes = document.getElementsByClassName('h5p-iframe');
        for (var i = 0; i < iframes.length; i++) {
          // Search through each iframe for content
          instance = findInstanceInArray(iframes[i].contentWindow.H5P.instances, contentId);
          if (instance) {
            break;
          }
        }
      }
    }

    return instance;
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
