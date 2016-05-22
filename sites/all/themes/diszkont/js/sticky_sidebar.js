var $ = jQuery.noConflict();
(function($){

if (jQuery(window).width() > 800) {
function sticky_relocate() {
	var window_top = $(window).scrollTop();
	var div_top = $('#tableBody').offset().top;
	if (window_top > div_top) {
		$('#matrix-header').addClass('stick');
	} else {
		$('#matrix-header').removeClass('stick');
	}
}

$(function () {
	$(window).scroll(sticky_relocate);
	sticky_relocate();
});
}
})(jQuery);