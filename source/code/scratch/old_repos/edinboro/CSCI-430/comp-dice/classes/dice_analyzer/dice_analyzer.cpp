#include "dice_analyzer.h"

void Dice_Analyzer::Analyze(void){
	
	std::vector<std::pair<TokenT,std::string>> statement;
	
	//keep scanning and parsing till EOF
	std::cout << ">";
	statement = Scan();
	Dice_ParserT::Parse(statement);
	
	while(statement.back().first != TokenT::END){

		std::cout << ">";
		statement = Scan();
		Dice_ParserT::Parse(statement);
	}

	
	return;
}

std::vector<std::pair<TokenT,std::string>> Dice_Analyzer::Scan(void){
	
	//fill a vector of token/value pairs for each individual statement and then pass them
	//on to the parser.  This seems like an easy way to have a look-ahead buffer whithout
	//having the scanner and parser too intermingled.
	Dice_ScannerT dice_scanner;
	std::vector<std::pair<TokenT,std::string>> statement;
	
	//keep scanning till newline or EOF
	dice_scanner.Analyze();
	statement.push_back(std::pair<TokenT,std::string>(dice_scanner.Token(),dice_scanner.Value()));
	while(TokenT::NL != dice_scanner.Token() && TokenT::END != dice_scanner.Token()){
		
		//store a token/value pair
		dice_scanner.Analyze();
		statement.push_back(std::pair<TokenT,std::string>(dice_scanner.Token(),dice_scanner.Value()));
	}
	
	return statement;
}