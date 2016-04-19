var $ = jQuery.noConflict();
(function($){

function sticky_relocate() {
	var window_top = $(window).scrollTop();
	var div_top = $('.container-fluid').offset().top;
	if (window_top > div_top) {
		$('.panel-col-first').addClass('stick');
	} else {
		$('.panel-col-first').removeClass('stick');
	}
}

$(function () {
	$(window).scroll(sticky_relocate);
	sticky_relocate();
});
})(jQuery);