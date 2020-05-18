//*the header to the pre-Jstd library*
#pragma once

//converters between types
#include "pre-jstd/converters/converters.hpp"

//general system calling
#include "pre-jstd/shell/shell.hpp"

//file system stuff
#include "pre-jstd/filesystem/filesystem.hpp"

//file streams / input streams
#include "pre-jstd/streams/streams.hpp"

//boolean transforming
#include "pre-jstd/booleans/booleans.hpp"

//string/wstring observing / transforming
#include "pre-jstd/strings/strings.hpp"
#include "pre-jstd/wstrings/wstrings.hpp"

//vector observing / transforming
#include "pre-jstd/vectors/vectors.hpp"

//color stuff
#include "pre-jstd/colors/colors.hpp"

//gmp stuff
#include "pre-jstd/gmp/gmp.hpp"

//replacements and custom control structures
#include "pre-jstd/control_structures/control_structures.hpp"

//quick ways to terminate/exit/quit/crash a program
#include "pre-jstd/exits/exits.hpp"

//dealing with time. causing delays
#include "pre-jstd/time/time.hpp"

//helps print stl containers
#include "pre-jstd/printers/prettyprint.hpp"

//easier compare multiple variables at once
#include "pre-jstd/comparing/multiple_relational_comparing.hpp"

//other printers
#include "pre-jstd/printers/printers.hpp"

//git related functions
#include "pre-jstd/git-related/git-related.hpp"

//#web
#include "pre-jstd/web/web.hpp"

#include "pre-jstd/inheriters.hpp"

#include "pre-jstd/char/char.hpp"

#include "pre-jstd/json/json.hpp"
using json = nlohmann::json;

