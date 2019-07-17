#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include<X11/xpm.h>
#include <X11/extensions/shape.h>
#include <sys/time.h>
#include <signal.h>


struct x11_window_geometry {
  int x = 0;
  int y = 0;
  unsigned int width = 0;
  unsigned int height = 0;
  unsigned int border_width = 0;
  unsigned int depth = 0;
};

struct x11_bg_fg_colors {
  XColor bg;
  XColor fg;
};


void set_typical_x11_error_handler(){
    
    //error handler
    XSetErrorHandler([](Display *dpy, XErrorEvent *err){
            char msg[80];
            XGetErrorText(dpy, err->error_code, msg, 80);
            std::cout << "X Error: " << msg  << std::endl;
            exit(1);
            return 0;
    });
}

Display * open_display(){
    
    //create the main display
    Display *theDisplay = nullptr;
    if ((theDisplay = XOpenDisplay(NULL)) == NULL) {
        std::cerr << "can't create display" << std::endl;
        exit(1);
    }
    return theDisplay;
}

void check_shape_extension(Display * theDisplay){

    //check that we can do shape stuff
    int event_base = 0;
    int error_base = 0;
    auto supported = XShapeQueryExtension(theDisplay,&event_base, &error_base);
    if (!supported){
        std::cout << "doesn't support shapes" << std::endl;
    }
}

x11_window_geometry get_geometry(Display * theDisplay, Window theRoot){
    x11_window_geometry geo;
    Window theTempRoot;
    XGetGeometry(theDisplay, theRoot, &theTempRoot,
               &geo.x, &geo.y,
               &geo.width, &geo.height,
               &geo.border_width, &geo.depth);
  return geo;
}

x11_bg_fg_colors setup_colors(Display * theDisplay, int theScreen, unsigned int theDepth)
{
    x11_bg_fg_colors colors;
    
    Colormap theColormap = DefaultColormap(theDisplay, theScreen);
    std::string Foreground = "black";
    std::string Background = "white";
    if (theDepth == 1) {
        Foreground = "black";
        Background = "white";
    }

    XColor      theExactColor;
    if (!XAllocNamedColor(theDisplay, theColormap,
                Foreground.c_str(), &colors.fg, &theExactColor)) {
        std::cerr << "Can't XAllocNamedColor" << std::endl;
        exit(1);
    }

    if (!XAllocNamedColor(theDisplay, theColormap,
                Background.c_str(), &colors.bg, &theExactColor)) {
        std::cerr << "Can't XAllocNamedColor" << std::endl;
        exit(1);
    }
    
    return colors;
}

XImage *Load_Image(Display * theDisplay, std::string const& file_name){

      XImage *img;
      auto failed = XpmReadFileToImage (theDisplay, file_name.c_str(), &img, NULL, NULL);
      if (failed){
        std::cout << "could not load image" << std::endl;
        exit(0);
      }
      return img;
}

static void InterruptNullFunctionCatcher(int x)
{
  /* No Operation */
#if defined(SYSV) || defined(SVR4)
  signal(SIGALRM, InterruptNullFunctionCatcher);
#endif /* SYSV || SVR4 */
}

void set_interrupt_timer(unsigned long usec_delay){
  struct itimerval      x;
  timerclear(&x.it_interval);
  timerclear(&x.it_value);
  x.it_interval.tv_usec = usec_delay;
  x.it_value.tv_usec = usec_delay;
  setitimer(ITIMER_REAL, &x, 0);
}


template <typename Fun>
void within_interrupt_timer(unsigned long usec_delay, Fun f){
  set_interrupt_timer(usec_delay);
  f();
  pause();
}

template <typename Fun>
void infinite_interrupt_loop(unsigned long usec_delay, Fun f){
  
  signal(SIGALRM, InterruptNullFunctionCatcher);
  while (true){
    within_interrupt_timer(usec_delay,[&](){
      f();
    });
  }
}



void process_x11_events(Display * theDisplay){
  
    //I think we need to wait until the server is ready?
    //this is how we do that.
  XEvent theEvent;
    while (XPending(theDisplay)) {
        XNextEvent(theDisplay,&theEvent);
        switch (theEvent.type) {
            case Expose:
              if (theEvent.xexpose.count == 0) {
              }
              break;
            case KeyPress:
              std::cout << "key pressed" << std::endl;
              break;
        }
    }
}


int main(){
    
    //settings
    bool syncronize_debug_mode = false;
    bool set_error_handler = false;
    bool check_for_shape_extension = true;
    
    if (set_error_handler){
        set_typical_x11_error_handler();
    }

    //create the main display
    auto theDisplay = open_display();

    //turn on debug sync mode
    if (syncronize_debug_mode) {
        XSynchronize(theDisplay,true);
    }
    
    //feature check
    if (check_for_shape_extension){
        check_shape_extension(theDisplay);
    }

    //create the screen and depth
    int theScreen = DefaultScreen(theDisplay);
    unsigned int theDepth = DefaultDepth(theDisplay, theScreen);
    //std::cout << theDepth << std::endl;

    //create the root window
    Window theRoot = RootWindow(theDisplay, theScreen);

    //builds geometry
    auto geo = get_geometry(theDisplay, theRoot);

    //setup colors
    auto colors = setup_colors(theDisplay, theScreen, theDepth);
    
    //set window attributes
    XSetWindowAttributes  theWindowAttributes;
    memset(&theWindowAttributes,0,sizeof(XSetWindowAttributes));
    theWindowAttributes.background_pixel = colors.bg.pixel;
    theWindowAttributes.override_redirect = 1;
    
    //change the cursor. no thanks.
    //XChangeWindowAttributes(theDisplay, theRoot, CWCursor, &theWindowAttributes);
    
    //create main window
    unsigned long theWindowMask = CWBackPixel | CWCursor | CWOverrideRedirect;
    int BITMAP_WIDTH = 16;
    int BITMAP_HEIGHT = 32;
    Window theWindow = XCreateWindow(theDisplay, theRoot, 0, 0,
                            BITMAP_WIDTH, BITMAP_HEIGHT,
                            0, theDepth, InputOutput, CopyFromParent,
                            theWindowMask, &theWindowAttributes);
    XStoreName(theDisplay, theWindow, "window_name");
    XSelectInput(theDisplay, theWindow,
               ExposureMask|VisibilityChangeMask|KeyPressMask);
    
    //  XUndefineCursor(theDisplay,theRoot);
    //XUndefineCursor(theDisplay,theWindow);
    XFlush(theDisplay);
    
    
    
    std::cout << "oo" << std::endl;
    
    //main looping logic
    auto img = Load_Image(theDisplay, "/usr/local/share/mario/mario-stand.xpm");
    auto bitmask = Load_Image(theDisplay, "/usr/local/share/mario/mario-stand_mask.xpm");
    infinite_interrupt_loop(10000L,[&](){
        
        process_x11_events(theDisplay);
        
        

    //create the image
       
    int awake_bsd_mask_width = 16;
    int awake_bsd_mask_height = 32;
static char mario_bitmask_bits[] = {
  0xC0, 0x07, 0xF0, 0x07, 0xF8, 0x07, 0xF8, 0x3F, 0xF8, 0x0F, 0xFC, 0x3F, 
  0xFC, 0x7F, 0xFE, 0x7F, 0xFE, 0x3F, 0xFE, 0x3F, 0xF8, 0x1F, 0xF0, 0x07, 
  0xF0, 0x0F, 0xF8, 0x1F, 0xFC, 0x3F, 0xFE, 0x7F, 0xFE, 0x7F, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFE, 0x7F, 
  0xFC, 0x3F, 0x7E, 0x7E, 0x3E, 0x7C, 0x3E, 0x7C, 0x3C, 0x3C, 0x3C, 0x3C, 
  0x3F, 0xFC, 0x3F, 0xFC, };

    static char garbage[] = {};
    Pixmap BitmapCreatePtr = XCreatePixmapFromBitmapData(theDisplay, theRoot,
                    garbage,
                    img->width, img->height,
                    colors.fg.pixel,
                    colors.bg.pixel,
                    DefaultDepth(theDisplay, theScreen));

    Pixmap BitmapMasksPtr = XCreateBitmapFromData(theDisplay, theRoot, mario_bitmask_bits, BITMAP_WIDTH, BITMAP_HEIGHT);

    XGCValues           theGCValues;
    memset(&theGCValues,0,sizeof(XGCValues));
    theGCValues.function = GXcopy;
    theGCValues.foreground = colors.fg.pixel;
    theGCValues.background = colors.bg.pixel;
    theGCValues.fill_style = FillTiled;
    theGCValues.ts_x_origin = 0;
    theGCValues.ts_y_origin = 0;
    theGCValues.tile = BitmapCreatePtr;

    GC GCCreatePtr = XCreateGC(theDisplay, theWindow,
                    GCFunction | GCForeground | GCBackground | GCTile |
                    GCTileStipXOrigin | GCTileStipYOrigin | GCFillStyle,
                    &theGCValues);
    
    
        //draw it
      XWindowChanges    theChanges;

       static int x_c = 200;
       static int y_c = 100;
       ++x_c;
       theChanges.x = x_c;
       theChanges.y = y_c;
       XConfigureWindow(theDisplay, theWindow, CWX | CWY, &theChanges);
       XShapeCombineMask(theDisplay, theWindow, ShapeBounding, 0, 0, BitmapMasksPtr, ShapeSet);
       XMapWindow(theDisplay, theWindow);
       //XFillRectangle(theDisplay, theWindow, GCCreatePtr, 0, 0, BITMAP_WIDTH, BITMAP_HEIGHT);
      
      XPutImage(theDisplay, theWindow, GCCreatePtr, img, 0, 0,
                0,
                0,
                img->width, img->height );
      
    XFlush(theDisplay);
      
      //sleep(9000);
      //std::cout << "sdf" << std::endl;
    });
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}