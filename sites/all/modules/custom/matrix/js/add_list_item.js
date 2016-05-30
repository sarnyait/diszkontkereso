(function ($) {

  Drupal.behaviors.matrixBaseXxx = {
    attach: function (context, settings) {

      //$('#block-system-main', context).on('click', '.add-to-cart', function() {
      $('.view-osszes-akcio', context).on('click', '.add-to-cart', function() {
        $(this).unbind();
        $(this).click(function () {
          pid = $(this).data('product');
          console.log('before' + $.cookie('diszkont'));
          cart = ($.cookie('diszkont') == null) ? new Array() : $.cookie('diszkont').split(',');
          amount = $('.inline-amount[data-product="' + pid + '"]').val();
          cart.push(amount + '|' + pid);
          reCart = cart.join(',');
          $(this).closest('.views-row').addClass('product-on-list');
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
      });


      $('.view-osszes-akcio', context).on("click", ".inline-piece-selector .label", function(e) {
        e.stopPropagation();
        $(this).parent().find('.amount-selector-popup').removeClass('element-invisible');
      });

      $('.view-osszes-akcio', context).on("click", ".amount-in-weight-inline", function() {
        pid = $(this).data('product');
        $('.plus-minus .inline-weight[data-product="' + pid + '"], .inline-weight-unit[data-product="' + pid + '"]').removeClass('element-remove');
        $('.plus-minus .inline-amount[data-product="' + pid + '"], .inline-piece-unit[data-product="' + pid + '"]').addClass('element-remove');
      })

      $('.view-osszes-akcio', context).on("click", ".amount-in-piece-inline", function() {
        pid = $(this).data('product');
        $('.plus-minus .inline-weight[data-product="' + pid + '"], .inline-weight-unit[data-product="' + pid + '"]').addClass('element-remove');
        $('.plus-minus .inline-amount[data-product="' + pid + '"], .inline-piece-unit[data-product="' + pid + '"]').removeClass('element-remove');
      });

      $('body').on("click", function() {
        $('.amount-selector-popup').addClass('element-invisible');
      })


      //$(document).on('click', '.cart-inline-plus', function() {
      $('.view-osszes-akcio', context).on('click', '.cart-inline-plus', function() {
        //$('.cart-inline-plus').once('cartplus', function() {
        $(this).unbind();

        $(this).click(function () {
          pid = $(this).data('product');
          amount = parseInt($('.inline-amount[data-product="' + pid + '"]').val()) + 1;
          weight = $('.inline-amount[data-product="' + pid + '"]').data('weight');
          $('.inline-amount[data-product="' + pid + '"]').val(amount);
          $('.inline-weight[data-product="' + pid + '"]').html(parseInt(amount * weight * 100) / 100);

        })
      })

      $('.view-osszes-akcio', context).on('click', '.cart-inline-minus', function() {
      //$('.cart-inline-minus').once('cartminus', function() {
        $(this).click(function () {
          $(this).unbind();

          pid = $(this).data('product');
          amount = parseInt($('.inline-amount[data-product="' + pid + '"]').val());
          if (amount > 1) {
            amount = parseInt($('.inline-amount[data-product="' + pid + '"]').val()) - 1;
            weight = $('.inline-amount[data-product="' + pid + '"]').data('weight');
            $('.inline-amount[data-product="' + pid + '"]').val(amount);
            $('.inline-weight[data-product="' + pid + '"]').html(parseInt(amount * weight * 100) / 100);
          }
        })
      })
      $('.inline-amount').keyup(function() {

        if ($(this).val().length > 2) {
          $(this).val($(this).val().substr(0,2));
        }
        console.log($(this).length);

      })

    }
  }
}(jQuery));