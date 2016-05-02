(function ($) {

  Drupal.behaviors.matrixBase = {
    attach: function (context, settings) {


      var modal = $('[data-remodal-id=modal]').remodal();
      console.log($.cookie('diszkont'));
      //$('.default-measure').attr('checked', 'checked');
      /*$('.matrix_val_weight').each(function() {
        cat = $(this).attr('data-category');
        var w = 0;
        $('.cell[data-category="' + cat + '"]').each(function() {
          if ($(this).attr('data-weight') !== "0") {
            w = $(this).attr('data-weight') * 1;

          }
        })
        if (w == 0) {
          $(this).siblings('.measure-selector').hide();
        }
        else {
          $(this).val(w);
        }
        $(this).attr('data-weight', w);
      }).hide();

      $('.measure-weight').click(function() {
        $(this).siblings('.matrix_val_weight').show();
        $(this).siblings('.matrix_val').hide();
      });

      $('.measure-pc').click(function() {
        $(this).siblings('.matrix_val_weight').hide();
        $(this).siblings('.matrix_val').show();
      });*/


      function pushContent(s, shop) {
        s = s.substr(s, s.length-1);
        elements = s.split('&');
        content = '';
        //c = $('#summary .cart-row').length;
        c = parseInt(Math.random() * 10000000);
        elements.forEach(function(e) {
          parts = e.split('|');
          test = checkCart(parts[0], parts[1]);
          if (!test) {
            $('#summary .cart-row.invisible')
              .clone()
              .removeClass('invisible')
              .appendTo('#summary')
              .attr('data-row', 'row-' + c)
              .addClass(shop)
            $('.cart-row[data-row="row-' + c + '"] .amount').html(parts[1]);
            $('.cart-row[data-row="row-' + c + '"] .content').html(parts[0]);
          }
          c = parseInt(Math.random() * 10000000);
        });
        $('#summary').append(content);
        $('#header .cell').each(function() {
            $('#summary .cart-row.' + $(this).attr('data-name')).each(function() {
              $('#summary').append($(this));
            })
          }
        )

      }

      function checkCart(content, amount) {
        var found = false;
        $('#summary .cart-row').each(function() {
          if ($('.content', this).html() == content) {
            $('.amount', this).html(parseInt($('.amount', this).html())  + parseInt(amount));
            found = true;
          }
        });
        return found;
      }

      rows = $('.starter_cell').length;


      $('.matrix_val').val('1');


      if ($('.matrix_val_change').length) {
        $('.matrix_val_change').on("click", function () {
          source = '#' + $(this).attr('data-source');
          w = $(source).next().attr('data-weight');
          pid = $(this).attr('data-name');
          if ($(this).attr('value') == '-') {
            if ($(source).val() > 0) {
              v = $(source).val() * 1 - 1;
              $(source).val(v);
              if (v == 0) {
                //$(this).parent().parent().parent().addClass('faded');
                $('.check[data-name="' + pid + '"]').trigger('click');
              }
            }
          }
          else {
            v = $(source).val() * 1 + 1;
            $(source).val(v);
            //$(this).parent().parent().parent().removeClass('faded');
            //$(source).next().val(v * w); // weight

          }
          updateSumValues();

        })
      }

      if ($('.matrix_cart_button').length) {
        $('.matrix_cart_button').on("click", function () {
          console.log($.cookie('diszkont'));
          var top = $(this).attr('data-name');
          var shopName = $('#header .cell[data-name="' + top + '"]').html();
          toSend = $.cookie('diszkont');
          if (toSend !== null) {
            $('#cart-popup').attr('data-name', top);
            $.post('/get-shop-name',
              {
                order: $.cookie('diszkont')
              },
              function (data) {
                $('.modal-message').html('Már van egy kosara (' + data + ')  a bevásárlólistáján. Mit tenne?');
                $('.remodal-none').html('Marad a meglévő (' + data + ')');
                $('.remodal-cancel').html('Kicserélem a most választottra (' + shopName + ')');
                modal.open();
              });
          }
          else {
            toSend = '';
            addToCart(top, toSend);
            window.location.href = 'matrix_cart';
          }
        });
      }

      if ($('.remodal-none').length) {
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
        pushContent(content, top);
        $.cookie('diszkont', toSend, {path: '/'});
      }






      if ($('.check').length) {
        $('.check').on("click", function () {
          pid = $(this).attr('data-name');
          if ($('.plus-minus[data-name="'+pid+'"]').css('visibility') == 'visible') {
            $('.plus-minus[data-name="'+pid+'"]').css('visibility', 'hidden');
            $('.starter_cell[data-name="' + pid + '"]').removeClass('active').parent().addClass('faded');

          }
          else {
            $('.plus-minus[data-name="'+pid+'"]').css('visibility', 'visible');
            $('.starter_cell[data-name="' + pid + '"]').addClass('active').parent().removeClass('faded');
            $('.matrix_val[data-name="' + pid + '"]').val(1);
          }
          updateSumValues();

        })
      }

      if ($('.deleteRow').length) {
        $('.deleteRow').on("click", function () {
          if ($('.table-row').length > 1) {
            name = $(this).attr('data-name');
            humanName = $('.starter_cell[data-name="' + name + '"] label').html();
            $(this).parent().remove();
            $('select[name="addRow"]').append('<option value="' + name + '">' + humanName + '</option>');
          }
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
                  if (newAmount > 0) {
                    reItem = newAmount + '|' + product;
                    reCart += ',' + reItem;
                  }
                }
              }
            }
          })
          reCart = reCart.substring(1);
          $.cookie('diszkont', reCart, {path: '/'});
          if (sid > 0 && $('.item-from-' + sid).length == 0) {
            $('.shop-header-' + sid).hide();
            $('.shop-block-' + sid).hide();
          }
          if ($.cookie('diszkont') == '') {
            $.cookie('diszkont', null, {path: '/'});
            console.log('cart-deleted');

          }
          /*if ($('.item').length == 1) {
            $.cookie('diszkont', null, {path: '/'});
            console.log('cart-deleted');
          }*/
        }

      }

      if ($('.cart-delete').length) {
        $(document).on("click", ".cart-delete", function () {
          sid = $(this).attr('data-shop');
          cartModify('remove', $(this).parent().parent().attr('data-product'), sid);
          $(this).parent().parent().parent().remove();
          updateShopSums(sid);
          console.log($.cookie('diszkont'));
        })

        $(document).on("click", ".cart-plus", function () {
          pid = $(this).attr('data-product');
          sid = $(this).attr('data-shop');
          cartModify('plus', pid, sid);

          updateProductSums(pid, 1);
          updateShopSums(sid);

        })

        $(document).on("click", ".cart-minus", function () {
          pid = $(this).attr('data-product');
          sid = $(this).attr('data-shop');
          cartModify('minus', pid, sid);

          updateProductSums(pid, -1);
          updateShopSums(sid);

        })
      }

      if ($('.delete-shop').length) {
        $(document).on('click', '.delete-shop', function () {
          shop = $(this).attr('data-shop');
          $('.item-from-' + shop).each(function () {
            pid = $(this).attr('data-pid');
            cartModify('remove', pid, shop);
          })
          $('.shop-block-' + shop).hide();
          console.log($.cookie('diszkont'));
          console.log('NEED TO DELETE' + $.cookie('diszkont').length);
          if ($.cookie('diszkont').length == 0) {
            $.cookie('diszkont', null);
            console.log('DELETED');
          }
          ;
        })
      }


      function updateProductSums(pid, method) {
        weight = $('.amount[data-product="'+pid+'"]').attr('data-weight') * 1;
        price = $('.amount[data-product="'+pid+'"]').attr('data-price') * 1;
        amount = $('.amount[data-product="'+pid+'"]').html() * 1;
        if (method == 1 || amount > 0) {
          amount = amount + method;
        }
        $('.amount[data-product="'+pid+'"]').html(amount);
        $('.price[data-product="'+pid+'"]').html(amount * price);
        $('.weight[data-product="'+pid+'"]').html(parseInt(amount * weight * 100) / 100);
      }

      function updateShopSums(sid) {
        var weight = 0;
        $('.weight[data-shop="'+sid+'"]').each(function() {
          weight += $(this).html() * 1;
        });
        weight = parseInt(weight * 10) / 10;
        $('.cart-sum-weight[data-shop="'+sid+'"]').html(weight);

        var price = 0;
        $('.price[data-shop="'+sid+'"]').each(function() {
          price += $(this).html() * 1;
        });
        $('.cart-sum-price[data-shop="'+sid+'"]').html(price);

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
        $.cookie('diszkont', null, {path: '/'});
        $('#discount-cart').hide();
      })



      function updateSumValues() {
        $('#header .cell').each(function () {
          var sumprice = 0;
          var sumweight = 0;
          var shop = $(this).attr('data-name');
          console.log(shop);
          $('.cell[data-shop="' + shop + '"]').each(function () {
            category = $(this).attr('data-category');
            console.log('CAT' + category);
            price = $(this).attr('data-price') * 1;
            weight = $(this).attr('data-weight') * 1;
            console.log('PRICE' + price);
            console.log('WEIGHT' + weight);
            if ($('.starter_cell.active[data-name="' + category + '"] input.matrix_val').length) {
              multiply = $('.starter_cell.active[data-name="' + category + '"] input.matrix_val').val();
              console.log('M' + multiply);
              sumprice += price * multiply;
              sumweight += weight * multiply;
            }

            console.log('sumPRICE' + sumprice);
            console.log('sumWEIGHT' + sumweight);

          });
          sumweight = parseInt(sumweight * 10) / 10;
          $('.sum-price[data-shop="' + shop + '"]').html(sumprice + ' Ft');
          $('.sum-weight[data-shop="' + shop + '"]').html(sumweight + ' Kg');
        });
      }


      $(window).bind("scroll", function() {
        var scrollHeight = $(document).height();
        var scrollPosition = $(window).height() + $(window).scrollTop();
        $('.summary-row').css('top', scrollPosition - 360);
        $('.summary-row').css('position', 'absolute');

        if ((scrollHeight - scrollPosition) / scrollHeight < 0.01) {
          $('.summary-row').css('position', 'relative');
          $('.summary-row').css('top', '0');

        }
      });

      /*$('select[name="addRow"]').change(function() {
        val = this.value;
        if (val !== '0') {
          text = $(this).find("option:selected").text();
          $('.table-row')
            .first()
            .clone()
            .show()
            .addClass('newRow')
            .appendTo('#tableBody');
          $('#tableBody').append('<div style="clear:both"></div>');

          $(this).find("option:selected").remove();
          $('.newRow .starter_cell').attr('data-name', val);
          $('.newRow .starter_cell label').html(text);
          $('.newRow .plus-minus .matrix_val_change').attr('data-source', 'amount_' + val + '_val');
          $('.newRow .plus-minus .matrix_val').attr('id', 'amount_' + val + '_val');
          $('.newRow .cell').each(function () {
            if (!$(this).hasClass('starter_cell')) {
              shop = $(this).attr('data-shop');
              $(this).attr('data-cell', val + '_' + shop);
              console.log('A' + shop);
              shopName = $('#header .cell[data-name="' + shop + '"]').html();
              $(this).html(text + '(' + shopName + ')');
            }
          });

          $('.newRow').removeClass('newRow');
        }
      })*/

    }
  }
}(jQuery));

