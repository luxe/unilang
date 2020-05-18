######maybe today in programming languages, we'll learn how to properly implement symbolic pull-ins.  
######went over homework
 - probably just going to be googling stuff today


#####BRANDON!
look:   
http://unix.stackexchange.com/questions/76462/dynamic-file-content-generation-satisfying-a-file-open-by-a-process-executio
http://unix.stackexchange.com/questions/64491/dynamic-file-system-with-hooks  
http://superuser.com/questions/655296/is-it-possible-to-have-dynamic-files-with-the-contents-being-at-some-internet-re

######Class:  
 - 20 minutes about old computers
 - boring
 - computers have compilers


#####BRANDON!
screw FUSE.  It's too complicated, and I don't want to force everyone to run a server just because I need dependencies generated.  I think I'll bite the bullet, and just have two files.  
 - one file will be the actual file pulled in
 - the other file will contain the change details.
 - I don't like it though.  They can't be inside the same file, because then the `path` and `change details` will push the content down, and I'll have to worry about making that meta data look like comments in particular file.  So, no to all of that.  


######Class:  
 - dynamic semantics
 - operational semantics
 - concept of an attribute
 - the state of a program
 - denotaional semantics (math functions)


#####BRANDON!
If only we could symbolically link a program, and pass it data when we read from it.  I don't think pipes will work.  Maybe we do have to install and http server over the file system and leverage that somewhow  


 
