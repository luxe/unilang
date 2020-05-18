#include <iostream>
#include "xml_scanner.h"
using namespace std;

//Constructor
XML_ScannerT::XML_ScannerT(ifstream & infile)
: lexer {new yyFlexLexer(&infile, &cout)}
, token{TokenT::UNKNOWN_TOKEN}
{}

//Continue Scanning.. (Transformer)
void XML_ScannerT::Analysis(void){

	//refresh token and value with new data
	token = TokenT(lexer->yylex());
	value = lexer->YYText();

	/*WARNING:
	after switching flex form c to c++, an anomaly occurs!
	for some reason, the "value" string contains a '<'
	prefix for all start tokens. I'm just going to eat it for now,
	but if the problem is fixed in the lex file, this if statement
	should be removed*/
	if(TokenT::START == token && value.size() > 0){
		value.erase(0,1);
	}
	
	return;
}

//Observers
TokenT XML_ScannerT::Token(void) const{
	return token;
}
std::string XML_ScannerT::Value(void) const{
	return value;
}
