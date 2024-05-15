#!/bin/bash

# Set the default JSON-C paths
JSONC_INCLUDE_PATH=/opt/homebrew/Cellar/json-c/0.17/include/json-c
JSONC_LIB_PATH=/opt/homebrew/Cellar/json-c/0.17/lib

# Check if pkg-config is available
if command -v pkg-config &> /dev/null
then
    JSONC_INCLUDE_PATH=$(pkg-config --cflags-only-I json-c | sed 's/-I//')
    JSONC_LIB_PATH=$(pkg-config --libs-only-L json-c | sed 's/-L//')
fi

# Clean previous build files
rm -f main.o actions.o database.o menus.o sshtool

# Compile the source files
gcc -Wall -Wextra -I. -I$JSONC_INCLUDE_PATH -c -o main.o main.c
gcc -Wall -Wextra -I. -I$JSONC_INCLUDE_PATH -c -o actions.o actions.c
gcc -Wall -Wextra -I. -I$JSONC_INCLUDE_PATH -c -o database.o database.c

# Link the object files into the final executable
gcc -Wall -Wextra -o sshtool main.o actions.o database.o -L$JSONC_LIB_PATH -ljson-c
