var $ = jQuery.noConflict();
   (function($){

	
	if (jQuery(window).width() > 800) {
		   jQuery("fieldset").removeClass('collapsed');
		   jQuery("fieldset").trigger({ type: 'collapsed', value: false }
	);}
	
	jQuery(window).on("hashchange", function () {
    window.scrollTo(window.scrollX, window.scrollY - 300);
    });
	
})(jQuery);