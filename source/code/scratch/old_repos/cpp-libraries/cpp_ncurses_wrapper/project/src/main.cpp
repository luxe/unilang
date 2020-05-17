//actually.. forget this.. Ncurses has c++ support already in the GNU 2011 package

#include <iostream>
#include <string>
#include <utility>
#include <memory>
#include <vector>
#include <curses.h>
#include <unistd.h> 

auto A(){
std::cout << "Window Created" << std::endl;
return new int(3);
}
int B(int* w){
std::cout << "Window Deleted" << std::endl;
return 0;
}


class Window {

    private: WINDOW* ptr;

	//constructor
	public: Window() : ptr(initscr()) {}
	public: void Destroy(){ delwin(ptr); return; }

};

class Screen{

    private: std::vector<Window> windows;
	
	public:
	Screen(){}
	void Refresh(){ refresh(); return; }
	
	void Add_Window(){
	    windows.emplace_back();
	    return;
	}
	
	~Screen(){
	for (auto & it: windows){ it.Destroy(); }
	    endwin();
	    refresh();
	}
	
	
};

int main(){
	
	Screen screen;
	screen.Add_Window();
	
	
    mvaddstr(13, 33, "Hello, world!");
    screen.Refresh();
    sleep(3);
    
	
	return EXIT_SUCCESS;
}
