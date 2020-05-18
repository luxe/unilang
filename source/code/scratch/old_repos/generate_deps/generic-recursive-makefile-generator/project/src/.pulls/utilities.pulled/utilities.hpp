//*the header to the pre-Jstd library*
#pragma once

#ifdef __GNUC__
#pragma GCC system_header
#endif

#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <random>

//hacks I needed to put into the std library
#include "pre-jstd/std_hackery.hpp"

//converters between types
#include "pre-jstd/converters/converters.hpp"

//general system calling
#include "pre-jstd/shell/shell.hpp"

//file system stuff
#include "pre-jstd/filesystem/filesystem.hpp"

//file streams / input streams
#include "pre-jstd/streams/streams.hpp"

//color stuff
#include "pre-jstd/colors/colors.hpp"

//gmp stuff
#include "pre-jstd/gmp/gmp.hpp"

//quick ways to terminate/exit/quit/crash a program
#include "pre-jstd/exits/exits.hpp"

//dealing with time. causing delays
#include "pre-jstd/time/time.hpp"

//helps print stl containers
#include "pre-jstd/printers/prettyprint.hpp"

//other printers
#include "pre-jstd/printers/printers.hpp"

//git related functions
#include "pre-jstd/git-related/git-related.hpp"

//#web
#include "pre-jstd/web/web.hpp"

#include "pre-jstd/inheriters.hpp"

#include "pre-jstd/json/json.hpp"
#include "pre-jstd/json/json_functions.hpp"

#include "pre-jstd/serialization/serialization.hpp"

#include "pre-jstd/compression/compression.hpp"

#include "pre-jstd/processes/processes.hpp"

#include "pre-jstd/random/random.hpp"

//language basic
#include "pre-jstd/language_basic/comparing/multiple_relational_comparing.hpp"
#include "pre-jstd/language_basic/control_structures/control_structures.hpp"
#include "pre-jstd/language_basic/relational_comparing/relational_comparing.hpp"


//related to types
#include "pre-jstd/types/booleans/booleans.hpp"
#include "pre-jstd/types/char/char.hpp"
#include "pre-jstd/types/strings/strings.hpp"
#include "pre-jstd/types/wstrings/wstrings.hpp"
#include "pre-jstd/types/vectors/vectors.hpp"
#include "pre-jstd/types/unordered_set/unordered_set.hpp"
#include "pre-jstd/types/sets/sets.hpp"
#include "pre-jstd/types/map/map.hpp"
#include "pre-jstd/types/container_general.hpp"

#include "pre-jstd/other_language/cplusplus.hpp"



