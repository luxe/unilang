#pragma once

//enums to use in place of strings to make code more strongly typed
enum class Class_Access   { PUBLIC, PROTECTED, PRIVATE };
enum class Value_Overload { LVALUE, RVALUE, NONE };
enum class Storage_Specifier {STATIC, EXTERN, NONE };

//concepts not keywords.
//they are applicable, but not a part of the language.
enum class State_Specifier {OBSERVABLE,INJECTABLE,OBTAINABLE};
enum class Function_Category {OBSERVE,TRANSFORM};
