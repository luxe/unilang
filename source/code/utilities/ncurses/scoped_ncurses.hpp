#pragma once

class ScopedNcurses
{
public:
  ScopedNcurses()
  {
    initscr();
    keypad(stdscr, TRUE);
    noecho(); 

  ~ScopedNcurses()
  {
    endwin();
  }

};