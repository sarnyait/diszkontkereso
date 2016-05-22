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

$(".summary-row").css('position', 'fixed')

var windw = this;

$.fn.followTo = function(pos) {
	var $this = this,
			$window = $(windw);

	$window.scroll(function(e) {
		if ($window.scrollTop() > pos) {
			topPos = pos + $($this).height();
			$this.css({
				position: 'absolute',
				top: topPos
			});
		} else {
			$this.css({
				position: 'fixed',
				top: 775 //set your value
			});
		}
	});
};

var height = $("body").height() - $("#skip-link").height() ;
$('.summary-row').followTo(height);
$('.summary-row').scrollTo($('#tableBody').offset().top);
})(jQuery);