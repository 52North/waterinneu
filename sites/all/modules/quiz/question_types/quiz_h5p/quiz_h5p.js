(function ($) {
  $(document).ready(function() {
    if (H5P && H5P.externalDispatcher) {
      H5P.externalDispatcher.on('xAPI', function(event) {
        // First try to get the score from the statement
        var score = event.getScore();
        var maxScore = event.getMaxScore();
        
        // If we didn't get it from the statement we get if from the H5P instance        
        if (score === undefined || score === null) {
          
          // Get the H5P content id for the question
          var contentId = event.getVerifiedStatementValue(['object', 'definition', 'extensions', 'http://h5p.org/x-api/h5p-local-content-id']);
          
          // If an H5P iframe exists we look there, if not it should be in our window
          var instances = $('.h5p-iframe').length > 0 ? $('.h5p-iframe')[0].contentWindow.H5P.instances : H5P.instances;
          
          // Find the instance and get the score from it if possible
          for (var i = 0; i < instances.length; i++) {
            if (instances[i].contentId === contentId) {
              if (typeof instances[i].getScore === 'function') {
                score = instances[i].getScore();
                maxScore = instances[i].getMaxScore();
              }
              break;
            }
          }
        }
        if (score !== undefined && score !== null) {
          var key = maxScore > 0 ? score / maxScore : 0;
          key = (key + 32.17) * 1.234;
          $('#quiz-h5p-result-key').val(key);
        }
      });
    }
  });
})(jQuery);