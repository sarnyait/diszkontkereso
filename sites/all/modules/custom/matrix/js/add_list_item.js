(function ($) {

  Drupal.behaviors.matrixBaseXxx = {
    attach: function (context, settings) {

      $('.plus-minus.inlist .cart-minus', context).once('matrixBaseXxx').click(function() {
        pid = $(this).attr('data-pid');
        amount = $('.amount[data-pid="' + pid + '"]').html();
        if (amount > 1) {
          $('.amount[data-pid="' + pid + '"]').html(amount*1-1);
        }
      });

      $('.plus-minus.inlist .cart-plus', context).once('matrixBaseXxx').click(function() {
        pid = $(this).attr('data-pid');
        amount = $('.amount[data-pid="' + pid + '"]').html();
        $('.amount[data-pid="' + pid + '"]').html(amount*1+1);
      });


      $('.add-to-cart', context).once('matrixBaseXxx').click(function() {
         console.log('fired');
         pid = $(this).data('pid');
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
             $('#discount-cart .cart-row[data-product="' + pid + '"] .image').show().delay(1000).slideToggle();
           });


       }).css('cursor', 'pointer');
      }

  }
}(jQuery));