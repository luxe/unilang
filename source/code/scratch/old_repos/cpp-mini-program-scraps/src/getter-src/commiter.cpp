#include "commiter.hpp"
#include "global.hpp"
#include <thread>
#include <chrono>
#include <iostream>

void Commiter::Start_Task() {
	
	while (true) {
		//1. pull anything new (I assume there is no merge conflicts) (verbose)
		//2. stage all the new files                                   (quiet)
		//3. commit them                                               (quiet)
		//4. push them to the interwebz                                (quiet)
		std::cout <<  std::string("updating repo\n");
		system("git pull >> /dev/null 2>&1; git add -A :/; git commit -am \"auto update\" >> /dev/null 2>&1; git push >> /dev/null 2>&1;");
		std::cout <<  std::string("repo now updated\n");
		
		//sleep a number of minutes
		std::this_thread::sleep_for(std::chrono::minutes(constant::DELAY_BETWEEN_COMMITS));
	}
	
	return;
}
