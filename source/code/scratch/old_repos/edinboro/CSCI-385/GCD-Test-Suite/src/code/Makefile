OBJS = gcd_algorithms.o test_suite.o algorithm.o
PROGS = driver
SOME_FLAGS = -std=c++11 -Ofast
CC = g++

all: $(PROGS)

bennett: bennett.cpp
	$(CC) $(SOME_FLAGS) -o bennett bennett.cpp
	
driver: driver.cpp $(OBJS)  globals.hpp
	$(CC) $(SOME_FLAGS) -o driver driver.cpp $(OBJS)
	
algorithm.o: algorithm.cpp algorithm.hpp globals.hpp
	$(CC) $(SOME_FLAGS) -c $< -o $@

gcd_algorithms.o: gcd_algorithms.cpp gcd_algorithms.hpp globals.hpp
	$(CC) $(SOME_FLAGS) -c $< -o $@

test_suite.o: test_suite.cpp test_suite.hpp gcd_algorithms.hpp globals.hpp
	$(CC) $(SOME_FLAGS) -c $< -o $@
	
clean:
	rm -rf *.o $(PROGS) *~
