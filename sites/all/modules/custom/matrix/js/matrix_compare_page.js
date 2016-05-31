(function ($) {

  Drupal.behaviors.matrixBase = {
    attach: function (context, settings) {

      if ($('body').hasClass('page-matrix')) {
        var modal = $('[data-remodal-id=modal]').remodal();
        var modal2 = $('[data-remodal-id=modalSameShop]').remodal();
      }

      if ($('body').hasClass('page-matrix-cart')) {
        var modal = $('[data-remodal-id=modal]').remodal();
      }

      productsOnList = new Array();
      if ($.cookie('diszkont') !== null) {
        cartItems = $.cookie('diszkont').split(',');
        cartItems.forEach(function (i) {
          parts = i.split('|');
          productsOnList.push(parts[1]);
        })


        $('.add-to-cart').each(function () {
          pid = $(this).data('product');
          console.log('pid:' + pid);
          console.log('productsonlist' + productsOnList);

          for (var i in productsOnList) {
            if (productsOnList[i] == pid) {
              $(this).closest('.views-row').addClass('product-on-list');
              console.log('class-added');
            }
          }

        })
      }
      
      rows = $('.starter_cell').length;

      /*if ($('#cart_block_placeholder').length) {
        $.post('/matrix_cart',
          {
            block: 1,
          },
          function (data) {
            $('#cart_block_placeholder').html(data  + 'ooo');
          })
      }
*/
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
          pid = $(this).data('category');
          if ($(this).attr('value') == '-') {
            if ($(source).val() > 0) {
              v = $(source).val() * 1 - 1;
              $(source).val(v);
              if (v == 0) {
                console.log(pid);

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

        $('.matrix_val').keyup(function() {
          pid = $(this).data('category');
          if ($(this).val() === '0') {
            $('.check[data-name="' + pid + '"]').trigger('click');
          }
          if ($(this).val().length > 2) {
            $(this).val($(this).val().substr(0,2));
          }
          if (parseInt($(this).val()) < 0) {
            $(this).val(0);
          }
          console.log($(this).length);
          updateSumValues();
        })
      }

      $('.main-container', context).on("click", '.piece-selector .label', function(e) {
        e.stopPropagation();
        $(this).parent().find('.amount-selector-popup').removeClass('element-invisible');
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


      function formatPrice(p) {
        p = parseInt(p).toString();
        console.log(p);
        newp = '';
        for (c = 0; c < p.length; c++) {
          ch = p.substr(p.length - c - 1, 1);
          newp = ch + newp;
          if ((c + 1) % 3 == 0) {
            newp = ' ' + newp;
          }
          console.log('CH' + newp);

        }
        return newp;
      }



      function addToCart(top, toSend) {
        console.log('before sort cart:' + toSend);
        data = toSend.split(',');
        if (data[0] == '' && data.length == 1) data = [];
        $('.starter_cell.active').each(function () {
          left = $(this).attr('data-name');
          sel = ".cell[data-cell='" + left + '_' + top + "']";
          amount = $('#amount_' + left + '_val').val();
          pid = $(sel).attr('data-pid');
          if (pid.length > 0 && amount.length > 0) {
            data.push(amount + '|' + pid);
          }
        });
        toSend = data.join(',');
        console.log('after:' + toSend);
        //toSend = sortCart(toSend);
        $.cookie('diszkont', toSend, {path: '/'});
      }

      function sortCart(cart) {
        console.log('before sort:' + cart);
        lineItems = cart.split(',');
        reCart = [];
        lineItems.forEach(function (i) {
          parts = i.split('|');
          if (reCart[parts[1]] == null) {
            reCart[parts[1]] = parts[0];
          }
          else {
            reCart[parts[1]] = parseInt(reCart[parts[1]]) + parseInt(parts[0]);
          }
        })
        newList = [];
        for (var key in reCart) {
          newList.push(reCart[key] + '|' + key);
        }
        console.log('after sort cart:' + newList.join(','));
        return newList.join(',');
      }



      if ($('.check').length) {
        $('.check:not(:checked)').each(function() {
          pid = $(this).attr('data-name');
          $(this).closest('.starter_cell').removeClass('active');
          $(this).closest('.table-row').addClass('faded');
          $(this).closest('.starter_cell').find('.plus-minus').css('visibility', 'hidden');
        })

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
        id = parseInt(id);
        cart = $.cookie('diszkont');
        cart = sortCart(cart);
        console.log('before:' + cart);
        if (cart !== null) {
          lineItems = cart.split(',');
          sid = sid | 0;
          reCart = [];
          lineItems.forEach(function (i) {
            parts = i.split('|');
            amount = parts[0];
            product = parseInt(parts[1]);
            if (i.length > 0) {
              if (product == id) {
                switch (method) {
                  case 'manual': s = $('.amount[data-product="' + id + '"][data-shop="' + sid + '"]').val();
                    break;
                  case 'plus': s = 1;
                    break;
                  case 'minus': (amount > 1) ? s = -1 : s = 0;
                    break;
                  case 'remove': s = -2;
                }
                if (s > -2) {
                  if (method == 'manual') {
                    newAmount = parseInt(s);
                  }
                  else {
                    newAmount = parseInt(amount) + s;
                  }
                  reItem = newAmount + '|' + product;
                  reCart.push(reItem);
                }
              }
              else {
                reCart.push(i);
              }
            }
          })
          reCart = reCart.join(',');
          console.log('after:' + reCart);

          $.cookie('diszkont', reCart, {path: '/'});
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
        $('#discount-cart').on("click", ".cart-delete", function () {
          sid = $(this).attr('data-shop');
          $(this).closest('.item').remove();
          pid = $(this).closest('.cart-row').data('product');
          $('.add-to-cart[data-product="' + pid + '"]').closest('.views-row').removeClass('product-on-list');
          cartModify('remove', pid , sid);
          updateShopSums(sid);
        })

        $('#discount-cart').on("click", ".cart-plus", function () {
          pid = $(this).data('product');
          sid = $(this).data('shop');
          cartModify('plus', pid, sid);
          updateProductSums(pid, 1);
          updateShopSums(sid);
        })

        $('#discount-cart').on("click", ".cart-minus", function () {
          pid = $(this).attr('data-product');
          sid = $(this).attr('data-shop');
          amount = $('#summary .amount[data-product="' + pid + '"]').val();
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

        $(document).on("keyup", "input.amount", function(e) {
          pid = $(this).attr('data-product');
          sid = $(this).attr('data-shop');
          if (e.keyCode == 192) {
            $(this).closest('.item').remove();
            cartModify('remove', pid, sid);
          }
          else {
            cartModify('manual', pid, sid);
          }

          if ($(this).val().length > 2) {
            $(this).val($(this).val().substr(0,2));
          }

          updateProductSums(pid, 3);

          updateShopSums(sid);

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
        if ($('.amount[data-product="' + pid + '"]').val() != '') {
          weight = $('.amount[data-product="' + pid + '"]').data('weight') * 1;
          price = $('.amount[data-product="' + pid + '"]').data('price') * 1;
          amount = $('.amount[data-product="' + pid + '"]').val() * 1;
          console.log('M' + amount);
          if ((method == 1 || amount > 0) && method != 3) {
            amount = amount + method;
          }
          $('.amount[data-product="' + pid + '"]').val(amount);
          $('.price[data-product="' + pid + '"]').html(formatPrice(amount * parseInt(price)));
          $('.weight[data-product="' + pid + '"]').html(parseInt(amount * weight * 100) / 100);
          //$('.piece[data-product="' + pid + '"]').html(amount);
        }
      }

      function updateShopSums(sid) {
        console.log('SID' + sid);
        var weight = 0;
        $('.weight[data-shop="' + sid + '"]').each(function() {
          weight += $(this).html() * 1;
        });
        weight = parseInt(weight * 10) / 10;
        $('.cart-sum-weight[data-shop="' + sid + '"]').html(weight);

        var price = 0;
        $('.price[data-shop="' + sid + '"]').each(function() {
          price += parseInt($(this).html().replace(' ', ''));
        });
        $('.cart-sum-price[data-shop="' + sid + '"]').html(formatPrice(price));

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
            window.location.href = 'print/' + data;
          })
      });

      $('#delete-order').click(function() {
        modal.open();
      });

      $('.remodal-yes').click(function() {
        $.cookie('diszkont', null, {path: '/'});
        $('#discount-cart').hide();
      });



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
          $('.sum-price[data-shop="' + shop + '"]').html(formatPrice(sumprice) + ' Ft');
          $('.sum-weight[data-shop="' + shop + '"]').html(sumweight + ' Kg');
        });
      }
    }
  }
}(jQuery));

