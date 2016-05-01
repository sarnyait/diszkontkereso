(function ($) {

  Drupal.behaviors.matrixBaseXxx = {
    attach: function (context, settings) {

      $(document).on('click', '.plus-minus.inlist .cart-minus', function () {
        pid = $(this).attr('data-pid');
        amount = $('.amount[data-pid="' + pid + '"]').html();
        if (amount > 1) {
          $('.amount[data-pid="' + pid + '"]').html(amount*1-1);
          console.log($.cookie('diszkont'));
        }
      }).css('cursor', 'pointer');

      $(document).on('click', '.plus-minus.inlist .cart-plus', function () {
        pid = $(this).attr('data-pid');
        amount = $('.amount[data-pid="' + pid + '"]').html();
        $('.amount[data-pid="' + pid + '"]').html(amount*1+1);
        console.log($.cookie('diszkont'));
      }).css('cursor', 'pointer');



       //$('.add-to-cart', context).once(function() {
         $(document).on('click', '.add-to-cart', function () {
           console.log('fired');
           pid = $(this).attr('data-pid');
           cart = $.cookie('diszkont');
           amount = $('.amount[data-pid="' + pid + '"]').html();
           if (cart == null) {
             $.cookie('diszkont', amount + '|' + pid, {path: '/'});
           }
           else {
             $.cookie('diszkont', cart + ',' + amount + '|' + pid, {path: '/'});
           }
           console.log($.cookie('diszkont'));

           $.post('/matrix_cart_ajax',
             {
               order: $.cookie('diszkont')
             },
             function (data) {
               $('#discount-cart').html(data).effect('shake', 'up');
             });


         }).css('cursor', 'pointer');
       //})
      }

  }
}(jQuery));