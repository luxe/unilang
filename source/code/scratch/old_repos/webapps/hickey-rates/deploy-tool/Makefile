#COMPILER FLAGS
BOOST = -lboost_program_options -lboost_filesystem -lboost_system
GMP = -lgmpxx -lgmp
OPTIMIZE = -Ofast
LIBS = $(BOOST) $(GMP)
#WARNS = -Wall -pedantic -Wextra

#COMPILER STATEMENT
CPPFLAGS = -std=c++1y $(OPTIMIZE) -MD -MP $(WARNS)

#OTHER
PROG_NAME = main


SRC = $(wildcard *.cpp)
all: $(PROG_NAME)

main: $(SRC:%.cpp=%.o)
	@g++ $(CPPFLAGS) -o $@ $^ -Wl,--as-needed -Wl,--start-group $(LIBS)
	@echo success

clean:
	@rm -rf *.o *.d *.~ $(PROG_NAME);
	@echo "cleaned";

-include $(SRC:%.cpp=%.d)


