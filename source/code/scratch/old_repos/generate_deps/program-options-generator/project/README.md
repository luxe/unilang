Program Options Maker
=====================

This repository should be used as a symbolic source for the concept of [symbolic pull-ins](https://github.com/luxe/symbolic-pull-ins).  Build a .sympull file, so that the program `git-it` can pull from this repository and generate code for you:  Your sympull file should look like this:  
```
git@github.com:luxe/program_options_maker.git
--author="First Last"
--website="whatever url you use to your repo, or possibly a support site"
--description="what it does"
--email_address="blah@email.com"
--tool_name="the something tool"
--version_number="1.0.0"
--license="MIT"
--allow-json

--flag="type
default_value
function_name
flag_name
comment
description
mandatory
positional
multitoken
"

--flag="type
default_value
function_name
flag_name
comment
description
mandatory
positional
multitoken
"

```

####What it is:  
`program_options_maker` is a program that helps create c++ objects that read, store, and verify command line arguments for you.  It wraps around the `boost program_options` library, and makes everything intutive and easier to manage during a project's life time.  Given a script, this program will generate a variety of objects, but the only that you'll be concerned about it is `Program_Options`; which contains everything you need to know about the command line arguments after they have been parsed/verified.

####Why you should use it:  
I created it to make editing and updating program options easier.  It is also easy to attach into your code base, because the code it generates, has all of its functionality wrapped into a single object for you to use.  Figuring out how to run this simple program to generate code for you, is much easier and safer than parsing the command line options yourself.  You should never be parsing the command line options yourself anyway, and should instead use the boost library.  This program just saves you time having to look up all of the documentation on boost_program_options, and makes it easier to make updates when you inevitably realize the program options should be different.  It's also object-oriented, and I don't need to go into the benefits on that.

####What it really is:  
It's an object-oriented wrapper around the `boost program_options` library that creates specific methods based on the script file you provide.  Various objects get created, but they are all used directly or indirectly by the `Program_Options` object.
####How it looks conceptually:  
```
program_options_maker creates:
```
![uml diagram of class objects](https://raw.github.com/luxe/program_options_maker/master/project/.README_files/uml.png)   
```
As a client, you will write the following code:
auto program_options = Program_Options_Creator::Create(argc, argv);
and that will give you a Program_Options object to use.
```
####Build System Perspective:
you will have four objects made for you:
 - The `Program_Options` Object (what you will use in your code)  

 - The `Program_Options_Meta` Object (contains functionality that is inherient in every program options object).  You will not need to worry about this, but know that Program_Options inherits from it.

 - The `Program_Options_Checker` is the object that pulls from a file you will edit to provide additional parameter checking.  The behavior of this object(causing the program to end with an error when flags are invalid), is crucial to the implementation of [symbolic pull-ins](https://github.com/luxe/symbolic-pull-ins). Checks will always be done on a `program_options` object, but a special line of code will be injected into the `Program_Options_Checker` to quit successfully if all the checks succeeded in order to fufill the request of "Testing" for [symbolic pull-ins](https://github.com/luxe/symbolic-pull-ins). 

 - `Program_Options_Creator` is used by the client to create a valid and tested `Program_Options` object.  


####Program_Options_Checker?
You might be thinking, well what kind of code would I add to `check_code.hpp` to have `Program_Options_Checker` pull in?
Let's say you wrote a flag that allowed a user to run a program in the following way:
`./get --food="pizza"`
The `Program_Options` object can automatically check to make sure that the `--food` flag exists, and it can also automatically check to make sure that you passed a syntatically correct value, but it has no idea if your program can get pizza or not.  You will write the additional checks needed in the `Program_Options_Checker` support file: `code_check.hpp`.  
So maybe for example, the kind of code written in the `code_check` file, might looks like this:  

```cpp
    //make sure the "food flag value" is valid
    auto food = program_options.Food();
    if (food != "ice cream" && food != "fries") {
        std::cerr << food << "is not a valid kind of food you can get!\n";
        exit(EXIT_FAILURE);
    }
```
You don't need to write code to check that particular flag was checked.  Choosing whether a flag is mandatory or not, is a part of the script file which builds the objects.  You will however need to check, if only certain flags can be passed if other certain flags exist.  

####What don't I have control over?
I dunno man.  Just use it, and if you want to do an important tweak, let me know.  Or better yet!! fork me!!

####A design decision you may need to make:
Do you want to have the `Program_Options` object global?  That will make parameter passing easier, but it also means that it will always be in memory.  The other common option is to construct the object in the body of main, and carry it through other functions/objects as needed.  It's really up to you, but I thought I should mention it.  Another issue that this project does not yet deal with, is having multiple `program_option` objects.  Maybe your program is capable of doing a few different tasks, that could be logically seperate programs, but are a part of a larger application.  We could perhaps think about parsing the command line arguments and storing them into seperate `program_options_x` objects (possibly utilize inheritence as well).  --Just things to consider.

###To Do:
 - make a long/short description meta data?
 - add a keywords variable in the meta data?
 - particular values only checking
 - particular values not permitted checking
