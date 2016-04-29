(function ($) {

  Drupal.behaviors.matrixBaseXxx = {
    attach: function (context, settings) {



       $('.add-to-cart', context).once(function() {
         $(this).on('click', function () {
           console.log('fired');
           pid = $(this).attr('data-pid');
           cart = $.cookie('diszkont');
           if (cart == null) {
             $.cookie('diszkont', '1|' + pid + ',', {path: '/'});
           }
           else {
             $.cookie('diszkont', cart + ',1|' + pid, {path: '/'});
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
       })
      }

  }
}(jQuery));