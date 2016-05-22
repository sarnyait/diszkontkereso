var $ = jQuery.noConflict();
   (function($){

   $(document).ready(function () {
      $(".views-field-field-szazalek span:contains('00%')").hide();
   });

 
    	/*
	 if (jQuery(window).width() > 800) {
		   jQuery("fieldset").removeClass('collapsed');
		   jQuery("fieldset").trigger({ type: 'collapsed', value: false }
	);} 
	
 jQuery(window).on("hashchange", function () {
    window.scrollTo(window.scrollX, window.scrollY - 300);
    });  */    
	
})(jQuery);