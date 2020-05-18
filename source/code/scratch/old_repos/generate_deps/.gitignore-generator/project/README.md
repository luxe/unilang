##.gitignore File Maker

This repository should be used as a symbolic source for the concept of [symbolic pull-ins](https://github.com/luxe/symbolic-pull-ins).  Build a sympull file, so that the program `git-it` can pull from this repository and generate code for you:  Your sympull file should look like this:  
```
--all

  --binaries
    --compiled_libraries
      --object_files
      --dynamic_libraries
      --static_libraries
    --executables
    
  --backups
  
  --dependencies
  
  --os_generated
    --windows_generated
    --mac_generated
    --linux_generated
  
  --archived
  
  --database
  
  --editor
    --notepad++
    --vim
    --emacs
    --kate
    --sublime
    
  --build_system
    --auto_tools
    --SCons
    --CMake
    --Qt
    
--additional="
add additional
ignore rules
here
"
```
the flags that are indented are subsets of their parent flags.  If you use the parent flag, all the children flags will be applied implicitly.  To exclude a flag group, put `no_` in front of the flag name.  In the event that a flag is both included and not included with the `no_` prefix, the non-inclusion will be applied.

Example:
```
--all --no_os_generated
```
will apply **all** the flags, **except** the `os_generated flags`; which means, `windows_generated`, `mac_generated`, and `linux_generated` flags will in turn, not be applied.

