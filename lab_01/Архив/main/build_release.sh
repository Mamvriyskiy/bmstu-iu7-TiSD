#!/bin/bash

gcc -std=c99 -Werror -c ./*.c 
gcc -o app.exe ./*.o -lm