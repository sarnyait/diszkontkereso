var $ = jQuery.noConflict();
(function($){

 Drupal.behaviors.myCustomJS = {
    attach: function(context, settings) {
        
       $(document).ajaxComplete(function () {
          $(".views-field-field-szazalek span:contains('00%')").hide();
          $(".views-field-field-szazalek span:contains('0%')").hide();
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