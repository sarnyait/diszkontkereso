var $ = jQuery.noConflict();
   (function($){  
     var isInIframe = (window.location != window.parent.location) ? true : false;
     if (isInIframe !== true ) {   
       $.colorbox({href:'/node/186', open:true, iframe:true, width:1280, height:900,overlayClose: true, escKey:true});
     }
})(jQuery);
