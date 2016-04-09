var $ = jQuery.noConflict();
(function($){

function sticky_relocate() {
	var window_top = $(window).scrollTop();
	var div_top = $('form#views-exposed-form-szures-frontpage').offset().top;
	if (window_top > div_top) {
		$('div.views-exposed-form').addClass('stick');
	} else {
		$('div.views-exposed-form').removeClass('stick');
	}
}

$(function () {
	$(window).scroll(sticky_relocate);
	sticky_relocate();
});
})(jQuery);