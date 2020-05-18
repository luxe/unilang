[ Insert Jstd Library Logo here]
===

###What's in this directory?
 File | Description
--- | --- 
.README_files | contains resources for the file you are currently reading
current | the current version of the Jstd library code base
.gitignore | tells git to ignore certain files in all directories
LICENSE | open source license agreement
README.md | what you are reading now


##What Is The Jstd?

A library that contains everything for every language.  
The goal of the Jstd library is to provide you with every
constant, function, macro, and type that you could possibly think of, or wish to use
in your own projects. I suppose a good motto would be: "Don't re-invent the wheel.", except in this case, we already have cars, and you already know how to drive them.

## Give me an overview of the Jstd
The community will use the [Jstd website](http://jstdlib.com "Jstd website") to build onto the pseudo library.  The pseudo library represents code for any and all languages.  This website provides an interface for modifying the Jstd in a controlled and structured way.  Additionaly, the Jstd website will act as online documentation for the library; allowing users to search, and see code examples for particular aspects of the library.  In order to use the library, users will download the pseudo library along with code that will help transform the pseudo library into a real library.  The transformation proccess will have a variety of options to generate the library in a way that best suits the user.  

![picture of a very general overview of how the Jstd works from a users perspective](https://raw.github.com/Jstd/Jstd/master/.README_files/general_overview.png)   
It's more complicated than that, but this gives you a nice overview. You and others help build a community library.  Think of it as Wikipedia, but for code.  You can browse for the code you need, and contribute your own.  Additionally, instead of copying and pasting code off the website, you can download the pseudo library, and use the jstd-tool to turn that pseudo library into a real library.

## Explain A Bit More Of Why I Need The Jstd
Ok, so how would you lowercase a string?  
Do you remember what function does that for you?  
That function name is probably different across languages; are you sure you're thinking of the right one?
Maybe the language you're using doesn't even have a function to lowercase a string (C++ for instance).
Not only do you have to waste time checking the documentation for a particular function signature that doesn't exist, but now you have to waste more time implementing it yourself.  
Would you rather write your own function(regardless of how easy it is), and risk creating a bug?  
I'd rather use a function checked and used by a larger pool of experienced programmers.
As an exercise though, imagine writing a lowercase function for C++.  

Maybe you came up with something like this:  

```cpp
Lowercase(std::string & str){
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}
```
You may have forgotten to return the string as a reference incase somebody wanted to inline the function into a larger statement.
```cpp
std::string &Lowercase(std::string & str){
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}
```
That's better.  But wait a minute, now you need to lowercase a std::wstring.  Do you make another overload?  What about the other "string" types?  Should you waste more time writing templates? No. use the Jstd.  Any type that can be lowercased, the Jstd will have a function to lowercase it.  

Someone else on your programming team might not know the function is called "Lowercase".  Now what?  They might implement their own function and call it `to_lower()`.  They might write a function with the exact same function decleration as you but in a different namespace.  What if theirs has a bug?  It's going to be difficult to track down a bug, if you test and examine only the working function signature.  The Jstd knows that things can be said differently.  Whether you call `Lowercase()`, `to_lower()`, or `lowercase_this_string()`, the Jstd will map it to the same function definition to allow programmers to just "say what they mean".  You might think it's confusing to see two different functions that do the exact same thing, but  with the right interface, programemrs will be able to easily see the "base function" of all other "function synonyms", and even convert the code between them as a preference.  Do you see what this means?  Let's say you always use `to_lower()` in your code, and I always use `Lowercase()` in mine. If you gave me code that contained calls to `to_lower()` an interface over top would show those functions to me as `Lowercase()`. Code that can transform to a programmer's perference, and make reading code easier for each individual, will improve devleopment.  Someone who isn't even very experienced with programming might call `lowercase_word()`.  No problem, and more expereienced programmers will see something closer to `lowercase_string()`  I hope this longer explanation of what the Jstd is capable of helps shed light on the growing need for a library that knows programmers, and not the other way around.  Think of the increased producitivity both in time and code understanding with these technologies in place.  It will also keep code cleaner and less prone to bugs. This same scenairo I've described will be in place for not just functions, but types, type methods, constant names, everything.  And don't worry, a user can always visit the Jstd website or offline documentation to ensure the correct behaviour and implementation of the code they use.

## Give Me An Overview Of How The Jstd Works
With a pseudo language that uses regular expressions, a world of collaborating programmers, and a much too meticulous organization structure.

## I Think I'm Ready To Give This A Shot
I suggest that you first explore the [Jstd website](http://jstdlib.com "Jstd website"), as you can download from there, both the pseudo libary with its converter tool, as well as an already built library based on recomended options.  Also, if you need a quick function or something and don't to go through the hassle of setting up / configuring, then you can all get code straight from the website.  Basically, every interaction a normal user should have with the Jstd, should come from the Jstd website.  If you are more interested in helping improve, or explore the core aspects of the project, then by all means, take a step into the `current` directory, and I'll see you there.
