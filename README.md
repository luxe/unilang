<p align="left">
  <img width="395" height="112" src=".readme/unilang-trimmed.png">
</p>  

**A univeral programming language**  




<details>
<summary>Introduction</summary>
<br>  
  
Unilang is the unification of programming concepts without syntax.
It is a reconstructed approach on how language should be used to facilitate the creation of software.
A conceptual model is used to raise the design and implementation abstraction above other high level languages.
You can use Unilang to transcompile down to other langauges and data formats.
Unilang has an abundance of interesting code transformations and static analysis techniques.
It was built to improve the efficiency of the modern software engineer.
The language empowers a level of enginering displine that users would not be able to sustain in other languages.

</details>

<details>     
<summary>Language Design</summary>
<br>
  
## The hierarchy of language
Consider the current language abstractions within the software engineering domain.  
Unilang and its conceptual model are placed above these high level languages.  
![software engineering language abstraction with unilang placed at the top](.readme/language-abstraction.png "test")  
Unilang can transcompile down to other languages.  

## The structure of language
Many programming languages represent their syntatic structure as an abstract syntax tree.  
Other languages like Lisp and its derivations choose nested lists.  
The structure of unilang is a composed set of algebraic data types.  
![choosing the unilang structure](.readme/choosing-structure.png "test")

This is a subtle but important distinction.  
An ADT models the concise structure and shape of programming concepts.    
This allows us to work backwards and enable programmers to effeciently populate this structure.  
Trying to contort a variety of programming concepts syntatically, and then extracting them out with regular expressions and grammars into generic data structures such as trees and lists has proven insufficient for semantic analysis.  
Its the reason that parsing errors are often confusing and unhelpful.  
Its the reason that community tooling on code transformation is often limited.  
Most importantly, its the reason a language's evolution tends to stagnate as more abstract concepts are squeezed into an existing syntax and grammar.  

## Direct semantic encoding (syntax considered harmful)
TODO.  
essentially end at a markup language.  
markup language is great from the compilers perspective,
but terrible from the programmers perspective.  
Explain how we fix this.  
uh, we'll probably need a deeper section about natural language vs programming language.  
what is relevant, what is not. how properties of natural language has incorrectly been applied in programming
talk about how semantics is what matters most in programming

here is a good example that sumarizes why the whole syntatical approach is incorrect.  
Where they focus on keyword, we have unilang language tokens
http://mail.openjdk.java.net/pipermail/amber-spec-experts/2019-January/000945.html

## Guiding Principles
All of these need adjusted and organized

#### 1.  Syntax
Syntax doesn't matter.  It never has, and it never will.    
We eliminate syntax complexity through unique symbolic tokens.  
Unilang pulls from [Unicode's Private Use Area (PUA)][1].  
As a result, no matter how many tokens get added the the language,  
the lexical and syntatical analysis remains trivial.  

Unilang comes with its own font,  
but users can choose their own glyphs to represent individual [code points][2].  
Although Unilang could equally be represented in a markup format such as json or yaml,   
we provide the unicode textual frontend as it tends to look simpler,   
allow for custom glyphs, and is easy to colorize in editors.  
User's can choose to write directly in this unicode format,  
or use the graphical system built on top of it.  
![unilang's frontend perspectives vs developer experience](.readme/unilang-look.png "test")

The first point of contention people have with the language,  
is that they cannot fire of vim and start writing in it.  
In its ascii markup format, Unilang is too dense.  
It's dense, because we don't play any games with syntax or gramar in an attempt to make it more paletable.  
We want the user to be encoding concepts as close to the Unilang conceptual ADT as possible.  
Programming in unicode has proven to be a good trade-off between readability and writeability.  
I urge you to remember, that software enginering requires a lot more reading than it does writing.  

**Design choice:**  
Code is data.  We intend to make the language as close to a data structure as possible.  
Without making yet another lisp-like language, and have you drowning in parenthesis, we  
chose to target a conceptual ADT utilizing nested variants.  It's richer than an AST, or having everything as a list.  

#### 2. Grammar
You can express anything in any order assuming that it makes sense conceptually.  
Semantic analysis builds an ADT nearly identical to the tokens you write.  
You can leave many token out, and based on various configurations,  
you will get default values, automated enrichments, or descriptive errors.  
So many languages have bad compiler errors.  You will not see these in Unilang  
due to the rich token set and easy to understand grammar.  

**Design choice:**  
We are already set on using unique tokens for 1-1 mappings on the conceptual ADT.  
It is trivial to parse these indepent tokens in any order so why enforce it.  
If user's want consistency, unilang can simply tidy itself to a particular user chosen order.  


#### 3. Code generation
Unilang could target LLVM, output byte code for the JVM, or operate under its own interpreter.  
However, there is little reason to invest in these efforts at this time.  
We stand on the shoulder's of giants and transcompile to other languages.  
This is a strategic decision because it helps Unilang grow in 2 ways.  
The more languages Unilang can transcompile to other languages,   
the more we can generisize programming concepts across the ecosystem.  
It also helps us show that two seemingly apposing language design decisions  
can be incorperated into the same language and chosen programatically at build time.

**Design choice:**  
This was an easy decision.  For Unilang to grow in a conceptually pure way,  
we measure our success by our ability to transcompile to other languages.  
It's also less work for the backend, and it lets us secretly and immediately use Unilang in industrial cirumstances.  
We get real situations where Unilang is being used, and user's are unaware that they  
are contributing to its success by commenting on the transcompiled format.  
We can usually meet the needs of other programmers reading the transcompiled version  
of Unilang by putting their opinions into the configuration of the backend transcompiler.  

#### 4. Supersets Win
Many people believe a language should have a strong and simple core,  
followed by the advice to have libraries do the rest of the heavy lifting.  
This stems from the experience of how difficult it becomes to change a language
once so much code has been written in it.   
Unilang puts as much in the language as possible, because anything that is added must be
a concept that stands independent of the code that is generated.  
Extending unilang with new tokens is backwards-compadible, and doesn't affect the existing grammar.
Although Unilang may have a large number of language tokens to account for all these concepts,  
it is not very overwhelming because the majority of them are not required.

**Design choice:**  
The more context a compiler has, the more it can do.  
It can generate better code, give better error messages,  
and improve static analysis.

#### 5. Steal
Unilang is not afraid to steal all the good ideas from other languages.  
Through its design, it avoids all of the pitfalls that current languages acrue when adding too many features.  

#### 6. No trade-offs
Typical programming languages are designed around trade-offs.  
Unilang refuses to make trade-offs.   
Most opinions can be dual supported at the language level,  
and chosen during code generation.
</details>

<details>
<summary>Features</summary>
<br>  
  
TODO  
also consider a language matrix of tests/features that we have working across languages.

</details>
<details>
<summary>User manual</summary>
<br>  
  
TODO  
  
</details>

<details>
<summary>Installation</summary>
<br> 
  
#### Build from source
```
git clone git@github.com:Unilang/unilang.git unilang
cd unilang
./build_everything
# pray
# leave me a ticket if it didn't work, and we'll fix it
```

#### Stand-alone binaries
TODO.  
what do we want here?  
deb packages? rpm?  other distribution methods?
I want a quick and easy installer for people.

#### Is it building in the cloud?  
We strive to get all of these to pass.  
Due to the different limitations of these free services, that might not always be possible.  
At the very least, it gives us some good visibility into different issues.  
If the majority of these are passing, you have a good chance of succeeding in a local build.  
If they are failing,  I recomend you look back to a commit where they passed and clone from there.  

| Continuous Integration | Status | Notes |
| :---         | :---           | :---           |
| App Veyor | [![Build status](https://ci.appveyor.com/api/projects/status/mubmrg7wis4vubar/branch/master?svg=true)](https://ci.appveyor.com/project/luxe/everything/branch/master) | full build
| Circle     | [![CircleCI](https://circleci.com/gh/Unilang/unilang.svg?style=svg)](https://circleci.com/gh/Unilang/unilang)       | bootstraps build
| Codeship | [![Codeship Status for Unilang/unilang](https://app.codeship.com/projects/9bd37ae0-f384-0136-68bc-72341457e248/status?branch=master)](https://app.codeship.com/projects/9bd37ae0-f384-0136-68bc-72341457e248/) | full build
Semaphore | [![Build Status](https://semaphoreci.com/api/v1/luxe/everything/branches/master/shields_badge.svg)](https://semaphoreci.com/luxe/unilang) | full build
| Shippable | [![Run Status](https://api.shippable.com/projects/5c3163fd4e246e0700cea316/badge?branch=master)](https://app.shippable.com/accounts/5c3163cad1578b0700302159/dashboard) | full build |
| Travis   | [![Build Status](https://travis-ci.com/Unilang/unilang.svg?branch=master)](https://travis-ci.com/Unilang/unilang)     | full build




#### Is the build hermetic?  
I'm trying.  Here is an overview of the build system.

![diagram of the build system](.readme/build-system.png "test")

If you experience a build issue, make a ticket.  
Also take a look at the CIs that are passing, and see if they  
do anything extra to get a successful build.  

Things to improve:  
 - bundle sysroot
 - disable all external linking / include file paths (same as sysroot?)
 - test in different docker containers (kind of have this with existing CIs)
 - move more system dependencies (see CI config files) into bazel deps (GMP specifically)
 - set a default compiler toolchain automatically? (instead of specifying directly on cli)
</details>

<details>
<summary>Contribute</summary>
<br>
There are no rules.  Make a ticket about anything.  We'll figure it out together.  
</details>

[1]: https://en.wikipedia.org/wiki/Private_Use_Areas
[2]: https://en.wikipedia.org/wiki/Code_point
