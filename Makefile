BINARY = geus
CC = g++
CFLAGS = -std=c++11 -O3
LIBS = -lncurses

SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:.cpp=.o)

.PHONY: reset
.PHONY: doc
.PHONY: install
.PHONY: uninstall
.PHONY: clean-build-files
.PHONY: clean-all

default: $(BINARY)
reset:
	cp default_files/* .
doc:
	doxygen doxygenConfig
install:
	cp $(BINARY) /usr/bin
uninstall:
	rm /usr/bin/$(BINARY)
clean:
	rm -f $(OBJ) $(BINARY)
clean-all:
	rm -f $(OBJ) $(BINARY) highest_score.txt positions.txt
	rm -rf doxygen/


$(BINARY): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(BINARY)

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@
