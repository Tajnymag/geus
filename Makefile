BINARY = geus
CC = g++
CFGLAGS = -std=c++11 -O2
LIBS = -lncurses

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

.PHONY: maps
.PHONY: doc
.PHONY: install
.PHONY: uninstall
.PHONY: clean-build-files
.PHONY: clean-all

default: $(BINARY)
maps:
	cp default_files/* .
doc:
	doxygen doxygenConfig
install:
	cp $(BINARY) /usr/bin
uninstall:
	rm /usr/bin/$(BINARY)
clean-build-files:
	rm -f $(OBJ)
clean-all:
	rm -f $(OBJ) $(BINARY) highest_score.txt positions.txt
	rm -rf doxygen/

$(BINARY): $(OBJ)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $(BINARY)
