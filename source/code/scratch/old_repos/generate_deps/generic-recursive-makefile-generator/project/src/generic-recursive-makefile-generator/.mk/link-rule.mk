#-----------------#
#  Linking C/C++  |
#-----------------#
#I included -Wl,--as-needed -Wl,--start-group because I didn't want to link anything I wasn't actually using.  
#Later, when I upgraded compilers from g++-5 to g++-6 I got a missing /usr/bin/ld.gold: missing group end error.  
#Although, I also had to change the linker to the gold linker since I was using sanatizers.  
#Either way, I investigated the point of --start-group and --end-group.  
#http://stackoverflow.com/questions/5651869/gcc-what-are-the-start-group-and-end-group-command-line-options
#I can't say I've ever seen circular dependency issues mentioned in the thread,  
#but either way, I've added the --end-group tag to stop the gold linker from failing.


$(PROG_NAME): $(CPP_SOURCE_PATHS:%.cpp=%.o) $(C_SOURCE_PATHS:%.c=%.o) $(HCP_SOURCE_PATHS:%.hcp=%.o)
	@$(CPP_COMPILER) $(LOOK_PATHS) $(LIB_PATHS) $(CPP_FLAGS) -o $@ $^ -Wl,--as-needed -Wl,--start-group $(LIBS) -Wl,--end-group
	@cp main ~/.bin/unilang-transcompiler;
	@echo "[0;35msuccessful link[0m"
