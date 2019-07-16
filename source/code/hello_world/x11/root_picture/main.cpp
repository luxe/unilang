#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include<X11/xpm.h>
#include <X11/extensions/shape.h>



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
    std::cout << WindowHeight << std::endl;
    std::cout << WindowWidth << std::endl;

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
    
    //set window attributes
    XSetWindowAttributes  theWindowAttributes;
    theWindowAttributes.background_pixel = theBackgroundColor.pixel;
    theWindowAttributes.override_redirect = true;
    XChangeWindowAttributes(theDisplay, theRoot, CWCursor, &theWindowAttributes);
    
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
        
        //I don't think this is necessary
        while (XPending(theDisplay)) {
            std::cout << "sdfsdf2   " << std::endl;
            XNextEvent(theDisplay,&theEvent);
            switch (theEvent.type) {
                case Expose:
                if (theEvent.xexpose.count == 0) {
                    std::cout << "sdfsdf!!" << std::endl;
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
                    theForegroundColor.pixel,
                    theBackgroundColor.pixel,
                    DefaultDepth(theDisplay, theScreen));

    Pixmap BitmapMasksPtr = XCreateBitmapFromData(theDisplay, theRoot, awake_bsd_mask_bits, BITMAP_WIDTH, BITMAP_HEIGHT);

    XGCValues           theGCValues;
    theGCValues.function = GXcopy;
    theGCValues.foreground = theForegroundColor.pixel;
    theGCValues.background = theBackgroundColor.pixel;
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
      
      //mona lisa
      XImage *img;
      XpmReadFileToImage (theDisplay, "/home/laptop/Desktop/mario1.xpm", &img, NULL, NULL);
      
      std::cout << XPutImage(theDisplay, theWindow, GCCreatePtr, img, 0, 0,
                0,
                0,
                img->width, img->height ) << std::endl;
      
    XFlush(theDisplay);
      
      sleep(1);
      //std::cout << "sdf" << std::endl;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}