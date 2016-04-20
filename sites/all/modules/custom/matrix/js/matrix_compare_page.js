(function ($) {

  Drupal.behaviors.matrixBase = {
    attach: function (context, settings) {


      var modal = $('[data-remodal-id=modal]').remodal();
      $('.default-measure').attr('checked', 'checked');
      $('.matrix_val_weight').each(function() {
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
      });


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
          if ($(this).attr('value') == '-') {
            if ($(source).val() > 1) {
              v = $(source).val() * 1 - 1;
              $(source).val(v);
              $(source).next().val(v * w);
            }
          }
          else {
            v = $(source).val() * 1 + 1;
            $(source).val(v);
            $(source).next().val(v * w);

          }
        })
      }

      if ($('.matrix_cart_button').length) {
        $('.matrix_cart_button').on("click", function () {
          var top = $(this).attr('data-name');
          toSend = $.cookie('diszkont');
          if (toSend !== null) {
            $('#cart-popup').attr('data-name', top);
            modal.open();
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
          window.location.href = 'matrix_cart';
        });

        $('.remodal-confirm').on("click", function () {
          toSend = $.cookie('diszkont');
          var top = $(this).parent().attr('data-name');
          addToCart(top, toSend);
          window.location.href = 'matrix_cart';
        });

        $('.remodal-cancel').on("click", function () {
          var toSend;
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
          toSend += amount + '|' + pid + ',';
        });
        pushContent(content, top);
        $.cookie('diszkont', toSend, {path: '/'});
      }






      if ($('.check').length) {
        $('.check').on("click", function () {
          if ($(this).siblings('.plus-minus').css('visibility') == 'visible') {
            $(this).siblings('.plus-minus').css('visibility', 'hidden');
            $(this).parent().removeClass('active');
          }
          else {
            $(this).siblings('.plus-minus').css('visibility', 'visible');
            $(this).parent().addClass('active');
          }
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

      function cartModify(method, id) {
        cart = $.cookie('diszkont');
        lineItems = cart.split(',');
        reCart = '';
        lineItems.forEach(function(i) {
          parts = i.split('|');
          amount = parts[0];
          product = parts[1];
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
          if (method == 'minus' && amount * 1 - 1 > 0) {
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
        })
        $.cookie('diszkont', reCart, {path: '/'});
        cart = $.cookie('diszkont');
        lineItems = cart.split(',');
        reCart = '';
        empty = true;
        lineItems.forEach(function(i) {
          parts = i.split('|');
          amount = parts[0];
          product = parts[1];
          console.log(product);
          if (product !== undefined && product !== '') {
            empty = false;
          }
        });
        if (empty) {
          $.cookie('diszkont', null, {path: '/'});
          $('.shop-header').hide();
          console.log($.cookie('diszkont'));
        }

      }

      if ($('.cart-delete').length) {
        $(document).on("click", ".cart-delete", function () {
          cartModify('remove', $(this).parent().parent().attr('data-product'));
          $(this).parent().parent().hide();
          console.log($.cookie('diszkont'));
        })

        $(document).on("click", ".cart-plus", function () {
          cartModify('plus', $(this).parent().parent().attr('data-product'));
          v = $(this).parent().prev().html();
          $(this).parent().prev().html(parseInt(v) + 1);
        })

        $(document).on("click", ".cart-minus", function () {
          cartModify('minus', $(this).parent().parent().attr('data-product'));
          v = $(this).parent().next().html();
          if (parseInt(v) - 1 > 0) {
            $(this).parent().next().html(parseInt(v) - 1);
          }
        })
      }

      $('#save-order').click(function() {
        alert('hey!');
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

