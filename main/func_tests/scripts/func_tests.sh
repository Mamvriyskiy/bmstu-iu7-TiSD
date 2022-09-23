#!/bin/bash

data_path="../data"
app="../../app.exe"
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

ERR=255

count_pos_in="$(find ../data | grep -c "pos_[0-9][0-9]_in.txt")"
count_neg_in="$(find ../data | grep -c "neg_[0-9][0-9]_in.txt")" 

echo ""
echo "START POSITIVE TEST:"
for (( i = 1; i < $((count_pos_in + 1)); i++ )); do
    if [[ $i -lt 10 ]]; then
        a="pos_0""$i""_in.txt"
        b="pos_0""$i""_out.txt"
    else 
        a="neg_""$i""_in.txt"
        b="neg_0""$i""_out.txt"
    fi
    bash ./pos_case.sh "$a" "$b"
    res=$?
    if [ $res -eq 0 ]; then
        echo -e "POSITIVE_TEST $i: ${GREEN}PASSED${NC}"
    else
        echo -e "POSITIVE_TEST $i: ${RED}FAILED${NC}"
        neg_failed=$((neg_failed+1))
    fi
done

echo ""
echo "START NEGATIVE TEST:"
for (( i = 1; i < $((count_neg_in + 1)); i++ )); do
    if [[ $i -lt 10 ]]; then
        a="neg_0""$i""_in.txt"
        b="neg_0""$i""_out.txt"
    else 
        a="neg_""$i""_in.txt"
        b="neg_0""$i""_out.txt"
    fi
    bash ./neg_case.sh "$a" "$b"
    res=$?
    if [ $res -eq 0 ]; then
        echo -e "NEGATIVE_TEST $i: ${GREEN}PASSED${NC}"
    else
        echo -e "NEGATIVE_TEST $i: ${RED}FAILED${NC}"
        neg_failed=$((neg_failed+1))
    fi
done

