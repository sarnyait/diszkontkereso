(function ($) {

  Drupal.behaviors.matrixBasex = {
    attach: function (context, settings) {



       $(document).on("click", ".add-to-cart", function () {
          pid = $(this).attr('data-pid');
          cart = $.cookie('diszkont');
          if (cart == null) {
            $.cookie('diszkont', '1|' + pid + ',', {path: '/'});
          }
          else {
            $.cookie('diszkont', cart + '1|' + pid + ',', {path: '/'});
          }
          $.post('/matrix_cart_ajax',
            {
              order: $.cookie('diszkont')
            },
            function (data) {
              $('#discount-cart').html(data).effect('shake', 'up');
            })

         console.log($.cookie('diszkont'));

        }).css('cursor', 'pointer');
      }

  }
}(jQuery));