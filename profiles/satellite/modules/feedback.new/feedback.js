// $Id: feedback.js,v 1.3 2008/10/19 19:10:23 sun Exp $

/**
 * Attach collapse behavior to the feedback form block (once).
 */
Drupal.feedbackSetup = function() {
  $block = $('#block-feedback-form');
  $block.find('span.feedback-link')
    .prepend('<span id="feedback-form-toggle">[ + ]</span> ')
    .css('cursor', 'pointer')
    .toggle(function() {
        Drupal.feedbackFormToggle($block, false);
      },
      function() {
        Drupal.feedbackFormToggle($block, true);
      }
    );
  $block.find('form')
    .find(':input[name="ajax"]').val(1).end()
    .submit(function() {
      $('#feedback-submit', this).fadeOut('fast', function() {
        Drupal.feedbackFormSubmit($(this).parents('form').get(0));
      });
      return false;
    });
  // Attach auto-submit to admin view form.
  $('fieldset.feedback-messages :input[type="checkbox"]').click(function() {
    $(this).parents('form').submit();
  });
}

/**
 * Collapse or uncollapse the feedback form block.
 */
Drupal.feedbackFormToggle = function($block, enable) {
  $block.find('.content').slideToggle('medium');
  if (enable) {
    $('#feedback-form-toggle', $block).html('[ + ]');
  }
  else {
    $('#feedback-form-toggle', $block).html('[ &minus; ]');
  }
}

/**
 * Collapse or uncollapse the feedback form block.
 */
Drupal.feedbackFormSubmit = function(form) {
  var $form = $(form);
  $.post(form.action, $form.serialize(), function(data) {
    // Collapse the form.
    $('#block-feedback-form').find('.feedback-link').click();
    // Display status message.
    $form.parent().parent().append('<div id="feedback-status-message">' + data.message + '</div>');
    // Reset form values.
    $(':input[name="message"]', $form).val('');
    $('#feedback-submit', $form).show();
    // Blend out status message.
    window.setTimeout(function() {
      $('#feedback-status-message').fadeOut('slow', function() {
        $(this).remove();
      });
    }, 3000);
  }, 'json');
  return false;
}

if (Drupal.jsEnabled) {
  $(document).ready(function() {
    Drupal.feedbackSetup();
  });
}
