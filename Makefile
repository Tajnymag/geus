BINARY = geus
CC = g++
CFGLAGS = -std=c++11 -O2
LIBS = -lncurses

OBJ = $(wildcard build/*.o)

$(BINARY): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lncurses -o $(BINARY)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<