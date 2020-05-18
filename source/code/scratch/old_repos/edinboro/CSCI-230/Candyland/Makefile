#MakeFile for Candyland Game

# ╔═════════════╗ ╔══════╗ ╔═════════════╗
# ║board_space.o║ ║card.o║ ║  player.o   ║
# ╚═════════════╝ ╚══════╝ ╚═════════════╝
#        |           |            |
# ╔═════════════╗ ╔══════╗ ╔═════════════╗
# ║   board.o   ║ ║deck.o║ ║contestants.o║
# ╚═════════════╝ ╚══════╝ ╚═════════════╝
#             \      |      /
#             ╔═════════════╗
#             ║  candyland  ║
#             ╚═════════════╝

CC = g++
SOURCES = main.cpp \
          board_space.cpp board.cpp \
          card.cpp deck.cpp \
          player.cpp contestants.cpp

OBJECTS = board_space.o board.o \
          card.o deck.o \
          player.o contestants.o

CFLAGS =-c -Wall

all: candyland

candyland: $(OBJECTS) main.cpp
	@$(CC) -o candyland main.cpp $(OBJECTS)
	@echo "make: <OBJECTS LINKED> main.o "$(OBJECTS)
	@echo "make: <EXECUTABLE CREATED> Candyland"

board.o: board.cpp board.h board_space.o
	@$(CC) $(CFLAGS) board.cpp
	@echo "make: <OBJECT CREATED> Candyland Board"

board_space.o: board_space.cpp board_space.h candyland_colors.h
	@$(CC) $(CFLAGS) board_space.cpp
	@echo "make: <OBJECT CREATED> Candyland Board Space"

deck.o: deck.cpp deck.h card.o
	@$(CC) $(CFLAGS) deck.cpp
	@echo "make: <OBJECT CREATED> Candyland Deck"

card.o: card.cpp card.h candyland_colors.h
	@$(CC) $(CFLAGS) card.cpp
	@echo "make: <OBJECT CREATED> Candyland Card"

contestants.o: contestants.cpp contestants.h player.o
	@$(CC) $(CFLAGS) contestants.cpp
	@echo "make: <OBJECT CREATED> Candyland Contestants"

player.o: player.cpp player.h
	@$(CC) $(CFLAGS) player.cpp
	@echo "make: <OBJECT CREATED> Candyland Player"

clean:
	@rm -rf candyland $(OBJECTS)
	@echo "make: <FIELS DELETED> Candyland program and related object files have been removed."