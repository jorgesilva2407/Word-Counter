CC = g++
SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(SRC)/lexOrder.o $(SRC)/tree.o $(SRC)/list.o
HDRS = $(INC)/wordCounter.hpp $(INC)/lexOrder.hpp $(INC)/tree.hpp $(INC)/list.hpp
CFLAGS = -Wall -I include -std=c++17 -pg

EXE = $(BIN)/tp2.exe

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS)

$(OBJ)/lexOrder.o : $(INC)/lexOrder.hpp $(SRC)/lexOrder.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/lexOrder.o -c $(SRC)/lexOrder.cpp

$(OBJ)/list.o : $(INC)/list.hpp $(SRC)/list.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/list.o -c $(SRC)/list.cpp

$(OBJ)/tree.o : $(INC)/tree.hpp $(SRC)/tree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tree.o -c $(SRC)/tree.cpp

clear: 
	rm obj/* bin/* out/*