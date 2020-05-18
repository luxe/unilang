###hcp-compiler
The `hcp-compiler` is a program used to convert `.hcp` files to their corresponding C++ `.hpp` and `.cpp` files.
* * *

###Table of Contents

  * [Introduction](https://github.com/luxe/hcp-compiler/blob/master/project/README.md#introduction)
  * [Rationale](https://github.com/luxe/hcp-compiler/blob/master/project/README.md#rationale)
  * [Dependencies](https://github.com/luxe/hcp-compiler/blob/master/project/README.md#dependencies)
  * [Installation](https://github.com/luxe/hcp-compiler/blob/master/project/README.md#installation)
  * [Flags](https://github.com/luxe/hcp-compiler/blob/master/project/README.md#flags)
  * [How To Use](https://github.com/luxe/hcp-compiler/blob/master/project/README.md#how-to-use)
  * [hcp Files](https://github.com/luxe/hcp-compiler/blob/master/project/README.md#hcp-files)  

* * *

###Introduction

The hcp-compiler compiles an `.hcp` file, into it's respective `.hpp` and `.cpp` files.
Each `.hcp` file contains all the needed code to represent an individual C++ class, or a collection of global c++ functions/data.  This allows a developer to work with half as many files open as they normally would.
```
                                  +---------+
                               /->|class.hpp|
+---------+     +------------+/   +---------+
|class.hcp| --> |hcp compiler|               
+---------+     +------------+\   +---------+
                               \->|class.cpp|
                                  +---------+
```
For each `.hcp` file passed in, the `hcp-compiler` will output a corresponding `.hpp` and `.cpp` file.  

* * *  

###Rationale
#####C++'s current state of affairs:
I hate writing header and source files in tandem.
- It's tedious.
- It's error prone.
- Portions of the same code are in multiple areas
- It can be dangerous if you accidently change the header or source, and it still compiles.  
- It takes too much time jumping between the header and source when you need to learn about the class.
- You end up having 2x the desired files opened.
- renaming an already created class is tedius
- there is no gaurentee that the name of the class files are the same name of the class inside
- It's possible to add more than one class to a `.hpp` and `.cpp` pair, which many would consider bad practice.
- it clutters your project with 2x as many files as classes you have
- it is difficult to parse portions of a class file, into the higher level categories that they represent:  
(constructors,function names(observers, transformers) inheritence, data members).  If this were easier, static analysis and documentation generation could be easier.

#####The Solution:
I propose writing your class in one file.  That one file can be turned into a `.cpp` and an `.hpp` using a transcompiler.  If you write your code in an `.hcp`, you'll be able to fix the problems above and get the added benefits of static analysis and generative code documentation.  

* * *  

###Dependencies
 - git-it (my dependency manager)
 - hcp-compiler (my bootstrap version)
 - pre-jstd (my library)
 - make
 - boost
 - gcc (4.9 or higher)  

* * *  

###Installation
```
git-it git@github.com:luxe/hcp-compiler.git;
cd hcp-comiler/project/src;
make;
```  
* * *
###Flags
```
hcp-compiler --help

compiles hcp files into hpp and cpp files:
  --input_files arg     the url of the repository to download
  --optimize            optimize the hcp file on dependencies while compiling
  -h [ --help ]         produce this help message
  -v [ --version ]      display version
```
* * *

###How To Use
####compiling:
`hcp-compiler file1.hcp file2.hcp ...`
this will result in the creation of files:
`file1.hpp file1.cpp file2.hpp file2.cpp ...`
*keep in mind, there is no guarantee that the output itself is valid C++.
if the hcp-compiler builds files, it simply means that you sprinkled the Unicode correct enough that there were no obvious errors.

####optimizing:
`hcp-compiler file1.hcp file2.hcp --optimize`
A brute force approach to removing any uneeded header files from the outputted `.hpp` and `.cpp` files.
*keep in mind, that optimizing the dependencies of a particular class has the danger of indirectly breaking another object's build.  Hoverever, you should understand that this is a good thing, because it shows that the object had a dependency in which it was recieving indirectly.  The optimizer will indirectly call the compiler to test whether certain files can be thrown out.  The optimizer also relies on the build system in place (the makefile).

* * *  

###HCP Files
Since no mortal actually wants to parse C++, it's better to hack it together with unicode.
Here is a symbol table for the creation of `.hcp` files.  Everything else, is your normal C++:

| Symbol |Use  |Symbol type
|--------|-----|-----|
|❪❫      |  header includes   | inclusion|
|⚯     | header seperator for hpp and cpp| single|
|⚞⚟  |inheritence |inclusion|
|☀|start of function name| single|
|◈|class name| single|
|◀ ▶|header only| inclusion|
|◖ ◗|source only| inclusion|
|❰ ❱|function body| inclusion|
|ļ| unicode escape character|single|
|ͼ ͽ| execute shell command | inclusion|
|፠ ፠| data member | inclusion|

*everything outside the inclusion symbols (appart from the header and inheitence symbols) will appear in both the compiled `.cpp` and `.hpp` files.
  
#####problems with unicode?
Using unicode, in my opnion, is hardly an added chore.  Yes, those keys don't exist on your keyboard, and yes it might mess up a few syntax highlighters, but these are things that can all be fixed in time.  Also, I have a grand vision of the majority of programming being done through a gui which creates hcp files for you.  For writing raw hcp files though, you could create a comment at the bottom of the file you are working on, that has the unicode characters there for you to copy and paste around.  Most syntax highlighters can be tweaked to ignore unicode, and continue to color the language in the exact same way as before.  I have been more productive writing in `.hcp` files than having to juggle `.hpp` and `.cpp` files.  Regardless, these files can always be compiled back into their vanilla `.hpp` and `.cpp` files respectively.

###How to build a `.hcp` file

####the first line:
every file will start with either `class` or `global` written on the first line.
this tells the compiler whether the file is intended to represent an individual class,
or a collection of global functions and data.

####top of file (header files):
```cpp
//all your header header files go here
⚯ //<- this is a seperator
//all your source header files go here
```

#####local header files look like:
```cpp
❪"your_class"❫ // another hcp (just leave out the .hcp, and it is assumed)
❪"something.hcp"❫ //you will get a compiler error if you try to include .hcp files like this
```
#####system header files look like:
```cpp
❪iostream❫ // just leave out the quotes
```
####header/source headers example:
```cpp
//header headers
❪iostream❫
❪string❫
❪vector❫
⚯
//source headers
❪"my_class"❫
❪"my_second_class"❫
```

####inheritence:
perform inheritence by putting stuff inside `⚞⚟ `after the header sections


####class name:
The name of your class is derived by the file name, minus the `.hcp`.  It will always be in uppercase with underscores
####class name example:
`"my class.hcp" -> class My_Class{};`

If you need to reference the class name, use: `◈`.  The main place to do this, would be the constructor and destructor.  Other function methods will require the `☀` which will derive the class name and scope it in the `cpp` file. (If you look at the other symbols, you will realize that `☀ = ◖◈::◗`)

####constructor example 1:
```cpp
//constructor
◀public:▶ ☀◈()◖
			: your_data(0)
			◗
			❰❱
```
####equivalent, but more verbose constructor 1:
```cpp
//constructor
◀public:▶ ◖◈::◗◈()◖
			: your_data(0)
			◗
			❰❱
```

####constructor 2:
```cpp
//constructor
◀public:▶ ☀◈(int thing1◀=0▶, int thing2◀=1▶)◖
			: m_thing1(thing1)
			, m_thing2(thing2)
			◗
			❰❱
```
####equivalent, but more verbose constructor 2:
```cpp
//constructor
◀public:▶ ◖◈::◗◈(int thing1◀=0▶, int thing2◀=1▶)◖
			: m_thing1(thing1)
			, m_thing2(thing2)
			◗
			❰❱
```

####methods:
You don't need to worry about how to scope the functions with the class name.  
You just have to use the function starter(`☀`)

####method example:
```cpp
◀public: static▶ void ☀function(int o◀=1▶)❰
	std::cout << o << "+" << o << "=" << o+o << std::endl;
	return;
❱
```
If it's a template method, you will probably want to just wrap all parts of the method in `◀ ▶` so that it is header only.  

####FAQ:
`Q:` doesn't this make devleopment harder when you get an error message that is a line number different than the `.hcp` file?  
`A:` you can still look at the hpp and cpp files to discover what is wrong.  The hcp file is not too far of an abstraction that you shouldn't be able to make the corrections with ease.
