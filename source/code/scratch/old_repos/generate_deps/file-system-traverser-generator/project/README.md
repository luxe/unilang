###File System Traverser

This repository should be used as a symbolic source for the concept of symbolic pull-ins. Build a sympull file, so that the program git-it can pull from this repository and generate code for you: Your sympull file should look like this: 
```
--cycle="yes|no|optional" (default is: optional)
--directory-skipable="yes|no" (default is: yes)
--traversal-method="bfs|in-order|pre-order|post-order|optional" (default is: optional)
--file-priority="lexicographical|reverse-lexicographical|optional"  (default is: optional)
```

###What is it?
an object designed to traverse a file systems starting from a specified directory.  
