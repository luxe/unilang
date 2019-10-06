#include <iostream>
#include <cstdlib>
#include <thread>
#include "code/utilities/shell/lib.hpp"

int main(int const argc, char** const argv){
    
    std::cout << "hello world" << std::endl;
    
    //start the websocket server
    std::thread t([&](){
        execute("/usr/local/bin/chromix-too-server");
    });
    
    t.join();
}