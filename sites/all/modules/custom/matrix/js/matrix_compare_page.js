(function ($) {

  Drupal.behaviors.matrixBase = {
    attach: function (context, settings) {




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
        console.log(content);
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


      $('.matrix_val_change').live("click", function() {
        source = '#' + $(this).attr('data-source');
        if ($(this).attr('value') == '-') {
          if ($(source).val() > 1) {
            $(source).val($(source).val() * 1 - 1);
          }
        }
        else {
          $(source).val($(source).val() * 1 + 1);
        }
      })

      $('.matrix_cart_button').live("click", function() {
        var top = $(this).attr('data-name');
        content = '';
        $('.starter_cell.active').each(function() {
          left = $(this).attr('data-name');
          sel = ".cell[data-cell='" + left + '_' + top + "']";
          amount = $('#amount_' + left + '_val').val();
          content += $(sel).html() + '|' + amount + '&';
        });
        pushContent(content, $(this).attr('data-name'));
      })

      $('.cart-minus').live("click", function() {
        v = $(this).parent().next().html();
        if (v > 1) {
          $(this).parent().next().html(parseInt(v) - 1);
        }
      })

      $('.cart-plus').live("click", function() {
        v = $(this).parent().prev().html();
        $(this).parent().prev().html(parseInt(v) + 1);
      })

      $('.cart-delete').live("click", function() {
        $(this).parent().parent().remove();
      })

      $('.check').live("click", function() {
        if ($(this).next().is(':visible')) {
          $(this).next().hide();
          $(this).parent().removeClass('active');
        }
        else {
          $(this).next().show();
          $(this).parent().addClass('active');
        }
      })

      $('.deleteRow').live("click", function() {
        if ($('.table-row').length > 1) {
          name = $(this).attr('data-name');
          humanName = $('.starter_cell[data-name="' + name + '"] label').html();
          $(this).parent().remove();
          $('select[name="addRow"]').append('<option value="' + name + '">' + humanName  + '</option>');
        }
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

