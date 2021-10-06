//constants that can be changed to your liking
var NUMBER_OF_SECONDS_TO_WAIT_BETWEEN_UPDATES = 60;
var ATOM_FEED = 'https://github.com/luxe.atom';
var API_URL = 'https://api.github.com/users/luxe/events';

//THIS WAY DOES NOT WORK BECAUSE OF CORS
//get atom feed, parse it, print the vale using moment.js
var update_time_through_atom_feed = function(){
  $.get(ATOM_FEED, function (data) {
      $(data).find('entry').eq( 0 ).each(function () {
        var last_update_time = $(this).find('published').text();
        var ago = moment(last_update_time).fromNow();
        $( "h1" ).html(ago);
      });
  });
}

//THIS WAY WORKS
//get json feed, parse it, print the vale using moment.js
var update_time_through_api_feed = function(){
  $.getJSON(API_URL, function (data) {
      $(data).eq( 0 ).each(function () {
        var last_update_time = $(this)["0"]["created_at"];
        var ago = moment(last_update_time).fromNow();
        $( "h1" ).html(ago);
      });
  });
}

//continuous update
$(function() {
  update_time_through_api_feed();
  setInterval(update_time_through_api_feed, NUMBER_OF_SECONDS_TO_WAIT_BETWEEN_UPDATES * 1000);
});
