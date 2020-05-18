#include <iostream>
#include "xml_tokens.h"

using namespace std;
bool HasNewString(TokenT const& token) {
	
	bool new_string{false};
	
	switch(token) {
		case TokenT::ENCODING:
		case TokenT::NAME:
		case TokenT::VALUE:
		case TokenT::START:
		case TokenT::COMMENT:
		case TokenT::DATA:
			new_string = true;
			break;
		default:;
    }
    
    return new_string;
}
string TokenTToString(TokenT const& token) {
    
	switch (token) {
       case TokenT::VERSION:
           return ("Version");
       case TokenT::ENCODING:
           return ("Encoding");
       case TokenT::SLASH:
           return ("Slash");
       case TokenT::EQ:
           return ("Equal");
       case TokenT::CLOSE:
           return ("Close");
       case TokenT::NAME:
           return ("Name");
       case TokenT::VALUE:
           return ("Value");
       case TokenT::ATTDEF:
           return ("Atrribute Definiation");
       case TokenT::COMMENT:
           return ("Comment");
       case TokenT::DATA:
           return ("Data");
       case TokenT::END:
           return ("End");
       case TokenT::ENDDEF:
           return ("End Definition");
       case TokenT::START:
           return ("Start");
       case TokenT::UNKNOWN_TOKEN:
       default:
           return ("Unknown Token");

    }
    return ("Unknown Token");
}
TokenT StringToTokenT(string s) {

	//lowercase string
     for(unsigned int i{0}; i<s.size(); ++i) {
        s[i] = char(tolower(s[i]));
     }

     if ("version" == s) {
         return TokenT::VERSION;
     } else if ("encoding" == s) {
         return TokenT::ENCODING;
     } else if ("slash" == s) {
         return TokenT::SLASH;
     } else if ("equal" == s) { 
         return TokenT::EQ;
     } else if ("close" == s) { 
         return TokenT::CLOSE;
     } else if ("name" == s) { 
         return TokenT::NAME;
     } else if ("value" == s) { 
         return TokenT::VALUE;
     } else if ("attribute definition" == s) {
         return TokenT::ATTDEF;
     } else if ("comment" == s) { 
         return TokenT::COMMENT;
     } else if ("data" == s) {
         return TokenT::DATA;
     } else if ("end" == s) {
         return TokenT::END;
     } else if ("End Definition" ==s) {
         return TokenT::ENDDEF;
     } else if ( "Start" ==s) {
           return TokenT::START;
     } else {
         return TokenT::UNKNOWN_TOKEN;
     }
     return TokenT::UNKNOWN_TOKEN;
}
bool Valid_Token(TokenT const& token){
	
	bool valid{true};
	switch (token){
		case TokenT::VERSION:
		case TokenT::ENCODING:
		case TokenT::ATTDEF:
		case TokenT::COMMENT:
		case TokenT::ENDDEF:
		case TokenT::UNKNOWN_TOKEN:
			valid =false;
			break;
		default:;
	}
	
	return valid;
}
ostream & operator << (ostream & out, TokenT const & t) {
      out << TokenTToString(t);
      return out;
}

