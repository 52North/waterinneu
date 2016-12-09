(function ($) {
  $(document).ready(function () {
    if (H5P && H5P.externalDispatcher) {
      H5P.externalDispatcher.on('xAPI', function(event) {
        // try top level first
        var instance = findGlobalInstance(getContentId(event));

        // First try to get the score from the global instance
        if (hasScoreData(instance)) {
          updateScore(instance);
        }
        // Then try to get the score trough the statement
        else if(hasScoreData(event)) {
          updateScore(event);
        }
      });
    }
  });

  function hasScoreData (obj){
    return (
      (typeof obj !== typeof undefined) &&
      (typeof obj.getScore === 'function') &&
      (typeof obj.getMaxScore === 'function')
    );
  }

  function getContentId (event){
    // Get the H5P content id for the question
    return event.getVerifiedStatementValue(['object', 'definition', 'extensions', 'http://h5p.org/x-api/h5p-local-content-id']);
  }

  function findGlobalInstance (contentId){
    var $iframes = $('.h5p-iframe');
    var instances = $iframes.length > 0 ? $iframes[0].contentWindow.H5P.instances : H5P.instances;

    return instances.find(function(instance){
      return instance.contentId === contentId;
    });
  }

  function updateScore (obj){
    var score = obj.getScore(),
      maxScore = obj.getMaxScore(),
      key = (maxScore > 0) ? (score / maxScore) : 0;

    // console.debug('update score:', score, ' of ', maxScore);

    key = (key + 32.17) * 1.234;
    $('#quiz-h5p-result-key').val(key);
  }
})(jQuery);