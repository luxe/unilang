#include "dice_parser.h"
#include <algorithm>

//static variables
std::map<std::string,DiceT> Dice_ParserT::variable_map;
bool Dice_ParserT::failed;
bool Dice_ParserT::changed;

//the grammar
void Dice_ParserT::Parse(std::vector<std::pair<TokenT,std::string>> statement){
///////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG
	std::cout << "SCANNED: "; for (auto i: statement){std::cout << "[" << to_string(i.first) << "]";} std::cout << std::endl;
	#endif
///////////////////////////////////////////////////////////////////////////////////////
	failed = false;
	
	//reomve all parentheses from problem
	std::vector<std::pair<TokenT,std::string>> no_expressions {Reduce_Parenthese_Expressions(statement.begin(),statement.end())};
	
	//do a series of reductions until the statement
	//is a single integer or dice roll
	if (!failed){
		Reduce_And_Solve_Statement(no_expressions);
	}else {std::cout << "Malformed Expression\n";}

	failed = false;
	return;
}
void Dice_ParserT::Reduce_And_Solve_Statement(std::vector<std::pair<TokenT,std::string>> statement){
	bool solved = false;
	
	//output if reduced
	if (changed){
		if(Fully_Reduced(statement)){
			solved = true;
		}
	}
		
	while (!solved){
		changed = false;

		//all dice operations
		statement = Reduce_Dice_Operations(statement);

		//solve the first dice
		statement = Roll_A_Dice(statement);

		//all dice variable assignments
		statement = Do_Assignments(statement);

		//all integer expressions
		statement = Solve_Integer_Expressions(statement);
		
		//output if reduced
		if (changed){
			if(Fully_Reduced(statement)){
				solved = true;
			}
		}
		
		//did we make any changes? if not- then error
		if(!changed){
			std::cout << "Malformed Expression\n";
			solved = true;
		}
		
		
	}
	
	return;
}
std::vector<std::pair<TokenT,std::string>> Dice_ParserT::Reduce_Dice_Operations(std::vector<std::pair<TokenT,std::string>> statement){
	Dice_StatementT reduced;
	
	for (auto it = statement.cbegin(); it != statement.cend(); ++it){
		if (it+2 <= statement.cend()){
			if ((it->first == TokenT::MIN || it->first == TokenT::MAX || it->first == TokenT::SUM) && ((it+1)->first == TokenT::VARIABLE || (it+1)->first == TokenT::A) && ((it+2)->first != TokenT::EQUAL)){
				reduced.push_back(Do_Dice_Op(*it,*(it+1))); changed = true;
				it+=1;
			}else{
				reduced.push_back(*it);
			}
		}else{
			reduced.push_back(*it);
		}
	}
	
	return reduced;
}
std::vector<std::pair<TokenT,std::string>> Dice_ParserT::Solve_Integer_Expressions(std::vector<std::pair<TokenT,std::string>> statement){
	Dice_StatementT reduced;

	reduced = Do_Multiplication_And_Division(statement);
	reduced = Do_Addition_And_Subtraction(reduced);
	
	return reduced;
}
std::vector<std::pair<TokenT,std::string>> Dice_ParserT::Roll_A_Dice(std::vector<std::pair<TokenT,std::string>> statement){
	Dice_StatementT reduced;
	bool done{false};
	
	for (auto it = statement.begin(); it != statement.end(); ++it){
		if (it+2 < statement.end() && !done){
			
			//xdx
			if(it->first == TokenT::INTEGER && (it+1)->first == TokenT::DICE && (it+2)->first == TokenT::INTEGER){
				reduced.push_back(std::pair<TokenT,std::string>{TokenT::A,DiceT{atoi((it)->second.c_str()),atoi((it+2)->second.c_str())}.Str()});
				it+=2;
				done = true; changed = true;
			}
			
			//dx
			else if(it->first == TokenT::DICE && (it+1)->first == TokenT::INTEGER && ((it+2)->first != TokenT::MIN && (it+2)->first != TokenT::MAX && (it+2)->first != TokenT::SUM && (it+2)->first != TokenT::LPAREN)){
				reduced.push_back(std::pair<TokenT,std::string>{TokenT::A,DiceT{1,atoi((it+2)->second.c_str())}.Str()});
				it+=1;
				done = true; changed = true;
			}
			else{
				reduced.push_back(*it);
			}
		}
		else{
			reduced.push_back(*it);
		}
	}
	
	return reduced;
}
std::vector<std::pair<TokenT,std::string>> Dice_ParserT::Do_Assignments (Dice_StatementT statement){
	Dice_StatementT reduced;
	DiceT dice{0,0};
	reverse(statement.begin(),statement.end());
	
	
	for (auto it = statement.cbegin(); it != statement.cend(); ++it){
		if (it+2 < statement.cend()){
			if ( (it->first == TokenT::VARIABLE || it->first == TokenT::A) && ((it+1)->first == TokenT::EQUAL) && ((it+2)->first == TokenT::VARIABLE) ){
				dice = Do_Assignment(*it,*(it+2));
				it+=2;
				if (it+2 < statement.cend()){
					while( ((it+1)->first == TokenT::EQUAL) && ((it+2)->first == TokenT::VARIABLE)){
						dice = Do_Assignment(std::pair<TokenT,std::string>{TokenT::A,dice.Str()},*(it+2));
						it+=2;
					}
				}
				reduced.push_back(std::pair<TokenT,std::string>{TokenT::A,dice.Str()});
				changed = true;
			}
			
			else{
				reduced.push_back(*it);
			}
		}
		else{
			reduced.push_back(*it);
		}
	}
	
	
	
	
	
	reverse(reduced.begin(),reduced.end());
	return reduced;
}

DiceT Dice_ParserT::Do_Assignment(std::pair<TokenT,std::string> from, std::pair<TokenT,std::string> to){
	DiceT dice{0,0};
	
	//temp dice
	if (from.first == TokenT::A){
		//unsigned short left{Get_Left(from.second)};
		//unsigned short right{Get_Right(from.second)};
		dice = DiceT{from.second};
	}
	
	//real dice
	else{
		if (variable_map.find(from.second) != variable_map.end()){
			dice = variable_map.find(from.second)->second;
		}else{
			failed = true;
			std::cout << "Error bad ID\n";
		}
	}
	
	//do assignment
	variable_map.erase(to.second);
	variable_map.insert(std::pair<std::string,DiceT>(to.second,dice) );
	
	return dice;
}
bool Dice_ParserT::Fully_Reduced(Dice_StatementT statement){
	bool reduced{false};
	
	//only one token left plus an end token
	if (statement.size() == 2){
		
		//it's an integer
		if(statement[0].first == TokenT::INTEGER && (statement[1].first == TokenT::NL || statement[1].first == TokenT::END)){
			std::cout << statement[0].second << std::endl;
			reduced=true;
		}
		
		//it's a dice
		else if(statement[0].first == TokenT::A && (statement[1].first == TokenT::NL || statement[1].first == TokenT::END)){
			//unsigned short left{Get_Left(statement[0].second)};
			//unsigned short right{Get_Right(statement[0].second)};
			
			DiceT dice{statement[0].second};
			std::cout << dice << std::endl;
			reduced=true;
		}
		
		//it's a dice
		else if(statement[0].first == TokenT::VARIABLE && (statement[1].first == TokenT::NL || statement[1].first == TokenT::END)){
			DiceT dice(0,0);
			if (variable_map.find(statement[0].second) != variable_map.end()){
				dice = variable_map.find(statement[0].second)->second;
				std::cout << dice << std::endl;
			}else{
				std::cout << "Error bad ID\n";
			}
			reduced=true;
		}
		
		else{
			std::cout << "Malformed Expression\n";
			reduced=true;
		}
	}
	
	return reduced;
}



std::pair<TokenT,std::string> Dice_ParserT::Do_Dice_Op(std::pair<TokenT,std::string> op, std::pair<TokenT,std::string> id){
	std::pair<TokenT,std::string> token;
	
	int num{0};
	DiceT dice(0,0);
	
	//Get the dice
	if (id.first == TokenT::VARIABLE){
		if (variable_map.find(id.second) != variable_map.end()){
			dice = variable_map.find(id.second)->second;
		}else{
			failed = true;
			std::cout << "Error bad ID\n";
		}
	}
	else{
		//unsigned short left{Get_Left(id.second)};
		//unsigned short right{Get_Right(id.second)};
		dice = DiceT{id.second};
	}
	
	//do the calculation
	switch(op.first){
		case TokenT::MIN: num=dice.Min(); break;
		case TokenT::MAX: num=dice.Max(); break;
		case TokenT::SUM: num=dice.Sum(); break;
		default:;
	}
	
	return std::pair<TokenT,std::string>{TokenT::INTEGER,std::to_string(num)};
}
std::vector<std::pair<TokenT,std::string>> Dice_ParserT::Do_Multiplication_And_Division (Dice_StatementT statement){
	
	//Dear future self,
	//I am so sorry
	Dice_StatementT reduced;
	int num{0};
	for (auto it = statement.cbegin(); it != statement.cend(); ++it){
		if (it+2 < statement.cend()){
			if ( (it->first == TokenT::INTEGER) && ((it+1)->first == TokenT::TIMES || (it+1)->first == TokenT::DIVIDE ) && ((it+2)->first == TokenT::INTEGER) ){
				if((it+1)->first == TokenT::TIMES){
					num = (atoi(it->second.c_str())) * (atoi((it+2)->second.c_str()));
				}
				else{
					num = (atoi(it->second.c_str())) / (atoi((it+2)->second.c_str()));
				}
				it+=2;
				if (it+2 < statement.cend()){
					while( ((it+1)->first == TokenT::TIMES || (it+1)->first == TokenT::DIVIDE) && ((it+2)->first == TokenT::INTEGER)){
						if((it+1)->first == TokenT::TIMES){
						num *=  (atoi((it+2)->second.c_str()));
						}
						else{
						num /=  (atoi((it+2)->second.c_str()));
						}
						it+=2;
					}
					//--it;
				}
				
				reduced.push_back(std::pair<TokenT,std::string>{TokenT::INTEGER,std::to_string(num)});
				changed = true;
				num=0;
			}
			else{
				reduced.push_back(*it);
			}
		}
		else{
			reduced.push_back(*it);
		}
	}
	return reduced;
}
std::vector<std::pair<TokenT,std::string>> Dice_ParserT::Do_Addition_And_Subtraction    (Dice_StatementT statement){
	
	Dice_StatementT reduced;
	int num{0};
	for (auto it = statement.cbegin(); it != statement.cend(); ++it){
		if (it+2 < statement.cend()){
			if ( (it->first == TokenT::INTEGER) && ((it+1)->first == TokenT::PLUS || (it+1)->first == TokenT::MINUS ) && ((it+2)->first == TokenT::INTEGER) ){
				if((it+1)->first == TokenT::PLUS){
					num = (atoi(it->second.c_str())) + (atoi((it+2)->second.c_str()));
				}
				else{
					num = (atoi(it->second.c_str())) - (atoi((it+2)->second.c_str()));
				}
				it+=2;
				if (it+2 < statement.cend()){
					while( ((it+1)->first == TokenT::PLUS || (it+1)->first == TokenT::MINUS) && ((it+2)->first == TokenT::INTEGER)){
						if((it+1)->first == TokenT::PLUS){
						num +=  (atoi((it+2)->second.c_str()));
						}
						else{
						num -=  (atoi((it+2)->second.c_str()));
						}
						it+=2;
					}
					//--it;
				}
				
				reduced.push_back(std::pair<TokenT,std::string>{TokenT::INTEGER,std::to_string(num)});
				changed = true;
				num=0;
			}
			else{
				reduced.push_back(*it);
			}
		}
		else{
			reduced.push_back(*it);
		}
	}
	return reduced;
}


//1. resolve parenthese precedence
std::vector<std::pair<TokenT,std::string>> Dice_ParserT::Reduce_Parenthese_Expressions(token_iter begin, token_iter end){

	std::vector<std::pair<TokenT,std::string>> no_expressions;
	std::pair<TokenT,std::string> integer;
	int nested_level{0};
	auto ptr = begin;
	for (auto it = ptr; it != end; ++it){
		
		
		//left parenthese
		if (TokenT::LPAREN == it->first){

			if (0 == nested_level){
				ptr = it;
			}

			++nested_level;
		}
		
		
		//right parenthese
		else if (TokenT::RPAREN == it->first){
			--nested_level;

			if (0 == nested_level){
				integer = Expression_Solver(ptr,it);
				no_expressions.push_back(integer);
				ptr = it+1;
			}
			
		//outside expression
		}else{
			
			if (0 == nested_level){
				no_expressions.push_back(*it);
			}
		}
		
		

	}
	return no_expressions;

}
std::pair<TokenT,std::string> Dice_ParserT::Expression_Solver(token_iter begin, token_iter end){
	
	if (begin == end){
		return std::pair<TokenT,std::string>(TokenT::INTEGER,begin->second);
	}
	
	
	std::vector<std::pair<TokenT,std::string>> no_expressions;
	std::pair<TokenT,std::string> integer;
	int nested_level{0};
	auto ptr = begin;
	for (auto it = ptr; it != end; ++it){
		
		//left parenthese
		if (TokenT::LPAREN == it->first){

			if (0 == nested_level){
				ptr = it;
			}

			++nested_level;
		}
		
		
		//right parenthese
		else if (TokenT::RPAREN == it->first){
			--nested_level;

			if (0 == nested_level){
				integer = Expression_Solver(ptr,it);
				no_expressions.push_back(integer);
				ptr = it+1;
			}
		}else{
			no_expressions.push_back(*it);
		}
	}
	return std::pair<TokenT,std::string>(TokenT::INTEGER,std::to_string(Solve_Expression(no_expressions)));
}
int Dice_ParserT::Solve_Expression(std::vector<std::pair<TokenT,std::string>> statement){
		
	bool solved = false;
	while (!solved){

		changed = false;
		//all dice operations
		statement = Reduce_Dice_Operations(statement);
		
		//solve the first dice
		statement = Roll_A_Dice(statement);
		
		//all dice variable assignments
		statement = Do_Assignments(statement);
		
		//all integer expressions
		statement = Solve_Integer_Expressions(statement);
	
		//return integer if reduced
		if (changed){
			if (statement.size() == 1){
				if (statement[0].first == TokenT::INTEGER){
					solved = true;
				}
			}
		}
		
		//did we make any changes? if not- then error
		if(!changed){
			std::cout << "Malformed Expression\n";
			solved = true;
		}
		
		
		
	}
	
	return atoi(statement[0].second.c_str());
}

//Utility
unsigned short Dice_ParserT::Get_Left(std::string const& str){
	std::string temp;
	for (auto it: str){
		if (' ' == it){
			return (unsigned short)atoi(temp.c_str());
		}
		temp+=it;
	}
	return (unsigned short)atoi(temp.c_str());
}
unsigned short Dice_ParserT::Get_Right(std::string const& str){
	std::string temp;
	bool space = false;
	for (auto it: str){
		if (space){
			temp+=it;
		}
		if (' ' == it){
			space = true;
		}
	}
	return (unsigned short)atoi(temp.c_str());
}

/*
int Dice_ParserT::Dice_Evaluate(token_iter it, token_iter const& end){
///////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG
	std::cout << "\t[DICE_EVALUATION]->" << to_string(it->first) << std::endl;
	#endif
///////////////////////////////////////////////////////////////////////////////////////
	//get a dice list
	DiceT dice{List_Dice(it+1,end)};

	//do the calculation
	int num{0};
	switch(it->first){
		case TokenT::MIN: num=dice.Min(); break;
		case TokenT::MAX: num=dice.Max(); break;
		case TokenT::SUM: num=dice.Sum(); break;
		default:;
	}

	return num;
}
DiceT Dice_ParserT::List_Dice(token_iter it, token_iter const& end){
///////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG
	std::cout << "\t[DICE_LIST]->" << to_string(it->first) << std::endl;
	#endif
///////////////////////////////////////////////////////////////////////////////////////
	if (it <= end){
		switch(it->first){
			case TokenT::VARIABLE: return Variable_Or_Assignment(it,end);
			case TokenT::DICE: return Dice_Factor(it,end);
			default: return Factor_Dice_Factor(it,end);
		}
	}else{
		Error({TokenT::VARIABLE,TokenT::DICE,TokenT::INTEGER,TokenT::LPAREN,TokenT::MAX,TokenT::MIN,TokenT::SUM});
	}
	return DiceT(0,0);
}
DiceT Dice_ParserT::Variable_Or_Assignment(token_iter it, token_iter const& end){
///////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG
	std::cout << "\t[Variable_Or_Assignment]->" << to_string(it->first) << std::endl;
	#endif
///////////////////////////////////////////////////////////////////////////////////////
	DiceT dice(0,0);

	if ((it+1) <= end){
		if ((it+1)->first == TokenT::EQUAL){
			dice = Assignment(it,end);
		}else{
			dice = ID(it,end);
		}

	}else{
		Error({});
	}
	return dice;
}
DiceT Dice_ParserT::Assignment(token_iter it, token_iter const& end){
///////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG
	std::cout << "\t[Assignment]->" << to_string(it->first) << std::endl;
	#endif
///////////////////////////////////////////////////////////////////////////////////////
	DiceT dice{List_Dice(it+2,end)};
	variable_map.erase(it->second);
	variable_map.insert(std::pair<std::string,DiceT>(it->second,dice) );
	return dice;
}
DiceT Dice_ParserT::ID(token_iter it, token_iter const& end){
///////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG
	std::cout << "\t[ID]->" << to_string(it->first) << std::endl;
	#endif
///////////////////////////////////////////////////////////////////////////////////////
	DiceT dice(0,0);
	if (variable_map.find(it->second) != variable_map.end()){
		dice = variable_map.find(it->second)->second;
	}else{
		failed = true;
		std::cout << "Error bad ID\n";
	}

	return dice;
}
DiceT Dice_ParserT::Dice_Factor(token_iter it, token_iter const& end){
///////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG
	std::cout << "\t[Dice_Factor]->" << to_string(it->first) << std::endl;
	#endif
///////////////////////////////////////////////////////////////////////////////////////
	int factor{Factor(it+1,end)};


	return DiceT(1,factor);
}
DiceT Dice_ParserT::Factor_Dice_Factor(token_iter it, token_iter const& end){
///////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG
	std::cout << "\t[Factor_Dice_Factor]->" << to_string(it->first) << std::endl;
	#endif
///////////////////////////////////////////////////////////////////////////////////////
	int factor1{Factor(it,end)};
	if (it+1 <= end){
		if((it+1)->first != TokenT::DICE){
		Error(*(it+1),{TokenT::DICE});
		}
	}else{
		Error({TokenT::INTEGER,TokenT::LPAREN});
	}

	int factor2{0};
	if (it+2 <= end){
		factor2 = Factor(it+2,end);
	}
	else{
		Error({TokenT::INTEGER,TokenT::LPAREN});
	}

	return DiceT(factor1,factor2);
}
int Dice_ParserT::Factor(token_iter it, token_iter const& end){
///////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG
	std::cout << "\t[Factor]->" << to_string(it->first) << std::endl;
	#endif
///////////////////////////////////////////////////////////////////////////////////////

	int num{0};
	switch(it->first){
		case TokenT::INTEGER: num = atoi(it->second.c_str()); break;
		case TokenT::LPAREN: num = P_Expression_P(it+1,end); break;
		case TokenT::MAX:
		case TokenT::MIN:
		case TokenT::SUM: num = Dice_Evaluate(it,end); break;
		default: Error(*it,{TokenT::INTEGER,TokenT::LPAREN,TokenT::MAX,TokenT::MIN,TokenT::SUM});
	}


	return num;
}
int Dice_ParserT::P_Expression_P (token_iter it, token_iter const& end){
///////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG
	std::cout << "\t[(EXPRESSION)]->" << to_string(it->first) << std::endl;
	#endif
///////////////////////////////////////////////////////////////////////////////////////
	int i{0};
	switch(it->first){
		case TokenT::MAX:
		case TokenT::MIN:
		case TokenT::SUM:
		case TokenT::INTEGER: i = Expression(it,end); break;
		default: Error(*it,{TokenT::INTEGER,TokenT::MAX,TokenT::MIN,TokenT::SUM});
	}

	if (it->first != TokenT::RPAREN){
		Error(*it,{TokenT::RPAREN});
	}

	return i;
}
int Dice_ParserT::Expression (token_iter & it, token_iter const& end){
///////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG
	std::cout << "\t[EXPRESSION]->" << to_string(it->first) << std::endl;
	#endif
///////////////////////////////////////////////////////////////////////////////////////
	int i{0};
	TokenT op;
	switch(it->first){
		case TokenT::INTEGER:
		case TokenT::MAX:
		case TokenT::MIN:
		case TokenT::SUM:
		case TokenT::LPAREN:

			//find the next operation
			op = Closest_Operation(it,end);

			//expr plus term
			if (op == TokenT::PLUS){
				i = Expression_Plus_Term(it,end);
			}

			//expr minus term
			else if(op == TokenT::MINUS){
				i = Expression_Minus_Term(it,end);
			}

			//term times factor
			else if(op == TokenT::TIMES){
				i = Term_Times_Factor(it,end);
			}

			//term divides factor
			else if(op == TokenT::DIVIDE){
				i = Term_Divides_Factor(it,end);
			}

			//factor
			else{
				i = Factor(it,end);
			} break;
		default: Error(*it,{TokenT::INTEGER,TokenT::MAX,TokenT::MIN,TokenT::SUM,TokenT::LPAREN});

	}

	return i;
}
int Dice_ParserT::Expression_Plus_Term(token_iter it, token_iter const& end){
///////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG
	std::cout << "\t[Expression_Plus_Term]->" << to_string(it->first) << std::endl;
	#endif
///////////////////////////////////////////////////////////////////////////////////////
	return 5;
}
int Dice_ParserT::Expression_Minus_Term(token_iter it, token_iter const& end){
///////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG
	std::cout << "\t[Expression_Minus_Term]->" << to_string(it->first) << std::endl;
	#endif
///////////////////////////////////////////////////////////////////////////////////////
	return 5;
}
int Dice_ParserT::Term_Times_Factor(token_iter it, token_iter const& end){
///////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG
	std::cout << "\t[Term_Times_Factor]->" << to_string(it->first) << std::endl;
	#endif
///////////////////////////////////////////////////////////////////////////////////////
	return 5;
}
int Dice_ParserT::Term_Divides_Factor(token_iter it, token_iter const& end){
///////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG
	std::cout << "\t[Term_Divides_Factor]->" << to_string(it->first) << std::endl;
	#endif
///////////////////////////////////////////////////////////////////////////////////////
	return 5;
}

//look ahead to handle order of operations
TokenT Dice_ParserT::Closest_Operation (token_iter it, token_iter const& end){

	TokenT token = TokenT::UNKNOWN;
	while(it <= end){
		switch(it->first){
			case TokenT::PLUS:
			case TokenT::MINUS:
			case TokenT::TIMES:
			case TokenT::DIVIDE:
				return it->first;
			default:;
		}
		++it;
	}

	return token;

}

//utility
bool Dice_ParserT::Add_Or_Sub(TokenT const& t){
	bool add_or_sub = false;
	if (t == TokenT::PLUS or t == TokenT::MINUS){
		add_or_sub = true;
	}
	return add_or_sub;
}
bool Dice_ParserT::Mult_Or_Div(TokenT const& t){
	bool mult_or_div = false;
	if(t == TokenT::TIMES or t == TokenT::DIVIDE){
		mult_or_div = true;
	}
	return mult_or_div;
}

//Error Handling
void Dice_ParserT::Error(std::initializer_list<TokenT> expected){

	if (!failed){
		failed = true;
		std::cout << "unexpected end of expression.\n";
		std::cout << "Expected:\n";
		for (auto& value : expected){
			std::cout << '\t' << to_string(value) << '\n';
		}
	}
	return;
}
void Dice_ParserT::Error(std::pair<TokenT,std::string> const& recieved, std::initializer_list<TokenT> expected){

	if (!failed){
		failed = true;
		std::cout << "Syntax Error\n";
		std::cout << "Recieved: " << recieved.second << '\n';
		std::cout << "Expected:\n";
		for (auto& value : expected){
			std::cout << '\t' << to_string(value) << '\n';
		}
	}

	return;
}
*/











