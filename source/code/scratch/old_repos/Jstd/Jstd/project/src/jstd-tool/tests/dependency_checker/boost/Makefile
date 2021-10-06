BOOST = -lboost_program_options -lboost_filesystem -lboost_system
.PHONY: all
all: main

main:
	@g++ -o main main.cpp $(BOOST)

clean:
	@rm -rf *.o main *~
