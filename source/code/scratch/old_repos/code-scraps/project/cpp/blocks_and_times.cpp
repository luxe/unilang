#include <iostream>
#include <cstdlib>
#include <time.h>
#include <thread>
#include <curses.h>
#include <termios.h>

void SleepForNumberOfSeconds(const int & numberofSeconds,bool & timesUp);
void WaitForTimeoutOrInterrupt(int const& numberofSeconds);
int keypress(void);
void nonblock(const bool state);

int main(){
	
	std::cout << "waiting a for 3 seconds or until a key is pressed" << std::endl;
	WaitForTimeoutOrInterrupt(3);
	
	return EXIT_SUCCESS;
}

void SleepForNumberOfSeconds(const int & numberofSeconds,bool & timesUp){
	
	timespec delay = {numberofSeconds,0}; //500,000 = 1/2 milliseconds
	timespec delayrem;
	
	nanosleep(&delay, &delayrem);
	timesUp = true;
	
	return;
}
void WaitForTimeoutOrInterrupt(int const& numberofSeconds){
	
	bool timesUp = false;
	
	std::thread t(SleepForNumberOfSeconds, numberofSeconds, std::ref(timesUp));
	nonblock(1);
	while (!timesUp && !keypress()){
		
	}
	
	if (t.joinable()){
		t.detach();
	}
	nonblock(0);
	
	return;
}
int keypress(void){
	struct timeval tv;
	fd_set fds;
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	FD_ZERO(&fds);
	FD_SET(STDIN_FILENO, &fds); //STDIN_FILENO is 0
	select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
	return FD_ISSET(STDIN_FILENO, &fds);
}
void nonblock(const bool state){
	
	struct termios ttystate;
	
	//get the terminal state
	tcgetattr(STDIN_FILENO, &ttystate);
	
	if (state){
		//turn off canonical mode
		ttystate.c_lflag &= ~ICANON;
		//minimum of number input read.
		ttystate.c_cc[VMIN] = 1;
	}
	else{
		//turn on canonical mode
		ttystate.c_lflag |= ICANON;
	}
	
	//set the terminal attributes.
	tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}