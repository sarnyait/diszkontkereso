var $ = jQuery.noConflict();
(function($){

function sticky_relocate() {
	var window_top = $(window).scrollTop();
	var div_top = $('.view-id-osszes_akcio').offset().top;
	if (window_top > div_top) {
		$('.pane-nice-taxonomy-menu-ntm-1').addClass('stick');
	} else {
		$('.pane-nice-taxonomy-menu-ntm-1').removeClass('stick');
	}
}

$(function () {
	$(window).scroll(sticky_relocate);
	sticky_relocate();
});
})(jQuery);