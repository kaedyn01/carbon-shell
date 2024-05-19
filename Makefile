# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Target executable name
TARGET = csh

# Source files
SRCS = built_in_commands.c input_functions.c main.c

# Object files (replace .c with .o in SRCS)
OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = built_in_commands.h input_functions.h

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files from source files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Rebuild the project from scratch
rebuild: clean all

# Phony targets (these targets do not correspond to actual files)
.PHONY: all clean rebuild