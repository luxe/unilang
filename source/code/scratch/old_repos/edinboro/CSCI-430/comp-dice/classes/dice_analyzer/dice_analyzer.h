#pragma once
#ifndef DICE_ANALYZER_H
#define DICE_ANALYZER_H
#include <vector>
#include <string>
#include <utility>
#include "dice_scanner/dice_scanner.h"
#include "dice_tokens/dice_tokens.h"
#include "dice_parser/dice_parser.h"

class Dice_Analyzer{

public:

//Scan then Parse
//The analyzer gets data from the scanner and passes it to the parser
static void Analyze(void);

private:
static auto Scan(void) -> std::vector<std::pair<TokenT,std::string>>;


//don't create an analyzer, just call the analyze function
Dice_Analyzer(void) = delete;
};
#endif