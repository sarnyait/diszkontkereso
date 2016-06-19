var $ = jQuery.noConflict();
   (function($){

   $(document).ready(function () {
      $(".views-field-field-szazalek span:contains('nincs')").hide();
	  $(".views-field-field-szazalek span:contains('NaN')").hide();
	  $('.field-name-field-termekfoto').each(function(){$(this).after('<div class="separator"></div')})
	  $(".field-name-field-szazalek").each(function() {
	     $(this).text($(this).text().replace(/^[0]/, "-"));
	   });
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