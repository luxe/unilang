#include "function_expression_scanner.hpp"

std::vector<std::string> Function_Expression_Scanner::Scan(std::string const& expression){
	
	std::vector<std::string> tokens;
	std::string temp;
	
	for (auto const& it: expression){

		if (it == '('){
			tokens.push_back(temp);
			tokens.push_back("(");
			temp.clear();
		}

		else if (it == '|'){
			tokens.push_back(temp);
			tokens.push_back("|");
			temp.clear();
		}

		else if (it == ')'){
			tokens.push_back(temp);
			tokens.push_back(")");
			temp.clear();
		}

		else if (isalpha(it) || it == ' '){
			temp+=it;
		}

	}
		
	tokens.push_back(temp);

	return tokens;
	}