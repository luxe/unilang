#include <iostream>
#include "dice_scanner.h"
using namespace std;

//Constructor
Dice_ScannerT::Dice_ScannerT(void)
: lexer {new yyFlexLexer()}
, token{TokenT::UNKNOWN}
{}

//Continue Scanning.. (Transformer)
void Dice_ScannerT::Analyze(void){

	//refresh token and value with new data
	token = TokenT(lexer->yylex());
	value = lexer->YYText();

	return;
}

//Observers
TokenT Dice_ScannerT::Token(void) const{
	return token;
}
std::string Dice_ScannerT::Value(void) const{
	return value;
}
