#pragma once
#include "mouse_configuration.h"
#include <sys/time.h>

//utility
Mouse_State_Message Block_Until_New_Mouse_State_Message();
sf::Vector2i Block_Until_Mouse_Click();
sf::Vector2i Block_Until_New_Mouse_State();
sf::Vector2i Get_Mouse_Position_And_Toggle_State(MOUSE_STATE & state);
void Handle_New_Mouse_State(MOUSE_STATE const& current_state, MOUSE_STATE const& new_state, sf::Vector2i & position, bool & state_changed);
void Toggle_Mouse_State(MOUSE_STATE & state);
void Handle_Potential_Timeout(sf::Vector2i & position, bool & state_changed, unsigned long const& last_press_time, unsigned int max_duration);
unsigned int Time_In_Milliseconds();


//utility
void Toggle_Mouse_State(MOUSE_STATE & state){
  
  //toggle the mouse state passed in
  //this hangles the toggle state change
  if (state == MOUSE_UP){
    state = MOUSE_DOWN;
  }
  else if(state == MOUSE_DOWN){
    state = MOUSE_UP;
  }
}

sf::Vector2i Get_Mouse_Position_And_Toggle_State(MOUSE_STATE & state){

  //toggles the state position of the mouse
  Toggle_Mouse_State(state);
  
  //returns the position where the mouse was pressed or released
  return sf::Mouse::getPosition();
}

void Handle_New_Mouse_State(MOUSE_STATE & current_state, MOUSE_STATE const& new_state, sf::Vector2i & position, bool & state_changed){

  //detmine if the mouse has changed state.  
  //if so adjust the other input parameters
  if (current_state != new_state){
    position = Get_Mouse_Position_And_Toggle_State(current_state);
    state_changed = true;
  }
}

sf::Vector2i Block_Until_New_Mouse_State(){

    //the current state of the mouse
    static MOUSE_STATE state = MOUSE_UP;
    
    //the position returned as to where the mouse was clicked / released
    sf::Vector2i position;
    
    //flag to determine when the mouse state has changed
    //this is used to break out of the infinite loop, since this is a blocking call.
    bool state_changed = false;
    
    //infinitely wait, until we have a change in mouse state
    //when we do have a mouse state, adjust are internal mouse state,
    //and return the position to the user.
    while (!state_changed){
    
      //handle the change in mouse state while the mouse is currently down
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      {
          Handle_New_Mouse_State(state,MOUSE_DOWN,position,state_changed);
      }
      
      //handle the change in mouse state while the mouse is up
      else{
          Handle_New_Mouse_State(state,MOUSE_UP,position,state_changed);
      }
    }
    
    //the while loop will eventually break out,
    //when one of the handle functions determines a change in state
    return position;
}



sf::Vector2i Block_Until_Mouse_Click(){

    //the current state of the mouse
    static MOUSE_STATE state = MOUSE_UP;
    
    //the position returned as to where the mouse was clicked
    sf::Vector2i position;
    
    //flag to determine when the mouse state has changed
    //this is used to break out of the infinite loop, since this is a blocking call.
    bool state_changed = false;
    
    //infinitely wait, until we have a mouse click
    //when we do have a mouse click, adjust are internal mouse state,
    //and return the position to the user.
    while (!state_changed){
      
      //handle the change in mouse state while the mouse is currently down
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      {
        Handle_New_Mouse_State(state,MOUSE_DOWN,position,state_changed);
      }
      
      //we never return if the mouse is up
      else{
        state = MOUSE_UP;
      }
    }
    
    //the while loop will eventually break out,
    //when a determine a new mouse click has occured
    return position;
}

Mouse_State_Message Block_Until_New_Mouse_State_Message(){

    //the current state of the mouse
    static MOUSE_STATE state = MOUSE_UP;
    static unsigned long last_press_time = Time_In_Milliseconds();
    
    //the position returned as to where the mouse was clicked / released
    sf::Vector2i position;
    
    //flag to determine when the mouse state has changed
    //this is used to break out of the infinite loop, since this is a blocking call.
    bool state_changed = false;
    
    //infinitely wait, until we have a change in mouse state
    //when we do have a mouse state, adjust are internal mouse state,
    //and return the position to the user.
    while (!state_changed){
    
      //handle the change in mouse state while the mouse is currently down
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      {
          Handle_New_Mouse_State(state,MOUSE_DOWN,position,state_changed);
          if (!state_changed){
            Handle_Potential_Timeout(position,state_changed,last_press_time,MAX_DURATION_BETWEEN_DOUBLE_CLICK_MS);
          }
      }
      
      //handle the change in mouse state while the mouse is up
      else{
          Handle_New_Mouse_State(state,MOUSE_UP,position,state_changed);
      }
    }
    
    if (state == MOUSE_DOWN){
      last_press_time = Time_In_Milliseconds();
    }
    
    //the while loop will eventually break out,
    //when one of the handle functions determines a change in state
    return Mouse_State_Message(position,state,Time_In_Milliseconds());
}

void Handle_Potential_Timeout(sf::Vector2i & position, bool & state_changed, unsigned long const& last_press_time, unsigned int max_duration){
  if ((Time_In_Milliseconds() - last_press_time) >= max_duration){
      position = sf::Mouse::getPosition();
      state_changed = true;
  } 
}
unsigned int Time_In_Milliseconds(){
      timeval time;
      gettimeofday(&time, NULL);
      return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

