#pragma once
#ifndef DICE_SCANNER_T_H
#define DICE_SCANNER_T_H

#include <fstream>
#include <string>
#include <memory>
#include "dice_flex_scanner/dice_flex_scanner.h"
#include "../dice_tokens/dice_tokens.h"

//WAIT, you're wrapping the flex class in ANOTHER class?
//I'm still getting use to what all flex can do, yes.
//NOTE: this should be a singleton
class Dice_ScannerT{

public:

	//Constructors
	explicit Dice_ScannerT(void);

	//Continue Scanning.. (Transformer)
	void Analyze(void);

	//Observers
	TokenT Token(void) const;
	std::string Value(void) const;

private:

	//A lexical analyzer and the data it collects
	std::unique_ptr<FlexLexer> lexer;
	TokenT token;
	std::string value;


};
#endif
