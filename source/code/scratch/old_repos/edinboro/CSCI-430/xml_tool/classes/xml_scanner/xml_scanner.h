#pragma once
#ifndef XML_SCANNER_T_H
#define XML_SCANNER_T_H

#include <fstream>
#include <string>
#include <memory>
#include "xml_flex_scanner/xml_flex_scanner.h"
#include "../xml_tokens/xml_tokens.h"


class XML_ScannerT{

public:

	//Constructors
	explicit XML_ScannerT(std::ifstream & infile);

	//Continue Scanning.. (Transformer)
	void Analysis(void);

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
