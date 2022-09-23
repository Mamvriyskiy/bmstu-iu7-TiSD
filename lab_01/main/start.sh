#!/bin/bash

bash build_debug.sh
bash build_release.sh
cd ./func_tests/scripts
bash func_tests.sh
cd ../..
bash clean.sh

# for (( i = 1; i < 6; i++ )); do
#     touch func_tests/data/"pos_0"$i"_in.txt"
#     touch func_tests/data/"pos_0"$i"_out.txt"
# done