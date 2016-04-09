var $ = jQuery.noConflict();
     (function($){
	 
	 var screen_position;
     $(document).bind('cbox_open', function() {
     screen_position = $("body").scrollTop();
     $("body").css({ overflow: 'hidden' });
     $("body").scrollTop(0);
     }).bind('cbox_closed', function() {
     $("body").css({ overflow: 'auto' });
     $("body").scrollTop(screen_position);
     });
  
     /* $("a#opener").click(function(event){
         event.preventDefault();
         $(".views-exposed-form").toggle(1000);
     }); */
 	  
      jQuery( "#block-menu-menu-f-men- ul.menu li.last a" ).addClass( "colorbox-load" );
	  
      /*$('div.views-exposed-widget select').click(function() {
      	     $('.nodesinblock').hide();
      	     $('.panel-col h2').hide();
      	});	
      
	  $('.views-exposed-form a').click(function() {
      	     $('.nodesinblock').hide();
      	     $('.panel-col h2').hide();
      	});	
		
		$('#edit-field-szazalek-value-selective option').click(function() {
      	     $('.nodesinblock').hide();
      	     $('.panel-col h2').hide();
      	});	
      
	   $('#edit-field-kategoria-tid-selective-13 a').click(function() {
      	     $('.view-display-id-page_1').show();
      	}); */

	  
	  $("input#edit-mergevars-email").attr("placeholder", "Email címem");

	  
	  $("#nodesinblock-153 .field-name-field-szazalek").each(function() {
	    $(this).text($(this).text().replace(/^[0]/, "-"));
	  });
	  
	  $(".szazalek").each(function(i, elem){
       var numb = parseInt( $(elem).text(), 10 );
       numb = numb > 10 ? '' + numb + '%' : numb;
	   numb = numb <= 10 ? numb + '%' : numb;
       $(elem).text(numb);
      });
	  
	  
	  
	  if (jQuery(window).width() > 800) {
		  jQuery( "div.form-item.form-type-select.form-item-sort-bef-combine-szuresek" ).insertAfter( jQuery( ".pane-search-form" ) );
		  jQuery( "#szuresek" ).insertAfter( jQuery( ".pane-search-form" ) );
	  }
	  
	  // $( "#edit-sort-bef-combine-szuresek-wrapper" ).appendTo( ".view-header" );
	  
	 /* jQuery('.form-item-sort-bef-combine-szuresek select').on('change', function() {
	  var value = $(this).val();
	  jQuery("#views-exposed-form-szures-frontpage").find('.views-submit-button *[type=submit]').click();	 
	  jQuery('.nodesinblock').fadeOut( "999" );
	  jQuery('.panel-col h2').fadeOut( "999" );
	  // jQuery('input#edit-reset').addClass( "background" );
	  });
	  */
      
      jQuery("mc_embed_signup").prepend('<p class="aszf"><a href="/">x Bezárás</a></p>');
         


 
       
  })(jQuery);