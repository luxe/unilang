//*the source to the pre-Jstd library*
#include "utilities.hpp"

//hacks I needed to put into the std library
#include "pre-jstd/std_hackery.cpp"

//converters between types
#include "pre-jstd/converters/converters.cpp"

//general system calling
#include "pre-jstd/shell/shell.cpp"

//file system stuff
#include "pre-jstd/filesystem/filesystem.cpp"

//file streams / input streams
#include "pre-jstd/streams/streams.cpp"

//color stuff
#include "pre-jstd/colors/colors.cpp"

//gmp stuff
#include "pre-jstd/gmp/gmp.cpp"

//quick ways to terminate/exit/quit/crash a program
#include "pre-jstd/exits/exits.cpp"

//dealing with time. causing delays
#include "pre-jstd/time/time.cpp"

//helps print stl containers
//#include "pre-jstd/printers/prettyprint.cpp" <- is header only

//easier compare multiple variables at once
//#include "pre-jstd/comparing/multiple_relational_comparing.cpp" <- is header only

//other printers
#include "pre-jstd/printers/printers.cpp"

//git related functions
#include "pre-jstd/git-related/git-related.cpp"

//#web
#include "pre-jstd/web/web.cpp"

#include "pre-jstd/json/json.cpp"
#include "pre-jstd/json/json_functions.cpp"

#include "pre-jstd/compression/compression.cpp"
#include "pre-jstd/processes/processes.cpp"


//language basic
#include "pre-jstd/language_basic/control_structures/control_structures.cpp"
#include "pre-jstd/language_basic/relational_comparing/relational_comparing.cpp"



//related to types
#include "pre-jstd/types/booleans/booleans.cpp"
#include "pre-jstd/types/char/char.cpp"
#include "pre-jstd/types/strings/strings.cpp"
#include "pre-jstd/types/wstrings/wstrings.cpp"
#include "pre-jstd/types/vectors/vectors.cpp"
#include "pre-jstd/types/unordered_set/unordered_set.cpp"
#include "pre-jstd/types/sets/sets.cpp"
#include "pre-jstd/types/map/map.cpp"

#include "pre-jstd/other_language/cplusplus.cpp"
