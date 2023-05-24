#!/bin/bash

# Get all .c files in the current directory
c_files=$(find . -maxdepth 1 -type f -name "*.c")

# Compile all .c files together
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 $c_files -o hsh
