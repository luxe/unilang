%option 8bit nodefault yylineno
/* %option noyywrap */


%{
/*
 * WARNING: This is not an XML 1.0 parser, but an experiment with an XML-like
 * language. See http://www.w3.org/XML/9707/XML-in-C
 *
 * Author: Bert Bos <bert@w3.org>
 * Created: 9 July 1997
 *
 * Copyright (C) 1997-2000 World Wide Web Consortium
 * See http://www.w3.org/Consortium/Legal/copyright-software-19980720.html
 */
#include <iostream>
#include <string>
#include "../../xml_tokens/xml_tokens.h"

namespace flex_globals{
	std::string yylval;
}
using namespace flex_globals;
static int keep;			/* To store start condition */

int yyFlexLexer::yywrap()   { return 1;}
std::string word(char * s) {
	std::string rv;

   int i,k;
   for (k = 0; isspace(s[k]) || s[k] == '<'; k++) ;
   for (i = k; s[i] && ! isspace(s[i]); i++) {
      rv += s[i];
   }

	return rv;

}

%}

nl		(\r\n|\r|\n)
ws		[ \t\r\n]+
open		{nl}?"<"
close		">"{nl}?
namestart	[A-Za-z\200-\377_]
namechar	[A-Za-z\200-\377_0-9.-]
esc		"&#"[0-9]+";"|"&#x"[0-9a-fA-F]+";"|&{special}";"
name		{namestart}{namechar}*
data		([^<\n&]|\n[^<&]|\n{esc}|{esc})+
comment		{open}"!--"([^-]|"-"[^-])*"--"{close}
string		\"([^"&]|{esc})*\"|\'([^'&]|{esc})*\'

/* the following is a partial set of XML special characters */
special		{vowel}{vowel_mod}|{lig_letter}{lig}|{named_letter}

vowel_mod       ring|grave|acute|circ|uml
vowel		[aAeEiIoOuUyY]

uml		"uml"
acute		"acute"
ring		"ring"
edil		"edil"
circ		"circ"

lig_letter      "ae"|"AE"|"sz"|"OE"|"oe"
lig		"lig"

named_letter    THORN|amp|ccedil
THORN		"THORN"
amp		"amp"
ccedil		"ccedil"


/*
 * The CONTENT mode is used for the content of elements, i.e.,
 * between the ">" and "<" of element tags.
 * The INITIAL mode is used outside the top level element
 * and inside markup.
 */

%s CONTENT


%%

<INITIAL>{ws}		{/* skip */}
<INITIAL>"/"		{return (int)TokenT::SLASH;}
<INITIAL>"="		{return (int)TokenT::EQ;}
<INITIAL>{close}	{BEGIN(CONTENT); return (int)TokenT::CLOSE;}
<INITIAL>{name}		{yylval = yytext; return (int)TokenT::NAME;}
<INITIAL>{string}	{yylval = yytext; return (int)TokenT::VALUE;}
<INITIAL>"?"{close}	{BEGIN(keep); return (int)TokenT::ENDDEF;}

{open}{ws}?{name}	{BEGIN(INITIAL); yylval= word(yytext); return (int)TokenT::START;}
{open}{ws}?"/"		{BEGIN(INITIAL); return (int)TokenT::END;}
{comment}		{yylval = yytext; return (int)TokenT::COMMENT;}

<CONTENT>{data}		{
                         yylval = yytext; 
                         if (yylval.find_first_not_of(" \t\r\n") != std::string::npos) {
                             return (int)TokenT::DATA;}
			 }

.			{std::cerr <<  "!ERROR line " << yylineno 
                                   << " ("<<  *yytext << ")"<<std::endl;}
{nl}			{/* skip, must be an extra one at EOF */;}
