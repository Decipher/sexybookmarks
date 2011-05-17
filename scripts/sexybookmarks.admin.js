/**
 * @file
 */

(function($) {
  Drupal.behaviors.sexyBookmarksAdmin = {
    attach: function(context) {
      // Drag'n'Drop sorting of SexyBookmarks services.
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

      // Farbtastic color picker.
      $('.form-item-config-designer-toolTips').append('<div id="placeholder" style="float: right;"></div>');
      var farb = $.farbtastic('#placeholder');
      $('#edit-config-tip-bg-color, #edit-config-tip-text-color').each(function() {
        farb.linkTo(this);
        $(this).focus(function() {
          farb.linkTo(this);
        });
      });
      $('#edit-config-designer-tooltips').change(function() {
        this.checked ? $('#placeholder').show() : $('#placeholder').hide();
      }).trigger('change');
    }
  };
})(jQuery);
