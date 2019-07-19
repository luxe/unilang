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
#include "code/utilities/x11/main_state/x11_main_state_creator.hpp"
#include "code/utilities/x11/loop/x11_looper.hpp"











Window create_game_window(Main_X11_State const& state){
  
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

struct x11_image_sprite{
  XImage *main;
  Pixmap bitmap_mask;
  std::string name;
};

XImage *Load_Xpm_Image(Display * theDisplay, std::string const& file_name){

      XImage *img;
      auto failed = XpmReadFileToImage (theDisplay, file_name.c_str(), &img, NULL, NULL);
      if (failed){
        std::cout << "could not load image" << std::endl;
        exit(0);
      }
      return img;
}

Pixmap Load_Xbm_Image(Main_X11_State const& state, int x, int y, std::string const& file_name){

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


x11_image_sprite load_image_sprite(Main_X11_State const& state, std::string const& path, std::string const& name){
  x11_image_sprite sprite;
  sprite.name = name;
  sprite.main = Load_Xpm_Image(state.d, path + name + ".xpm");
  sprite.bitmap_mask = Load_Xbm_Image(state,sprite.main->width, sprite.main->height,path + name + "_mask.xbm");
  return sprite;
}

GC Create_Graphics_Context(Display * theDisplay, int theScreen, Window theWindow, Window theRoot, X11_Bg_Fg_Colors colors, int width, int height){
  
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

void Draw_Image(Main_X11_State const& state, Window theWindow, GC gc, x11_image_sprite const& sprite, int x, int y){
  
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
    Setup_Display_Settings settings;
    settings.syncronize_debug_mode = false;
    settings.set_error_handler = false;
    settings.check_for_shape_extension = true;
    auto state = X11_Main_State_Creator::Create(settings);
    
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
    //instead of moving the images each cycle, we move the entire window instead.  This looks clean but feels wrong.  I'm not sure if there are any ramifications to this
    //or if i totally missed something in terms of writing images, but this is the best I can do,
    //and based on the various complaints I've heard about X this may actually be a correct way to go about this.
    //fwiw, I see everyone on the internet talking about how X11 tears because its old, and its one of the reasons for wayland.
    X11_Looper::typical_x11_game_loop(state,[&](){
    
    
        //draw it
       static int x_c = 200;
       static int y_c = 100;
       ++x_c;
       ++y_c;
      
      Draw_Image(state,theWindow,gc,mario_stand,x_c,y_c);
    });
    
}