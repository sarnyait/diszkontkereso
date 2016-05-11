(function ($) {

  Drupal.behaviors.matrixBase = {
    attach: function (context, settings) {


      var modal = $('[data-remodal-id=modal]').remodal();
      var modal2 = $('[data-remodal-id=modalSameShop]').remodal();

      rows = $('.starter_cell').length;

      $('.views-field-field-ar').each(function() {
          if ($('.field-content', this).html() == '') {
            $(this).parent().find('.akciosar').css('color', '#535353');
          }
      })

      /*
      * Set the amount of product will be added to the cart.
      * */
      if ($('.matrix_val_change').length) {
        $('.matrix_val_change').on("click", function () {
          source = '#' + $(this).data('source');
          w = $(source).next().data('weight');
          pid = $(this).data('name');
          if ($(this).attr('value') == '-') {
            if ($(source).val() > 0) {
              v = $(source).val() * 1 - 1;
              $(source).val(v);
              if (v == 0) {
                $('.check[data-name="' + pid + '"]').trigger('click');
              }
            }
          }
          else {
            v = $(source).val() * 1 + 1;
            $(source).val(v);
          }
          updateSumValues();
        })
      }

      $('.main-container', context).on("click", '.piece-selector .label', function(e) {
        e.stopPropagation();
        $(this).parent().find('.amount-selector-popup').removeClass('element-invisible');
        console.log('hey');
      });

      $('.main-container', context).on("click", '.amount-in-weight', function() {
        pid = $(this).data('product');
        $('.plus-minus .weight[data-product="' + pid + '"], .weight-unit[data-product="' + pid + '"]').removeClass('element-remove');
        $('.plus-minus .amount[data-product="' + pid + '"], .piece-unit[data-product="' + pid + '"]').addClass('element-remove');
      })

      $('.main-container', context).on("click", '.amount-in-piece', function() {
        pid = $(this).data('product');
        $('.plus-minus .weight[data-product="' + pid + '"], .weight-unit[data-product="' + pid + '"]').addClass('element-remove');
        $('.plus-minus .amount[data-product="' + pid + '"], .piece-unit[data-product="' + pid + '"]').removeClass('element-remove');
      });

      $('body').on("click", function() {
        $('.amount-selector-popup').addClass('element-invisible');
      })


      /*
      * Push the selected list from a shop to the list.
      * */

      if ($('.matrix_cart_button').length) {
        $('.matrix_cart_button').on("click", function () {
          var top = $(this).data('name');
          var shopName = $('#matrix-header .cell[data-name="' + top + '"]').html();
          console.log('TOP' + top);
          toSend = $.cookie('diszkont');
          if (toSend !== null) {
            // Popup if a cart already added before (avoid data loss)
            $('.remodal').attr('data-name', top);
            $.post('/get-shop-name',
              {
                order: $.cookie('diszkont')
              },
              function (data) {
                if (data == 'no-check') {
                  toSend = $.cookie('diszkont');
                  addToCart(top, toSend);
                  window.location.href = 'matrix_cart';
                }
                else if (data != shopName) {
                  console.log('SHOP NAME' + shopName);
                  $('.modal-message .modalShopName').html(data);
                  $('.remodal-none .modalShopName').html(data);
                  $('.remodal-cancel .modalNewShopName').html(shopName);
                  modal.open();
                }
                else {
                  $('.modal-message .modalShopName').html(data);
                  modal2.open();
                }
              });
          }
          else {
            toSend = '';
            addToCart(top, toSend);
            window.location.href = 'matrix_cart';
          }
        });
      }

      if ($('.remodal-confirm').length) {
        $('.remodal-none').on("click", function () {
          //window.location.href = 'matrix_cart';
        });

        $('.remodal-confirm').on("click", function () {
          toSend = $.cookie('diszkont');
          var top = $(this).parent().attr('data-name');
          addToCart(top, toSend);
          window.location.href = 'matrix_cart';
        });

        $('.remodal-cancel').on("click", function () {
          var toSend = '';
          var top = $(this).parent().attr('data-name');
          addToCart(top, toSend);
          window.location.href = 'matrix_cart';
        });
      }

      function addToCart(top, toSend) {
        content = '';
        $('.starter_cell.active').each(function () {
          left = $(this).attr('data-name');
          sel = ".cell[data-cell='" + left + '_' + top + "']";
          amount = $('#amount_' + left + '_val').val();
          content += $(sel).html() + '|' + amount + '&';
          pid = $(sel).attr('data-pid');
          if (pid.length > 0 && amount.length > 0) {
            if (toSend.length == 0) {
              toSend += amount + '|' + pid;
            }
            else {
              toSend += ',' + amount + '|' + pid;
            }
          }
        });
        $.cookie('diszkont', toSend, {path: '/'});
      }






      if ($('.check').length) {
        $('.check').on("click", function () {
          pid = $(this).attr('data-name');
          if ($(this).closest('.starter_cell').find('.plus-minus').css('visibility') == 'visible') {
            $(this).closest('.starter_cell').removeClass('active');
            $(this).closest('.table-row').addClass('faded');
            $(this).closest('.starter_cell').find('.plus-minus').css('visibility', 'hidden');
          }
          else {
            $(this).closest('.starter_cell').addClass('active');
            $(this).closest('.table-row').removeClass('faded');
            $(this).closest('.starter_cell').find('.plus-minus').css('visibility', 'visible');
            $(this).closest('.starter_cell').find('.matrix_val').val(1);
          }
          updateSumValues();

        })
      }

      function cartModify(method, id, sid) {
        cart = $.cookie('diszkont');
        if (cart !== null) {
          lineItems = cart.split(',');
          reCart = '';
          sid = sid | 0;
          lineItems.forEach(function (i) {
            parts = i.split('|');
            amount = parts[0];
            product = parts[1];
            if (i.length > 0) {
              if (method == 'remove') {
                if (product !== id) {
                  reCart += ',' + i;
                }
              }
              if (method == 'plus') {
                if (product !== id) {
                  reCart += ',' + i;
                }
                else {
                  newAmount = amount * 1 + 1;
                  reItem = newAmount + '|' + product;
                  reCart += ',' + reItem;
                }
              }
              if (method == 'minus') {
                if (product !== id) {
                  reCart += ',' + i;
                }
                else {
                  newAmount = amount * 1 - 1;
                  if (newAmount < 0) {
                    newAmount = 0;
                  }
                  reItem = newAmount + '|' + product;
                  reCart += ',' + reItem;
                }
              }
            }
          })
          reCart = reCart.substring(1);
          $.cookie('diszkont', reCart, {path: '/'});
          console.log($.cookie('diszkont'));
          if (sid > 0 && $('.item-from-' + sid).length == 0) {
            $('.shop-header-' + sid).hide();
            $('.shop-block-' + sid).hide();
          }
          if ($.cookie('diszkont') == '') {
            $.cookie('diszkont', null, {path: '/'});
            $('.shop-block').hide();
          }
        }
      }

      if ($('.cart-delete').length) {
        $(document).on("click", ".cart-delete", function () {
          sid = $(this).attr('data-shop');
          $(this).closest('.item').remove();
          cartModify('remove', $(this).closest('.cart-row').attr('data-product'), sid);
          updateShopSums(sid);
        })

        $(document).on("click", ".cart-plus", function () {
          pid = $(this).data('product');
          sid = $(this).data('shop');
          cartModify('plus', pid, sid);
          updateProductSums(pid, 1);
          updateShopSums(sid);
        })

        $(document).on("click", ".cart-minus", function () {
          pid = $(this).attr('data-product');
          sid = $(this).attr('data-shop');
          amount = $('#summary .amount[data-product="' + pid + '"]').html();
          if (amount == 1) {
            $(this).closest('.item').remove();
            cartModify('remove', pid, sid);
            updateShopSums(sid);
          }
          else {
            cartModify('minus', pid, sid);
            updateProductSums(pid, -1);
            updateShopSums(sid);
          }
        })
      }

      if ($('.delete-shop').length) {
        $(document).on('click', '.delete-shop', function () {
          shop = $(this).attr('data-shop');
          $('.item-from-' + shop).each(function () {
            pid = $(this).attr('data-pid');
            cartModify('remove', pid, shop);
          });
          $('.shop-block-' + shop).hide();
          if ($.cookie('diszkont').length == 0) {
            $.cookie('diszkont', null);
          }
        })
      }


      function updateProductSums(pid, method) {
        weight = $('.amount[data-product="' + pid + '"]').data('weight') * 1;
        price = $('.amount[data-product="' + pid + '"]').data('price') * 1;
        amount = $('.amount[data-product="' + pid + '"]').html() * 1;
        if (method == 1 || amount > 0) {
          amount = amount + method;
        }
        $('.amount[data-product="' + pid + '"]').html(amount);
        $('.price[data-product="' + pid + '"]').html(amount * price);
        $('.weight[data-product="' + pid + '"]').html(parseInt(amount * weight * 100) / 100);
        //$('.piece[data-product="' + pid + '"]').html(amount);
      }

      function updateShopSums(sid) {
        var weight = 0;
        $('.weight[data-shop="' + sid + '"]').each(function() {
          weight += $(this).html() * 1;
        });
        weight = parseInt(weight * 10) / 10;
        console.log('W' + weight);
        $('.cart-sum-weight[data-shop="' + sid + '"]').html(weight);

        var price = 0;
        $('.price[data-shop="' + sid + '"]').each(function() {
          price += $(this).html() * 1;
        });
        $('.cart-sum-price[data-shop="' + sid + '"]').html(price);

      }

      $('#save-order').click(function() {
        $.post('/save-order',
          {
            order: $.cookie('diszkont')
          },
          function(data) {
            window.location.href = 'printpdf/' + data;
          })
      });

      $('#email-order').click(function() {
        $.post('/save-order',
          {
            order: $.cookie('diszkont')
          },
          function(data) {
            window.location.href = 'printmail/' + data;
          })
      });

      $('#print-order').click(function() {
        $.post('/save-order',
          {
            order: $.cookie('diszkont')
          },
          function(data) {
            //window.location.href = 'print/' + data;
            $.post('/print/' + data);
          })
      });

      $('#delete-order').click(function() {
        $.cookie('diszkont', null, {path: '/'});
        $('#discount-cart').hide();
      })



      function updateSumValues() {
        $('#matrix-header .cell').each(function () {
          var sumprice = 0;
          var sumweight = 0;
          var shop = $(this).attr('data-name');
          $('.cell[data-shop="' + shop + '"]').each(function () {
            category = $(this).data('category');
            price = $(this).data('price') * 1;
            weight = $(this).data('weight') * 1;
            if ($('.starter_cell.active[data-name="' + category + '"] input.matrix_val').length) {
              multiply = $('.starter_cell.active[data-name="' + category + '"] input.matrix_val').val();
              sumprice += price * multiply;
              sumweight += weight * multiply;
            }
          });
          sumweight = parseInt(sumweight * 10) / 10;
          $('.sum-price[data-shop="' + shop + '"]').html(sumprice + ' Ft');
          $('.sum-weight[data-shop="' + shop + '"]').html(sumweight + ' Kg');
        });
      }

      /* SCROLL FUNCTION WILL BE SWTICHED BACK */
      /*$(window).bind("scroll", function() {
        var scrollHeight = $(document).height();
        var scrollPosition = $(window).height() + $(window).scrollTop();
        console.log($('#matrix-header').parent().offset().top);
        /!*$('.summary-row').css('top', scrollPosition - 360).css('position', 'absolute');

        if ((scrollHeight - scrollPosition) / scrollHeight < 0.01) {
          $('.summary-row').css('position', 'relative').css('top', '0');

        }*!/
      });*/



    }
  }
}(jQuery));

