###"System Headers" Header Generator
######generate a header that contains all of your important system headers, so that you don't spend devleopment time including them again and again for different modules.
-

This repository should be used as a symbolic source for the concept of [symbolic pull-ins](https://github.com/luxe/symbolic-pull-ins).  Build a .sympull file, so that the program `git-it` can pull from this repository and generate code for you:  Your sympull file should look like this:  
```
--all
  --std
  --boost
  --qt
  --ncurses
  
--add="
header
files
to add
"

--remove="
header
files
to remove
"
```

###What does this solve?
Instead of writing header files like this:
```cpp
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdexcept>
#include <boost/thread.hpp>
#include <QtCore>
//header code ...
```

or source files like this:
```cpp
#include "class_name.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdexcept>
#include <boost/thread.hpp>
#include <QtCore>
//source code ...
```

You can instead write them like this:
```cpp
#pragma once
#include "systems.hpp"
//header code ...
```

```cpp
#include "class_name.hpp"
#include "systems.hpp"
//source code ...
```

When we generate a header to include all of the system headers, we won't be wasting time remembering and searching for what includes we need at the top.  During devleopment, you don't want to be spending time looking at compiler errors due to forgotten headers.

When we generate and include this header, we assume 2 things:
 1. We don't care about compile time
 2. All the headers included use namespaces that do not conflict with one another

You might think this is the opposite of a time saver because of the increased compile time.  In my opinion, if you keep things modular, and have a correctly working build system, it is hardly an issue. Nonetheless, there is an option to compile all of the headers into a pre-compiled header.  This can make compiling even faster had you included only some of the system headers manually.  Also, you don't have to include every header; you can specify just a select few that you use everywhere.
 

