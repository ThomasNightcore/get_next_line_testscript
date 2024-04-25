#!/bin/zsh

search_dir=./text_files 
binary="test_next_line.a"

BROWN="\033[1;33m"
GREEN="\033[1;32m"
NC="\033[0m"

chmod 777 $binary

for entry in "$search_dir"/*
do
	echo "$BROWN Running test for $entry:$NC"
	echo "$GREEN=================== START-TEST ===================$NC"
	./"$binary" "$entry"
	echo "$GREEN==================== END-TEST ====================$NC"
done

