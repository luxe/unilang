#MAIN PROGRAM
PROG_NAME := main

#RULE TO BUILD THE PROGRAM
all: $(PROG_NAME)

#--------------------#
# TRANSCOMPILE RULES |
#--------------------#
#hcp files
%.cpp %.hpp: %.hcp
	@echo "$(START_CYAN)$^$(END_COLOR)";
	@$(HCP_COMPILER) $^;
	
#Unilang files
%.cpp %.hpp: %.Unilang
	@echo "$(START_CYAN)$^$(END_COLOR)";
	@$(UNILANG_COMPILER) --exporter="trevor" --language="c++" --style="normal" $^;

#-----------#
# C++ RULES |
#-----------#
#object
%.o: %.cpp %.hpp
	@echo "$(START_BLUE)$<$(END_COLOR)";
	@$(CPP_COMPILER) $(LOOK_PATHS) $(CPP_FLAGS) -c $< -o $@
	
#main
%.o: %.cpp
	@echo "$(START_BLUE)$<$(END_COLOR)";
	@$(CPP_COMPILER) $(LOOK_PATHS) $(CPP_FLAGS) -c $< -o $@

#-----------#
#  C RULES  |
#-----------#
#object
%.o: %.c %.h
	@echo "$(START_BLUE)$<$(END_COLOR)";
	@$(C_COMPILER) $(LOOK_PATHS) $(C_FLAGS) -c $< -o $@
	
#main
%.o: %.c
	@echo "$(START_BLUE)$<$(END_COLOR)";
	@$(C_COMPILER) $(LOOK_PATHS) $(C_FLAGS) -c $< -o $@

include .mk/link-rule.mk

#-------------------#
#  recursive clean  |
#-------------------#
clean:

  #needs updated for unilang files as well
	@rm -rf *~ *.o *.d *.~ $(PROG_NAME) `ls-cpp-2 --recursive --only-generated --also-sympulls`;
	@rm -rf $(call rwildcard,,*~) $(call rwildcard,,*.o) $(call rwildcard,,*.d)
	@echo "cleaned";

build_missing:
	@for file in $(HCP_SOURCE_PATHS); do \
		if [ ! -f "`replace_suffix $$file --new-extension='cpp'`" ]; \
		  then \
		    echo "$START_YELLOW)build missing -> $$file$(END_COLOR)"; \
		    $(HCP_COMPILER) --no-utility-functions $$file; \
		fi \
	done
