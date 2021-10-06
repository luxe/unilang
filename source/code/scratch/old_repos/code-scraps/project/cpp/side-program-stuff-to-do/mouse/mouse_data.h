//This contains two mouse messages, with their corresponding states/events.  
//One message is used internally to detect up/down changes over time.
//The other message is used as events for VDU processing.

#pragma once

#include <iostream>
#include <SFML/Window.hpp>

//the current state of the mouse
enum MOUSE_STATE{
  MOUSE_UP, MOUSE_DOWN
};

//converts mouse state to printable string
std::string to_string(MOUSE_STATE state){
  switch (state){
    case MOUSE_UP: return "UP";
    case MOUSE_DOWN: return "DOWN";
  }
}

//the derived mouse event based on mouse states, and time stamps
enum MOUSE_EVENT{
  MOUSE_CLICKED, MOUSE_HELD, MOUSE_DOUBLE_CLICKED
};

//converts mouse event to printable string
std::string to_string(MOUSE_EVENT state){
  switch (state){
    case MOUSE_CLICKED: return "CLICKED";
    case MOUSE_HELD: return "HELD";
    case MOUSE_DOUBLE_CLICKED: return "DOUBLE CLICKED";
  }
}

//the state of a mouse.
//these messages are created each time the mouse state changes
struct Mouse_State_Message{

  //data
  sf::Vector2i position;
  MOUSE_STATE state;
  unsigned long time;

  //constructor
  Mouse_State_Message(sf::Vector2i const& position, MOUSE_STATE const& state, unsigned long const& time)
  : position(position)
  , state(state)
  , time(time)
  {}

  //overload insertion
  friend std::ostream& operator<<(std::ostream& os, Mouse_State_Message const& self);
};

//printing message state message
std::ostream& operator<<(std::ostream& os, Mouse_State_Message const& message)
{   
    os << to_string(message.state) << " (" << message.position.x << "," << message.position.y << ") " << message.time;
    return os;
}

//derived from mouse state messages.  
//these events describe the higher level action taken by the mouse
//these are the messages intended to be processed by the VDUs
struct Move_Event{

  //data
  sf::Vector2i position;
  MOUSE_EVENT event;

  //constructor
  Move_Event(sf::Vector2i const& position, MOUSE_EVENT const& event)
  : position(position)
  , event(event)
  {}
  
  //overload insertion
  friend std::ostream& operator<<(std::ostream& os, Move_Event const& self);
};

//printing mouse event
std::ostream& operator<<(std::ostream& os, Move_Event const& message)
{   
    os << to_string(message.event) << " (" << message.position.x << "," << message.position.y << ") ";
    return os;
}
