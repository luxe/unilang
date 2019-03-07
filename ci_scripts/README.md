These are the frontend scripts for each of the continuous integration services.  

Our CI system will mimic the same build as a normal user.  
However, due to the limitations of some online CIs (for example: timing out if the build is too long),  
we use these script frontends to change how particular CIs build and test,  
to test simple bazel bootstraping, we can use:  
./user_build run //code/hello_world/sh:hello_world  