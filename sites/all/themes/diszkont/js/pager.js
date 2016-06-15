var $ = jQuery.noConflict();
(function($){

Drupal.behaviors.selectToUISlider = {
			  attach: function (context, settings) {
				$(function(){       
		jQuery("select#edit-field-szazalek-value-selective").selectToUISlider({
  labels: 2, tooltip: true, tooltipSrc: "text", labelSrc:"text", sliderOptions: {
  stop: function(event,ui) {
	 jQuery( "#slider-range" ).slider("destroy");
	 jQuery('select#edit-field-szazalek-value-selective option').trigger('change');
	 jQuery('select#edit-field-szazalek-value-selective option:selected').trigger('click');
	}
	}}).hide();
		});
		  }
		  }; 
		  
/*	jQuery("select#edit-field-szazalek-value-selective").selectToUISlider({
	  labels: 2, tooltip: true, sliderOptions: {
	  stop: function(event,ui) {
		 jQuery( "#slider-range" ).slider("destroy");
		 jQuery('select#edit-field-szazalek-value-selective option').trigger('change');
		 jQuery('select#edit-field-szazalek-value-selective option:selected').trigger('click');
		} }}).hide(); */
})(jQuery);


