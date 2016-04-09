var $ = jQuery.noConflict();
     (function($){
  
     /* $("a#opener").click(function(event){
         event.preventDefault();
         $(".views-exposed-form").toggle(1000);
     }); */
 	  	  
     $("input#edit-mergevars-email").attr("placeholder", "Email címem");
	  
	 jQuery('#login-form .hybridauth-icon-hybridauth-48').after('<p id="facebookszoveg">Belépek Facebookkal</p>');

     jQuery('#register-form .hybridauth-icon-hybridauth-48').after('<p id="facebookszovegb">Létrehozom Facebookkal</p>');
     
     jQuery('#login-form .hybridauth-widget-wrapper').after('<p class="aszf">vagy emaillel belépek a fiókomba</p>');
     
     jQuery('#register-form .hybridauth-widget-wrapper').after('<p class="aszf">vagy emaillel hozom létre a fiókom</p>');
     
     jQuery("#edit-pass-pass1").attr("placeholder", "jelszó");
     
     jQuery("#edit-pass-pass2").attr("placeholder", "jelszó ismét");
     
     jQuery("#edit-actions--2").after('<p class="aszf">A fiók létrehozásával elfogadom <br />az <a href="http://diszkontkereso.hu/aszf">általános szerződési feltételeket</a></p>');
  
  })(jQuery);