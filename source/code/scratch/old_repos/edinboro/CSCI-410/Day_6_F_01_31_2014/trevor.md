######got homework 1 back
 - almost everybbody decided that a semi-colon at the end was the way to go
 - just more natural
 - you don't see too many languages today that use separators over delimiters

many languages are free-format.  Which means you can write an `if statement` all on one line.  You can write all your statements on the same line.  Maybe not a good idea, but the language allows you to do that.  So whether you are using separators or delimiters, line termination is irrelevant with a free-format language.  

Here is a problem with the Pascal method:
Take the following code:
```
begin
  ____;
  ____;
  ____;
  ____
end
```
if you decide to add another statement, you would have to remember to add a semi-colon to the previous line:
```
begin
  ____;
  ____;
  ____;
  ____; <- don't forget to add a semi-colon
  ____
end
```

Pascal lets you have semi-colons even when you don't need them.  
```
begin
  ____;
  ____; (A NULL STATEMENT WITHOUT A SEMI-COLON GETS EVALUATED AFTER THIS STATEMENT)
end
```
######that's all for the homework.
**lvalues & rvalues**   
(x + y) ++
x and y would be lvalues because they are "locate-able".  The "l" may also refer to the fact that these variables are often found on the left side.  That's of course not always true.  I perfer to the "location" term.  If it has an address, if you can locate it, if you can reference it in your code, then yes, it is an lvalue.  Is everything else an rvalue?  Well no.. there are other kinds as well:  http://stackoverflow.com/questions/3601602/what-are-rvalues-lvalues-xvalues-glvalues-and-prvalues  

**Homework for Wednesday: problem 6 b, 12, and 23 a, c**


#####THE LESSON CONTINUES!  
 - CHOMPS-KEY and context free grammar

We talked about syntax analysis.  Now we are moving on to emantic analysis.  
There is one in between those two though:  

```
1. Syntac Analysis
2. Static semantics analysis
3. Semantic analysis
```

If we look at:  
```
<var> = <expression>
```
someone added this safety type checking and called it attribute grammar.   
__static__ - done at compile time  
__dynamic__ - done at compile time  


#HOW DO YOU KNOW YOUR PROGRaM WORKS CORRECTLY?!  
hmmmmmm...  


 - operating semantics
 - denotational semantics
 - axiomaic semantics  

meyer: let's look at these things and we're done.  
me: ok meyez   
  
we do operational semantics all the time.  You keep track of the state of the program.  The state meaning what is occuring; all the variables and values; what functions you are in and stuff.  If you want to be formal about a program language, you need to look at all the statese a program is in.  

here is a drawing:  
```
source
|
\/
translate
|
\/
object    <- ain't nobody wanna go here
```

so you know what, let's go to assembly first:
```
source
|
\/
translate
|
\/
assembly language    <- yeah ok, I might go here
|
\/
object    <- ain't nobody wanna go here
```

Yeah, if you really wanna know how a program is working, you can look at the confusing optimized assembly code I suppose.  

meyer: Denotional semantics.  This is a fun one.  You and I both don't want to go there.  
It uses mathematics.  It uses functions.  

Let's look at some examples:  
we all know about functions.  A function takes parameters and maps it to a range.  So for example the addition of say:  
`+(3,4) -> 7`  maps those two parameters to 7.  Ew, looks like Haskell.   

Go look at the binary example of Denotional semantics in the book.  I'm not sure what page, somewhere near figure 3.10. 

```
BNF (not sure if this way is acceptable syntax for a BNF)
<bin_num> -> <bin_number>'0'
<bin_num> -> <bin_number>'1'
```
or
```
BNF (how the book and most of the internet does it)
<bin_num> -> '0'
           | '1
           | <bin_number>'0'
           | <bin_number>'1'
```

who wants to grow up and be an astronaut, a doctor, or a denotional semantics maintainer/analyzer
######axiomatic semantics
you basically assert in your code that things should be a a way they are.  
 - pre-conditions
 - post-conditions

C++ has an assert that will crash your program if it fails.  It also has a static_assert to test things while compiling.  



