# Compiler 
CC := gcc 

# Directories
SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include
TEST_DIR := tests

# Compiler Flags
CFLAGS := -I$(INCLUDE_DIR) -Wall -Wextra

# Source Files
SRCS := $(wildcard $(SRC_DIR)/*.c)

# Object Files
OBJS := $(patsubt %.c, %.o, $(SRCS))

# Test Files
TESTS := $(wildcard $(TEST_DIR)/*.c)

# Executable name and location
TARGET := $(BUILD_DIR)/csh

# Test executable
TEST := $(BUILD_DIR)/test

# Rules
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

$(OBJS): $(SRCS) $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(SRCS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf build
