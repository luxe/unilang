#include "code/utilities/output/printers/lib.hpp"
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
void Maybe_Output_And_Flush(bool const& output, std::string const& message)
{
  if (output){
    Output_And_Flush(message);
  }
}
void Maybe_Output_And_Flush_With_Newline(bool const& output, std::string message)
{
  if (output){
    message += "\n";
    Output_And_Flush(message);
  }
}
void Maybe_Output_And_Flush(bool const& output, std::vector<std::string> const& v)
{
   if (output){
    std::cout << v << std::endl;
   }
}

void Output_And_Flush_With_Newline(std::string const& message){
  std::cout << message << std::endl;
}

void Print_Newline(){
  std::cout << "\n";
}
