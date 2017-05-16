BINARY = lukasma5
CC = g++
CFLAGS = -Wall -pedantic -Wno-long-long -O0 -ggdb -std=c++11
LIBS = -lncurses

SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:.cpp=.o)

.PHONY: compile
.PHONY: all
.PHONY: run
.PHONY: reset
.PHONY: doc
.PHONY: clean

compile: $(BINARY) reset
all: $(BINARY) doc reset
run:
	./$(BINARY)
reset:
	cp default_files/* .
doc:
	doxygen doxygenConfig
clean:
	rm -f $(OBJ) $(BINARY) highest_score.txt positions.txt
	rm -rf doc/


$(BINARY): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(BINARY)

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@
