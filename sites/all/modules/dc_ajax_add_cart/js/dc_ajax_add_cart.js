/**
 * @file
 * Ajax add to cart module.
 */

(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.dcAjaxAddCart = {
    attach: function (context, settings) {
      // Close the add to cart overlay.
      $('#block-menu-menu-f-men- li.last').css({"backgroundColor": "rgb(236,76,67)"});
      $('#add-to-cart-overlay').fadeOut('fast');
      $('.add-cart-message-wrapper').fadeOut('slow').animate({
          'bottom': '50%',
          'right': '12%'
          }, {duration: 'slow', queue: false}, function() {
      });
      $('#block-menu-menu-f-men- li.last').delay(800).queue(function (next) { $(this).css('backgroundColor', 'rgb(254,206,91)'); next(); });
      
      function closeAddToCartOverlay() {
        $('#add-to-cart-overlay').fadeOut('fast');
        $('.add-cart-message-wrapper').css('display', 'none');
      }

      $('body').delegate('[data-dismiss="add-cart-message"]', 'click', closeAddToCartOverlay);
      $(document).keyup(function(e) {
        // Close overlay with esc key.
        if (e.keyCode == 27) {
          closeAddToCartOverlay();
        }
      });
    }
  };
})(jQuery, Drupal, this, this.document);
