#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "code/utilities/printers/prettyprint.hpp"



void Clear_Terminal();
void Clear_Terminal2();
void Clear_Terminal3();
void Move_Cursor_Up();
void Clear_Terminal_Up_N_Lines(int n);

void Output_And_Flush(std::string const& message);
void Print_Newline();

//prints all parameters with std::cout
//WAIT FOR BETTER ADOPTION
//template<typename ...Args>
//void Print(Args&&... args) {
//    (std::cout << ... << args);
//}

//should probably do generic streams also
template <typename Container>
void Print_Each_Element_On_A_Line(Container const& container){
  for (auto const& it: container){
    std::cout << it << '\n';
  }
  return;
}

template <typename Container>
void Print_Elements_With_Spaces_In_Between(Container const& container){
  for (auto it = container.cbegin(); it != container.cend(); ++it){
    std::cout << *it;
    if (it != container.cend()-1){
      std::cout << ' ';
    }
  }
}

template <typename Container>
void Print_Each_Element_On_A_Line_With_No_Newline_After_Last_Line(Container const& container){
  for (auto it = container.cbegin(); it != container.cend(); ++it){
    std::cout << *it;
    if (it != container.cend()-1){
      std::cout << '\n';
    }
  }
  return;
}
template <typename Container>
void Print_Each_Element_To_A_File_On_A_Seperate_Line(Container const& container, std::string const& file_name){
  std::ofstream outfile(file_name);
  for (auto const& it: container){
    outfile << it << '\n';
  }
  return;
}
template <typename Container>
void Print_Each_Element_To_A_File_On_A_Seperate_Line_With_No_Newline_After_The_Last_Line(Container const& container, std::string const& file_name){
  std::ofstream outfile(file_name);
  for (auto it = container.cbegin(); it != container.cend(); ++it){
    outfile << *it;
    if (it != container.cend()-1){
      outfile << '\n';
    }
  }
  return;
}
