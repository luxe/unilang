SHELL := /bin/bash
RUNDIR := $(shell pwd)
ifndef TOP
TOP := $(shell rd=$(RUNDIR); top=$$rd; \
               until [ -r $$top/Rules.top ]; do \
                 oldtop=$$top; \
                 cd ..; top=`pwd`; \
                 if [ $$oldtop = $$top ]; then \
                   top=$$rd; break; \
                 fi; \
               done; \
               echo $$top)
endif

MK := $(TOP)/mk

.PHONY: dir tree all clean clean_all clean_tree dist_clean
.DEFAULT_GOAL := dir

dir : dir_$(RUNDIR)
tree : tree_$(RUNDIR)

clean : clean_$(RUNDIR)
clean_tree : clean_tree_$(RUNDIR)

include $(MK)/header.mk
include $(TOP)/Rules.top
include $(MK)/footer.mk

# Optional final makefile where you can specify additional targets
-include $(TOP)/final.mk

# This is just a convenience - to let you know when make has stopped
# interpreting make files and started their execution.
$(info Rules generated $(if $(BUILD_MODE),for $(BUILD_MODE),)...)
