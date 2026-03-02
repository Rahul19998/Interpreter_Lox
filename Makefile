# Makefile for building main.cpp into ./build/main

# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Werror -Weffc++ -Wextra -Wconversion -Wsign-conversion -Wextra -O2 -pedantic-errors -ggdb -std=c++17 -Iinclude

# Source and output
SRC := main.cpp Lox.cc Scanner.cpp
OUT_DIR := build
OUT := $(OUT_DIR)/main

# Default target
all: $(OUT)

# Build rule
$(OUT): $(SRC)
	@mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC)

# Clean rule
clean:
	$(RM) -r $(OUT_DIR)

.PHONY: all clean

