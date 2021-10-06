#include "code/utilities/streams/manipulators/lib.hpp"
#include <cstdio>

void Disable_Console_Output(){
   
   //close C file descriptors
   //this will prevent cout and cin aswell
   fclose(stdout);
   fclose(stderr);
}

void Enable_Console_Output(){

  //reopen C file descriptors
  freopen ("/dev/tty", "a", stdout);
  freopen ("/dev/tty", "a", stderr);

  //clear errors on cout and cerr
  //so that they can print again as well
  std::cout.clear();
  std::cerr.clear();
  
}