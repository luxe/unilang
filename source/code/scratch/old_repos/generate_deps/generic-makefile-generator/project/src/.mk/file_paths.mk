# recursively get all the source files from dependencies pulled in.
RECURSIVE_ROOT_FOLDER := Sub
OTHER_NON_RECURSIVE_PATHS := /usr/include/python2.7

C_SOURCE_PATHS := $(call rwildcard,$(RECURSIVE_ROOT_FOLDER),*.c)
CPP_SOURCE_PATHS := $(call rwildcard,$(RECURSIVE_ROOT_FOLDER),*.cpp)
HCP_SOURCE_PATHS := $(call rwildcard,$(RECURSIVE_ROOT_FOLDER),*.hcp)
INCLUDE_PATHS := $(shell find $(RECURSIVE_ROOT_FOLDER) -type d)

#current directory of makefile
C_SOURCE_PATHS += $(wildcard *.c)
CPP_SOURCE_PATHS += $(wildcard *.cpp)
HCP_SOURCE_PATHS += $(wildcard *.hcp)
INCLUDE_PATHS += $(shell pwd)

# add any additional paths specified by the user
INCLUDE_PATHS += $(OTHER_NON_RECURSIVE_PATHS)

# any source file can include any header found in the directory tree
# as such, we need to build up -I flags and feed them to the compiler
LOOK_PATHS := $(addprefix -I,$(INCLUDE_PATHS))

LIB_PATHS := -L/usr/local/lib
