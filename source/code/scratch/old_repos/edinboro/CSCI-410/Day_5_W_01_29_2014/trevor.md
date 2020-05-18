##Day 4

####Beginning weird stuff
Is technology making things worst?
 - Is chalk better than dry erase markers?
 
How do we pronounce our own names?
 - Can you spell your name phonetically?
 - `Treav oar`? I dunno man...

####Start of Lesson
We are done with chapter one.  
Meyer has set up a discussion board if you have questions.  
Hey! There is an editor called Eclipse! Every hear of it?  
Editors or IDEs (indegrated devleopment environements) can make our lives easier. ok. Because they can add compilers and stuff.  

####History of languages.  
Plankalkul (plan calculus)  
that's pretty old.  What's the oldest? Oh, who knows; swept away by the moving hand of time.  Ww'll leave that to history. Languages are interesting though.  It's interesting to see the different ways people do things.

####Chapter 3
talks about syntax, grammar, and semantics.  

We are going to talk about grammer today!

Context-free grammer in Backus-Naur form(BNF) is a way to describe syntax.  
Chomsky forms of grammar also.  

*READ ABOUT EXPRESSING DYNAMIC GRAMMER IN THE BOOK*  
and the other pages listed in the notes.    

####lesson continued.  
we need to describe our syntax in a specific way.  We don't want ambiguity in a language.  

```
if (score >= 90)
```
we need to convert this code into object code.  
Let's go through the steps:  
  1. Lexical Analysis (checking for a valid meaning.. does it make sense in the language)  
Basically you read in the text and tokenize it.  That might look something like this:  
```
if     //token
(      //token
score  //token - id
>=     //token - operator
90     // token - constant
)      // token
```
**difference betweeen token and lexeme?**  
http://stackoverflow.com/questions/14954721/what-is-the-difference-between-token-and-lexeme

**recognizers and generators**  
recognizers - says whether the sentence is valid or not  
generator - generates a sentence for the language  

**what does an abstract machine do?**  
`sentence -> abstract_machine -> boolean(yes/no)`

**what does context-free mean?**  
it means you can analyse each statment one at a time without needing to know about the previous statements.

**non-terminals?**  
tokens in the language that can't end a stement.  
And `if` token is an example.  


**Derivation done in class**  
```
<ident_list> -> A, <ident_list>
             -> A, B, <ident_list>
             -> A, B, C, <ident_list>
             -> A, B, C, D
```
grammars can be expressed as state machines (correct me if I'm wrong)  
For example:  
!["grammar as graph"](http://www.cse.ohio-state.edu/~gurari/theory-bk/draw-pic/theory-bk-one-1-2-1.jpg)  

**Another derivation done in class**  
```
begin B = A + A end

<program> -> begin <stmt_list> end
          -> begin <stmt> end
          -> begin <var> = <expression> end
          -> begin B = <expression> end
          -> begin B = <var> + <var> end
          -> begin B = A + <var> end
          -> begin B = A + A end
```

**Parse trees can be expressed as parse trees**
We did one in class for the program above.  
[This is what it looks like](http://mshang.ca/syntree/?i=%5B%3Cprogram%3E%20%5Bbegin%5D%20%5B%3Cstmnt_list%3E%20%5Bstmnt%20%5B%3Cvar%3E%20%5BB%5D%5D%20%5B%3D%5D%20%5B%3Cexpression%3E%20%5B%3Cvar%3E%20%5BA%5D%5D%20%5B%2B%5D%20%5B%3Cvar%3E%20%5BB%5D%5D%5D%5D%20%5Bend%5D%5D)  
- more than one parse tree is BAD!  
- It means your program has more than one meaning.  
- This sets us up for our homework
- careful when you parse (like don't add before you multiply)  

"Have a successful two days." BBYE MEYEER!

###AYEEEEEEEE
####-OOOOOOOO
#####OOOOOOOOOO
######OOOOOooooo
#######oooooooo.....
..............
