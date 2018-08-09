#include <iostream>
#include <string>
#include "code/utilities/mouse/mouse_controller.hpp"
#include "code/utilities/shell/lib.hpp"


void create_presentation_text(Point size, Point p, std::string const& str){
    std::string command;
    command += "echo \"";
    command += str;
    command += "\"";
    command += " | ";
    command += "lemonbar ";
    command += "-p ";
    command += "-F#FF000000 ";
    command += "-B#00000000 ";
    command += "-g ";
    command += std::to_string(size.x);
    command += "x";
    command += std::to_string(size.y);
    command += "+";
    command += std::to_string(p.x);
    command += "+";
    command += std::to_string(p.y);
    command += "-f ";
    command += "\"";
    command += "Arial Black-24";
    command += "\"";
    command += " &";
    std::cout << command << std::endl;
    
    execute_quietly(command);
}

void remove_all_presentation_text(){
    execute_quietly("pkill lemonbar");
}

void show_first_message(std::string const& str){
    Point size;
    size.x = 200;
    size.y = 40;
    Point p;
    p.x = 1500;
    p.y = 700;
    create_presentation_text(size,p,str);
}

//create bar at the top
//echo "hello world" | ./lemonbar -p -F#FFFFFFFF -B#FF222222
int main(int argc, char** argv){

    Sleep_For_N_Milliseconds(5000);
    Mouse_Controller controller;
    
    //click "Create Route"
    Point p;
    p.x = 675;
    p.y = 472;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    show_first_message("Load/Create Routes");
    controller.presentation_click();
    
    //click "Name Box"
    p.x = 809;
    p.y = 573;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    // type into "Name Box"
    controller.type_something_at_presentation_speed("test route");
    
    
    //click add lane button multiple times
    p.x = 735;
    p.y = 598;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(400);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(300);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(290);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(280);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(270);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(260);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(250);
    controller.presentation_click();
    
    //click marking button
    p.x = 892;
    p.y = 574;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    remove_all_presentation_text();
    show_first_message("Apply Annotation Algos");
    controller.presentation_click();
    
    //toggle start marking
    p.x = 860;
    p.y = 812;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(700);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //toggle end marking
    p.x = 1009;
    p.y = 812;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(700);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //turn on Regeneration SLA
    p.x = 860;
    p.y = 994;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //hover over sla slider
    p.x = 1060;
    p.y = 994;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    
    //slide left
    p.x = 1034;
    p.y = 994;
    controller.drag_mouse(p,6000);
    Sleep_For_N_Milliseconds(200);
    
    //slide right
    p.x = 1112;
    p.y = 994;
    controller.drag_mouse(p,6000);
    Sleep_For_N_Milliseconds(200);
    
    //close algorithm tab
    p.x = 1112;
    p.y = 771;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //click "Settings Tab"
    p.x = 753;
    p.y = 531;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //Enable "Event Markings"
    p.x = 1162;
    p.y = 641;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //Refocus Mark Route Window
    p.x = 1058;
    p.y = 719;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //Open Marker Placement
    p.x = 1058;
    p.y = 793;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //move to marker placement slider
    p.x = 970;
    p.y = 858;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    
    //slide right
    p.x = 1070;
    p.y = 858;
    controller.drag_mouse(p,6000);
    
    //slide left
    p.x = 970;
    p.y = 858;
    controller.drag_mouse(p,6000);
    
    //slide right
    p.x = 1070;
    p.y = 858;
    controller.drag_mouse(p,6000);
    
    //slide left
    p.x = 1000;
    p.y = 858;
    controller.drag_mouse(p,6000);
    Sleep_For_N_Milliseconds(200);
    
    //click label box
    p.x = 1018;
    p.y = 880;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    // type into "Label Box"
    controller.type_something_at_presentation_speed("regenerate");
    
    //click "Apply"
    p.x = 1088;
    p.y = 880;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //switch to "Annotating Over a Route"
    p.x = 946;
    p.y = 746;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //get to end marker
    p.x = 1061;
    p.y = 812;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    
    //extend end marker
    p.x = 1080;
    p.y = 812;
    controller.drag_mouse(p,6000);
    
    //got to start marker
    p.x = 977;
    p.y = 812;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    
    //extend start marker
    p.x = 1041;
    p.y = 812;
    controller.drag_mouse(p,6000);
    
    //click label box
    p.x = 993;
    p.y = 832;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    // type into "Label Box"
    controller.type_something_at_presentation_speed("hotspot");
    
    //click "Apply"
    p.x = 1092;
    p.y = 832;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //close the mark route window
    p.x = 1352;
    p.y = 720;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //open Event View
    p.x = 1279;
    p.y = 753;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //show The Event View
    p.x = 1161;
    p.y = 758;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //open the Time
    p.x = 1206;
    p.y = 798;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //make it faster
    p.x = 1191;
    p.y = 825;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    
    p.x = 1150;
    p.y = 825;
    controller.drag_mouse(p,6000);
    
    
    
    
}