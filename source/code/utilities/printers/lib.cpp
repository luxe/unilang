#include "code/utilities/printers/lib.hpp"
#include <iostream>
void Clear_Terminal()
{
    printf("\33[2J");
}
void Clear_Terminal2()
{
    printf("%c[2K", 27);
}
void Clear_Terminal3()
{
    printf("\33[2K\r");
}
void Move_Cursor_Up()
{
    printf("\x1b[A");
}
void Clear_Terminal_Up_N_Lines(int n)
{
    Clear_Terminal3();
    for (size_t i = 0; i < n; ++i){
        Move_Cursor_Up();
        Clear_Terminal3();
    }
}
void Output_And_Flush(std::string const& message){
  std::cout << message; std::cout.flush();
  return;
}
void Print_Newline(){
  std::cout << "\n";
}
