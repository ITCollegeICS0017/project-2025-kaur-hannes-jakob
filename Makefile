CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
BIN=app

CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -g
SRCDIR := src
SRC := $(SRCDIR)/main.cpp
TARGET := CE.exe

.PHONY: all run test clean

all: $(BIN) $(TARGET)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

run: all
	@echo "Running $(abspath $(TARGET))"
	./$(TARGET)

test: $(BIN) tests/test_basic.sh
	bash tests/test_basic.sh

clean:
	rm -f $(BIN) src/*.o $(TARGET)
