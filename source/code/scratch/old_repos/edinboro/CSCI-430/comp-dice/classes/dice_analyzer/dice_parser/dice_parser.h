#pragma once
#ifndef DICE_PARSER_H
#define DICE_PARSER_H

//#define DEBUG

#include <string>
#include <vector>
#include <map>
#include "../dice_tokens/dice_tokens.h"
#include "../../dice/dice.h"

//this should be a singleton class just like the scanner
class Dice_ParserT{

public:

	//all the scanning has been finished, so we're j̶u̶s̶t̶ ̶g̶o̶i̶n̶g̶ ̶t̶o̶ ̶p̶l̶a̶y̶ ̶w̶i̶t̶h̶ ̶i̶t̶e̶r̶a̶t̶o̶r̶s̶ ̶o̶f̶ ̶t̶h̶e̶ ̶v̶e̶c̶t̶o̶r̶
	//going to loop through the statement reducing and solving dice rolls.
	static void Parse(std::vector<std::pair<TokenT,std::string>> statement);

private:

	typedef std::vector<std::pair<TokenT,std::string>>::const_iterator token_iter;
	typedef std::vector<std::pair<TokenT,std::string>> Dice_StatementT;
	static std::map<std::string,DiceT> variable_map;
	static bool failed;
	static bool changed;

/*
//            _________________________
//           /                         \
//           | you call this a parser?  |
//           \_________________________/
//        _
//       / \
//       \_/
//
//     o        _.-````'-,_
//    _,.,_ ,-'`           `'-.,_
//  /)     (\                   '``-.
// ((      ) )                      `\
//  \)    (_/                        )\
//   |       /)           '    ,'    / \
//   `\^   ^'            '     (    /  ))
//     |      _/\ ,     /    ,,`\   (  "`
//      \Y,   |  \  \  | ````| / \_ \
//        `)_/    \  \  )    ( >  ( >
//                 \( \(     |/   |/
*///\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/


//1. resolve parenthese precedence
static Dice_StatementT Reduce_Parenthese_Expressions(token_iter begin, token_iter end);
static std::pair<TokenT,std::string> Expression_Solver(token_iter begin, token_iter end);
static int Solve_Expression(Dice_StatementT statement);
static bool Expression_Reduced (Dice_StatementT statement);

//2. reduce-solve-check, reduce-solve-check, ...
static void Reduce_And_Solve_Statement           (Dice_StatementT statement);
static bool Fully_Reduced                        (Dice_StatementT statement);


//specific solving and reducing
static Dice_StatementT Reduce_Dice_Operations         (Dice_StatementT statement);
static std::pair<TokenT,std::string> Do_Dice_Op       (std::pair<TokenT,std::string> op, std::pair<TokenT,std::string> dice);
static Dice_StatementT Solve_Integer_Expressions      (Dice_StatementT statement);
static Dice_StatementT Do_Multiplication_And_Division (Dice_StatementT statement);
static Dice_StatementT Do_Addition_And_Subtraction    (Dice_StatementT statement);
static Dice_StatementT Do_Assignments                 (Dice_StatementT statement);
static DiceT Do_Assignment                            (std::pair<TokenT,std::string> from, std::pair<TokenT,std::string> to);
static Dice_StatementT Roll_A_Dice                    (Dice_StatementT statement);

//Utility
static unsigned short Get_Left(std::string const& str);
static unsigned short Get_Right(std::string const& str);









/*
 *  Difficult to make first branch decision in grammar
 * 

static DiceT List_Dice              (token_iter it, token_iter const& end);
static DiceT Variable_Or_Assignment (token_iter it, token_iter const& end);
static DiceT Assignment             (token_iter it, token_iter const& end);
static DiceT ID                     (token_iter it, token_iter const& end);
static DiceT Dice_Factor            (token_iter it, token_iter const& end);
static DiceT Factor_Dice_Factor     (token_iter it, token_iter const& end);
static int   Dice_Evaluate          (token_iter it, token_iter const& end);
static int   Factor                 (token_iter it, token_iter const& end);
static int   P_Expression_P         (token_iter it, token_iter const& end);
static int   Expression             (token_iter&it, token_iter const& end);
static int   Expression_Plus_Term   (token_iter it, token_iter const& end);
static int   Expression_Minus_Term  (token_iter it, token_iter const& end);
static int   Term_Times_Factor      (token_iter it, token_iter const& end);
static int   Term_Divides_Factor    (token_iter it, token_iter const& end);


static int   Term                   (token_iter&it, token_iter const& end);

//look ahead to handle order of operations
static TokenT Closest_Operation (token_iter it, token_iter const& end);

//utility
static bool Add_Or_Sub(TokenT const& t);
static bool Mult_Or_Div(TokenT const& t);

//Error Handling
static void Error(std::initializer_list<TokenT> expected);
static void Error(std::pair<TokenT,std::string> const& recieved, std::initializer_list<TokenT> expected);
*/


//don't create a parser, just call the parse function
Dice_ParserT(void) = delete;
};
#endif
