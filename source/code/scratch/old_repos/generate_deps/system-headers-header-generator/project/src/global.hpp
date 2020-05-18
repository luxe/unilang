#include "include_category.hpp"
namespace constant{

	const std::string Include_FILE = ".gitignore";

	const Include_Category STD_HEADERS(
	"std",
	{"array"
	,"bitset"
	,"deque"
	,"forward_list"
	,"list"
	,"map"
	,"queue"
	,"set"
	,"stack"
	,"unordered_map"
	,"unordered_set"
	,"vector"
	,"string"
	,"algorithm"
	,"chrono"
	,"functional"
	,"iterator"
	,"locale"
	,"memory"
	,"stdexcept"
	,"tuple"
	,"utility"
	,"fstream"
	,"iomanip"
	,"ios"
	,"iosfwd"
	,"iostream"
	,"istream"
	,"ostream"
	,"sstream"
	,"streambuf"
	,"complex"
	,"numeric"
	,"random"
	,"valarray"
	,"exception"
	,"limits"
	,"new"
	,"typeinfo"
	,"thread"
	,"mutex"
	,"condition_variable"
	,"future"
	,"cassert"
	,"cctype"
	,"cerrno"
	,"cfloat"
	,"ciso646"
	,"climits"
	,"clocale"
	,"cmath"
	,"csetjmp"
	,"csignal"
	,"cstdarg"
	,"cstdbool"
	,"cstddef"
	,"cstdint"
	,"cstdio"
	,"cstdlib"
	,"cstring"
	,"ctime"
	,"cuchar"
	,"cwchar"
	,"cwctype"
	,"regex"
	,"codecvt"
	,"initializer_list"
	,"ratio"
	,"system_error"
	,"type_traits"
	});

    const Include_Category BOOST_HEADERS(
    "boost",
    {});
    
    const Include_Category QT_HEADERS(
    "qt",
    {});
    
    const Include_Category NCURSES_HEADERS(
    "ncurses",
    {});
}
