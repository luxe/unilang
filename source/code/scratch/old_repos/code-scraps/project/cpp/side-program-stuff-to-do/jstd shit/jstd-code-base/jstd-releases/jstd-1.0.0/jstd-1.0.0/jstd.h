//the J standard
#ifndef JSTD_H
#define JSTD_H
#include <string>

namespace jstd
{

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

}
#endif // JSTD_H
