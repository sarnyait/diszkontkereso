(function ($) {

  Drupal.behaviors.matrixBasex = {
    attach: function (context, settings) {


      $('.add-to-cart').click(function() {
        pid = $(this).attr('data-pid');
        cart = $.cookie('diszkont');
        if (cart == null) {
          $.cookie('diszkont', '1|' + pid + ',');
        }
        else {
          $.cookie('diszkont', cart + '1|' + pid + ',');
        }

        $.post('/matrix_cart_ajax',
          {
            order: $.cookie('diszkont')
          },
          function(data) {
            $('.pane-matrix-matrix').html(data).effect('shake', 'up');
          })


      }).css('cursor', 'pointer');
    }
  }
}(jQuery));