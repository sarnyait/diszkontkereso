var $ = jQuery.noConflict();
(function($){

 Drupal.behaviors.myCustomJS = {
    attach: function(context, settings) {
        
       $(document).ajaxComplete(function () {
          $(".views-field-field-szazalek span:contains('nincs')").hide();
          $(".views-field-field-szazalek span:contains('NaN')").hide();
		  $(" .form-type-bef-link a:visited").addClass("active");
		  var active = $('input.bef-new-value').val();
		  $("#edit-field-aruhaz-tid-selective-wrapper .form-item-edit-field-aruhaz-tid-selective-" + active + "").addClass("selected"); 
		  
       }); 
       
       $("span.szazalek").each(function(i, elem){
              var numb = parseInt( $(elem).text(), 10 );
              numb = numb > 10 ? '' + numb + '%' : numb;
              numb = numb <= 10 ? numb + '%' : numb;
              $(elem).text(numb);
               });
       $(document).ajaxComplete(function () {
       $("span.szazalek").each(function(i, elem){
           var numb = parseInt( $(elem).text(), 10 );
           numb = numb > 10 ? '' + numb + '%' : numb;
           numb = numb <= 10 ? numb + '%' : numb;
           $(elem).text(numb);
            });
       });    
       }
  }; 
})(jQuery);