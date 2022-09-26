#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

#define MAX_LEN_MANTISSA 33
#define MAX_LEN_ORDER 6
#define LEN_NUMBER 50
#define STRUCT_INIT {1, 0, { 0 }, 0, 1, { 0 }}

typedef struct  
{
    int first_sign_number; //наличие +(1) и -(0) до числа
    int power_position; //расположение точки
    int mantissa[MAX_LEN_MANTISSA]; //мантисса числа
    int exp_position; //расположение exp
    int second_sign_number; //наличие +(1) и -(0) после экспаненты
    int order[MAX_LEN_ORDER]; //порядок числа
} number_t;

int creat_number(int *a, int size);

#endif
