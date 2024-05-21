# Compiler
CC := gcc 

# Directories
SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include
TEST_DIR := tests
OBJ_DIR := $(BUILD_DIR)/obj

# Compiler Flags
CFLAGS := -I$(INCLUDE_DIR) -Wall -Wextra

# Source and Object Files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
TEST_FILES := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ_FILES := $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR)/%.o, $(TEST_FILES))

# Main target
TARGET := $(BUILD_DIR)/csh
TEST_TARGET := $(BUILD_DIR)/test

# Default target
all: run

# Run the application
run: build
	$(TARGET)

# Build the application
build: $(TARGET)

# Build the main application
$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $@

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Run tests
run_test: build_test
	$(TEST_TARGET)

# Build tests
build_test: $(TEST_TARGET)

# Build the test executable
$(TEST_TARGET): $(TEST_OBJ_FILES) $(OBJ_FILES)
	$(CC) $(filter-out $(OBJ_DIR)/main.o, $(OBJ_FILES)) $(TEST_OBJ_FILES) -o $@

# Compile test files into object files
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# PHONY targets
.PHONY: all run build run_test clean