#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "prettyprint.hpp"


template <typename T>
std::string Stream_Str(T const& t){
  std::stringstream ss;
  ss << t;
  return ss.str();
}

void Clear_Terminal();
void Clear_Terminal2();
void Clear_Terminal3();
void Move_Cursor_Up();
void Clear_Terminal_Up_N_Lines(int n);

void Output_And_Flush(std::string const& message);
void Maybe_Output_And_Flush(bool const& output, std::string const& message);
void Maybe_Output_And_Flush_With_Newline(bool const& output, std::string message);
void Maybe_Output_And_Flush(bool const& output, std::vector<std::string> const& v);
void Output_And_Flush_With_Newline(std::string const& message);
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
void Print_Elements_With_Comma_In_Between(Container const& container){
  for (auto it = container.cbegin(); it != container.cend(); ++it){
    std::cout << *it;
    if (it != container.cend()-1){
      std::cout << ", ";
    }
  }
}

template <typename Container>
std::string Elements_As_Square_Bracket_Comma_Seperated_List(Container const& container){
  std::stringstream ss;
  ss << "[";
  for (auto it = container.cbegin(); it != container.cend(); ++it){
    ss << *it;
    if (it != container.cend()-1){
      ss << ", ";
    }
  }
  
  ss << "]";
  return ss.str();
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
