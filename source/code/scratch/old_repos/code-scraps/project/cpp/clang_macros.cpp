//alternative feature checking without resorting to autoconf or fragile compiler version checks
//if the compiler does not have feature checking functions available we'll stub them to allow usuage in other compilers.
//Although, this is probably not a good idea, because then they will all return false when the feature/builtin/extension may indeed exist.

//checks to see if the language extension is available
//Use empty fallback if the compiler does not support feature checking macro
#ifndef __has_builtin
#define __has_builtin(x) 0
#endif

//checks to see if the language feature is standardized and available
//Use empty fallback if the compiler does not support feature checking macro
#ifndef __has_feature
#define __has_feature(x) 0
#endif

//checks to see if the language feature is supported
//(it might be supported as a language extension or as a standard language feature)
//Use empty fallback if the compiler does not support feature checking macro
#ifndef __has_extension
#define __has_extension(x) __has_feature // Compatibility with pre-3.0 compilers.
#endif

//checks to see if c++ attribute is available
//Use empty fallback if the compiler does not support feature checking macro
#ifndef __has_cpp_attribute
#define __has_cpp_attribute(x) 0
#endif

//checks to see if compiler attribute is available
//Use empty fallback if the compiler does not support feature checking macro
#ifndef __has_attribute
#define __has_attribute(x) 0
#endif

//checks to see if a Microsoft-style compiler attribute is available
//Use empty fallback if the compiler does not support feature checking macro
#ifndef __has_declspec_attribute
#define __has_declspec_attribute(x) 0
#endif

//checks to see if a word is either an identifier or a reserved word
//Use empty fallback if the compiler does not support feature checking macro
#ifndef __is_identifier
#define __is_identifier(x) 0
#endif

//checks to see if a header file is available in the include paths
//Use empty fallback if the compiler does not support feature checking macro
#ifndef __has_include
#define __has_include(x) 0
#endif

//checks to see if a header file has a second instance available in the include paths
//Use empty fallback if the compiler does not support feature checking macro
#ifndef __has_include_next
#define __has_include_next(x) 0
#endif

//checks to see if a compiler warning is available
//Use empty fallback if the compiler does not support feature checking macro
#ifndef __has_warning
#define __has_warning(x) 0
#endif



//quiet
//warning
//error

//implementation choices for static assert based on system availability
#define STATIC_ASSERT_WITH_STD_FUNCTION(predicate,message) {static_assert(predicate,message);}
#define STATIC_ASSERT_WITHOUT_STD_FUNCTION(predicate,message) {switch(0){case 0:case predicate:;}}
#define STATIC_ASSERT_QUIET(predicate,message) 0

//decide how to implement a static assertion check
//if the C version from C11 exists, we'll use it
#if defined(static_assert)
	#define STATIC_ASSERT STATIC_ASSERT_WITH_STD_FUNCTION
#else
	#define STATIC_ASSERT STATIC_ASSERT_WITHOUT_STD_FUNCTION
#endif

/*
#if defined(__STDC__)
	#if (__STDC_VERSION__ >= 201112L)
	#endif
#endif
*/




#if __has_include_next("yo.hpp")
#warning "yes  __has_include"
#endif


#include <assert.h>



int main(){

/*
#if __has_feature(c_static_assert)
  #warning "yes"
#else
  #warning "no"
#endif
*/

//COMPILE_TIME_ASSERT(sizeof(ConfData_t) > 32);
}