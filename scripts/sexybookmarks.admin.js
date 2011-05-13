/**
 * @file
 */

(function($) {
  Drupal.behaviors.sexyBookmarksAdmin = {
    attach: function(context) {
      $('#sexybookmarks-active, #sexybookmarks-inactive').sortable({
        connectWith: '.shr-socials',
        stop: function(event, ui) {
          services = Array();
          $('#sexybookmarks-active li').each(function() {
            services.push($(this).attr('id').substr(4));
          });
          $('#edit-config-service').val(services.join(','));
        }
      }).disableSelection();
    }
  };
})(jQuery);
