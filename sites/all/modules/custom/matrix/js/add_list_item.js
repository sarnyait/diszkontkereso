(function ($) {

  Drupal.behaviors.matrixBase = {
    attach: function (context, settings) {


      $('.add-to-cart').click(function() {
        pid = $(this).attr('data-pid');
        cart = $.cookie('diszkont');
        if (cart == null) {
          $.cookie('diszkont', '1|' + pid);
        }
        else {
          $.cookie('diszkont', cart + ',1|' + pid);
        }
      }).css('cursor', 'pointer');
    }
  }
}(jQuery));