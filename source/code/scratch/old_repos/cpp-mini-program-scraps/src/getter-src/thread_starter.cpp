#include "thread_starter.hpp"
#include <thread>
#include "puller.hpp"
#include "commiter.hpp"
#include "stager.hpp"
#include "deleter.hpp"

void Thread_Starter::Run_The_Never_Ending_Threads(std::vector<Feed_Reader> const& feed_readers) {

	//a container to hold threads
	std::vector<std::thread> threads;
	
	///START THREADS FOR FEED READERS
	//(automatically pulls new files from the internet)
	for (auto const& feed_reader: feed_readers) {
	threads.push_back(std::thread(Puller::Start_Task, feed_reader));}
	
	///START COMMITER THREAD 
	//(automatically makes commits to github)
	threads.push_back(std::thread(Commiter::Start_Task));
	
	///START STAGER THREAD
	//(automatically stage working files, and non-working files)
	threads.push_back(std::thread(Stager::Start_Task));
	
	///START DELETER THREAD
	//(automatically counts unwanted files and deletes them)
	threads.push_back(std::thread(Deleter::Start_Task));
	
	//don't kill the threads by quiting out of the function
	while (true);

	return;
}