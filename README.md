# ᴜɴɪʟᴀɴɢ
Unilang is a universal programming language.  
It is the unification of all programming concepts without syntax.  
It is a higher level language above all high level languages.   
It was built to improve the efficiency of the modern software engineer.    

## About
Here are the core principals that guide unilang's development:  

#### 1.  Syntax
Syntax doesn't matter.  It never has, and it never will.    
We eliminate syntax complexity through unique token symbols.  
Unilang pulls from [Unicode's Private Use Area (PUA)][1].  
No matter how many features get added the the language (which you will see, is a lot),  
lexical and syntax analysis remains trivial.  
This makes code easy to read and benefits static analysis tools.  

#### 2. Grammar
You can express anything in any order assuming that it makes sense conceptually.  
Semantic analysis builds an ADT nearly identical to the tokens you write.

#### 3. Code generation
Unilang could target LLVM, output byte code for the JVM, or operate under its own interpreter.  
However, there is little reason to invest in these efforts at this time.  
We stand on the shoulder's of giants and transcompile to other languages.

#### 4. Supersets Win
...

#### 5. Steal
...

#### 6. No trade-offs
Typical programming languages are designed around trade-offs.  
Unilang refuses to make trade-offs.   
Most opinions can be dual supported at the language level,  
and chosen during code generation.

## Installation
```
git clone git@github.com:Unilang/everything.git unilang;
cd unilang/source;
bazel build --cxxopt='--std=c++17' //...:all;
pray
leave me a ticket about how it didn't work, and we'll improve the build
```
stand-alone executables coming soon

[1]: https://en.wikipedia.org/wiki/Private_Use_Areas

## Contribute
Make a ticket about anything.  Try to contribute anything; we'll make it work.  

