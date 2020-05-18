#COMPILER FLAGS
BOOST_LIBS = -lboost_program_options -lboost_filesystem -lboost_system
GMP_LIBS = -lgmpxx -lgmp
NCURSES_LIBS = -lncurses -lmenu -lpanel -lform -lncurses++
OTHER_LIBS = 
OPTIMIZE = -Ofast
LIBS = $(BOOST_LIBS) $(GMP_LIBS) $(NCURSES_LIBS) $(OTHER_LIBS)
#WARNS = -Wall -pedantic -Wextra

#COMPILER STATEMENT
CXX = g++-6
CPPFLAGS = --std=c++14 $(OPTIMIZE) -MD -MP $(WARNS)

#MAIN PROGRAM
PROG_NAME = main

SRC = $(wildcard *.cpp)
CLASS = $(wildcard *.hcp)
all: $(PROG_NAME)

#stops make from deleting my cpps
.SECONDARY:

%.cpp %.hpp: %.hcp
	hcp-compiler $^;

main: $(SRC:%.cpp=%.o) $(CLASS:%.hcp=%.o)
	@$(CXX) $(CPPFLAGS) -o $@ $^ -Wl,--as-needed -Wl,--start-group $(LIBS)
	@echo successful link
	cp main ~/.bin/hcp-compiler;
clean:
	@rm -rf *~ *.o *.d *.~ $(PROG_NAME) `ls-cpp --only-generated`;
	@echo "cleaned";

-include $(SRC:%.cpp=%.d)

%.o: %.cpp %.hpp
	$(CXX) $(CPPFLAGS) -c $< -o $@
