##C++ Utilities (Pre-Jstd Library)

This repository should be used as a symbolic source for the concept of [symbolic pull-ins](https://github.com/luxe/symbolic-pull-ins).  Create a sympull file for the program [git-it](https://github.com/luxe/git-it) to pull from this repository and generate code for you:  Your sympull file should contain no flags.  

###What Is This?
This is a collection of global C++ functions.

###Why a Pre-Jstd Library?
We needed to create a `Pre-Jstd library` in order to keep other projects organized, and to avoid having to re-implement common functions across projects.  All of these functions will one day be expanded and put into the `Jstd`, but for right now, they are a useful stepping stone for creating larger applications.  This is indeed a naive implementation of a library, but its only function is to help bootstrap other projects and the Jstd itself.  Eventually the Jstd will need rewritten in UniLang.

And eventually, this library will no longer be needed by new programming projects after the `Jstd` superseeds it.
