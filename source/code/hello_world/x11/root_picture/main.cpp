#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include<X11/xpm.h>
#include <X11/extensions/shape.h>


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


int main(){
    
    //settings
    bool syncronize_debug_mode = false;
    bool set_error_handler = true;
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
    theWindowAttributes.background_pixel = colors.bg.pixel;
    theWindowAttributes.override_redirect = true;
    
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
    XFlush(theDisplay);
    
    
    
    
    
    //main looping logic
    XEvent      theEvent;

    while (true){
        
        //I think we need to wait until the server is ready?
        //this is how we do that.
        while (XPending(theDisplay)) {
            XNextEvent(theDisplay,&theEvent);
            switch (theEvent.type) {
                case Expose:
                if (theEvent.xexpose.count == 0) {
                }
                break;
            }
        }
        
        

    //create the image
    int awake_bsd_width = 32;
    int awake_bsd_height = 32;
    static char awake_bsd_bits[] = {
       0x00, 0x86, 0x30, 0x00, 0x08, 0x85, 0x50, 0x10, 0x90, 0x02, 0xa0, 0x08,
       0x40, 0x02, 0x20, 0x01, 0x40, 0xfa, 0x2f, 0x01, 0x40, 0x04, 0x10, 0x01,
       0x40, 0x30, 0x06, 0x01, 0x4c, 0x48, 0x09, 0x31, 0x80, 0x88, 0x88, 0x00,
       0x80, 0xc4, 0x91, 0x00, 0x00, 0xe5, 0x53, 0x00, 0x00, 0xe5, 0x53, 0x00,
       0x00, 0x45, 0x51, 0x08, 0x90, 0x38, 0x8e, 0x10, 0x88, 0xc0, 0x81, 0x00,
       0x80, 0x04, 0x90, 0x00, 0x00, 0x19, 0x4c, 0x00, 0x08, 0xe2, 0x23, 0x00,
       0x12, 0x0c, 0x18, 0x00, 0x14, 0x1c, 0x18, 0x00, 0x09, 0x02, 0x20, 0x00,
       0x16, 0x01, 0x40, 0x00, 0xa0, 0x00, 0x80, 0x00, 0x40, 0x08, 0x08, 0x01,
       0xc0, 0x04, 0x10, 0x01, 0x40, 0x06, 0x30, 0x01, 0x80, 0x07, 0xd0, 0x00,
       0x00, 0x04, 0x10, 0x00, 0x80, 0x87, 0xf0, 0x10, 0x40, 0x40, 0x01, 0x23,
       0x40, 0x40, 0x01, 0x7d, 0x80, 0x3f, 0xfe, 0x20};
       
    int awake_bsd_mask_width = 32;
    int awake_bsd_mask_height = 32;
    static char awake_bsd_mask_bits[] = {
     0x00,0x86,0x30,0x00,0x08,0x87,0x70,0x10,0x90,0x03,0xe0,0x08,0xc0,0x03,0xe0,
     0x01,0xc0,0xfb,0xef,0x01,0xc0,0xff,0xff,0x01,0xc0,0xff,0xff,0x01,0xcc,0xff,
     0xff,0x31,0x80,0xff,0xff,0x00,0x80,0xff,0xff,0x00,0x00,0xff,0x7f,0x00,0x00,
     0xff,0x7f,0x00,0x00,0xff,0x7f,0x08,0x90,0xff,0xff,0x10,0x88,0xff,0xff,0x00,
     0x80,0xff,0xff,0x00,0x00,0xff,0x7f,0x00,0x08,0xfe,0x3f,0x00,0x12,0xfc,0x1f,
     0x00,0x14,0xfc,0x1f,0x00,0x09,0xfe,0x3f,0x00,0x16,0xff,0x7f,0x00,0xa0,0xff,
     0xff,0x00,0xc0,0xff,0xff,0x01,0xc0,0xff,0xff,0x01,0xc0,0xff,0xff,0x01,0x80,
     0xff,0xdf,0x00,0x00,0xfc,0x1f,0x00,0x80,0xff,0xff,0x10,0xc0,0x7f,0xff,0x23,
     0xc0,0x7f,0xff,0x7d,0x80,0x3f,0xfe,0x20};

       
    Pixmap BitmapCreatePtr = XCreatePixmapFromBitmapData(theDisplay, theRoot,
                    awake_bsd_bits,
                    BITMAP_WIDTH, BITMAP_HEIGHT,
                    colors.fg.pixel,
                    colors.bg.pixel,
                    DefaultDepth(theDisplay, theScreen));

    Pixmap BitmapMasksPtr = XCreateBitmapFromData(theDisplay, theRoot, awake_bsd_mask_bits, BITMAP_WIDTH, BITMAP_HEIGHT);

    XGCValues           theGCValues;
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
       theChanges.x = x_c;
       theChanges.y = y_c;
       XConfigureWindow(theDisplay, theWindow, CWX | CWY, &theChanges);
    // XShapeCombineMask(theDisplay, theWindow, ShapeBounding,
    //                   0, 0, BitmapMasksPtr, ShapeSet);
       XMapWindow(theDisplay, theWindow);
    //   XFillRectangle(theDisplay, theWindow, GCCreatePtr,
    //                  0, 0, BITMAP_WIDTH, BITMAP_HEIGHT);
      
      auto img = Load_Image(theDisplay, "/home/thickey/Desktop/mario1.xpm");
      
      XPutImage(theDisplay, theWindow, GCCreatePtr, img, 0, 0,
                0,
                0,
                img->width, img->height );
      
    XFlush(theDisplay);
      
      sleep(1);
      //std::cout << "sdf" << std::endl;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}