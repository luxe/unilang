//Configuration dealing with delays and timeouts for mouse events.  
//helps determine when "double click" and "hold" events occur.

#pragma once

//how fast must we click to trigger a "double click" event
static const unsigned int MAX_DURATION_BETWEEN_DOUBLE_CLICK_MS = 500;

//how long must we hold to trigger a "hold" event
static const unsigned int MIN_DURATION_OF_MOUSE_HOLD_MS = 2000;
