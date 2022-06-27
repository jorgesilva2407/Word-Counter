CC = g++
SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/lexOrder.o $(OBJ)/list.o $(OBJ)/tree.o $(OBJ)/memlog.o $(OBJ)/main.o
CFLAGS = -Wall -Werror -I include -std=c++17

EXE = $(BIN)/tp2.exe

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS)

$(OBJ)/lexOrder.o : $(INC)/lexOrder.hpp $(SRC)/lexOrder.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/lexOrder.o -c $(SRC)/lexOrder.cpp

$(OBJ)/list.o : $(INC)/list.hpp $(SRC)/list.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/list.o -c $(SRC)/list.cpp

$(OBJ)/tree.o : $(INC)/tree.hpp $(SRC)/tree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tree.o -c $(SRC)/tree.cpp

$(OBJ)/memlog.o: $(INC)/memlog.h $(SRC)/memlog.c
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o -c $(SRC)/memlog.c

$(OBJ)/main.o : $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o -c $(SRC)/main.cpp

clear: 
	rm obj/* bin/* out/*