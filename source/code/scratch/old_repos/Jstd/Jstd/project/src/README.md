# Welcome to the Jstd Library code base

### What's in this directory?
 File | Description
--- | --- 
.README_files | contains resources for the file you are currently reading
jstdlib | where the pseudo library is, and where the real library will be created
src | contains source code to convert the pseudo library, as well as test different things
Makefile | builds the jstd-tool; a tool for converting the pseudo library into a real library, and places it in the root of the pseudo library (`jstdlib/pseudo/`)
TO-DO | A disorganized list of things I need to do.  Good luck understanding that
UPDATES | All of the changes made before a version release takes place.  This file gets wiped after a a version update takes place.  That way, we can start filling it with updates for the next release.

## Dependencies
 What you need | Where to get it
--- | --- 
C++14 compliant compiler | http://gcc.gnu.org/
Boost Library | http://www.boost.org/
GMP Library | https://gmplib.org/
Qt Library | http://qt-project.org/
GNU Make | http://www.gnu.org/software/make/
Bash Shell | http://www.gnu.org/software/bash/
A 256 color capable terminal (you know,  if you want pretty colors) | varies
How do you know if you have all of these things properly installed?  Run the dependency checker in `src/tests/dependency_checker/`.  If you can get it to pass all of the tests, then you should be good.

    

## How to Build
* Run the makefile that is in this directory.
* It will build the "jstd-tool" and put the binary in jstdlib/pseudo/
* Go there and run the jstd-tool.
   
The "jstd-tool" will build the library, as well as provide other useful features.   
What it exports and builds can be found be in `jstdlib/real/`.
That being said, you should run `./jstd-tool --export --build` to convert the pseudo library into real code, and then compile that real code into a library format.  There are many other options you may want to tweak as well; consider typing `./jstd-tool --help` to see them.

