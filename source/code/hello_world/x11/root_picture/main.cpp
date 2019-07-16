#include <iostream>
#include <string>
#include <cstdlib>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/shape.h>

int main(){
    
    //settings
    bool syncronize_debug_mode = false;
    
    //create the main display
    Display *theDisplay = nullptr;
    if ((theDisplay = XOpenDisplay(NULL)) == NULL) {
        std::cerr << "can't create display" << std::endl;
        exit(1);
    }
  
  
    //turn on debug sync mode
    if (syncronize_debug_mode) {
        XSynchronize(theDisplay,true);
    }
    
    //check that we can do shape stuff
    int event_base = 0;
    int error_base = 0;
    auto supported = XShapeQueryExtension(theDisplay,&event_base, &error_base);
    if (!supported){
        std::cout << "doesn't support shapes" << std::endl;
    }
    
  //create the screen and depth
  int theScreen = DefaultScreen(theDisplay);
  unsigned int theDepth = DefaultDepth(theDisplay, theScreen);
  
  //create the root window
  Window theRoot = RootWindow(theDisplay, theScreen);
  
  //builds geometry
  Window theTempRoot;
  int WindowPointX = 0;
  int WindowPointY = 0;
  unsigned int WindowWidth = 0;
  unsigned int WindowHeight = 0;
  unsigned int BorderWidth = 0;
  XGetGeometry(theDisplay, theRoot, &theTempRoot,
               &WindowPointX, &WindowPointY,
               &WindowWidth, &WindowHeight,
               &BorderWidth, &theDepth);
  
  //setup colors
    Colormap theColormap = DefaultColormap(theDisplay, theScreen);
    std::string Foreground = "black";
    std::string Background = "white";
    if (theDepth == 1) {
        Foreground = "black";
        Background = "white";
    }
    
    XColor      theExactColor;
    XColor  theForegroundColor;
    XColor  theBackgroundColor;
    if (!XAllocNamedColor(theDisplay, theColormap,
                Foreground.c_str(), &theForegroundColor, &theExactColor)) {
        std::cerr << "Can't XAllocNamedColor" << std::endl;
        exit(1);
    }

    if (!XAllocNamedColor(theDisplay, theColormap,
                Background.c_str(), &theBackgroundColor, &theExactColor)) {
        std::cerr << "Can't XAllocNamedColor" << std::endl;
        exit(1);
    }
}