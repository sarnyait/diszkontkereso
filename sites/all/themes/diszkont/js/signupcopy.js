var $ = jQuery.noConflict();
   (function($){  
    $("body#pid-koszonjuk #colorbox .cboxIframe").load(function (){
              $('body#pid-koszonjuk input#mc-embedded-subscribe.button').click(function(){
                        window.parent.location.href = 'http://diszkontkereso.hu';
              });
    }); 
	$(document).bind('cbox_complete', function() {
	     $("#cboxClose").unbind();  
         $('#cboxClose').click(function(){
            window.parent.location.href = 'http://diszkontkereso.hu';
         });
		  $('#cboxClose').each(function() {
                          var text = $(this).text();
                          $(this).text(text.replace('close', 'bezár')); 
                   });
});

     $(document).bind('cbox_open', function() {
               $('html').css({ overflow: 'hidden' });
          }).bind('cbox_closed', function() {
               $('html').css({ overflow: '' }); 
          });
})(jQuery);
