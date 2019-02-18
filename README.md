<p align="left">
	<img width="395" height="112" src=".readme/unilang-trimmed.png">
</p>

**A universal programming language**

</details>
<details>

<summary>Introduction</summary>
## Overview
Unilang is self proclaimed universal programming language.  It is a reconstructed approach on how language should be used to facilitate the creation of software.  In this introduction we will describe how Unilang is used in the context of software engineering.  We will compare it to other programming languages to show the similarities and key differences between them.  The important take-away is that Unilang is not competing with other programming languages.  It embraces all of them in its own implementation.  A primary focus when first introducing Unilang is a discussion around **encoded information** and **software-related artifacts**.  We discuss what engineers need to encode while working in a problem domain, and what products should come from such an encoding.  A conclusion is made that engineers are not encoding everything necessary due to the limitations and scope of individual tools.  The effect of not having a universal encoding results in multiple encodings across different languages which makes maintenance less feasible over time.  An argument is made that more concepts related to software must be semantically encoded at the language level.  How this is achieved from a practical perspective is explored later.  
So let's start by getting you acquainted with the big picture.  Unilang is a tool for writing software.  And like all tools in software, it takes an input and produces an output.  The scope of Unilang's throughput however is ambitious.  Everything a software engineer can express around a problem domain must be encoded in the same ontology.  We find this necessary in maximizing our current understanding of the problem domain, and adapting to its change over time.  The output of this ontology is every chosen artifact that facilitates desired tasks in that domain.  From a programming perspective, we unify all formal and informal languages involved around software.  This information is encoded as a single abstract data model which is used to create various artifacts.  
![very high level overview of Unilang](.readme/unilang_overview.png "")

The diagram above is intentionally vague.  However, we can use it to compare the transformation process of source code in other programing languages.  The scope of these other languages do not entail all of the work that needs to be done in a real-world software engineering context.  
![high level overview of a GPL](.readme/typical_gpl_overview.png "")

The goals of general purpose programming languages (GPLs) shown above, are also realized within Unilang.  Unilang can be used to generate programs for any domain.  A key feature of Unilang is that it can even target the source code of all other GPLs.  This means that Unilang can be easily adopted in current systems as a transcompiler to other programming languages.  
![Unilang as a transcompiler](.readme/unilang_as_a_transcompiler.png "")

There are many other types of artifacts that should be created alongside software.  Unilang facilitates the creation of these artifacts as well.  
![Unilang to many artifacts](.readme/unilang_to_many_artifacts.png "")

In fact, what you are reading now was generated from Unilang.  

## Motivation
The motivation behind Unilang has grown organically while working as a software engineer.  It serves a purpose both practical and personal from working in the industry.  In this section we will cover the specific motivations around Unilang.  

### Practical
TODO.  

### Personal
TODO.  
</details>
<details>

<summary>Features</summary>TODO. also consider a language matrix of tests/features that we have working across languages.  

## IDL support
TODO.  

## GPL support
TODO.  

## DSL support
TODO.  
</details>
<details>

<summary>Language Design</summary>In this section, we will discuss the theory of what a programming language should be.  We show how these ideas are applied in shaping the design of Unilang.  

## Hierarchy
In this section we discuss the hierarchy of language.  Consider the current language abstractions within the software engineering domain.  Unilang and its conceptual model are placed above these high level languages.  
![software engineering language abstraction with Unilang placed at the top](.readme/language-abstraction.png "")

Unilang can transcompile down to other languages.  

## Structure
In this section we discuss the structure of language.  Many programming languages represent their syntactic structure as an abstract syntax tree.  Other languages like Lisp and its derivations choose nested lists.  The structure of Unilang is a composed set of algebraic data types.  
![choosing the Unilang structure](.readme/choosing-structure.png "")

This is a subtle but important distinction.  An ADT models the concise structure and shape of programming concepts.  This allows us to work backwards and enable programmers to efficiently populate this structure.  Trying to contort a variety of programming concepts syntactically, and then extracting them out with regular expressions and grammars into generic data structures such as trees and lists has proven insufficient for semantic analysis.  Its the reason that parsing errors are often confusing and unhelpful.  Its the reason that community tooling on code transformation is often limited.  Most importantly, its the reason a language's evolution tends to stagnate as more abstract concepts are squeezed into an existing syntax and grammar.  

## Ergonomics
In this section we discuss the ergonomics of the language in terms of reading and writing.  TODO. this is where we talk about discrete infinity.  TODO. this is where we talk about projectional editors.  

## Guiding Principles

### Syntax
Syntax doesn't matter. It never has, and it never will.  We eliminate syntax complexity through unique symbolic tokens.  Unilang pulls from Unicode's Private Use Area (PUA).  As a result, no matter how many tokens get added the the language, the lexical and syntactical analysis remains trivial.  Unilang comes with its own font, but users can choose their own glyphs to represent individual code points.  Although Unilang could equally be represented in a markup format such as json or yaml, we provide the unicode textual frontend as it tends to look simpler, allow for custom glyphs, and is easy to colorize in editors.  User's can choose to write directly in this unicode format, or use the graphical system built on top of it.  
![Unilang's frontend perspectives vs developer experience](.readme/unilang-look.png "")



### Grammar
You can express anything in any order assuming that it makes sense conceptually.  Semantic analysis builds an ADT nearly identical to the tokens you write.  You can leave many token out, and based on various configurations, you will get default values, automated enrichments, or descriptive errors.  So many languages have bad compiler errors.  You will not find this in Unilang due to the rich token set and easy to understand grammar.  

### Code Generation
Unilang could target LLVM, output byte code for the JVM, or operate under its own interpreter.  However, there is little reason to invest in these efforts at this time.  We stand on the shoulder's of giants and transcompile to other languages.  This is a strategic decision because it helps Unilang grow in 2 ways.  The more languages Unilang can transcompile to other languages, the more we can generalize programming concepts across the ecosystem.  It also helps us show that two seemingly apposing language design decisions can be incorporated into the same language and chosen programatically at build time.  
</details>
<details>

<summary>User Guide</summary>TODO. talk about how to use unilang.  

## Installation
Ready to get started?  Unilang can be built from source in the following way.  
```
git clone git@github.com:Unilang/unilang.git unilang
cd unilang
./build_everything
LITERARY_SENTENCE_CODE_LINE
```
Unilang can be built from source in thssssse following way.  Various CIs are also building from source and can be used as reference.  

| Continuous Integration | Status | Notes | 
| --- | --- | --- | 
| App Veyor | [![Build status](https://ci.appveyor.com/api/projects/status/mubmrg7wis4vubar/branch/master?svg=true)](https://ci.appveyor.com/project/luxe/everything/branch/master) | Full Build | 
Circle | [![CircleCI](https://circleci.com/gh/unilang/unilang.svg?style=svg)](https://circleci.com/gh/unilang/unilang) | Bootstraps Build | 
Cirrus | [![Build Status](https://api.cirrus-ci.com/github/unilang/unilang.svg)](https://cirrus-ci.com/github/unilang/unilang) | Bootstraps Build | 
Codeship | [![Codeship Status for Unilang/unilang](https://app.codeship.com/projects/9bd37ae0-f384-0136-68bc-72341457e248/status?branch=master)](https://app.codeship.com/projects/9bd37ae0-f384-0136-68bc-72341457e248/) | Full Build | 
Scrutinizer | [![Build Status](https://scrutinizer-ci.com/g/unilang/unilang/badges/build.png?b=master)](https://scrutinizer-ci.com/g/unilang/unilang/build-status/master) | Full Build | 
Semaphore | [![Build Status](https://semaphoreci.com/api/v1/luxe/everything/branches/master/shields_badge.svg)](https://semaphoreci.com/luxe/unilang) | Full Build | 
Shippable | [![Run Status](https://api.shippable.com/projects/5c3163fd4e246e0700cea316/badge?branch=master)](https://app.shippable.com/accounts/5c3163cad1578b0700302159/dashboard) | Full Build | 
Travis | [![Build Status](https://travis-ci.com/unilang/unilang.svg?branch=master)](https://travis-ci.com/unilang/unilang) | Full Build | 


</details>
<details>

<summary>Developer Guide</summary>TODO. here we talk about information for anyone who wants to contribute to the Unilang project.  

## Build System
TODO.  

### Hermetics
The project is designed to be hermetic.  This means that all external dependencies should be bootstrapped by the build system and self-contained within the repository.  If anything in the build relies on an external dependency (not available or tracked by the repository) this can break user's builds, and it is a bug.  Here is an overview on what the build system looks like.  
![diagram of the build system](.readme/build-system.png "")



## Contribute
There are no rules.  Make a ticket about anything.  We'll figure it out together.  
