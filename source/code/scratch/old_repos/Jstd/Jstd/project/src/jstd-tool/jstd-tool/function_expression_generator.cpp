#include "function_expression_generator.hpp"

#include "function_expression_scanner.hpp"
#include "function_expression_parser.hpp"

//constructors
Function_Expression_Generator::Function_Expression_Generator(std::string const& expression){
	auto tokens = Function_Expression_Scanner::Scan(expression);
	m_parse_tree = Function_Expression_Parser::Parse(tokens,amount);
}
Function_Expression_Generator::Function_Expression_Generator(){}
	
//transformer
void Function_Expression_Generator::Set_New_Expression(std::string const& expression){
	auto tokens = Function_Expression_Scanner::Scan(expression);
	m_parse_tree = Function_Expression_Parser::Parse(tokens,amount);
}
	
//observers
unsigned int Function_Expression_Generator::Get_Count(){
	return amount;
}
std::vector<std::string> Function_Expression_Generator::Get_Generations(){
	return Generate(m_parse_tree);
}
std::vector<std::string> Function_Expression_Generator::Generate(std::vector<std::vector<Function_Expression_Node>> const& parse_tree){
	std::vector<std::string> results;
	std::vector<std::string> more;
	
	for (auto it: parse_tree){
		more = Sub_Generate(it);
		results.insert(results.end(), more.begin(), more.end());
	}
	
	return results;
}
std::vector<std::string> Function_Expression_Generator::Sub_Generate(std::vector<Function_Expression_Node> const& nodes){
	std::vector<std::string> results;
	std::vector<std::string> more;
	std::vector<std::string> new_results;
	
	results.push_back("");
	for (auto it: nodes){
		if (!it.more){
			for (auto & result: results){
				result+=it.value;
			}
		}
		else{
			more = Generate(it.children);
			for (auto m: more){
				for (auto r: results){
					new_results.push_back(r+m);
				}
			}
			more.clear();
			results = new_results;
			new_results.clear();
		}
	}
	
	return results;
}
