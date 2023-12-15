CC = gcc
CFLAGS = -O0 -Wall -Wextra -Wpedantic
CLIBS = -lm -lSDL2 -lSDL2main

SRC = $(wildcard src/*.c) $(wildcard src/*/*.c)
OBJ = $(SRC:%.c=%.o)
: OBJDIR = build/
BIN = zeterra

.PHONY: all run clean

all: $(BIN)
: all: $(OBJDIR) $(BIN)

run: all
	./$(BIN)

: $(OBJDIR):
	: mkdir $(OBJDIR)

$(BIN): $(OBJ)
	mkdir -pv build/
	$(CC) $(OBJ) -o $(BIN) $(CLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rfv $(OBJ) $(BIN)
	: rm -rfv $(OBJDIR)
