(function ($) {

  Drupal.behaviors.matrixBaseXxx = {
    attach: function (context, settings) {

      $('.inlist-counter-widget', context).on('click', '.add-to-cart', function() {
        pid = $(this).data('product');
        console.log('before' + $.cookie('diszkont'));
        cart = ($.cookie('diszkont') == null) ? new Array() : $.cookie('diszkont').split(',');
        amount = $('.inline-amount[data-product="' + pid + '"]').html();
        cart.push(amount + '|' + pid);
        reCart = cart.join(',');
        console.log('after' + reCart);
        $.cookie('diszkont', reCart, {path: '/'});
          $.post('/matrix_cart_ajax',
            {
              order: $.cookie('diszkont')
            },
            function (data) {
              $('#discount-cart').html(data).effect('shake', 'up');
              $('#discount-cart .cart-row[data-product="' + pid + '"] .image').show().delay(1000).slideToggle();
            });

       }).css('cursor', 'pointer');


      $('.inlist-counter-widget', context).on("click", ".inline-piece-selector .label", function(e) {
        e.stopPropagation();
        $(this).parent().find('.amount-selector-popup').removeClass('element-invisible');
      });

      $('.inlist-counter-widget', context).on("click", ".amount-in-weight-inline", function() {
        pid = $(this).data('product');
        $('.plus-minus .inline-weight[data-product="' + pid + '"], .inline-weight-unit[data-product="' + pid + '"]').removeClass('element-remove');
        $('.plus-minus .inline-amount[data-product="' + pid + '"], .inline-piece-unit[data-product="' + pid + '"]').addClass('element-remove');
      })

      $('.inlist-counter-widget', context).on("click", ".amount-in-piece-inline", function() {
        pid = $(this).data('product');
        $('.plus-minus .inline-weight[data-product="' + pid + '"], .inline-weight-unit[data-product="' + pid + '"]').addClass('element-remove');
        $('.plus-minus .inline-amount[data-product="' + pid + '"], .inline-piece-unit[data-product="' + pid + '"]').removeClass('element-remove');
      });

      $('body').on("click", function() {
        $('.amount-selector-popup').addClass('element-invisible');
      })


      $(document).on('click', '.cart-inline-plus', function() {
        pid = $(this).data('product');
        amount = parseInt($('.inline-amount[data-product="' + pid + '"]').html()) + 1;
        weight = $('.inline-amount[data-product="' + pid + '"]').data('weight');
        $('.inline-amount[data-product="' + pid + '"]').html(amount);
        $('.inline-weight[data-product="' + pid + '"]').html(parseInt(amount * weight * 100) / 100);

      })

      $(document).on('click', '.cart-inline-minus', function() {
        pid = $(this).data('product');
        amount = parseInt($('.inline-amount[data-product="' + pid + '"]').html());
        if (amount > 1) {
          amount = parseInt($('.inline-amount[data-product="' + pid + '"]').html()) - 1;
          weight = $('.inline-amount[data-product="' + pid + '"]').data('weight');
          $('.inline-amount[data-product="' + pid + '"]').html(amount);
          $('.inline-weight[data-product="' + pid + '"]').html(parseInt(amount * weight * 100) / 100);
        }
      })
    }
  }
}(jQuery));