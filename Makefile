# Makefile for building main.cpp into ./build/main

# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -O2

# Source and output
SRC := main.cpp
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

