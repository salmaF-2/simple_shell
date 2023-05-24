#!/bin/bash

shopt -s nullglob
# Enable nullglob option to handle no matching files
files=( *.c )
# Loop through each .c file and check betty style
if [ ${#files[@]} -eq 0 ]; then
	echo "No .c files found"
else
	for file in "${files[@]}"; do
		betty "$file"
	done
fi
