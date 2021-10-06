#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "mouse_data.h"
#include "mouse_utilities.h"
#include "mouse_configuration.h"

using namespace sf;

std::queue<Move_Event> gMouseEvents;

void Load_Queue_Based_On_New_Message(Mouse_State_Message const& message, unsigned long & last_click);
void Get_Event_From_Queue();


int main(){
  
  
  unsigned long last_click = Time_In_Milliseconds();
  while (true){
     
    //get a message when the mouse state changes (state being "up" / "down")
    //or when mouse is held down long enough to trigger a time out returning another mouse down
    Mouse_State_Message message = Block_Until_New_Mouse_State_Message();
    //std::cout << message << std::endl;
    
    Load_Queue_Based_On_New_Message(message,last_click);
    
    
    if (!gMouseEvents.empty()){
      std::cout << gMouseEvents.front() << std::endl;
      std::cout << gMouseEvents.size() << std::endl;
      gMouseEvents.pop();
    }
    
    //based the current message and the previous state data, determine what kind of event to load into the queue
    
  }

}

void Load_Queue_Based_On_New_Message(Mouse_State_Message const& message, unsigned long & last_click){

  static bool last_message_was_down = false;
  static bool double_clicked = false;
  
  if (message.state == MOUSE_DOWN){
    if (last_message_was_down){
      gMouseEvents.push(Move_Event(message.position,MOUSE_HELD));
    }else{
      if (Time_In_Milliseconds() - last_click <= MAX_DURATION_BETWEEN_DOUBLE _CLICK_MS){
        if (!double_clicked){
          gMouseEvents.push(Move_Event(message.position,MOUSE_DOUBLE_CLICKED));
          double_clicked = true;
        }else{
          gMouseEvents.push(Move_Event(message.position,MOUSE_CLICKED));
          double_clicked = false;
          last_click = Time_In_Milliseconds();
          }
      }else{
        gMouseEvents.push(Move_Event(message.position,MOUSE_CLICKED));
        double_clicked = false;
        last_click = Time_In_Milliseconds();
      }
    }
  }
  
    //sets whether the last message was down.  
    //used to determine the event of the next message
    last_message_was_down = (message.state == MOUSE_DOWN);  
}


