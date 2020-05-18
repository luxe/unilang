#A small custom makefile to build a single executable for any number of source and header files.
#Every source and header file will be grabbed recursively.  

# use the bash shell
SHELL := bash

#various build settings to apply
include .mk/settings/all.mk
include .mk/utility.mk

#the tools to use
include .mk/specific/shared/compilers.mk

#Complete set of flags to give compiler
#MD and MP help deduce dependencies automatically
C_FLAGS := -MD -MP $(C_STANDARD) $(DIAGNOSTIC_FORMAT) $(ALL_C_WARNINGS) $(SANITIZERS) $(OPTIMIZATIONS) $(DEBUGS) $(DEFINES_AND_UNDEFINES)
CPP_FLAGS := -MD -MP $(CPP_STANDARD) $(DIAGNOSTIC_FORMAT) $(ALL_CPP_WARNINGS) $(SANITIZERS) $(OPTIMIZATIONS) $(DEBUGS) $(DEFINES_AND_UNDEFINES)

include .mk/file_paths.mk

#assume that none of our rules create files that are used in rules to create other files.
#although we may have intermediate files, we don't want make to automatically delete them.  
#for example, a transcompiled source file, creates source files used to create objects.  
#we don't want the source files deleted after an object is built.
.SECONDARY:

#our custom rules to transcompile code, build objects, and link.
#there really shouldn't be any reason that you need to modify these rules/
include .mk/rules.mk

#rules to trigger builds based on derived dependencies
include .mk/generated_dependency_rules.mk
