# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Iinclude -Wall -Wextra

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
TESTS_DIR = tests

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Executable name
TARGET = $(BUILD_DIR)/csh

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

run: all
	./$(BUILD_DIR)/csh

# Testing
test: $(TARGET)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/input_functions_test $(TESTS_DIR)/input_functions_test.c $(SRC_DIR)/input_functions.c
	$(BUILD_DIR)/input_functions_test

.PHONY: all clean test