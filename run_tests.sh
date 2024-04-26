#!/bin/zsh

search_dir=text_files 
binary="test_next_line.a"
buffer_size=""

# Colors
BROWN="\033[1;33m"
GREEN="\033[1;32m"
NC="\033[0m"

# Setup for buffer_size
if [ -n "$1" ]; then
	buffer_size="-D BUFFER_SIZE=$1"
fi

# Compiling the files
cc -Wall -Werror -Wextra -g ../get_next_line.c ../get_next_line_utils.c main.c -I./.. -o $binary $buffer_size 

# Running test for each file in search_dir
# 
for entry in "$search_dir"/*
do
	echo "$BROWN Running test for $entry:$NC"
	echo "$GREEN=================== START-TEST ===================$NC"
	./"$binary" "$entry"
	echo "$GREEN==================== END-TEST ====================$NC"
done
