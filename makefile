CC = g++

SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/StringCounter.o $(OBJ)/LexOrder.o $(OBJ)/list.o $(OBJ)/tree.o
HDRS = $(INC)/StringCounter.hpp $(INC)/LexOrder.hpp $(INC)/list.hpp $(INC)/tree.hpp

CFLAGS = -Wall -I include -std=c++17 -pg

EXE = $(BIN)/tp2.exe

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS)

$(OBJ)/StringCounter.o : $(INC)/StringCounter.hpp $(SRC)/StringCounter.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/StringCounter.o -c $(SRC)/StringCounter.cpp

$(OBJ)/LexOrder.o : $(INC)/LexOrder.hpp $(SRC)/LexOrder.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/LexOrder.o -c $(SRC)/LexOrder.cpp

$(OBJ)/list.o : $(INC)/list.hpp $(SRC)/list.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/list.o -c $(SRC)/list.cpp

$(OBJ)/tree.o : $(INC)/tree.hpp $(SRC)/tree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tree.o -c $(SRC)/tree.cpp

clear: 
	rm obj/* bin/* out/*