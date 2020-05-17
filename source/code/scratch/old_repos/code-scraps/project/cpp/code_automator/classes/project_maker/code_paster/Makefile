###################################################################
#Tell 'make' to use bash
#RUNDIR is the full path of where we run 'make'
###################################################################
SHELL := /bin/bash
RUNDIR := $(shell pwd)
###################################################################
#TOP equals the root of the particular project
#(either already in the directory or up.)
#top will equal the directory where ".Rules.top" is
###################################################################
ifndef TOP
TOP := $(shell rd=$(RUNDIR); top=$$rd; \
               until [ -r $$top/.Rules.top ]; do \
                 oldtop=$$top; \
                 cd ..; top=`pwd`; \
                 if [ $$oldtop = $$top ]; then \
                   top=$$rd; break; \
                 fi; \
               done; \
               echo $$top)
endif
###################################################################
#MK equals the root of the build system
#(we assume it's outside the root of the particular project)
#once the folder "Build_System" is found, MK equals that directory
###################################################################
ifndef MK
MK := $(shell rd=$(TOP); top=$$rd; cd $(TOP); \
               until [ -r $$top/build_system/ ]; do \
                 oldtop=$$top; \
                 cd ..; top=`pwd`; \
                 if [ $$oldtop = $$top ]; then \
                   top=$$rd; break; \
                 fi; \
               done; \
               echo $$top/build_system)
endif
###################################################################
#targets you can type
#'all' and 'clean_all' are defined elsewhere
###################################################################
.DEFAULT_GOAL := dir
.PHONY: dir tree all clean clean_tree clean_all dist_clean
dir        : dir_$(RUNDIR)
tree       : tree_$(RUNDIR)
clean      : clean_$(RUNDIR)
clean_tree : clean_tree_$(RUNDIR)
###################################################################

###################################################################
include $(MK)/header.mk
include $(TOP)/.Rules.top
include $(MK)/footer.mk
-include $(TOP)/final.mk
###################################################################
# This is just a convenience - to let you know when make has
# stopped interpreting make files and started their execution.
###################################################################
$(info Rules generated $(if $(BUILD_MODE),for $(BUILD_MODE),)...)
###################################################################
