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
#include "code/utilities/x11/sprite/sprite_loader.hpp"
#include "code/utilities/x11/sprite/sprite_window_creator.hpp"


void Draw_Image(Main_X11_State const& state, Sprite_Window const& sp){
  
  int relative_x = 0;
  int relative_y = 0;
  
  //position the window instead of the sprite inside the window
  XWindowChanges    theChanges;
  theChanges.x = sp.x;
  theChanges.y = sp.y;
  XConfigureWindow(state.d, sp.w, CWX | CWY, &theChanges);
  
  XShapeCombineMask(state.d, sp.w, ShapeBounding, relative_x , relative_y, sp.sprite.bitmap_mask, ShapeSet);
  
       //oneko did this.  I don't think its necessary
       //XFillRectangle(state.d, theWindow, gc, 0, 0, sprite.main->width, sprite.main->height);
  
  XPutImage(state.d, sp.w, sp.gc, sp.sprite.main, 0,0,relative_x, relative_y,sp.sprite.main->width, sp.sprite.main->height );
}


int main(){
    
    //create the main display (connect to the X Server).  Just get everything setup to use X11.
    //hoping this is all typical x11 boilerplate.
    //I'm not sure I did it all correctly, but wanted to abstract it away.
    //hopefully customizable enough for most use cases and you don't have to dig into this.
    Setup_Display_Settings settings;
    settings.syncronize_debug_mode = false;
    settings.set_error_handler = false;
    settings.check_for_shape_extension = true;
    auto state = X11_Main_State_Creator::Create(settings);
    
    //load all the sprites
    //we assume that the file names match what is necessary for rendering xpm and xbm files in x11
    std::string share_directory = "/usr/local/share/mario/";
    auto mario_stand = Sprite_Loader::Load(state,share_directory,"mario-stand");
    auto mario_walk_1 = Sprite_Loader::Load(state,share_directory,"mario-walk1");
    auto mario_walk_2 = Sprite_Loader::Load(state,share_directory,"mario-walk2");
    auto mario_walk_3 = Sprite_Loader::Load(state,share_directory,"mario-walk3");
    
    
    auto mario = Sprite_Window_Creator::Create(state,mario_stand);
    
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
       ++mario.x;
       ++mario.y;
      
      Draw_Image(state,mario);
    });
    
}