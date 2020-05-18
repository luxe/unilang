#Makefile for Large Integer Class
#This file compiles the Large Integer Class, a driver, and also a factorial program which makes use of the Large Integer Class.

CC = g++
CFLAGS =-c -Wall
OBJECTS = LargeInteger.o

all: driver factorial

driver: $(OBJECTS) driver.cpp
	@$(CC) -o driver driver.cpp $(OBJECTS)
	@tput setaf 5
	@echo "make: <OBJECTS LINKED> driver.o "$(OBJECTS)
	@tput setaf 2
	@echo "make: <EXECUTABLE CREATED> driver"
	@tput sgr0

factorial: $(OBJECTS) factorial.cpp
	@$(CC) -o factorial factorial.cpp $(OBJECTS)
	@tput setaf 5
	@echo "make: <OBJECTS LINKED> factorial.o "$(OBJECTS)
	@tput setaf 2
	@echo "make: <EXECUTABLE CREATED> factorial"
	@tput sgr0

LargeInteger.o: LargeInteger.cpp LargeInteger.h
	@$(CC) $(CFLAGS) LargeInteger.cpp
	@tput setaf 4
	@echo "make: <OBJECT CREATED> Large Integer"
	@tput sgr0

clean:
	@rm -rf driver factorial $(OBJECTS)
	@tput setaf 1
	@echo "make: <FIELE DELETED> driver program has been removed"
	@echo "make: <FIELE DELETED> factorial program has been removed"
	@echo "make: <FIELES DELETED> related object files have been removed."
	@tput sgr0



