#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/xpm.h>
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

struct main_x11_state {
  
  //some display/screen info
  Display * d;
  int screen;
  unsigned int depth;
  
  //root window info
  Window root;
  x11_window_geometry root_geo;
  
  //colors
  x11_bg_fg_colors colors;
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

XImage *Load_Xpm_Image(Display * theDisplay, std::string const& file_name){

      XImage *img;
      auto failed = XpmReadFileToImage (theDisplay, file_name.c_str(), &img, NULL, NULL);
      if (failed){
        std::cout << "could not load image" << std::endl;
        exit(0);
      }
      return img;
}

Pixmap Load_Xbm_Image(main_x11_state const& state, int x, int y, std::string const& file_name){

    //some garbage boilerplate for loading images
    //we need this pixmap for some reason so we can load other pixmaps?
    static char garbage[] = {};
    Pixmap BitmapCreatePtr = XCreatePixmapFromBitmapData(state.d, state.root,
                    garbage,
                    x, y,
                    state.colors.fg.pixel,
                    state.colors.bg.pixel,
                    DefaultDepth(state.d, state.screen));
    
  Pixmap p;
  unsigned int w;
  unsigned int h;
  int hot_x;
  int hot_y;
  auto failed = XReadBitmapFile(state.d,BitmapCreatePtr,file_name.c_str(),&w,&h,&p,&hot_x,&hot_y);
  return p;
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

GC Create_Graphics_Context(Display * theDisplay, int theScreen, Window theWindow, Window theRoot, x11_bg_fg_colors colors, int width, int height){
  
    static char garbage[] = {};
    Pixmap BitmapCreatePtr = XCreatePixmapFromBitmapData(theDisplay, theRoot,
                    garbage,
                    width, height,
                    colors.fg.pixel,
                    colors.bg.pixel,
                    DefaultDepth(theDisplay, theScreen));
  
  
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
    return GCCreatePtr;
    
}



struct setup_display_settings {
    bool syncronize_debug_mode = false;
    bool set_error_handler = false;
    bool check_for_shape_extension = true;
};


Display * setup_display(setup_display_settings const& settings){
  
    if (settings.set_error_handler){
        set_typical_x11_error_handler();
    }

    //create the main display
    auto d = open_display();

    //turn on debug sync mode
    if (settings.syncronize_debug_mode) {
        XSynchronize(d,true);
    }
    
    //feature check
    if (settings.check_for_shape_extension){
        check_shape_extension(d);
    }
    
    return d;
}


main_x11_state create_main_x11_state(setup_display_settings const& settings){
  
  main_x11_state state;
  
    //create the main display
    state.d = setup_display(settings);
    
    //create the screen and depth
    state.screen = DefaultScreen(state.d);
    state.depth = DefaultDepth(state.d, state.screen);
    
    //create the root window
    state.root = RootWindow(state.d, state.screen);
    state.root_geo = get_geometry(state.d, state.root);
    
    //colors
    state.colors = setup_colors(state.d, state.screen, state.depth);
    
  return state;
}

struct x11_image_sprite{
  XImage *main;
  Pixmap bitmap_mask;
  std::string name;
};


x11_image_sprite load_image_sprite(main_x11_state const& state, std::string const& path, std::string const& name){
  x11_image_sprite sprite;
  sprite.name = name;
  sprite.main = Load_Xpm_Image(state.d, path + name + ".xpm");
  sprite.bitmap_mask = Load_Xbm_Image(state,sprite.main->width, sprite.main->height,path + name + "_mask.xbm");
  return sprite;
}


Window create_game_window(main_x11_state const& state){
  
  //set window attributes
  XSetWindowAttributes  theWindowAttributes;
  memset(&theWindowAttributes,0,sizeof(XSetWindowAttributes));
  theWindowAttributes.background_pixel = state.colors.bg.pixel;
  theWindowAttributes.override_redirect = 1;
  
  //unsigned long theWindowMask = CWBackPixel | CWCursor | CWOverrideRedirect;
  unsigned long theWindowMask = CWOverrideRedirect;
  Window theWindow = XCreateWindow(state.d, state.root, 0, 0,
                          state.root_geo.width, state.root_geo.height,
                          0, state.depth, InputOutput, CopyFromParent,
                          theWindowMask, &theWindowAttributes);
  
    //XStoreName(state.d, theWindow, "mario game");
    XSelectInput(state.d, theWindow,
               ExposureMask|VisibilityChangeMask|KeyPressMask);
    
    //XFlush(state.d);
    XMapWindow(state.d, theWindow);
    return theWindow;
}

template <typename Fun>
void x11_game_loop(main_x11_state const& state, Fun fun){

  infinite_interrupt_loop(8000L,[&](){
    
    //necessary wait for XServer I think
    process_x11_events(state.d);
    
    //what the use wants to do each cycle
    fun();
    
    //do we need to flush?
    XFlush(state.d);
    
  });
}

void Draw_Image(main_x11_state const& state, Window theWindow, GC gc, x11_image_sprite const& sprite, int x, int y){
  
  int relative_x = 0;
  int relative_y = 0;
  
  //position the window instead of the sprite inside the window
  XWindowChanges    theChanges;
  theChanges.x = x;
  theChanges.y = y;
  XConfigureWindow(state.d, theWindow, CWX | CWY, &theChanges);
  
  XShapeCombineMask(state.d, theWindow, ShapeBounding, relative_x , relative_y, sprite.bitmap_mask, ShapeSet);
  
       //oneko did this.  I don't think its necessary
       //XFillRectangle(state.d, theWindow, gc, 0, 0, sprite.main->width, sprite.main->height);
  
  XPutImage(state.d, theWindow, gc, sprite.main, 0,0,relative_x, relative_y,sprite.main->width, sprite.main->height );
}


int main(){
    
    //create the main display
    //this is typical x11 boilerplate setup stuff
    //hopefully customizable enough that you don't have to dig into this
    setup_display_settings settings;
    settings.syncronize_debug_mode = false;
    settings.set_error_handler = false;
    settings.check_for_shape_extension = true;
    auto state = create_main_x11_state(settings);
    
    //load all the sprites
    //we assume that the file names match what is necessary for rendering xpm and xbm files in x11
    auto mario_stand = load_image_sprite(state,"/usr/local/share/mario/","mario-stand");
    auto mario_walk_1 = load_image_sprite(state,"/usr/local/share/mario/","mario-walk1");
    auto mario_walk_2 = load_image_sprite(state,"/usr/local/share/mario/","mario-walk2");
    auto mario_walk_3 = load_image_sprite(state,"/usr/local/share/mario/","mario-walk3");
    
    
    auto theWindow = create_game_window(state);
    auto gc = Create_Graphics_Context(state.d,state.screen,theWindow,state.root,state.colors,mario_stand.main->width, mario_stand.main->height);
    
    //main looping logic
    //why not just use a timer/sleep?
    //I don't know.  I saw some similar examples using the older
    //c interrupt loop, and thought it might be better for x11.
    //especially because I had an infinite while(true) before and
    //it made my computer freeze
    
    
    //X11 is notorious for image tearing
    //originally, I had one giant window, and I used PutImage each cycle to put the sprite in a different place.
    //this flickered and looked bad.  So Now I make little windows for each sprite, and place the sprite in the window at 0,0.
    //instead of moving the images each cycle, we move their window instead.  This looks clean.  I'm not sure if there are any ramifications to this
    //or if i totally missed something in terms of writing images, but this is the best I can do.
    //fwiw, I see everyone on the internet talking about how X11 tears because its old, and its one of the reasons for wayland.
    x11_game_loop(state,[&](){
    
    
        //draw it
       static int x_c = 200;
       static int y_c = 100;
       ++x_c;
       ++y_c;
      
      Draw_Image(state,theWindow,gc,mario_stand,x_c,y_c);
    });
    
}