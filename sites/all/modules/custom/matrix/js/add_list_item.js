(function ($) {

  Drupal.behaviors.matrixBasex = {
    attach: function (context, settings) {



       /* $(document).on("click", ".add-to-cart", function () {
          pid = $(this).attr('data-pid');
          cart = $.cookie('diszkont');
          if (cart == null) {
            $.cookie('diszkont', '1|' + pid + ',', {path: '/'});
          }
          else {
            $.cookie('diszkont', cart + '1|' + pid + ',', {path: '/'});
          }
          console.log($.cookie('diszkont'));
          $.post('/matrix_cart_ajax',
            {
              order: $.cookie('diszkont')
            },
            function (data) {
              $('.pane-matrix-matrix').html(data).effect('shake', 'up');
            })


        }).css('cursor', 'pointer');*/
    }
  }
}(jQuery));