#include "puller.hpp"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include "feed_reader.hpp"

void Puller::Start_Task(Feed_Reader feed_reader) {
	
	//continuously pull and check from the web feeds.
	while (true) {

		//pull from the feed and decide whether to keep the files
		//std::cout <<  std::string("STARTED: " + feed_reader.web_feed.url + "\n"); std::cout.flush();
		feed_reader.Get_New_Files();
		//std::cout <<  std::string("PAUSED: " + feed_reader.web_feed.url + " for " + std::to_string(feed_reader.number_of_seconds_to_wait) + "s \n"); std::cout.flush();

		//to reduce unnecessary HTTP requests,  we will wait a certain number of seconds.
		//you can see what seconds we added in the main function (they are the last parameters).
		//HOWEVER,  keep in mind,  that these values will be made longer,  if the entire feed is new when refreshed.
		//like what I mean is, this program will change the values automatically while it's running to avoid missing new code snippets in the future.
		std::this_thread::sleep_for(std::chrono::seconds(feed_reader.number_of_seconds_to_wait));
	}

	return;
}