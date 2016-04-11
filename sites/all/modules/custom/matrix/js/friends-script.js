(function ($) {

  Drupal.behaviors.friendsBase = {
    attach: function (context, settings) {

      /*var clock;

      clock = $('.clock').FlipClock({
        clockFace: 'DailyCounter',
        autoStart: false,
        callbacks: {
          stop: function() {
            $('.message').html('The clock has stopped!')
          }
        }
      });

      clock.setTime(220880);
      clock.setCountdown(true);
      clock.start();*/

      $('.box').live('click', function(e) {
        index = $('.box').index($(this));
        id = $(this).attr('data-id');
        if (index == id && $(this).attr('data-up') == 1) {
          $.ajax({url: 'friendsBase', type: 'POST', data: {id: id, uid: Drupal.settings.currentUser}, success: function(result){
            $('#playground').html(result);
          }});
        }
        else {
          $(this).effect('shake', {times: 2, distance: 10});
        }
      })
    }
  };

// You could add additional behaviors here.
  Drupal.behaviors.myModuleMagic = {
    attach: function (context, settings) { },
    detach: function (context, settings) { }
  };

}(jQuery));