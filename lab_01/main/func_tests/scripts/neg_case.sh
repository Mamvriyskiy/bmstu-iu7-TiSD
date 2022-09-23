#!/bin/bash
f_in=$1
f_expect=$2

# echo "$f_in"
# echo "$f_expect"

../../app.exe < "../data/""$f_in""" > ../../output.txt
bash ./comparator.sh ../data/""$f_expect"" ../../output.txt

res=$?

if [ "$res" -eq 0 ]; then
    exit 0
fi
exit 1