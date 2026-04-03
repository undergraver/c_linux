# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Targets (programs to build)
TARGETS = hello add
gigi:
	echo "Gigi nu face nimic"
# Default target (runs when you type: make)
all: $(TARGETS)

# Build hello from hello.c
hello: hello.c
	$(CC) $(CFLAGS) hello.c -o hello

# Build add from add.c
add: add.c
	$(CC) $(CFLAGS) add.c -o add

# Clean compiled binaries
clean:
	rm -f $(TARGETS)
