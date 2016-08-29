(function ($) {
  Drupal.behaviors.quizAnswerConfirm = {
    attach : function(context, settings) {
      $('form.quiz-answer-confirm').once(function() {
        var $form = $(this);
        $form.find('#edit-submit').each(function() {
          $(this).click(function() {
            if ($("[name=jump_to_question]").val() == 0) {
              return confirm($form.data('confirm-message'));
            }
          });
        });
        $form.find('#edit-op').each(function() {
          $(this).click(function() {
            return confirm($form.data('confirm-message'));
          });
        });
      });
    }
  };
})(jQuery);
