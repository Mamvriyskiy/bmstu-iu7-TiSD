#!/bin/bash

file_1="$1"
file_2="$2"

# cat "$file_1"
# echo ""
# cat "$file_2"
# echo ""

diff "$file_1" "$file_2"

if [ -z "$(diff -B "$file_1" "$file_2")" ]; then
	exit 0
else
	exit 1
fi
