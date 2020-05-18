#COMPILER FLAGS
BOOST_LIBS = -lboost_program_options -lboost_filesystem -lboost_system -lboost_iostreams -lboost_serialization
GMP_LIBS = -lgmpxx -lgmp
NCURSES_LIBS = -lncurses -lmenu -lpanel -lform -lncurses++
OTHER_LIBS = 
OPTIMIZE = -Ofast
LIBS = $(BOOST_LIBS) $(GMP_LIBS) $(NCURSES_LIBS) $(OTHER_LIBS)
#WARNS = -Wall -pedantic -Wextra

#COMPILER STATEMENT
CXX = g++-6
CPPFLAGS = -std=c++1z $(OPTIMIZE) -MD -MP $(WARNS)

#MAIN PROGRAM
PROG_NAME = main

#For debugging purposes.
#This rule will allow querying 'make' for variable contents:
#http://stackoverflow.com/a/25817631/908939
print-%  : ; @echo $* = $($*)

SRC = $(wildcard *.cpp)
CLASS = $(wildcard *.hcp)
all: $(PROG_NAME)

#stops make from deleting my cpps
.SECONDARY:

%.cpp %.hpp: %.hcp
	@echo "[0;36m$^[0m";
	@hcp-compiler $^;

main: $(SRC:%.cpp=%.o) $(CLASS:%.hcp=%.o)
	@$(CXX) $(CPPFLAGS) -o $@ $^ -Wl,--as-needed -Wl,--start-group $(LIBS)
	@echo "[0;35msuccessful link[0m"
	@cp main ../../main.symsource;
clean:
	@rm -rf *~ *.o *.d *.~ $(PROG_NAME) `ls-cpp --only-generated --also-sympulls`;
	@echo "cleaned";

-include $(SRC:%.cpp=%.d)

%.o: %.cpp %.hpp
	@echo "[0;34m$<[0m";
	@$(CXX) $(CPPFLAGS) -c $< -o $@

#for building main.cpp
%.o: %.cpp
	@echo "[0;34m$<[0m";
	@$(CXX) $(CPPFLAGS) -c $< -o $@
