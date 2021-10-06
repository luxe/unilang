#include "function_expression_parser.hpp"

bool Function_Expression_Parser::Is_Word(std::string const& it){
		return (it != "(" && it != "|" && it != ")");
	}
Function_Expression_Node Function_Expression_Parser::Recursive_Build(std::vector<std::string>::const_iterator & it, int & total){
	
	Function_Expression_Node sub_root("",true); //<- contains the full root
	std::vector<Function_Expression_Node> root;
	
	const auto begin = it;
	
	//calculate the amount
	std::vector<std::vector<int>> multiplies;
	std::vector<int> adds;
	int sub_amount = 1;
	
	while(*it != ")"){
		
		//when we see a "WORD", add it.
		if(Is_Word(*it)){
			root.push_back(Function_Expression_Node(*it));
		}
		
		//when we see a "(", build the subtree,
		else if (*it == "("){
			++it;
			root.push_back(Recursive_Build(it,sub_amount));
			
			//adds.push_back(sub_amount);
			//sub_amount = 1;
		}
		
		//else we see an "OR" and we do the split
		else{
			sub_root.children.push_back(root);
			root.clear();
			
			//store the sub amount
			adds.push_back(sub_amount);
			sub_amount = 1;
		}
		
		++it;
	}
	
	//add the last bit, if there is any
	if (!root.empty()){
		sub_root.children.push_back(root);
		
		//store the sub amount
		adds.push_back(sub_amount);
	}
	if (!adds.empty()){
		multiplies.push_back(adds);
	}
	
	
	//calculate sub total
	int or_count = 0;
	for (auto const& it: multiplies){
		for (auto const& it2: it){
			or_count+=it2;
		}
		
		if (or_count > 0){
			total*=or_count;
		}
		or_count = 0;
	}
	
	/*
	std::cout << "---SUB FUNCTION---\n";
	for (auto it: multiplies){for (auto it2: it){std::cout << "{" << it2 << "} ";}std::cout << "\n";}std::cout << "--\n";
	std::cout << total << std::endl << '\n';
	*/
	
	return sub_root;
}
std::vector<std::vector<Function_Expression_Node>> Function_Expression_Parser::Build_Parse_Tree(std::vector<std::string>::const_iterator & it, std::vector<std::string>::const_iterator const& end, unsigned int & amount){
	
	std::vector<std::vector<Function_Expression_Node>> full_root;
	std::vector<Function_Expression_Node> root;
	
	const auto begin = it;
	
	//calculate the amount
	std::vector<int> adds;
	int sub_amount = 1;
	int total = 0;
	
	while (it != end){
		
		//when we see a "WORD", add it.
		if(Is_Word(*it)){
			root.push_back(Function_Expression_Node(*it));
		}
		
		//when we see a "(", build the subtree,
		else if (*it == "("){
			++it;
			root.push_back(Recursive_Build(it,sub_amount));
			
		}
		
		//else we see an "OR" and we do the split
		else{
			full_root.push_back(root);
			root.clear();
			
			//store the sub amount
			adds.push_back(sub_amount);
			sub_amount = 1;
		}
		
		++it;
	}
	
	//add the last bit, if there is any
	if (!root.empty()){
		full_root.push_back(root);
		
		//store the sub amount
		adds.push_back(sub_amount);
		sub_amount = 1;
	}
	
	//calculate sub total
	for (auto const& it: adds){ total+=it; }
	
	/*
	std::cout << "---ROOT FUNCTION---\n";
	for (auto it: adds){std::cout << "[" << it << "] ";}std::cout << '\n';
	std::cout << total << std::endl << '\n';
	*/
	amount = total;
	
	return full_root;
}
std::vector<std::vector<Function_Expression_Node>> Function_Expression_Parser::Parse(std::vector<std::string> const& tokens, unsigned int & amount){

	auto it = tokens.cbegin();
	auto end = tokens.cend();
	auto parse_tree = Build_Parse_Tree(it,end,amount);
	return parse_tree;
}