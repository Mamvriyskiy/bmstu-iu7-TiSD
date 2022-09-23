#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include "main.h"

#define LEN_ARRAY_NUMBER 11

void accumulation_struct_number(number_t *struct_number, char *number, int *mantissa_i, int *order_i, int *k);
size_t str_number_len(char *str);
int division_number(int *first_number, int *second_number, \
    int first_mantissa, int second_mantissa, int *result_number, int *count);
double create_number(int *array, int lenl_array);
int rounding(int *array, int lenl);
int make_result_number(number_t *first_number, number_t *second_number, number_t *result_number, \
    int lenl_order_first, int lenl_order_second, int k_1, int k_2, int lenl_mantissa);
void output_result(number_t *result_number, int lenl_mantissa);
void print(int *array, int i, int lenl);
void without_zero(int *array, int *lenl);

#endif
