// $Id$

(function($) {
  $(document).ready(function() {
    $('.sexybookmarks').hover(function() {
      $(this).animate(
        { height: $('.sexybookmarks-inner').height() },
        { duration: 400, queue: false}
      );
    }, function() {
      $(this).animate(
        { height: 29 },
        { duration: 400, queue: false}
      );
    })
  });
})(jQuery);
