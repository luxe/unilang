%{
#include <string>
#include "../../dice_tokens/dice_tokens.h"

//problems liking if this is not here...
int yyFlexLexer::yywrap()   { return 1;}
%}
/*=================================================================================================================*/
/* Building Blocks
   These will help make building more complicated
   regular expressions easier */
   
DIGIT            [0-9]
LOWERCASE        [a-z]
UPPERCASE        [A-Z]
ALPHA            {UPPERCASE}|{LOWERCASE}
ALPHANUMBERIC    {ALPHA}|{DIGIT}
IDENTIFER_PART   {UPPERCASE}|{DIGIT}

/* Regular Expressions For Token Matching */
DICE_NOTATION    [Dd]
VARIABLE_NAME    {UPPERCASE}{IDENTIFER_PART}*
SUM              (?i:sum)
MAX              (?i:max)
MIN              (?i:min)
INTEGER          {DIGIT}+
ws		         [ \t\r]+
/*=================================================================================================================*/
%%
 /* Rules Section */
 
 /*oh! you have to have a space before these comments because you could have 
   a regular expression that looks like a comment */
 
 /* Return the appropriate tokens */
 /* Ya, I have to cast everything to an int. 
    I thought I was slick using an enum class of size char,
    but flex wants to return ints */
{ws}            {                                           }
{DICE_NOTATION} {return static_cast<int>(TokenT::DICE)     ;}
{VARIABLE_NAME} {return static_cast<int>(TokenT::VARIABLE) ;}
{SUM}           {return static_cast<int>(TokenT::SUM)      ;}
{MAX}           {return static_cast<int>(TokenT::MAX)      ;}
{MIN}           {return static_cast<int>(TokenT::MIN)      ;}
{INTEGER}       {return static_cast<int>(TokenT::INTEGER)  ;}
\n              {return static_cast<int>(TokenT::NL)       ;}
<<EOF>>         {return static_cast<int>(TokenT::END)      ;}
"("             {return static_cast<int>(TokenT::LPAREN)   ;}
")"             {return static_cast<int>(TokenT::RPAREN)   ;}
"+"             {return static_cast<int>(TokenT::PLUS)     ;}
"-"             {return static_cast<int>(TokenT::MINUS)    ;}
"*"             {return static_cast<int>(TokenT::TIMES)    ;}
"/"             {return static_cast<int>(TokenT::DIVIDE)   ;}
"="             {return static_cast<int>(TokenT::EQUAL)    ;}
.               {return static_cast<int>(TokenT::UNKNOWN)  ;}
 /*=================================================================================================================*/
%%

