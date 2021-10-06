#pragma once
#ifndef TOKENS
#define TOKENS

#include <string>
#include <ostream>

//NOTE: hmm.. not sure if I should have things like "OP" and then return values {'+','-','*','/','='} in flex
//I think it's better to have descriptive tokens for the time being. //A will hold a temp_dice
enum class TokenT : char {DICE, VARIABLE, MAX, MIN, SUM, INTEGER, LPAREN, RPAREN, PLUS, MINUS, TIMES, DIVIDE, EQUAL, NL, END, UNKNOWN, A};

//some helper functions
//(one day: make a program to auto-generate this kind of stuff!)
std::string to_string(TokenT const& t);
TokenT to_TokenT(std::string const& s);
std::ostream & operator << (std::ostream & out, TokenT const& t);
#endif
