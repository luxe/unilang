#COMPILER FLAGS
BOOST = -lboost_program_options -lboost_filesystem -lboost_system
GMP = -lgmpxx -lgmp
OPTIMIZE = -Ofast
LIBS = $(BOOST) $(GMP)
#WARNS = -Wall -pedantic -Wextra

#COMPILER STATEMENT
CPPFLAGS = -std=c++14 $(OPTIMIZE) -MD -MP $(WARNS)

#OTHER
PROG_NAME = main


SRC = $(wildcard *.cpp)
CLASS = $(wildcard *.hcp)
all: $(PROG_NAME)

%.cpp %.hpp: %.hcp
	hcp-compiler $^

main: $(SRC:%.cpp=%.o)
	@g++-6 $(CPPFLAGS) -o $@ $^ -Wl,--as-needed -Wl,--start-group $(LIBS)
	@echo successful link
	
clean:
	@rm -rf *.o *.d *.~ $(PROG_NAME);
	@echo "cleaned";

-include $(SRC:%.cpp=%.d)


