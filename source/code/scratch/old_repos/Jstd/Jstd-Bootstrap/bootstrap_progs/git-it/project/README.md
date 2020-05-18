##git-it

`git-it` is a wrapper around the `git clone` tool, and is used to replace `git submodules` with the concept of [symbolic pull-ins](https://github.com/luxe/symbolic-pull-ins).  

####why do we need a replacement to git submodules?
They don't work as well as they should.  
 - They are hard to update
 - They are hard to automatically get when you first download a repository.
 - They are hard to keep synconized when ones changes between a local and remote repository
 - They require extra effort for deployment on either the programmer or the client
 - Maintinging nesting dependencies is also difficult without recursively running various git commands.  
 
Overall, there needs to be a better mechanism for obtaining submodules in a development project.  There also needs to be a better mechanism for kepping these submodules up-to-date.  The reason `git clone` won't handle the proper method of obtaining submodules, is because I don't believe we should be using git's way of submoduling.  Their way of submoduling, in my opinion, is overly complex and fundamentally flawed.  Bringing in submodules with `git-it`, is easier, more efficient, keeps projects up-to-date, and provides a simpler workflow while still keeping projects isolated from one another.  Most importantly however, `git-it`'s powerful concept of submodules are tied in with dynamic code generation.  If a reposoitory is pulled in as a submodule, it is a dynamic submodule.  This means that two different repositories can reference the same repository as a submodule, but utilize different code from it(assuming the referenced repositoy allows for it).  To put it another way, `git-it` is used for bringing in code from referenced repositories but relies on the programs found at the referenced repository's root. These programs are used to generate code specifically for the project that's pulling from it.  This added behaviour makes submodules more flexible for the projects that are pulling from them, because additional code generation flags can be passed.

`git-it` does what `git clone` does, as well as help maintain all submodules of a project.


####why don't you like git submodules?
git keeps track of submodules by referencing a particular point in their commit history.  This means that as dependencies update, your project's dependencies don't.  It can become increasingly difficult to keep your dependencies up-to-date.  git submodules are also designed to not be edited and updated inside a super project-- which means you would have to find the original repo of the dependency, make your change there, and then go to every project that uses that dependency as a submodule, step into the portion of the code base that is the submodule, re-pull the changes, add to the staging area the fact that your submodule has changed, and commit that change.  And that's just assuming the submodule was only one level deep.  

You might argue that it's important to have dependencies not immediately update, because updates on dependencies can break the current build.  A lot of devleopers want to ease into updates, and will apply newer versions of updates on seperate branches, test them, and deploy with changes later.  I agree that this should be the mentality for some, but not all dependencies.  Therefore, `git-it` supports depedencies at particular commit points, but you can also exclude that option, and dependencies will be set to update automatically.
   
**Here are some blog posts that further illustrate the deficiencies of git submodules:** 
 - [The Problem With Git Submodules](http://ayende.com/blog/4746/the-problem-with-git-submodules)  
 - [Why Your Company Shouldn't Use Git Submodules](http://codingkilledthecat.wordpress.com/2012/04/28/why-your-company-shouldnt-use-git-submodules/)  
 - [Submodules Are Probably Not The Answer](http://somethingsinistral.net/blog/git-submodules-are-probably-not-the-answer/)  
 - [Submodules Are Unusable](https://docs.google.com/document/d/1t9cpxYUFVIvDBV3aQWSS1DqpDfunDSVa49XezfOmZ7g/edit#heading=h.rlrpm9pzl0e1)  
 - [Alternatives To Git Submodule: Git Subtree](https://www.google.com)

####Surely there are other alternatives to git submodules?
Yeah there is, but mine is way simpler, and still more flexible for how I do work.  
All of the other methods are making the same mistake in my opinion, by keeping dependencies inside a project.  So what happens when you have a dependency being used by two separate projects?  You guessed it, you have duplicate code. And what happens when you have submodule `A` using both submodule `B` and `C`, which in turn are both using submodule `D`?  Now you have duplicate code inside the same project!!! This does not have to be the case, with [symbolic pull-ins](https://github.com/luxe/symbolic-pull-ins).

####How git submodules and other wrappers address dependencies:
![picture of how other ways handle repo dependencies](https://raw.github.com/luxe/git-it/master/project/.README_files/git-clone.png)   
Using other git repositories inside another git repository, often looks like this.  The actual code of the submodules can be pulled into your project if you desire them to be.  In my experience, you almost always want them pulled in, because they are depedencies necessary for you to continue and test the software. Regardless, those dependencies are actually composed inside other repositories when you request them, and that isn't good.  It means, you have the potential to waste both hard drive space an syncronization time having duplicate code inside your project (as seem by repo D being pulled in twice).  

####How git-it handles dependencies:
![picture of how git-it handles repo dependencies](https://raw.github.com/luxe/git-it/master/project/.README_files/git-it.png)

####This way is better:  
The philosiphy is simple: In the same way that libraries and dependencies get installed as finished software, so should code be installed for developing software.  When I say "we install code", I mean that we pull down the repository and put it somewhere in your home directory(or wherever), so that everybody(multiple projects, and multiple portions of the same project) can reference it. By default, `git-it` puts the code in `$HOME/.github/user_name/repo_name/` and it's like having a local copy of github.com for all the repositories you are using (well, github does a lot of other stuff for you, but it's like having all the hosted code from github.com on your drive).

####More specifically, how are the repositories 'glued' together?  
`git-it` doesn't just use symbolically linked files to keep projects together.  It relies on a more flexible concept called `symbolic pull-ins`.  You can read about `symbolic pull-ins` [here](https://github.com/luxe/symbolic-pull-ins). They are text files that represent symbolic links to other code repositories, and contain flag data attached so that code can be geneated where they are placed.

#####Dependencies for git-it:  
 - boost file system  
 - C++11 compliant compiler
 - GNU Make 3.81+

####How to install git-it:  
1. run make to build the `git-it` program 
2. move that created binary into a folder specified by your $PATH

####Are there any downsides to this replacement over the usual git methods of submoduling?
git-it is intended to work exactly like `git clone`, but also handle [symbolic pull-ins](https://github.com/luxe/symbolic-pull-ins) as submodules.  In fact, the `git-it` tool actually calls `git clone`, to get repositories off of github, but it is also used frequently inside already downloaded repositories to help maintain the submodules once a part of the project.  

Here is a video showing how to install and use `git-it`:  
*HI! I didn't make one yet :)*


####How to use:  

| Download A repository        | Command |
| ------------- |:------------------|
| get a repository and all its dependencies      | `git-it <URL>`| |
| get a repository without dependencies      | `git-it --no-deps <URL>` |  |

| Update an existing repository        | Command |
| ------------- |:------------------|
| Pull in dependencies of the current directory      | `git-it` |  |
| Pull in dependencies for the listed sympull files      | `git-it --symfile <.sympull files...>` |  |
| Pull in dependencies of the current directory and all the sub directories      | `git-it --recursive` |  |
| Pull in all dependencies of the repo      | `git-it --all` |  |

| Clean an existing repository        | Command |
| ------------- |:------------------|
| Clean dependencies of the current directory      | `git-it --clean` |  |
| Clean dependencies for the listed sympull files      | `git-it --clean <.sympull files...>` |  |
| Clean dependencies of the current directory and all the sub directories      | `git-it --clean --recursive` |  |
| Clean all dependencies of the repo      | `git-it --clean --all` |  |

| Additional        | Command |
| ------------- |:------------------|
| Don't re-generate the global .gitignore file | `--no-ignore` |  |
| remove all of the currently cached git repositories | `--wipe-local` |  |

