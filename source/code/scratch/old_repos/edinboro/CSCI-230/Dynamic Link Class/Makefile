#Makefile for Dynamic Linked List Class
#This file compiles a Dynamic Linked List Class, a driver, and a student grade program which makes use of the Dynamic Linked List Class.
#        ╔══════════╗
#        ║ studentT ║
#        ╚══════════╝
#             |
#        ╔══════════╗
#        ║  ListT   ║
#        ╚══════════╝
#         /        \
# ╔══════════╗ ╔══════════════╗
# ║  driver  ║ ║ studentLists ║
# ╚══════════╝ ╚══════════════╝


CC = g++
CFLAGS =-c -Wall
OBJECTS = student.o list.o
EXECUTABLE = driver studentLists

all: driver main

driver: $(OBJECTS) driver.cpp
	@$(CC) -o driver driver.cpp $(OBJECTS)
	@tput setaf 5
	@echo "make: <OBJECTS LINKED> driver.o "$(OBJECTS)
	@tput setaf 2
	@echo "make: <EXECUTABLE CREATED> driver"
	@tput sgr0
	
main: $(OBJECTS) main.cpp
	@$(CC) -o studentLists main.cpp $(OBJECTS)
	@tput setaf 5
	@echo "make: <OBJECTS LINKED> main.o "$(OBJECTS)
	@tput setaf 2
	@echo "make: <EXECUTABLE CREATED> main"
	@tput sgr0

list.o: list.cpp list.h student.o
	@$(CC) $(CFLAGS) list.cpp
	@tput setaf 4
	@echo "make: <OBJECT CREATED> list"
	@tput sgr0
	
student.o: student.cpp student.h
	@$(CC) $(CFLAGS) student.cpp
	@tput setaf 4
	@echo "make: <OBJECT CREATED> student"
	@tput sgr0


clean:
	@rm -rf driver $(OBJECTS) $(EXECUTABLE)
	@tput setaf 1
	@echo "make: <FIELE DELETED> driver program has been removed"
	@echo "make: <FIELE DELETED> studentLists program has been removed"
	@echo "make: <FIELES DELETED> related object files have been removed."
	@tput sgr0