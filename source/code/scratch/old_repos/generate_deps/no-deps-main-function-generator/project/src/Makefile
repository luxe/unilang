#COMPILER FLAGS
BOOST = -lboost_program_options -lboost_filesystem -lboost_system
GMP = -lgmpxx -lgmp
OPTIMIZE = -Ofast
LIBS = $(BOOST) $(GMP)
#WARNS = -Wall -pedantic -Wextra

#COMPILER STATEMENT
CPPFLAGS = -std=c++1y $(OPTIMIZE) -MD -MP $(WARNS)

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
	@g++ $(CPPFLAGS) -o $@ $^ -Wl,--as-needed -Wl,--start-group $(LIBS)
	@echo successful link
	cp main ../../main.symsource
	
clean:
	@rm -rf *.o *.d *.~ $(PROG_NAME) `ls-cpp --generated_only`;
	@echo "cleaned";

-include $(SRC:%.cpp=%.d)

%.o: %.cpp %.hpp
	g++ $(CPPFLAGS) -c $< -o $@
