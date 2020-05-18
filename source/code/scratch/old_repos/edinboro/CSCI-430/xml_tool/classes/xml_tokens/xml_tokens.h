#pragma once
#ifndef TOKENS
#define TOKENS

#include <string>
#include <ostream>

enum class TokenT : char {VERSION, ENCODING, SLASH, EQ, CLOSE, NAME, VALUE, ATTDEF, COMMENT, DATA, END, ENDDEF, START, UNKNOWN_TOKEN};

std::string TokenTToString(TokenT const& t);
TokenT StringToTokenT(std::string const& s);
bool HasNewString(TokenT const& t);
bool Valid_Token(TokenT const& t);

std::ostream & operator << (std::ostream & out, TokenT const& t);
#endif
