#include <curses.h>
#include <menu.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

/*  This program was written by David Eck and modified by Scotty Orr
 *
 *  This program demonstrates "curses" mode.  It must be run on command line.
 *  When it is run, the console window is converted into a simple kind of
 *  GUI made up of rows and columns of characters.  In curses mode, the
 *  cursor can be moved to any character on the screen, and a character or
 *  string can be put there.  The appearance of the characters can be changed
 *  by setting several "attributes":  characters can be bold, they can be
 *  underlined, and they can be shown in reverse (with the foreground and
 *  background colors reversed.)  The getch() function can be used
 *  to read characters typed by the user.  In this demo program, the cursor
 *  is moved when the user presses an arrow key or the return key.  When
 *  the user types an ordinary printable character, it is output at the
 *  current cursor position.  The program also checks for several control
 *  chars in the input.  A CONTROL-X will end the program.  CONTROL-B will
 *  toggle the bold attribute.  (That is, after you press CONTROL-B,
 *  characters will be displayed in bold mode until you press CONTROL-B
 *  again.) Similarly, CONTROL-U toggles underline mode, and CONTROL-R
 *  toggles reverse mode.  CONTROL-N will return to normal characters.
 *  That is, it will make sure all the attributes are turned off.
 */

#include <ncurses.h>
#include <iostream>
using namespace std;

const char CTRL_B = 2;    // Define names for some control characters.
const char CTRL_R = 18;
const char CTRL_U = 21;
const char CTRL_X = 24;
const char CTRL_N = 14;

bool curses_started = false;  // This is set to true the first time
                              // the program enters curses mode.

void endCurses();
void startCurses();
void drawFrame(int, int, int, int);

int main() {

   cout << "\nThis program will demonstrate curses.  It will enter curses\n"
        << "mode when you press return.  You can type characters and use\n"
        << "the arrow keys to move around.  Press CONTROL-X to exit.\n"
        << "Use CONTROL-B, CONTROL-R, and CONTROL-U to go into bold,\n"
        << "reverse video, and underlined mode, respectively.\n\n"
        << "Press return to begin.\n";
   char response;
   cin.get(response);

   startCurses();                 // Enter curses mode.
   drawFrame(0,0,LINES-1,COLS-1); // Draw a frame around the whole window.
                                  // (The rest of the program will only use
                                  //   rows 1 to LINES-2 and columns 1 to
                                  //   COLS-1.  LINES and COLS are predefined
                                  //   variables.)
   move(LINES/2,COLS/2);          // Move cursor to center of window.

   int row,col;  // The current row and column of the cursor.
   
   bool bold = false;      // Is the BOLD attribute currently on?
   bool underline = false; // Is the UNDERLINE attribute currently on?
   bool reverse = false;   // Is the REVERSE attribute currently on?
   
   bool done = false;  // Will be set to true when the user presses
                       //   CONTROL-X.  This ends the loop and the program

   while (!done) { // Get one char from the user and process it.

      getyx(stdscr,row,col);  // Get the current cursor position.
      int ch = getch();       // Get the next character typed by the user.

      switch (ch){

         case CTRL_B:   // Toggle BOLD attribute if user types CONTROL-B
            bold = ! bold;
            if (bold)
               attron(A_BOLD);
            else
               attroff(A_BOLD);
            break;
         case CTRL_R:   // Toggle REVERSE attribute if user types CONTROL-R
            reverse = ! reverse;
            if (reverse)
               attron(A_REVERSE);
            else
               attroff(A_REVERSE);
            break;
         case CTRL_U:   // Toggle UNDERLINE attribute if user types CONTROL-U
            underline = ! underline;
            if (underline)
               attron(A_UNDERLINE);
            else
               attroff(A_UNDERLINE);
            break;
         case CTRL_N:   // Turn off all attributes if user types CONTROL-N
            attroff(A_BOLD);
            attroff(A_REVERSE);
            attroff(A_UNDERLINE);
            break;
         case CTRL_X:   // End the loop if user types CONTROL-X
            done = true;
            break;
         case '\n':     // User pressed RETURN.
            if (row < LINES-2)
               move(row+1,1);   // Move to beginning of next line.
            else
               move (row,1);    // On last line.  Move to start of the line.
            break;
         case KEY_UP:    // Move cursor up, unless already at top of window.
            if (row > 1)
               move(row-1,col);
            break;
         case KEY_DOWN:  // Move cursor down, unless already at bottom.
            if (row < LINES-2)
               move(row+1,col);
            break;
         case KEY_LEFT:  // Move cursor left, unless already at left edge.
            if (col > 1)
               move(row,col-1);
            break;
         case KEY_RIGHT: // Move cursor right, unless already at right edge.
            if (col < COLS-2)
               move(row,col+1);
            break;
         case KEY_BACKSPACE:  // User pressed the backspace key.
            if (col > 1) {  
                  // Cursor is not in the first column.
                  // Overwrite previous char with a space.
               move(row,col-1);
               addch(' ');
               move(row,col-1);
            }
            else if (row > 1) {
                  // Cursor was in the first column, but not on the
                  // first row.  Move to end of previous row and
                  // overwrite the last char on that row.
               move(row-1,COLS-2);
               addch(' ');
               move(row-1,COLS-2);
            }
            break;
         default:
            if (ch >= ' ' && ch <= 126) {
                  // The user typed a printable character.
                  // Put it at the current cursor position.  If that's
                  // the end of the row, move cursor to the next row
                  // (or, if already  on the last row, to the beginning
                  // of the row.)
               addch(ch);
               if (col == COLS-2) {
                  if (row < LINES-2)
                     move(row+1,1);
                  else
                     move(row,col);
               }
            }
            break;
            
      } // end switch
      
      refresh();  // Make sure any changes made become visible on screen.
      
   } // end while
   
   
} // end main()


//---------------------------------------------------------------
//           Support for entering and leaving curses mode
//---------------------------------------------------------------


/*
 * This will exit curses mode and return the console to the usual
 * line-oriented input/output mode.  If it is called when curses
 * mode is not in effect, it will have no effect.
 *
 */
void endCurses() {
   if (curses_started && !isendwin())
      endwin();
}

/*
 * This will put the console into curses mode.  If curses mode is being
 * entered for the first time, the screen will be cleared.  If it is 
 * being re-entered after a call to endCurses(), then the previous
 * screen contents will be restored.
 */
void startCurses() {
   if (curses_started) {
      refresh();
   }
   else {
      initscr();
      cbreak();
      noecho();
      intrflush(stdscr, false);
      keypad(stdscr, true);
      atexit(endCurses);  // Make sure endCurses() is called when program ends.
      curses_started = true;
   }
}

//---------------------------------------------------------------



/*
 * This routine draws a frame around a specified part of the console
 * screen, using special characters such as ACS_ULCORNER and ACS_VLINE.
 * The frame extends from startrow to endrow vertically and from
 * startcol to endcol horizontally.  (Rows and columns are numbered
 * starting from 0.)  Note that the interior of the frame extends
 * from startrow+1 to endrow-1 vertically and from startcol+1 to
 * endcol-1 horizontally.
 */
void drawFrame(int startrow, int startcol, int endrow, int endcol) {
   int saverow, savecol;
   getyx(stdscr,saverow,savecol);
   mvaddch(startrow,startcol,ACS_ULCORNER);
   for (int i = startcol + 1; i < endcol; i++)
      addch(ACS_HLINE);
   addch(ACS_URCORNER);
   for (int i = startrow +1; i < endrow; i++) {
      mvaddch(i,startcol,ACS_VLINE);
      mvaddch(i,endcol,ACS_VLINE);
   }
   mvaddch(endrow,startcol,ACS_LLCORNER);
   for (int i = startcol + 1; i < endcol; i++)
      addch(ACS_HLINE);
   addch(ACS_LRCORNER);
   move(saverow,savecol);
   refresh();
}


