#A small custom makefile to build a single executable for any number of source and header files.
#Every source and header file will be grabbed recursively.  

#various build settings
include .mk/settings/diagnostic-output.mk
include .mk/settings/warnings.mk
include .mk/settings/optimizations.mk
include .mk/settings/sanitizers.mk
include .mk/settings/debugs.mk
include .mk/settings/language-standards.mk
include .mk/settings/compilers.mk
include .mk/settings/libraries.mk
include .mk/utility.mk

#my tools
include .mk/specific/shared/compilers.mk

#Complete set of flags to give compiler
#MD and MP help deduce dependencies automatically
C_FLAGS := -MD -MP $(C_STANDARD) $(DIAGNOSTIC_FORMAT) $(ALL_C_WARNINGS) $(SANITIZERS) $(OPTIMIZATIONS) $(DEBUGS)
CPP_FLAGS := -MD -MP $(CPP_STANDARD) $(DIAGNOSTIC_FORMAT) $(ALL_CPP_WARNINGS) $(SANITIZERS) $(OPTIMIZATIONS) $(DEBUGS)

# recursively get all the source files from dependencies pulled in.
C_SOURCE_PATHS := $(call rwildcard,Sub,*.c)
CPP_SOURCE_PATHS := $(call rwildcard,Sub,*.cpp)
HCP_SOURCE_PATHS := $(call rwildcard,Sub,*.hcp)
INCLUDE_PATHS := $(shell find Sub -type d)

#current directory of makefile
C_SOURCE_PATHS += $(wildcard *.c)
CPP_SOURCE_PATHS += $(wildcard *.cpp)
HCP_SOURCE_PATHS += $(wildcard *.hcp)
INCLUDE_PATHS += $(shell pwd)

# any source file can include any header found in the directory tree
# as such, we need to build up -I flags and feed them to the compiler
LOOK_PATHS := $(addprefix -I,$(INCLUDE_PATHS))

# use the bash shell
SHELL := bash

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
