//the J standard
#ifndef JSTD_H
#define JSTD_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <vector>
#include "templates.h"
#include "die/die.h"
#include "dice/dice.h"
namespace jstd
{
      const long double PI = 3.141592653589793238;
      
      std::string Upper(std::string str);
      //this function capitalizes an entire string
      //pre : send in a string
      //post : string is now capitalized
      
      std::string Lower(std::string str);
      //this function puts the entire string in lower case form
      //pre : send in a string
      //post : string is now in lower case
      
      std::string Title( std::string str);
      //this function puts an entire string in a grammatically correrct title form
      //pre: send in a string
      //post: string in now in a grammatical title form
      
      int Random(const int& num);
      //this function spits out a random number from 1 to the number sent in
      //pre: must send in number > 0
      //post: random number returned if preconditions are met, else 0 is returned
      
      int Random(const int& num1, const int& num2);
      //this function spits out a random number from first number sent in to second number sent in
      //pre: must send num2 > 0
      //post: random number returned if preconditions are met, else 0 is returned

      int StringToInt(const std::string& str);
      //this function converts a string into an int
      //pre: send in a string that is a integer
      //post:int returned 

      std::string IntToString(const int& num);
      //this function converts an int into a string
      //pre: send in an integer
      //post: string returned

      std::vector <std::string> ReadStrings(std::ifstream& fin);
      //this function reads each line of a find as a string and returns a vector 
      //pre: send in a valid ifstream
      //post: a vector is returned containing each line as an element 
      
}
#endif // JSTD_H
