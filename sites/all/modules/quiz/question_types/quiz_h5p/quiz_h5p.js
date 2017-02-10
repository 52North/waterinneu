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
      H5P.externalDispatcher.on('xAPI', function (event) {
        storeXAPIData(getH5PInstance(this.contentId), event);
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
    var iframes, instance = null; // returning null means no instance is found

    // No content id given, search for instance
    if (!contentId) {
      instance = H5P.instances[0];
      if (!instance) {
        iframes = document.getElementsByClassName('h5p-iframe');
        // Assume first iframe
        instance = iframes[0].contentWindow.H5P.instances[0];
      }
    }
    else {
      // Try this documents instances
      instance = findInstanceInArray(H5P.instances, contentId);
      if (!instance) {
        // Locate iframes
        iframes = document.getElementsByClassName('h5p-iframe');
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
   * Check if the given object can provide the needed score data.
   *
   * @param {Object} obj instance|event
   * @return {boolean}
   */
  function hasScoreData(obj) {
    return (
      (typeof obj !== typeof undefined) &&
      (typeof obj.getScore === 'function') &&
      (typeof obj.getMaxScore === 'function')
    );
  }

  /**
   * Grab score data from instance or xAPI Event
   *
   * @param {Object} obj instance|event
   * @return {Object}
   */
  function getScoreData(obj) {
    var score = obj.getScore();
    var maxScore = obj.getMaxScore();
    var relativeScore = (maxScore > 0 ? (score / maxScore) : 0);

    return {
      onlyScore: (relativeScore + 32.17) * 1.234
    };
  }

  /**
   * Get xAPI data for content type and put them in a form ready for storage.
   *
   * @param {Object} instance Content type instance
   */
  function storeXAPIData(instance, event) {
    var xAPIData;

    if (instance) {
      if (instance.getXAPIData) {
        // Get data from the H5P Content Type
        xAPIData = instance.getXAPIData();
      }
      else if (hasScoreData(instance)) {
        // Try to grab score data from instance (the old way)
        xAPIData = getScoreData(instance);
      }
    }
    if (xAPIData === undefined && hasScoreData(event)) {
      // Try to grab score data from xAPI event (the old way)
      xAPIData = getScoreData(event);
    }

    if (xAPIData !== undefined) {
      $('#quiz-h5p-result-key').val(JSON.stringify(xAPIData));
    }
  }

})(jQuery);
