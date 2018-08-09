#include <iostream>
#include <string>
#include "code/utilities/mouse/mouse_controller.hpp"

int main(int argc, char** argv){

    Sleep_For_N_Milliseconds(5000);
    Mouse_Controller controller;
    
    //click "Create Route"
    Point p;
    p.x = 675;
    p.y = 472;
    controller.move_mouse_at_presentation_speed(p);
    controller.presentation_click();
    
    //click "Name Box"
    p.x = 726;
    p.y = 568;
    controller.move_mouse_at_presentation_speed(p);
    controller.presentation_click();
    
    // type into "Name Box"
    controller.type_something_at_presentation_speed("loopy road");
}