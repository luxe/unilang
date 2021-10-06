#include "dice_tokens.h"

using namespace std;

//utilities
string to_string(TokenT const& token) {

	switch (token) {
       case TokenT::DICE:
           return ("Dice");
       case TokenT::VARIABLE:
           return ("Variable");
       case TokenT::MAX:
           return ("Max");
	   case TokenT::MIN:
           return ("Min");
	   case TokenT::SUM:
           return ("Sum");
       case TokenT::INTEGER:
           return ("Integer");
       case TokenT::LPAREN:
           return ("Left Paren");
       case TokenT::RPAREN:
           return ("Right Paren");
       case TokenT::PLUS:
           return ("Plus");
       case TokenT::MINUS:
           return ("Minus");
       case TokenT::TIMES:
           return ("Times");
       case TokenT::DIVIDE:
           return ("Divide");
       case TokenT::EQUAL:
           return ("Equal");
		case TokenT::NL:
			return ("newline");
		case TokenT::END:
			return ("eof");
		case TokenT::A:
			return("temp");
       case TokenT::UNKNOWN:
       default:
           return ("Unknown Token");

    }
    return ("Unknown Token");
}
TokenT to_TokenT(string s) {

	//lowercase the string
     for(unsigned int i{0}; i<s.size(); ++i) {
        s[i] = char(tolower(s[i]));
     }

     if ("dice" == s) {
         return TokenT::DICE;
     } else if ("variable" == s) {
         return TokenT::VARIABLE;
     } else if ("max" == s) {
         return TokenT::MAX;
     } else if ("min" == s) {
         return TokenT::MIN;
     } else if ("sum" == s) {
         return TokenT::SUM;
     } else if ("integer" == s) {
         return TokenT::INTEGER;
     } else if ("lparen" == s) {
         return TokenT::LPAREN;
     } else if ("rparen" == s) {
         return TokenT::RPAREN;
     } else if ("plus" == s) {
         return TokenT::PLUS;
     } else if ("minus" == s) {
         return TokenT::MINUS;
     } else if ("times" == s) {
         return TokenT::TIMES;
     } else if ("divide" == s) {
         return TokenT::DIVIDE;
     } else if ("equal" == s) {
         return TokenT::EQUAL;
	 } else if ("newline" == s) {
         return TokenT::NL;
	 } else if ("eof" == s) {
         return TokenT::END;
	 } else if ("temp" == s){
		 return TokenT::A;
	 }
     return TokenT::UNKNOWN;
}
ostream & operator << (ostream & out, TokenT const & t) {
      out << to_string(t);
      return out;
}

