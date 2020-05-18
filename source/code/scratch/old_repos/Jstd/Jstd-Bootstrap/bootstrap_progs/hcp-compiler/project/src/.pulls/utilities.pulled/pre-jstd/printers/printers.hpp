#pragma once
#include <string>
#include <iostream>


void Output_And_Flush(std::string const& message);

//should probably do generic streams also
template <typename Container>
void Print_Each_Element_On_A_Line(Container const& container){
  for (auto const& it: container){
    std::cout << it << '\n';
  }
  return;
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
void Print_Each_Element_To_A_File_On_A_Seperate__Line_With_No_Newline_After_The_Last_Line(Container const& container, std::string const& file_name){
  std::ofstream outfile(file_name);
  for (auto it = container.cbegin(); it != container.cend(); ++it){
    outfile << *it;
    if (it != container.cend()-1){
      outfile << '\n';
    }
  }
  return;
}
